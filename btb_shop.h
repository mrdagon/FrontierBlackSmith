#pragma once

int SHOP::kouji_end(){

	if(this->mana_cnt[M_TAKM] > 0)

	for(int E=0;E<EMP_M;E++){//匠リフォーム
		if(emp[E].shop_n != no || emp[E].now_job != 1) continue;
		emp[E].tension += 3;
	}

	logu.add("工事が完了しました",12,no);

	if(kouji != 0)
	{
		shop[no].senden_syori(100,200);
		kouji = 0;
	}
	
	if(mana_cnt[M_RIFO] > 0 ){//リフォームセール
		this->start_sell(80,7);
	}

	return 1;
}
int SHOP::start_sell(int Wari,int D){
	price_rate  = min(price_rate,Wari);
	yasuuri		= max(yasuuri,D);

	logu.add("セールを開始しました",12,P);

	char str[32];
	sprintf_s(str,"%d％セール開始!",100-Wari);
	logu.add(str,9,no);

	return 1;
}
int SHOP::senden_syori(int HIT,int LV){

	//LV % の確率で効果

	//品揃え更新
	//認知度回復
	LV  = LV  * senden_b /100;
	HIT = HIT * senden_b /100;

	for(int H=0;H<data.jinkou_max;H++){
		if(hun[H].life <= 0) continue;//死亡or未登録
		if(fun.Rand(99) < HIT){
			hun[H].sinazoroe(no);
			hun[H].shop_koukan[no] = max(hun[H].shop_koukan[no],LV); 
			hun[H].shop_koukan[no] = max(LV,hun[H].shop_koukan[no]);
			hun[H].senden_boost[no] = max(100+LV,hun[H].senden_boost[no]);
		}
	}

	cul_timeido();

	if(no == P) sys.total_senden++;

	return 1;
}
int SHOP::senden_day(){

	//雨天セール
	if(mana_cnt[M_UTES] >= 1 && data.tenki > 1){
		start_sell(80,1);
	}
	//セール終了
	if(yasuuri <=0 && price_rate != 100 - mana_cnt[M_HEIT] * 10){
		price_rate = 100 - mana_cnt[M_HEIT] * 10;
		logu.add("セール終了！",10,no);
	}

	//セール効果
	if(price_rate < 90 ){
		//通常セール
		senden_syori( int(( 50 - price_rate / 2 ) * yasuuri_efe) ,  300 - price_rate * 2 );
		yasuuri--;
		yasuuri_efe /= 1.5;
	}else if(mana_cnt[M_HEIT] > 0){
		//常態セール
		price_rate = 90;
		senden_syori( 2 ,  50 );
	}

	yasuuri_efe += 0.04;
	if(yasuuri_efe > 1 ) yasuuri_efe = 1;

	cul_timeido();

	return 1;
}
int SHOP::hirameki_wep(){

	int RF,REQ;
	int SE= 0;
	int KAI = 0;
	int K_NO = 0;
	int KP = 0;
	char str[100];

	int cre_cnt[WEP_M];//開発済み人数&特許補正
	int HB[WEP_M];
	int HOK[WEP_M];

	//基本武器の開発開放
	for(int W=0;W<10;W++){
		for(int T=0;T<4;T++){
			for(int S=0;S<3;S++){
				 int w = W+T*100+S*10;
				 if(this->wep_cre[w] == -1 && this->wep_sb[T][S] >= W){
					 wep_cre[w] = 0;
				 }
			}
		}
	}

	for(int i=0;i<10;i++){
		for(int T=0;T<4;T++){
			if(wep_cre[T*100+i] == -1    && wep_sb[T][0] > i) wep_cre[T*100+i] = 0;
			if(wep_cre[T*100+10+i] == -1 && wep_sb[T][1] > i) wep_cre[T*100+10+i] = 0;
			if(wep_cre[T*100+20+i] == -1 && wep_sb[T][2] > i) wep_cre[T*100+20+i] = 0;
		}
	}

	for(int s=0;s<data.shop_cnt;s++){
		for(int W=0;W<WEP_M;W++){
			HB[W] = 100;
			HOK[W] = 0;
			if(shop[s].wep_cre[W] == 2){
				if(shop[s].mana_cnt[M_TOCG]>0)	cre_cnt[W] = 1;//特許取得
				if(mana_cnt[M_KORO]>0)			HOK[W] = 1;//似通った武器
				HB[W] -= 5;
			}
		}
	}

	hirameki_dayb++;
	int HB2 = 100+hirameki_dayb*10;

	for(int W=0;W<WEP_M;W++){//開発済み、未開発ボーナス
		if(wep_cre[W] == 2 && mana_cnt[M_IDEC]>0) HB2++;
		if(wep_cre[W] == 1 && mana_cnt[M_HUMI]>0) HB2++;
	}

	if(emp_cnt == 0 || data.hirameki_rate == 0 || emp_kou <= 0) return 1;//店員０

	int R = fun.Rand(WEP_M-3)+1;
	int BS;

	for(int W=R+1;W!=R;W++){//必要値計算
		if(W >= WEP_M) W = 0;
		if(wep_cre[W] != 0 ) continue;

		if(cre_cnt[W]>0) continue;

		REQ = 0;//閃き率
		RF  = 0;//技術レベル差補正

		if(create_lv[0] < wep[W].req_clv[0]) RF += wep[W].req_clv[0]-create_lv[0];//技術レベル足りない
		if(create_lv[1] < wep[W].req_clv[1]) RF += wep[W].req_clv[1]-create_lv[1];
		if(create_lv[2] < wep[W].req_clv[2]) RF += wep[W].req_clv[2]-create_lv[2];

		if( create_lv[0] > wep[W].req_clv[0] &&//技術レベル高すぎ
			create_lv[1] > wep[W].req_clv[1] &&
			create_lv[2] > wep[W].req_clv[2] &&
			wep[W].rank<50){

			if(mana_cnt[M_LOST] > 0) RF+= max(max(create_lv[0] - wep[W].req_clv[0] , create_lv[1] - wep[W].req_clv[1]) , create_lv[2] - wep[W].req_clv[2])/4;
			else				  RF+= max(max(create_lv[0] - wep[W].req_clv[0] , create_lv[1] - wep[W].req_clv[1]) , create_lv[2] - wep[W].req_clv[2])/2;
		}

		if(HOK[W] == 1) RF = 0;//似通った武器

		BS  = 0;
		//下位武器改良による補正
		if(W > 0 && wep[W].gazou == wep[W-1].gazou && wep_cre[W-1] == 2){
			BS = this->wep_kaicnt[W-1];
		}

		REQ = (100 + wep[W].rank * 10 - BS)*(10+RF*RF) / 2;//確率計算
		//100～

		if(RF >= 10) continue;
        if(RF <=  1) REQ /= 2;//差が殆ど無いと確率大UP

		for(int i = 0;i<emp_cnt;i++){//一番閃き率が高い奴を算出
			int E = emp_list[i];
			if(emp[E].job == 0) continue;
			KP  = fun.Rand(emp[E].st_st[2])+1;
			if(emp[E].skill == 30) KP += KP/5;
			if(emp[E].skill == 31) KP += KP/2;

			if(KP > KAI){
				KAI = KP;
				K_NO = E;
			}
		}

		KP *= HB2 * HB[W];
		KP /= REQ;

		//各種補正
		if(fun.Rand(100000) <= KP){//閃き判定
			wep_cre[W] = 1;//開発可能にする
			if(no==P){
				fun.list_pw(W);//リスト最後尾に追加
				sprintf_s(str,"「%s」開発可!",wep[W].name.c_str());
				logu.add(str,1000+W,P);
				SE = 1;
			}
			wep_hday[W]=data.day;
			emp[K_NO].sell_now += 1;	//開発ボーナス
			hirameki_dayb=0;
			break;
		}

	}

	if(SE == 1){//閃きあり
		fun.se_ok(5);
	}

	return 1;
}
int SHOP::hirameki_mana(){

	//株式系
	if(mana_cnt[141] == 0 && kabu_rate[3] > 20) mana_rest[141] = 1;
	if(mana_cnt[142] == 0 && kabu_rate[3] > 30) mana_rest[142] = 1;
	if(mana_cnt[143] == 0 && kabu_rate[3] > 50) mana_rest[143] = 1;
	
	if(mana_cnt[144] == 0 && kabu_rate[2] > 20) mana_rest[144] = 1;
	if(mana_cnt[145] == 0 && kabu_rate[2] > 30) mana_rest[145] = 1;
	if(mana_cnt[146] == 0 && kabu_rate[2] > 50) mana_rest[146] = 1;

	if(mana_cnt[205] == 0 && kabu_rate[4] > 20) mana_rest[205] = 1;
	if(mana_cnt[206] == 0 && kabu_rate[4] > 30) mana_rest[206] = 1;
	if(mana_cnt[207] == 0 && kabu_rate[4] > 40) mana_rest[207] = 1;
	if(mana_cnt[208] == 0 && kabu_rate[4] > 50) mana_rest[208] = 1;

	if(mana_cnt[209] == 0 && kabu_rate[1] > 20) mana_rest[209] = 1;
	if(mana_cnt[210] == 0 && kabu_rate[1] > 30) mana_rest[210] = 1;
	if(mana_cnt[211] == 0 && kabu_rate[1] > 40) mana_rest[211] = 1;
	if(mana_cnt[212] == 0 && kabu_rate[1] > 50) mana_rest[212] = 1;

	//経営戦術閃き
	for(int i=0;i<MANA_M;i++){

		if( mana_rest[i]>0 &&
			mana[i].b_w_d  < b_w &&
			mana[i].b_w_u  > b_w &&
			mana[i].rank   <= bumon_lv[mana[i].type]){
			if(mana_ok[i] == 0){
				mana_ok[i] = 1;
				mana_day[i] = data.day;
			}
		}else{
			mana_ok[i]= 0;
		}
	}

	if(kabu_rate[0] > 95) mana_ok[61] = 0;//減資

	if(kouji > 0){//工事中
		mana_ok[121] = 0;
		mana_ok[123] = 0;
		mana_ok[124] = 0;
		mana_ok[125] = 0;
		mana_ok[126] = 0;
		mana_ok[127] = 0;
		mana_ok[128] = 0;
		mana_ok[129] = 0;
		mana_ok[130] = 0;
		mana_ok[131] = 0;
		mana_ok[132] = 0;
		mana_ok[133] = 0;
		mana_ok[136] = 0;
		mana_ok[137] = 0;
		mana_ok[139] = 0;
	}

	if (kabu_cnt[0] + kabu_buy >= kabu_max)			mana_ok[61] = 0;
	if(kabu_cnt[1] + kabu_buy >= data.kabu_cnt[1]) mana_ok[62] = 0;
	if (kabu_cnt[2] + kabu_buy >= data.kabu_cnt[2]) mana_ok[63] = 0;
	if (kabu_cnt[3] + kabu_buy >= data.kabu_cnt[3]) mana_ok[64] = 0;
	if (kabu_cnt[4] + kabu_buy >= data.kabu_cnt[4]) mana_ok[65] = 0;

	if(kabu_cnt[1] <= kabu_buy) mana_ok[93] = 0;
	if (kabu_cnt[2] <= kabu_buy) mana_ok[94] = 0;
	if (kabu_cnt[3] <= kabu_buy) mana_ok[95] = 0;
	if (kabu_cnt[4] <= kabu_buy) mana_ok[96] = 0;

	fun.list_sort();

	return 1;
}
int SHOP::kairyou(int W){
	//改良する

	int A;
	int C;
	int N;
	int T;

	if(mana_cnt[M_BARA]==0){
		A = atk_kai[W]   + 3;
		C = cost_kai[W]  + 3;
		N = ninki_kai[W] + 3;
		T = time_kai[W]  + 3;
	}else{//バランス処理
		A = atk_kai[W]/2   + 6;
		C = cost_kai[W]/2  + 6;
		N = ninki_kai[W]/2 + 6;
		T = time_kai[W]/2  + 6;
	}

	int R = fun.Rand(A+C+N+T);

	if(		R < A		) atk_kai[W]   += 3;
	else if(R < A+C		) cost_kai[W]  += 3;
	else if(R < A+C+N	) ninki_kai[W] += 3;
	else				  time_kai[W]  += 3;

	wep_kaicnt[W]++;
	wep_kaiexp[W] =0;

	cul_kaihosei();

	return 1;
}
int SHOP::make(int W){

	wep_make_t[W] ++;

	if(wep_rest[W]<=0 && W!= NOU_NO){//農具以外作成＆在庫０
		tana_now++;
		tana_now_t[wep[W].type]++;
	}

	souko_now ++;
	wep_rest[W] ++;

	wep_make[W] = 0;
	money					-= int(wep[W].price * wep[W].seizou_cost * cost_j[W]);
	incom_mon[data.mon]     -= int(wep[W].price * wep[W].seizou_cost * cost_j[W]);
	seizc_day[data.day]++;
	seiz_day[data.day]		-= int(wep[W].price * wep[W].seizou_cost * cost_j[W]);
	seizc_mon[data.mon]++;
	seiz_mon[data.mon]		-= int(wep[W].price * wep[W].seizou_cost * cost_j[W]);

	if(no == P){
		sys.total_make++;
		sys.total_makec+= int(wep[W].price * wep[W].seizou_cost * cost_j[W]);
		sys.wep_maket[W]++;
	}

	return 1;
}
int SHOP::kaihatu(int W){

	char str[256];

	if(wep_cre[W]!=2){
		wep_rest[W] = 10 + mana_cnt[M_AHUR]*20;//試作品が10個
		souko_now  += 10 + mana_cnt[M_AHUR]*20;
		wep_cre[W]  = 2;
		wep_make[W] = 0;
		tana_now++;
		tana_now_t[wep[W].type]++;
		seizc_day[data.day]+= 10;
		seizc_mon[data.mon]+= 10;
		money -= wep[W].create_time/48;//開発費支払い+製造費合計＋
		seiz_day[data.day]-= wep[W].create_time/54;
		seiz_mon[data.mon]-= wep[W].create_time/54;
		incom_mon[data.mon] -= wep[W].create_time/54;
		if(data.wep_ganso[W] == -1) data.wep_ganso[W]=no;
	}
	if(no==P){
		sprintf_s(str,"「%s」開発完了",wep[W].name.c_str());
		fun.se_ok(2);
		sys.total_kaihatu++;
		sys.wep_cret[W]++;
		sys.wep_maket[W]+=10 + mana_cnt[M_AHUR]*20;
		sys.total_make += 10 + mana_cnt[M_AHUR]*20;
	}else{
		sprintf_s(str,"「%s」販売開始！",wep[W].name.c_str());
	}

	if(data.wep_ganso[W] == no)	logu.add(str,2000+W,no);
	else						logu.add(str,3000+W,no);

	if(mana_cnt[194]>0){
		n_mp += 10;
	}
	if(mana_cnt[M_NSEL]>0){
		senden_syori(20,100);
	}

	cul_seiz_kair();//生産速度等再計算

	return 1;
}
int SHOP::day_mana(){

	//経営戦術使用
	ai.wep_sel(no);
	ai.mana_sel(no);

	for(int MA=0;MA<MANA_M;MA++)
	{//経営戦術使用
		if(use_mana >0 && syou_mp[use_mana] * mana_b[mana[use_mana].type] / 100 <= n_mp )
		{
			if (EVE_FUN::Sin().mana_syori(no, MA) == 1)
			{
				this->ai_like[MA / 60] = 0;
				if(P == no)fun.se_ok(1);
			}
		}
	}
	//工事日数等計算
	if(holiday > 0) holiday--;

	if(kouji > 0){
		kouji--;
		if(kouji == 0 || kouji == 100){
			kouji_end();
		}else	holiday = max(1,holiday);
	}
	if(data.day % 7 == teikyuu){
		holiday = max(1,holiday);
	}

	return 1;
}
int SHOP::day_start(){

	kabu_mon[data.mon] = (int)kabu_price;

	ai.koyou_sel(no);//雇用者選択

	for(int i=0;i<emp_cnt;i++)
	{
		int e = emp_list[i];
		emp[e].rote_type = i%12;
	}

	//AI調整
	for (int i = 0; i < 5;i++)
	{
		ai_like[i] += GetRand(100);
	}
    
    if(no == 0) ai_like[0] += GetRand(50);//経営好き
    if(no == 1) ai_like[2] += GetRand(50);//工事好き
    if(no == 2) ai_like[4] += GetRand(50);//宣伝好き
    if(no == 3) ai_like[3] += GetRand(50);//開発好き
    if(no == 4) ai_like[1] += GetRand(50);//財務好き


	//倉庫料金
	if(souko_now > souko_max){
		money			   -= (souko_now-souko_max)*10;
		etc_mon[data.mon]  -= (souko_now-souko_max)*10;
	}else if(mana_cnt[M_KUUK] > 0){
		money			   -= (souko_now-souko_max)*3;
		etc_mon[data.mon]  -= (souko_now-souko_max)*3;
	}

	//急募効果
	if(kyuubo != 0){
		int i;
		int c=0;
		for(int n=0;n<1000;n++)
        {
			i= 101+(kyuubo-1)*200 + fun.Rand(198);
			if( emp[i].now_job == 3)
            {
				emp[i].now_job = 0;
				emp[i].shop_n = this->no;
				c++;
				if(c >= 2 ) break;
			}
		}
		kyuubo = 0;
	}

	//客数初期化
	cust_cnt = 0;
	for(int W=0;W<4;W++)cust_cnt_t[W] = 0;		
	for(int W=0;W<1000;W++)cust_list[W]=-1;//客をリストから排除		

	//改善強化週
	if(kaizen_week>0)kaizen_week--;

	//閃き判定
	if(data.day > 17 || data.mode != 0){
		hirameki_wep();//閃き判定
		hirameki_mana();//閃き判定
	}

	n_mp += p_mp;//回復

	if(n_mp > 10000) n_mp = 10000;//最大は1000
		
	if(data.day%7==0){
		koubou_t = koubou_n;//残業時間変化
	}

	//目玉商品設定
	if(no == P){
		for(int W=0;W<7;W++){
			wep_medama[W] = -1;
		}

		for(int W=0;W<medama_max;W++){
			if( W == wind.wfold_cnt[0]) break;
			wep_medama[W] = wind.wfold_list[0][W];
		}
	}

	kabu_mon[data.mon-1] = (int)kabu_price;
	senden_day();//宣伝処理

	cul_seiz_kair();
	cul_kenkyuu();

	cul_kaburate();
	cul_medama();
	cul_kaihosei();

	return 1;
}
int SHOP::mon_start(){

	cul_ave();

	ai.taiguu_sel(no);//待遇計算
	ai.koyou_sel(no);//雇用者選択
	n_mp += mp_ninnzuu * emp_cnt;

	mana_cnt[244] = 1;//月刊系雑誌MP回復
	if(data.mon % 3 == 1) mana_cnt[245] = 1;	
	if(fun.Rand(11) == 0) mana_cnt[246] = 1;

	//飲み会系MP回復
	mana_cnt[40] = 0;
	mana_cnt[41] = 0;
	mana_cnt[42] = 0;
	mana_cnt[43] = 0;
	if(data.mon % 12 == 0) mana_cnt[43] = 1;//新年会
	if(data.mon % 12 == 3) mana_cnt[40] = 1;//お花見
	if(data.mon % 12 == 6) mana_cnt[41] = 1;//夏休み
	if(data.mon % 12 == 9) mana_cnt[42] = 1;//お月見

	//農具納品
	if(nougu_req<= wep_rest[NOU_NO]){//達成
		nougu_mon[data.mon-1] = nougu_req;
		if(no == P) sys.total_matokku += nougu_req;
		wep_rest[NOU_NO] -= nougu_req;
		souko_now -= nougu_req;
		money += wep[NOU_NO].price * 100 * nougu_req;
		sell_mon[data.mon-1] += wep[NOU_NO].price * 100 * nougu_req;
		nougu_req += nougu_up;//基本+3
	}else{
		nougu_mon[data.mon-1] = wep_rest[NOU_NO];
		if(no == P) sys.total_matokku += wep_rest[NOU_NO];
		money += wep[NOU_NO].price * 100 * wep_rest[NOU_NO];
		sell_mon[data.mon-1] += wep[NOU_NO].price * 100 * wep_rest[NOU_NO];
		nougu_req -= nougu_up;
		souko_now -= wep_rest[NOU_NO];
		wep_rest[NOU_NO] = 0;
		if(nougu_req<10)nougu_req = 10;

	}
	//利子処理
	if(money>0){//預金
		etc_mon[data.mon-1] += int(money/100*risi_rate/100);//基本1%
		money				+= int(money/100*risi_rate/100);
	}else{//借金
		etc_mon[data.mon-1] -= int(money*3/100*risoku_rate/100);//基本3%
		money				-= int(money*3/100*risoku_rate/100);
	}
	//株価配当 2%
	int kabu_h = 0;
	kabu_h += (int)(data.kabu_price[1] * this->kabu_cnt[1] / 50);
	kabu_h += (int)(data.kabu_price[2] * this->kabu_cnt[2] / 50);
	kabu_h += (int)(data.kabu_price[3] * this->kabu_cnt[3] / 50);
	kabu_h += (int)(data.kabu_price[4] * this->kabu_cnt[4] / 50);
	etc_mon[data.mon-1] += kabu_h;
	money				+= kabu_h;

	//税金処理
	int RM = sell_mon[data.mon-1]/5*tax_b/100;//売上の20%
	money				 -= RM;//売上の20%
	etc_mon[data.mon-1] -= RM;//武器売上の20%

	incom_mon[data.mon-1] = sell_mon[data.mon-1];
	incom_mon[data.mon-1] += seiz_mon[data.mon-1];
	incom_mon[data.mon-1] += emp_mon[data.mon-1];
	incom_mon[data.mon-1] += etc_mon[data.mon-1];
	incom_mon[data.mon-1] += manege_mon[data.mon-1];

	RM = incom_mon[data.mon-1]/5*tax_b/100;
	money				 -= RM;
	etc_mon[data.mon-1]  -= RM;
	incom_mon[data.mon-1]-= RM;

	total_mon[data.mon-1] = int(money);
	for(int W=0;W<WEP_M;W++){
		total_mon[data.mon-1]+= wep[W].price * wep_rest[W] * 100;
	}
	//株価処理
	int up_sisan = 0;

	if(data.mon < 2){
		up_sisan = incom_mon[data.mon-1] - incom_mon[data.mon-2];
	}else{
		up_sisan = incom_mon[data.mon-1];
	}

	kabu_price += (up_sisan + incom_mon[data.mon-1]/10) / kabu_max;
	kabu_price = max(kabu_price,0);
	//ブラック度変化
	b_w = b_w/2 + (50 - int(mon_ave*2) + bw_bonus)/2;
	if(b_w <   0) b_w =   0;
	if(b_w > 100) b_w = 100;
	cul_kaburate();

	return 1;
}
int SHOP::cul_seiz_kair(){

	int nin_cnt[WEP_M];

	for(int W=0;W<WEP_M;W++){
		wep_make_now[W] = 0;
		wep_kai_now[W] = 0;
	}

	no = no;

	for(int C=0;C<emp_cnt;C++){
		int E = emp_list[C];
		if(emp[E].job == 0 || emp[E].rest > 0) continue;//店員は無視
		//開発値＆製造値	
		int R = 1;
		int W = emp[E].shift;

		if(wep_cre[W] == 2){//製造中
			wep_make_now[W] += emp[E].st_st[1] * seizou_b / 100;
			wep_kaiexp[W]   += emp[E].st_st[2] * kairyou_b / 100;
		}else{//開発中
			if(	    emp[E].skill == 30) R = 2;
			else if(emp[E].skill == 31) R = 3;
			wep_make_now[W] += emp[E].st_st[1]* R * kaihatu_b / 100;
		}

		R = 1;
		if(emp[E].skill		 == 33) R = 2;
		else if(emp[E].skill == 34) R = 3;
		else if(emp[E].skill == 35) R = -1;

		wep_kai_now[W] += R * emp[E].st_st[2] * 10;
		nin_cnt[W] ++;
	}
	//人月補正等
	for(int W=0;W<WEP_M;W++){
		if(kaizen_week > 0) wep_kai_now[W]*=3;//カイゼン週間

		if(wep_cre[W] == 2) continue;
		if(nin_cnt[W] > 0 && mana_cnt[M_NILE] == 0){//人月神話
			wep_make_now[W] = (int)pow(double(wep_make_now[W]),double(1)/nin_cnt[W]);
		}
		if( wep_kai_now[W] < 0) wep_kai_now[W] = 0;  
		if(mana_cnt[M_AJYA]>0){//アジャイル
			wep_make_now[W]*=2;
			wep_kai_now[W] = 0;
		}
	}

	return 1;
}
int SHOP::cul_kenkyuu(){
	int R;
	int MAX= 0;

	create_get[0] = 0;
	create_get[1] = 0;
	create_get[2] = 0;
	
	//研究力計算
	for(int C=0;C<emp_cnt;C++){
		int E = emp_list[C];
		if(emp[E].job == 0 || emp[E].rest>0) continue;//店員 or　休み

		//武器研究値＋
		if(emp[E].skill == 28)		R = 150;
		else if(emp[E].skill == 29)	R = 200;
		else						R = 100;
		R = fun.Rand(R * emp[E].st_st[2]) + emp[E].st_st[2];

		if( R > MAX){
			MAX = R;
			if(teikyuu<7) R += R/5;//定休日がある場合２割増し
			create_get[0] = 0;
			create_get[1] = 0;
			create_get[2] = 0;
			switch(wep[emp[E].shift%WEP_M].type){//技術力
				case 1:
					create_get[0] = R/10;break;//研磨
				case 2:
					create_get[1] = R/10;break;//錬鉄
				case 3:
					create_get[2] = R/10;break;//細工
				case 0:
					create_get[0] = R/30;
					create_get[1] = R/30;
					create_get[2] = R/30;
				break;
			}
		}
	}

	return 1;
}
int SHOP::cul_ave(){

	double total_LV,total_PAY,total_MON;
	
	total_LV  = 0;
	total_PAY = 0;
	total_MON = total_yame;
	for(int i=0;i<emp_cnt;i++){
		int E = emp_list[i];
		total_LV  += emp[E].lv;
		total_PAY += emp[E].pay_money;
		total_MON += emp[E].kinzoku;
	}

	lv_ave  = max(total_LV/max(emp_cnt,1),1);
	pay_ave = total_PAY/max(emp_cnt,1);
	mon_ave = total_MON/max(total_saiyou,1);
	
	return 1;
}
int SHOP::cul_kaihosei(){

	for(int W=0;W<WEP_M;W++){

		atk_j[W]    = (2 - double(100) / (100 + atk_kai[W]))*atk_b/100;
		cost_j[W]   = double(100) / (100 + cost_kai[W]);
		ninki_j[W]  = 2 - double(100) / (100 + ninki_kai[W]);
		time_j[W]   = double(100) / (100 + time_kai[W]);
		dur_j[W]    = double(dur_b)/100;

		if(wep_kaicnt[W] >= 100 && mana_cnt[M_ENAL]>0){
			ninki_j[W] *= 2;
			atk_j[W]   *= 2;
		}

		//目玉商品ボーナス
		if(wep[W].type < 4 && wep[W].zoku < 3)
        {
			ninki_j[W] *= medama_wept[wep[W].type] * medama_zoku[wep[W].zoku];
		}

		//元祖補正
		if(data.wep_ganso[W] == no) ninki_j[W]*= 1.1 + mana_cnt[M_HOMO]*0.1;
		
	}

	//目玉商品効果
	for(int W=0;W< medama_max;W++)
    {
		int N = wep_medama[W];
		if(N <= 0) continue;
		ninki_j[N]*= 1.20;
	}

	return 1;
}
int SHOP::cul_timeido(){

	timeido = 0;
	double total_timeido = 0;

	for(int i=0;i<data.jinkou_max;i++){
		if(hun[i].life <= 0) continue;
		total_timeido += 1.0 * hun[i].shop_koukan[no] * hun[i].senden_boost[no]/10;
	}

	timeido = total_timeido / max(data.jinkou,1);

	return 1;
}
int SHOP::cul_kaburate(){
	//株保持率再計算
	int R[5] = {0,0,0,0,0};

	data.kabu_cnt[0] = kabu_max;

	for(int S=0;S<5;S++){
		kabu_rate[S] = double(kabu_cnt[S]) * 100 / max(data.kabu_cnt[S],1);
		R[S] = (int)kabu_rate[S];
		if(kabu_rate[S]		 > 50) R[S] *= 2;
	}

	p_mp     += 0.01 * (R[0] - kabu_rank[0]);
	sinn_b   += int(0.5  * (R[1] - kabu_rank[1]));
	cost_b   -= int(0.1 * (R[2] - kabu_rank[2]));
	kairyou_b+= int(0.1 * (R[3] - kabu_rank[3]));
	senden_b += int(0.1 * (R[4] - kabu_rank[4]));

	for(int S=0;S<5;S++){
		kabu_rank[S] = R[S];
	}

	syou_money[61] = kabu_buy * (int)kabu_price;
	syou_money[62] = kabu_buy * (int)data.kabu_price[1];
	syou_money[63] = kabu_buy * (int)data.kabu_price[2];
	syou_money[64] = kabu_buy * (int)data.kabu_price[3];
	syou_money[65] = kabu_buy * (int)data.kabu_price[4];

	return 1;
}
int SHOP::cul_medama(){

	medama_wept[0] = 1;
	medama_wept[1] = 1;
	medama_wept[2] = 1;
	medama_wept[3] = 1;
	
	medama_zoku[0] = 1;
	medama_zoku[1] = 1;
	medama_zoku[2] = 1;

	for(int W=0;W< medama_max;W++){
		int N = wep_medama[W];
		if(N < 0 || wep_cre[N] != 2) continue;//開発中or未設定
		medama_wept[wep[N].type] *= double(1000+wep[N].mtype)/1000;
		medama_zoku[wep[N].zoku] *= double(1000+wep[N].mzoku)/1000;
	}

	return 1;
}
int SHOP::medama_check(int W){

	for(int C=0;C< medama_max;C++){
		if(wep_medama[C] == W) return 1;
	}

	return 0;
}

int SHOP::goal_check(){

	g_wepcre = 0;

	for(int i=0;i<WEP_M;i++){
		if(this->wep_cre[i] == 2){
			g_wepcre++;
		}
	}

	g_kabu = (int)shop[P].kabu_price * shop[P].kabu_max;
	g_turu =  this->wep_make_t[NOU_NO];
	g_money = (int)money;

	//判定処理 -1　なら未達成 0～11でどれか達成

	if(data.goal_cust    > 0 && data.goal_cust    <= g_cust   ) return 0;
	if(data.goal_kabu    > 0 && data.goal_kabu    <= g_kabu   ) return 1;
	if(data.goal_sell_t  > 0 && data.goal_sell_t  <= g_sell_t ) return 2;
	if(data.goal_sell[0] > 0 && data.goal_sell[0] <= g_sell[0]) return 3;
	if(data.goal_sell[1] > 0 && data.goal_sell[1] <= g_sell[1]) return 4;
	if(data.goal_sell[2] > 0 && data.goal_sell[2] <= g_sell[2]) return 5;
	if(data.goal_sell[3] > 0 && data.goal_sell[3] <= g_sell[3]) return 6;
	if(data.goal_turu	 > 0 && data.goal_turu	  <= g_turu	  ) return 7;
	if(data.goal_wepcre  > 0 && data.goal_wepcre  <= g_wepcre ) return 8;
	if(data.goal_money   > 0 && data.goal_money   <= money  ) return 9;
	if(data.goal_taikai  > 0 && data.goal_taikai  <= g_taikai ) return 10;
	if(data.goal_boss	 > 0 && data.goal_boss    <= g_boss   ) return 11;
	
	//破産チェック、プレイヤーのみ
	if(-int(shop[P].money) > g_kabu && no == P) return 512;

	return -1;
}

int SHOP::reset(){
	//ステータス初期化
	emp_cnt		 = 0;
	emp_kou		 = 0;//工房人数

	money = 3000000;//基本300万

	nougu_req = 30;//基本農具30

	kabu_price = 10000;//株価
	kabu_max   = 1000;//株最大数

	for(int N=0;N<5;N++){
		if(N==0) kabu_cnt[N]   = 501;//株保持数
		else	 kabu_cnt[N]   = 0;
		kabu_rank[N] = 0;
	}

	b_w			= 50;//ブラック度0～100、１万で１００％
	koubou_t	= 54;//工房営業時間
	koubou_n	= 54;//次の日工房時間
	zangyou     = 57;//最大残業時間		初期不可

	for(int N=0;N<3;N++){
		create_get[N] = 0;//獲得開発経験値
		create_exp[N] = 0;//開発経験値
		create_lv[N]  = 0;//開発力
		wep_sb[0][N] = 3;//基本武器閃き
		wep_sb[1][N] = 3;//基本武器閃き
		wep_sb[2][N] = 3;//基本武器閃き
		wep_sb[3][N] = 3;//基本武器閃き
	}

	for(int W = 0;W<WEP_M;W++){
		wep_rest[W] = 0;//在庫数
		wep_hday[W] = 0;//閃いた日数
		wep_make[W] = 0;//生産進行度
		wep_kaicnt[W] = 0;//改良回数
		wep_make_t[W] = 0;//総生産数
		wep_make_now[W] = 0;//投入生産力
		wep_kaiexp[W] = 0;
		//改良回数
		ninki_kai[W] = 0;//人気
		atk_kai[W]	 = 0;//攻撃
		dur_kai[W]	 = 0;//耐久
		cost_kai[W]	 = 0;//コスト
		time_kai[W]  = 0;//時間
	}

	yasuuri    = 0;//ｾｰﾙ期間
	price_rate = 100;//販売価格
	yasuuri_efe = 1;

	for(int i=0;i<5;i++){
		bumon_lv[i]    = 1;//
		bumon_exp[i]   = 0;//
	}

	total_saiyou= 0;//累計採用数
	total_yame  = 0;//辞めた人の合計勤続日数

	bw_bonus    = 0;//ブラック度ボーナス値

	yasumi_max  = 4;//休日数			休み数

	seizou_b    = 100;
	kairyou_b   = 100;
	tukare_b    = 100;
	sekkyaku_b  = 100;
	kaihatu_b   = 100;
	sabaki_b    = 100;
	stress_b    = 100;
	yaruki_b    = 100;//やる気上昇率

	size		= 0;
	kouji	    = -1;//工事残り日数

	souko_max   = 500;//倉庫最大数

	teikyuu		= (no+1)%5;//定休日
	cust_cnt	= 0;//来客数

	for(int N=0;N<4;N++){
		cust_cnt_t[N] ;//武器種類毎の現在来客数
		cust_wep[N];//武器種類別来客数
	}

	p_mp = 5;//回復マネジメントポイント
	n_mp = 0;//現在マネジメントポイント
	use_mana = -1;//使用戦術

	for(int N=0;N<DAY_M;N++){
		sellc_day[N]   = 0;//販売数
		sell_day[N]    = 0;//売り上げ
		cust_day[N][0] = 0;//客数
		cust_day[N][1] = 0;//客数
		cust_day[N][2] = 0;//客数
		cust_day[N][3] = 0;//客数
		seizc_day[N]   = 0;//製造数
		seiz_day[N]    = 0;//製造費
		shera_wepd[N][0] = 0;//各武器の販売シェア
		shera_wepd[N][1] = 0;//各武器の販売シェア
		shera_wepd[N][2] = 0;//各武器の販売シェア
		shera_wepd[N][3] = 0;//各武器の販売シェア
	}

	for(int N=0;N<MANTH_M;N++){
		sellc_mon[N] = 0;//販売数
		sell_mon[N]  = 0;//売り上げ
		cust_mon[N]  = 0;//客数
		seizc_mon[N] = 0;//製造数
		seiz_mon[N]  = 0;//製造費

		emp_mon[N]   = 0;//雇用費//月末に計算
		manege_mon[N]= 0;//経営戦術費用
		etc_mon[N]   = 0;//税,利子月末に計算
		incom_mon[N] = 0;//利益月末に計算
		nougu_mon[N] = 0;//農具納入数
		total_mon[N] = 0;//総資産//月末に計算
		kabu_mon[N]  = 0;//株価

		shera_wepm[N][0] = 0;//各武器の販売シェア
		shera_wepm[N][1] = 0;//各武器の販売シェア
		shera_wepm[N][2] = 0;//各武器の販売シェア
		shera_wepm[N][3] = 0;//各武器の販売シェア
	}

	holiday = 0;
	timeido = 0;

		//追加仕様Δ
	for(int N=0;N<5;N++){
		mana_b[N]=100;//戦術使用ＭＰ補正
		mana_gb[N]=100;//戦術使用資金補正
	}

	mensetu_lv=20;//面接率

	kaihuku_b   =100;//回復補正
	kaihuku_bs   =100;//回復補正、新入り
	exp_b		 =100;//経験値補正
	exp_bs		 =100;//経験値補正、新入り
	monster_b	 =100;//クレーマー発生率補正
	syakai_b	 =100;//社会人度変化ボーナス
	hp_up_b		 =0;//HP成長率ボーナス
	sei_up_b     =0;//製造成長率
	kai_up_b     =0;//開発成長率
	kya_up_b     =0;//客捌成長率
	sek_up_b     =0;//接客成長率

	mp_ninnzuu   =0;//人数によるＭＰ回復ボーナス

	sk_pup		 =0;//スキル強化確率
	sk_rup		 =0;//スキル反転確率
	sk_qup		 =0;//？スキル変化確率

	kabu_buy	 =50;//株取引量
	nougu_up	 =3;
	kyuuryou_b   =100;//支払い率率
	risoku_rate  =100;//借金利息
	risi_rate	 =100;//貯金利子
	cost_b		 =100;//コスト補正
	atk_b		 =100;//攻撃力ボーナス
	dur_b		 =100;

	kaicost_b	 =100;//開発コスト補正

	bukimatu_b	 =100;//武器祭りボーナス
	turumatu_b	 =100;//つるはし祭りボーナス
	tax_b		 =100;//税金率

	for(int N=0;N<4;N++){
		hirameki_b[N]=100;//武器種別閃き補正
	}

	hirameki_dayb = 0;
	senden_b=100;

	kaizen_week=0;

	for(int N=0;N<3;N++){
		ken_b[N]  = 100;//研究経験補正
		ninki_b[N] = 100;//集客補正、属性別
	}

	otona_b=100;//大人買い補正

	koukan_down = 0;

	saitei_koukan = 1;//好感度最低値

	jisyoku_b=100;//辞職確率補正

	eve_efe=-1;//イベントによる特殊効果
	eve_turn=-1;//特殊効果残り時間		

	sinn_b = 0;

	for(int M=0;M<MANA_M;M++){
		mana_ok[M]  = 0;//経営戦略使用状況 -1使用不可 0使用可能　1使用中
		mana_cnt[M] = 0;//使った回数
		mana_day[M] = 0;//閃いてからの日数
	}
		
	for(int W=0;W<7;W++){
		wep_medama[W] = -1;
	}

	medama_max = 1;

	g_cust = 0;//総来客○
	g_kabu = this->kabu_cnt[0] * (int)this->kabu_price;//株価時価○
	g_sell_t = 0;//総売り上げ○
	g_sell[0] = 0;//武器種別売り上げ○
	g_sell[1] = 0;//武器種別売り上げ○
	g_sell[2] = 0;//武器種別売り上げ○
	g_sell[3] = 0;//武器種別売り上げ○
	g_turu = 0;//つるはし総生産○
	g_wepcre = 0;//武器総開発○
	g_money = 0;//総資金○
	g_taikai = 0;//総大会得点○
	g_boss = 0;//総ボス討伐○

	kyuubo = 0;

	//客一覧
	for(int H=0;H<SHOP_SP;H++){
		cust_list[H] = -1;
	}

	cul_kaburate();

	return 1;
}

int SHOP::eve_random(){
	
	//シナリオモードは二ヶ月間イベント発生なし
	if(data.mode == 0 && data.day < 56) return -1;

	int R = 0;
	if(mana_cnt[M_ELVE] > 0) R = fun.Rand(9000);
	else					 R = fun.Rand(10000);


	//HP回復
	R -= 100 - int(b_w);
	if(R <= 0){
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job != 1 || emp[E].shop_n != no) continue;
			emp[E].hp_gain(25);
		}
		logu.add("EV:アロマでＨＰが回復",13,no);
		return 1;
	}

	//ストレス回復
	R -= 100 - int(b_w);
	if(R <= 0){
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job != 1 || emp[E].shop_n != no) continue;
			emp[E].sun -= 10;
			if(emp[E].sun < 0) emp[E].sun = 0;
		}
		logu.add("EV:ハーブでストレスが回復",13,no);
		return 1;
	}

	//テンションアップ
	R -= 100 - int(b_w);
	if(R <= 0){
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job != 1 || emp[E].shop_n != no) continue;
			emp[E].tension += 5;
		}
		logu.add("EV:ダンスでテンション上昇",13,no);
		return 1;
	}

	//勉強会
	R -= 50;
	if( R <=0){
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job != 1 || emp[E].shop_n != no) continue;
			emp[E].exp += int(lv_ave*1000);
			emp[E].lv_up();
		}
		logu.add("EV:勉強会を開いて経験獲得",13,no);
		return 1;
	}
	
	//資金調達
	R -= 50;
	if( R <=0){
		int M = kabu_cnt[0] * (int)kabu_price / 50;
		etc_mon[data.mon] += M;
		money += M;
		logu.add("EV:投資に成功、資金が増えた",13,no);
		return 1;
	}

	//特別配当
	R -= 50;
	if( R <=0){
		int M = kabu_cnt[1] * (int)data.kabu_price[1] / 25;
		M +=  kabu_cnt[2] * (int)data.kabu_price[2] / 25;
		M +=  kabu_cnt[3] * (int)data.kabu_price[3] / 25;
		M +=  kabu_cnt[4] * (int)data.kabu_price[4] / 25;
		etc_mon[data.mon] += M;
		money += M;
		logu.add("EV:特別に配当が出た",13,no);
		return 1;
	}

	//宣伝A
	R -= 50;
	if( R <=0){
		this->senden_syori(30,10);
		logu.add("EV:町で噂になっている！",13,no);
		return 1;
	}

	//宣伝B
	R -= 50;
	if( R <=0){
		this->senden_syori(10,300);
		logu.add("EV:一部で話題になっている！",13,no);
		return 1;
	}

	//研究A
	R -= 50;
	if( R <=0){
		if( create_lv[0] > create_lv[1] &&
			create_lv[0] > create_lv[2]){
			create_lv[0]++;
		}else if(create_lv[1] > create_lv[2]){
			create_lv[1]++;
		}else{
			create_lv[2]++;
		}
		logu.add("EV:得意な技術を伸ばした！",13,no);
		return 1;
	}

	//研究B
	R -= 50;
	if( R <=0){
		if( create_lv[0] < create_lv[1] &&
			create_lv[0] < create_lv[2]){
			create_lv[0]++;
		}else if(create_lv[1] < create_lv[2]){
			create_lv[1]++;
		}else{
			create_lv[2]++;
		}
		logu.add("EV:苦手な技術を克服した！",13,no);
		return 1;
	}

	//閃き補正
	R -= 50;
	if( R <=0){
		hirameki_dayb += 56;
		logu.add("EV:アイデアが溢れて閃き確率＋！",13,no);
		return 1;
	}

	//改善習慣
	R -= 50;
	if( R <=0){
		kaizen_week+=7;
		logu.add("EV:カイゼン案を募集！改良経験＋！",13,no);
		return 1;
	}

	//MP回復
	R -= 50;
	if( R <=0){
		n_mp += (double)emp_cnt * 2 * (150 - b_w) / 100;
		logu.add("EV:標語を募集！ＭＰが回復！",13,no);
		return 1;
	}

	//株価アップ
	R -= 50;
	if( R <=0){
		kabu_price += kabu_price/10;
		logu.add("EV:投資家が注目！株価が上昇",13,no);
		return 1;
	}

	//部門経験A
	R -= 50;
	if( R <=0){
			int T = fun.Rand(4);
			bumon_exp[T] += int(emp_cnt* 40 * (150 - b_w) / 100);
			EVE_FUN::Sin().mana_lvup(no,T);
		logu.add("EV:組織について考える！部門が成長",13,no);
		return 1;
	}

	return -1;
}

void SHOP::getumatu()
{
	for(int C=0;C<emp_cnt;C++)
    {
		int E = emp_list[C];

        int no = 0;

        if( emp[E].manzoku_cul() > 0 ) no = 1;////昇給要求

	    fun.list_de(E);//リストから削除
	    emp[E].chan_tai = no;
	    fun.list_pe(E);//リストに追加

	}
}