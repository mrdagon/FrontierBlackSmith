//using namespace fbs;
#pragma once

#define AI_ON 1//0で自社もＡＩ
int AI::wep_sel(int S){

	if( S == P && AI_ON) return 1;

	int W,i,T,K1,K2;

	sei_cnt=0;
	kai_cnt=0;
	zero_cnt=0;
	syou_cnt=0;

	for(i=0;i<4;i++){
		wep_cnt[i]=0;
		wep_tc[i]=0;
		list[i]=0;
		for(W=0;W<100;W++){
			no[W][i]=0;
			ninki[W][i]=-999999;
		}
	}

	for(W=0;W<400;W++){
		wep_n[W]=0;
		wep_rf[W]=0;
		wep_kai[W]=0;
		wep_kp[W]=0;
	}

	for(W=0;W<WEP_M;W++){//開発＆生産可能なのをリスト化
		if(shop[S].wep_cre[W]<=0 || W == NOU_NO) continue;
		T= wep[W].type;
		wep_cnt[T]	     += shop[S].wep_rest[T];
		no[list[T]][T]    = W;
		ninki[list[T]][T] = wep[W].ninki[0]+wep[W].ninki[1]+wep[W].ninki[2];
		if(shop[S].wep_cre[W]<=1) ninki[list[T]][T]=ninki[list[T]][T]*9/10;//90%換算
		list[T] ++;
	}

	//人気順に並び替え
	for(T=0;T<4;T++){
		for(W=0;W<list[T];W++){
			for(i=list[T]-1;i>W;i--){
				if(ninki[i][T]> ninki[i-1][T]){
					K1 = ninki[i][T];
					K2 = no[i][T];
					ninki[i][T]    = ninki[i-1][T];
					no[i][T]       = no[i-1][T];
					ninki[i-1][T]  = K1;
					no[i-1][T]     = K2;
				}
			}
		}
	}

	int NH[4]={0};

	//商品決定//暫定
	for(W=0;W<100;W++)
    {
		if(			ninki[wep_tc[0]][0]-NH[0] >= ninki[wep_tc[1]][1]-NH[1] &&
					ninki[wep_tc[0]][0]-NH[0] >= ninki[wep_tc[2]][2]-NH[2] &&
					ninki[wep_tc[0]][0]-NH[0] >= ninki[wep_tc[3]][3]-NH[3]){
			T=0;
		}else if(	ninki[wep_tc[1]][1]-NH[1] >= ninki[wep_tc[2]][2]-NH[2] &&
					ninki[wep_tc[1]][1]-NH[1] >= ninki[wep_tc[3]][3]-NH[3]){
			T=1;
		}else if(	ninki[wep_tc[2]][2]-NH[2] >= ninki[wep_tc[3]][3]-NH[3]){
			T=2;
		}else{
			T=3;
		}

		if(shop[S].wep_cre[no[wep_tc[T]][T]] == 1)//開発
        {
			wep_kai[kai_cnt]=no[wep_tc[T]][T];//開発予定リスト
			wep_kp[kai_cnt]=0;//投入開発力
			kai_cnt++;
			W--;
		}else if(shop[S].wep_cre[no[wep_tc[T]][T]] == 2){
			wep_n[W]  = no[wep_tc[T]][T];
			wep_rf[W] = shop[S].wep_rest[wep_n[W]];
            //在庫が凄く少ない
			if(wep_rf[W]<=20) zero_cnt++;
			if(wep_rf[W]<=50) syou_cnt++;
			sei_cnt++;
			NH[T]+=20;
		}
		wep_tc[T]++;
	}

	set_emp(S);

	//稼働時間変更
	shop[S].koubou_n = 54;

	return 1;
}
int AI::set_emp(int S){
	int E,C,K;
	
	if( S == P && AI_ON) return 1;

	if(P==S){//プレイヤー陣営
		for(E=0;E<shop[S].emp_cnt;E++){
			fun.list_de(shop[S].emp_list[E]);
		}
	}

	//店員割り当て
	for(C=0;C<shop[S].emp_cnt;C++){	
		if(emp[shop[S].emp_list[C]].job == 0 ){
			emp[shop[S].emp_list[C]].shift= C%4;//バランス配置
		}else{
			emp[shop[S].emp_list[C]].shift_n= -1;//一旦白紙化
		}
	}

	//K = shop.emp_kou[S]-syou_cnt;//
	K = 1;//とりあえず一個開発
	if(K>kai_cnt) K=kai_cnt;

	
	//開発割り当て
	for(C=0;C<K;C++){
		emp_kai(S);
	}
	//製造割り当て
	emp_sei(S);

	if(P==S){//プレイヤー店舗用
		for(E=0;E<shop[S].emp_cnt;E++){
			fun.list_pe(shop[S].emp_list[E]);
		}
	}

	return 1;
}
int AI::mana_sel(int S){
	
	if( S == P && AI_ON) return 1;

	int M = -1;
	int YUU_MAX = 0;
	int R = 0;
	//知名度が下がったら宣伝する
	//自分の好きな武器を優先する
	//使ってない系統の戦術を優先する
	//ある程度ランダム
	//優先値を計算

	for(int i=0;i<MANA_M;i++)
	{
		if(shop[S].mana_ok[i]==1)
		{//AI処理
			R = EVE_FUN::Sin().mana_ai(S,i);
			if (R > 0) R += shop[S].ai_like[i / 60];

			if( R > YUU_MAX )
			{
				YUU_MAX = R;
				M = i;
			}
		}
	}

	//優先度が一番高い奴を使用選択
	shop[S].use_mana = M;

	return 1;
}
int AI::taiguu_sel(int S){
	
	if( S == P && AI_ON) return 1;

	int i,E,MAN;

	for(i=0;i<shop[S].emp_cnt;i++){
		E = shop[S].emp_list[i];
		MAN = emp[E].manzoku_cul();
		if(S == P) fun.list_de(E);
		if(MAN>0){
			emp[E].chan_tai=1;
		}else{
			emp[E].chan_tai=0;
		}
		if(emp[E].rest>=14){
			kaico_cnt++;
		}
		if(S == P) fun.list_pe(E);
	}

	return 1;
}
int AI::koyou_sel(int S){
	
	if( S == P && AI_ON) return 1;

	//店員雇用
	int C,i;
	jinji_cul(S);

	C = custom_pre/200 - (shop[S].emp_cnt - shop[S].emp_kou) + kaico_cnt + 2;

	for(i=0;i<C;i++)
	{
		jinji_sel(S,0);
	}

	//職人雇用
	if( shop[S].souko_now > 500 ) return 1;//在庫多すぎ

	if( data.jinkou / 75 > shop[S].emp_kou ) jinji_sel(S,1);

	return 1;
}
//評価値計算
int AI::emp_kai(int S){

	int N;//武器番号
	int E;//店員
	int i;

	int SE = 0;//店員番号
	int MAX=0;//最大優先値

	if(shop[S].emp_kou == 0) return 1;

	for(i=0;i<shop[S].emp_cnt;i++){//一番開発力が高い人を選択
		E = shop[S].emp_list[i];
		if(emp[E].job == 0 ) continue;
		if(emp[E].shift_n != -1) continue;
		if(emp[E].st[2]>MAX){
			SE = E;
			MAX = emp[E].st[2];
		}
	}

	MAX=10000;
	for(i=0;i<kai_cnt;i++){//開発対象決定
		if(wep_kp[i]<MAX){
			MAX = wep_kp[i];
			N   = i;
		}
	}

	emp[SE].shift_n = wep_kai[N];
	wep_kp[N] += emp[SE].st[2];

	return 1;
}
int AI::emp_sei(int S){

	int i,E;
	//製造予定リスト
	int SE = -1;
	int MAX = 0;
	for(i=0;i<shop[S].emp_cnt;i++){//製造力が高い人から選択
		E = shop[S].emp_list[i];
		if(emp[E].job == 0 ) continue;
		if(emp[E].shift_n != -1) continue;
		if(emp[E].st[1]>MAX){
			SE = E;
			MAX = emp[E].st[2];
		}
	}
	if(SE == -1) return 1;

	//製造武器を選択
	int N=-1;
	int MIN = 200;
	if(shop[S].wep_rest[NOU_NO] < shop[S].nougu_req /2 ) MIN=21;
    else if(shop[S].wep_rest[NOU_NO] < shop[S].nougu_req ) MIN = 31;
    else if(shop[S].wep_rest[NOU_NO] < shop[S].nougu_req *2) MIN = 51;

	for(i=0;i<sei_cnt;i++)
    {		
		if(wep_rf[i]<MIN)
        {
			N = i;
			MIN = wep_rf[i];
		}
	}

	if(N!=-1)
    {
		emp[SE].shift_n = wep_n[N];
		wep_rf[N] += 20;
	}else{
		emp[SE].shift_n = NOU_NO;
	}

	emp_sei(S);

	return 1;
}
int AI::jinji_cul(int S){
	//人事評価計算

	for(int E=0;E<EMP_M;E++)
	{
		if(emp[E].shop_n != S || emp[E].now_job == 3) continue;
		//ステータス合計のみで判別・仮
		emp_hyou[E] = emp[E].st[0] + emp[E].st[1] + emp[E].st[2];
		if(emp[E].job==0){
			if(emp[E].rest<30)	tai_heikin+=int(emp[E].hp);
		}
		if(emp[E].now_job == 2) emp[E].now_job = 0;//一旦内定解除
	}

	tai_husoku = 1000*(shop[S].emp_cnt - shop[S].emp_kou) - tai_heikin;//不足合計
	if(tai_husoku<0) tai_husoku = 0;

	if(shop[S].emp_cnt - shop[S].emp_kou == 0)	tai_heikin = 1000;
	else										tai_heikin = tai_heikin/(shop[S].emp_cnt - shop[S].emp_kou);//平均体力

	//先月客数計算
	custom_pre=0;
	for(int i=data.day;i>data.day-14;i--)
	{
		if(i<0 || i>1680) break;
		custom_pre += shop[S].cust_day[i][0] + 
					  shop[S].cust_day[i][1] + 
					  shop[S].cust_day[i][2] + 
					  shop[S].cust_day[i][3];
	}


	return 1;
}
int AI::jinji_sel(int S,int J){

	int E,N=-1,M=0;

	for(E=0;E<EMP_M;E++){
		if(emp[E].job==J && emp[E].now_job ==0 && emp[E].shop_n == S && emp_hyou[E]>M){
			N = E;
			M = emp_hyou[E];
		}
	}
	if(N!=-1) emp[N].now_job = 2;//内定
	return 1;
}