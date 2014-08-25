#pragma once

#define stup_par(h0,h1,a0,a1,b0,b1,u0,u1) H[0] = h0;H[1] =h1;A[0] = a0;A[1]=a1;B[0]=b0;B[1]=b1;U[0]=u0;U[1]=u1;
#define stup_ski(s0,s1,s2,s3,s4,s5,s6,s7,s8,s9) SK[0] = s0;SK[1] = s1;SK[2] = s2;SK[3] = s3;SK[4] = s4;SK[5] = s5;SK[6] = s6;SK[7] = s7;SK[8] = s8;SK[9] = s9;

int EMPLOY::tension_change()
{
	int MX=130,MIN=80;

	//やる気変化
	//休日or給料で上昇、それ以外は基本的に低下のみ
	int S = shop_n;
	//int R = fun.Rand(int(shop[S].b_w + this->b_w)/4 + 50 );
	int R = int((shop[S].b_w + this->b_w) * (100 - this->hp));//100 * 10ぐらい目安

	if(shop[S].mana_cnt[M_SUKR] > 0){//スクラム
		if(shop[S].emp_cnt - shop[S].emp_kou <= 10 && job == 0){
			R -= 500;
			MX+=10;
		}else if(shop[S].emp_kou <= 10 && job == 1){
			R -= 500;
			MX+=10;
		}
	}

	if(sun <= 0)   R -= 500*(1+shop[S].mana_cnt[M_NOBI]*2);//ストレス０
	if(skill == 7){R -= 500;MX+=10;}//元気印
	if(skill == 8){R += 500;MX-=10;}//サボり癖
	if(skill == 9){R -= 1000;MX+=20;}

	R = fun.Rand(R);
	tension -= R / 1000;

	if(	    tension < MIN ){
		pb_count += (tension - MIN)*10;
		tension = MIN;
	}else if(tension > MX){
		pb_count += (tension - MX)*10;
		tension = MX;
	}

	pb_count += (tension-100);

	if(pb_count > 1000){
		pb_rest =  14+fun.Rand(7);
		if(shop[S].mana_cnt[M_GLDM] > 0) shop[S].n_mp += 5;
	}else if(pb_count <-1000){
		pb_rest = -14+fun.Rand(7);
	}

	if(pb_rest >0 ){//黄金期
		tension = MX+10;
		pb_rest--;
		pb_count = 0;
		if(pb_rest == 0) tension = 90 + shop[S].mana_cnt[M_GLDS] * 10;
	}else if(pb_rest < 0){//暗黒期
		tension = MIN-10;
		pb_rest++;
		pb_count = 0;
		if(pb_rest == 0) tension = 100;
	}


	
	return 1;
}
int EMPLOY::manzoku_cul(){

	double ave_k;
	int S = shop_n;

	ave_k = req_rate + 50 + data.day / 7;
	//特殊能力持ちは相場＋アルファ

	//ブラック度が上がると減少
	//レベルか補正が上がると増加
	req_money = int(ave_k * (100 - shop[S].lv_ave*2 + lv*2 ) /100) + int((req_money_h*3 + lv)*(150-b_w)/100);
	req_money = max(req_money ,100);//最低10万

	if(shop[S].mana_cnt[13] > 0 && shop[S].mana_cnt[M_KUSY] <= 0) req_money += req_money/10;//労働組合
	if(skill == 26			   ) req_money += req_money / 5;
	else	if(skill == 27     ) req_money -= req_money / 5;
	
	int M_D = req_money;
	int M_U = pay_money;
	int MAN;

	MAN = M_U * 1000 / max(M_D,1);//比に応じる

	MAN = 1000 - MAN;

	if(MAN > 0){
		MAN = MAN * shop[S].jisyoku_b / 100;
	}

	if( shop[S].mana_cnt[M_SAKU] > 0 ){
		MAN -= 50;
		if( MAN < 0 ) MAN = 0;
	}


	return MAN;//辞める確率 1000で100%
}
int EMPLOY::select_shop(){


	if(shop_n >= 0){
		shop_like[shop_n] = 0;//
	}
	
	req_money_h = req_money_h*4 / 5;
	if(req_money_h < 0) req_money_h = 0;

	int LS = 0;
	int ML = 0;
	int LP = 0;

	for(int S=0;S<SHOP_M;S++){
		LP = fun.Rand(int(200-b_w-shop[S].b_w));

		LP = int(LP * shop[S].pay_ave);

		if(shop[S].mana_cnt[M_SINK] > 0){
			if(lv <= 1)	LP += LP/5;
			else		LP -= LP/5;
		}else if(shop[S].mana_cnt[M_TYUK]>0){
			if(lv <= 1)	LP -= LP/5;
			else		LP += LP/5;
		}

		shop_like[S] += LP;

		if(shop_like[S] > ML){
			ML = shop_like[S];
			LS = S;
		}
	}

	//面接判定
	if(req_jinji[0] <= shop[LS].mensetu_lv ) mensetu[0][LS] = 1;
	if(req_jinji[1] <= shop[LS].mensetu_lv ) mensetu[1][LS] = 1;
	if(req_jinji[2] <= shop[LS].mensetu_lv ) mensetu[2][LS] = 1;
	if(req_jinji[3] <= shop[LS].mensetu_lv ) mensetu[3][LS] = 1;			
	if(req_jinji[4] <= shop[LS].mensetu_lv ) mensetu[4][LS] = 1;
	if(skill == 0)							 mensetu[4][LS] = 1;

	rest = 0;

	//求職をあきらめる
	if(fun.Rand(intai) > 6){
		req_turn = 0;
		now_job = 3;
	}
	intai++;

	shop_n=LS;

	//要求計算
	manzoku_cul();
	pay_money = req_money;

	return 1;
}
int EMPLOY::status_cul(){

	int S = shop_n;

	//やる気等による補正

	if(pb_rest != 0){
		st_st[0] = (int)(sqrt((double)st[0]*100));
	}

	st_st[0] = (int)(sqrt((double)st[0]*100) * 100 / tension);
	st_st[1] = st[1] * tension / 100;
	st_st[2] = st[2] * tension / 100;

	if(shop[S].mana_cnt[M_TEKI] > 0){//エクストリーム
		if(     st[0] > st[1] && st[0] > st[2])	st_st[0] += st_st[0]/5;
		else if(st[1] > st[2]				  )	st_st[1] += st_st[1]/5;
		else									st_st[2] += st_st[2]/5;
	}

	konjyou_k = konjyou;

	//武器にケーション
	if(shop[S].mana_cnt[M_WECO] <= 0 && b_w > 50){		
		konjyou_k += int(( b_w - 50 )*(1 + shop[S].mana_cnt[M_LOVP]));
	}

	return 1;
}
int EMPLOY::skill_change(){

	int S = shop_n;
	int R = fun.Rand(100);
	int C = 0;

	switch(skill){
		case  0:
			if(R < shop[S].sk_qup)
			{
				while(1)
				{
					skill = fun.Rand(35);

					if(this->job == 0 )
					{
						if( skill == 25 ||
							skill == 28 ||
							skill == 29 ||
							skill == 30 ||
							skill == 31 ||
							skill == 33 || 
							skill == 34 ||
							skill == 35  ) continue;
					}
					if(this->job == 1 )
					{
						if( skill == 14 || 	
							skill == 15 ||
							skill == 16 ||
							skill == 17 ||
							skill == 18 ||
							skill == 19 ||
							skill == 22 ||
							skill == 23 ) continue;

					}
					break;
				}
				skill_efe(0);
			}
		break;
		case  1:if(R < shop[S].sk_pup) skill = 2;break;//快眠     - 超快眠
		case  4:if(R < shop[S].sk_rup) skill = 3;break;//神経質   - ノー天気
		case  5:if(R < shop[S].sk_rup) skill = 6;break;//病弱　   - 不死
		case  7:if(R < shop[S].sk_pup) skill = 9;break;//元気印   - ファイト一発！
		case  8:if(R < shop[S].sk_rup) skill = 7;break;//サボり癖 - 元気印
		case 11:if(R < shop[S].sk_rup) skill =10;break;//どじっ子 - 天才
		case 13:if(R < shop[S].sk_rup) skill =12;break;//凡骨     - カリスマ
		case 15:if(R < shop[S].sk_pup) skill =23;break;//押し売り
		case 18:if(R < shop[S].sk_rup) skill =17;break;//スマイル
		case 19:if(R < shop[S].sk_rup) skill =18;break;//無愛想
		case 20:
			if(R < shop[S].sk_pup){
				skill =21;
				shop[S].p_mp += 0.3;
			}
		break;//経営学
		case 22:if(R < shop[S].sk_rup) skill =15;break;//単騎
		case 26:if(R < shop[S].sk_rup) skill =27;break;//無欲化
		case 28:if(R < shop[S].sk_pup) skill = 29;break;//
		case 30:if(R < shop[S].sk_pup) skill = 31;break;//
		case 33:if(R < shop[S].sk_pup) skill = 34;break;//
		case 35:if(R < shop[S].sk_rup) skill = 33;break;//
		case 32:
			if(R < shop[S].sk_qup){
				skill = fun.Rand(35);
				skill_efe(0);
			}
		break;
	}

	return 1;
}
int EMPLOY::skill_efe(int UD){

	int S = shop_n;

	switch(skill){
		case 14://看板系
		case 25:
			if(UD == 0)	shop[S].senden_b += 5 + shop[S].mana_cnt[M_METE] * 5;
			else		shop[S].senden_b -= 5 + shop[S].mana_cnt[M_METE] * 5;
		break;
		case 20://経営学
			if(UD == 0)	shop[S].p_mp += 0.2;
			else		shop[S].p_mp -= 0.2;
		break;
		case 21://経営学２
			if(UD == 0)	shop[S].p_mp += 0.5;
			else		shop[S].p_mp -= 0.5;
		break;
		case 24://占星術
			if(UD == 0)	shop[S].mensetu_lv ++;
			else		shop[S].mensetu_lv --;
		break;
	}

	return 1;
}
int EMPLOY::month_emp(){

	int S = shop_n,RM,MAN;

	//労働日数計算
	RM = 100 * work_cnt /(28-shop[S].yasumi_max);
	//遅延
	if(shop[S].mana_cnt[71] > 0 && kinzoku == 1){
		RM=0;
		b_w+=10;
	}
	//閃き補正
	if(shop[S].mana_cnt[M_IDEB] > 0 && job == 1){
		RM += sell_now*20;
		sun-=5;
		b_w-=5;
	}
	//解雇補正
	if(shop[S].mana_cnt[M_KAIK] > 0 && chan_tai ==3) RM*=2;
	//ボーナス制
	if(shop[S].mana_cnt[M_BONU] > 0 && kinzoku%6 == 0){
		RM+=300-shop[S].mana_cnt[79]*30-shop[S].mana_cnt[80]*30-shop[S].mana_cnt[81]*30-shop[S].mana_cnt[73]*15;
		sun-=10;
		b_w-=10;
	}
	//非正規雇用
	if(shop[S].mana_cnt[M_TEST] > 0 && kinzoku < 6){
		RM=RM*2/3;
		b_w+=5;
	}
	//持ち株制度
	if(shop[S].mana_cnt[77] > 0){
		RM = RM*9/10;
		shop[S].kabu_max += (int)(pay_money*RM / (shop[S].kabu_price+1) / 10);
	}

	switch(chan_tai){
		case 1://昇給
			pay_money+= max(pay_money/10,30);
			sun -= 5;
			b_w -= 5;
			tension += 10;
			req_money_h -= 2;
		break;
		case 2://減給
			pay_money-= max(pay_money/10,30);
			sun += 5;
			b_w += 5;
			tension -= 10;
			req_money_h += 2;
		break;
	}

	//給料満足度計算
	MAN = manzoku_cul();

	if(chan_tai == 1) MAN = 0;//給料を上げた月は基本辞めない

	if( eve_flag==0 && 
		( fun.Rand(1000) < MAN		|| //満足度に応じて辞める
		  sun>konjyou_k			    || //ストレス限界
		  chan_tai == 3		        || //解雇指令
		  rest>=14 )){				   //廃人中

		if(sun>konjyou_k){
			intai = 10;
		}

		if(eve_flag == 1){
			this->tension = 0;//テンション最低になる
			char str[128];
			sprintf_s(str,"%sが辞めそうになった",name.c_str());
			logu.add(str,0,P);
		}else if(chan_tai == 3) yame(1);
		else					yame(0);
	}

	//要求変化
	kinzoku++;
	req_money_h ++;

	manzoku_cul();//満足度と要求再計算

	if(shop[S].mana_cnt[M_WECO] > 0) sun -=5;//ストレス回復ボーナス

	//給料支払い
	int RATE = 10;
	if(shop[S].mana_cnt[M_MOKA] > 0){
		//社員持ち株制度
		RATE = 7;
		shop[S].kabu_max += (int)((pay_money*3*RM)/(shop[S].kabu_price+1));
	}

	shop[S].money -= pay_money*RATE*RM;
	shop[S].emp_mon[data.mon-1] -= pay_money*RATE*RM;

	if(S==P) sys.total_kyuuryou += pay_money*10*RM;
	work_cnt = 0;
	sell_now = 0;

	//やる気上昇
	tension += pay_money * 40 / req_money - 30;

	return 1;
}
int EMPLOY::yame(int MES){

	int S = shop_n;
	char str[256];
	char str2[256];

	skill_efe(1);

	for(int I=0;I<shop[S].emp_cnt-1;I++){
		if(shop[S].emp_list[I] == no){
			shop[S].emp_list[I] = shop[S].emp_list[I+1];
			shop[S].emp_list[I+1] = no;
		}
	}
	shop_like[S]=-10000;
	if(job == 1)shop[S].emp_kou--;
	shop[S].emp_cnt--;

	if(S==P){
		switch(MES){
			case 0:
				sprintf_s(str,"辞職：%s",name.c_str());
				sprintf_s(str2,"%sが辞職しました！！！",name.c_str());
				sys.total_jisyoku++;
			break;
			case 1:
				sprintf_s(str,"解雇：%s",name.c_str());
				sprintf_s(str2,"%sを解雇しました",name.c_str());
				sys.total_kaiko++;
			break;
			case 2:
				sprintf_s(str,"逃走：%s",name.c_str());
				sys.total_jisyoku++;
			break;
		}

		logu.add(str,0,P);

		fun.list_de(no);

		draw.kakunin(str2,0);
	}
	req_money_h /= 2;//要求補正1/2



	shop[S].total_yame += kinzoku;
	kinzoku = 0;

	shop[S].nougu_req -= shop[S].mana_cnt[M_JITU] * 2;

	select_shop();

	return 1;
}
int EMPLOY::lv_up(){

	int S = shop_n;
	int STP;
	int STU[5][6]={
		{7,6,5,3,2,2},
		{6,5,4,4,3,3},
		{4,4,4,4,4,4},
		{3,3,4,4,5,5},
		{2,3,3,4,5,7},
	};
	int LV;
	double R = 0.1;
	if(skill == 10)			R=0.2;//天才
	else if(skill == 11)	R=0.05;//どじっ子

	R = R * data.exp_rate / 100;

	LV = int(sqrt(double(exp)*R))/10 + 1;

	if(LV > 100)LV = 100;
	if(LV < 1  ){
		LV = 100;
	}

	int B[3] = {0,0,0};//教育レベルに応じて成長率UP

	B[0] = shop[S].hp_up_b;//体力

	if(this->job == 0){
		B[1] = shop[S].sei_up_b;
		B[2] = shop[S].kai_up_b;
	}else{
		B[1] = shop[S].kya_up_b;
		B[2] = shop[S].sek_up_b;
	}

	if(skill == 12){
		B[0] += 25;
		B[1] += 25;
		B[2] += 25;
	}else if(skill == 13){
		B[0] -= 25;
		B[1] -= 25;
		B[2] -= 25;
	}

	while(LV > lv){
		STP = min(lv,50)/10;
		STP = STU[grow_t][STP];
		while(STP>0){
			if(fun.Rand(255) < st_up[0]+B[0] ) st[0]+=2;
			if(fun.Rand(255) < st_up[1]+B[0] ) st[1]+=2;
			if(fun.Rand(255) < st_up[2]+B[0] ) st[2]+=2;
			STP--;
		}
		lv++;
		draw.lv_t[no] = 100;
	}
	//スキル変化
	skill_change();

	shop[shop_n].cul_ave();

	return 1;
}
int EMPLOY::plus(int S){

	int i,W;

	now_job = 1;
	shop_n = S;

	skill_efe(0);//スキル効果

	if(job==1){//工房
		for(i=shop[S].emp_cnt;i>0;i--){
			shop[S].emp_list[i] = shop[S].emp_list[i-1];
		}
		shop[S].emp_list[0]=no;
		shop[S].emp_kou++;
	}else{
		shop[S].emp_list[shop[S].emp_cnt] = no;
	}
	shop[S].emp_cnt++;
	shop[S].total_saiyou++;

	pay_money = req_money;
	b_w		  = 70;//社会人度
	sell_now  = 0;

	mensetu[0][S] = 1;//面接済みにする
	mensetu[1][S] = 1;
	mensetu[2][S] = 1;
	mensetu[3][S] = 1;
	mensetu[4][S] = 1;
	tension = 100;
	if(job == 0) shift_n = shop[S].emp_cnt%4;//シフトALL
	else{
		shift_n = NOU_NO;//基本は農具
		if(S==P){
			for(i=0;i<WEP_M;i++){
				W=wind.efold_s[i];
				if(W==-1) break;
				if(shop[P].wep_cre[W] == 2 || wind.efold_cnt[W]<3){//開発中のは三人まで					
					shift_n = wind.efold_s[i];//リスト一番上のに決定
					break;
				}
			}
		}
	}

	if(S==P){//自店時リストに追加
		fun.list_pe(no);
		sys.total_koyou++;
	}

	shop[S].nougu_req -= shop[S].mana_cnt[M_JITU] * 2;//現物支給

	this->status_cul();

	return 1;
}
int EMPLOY::day_start(/*日はじめ処理*/){

	shop[shop_n].cul_ave();

	int RD,KEGA,S;
	char str[100];
	RD=28-data.day%28;//今月残り日数
	//シフトの変更,製造力の再計算
	if(shop_n >= data.shop_cnt) return 1;
	//現職ではない場合
	if(now_job == 2){//雇用
		chan_tai = 0;
		work_cnt = 0;
		intai = 0;
		char str[256];
		sprintf_s(str,"雇用：%s",name.c_str());
		if(shop_n == P)logu.add(str,1,P);
		plus(shop_n);
	}

	if( now_job != 1){
		rest--;
		return 1;
	}

	wait = 0;
	S = shop_n;

	tension_change();
	status_cul();

	//バックレなんてない
	//int PR = konjyou_k*2 + kinzoku*60 + work_cnt * 30;
	//if(shop[S].mana_cnt[M_SAKU] > 0) PR *= 2;//柵
	//バックレ判定
	//if(fun.Rand(int(shop[S].b_w+b_w+sun)) > PR && eve_flag == 0 && rest <= 1){
	//	yame(2);
	//	return 1;
	//}

	KEGA = int((100-hp) * (100-hp) * (100-hp) / 100 +10);//HP 0　で 10000

	double Stres = 0;
	//ストレス計算
	if(hp < 75){
		Stres += double(75 - hp) * (50 + shop[S].b_w) / 1000;
	}
	//社会人度計算
	if(hp<75){
		b_w += double(75 - hp)/100;//最大1000//HP70%以下なら上昇
	}
	//会社に染まる
	if(b_w != shop[S].b_w){
		b_w = (b_w * 199 + shop[S].b_w) / 200;
	}

	if(	   skill == 3) Stres /= 2;
	else if(skill ==4) Stres *= 2;
	sun += Stres;

	if(skill == 5) KEGA *=2;//病弱
	if(skill == 6) KEGA = 0;//不死
	if(rest == 1) rest = 0;

	//怪我計算
	if( fun.Rand(9999) < KEGA && rest <= 0){//HP0で20%、20で10%、50で2.5%程度//超元気でも0.3%
		KEGA = fun.Rand(KEGA);//重症度計算
		if(KEGA<200){//軽い風邪 50%
			rest = 2+fun.Rand(1);//1～2
			b_w += 1;
			tension-=20;
			if(shop_n == P){
				sprintf_s(str,"風邪：%s",name.c_str());
				logu.add(str,6,P);
			}
		}else if(KEGA<500){//高熱病
			rest = 4+fun.Rand(2);//3～5
			b_w += 10;
			sun += 4;
			tension-=40;
			if(shop_n == P){
				sprintf_s(str,"高熱：%s",name.c_str());
				logu.add(str,6,P);
			}
		}else if(eve_flag == 0){//過労
			rest = 6+fun.Rand(3);//5～8
			b_w += 30;
			sun += 6;
			tension-=60;
			shop[shop_n].bw_bonus += 10;//ブラック度固定１％＋
			if(shop_n == P){
				sprintf_s(str,"過労：%s",name.c_str());
				logu.add(str,6,P);
			}
		}
	}
	if(sun > konjyou_k && rest<=0){//廃人化
		rest = int(sun);
		b_w = 50;
		shop_like[S] = 0;
		shop[shop_n].bw_bonus += 5;//ブラック度固定５％＋
		tension=50;
		if(shop_n == P){
			sprintf_s(str,"廃人化：%s",name.c_str());
			logu.add(str,6,P);
			sys.total_haijin++;
		}
		sun = 0;
	}

	if( b_w < 0   ) b_w = 0;
	if( b_w > 100 ) b_w = 100;

	if(shop[S].holiday >= 1 || rest_check() == 1){//会社が休みか休日ローテ
		if(rest <= 1)rest = 2;//一日休み
	}
		
	//休日出勤判定、HPが高い、隷属度高い、ブラック度高いで発生
	if(shop[S].holiday == 0 && shop[S].kouji == 0 && rest == 2 && shop[S].mana_cnt[M_SABI]>0){
		if( shop[S].b_w + b_w + hp  > fun.Rand(100) + 200){
			rest = 0;
			b_w += 5;
			if( b_w > 100 ) b_w = 100;
			work_cnt--;//労働日数には含まない
		}
	}

	if(rest > 0){//休日or怪我等
		rest--;
		tension +=3;
		hp_gain(30);//休日は平日の２倍回復 30程度
		if(hp >= 100) tension++;
		sun -= 0.5;
	}else{//労働
		work_cnt++;
		int T = 165 - 54/3*5;
		
		if(job == 1 && shop[S].mana_cnt[M_SYSA] == 0)	T = 165 - shop[S].koubou_t/3*5;

		if(skill == 1)	    hp_gain(T * 2 * 1.2 / 15);//快眠1.2倍
		else if(skill == 2)	hp_gain(T * 2 * 1.5 / 15);//超快眠1.5倍
		else				hp_gain(T * 2 * 1.0 / 15);//体力約5％回復
	}

	//ステータス計算、体調反映
	status_cul();
	shift = shift_n;//シフト変更

	return 1;
}
int EMPLOY::mon_start(/*月はじめ処理*/){

	//辞職、解雇、減給、昇給、雇用処理
	if(shop_n >= data.shop_cnt) return 1;

	switch(now_job){
		case 3://■ニート■
			req_turn--;
			if(this->req_turn == 1) now_job = 0;
			shop_n = -1;
			select_shop();
		break;
		case 0://■無い内定■//求職先を探す
			select_shop();
		break;
		case 1://■現職■
			month_emp();
		break;
		case 2://■ある内定■
			chan_tai = 0;
			work_cnt = 0;
			intai = 0;
			plus(shop_n);
			char str[256];
			sprintf_s(str,"雇用：%s",name.c_str());
			if(shop_n == P)logu.add(str,1,P);
		break;
	}
	
	return 1;
}
int EMPLOY::hp_lose(int R){

	hp -= hp * fun.Rand(R) / st_st[0] / 100;

	if(hp<0) hp = 0;

	return 1;
}
int EMPLOY::hp_gain(double R){

	int S = shop_n;

	if(kinzoku < 3) R =  R * shop[S].kaihuku_bs / 100;
	R =  R * shop[S].kaicost_b / 100;

	hp += R;

	if(hp > 100) hp = 100;

	return 1;
}
int EMPLOY::rest_check(){

	int S = shop_n;
	int YOU = data.day%7;
	int SYU = data.day/7%4;
	int SUT;//定休有なら0
	int YCNT = shop[S].yasumi_max;
	if(shop[S].teikyuu<7) YCNT -= 4;
	int RT;

	if(shop[S].teikyuu>=7 && SYU<2) SUT = 6;
	else							SUT = 5;

	if(YOU == shop[S].teikyuu) return 1;
	else if(YOU > shop[S].teikyuu && YOU != 6) YOU--;

	if( YCNT == 12){//週休3
		RT = rote_type%4;
		switch(RT%2){
			case 0:
			if(YOU == 0 || YOU == 2 || YOU == 4) return 1;
			break;
			case 1:
			if(YOU == 1 || YOU == 3) return 1;
			if(YOU == SUT && (SYU+RT/2)%2 == 0) return 1;
			break;
		}
	}else if(YCNT >=8){//週休２以上
		RT = rote_type%6;
		switch(RT%3){
			case 0:
				if(YOU == 0 || YOU == 3) return 1;
				if(YCNT == 10 && SYU == 0+RT/3 && YOU == 1) return 1;
				if(YCNT == 10 && SYU == 2+RT/3 && YOU == 4) return 1;
			break;
			case 1:
				if(YOU == 1 || YOU == 4) return 1;
				if(YCNT == 10 && SYU == 0+RT/3 && YOU == 2) return 1;
				if(YCNT == 10 && SYU == 2+RT/3 && YOU == 5) return 1;
			break;
			case 2:
				if(YOU == 2 || YOU == SUT) return 1;
				if(YCNT == 10 && SYU == 0+RT/3 && YOU == 0) return 1;
				if(YCNT == 10 && SYU == 2+RT/3 && YOU == 3) return 1;
			break;
		}
	}else if(YCNT>=4){//週休２以上
		RT = rote_type;
		switch(RT%6){
			case 0:
				if(YOU == 0) return 1;
				if(YCNT == 6 && SYU == 0+RT/6 && YOU == 2) return 1;
				if(YCNT == 6 && SYU == 2+RT/6 && YOU == 4) return 1;
			break;
			case 1:
				if(YOU == 1) return 1;
				if(YCNT == 6 && SYU == 0+RT/6 && YOU == 3) return 1;
				if(YCNT == 6 && SYU == 2+RT/6 && YOU == SUT) return 1;
			break;
			case 2:
				if(YOU == 2) return 1;
				if(YCNT == 6 && SYU == 0+RT/6 && YOU == 4) return 1;
				if(YCNT == 6 && SYU == 2+RT/6 && YOU == 0) return 1;
			break;
			case 3:
				if(YOU == 3) return 1;
				if(YCNT == 6 && SYU == 0+RT/6 && YOU == SUT) return 1;
				if(YCNT == 6 && SYU == 2+RT/6 && YOU == 1) return 1;
			break;
			case 4:
				if(YOU == 4) return 1;
				if(YCNT == 6 && SYU == 0+RT/6 && YOU == 0) return 1;
				if(YCNT == 6 && SYU == 2+RT/6 && YOU == 2) return 1;
			break;
			case 5:
				if(YOU == SUT) return 1;
				if(YCNT == 10 && SYU == 0+RT/6 && YOU == 1) return 1;
				if(YCNT == 10 && SYU == 2+RT/6 && YOU == 3) return 1;
			break;
		}
	}else if(YCNT>=2){		
		RT = rote_type;
		switch(RT%6){
			case 0:
				if(SYU == 0+RT/6 && YOU == 2) return 1;
				if(SYU == 2+RT/6 && YOU == 4) return 1;
			break;
			case 1:
				if(SYU == 0+RT/6 && YOU == 3) return 1;
				if(SYU == 2+RT/6 && YOU == SUT) return 1;
			break;
			case 2:
				if(SYU == 0+RT/6 && YOU == 4) return 1;
				if(SYU == 2+RT/6 && YOU == 0) return 1;
			break;
			case 3:
				if(SYU == 0+RT/6 && YOU == SUT) return 1;
				if(SYU == 2+RT/6 && YOU == 1) return 1;
			break;
			case 4:
				if(SYU == 0+RT/6 && YOU == 0) return 1;
				if(SYU == 2+RT/6 && YOU == 2) return 1;
			break;
			case 5:
				if(SYU == 0+RT/3 && YOU == 1) return 1;
				if(SYU == 2+RT/3 && YOU == 3) return 1;
			break;
		}

	}
	return 0;

}
int EMPLOY::make(){
	int H[2],A[2],B[2],U[2],SK[10];
	int TEN = 50;

	//画像で基本ST決定
	switch(gra%100){
			case 0://店員・男
				stup_par( 80,130, 90,150, 80,130, 70,130);
				if(no<300){stup_ski(0,1,3,5,7,7,8,18,16,15)}//店員の場合
				else	 {stup_ski(0,1,3,5,7,7,8,28,30,33)}
				req_rate = 100 + GetRand(10);
			break;
			case 1://店員・女
				stup_par( 80,130, 90,150, 80,130, 70,130);
				if(no<300)	{stup_ski(0,1,3,5,7,7,8,18,16,15)}
				else		{stup_ski(0,1,3,5,7,7,8,28,30,33)}
				req_rate = 100 + GetRand(10);
			break;
            case 4://ポニテ
				stup_par( 80,130, 80,130, 90,150, 70,130);
				stup_ski(7,7,7,18,18,18,18,14,14,14);
				req_rate = 100 + GetRand(20);
			break;
            case 5://弓手
				stup_par(100,150, 80,130, 70,120, 80,120);
				stup_ski(0,1,1,1,3,3,3,3,4,4);
				req_rate = 100 + GetRand(10);
			break;
            case 37://女兵士
				stup_par(100,150, 80,120, 80,130, 70,120);
				stup_ski(0,1,1,1,3,3,3,3,4,4);
				req_rate = 100 + GetRand(10);
			break;
            case 7://ハゲ
				stup_par(120,160,120,160,120,160,100,150);
				if(no<300)	{stup_ski(1,1,3,21,15,15,15,18,18,18)}
				else		{stup_ski(1,1,3,21,28,28,30,30,33,33)}
				req_rate = 140 + GetRand(20);
			break;
            case 10://中年・男
				stup_par( 90,160,110,180, 90,160, 60, 90);
				if(no<300)	{stup_ski(0,1,1,3,5,7,8,16,16,16)}
				else		{stup_ski(0,1,1,3,5,7,8,28,30,33)}
				req_rate = 120 + GetRand(10);
			break;
            case 11://中年・女
				stup_par( 90,160, 90,160,110,180, 60, 90);
				if(no<300)	{stup_ski(0,1,1,3,5,7,8,16,16,16)}
				else		{stup_ski(0,1,1,3,5,7,8,28,30,33)}
				req_rate = 120 + GetRand(10);
			break;
            case 12://老人・男
				stup_par( 50,100, 60,155, 50,145, 50, 80);TEN=100;
				if(no<300)	{stup_ski(1,3,5,5,15,15,16,16,16,16)}
				else		{stup_ski(1,3,5,5,28,28,28,30,30,33)}
				req_rate = 100 + GetRand(10);
			break;
            case 13://老人・女
				stup_par( 50,100, 50,145, 60,155, 50, 80);TEN=100;
				if(no<300)	{stup_ski(1,3,5,5,20,20,16,16,16,16)}
				else		{stup_ski(1,3,5,5,28,30,30,33,33,33)}
				req_rate = 100 + GetRand(10);
			break;
            case 14://魔女
				stup_par( 70,120, 75,125,110,180, 90,150);
				stup_ski(28,28,28,30,30,33,33,26,26,26);
				req_rate = 130 + GetRand(10);
			break;
            case 19://魔族・女
				stup_par( 80,130,110,150, 90,140, 70,130);
				if(no<300)	{stup_ski(1,3,5,7,18,18,18,15,15,15)}
				else		{stup_ski(1,3,5,7,28,28,30,30,33,33)}
				req_rate = 110 + GetRand(10);
			break;
            case 20://魔族・男
				stup_par( 80,130,120,160, 80,130, 70,130);
				if(no<300)	{stup_ski(1,3,5,7,18,18,18,15,15,15)}
				else		{stup_ski(1,3,5,7,28,28,30,30,33,33)}
				req_rate = 110 + GetRand(10);
			break;
            case 22://鉢巻
				stup_par(110,170,110,170, 50, 70,100,150);
				stup_ski(0,1,1,3,3,7,7,7,9,9);
				req_rate = 120 + GetRand(10);
			break;
            case 26://覆面
				stup_par( 50,200, 50,200, 50,200,100,400);
				stup_ski(10,10,10,10,10,11,11,11,11,11);
				req_rate = 75 + GetRand(50);
			break;
            case 29://幼児・女
				stup_par( 50, 70, 60, 90, 50, 70,230,300);
				stup_ski(0,1,3,5,7,8,10,10,11,11);
				req_rate = 80 + GetRand(10);
			break;
            case 30://幼児・男
				stup_par( 50, 70, 50, 70, 60, 90,230,300);
				stup_ski(0,1,3,5,7,8,10,10,11,11);
				req_rate = 80 + GetRand(10);
			break;
			case 31://あらくれ
				stup_par(150,200, 90,150, 50, 80, 70,130);
				stup_ski(0,1,1,1,3,3,3,7,7,20);
				req_rate = 120 + GetRand(10);
			break;
            case 32://武人
				stup_par(120,130,120,130,120,130,120,130);TEN=-80;
				if(no<300)	{stup_ski(0,1,1,1,7,7,2,18,16,15)}
				else		{stup_ski(0,1,1,1,7,7,2,28,30,33)}
				req_rate = 120 + GetRand(10);
			break;
			default:
			break;
	}

	this->b_w = (5000+(70-fun.Rand(140))*(70-fun.Rand(140))) / 100;

	this->konjyou = fun.Rand(50) + 25;

	H[1] -= H[0];
	A[1] -= A[0];
	B[1] -= B[0];
	U[1] -= U[0];

	st_st[0] = H[0] + fun.Rand(H[1]);//下限と上限の間にランダム決定
	st_st[1] = A[0] + fun.Rand(A[1]);
	st_st[2] = B[0] + fun.Rand(B[1]);

	st_up[0] = (H[0]+H[1]/2) * fun.Rand(U[0]+fun.Rand(U[1]))/100;
	st_up[1] = (A[0]+A[1]/2) * fun.Rand(U[0]+fun.Rand(U[1]))/100;
	st_up[2] = (B[0]+B[1]/2) * fun.Rand(U[0]+fun.Rand(U[1]))/100;

    while(1)
    {
	    skill = SK[fun.Rand(9)];

	    if(this->job == 0 )
	    {
		    if( skill == 25 ||
		        skill == 28 ||
			    skill == 29 ||
			    skill == 30 ||
			    skill == 31 ||
			    skill == 33 || 
			    skill == 34 ||
			    skill == 35  ) continue;
	    }
	    else 
        if(this->job == 1 )
	    {
		    if( skill == 14 || 	
	    	    skill == 15 ||
			    skill == 16 ||
			    skill == 17 ||
			    skill == 18 ||
			    skill == 19 ||
			    skill == 22 ||
			    skill == 23 ) continue;
	    }
        break;
    }


	req_money_h = 0;
	
	//初期設定
	req_turn = no%10 * 5 + fun.Rand(10) - 7;

	if(req_turn < 1) req_turn = 1;

	//天才判定
	int R = fun.Rand(40);

	if(R == 0){//超天才
		st_st[0] += TEN/2 +fun.Rand(TEN);
		st_st[1] += TEN/2 +fun.Rand(TEN);
		st_st[2] += TEN/2 +fun.Rand(TEN);
		b_w = 0;
		req_rate += 50;
	}else if(R<5){//体力馬鹿
		st_st[0] += TEN/2 +fun.Rand(TEN);
		req_rate += 25;
		b_w /= 2;
	}else if(R<9){//製造・捌き
		st_st[1] += TEN/2 +fun.Rand(TEN);
		req_rate += 25;
		b_w /= 2;
	}else if(R<13){//開発・接客
		st_st[2] += TEN/2 +fun.Rand(TEN);
		req_rate += 25;
		b_w /= 2;
	}
	//初期ステータス代入＆補正
	st_st[0] = st_st[0] * data.st_rate / 100;
	st_st[1] = st_st[1] * data.st_rate / 100;
	st_st[2] = st_st[2] * data.st_rate / 100;
	
	st_up[0] = st_up[0] * (200-data.st_rate) / 100;
	st_up[1] = st_up[1] * (200-data.st_rate) / 100;
	st_up[2] = st_up[2] * (200-data.st_rate) / 100;

	st[0] = st_st[0];
	st[1] = st_st[1];
	st[2] = st_st[2];

	exp = 0;

	lv_up();

	status_cul();

	return 1;
}