#pragma once

int SHOP::kouji_end(){

	if(this->mana_cnt[M_TAKM] > 0)

	for(int E=0;E<EMP_M;E++){//�����t�H�[��
		if(emp[E].shop_n != no || emp[E].now_job != 1) continue;
		emp[E].tension += 3;
	}

	logu.add("�H�����������܂���",12,no);

	if(kouji != 0)
	{
		shop[no].senden_syori(100,200);
		kouji = 0;
	}
	
	if(mana_cnt[M_RIFO] > 0 ){//���t�H�[���Z�[��
		this->start_sell(80,7);
	}

	return 1;
}
int SHOP::start_sell(int Wari,int D){
	price_rate  = min(price_rate,Wari);
	yasuuri		= max(yasuuri,D);

	logu.add("�Z�[�����J�n���܂���",12,P);

	char str[32];
	sprintf_s(str,"%d���Z�[���J�n!",100-Wari);
	logu.add(str,9,no);

	return 1;
}
int SHOP::senden_syori(int HIT,int LV){

	//LV % �̊m���Ō���

	//�i�����X�V
	//�F�m�x��
	LV  = LV  * senden_b /100;
	HIT = HIT * senden_b /100;

	for(int H=0;H<data.jinkou_max;H++){
		if(hun[H].life <= 0) continue;//���Sor���o�^
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

	//�J�V�Z�[��
	if(mana_cnt[M_UTES] >= 1 && data.tenki > 1){
		start_sell(80,1);
	}
	//�Z�[���I��
	if(yasuuri <=0 && price_rate != 100 - mana_cnt[M_HEIT] * 10){
		price_rate = 100 - mana_cnt[M_HEIT] * 10;
		logu.add("�Z�[���I���I",10,no);
	}

	//�Z�[������
	if(price_rate < 90 ){
		//�ʏ�Z�[��
		senden_syori( int(( 50 - price_rate / 2 ) * yasuuri_efe) ,  300 - price_rate * 2 );
		yasuuri--;
		yasuuri_efe /= 1.5;
	}else if(mana_cnt[M_HEIT] > 0){
		//��ԃZ�[��
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

	int cre_cnt[WEP_M];//�J���ςݐl��&�����␳
	int HB[WEP_M];
	int HOK[WEP_M];

	//��{����̊J���J��
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
				if(shop[s].mana_cnt[M_TOCG]>0)	cre_cnt[W] = 1;//�����擾
				if(mana_cnt[M_KORO]>0)			HOK[W] = 1;//���ʂ�������
				HB[W] -= 5;
			}
		}
	}

	hirameki_dayb++;
	int HB2 = 100+hirameki_dayb*10;

	for(int W=0;W<WEP_M;W++){//�J���ς݁A���J���{�[�i�X
		if(wep_cre[W] == 2 && mana_cnt[M_IDEC]>0) HB2++;
		if(wep_cre[W] == 1 && mana_cnt[M_HUMI]>0) HB2++;
	}

	if(emp_cnt == 0 || data.hirameki_rate == 0 || emp_kou <= 0) return 1;//�X���O

	int R = fun.Rand(WEP_M-3)+1;
	int BS;

	for(int W=R+1;W!=R;W++){//�K�v�l�v�Z
		if(W >= WEP_M) W = 0;
		if(wep_cre[W] != 0 ) continue;

		if(cre_cnt[W]>0) continue;

		REQ = 0;//�M����
		RF  = 0;//�Z�p���x�����␳

		if(create_lv[0] < wep[W].req_clv[0]) RF += wep[W].req_clv[0]-create_lv[0];//�Z�p���x������Ȃ�
		if(create_lv[1] < wep[W].req_clv[1]) RF += wep[W].req_clv[1]-create_lv[1];
		if(create_lv[2] < wep[W].req_clv[2]) RF += wep[W].req_clv[2]-create_lv[2];

		if( create_lv[0] > wep[W].req_clv[0] &&//�Z�p���x��������
			create_lv[1] > wep[W].req_clv[1] &&
			create_lv[2] > wep[W].req_clv[2] &&
			wep[W].rank<50){

			if(mana_cnt[M_LOST] > 0) RF+= max(max(create_lv[0] - wep[W].req_clv[0] , create_lv[1] - wep[W].req_clv[1]) , create_lv[2] - wep[W].req_clv[2])/4;
			else				  RF+= max(max(create_lv[0] - wep[W].req_clv[0] , create_lv[1] - wep[W].req_clv[1]) , create_lv[2] - wep[W].req_clv[2])/2;
		}

		if(HOK[W] == 1) RF = 0;//���ʂ�������

		BS  = 0;
		//���ʕ�����ǂɂ��␳
		if(W > 0 && wep[W].gazou == wep[W-1].gazou && wep_cre[W-1] == 2){
			BS = this->wep_kaicnt[W-1];
		}

		REQ = (100 + wep[W].rank * 10 - BS)*(10+RF*RF) / 2;//�m���v�Z
		//100�`

		if(RF >= 10) continue;
        if(RF <=  1) REQ /= 2;//�����w�ǖ����Ɗm����UP

		for(int i = 0;i<emp_cnt;i++){//��ԑM�����������z���Z�o
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

		//�e��␳
		if(fun.Rand(100000) <= KP){//�M������
			wep_cre[W] = 1;//�J���\�ɂ���
			if(no==P){
				fun.list_pw(W);//���X�g�Ō���ɒǉ�
				sprintf_s(str,"�u%s�v�J����!",wep[W].name.c_str());
				logu.add(str,1000+W,P);
				SE = 1;
			}
			wep_hday[W]=data.day;
			emp[K_NO].sell_now += 1;	//�J���{�[�i�X
			hirameki_dayb=0;
			break;
		}

	}

	if(SE == 1){//�M������
		fun.se_ok(5);
	}

	return 1;
}
int SHOP::hirameki_mana(){

	//�����n
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

	//�o�c��p�M��
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

	if(kabu_rate[0] > 95) mana_ok[61] = 0;//����

	if(kouji > 0){//�H����
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
	//���ǂ���

	int A;
	int C;
	int N;
	int T;

	if(mana_cnt[M_BARA]==0){
		A = atk_kai[W]   + 3;
		C = cost_kai[W]  + 3;
		N = ninki_kai[W] + 3;
		T = time_kai[W]  + 3;
	}else{//�o�����X����
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

	if(wep_rest[W]<=0 && W!= NOU_NO){//�_��ȊO�쐬���݌ɂO
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
		wep_rest[W] = 10 + mana_cnt[M_AHUR]*20;//����i��10��
		souko_now  += 10 + mana_cnt[M_AHUR]*20;
		wep_cre[W]  = 2;
		wep_make[W] = 0;
		tana_now++;
		tana_now_t[wep[W].type]++;
		seizc_day[data.day]+= 10;
		seizc_mon[data.mon]+= 10;
		money -= wep[W].create_time/48;//�J����x����+������v�{
		seiz_day[data.day]-= wep[W].create_time/54;
		seiz_mon[data.mon]-= wep[W].create_time/54;
		incom_mon[data.mon] -= wep[W].create_time/54;
		if(data.wep_ganso[W] == -1) data.wep_ganso[W]=no;
	}
	if(no==P){
		sprintf_s(str,"�u%s�v�J������",wep[W].name.c_str());
		fun.se_ok(2);
		sys.total_kaihatu++;
		sys.wep_cret[W]++;
		sys.wep_maket[W]+=10 + mana_cnt[M_AHUR]*20;
		sys.total_make += 10 + mana_cnt[M_AHUR]*20;
	}else{
		sprintf_s(str,"�u%s�v�̔��J�n�I",wep[W].name.c_str());
	}

	if(data.wep_ganso[W] == no)	logu.add(str,2000+W,no);
	else						logu.add(str,3000+W,no);

	if(mana_cnt[194]>0){
		n_mp += 10;
	}
	if(mana_cnt[M_NSEL]>0){
		senden_syori(20,100);
	}

	cul_seiz_kair();//���Y���x���Čv�Z

	return 1;
}
int SHOP::day_mana(){

	//�o�c��p�g�p
	ai.wep_sel(no);
	ai.mana_sel(no);

	for(int MA=0;MA<MANA_M;MA++)
	{//�o�c��p�g�p
		if(use_mana >0 && syou_mp[use_mana] * mana_b[mana[use_mana].type] / 100 <= n_mp )
		{
			if (EVE_FUN::Sin().mana_syori(no, MA) == 1)
			{
				this->ai_like[MA / 60] = 0;
				if(P == no)fun.se_ok(1);
			}
		}
	}
	//�H���������v�Z
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

	ai.koyou_sel(no);//�ٗp�ґI��

	for(int i=0;i<emp_cnt;i++)
	{
		int e = emp_list[i];
		emp[e].rote_type = i%12;
	}

	//AI����
	for (int i = 0; i < 5;i++)
	{
		ai_like[i] += GetRand(100);
	}
    
    if(no == 0) ai_like[0] += GetRand(50);//�o�c�D��
    if(no == 1) ai_like[2] += GetRand(50);//�H���D��
    if(no == 2) ai_like[4] += GetRand(50);//��`�D��
    if(no == 3) ai_like[3] += GetRand(50);//�J���D��
    if(no == 4) ai_like[1] += GetRand(50);//�����D��


	//�q�ɗ���
	if(souko_now > souko_max){
		money			   -= (souko_now-souko_max)*10;
		etc_mon[data.mon]  -= (souko_now-souko_max)*10;
	}else if(mana_cnt[M_KUUK] > 0){
		money			   -= (souko_now-souko_max)*3;
		etc_mon[data.mon]  -= (souko_now-souko_max)*3;
	}

	//�}�����
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

	//�q��������
	cust_cnt = 0;
	for(int W=0;W<4;W++)cust_cnt_t[W] = 0;		
	for(int W=0;W<1000;W++)cust_list[W]=-1;//�q�����X�g����r��		

	//���P�����T
	if(kaizen_week>0)kaizen_week--;

	//�M������
	if(data.day > 17 || data.mode != 0){
		hirameki_wep();//�M������
		hirameki_mana();//�M������
	}

	n_mp += p_mp;//��

	if(n_mp > 10000) n_mp = 10000;//�ő��1000
		
	if(data.day%7==0){
		koubou_t = koubou_n;//�c�Ǝ��ԕω�
	}

	//�ڋʏ��i�ݒ�
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
	senden_day();//��`����

	cul_seiz_kair();
	cul_kenkyuu();

	cul_kaburate();
	cul_medama();
	cul_kaihosei();

	return 1;
}
int SHOP::mon_start(){

	cul_ave();

	ai.taiguu_sel(no);//�ҋ��v�Z
	ai.koyou_sel(no);//�ٗp�ґI��
	n_mp += mp_ninnzuu * emp_cnt;

	mana_cnt[244] = 1;//�����n�G��MP��
	if(data.mon % 3 == 1) mana_cnt[245] = 1;	
	if(fun.Rand(11) == 0) mana_cnt[246] = 1;

	//���݉�nMP��
	mana_cnt[40] = 0;
	mana_cnt[41] = 0;
	mana_cnt[42] = 0;
	mana_cnt[43] = 0;
	if(data.mon % 12 == 0) mana_cnt[43] = 1;//�V�N��
	if(data.mon % 12 == 3) mana_cnt[40] = 1;//���Ԍ�
	if(data.mon % 12 == 6) mana_cnt[41] = 1;//�ċx��
	if(data.mon % 12 == 9) mana_cnt[42] = 1;//������

	//�_��[�i
	if(nougu_req<= wep_rest[NOU_NO]){//�B��
		nougu_mon[data.mon-1] = nougu_req;
		if(no == P) sys.total_matokku += nougu_req;
		wep_rest[NOU_NO] -= nougu_req;
		souko_now -= nougu_req;
		money += wep[NOU_NO].price * 100 * nougu_req;
		sell_mon[data.mon-1] += wep[NOU_NO].price * 100 * nougu_req;
		nougu_req += nougu_up;//��{+3
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
	//���q����
	if(money>0){//�a��
		etc_mon[data.mon-1] += int(money/100*risi_rate/100);//��{1%
		money				+= int(money/100*risi_rate/100);
	}else{//�؋�
		etc_mon[data.mon-1] -= int(money*3/100*risoku_rate/100);//��{3%
		money				-= int(money*3/100*risoku_rate/100);
	}
	//�����z�� 2%
	int kabu_h = 0;
	kabu_h += (int)(data.kabu_price[1] * this->kabu_cnt[1] / 50);
	kabu_h += (int)(data.kabu_price[2] * this->kabu_cnt[2] / 50);
	kabu_h += (int)(data.kabu_price[3] * this->kabu_cnt[3] / 50);
	kabu_h += (int)(data.kabu_price[4] * this->kabu_cnt[4] / 50);
	etc_mon[data.mon-1] += kabu_h;
	money				+= kabu_h;

	//�ŋ�����
	int RM = sell_mon[data.mon-1]/5*tax_b/100;//�����20%
	money				 -= RM;//�����20%
	etc_mon[data.mon-1] -= RM;//���프���20%

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
	//��������
	int up_sisan = 0;

	if(data.mon < 2){
		up_sisan = incom_mon[data.mon-1] - incom_mon[data.mon-2];
	}else{
		up_sisan = incom_mon[data.mon-1];
	}

	kabu_price += (up_sisan + incom_mon[data.mon-1]/10) / kabu_max;
	kabu_price = max(kabu_price,0);
	//�u���b�N�x�ω�
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
		if(emp[E].job == 0 || emp[E].rest > 0) continue;//�X���͖���
		//�J���l�������l	
		int R = 1;
		int W = emp[E].shift;

		if(wep_cre[W] == 2){//������
			wep_make_now[W] += emp[E].st_st[1] * seizou_b / 100;
			wep_kaiexp[W]   += emp[E].st_st[2] * kairyou_b / 100;
		}else{//�J����
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
	//�l���␳��
	for(int W=0;W<WEP_M;W++){
		if(kaizen_week > 0) wep_kai_now[W]*=3;//�J�C�[���T��

		if(wep_cre[W] == 2) continue;
		if(nin_cnt[W] > 0 && mana_cnt[M_NILE] == 0){//�l���_�b
			wep_make_now[W] = (int)pow(double(wep_make_now[W]),double(1)/nin_cnt[W]);
		}
		if( wep_kai_now[W] < 0) wep_kai_now[W] = 0;  
		if(mana_cnt[M_AJYA]>0){//�A�W���C��
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
	
	//�����͌v�Z
	for(int C=0;C<emp_cnt;C++){
		int E = emp_list[C];
		if(emp[E].job == 0 || emp[E].rest>0) continue;//�X�� or�@�x��

		//���팤���l�{
		if(emp[E].skill == 28)		R = 150;
		else if(emp[E].skill == 29)	R = 200;
		else						R = 100;
		R = fun.Rand(R * emp[E].st_st[2]) + emp[E].st_st[2];

		if( R > MAX){
			MAX = R;
			if(teikyuu<7) R += R/5;//��x��������ꍇ�Q������
			create_get[0] = 0;
			create_get[1] = 0;
			create_get[2] = 0;
			switch(wep[emp[E].shift%WEP_M].type){//�Z�p��
				case 1:
					create_get[0] = R/10;break;//����
				case 2:
					create_get[1] = R/10;break;//�B�S
				case 3:
					create_get[2] = R/10;break;//�׍H
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

		//�ڋʏ��i�{�[�i�X
		if(wep[W].type < 4 && wep[W].zoku < 3)
        {
			ninki_j[W] *= medama_wept[wep[W].type] * medama_zoku[wep[W].zoku];
		}

		//���c�␳
		if(data.wep_ganso[W] == no) ninki_j[W]*= 1.1 + mana_cnt[M_HOMO]*0.1;
		
	}

	//�ڋʏ��i����
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
	//���ێ����Čv�Z
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
		if(N < 0 || wep_cre[N] != 2) continue;//�J����or���ݒ�
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

	//���菈�� -1�@�Ȃ疢�B�� 0�`11�łǂꂩ�B��

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
	
	//�j�Y�`�F�b�N�A�v���C���[�̂�
	if(-int(shop[P].money) > g_kabu && no == P) return 512;

	return -1;
}

int SHOP::reset(){
	//�X�e�[�^�X������
	emp_cnt		 = 0;
	emp_kou		 = 0;//�H�[�l��

	money = 3000000;//��{300��

	nougu_req = 30;//��{�_��30

	kabu_price = 10000;//����
	kabu_max   = 1000;//���ő吔

	for(int N=0;N<5;N++){
		if(N==0) kabu_cnt[N]   = 501;//���ێ���
		else	 kabu_cnt[N]   = 0;
		kabu_rank[N] = 0;
	}

	b_w			= 50;//�u���b�N�x0�`100�A�P���łP�O�O��
	koubou_t	= 54;//�H�[�c�Ǝ���
	koubou_n	= 54;//���̓��H�[����
	zangyou     = 57;//�ő�c�Ǝ���		�����s��

	for(int N=0;N<3;N++){
		create_get[N] = 0;//�l���J���o���l
		create_exp[N] = 0;//�J���o���l
		create_lv[N]  = 0;//�J����
		wep_sb[0][N] = 3;//��{����M��
		wep_sb[1][N] = 3;//��{����M��
		wep_sb[2][N] = 3;//��{����M��
		wep_sb[3][N] = 3;//��{����M��
	}

	for(int W = 0;W<WEP_M;W++){
		wep_rest[W] = 0;//�݌ɐ�
		wep_hday[W] = 0;//�M��������
		wep_make[W] = 0;//���Y�i�s�x
		wep_kaicnt[W] = 0;//���ǉ�
		wep_make_t[W] = 0;//�����Y��
		wep_make_now[W] = 0;//�������Y��
		wep_kaiexp[W] = 0;
		//���ǉ�
		ninki_kai[W] = 0;//�l�C
		atk_kai[W]	 = 0;//�U��
		dur_kai[W]	 = 0;//�ϋv
		cost_kai[W]	 = 0;//�R�X�g
		time_kai[W]  = 0;//����
	}

	yasuuri    = 0;//��ي���
	price_rate = 100;//�̔����i
	yasuuri_efe = 1;

	for(int i=0;i<5;i++){
		bumon_lv[i]    = 1;//
		bumon_exp[i]   = 0;//
	}

	total_saiyou= 0;//�݌v�̗p��
	total_yame  = 0;//���߂��l�̍��v�Α�����

	bw_bonus    = 0;//�u���b�N�x�{�[�i�X�l

	yasumi_max  = 4;//�x����			�x�ݐ�

	seizou_b    = 100;
	kairyou_b   = 100;
	tukare_b    = 100;
	sekkyaku_b  = 100;
	kaihatu_b   = 100;
	sabaki_b    = 100;
	stress_b    = 100;
	yaruki_b    = 100;//���C�㏸��

	size		= 0;
	kouji	    = -1;//�H���c�����

	souko_max   = 500;//�q�ɍő吔

	teikyuu		= (no+1)%5;//��x��
	cust_cnt	= 0;//���q��

	for(int N=0;N<4;N++){
		cust_cnt_t[N] ;//�����ޖ��̌��ݗ��q��
		cust_wep[N];//�����ޕʗ��q��
	}

	p_mp = 5;//�񕜃}�l�W�����g�|�C���g
	n_mp = 0;//���݃}�l�W�����g�|�C���g
	use_mana = -1;//�g�p��p

	for(int N=0;N<DAY_M;N++){
		sellc_day[N]   = 0;//�̔���
		sell_day[N]    = 0;//����グ
		cust_day[N][0] = 0;//�q��
		cust_day[N][1] = 0;//�q��
		cust_day[N][2] = 0;//�q��
		cust_day[N][3] = 0;//�q��
		seizc_day[N]   = 0;//������
		seiz_day[N]    = 0;//������
		shera_wepd[N][0] = 0;//�e����̔̔��V�F�A
		shera_wepd[N][1] = 0;//�e����̔̔��V�F�A
		shera_wepd[N][2] = 0;//�e����̔̔��V�F�A
		shera_wepd[N][3] = 0;//�e����̔̔��V�F�A
	}

	for(int N=0;N<MANTH_M;N++){
		sellc_mon[N] = 0;//�̔���
		sell_mon[N]  = 0;//����グ
		cust_mon[N]  = 0;//�q��
		seizc_mon[N] = 0;//������
		seiz_mon[N]  = 0;//������

		emp_mon[N]   = 0;//�ٗp��//�����Ɍv�Z
		manege_mon[N]= 0;//�o�c��p��p
		etc_mon[N]   = 0;//��,���q�����Ɍv�Z
		incom_mon[N] = 0;//���v�����Ɍv�Z
		nougu_mon[N] = 0;//�_��[����
		total_mon[N] = 0;//�����Y//�����Ɍv�Z
		kabu_mon[N]  = 0;//����

		shera_wepm[N][0] = 0;//�e����̔̔��V�F�A
		shera_wepm[N][1] = 0;//�e����̔̔��V�F�A
		shera_wepm[N][2] = 0;//�e����̔̔��V�F�A
		shera_wepm[N][3] = 0;//�e����̔̔��V�F�A
	}

	holiday = 0;
	timeido = 0;

		//�ǉ��d�l��
	for(int N=0;N<5;N++){
		mana_b[N]=100;//��p�g�p�l�o�␳
		mana_gb[N]=100;//��p�g�p�����␳
	}

	mensetu_lv=20;//�ʐڗ�

	kaihuku_b   =100;//�񕜕␳
	kaihuku_bs   =100;//�񕜕␳�A�V����
	exp_b		 =100;//�o���l�␳
	exp_bs		 =100;//�o���l�␳�A�V����
	monster_b	 =100;//�N���[�}�[�������␳
	syakai_b	 =100;//�Љ�l�x�ω��{�[�i�X
	hp_up_b		 =0;//HP�������{�[�i�X
	sei_up_b     =0;//����������
	kai_up_b     =0;//�J��������
	kya_up_b     =0;//�q�J������
	sek_up_b     =0;//�ڋq������

	mp_ninnzuu   =0;//�l���ɂ��l�o�񕜃{�[�i�X

	sk_pup		 =0;//�X�L�������m��
	sk_rup		 =0;//�X�L�����]�m��
	sk_qup		 =0;//�H�X�L���ω��m��

	kabu_buy	 =50;//�������
	nougu_up	 =3;
	kyuuryou_b   =100;//�x��������
	risoku_rate  =100;//�؋�����
	risi_rate	 =100;//�������q
	cost_b		 =100;//�R�X�g�␳
	atk_b		 =100;//�U���̓{�[�i�X
	dur_b		 =100;

	kaicost_b	 =100;//�J���R�X�g�␳

	bukimatu_b	 =100;//����Ղ�{�[�i�X
	turumatu_b	 =100;//��͂��Ղ�{�[�i�X
	tax_b		 =100;//�ŋ���

	for(int N=0;N<4;N++){
		hirameki_b[N]=100;//�����ʑM���␳
	}

	hirameki_dayb = 0;
	senden_b=100;

	kaizen_week=0;

	for(int N=0;N<3;N++){
		ken_b[N]  = 100;//�����o���␳
		ninki_b[N] = 100;//�W�q�␳�A������
	}

	otona_b=100;//��l�����␳

	koukan_down = 0;

	saitei_koukan = 1;//�D���x�Œ�l

	jisyoku_b=100;//���E�m���␳

	eve_efe=-1;//�C�x���g�ɂ��������
	eve_turn=-1;//������ʎc�莞��		

	sinn_b = 0;

	for(int M=0;M<MANA_M;M++){
		mana_ok[M]  = 0;//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��
		mana_cnt[M] = 0;//�g������
		mana_day[M] = 0;//�M���Ă���̓���
	}
		
	for(int W=0;W<7;W++){
		wep_medama[W] = -1;
	}

	medama_max = 1;

	g_cust = 0;//�����q��
	g_kabu = this->kabu_cnt[0] * (int)this->kabu_price;//����������
	g_sell_t = 0;//������グ��
	g_sell[0] = 0;//�����ʔ���グ��
	g_sell[1] = 0;//�����ʔ���グ��
	g_sell[2] = 0;//�����ʔ���グ��
	g_sell[3] = 0;//�����ʔ���グ��
	g_turu = 0;//��͂������Y��
	g_wepcre = 0;//���푍�J����
	g_money = 0;//��������
	g_taikai = 0;//�����_��
	g_boss = 0;//���{�X������

	kyuubo = 0;

	//�q�ꗗ
	for(int H=0;H<SHOP_SP;H++){
		cust_list[H] = -1;
	}

	cul_kaburate();

	return 1;
}

int SHOP::eve_random(){
	
	//�V�i���I���[�h�͓񃖌��ԃC�x���g�����Ȃ�
	if(data.mode == 0 && data.day < 56) return -1;

	int R = 0;
	if(mana_cnt[M_ELVE] > 0) R = fun.Rand(9000);
	else					 R = fun.Rand(10000);


	//HP��
	R -= 100 - int(b_w);
	if(R <= 0){
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job != 1 || emp[E].shop_n != no) continue;
			emp[E].hp_gain(25);
		}
		logu.add("EV:�A���}�łg�o����",13,no);
		return 1;
	}

	//�X�g���X��
	R -= 100 - int(b_w);
	if(R <= 0){
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job != 1 || emp[E].shop_n != no) continue;
			emp[E].sun -= 10;
			if(emp[E].sun < 0) emp[E].sun = 0;
		}
		logu.add("EV:�n�[�u�ŃX�g���X����",13,no);
		return 1;
	}

	//�e���V�����A�b�v
	R -= 100 - int(b_w);
	if(R <= 0){
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job != 1 || emp[E].shop_n != no) continue;
			emp[E].tension += 5;
		}
		logu.add("EV:�_���X�Ńe���V�����㏸",13,no);
		return 1;
	}

	//�׋���
	R -= 50;
	if( R <=0){
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job != 1 || emp[E].shop_n != no) continue;
			emp[E].exp += int(lv_ave*1000);
			emp[E].lv_up();
		}
		logu.add("EV:�׋�����J���Čo���l��",13,no);
		return 1;
	}
	
	//�������B
	R -= 50;
	if( R <=0){
		int M = kabu_cnt[0] * (int)kabu_price / 50;
		etc_mon[data.mon] += M;
		money += M;
		logu.add("EV:�����ɐ����A������������",13,no);
		return 1;
	}

	//���ʔz��
	R -= 50;
	if( R <=0){
		int M = kabu_cnt[1] * (int)data.kabu_price[1] / 25;
		M +=  kabu_cnt[2] * (int)data.kabu_price[2] / 25;
		M +=  kabu_cnt[3] * (int)data.kabu_price[3] / 25;
		M +=  kabu_cnt[4] * (int)data.kabu_price[4] / 25;
		etc_mon[data.mon] += M;
		money += M;
		logu.add("EV:���ʂɔz�����o��",13,no);
		return 1;
	}

	//��`A
	R -= 50;
	if( R <=0){
		this->senden_syori(30,10);
		logu.add("EV:���ŉ\�ɂȂ��Ă���I",13,no);
		return 1;
	}

	//��`B
	R -= 50;
	if( R <=0){
		this->senden_syori(10,300);
		logu.add("EV:�ꕔ�Řb��ɂȂ��Ă���I",13,no);
		return 1;
	}

	//����A
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
		logu.add("EV:���ӂȋZ�p��L�΂����I",13,no);
		return 1;
	}

	//����B
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
		logu.add("EV:���ȋZ�p�����������I",13,no);
		return 1;
	}

	//�M���␳
	R -= 50;
	if( R <=0){
		hirameki_dayb += 56;
		logu.add("EV:�A�C�f�A�����đM���m���{�I",13,no);
		return 1;
	}

	//���P�K��
	R -= 50;
	if( R <=0){
		kaizen_week+=7;
		logu.add("EV:�J�C�[���Ă��W�I���ǌo���{�I",13,no);
		return 1;
	}

	//MP��
	R -= 50;
	if( R <=0){
		n_mp += (double)emp_cnt * 2 * (150 - b_w) / 100;
		logu.add("EV:�W����W�I�l�o���񕜁I",13,no);
		return 1;
	}

	//�����A�b�v
	R -= 50;
	if( R <=0){
		kabu_price += kabu_price/10;
		logu.add("EV:�����Ƃ����ځI�������㏸",13,no);
		return 1;
	}

	//����o��A
	R -= 50;
	if( R <=0){
			int T = fun.Rand(4);
			bumon_exp[T] += int(emp_cnt* 40 * (150 - b_w) / 100);
			EVE_FUN::Sin().mana_lvup(no,T);
		logu.add("EV:�g�D�ɂ��čl����I���傪����",13,no);
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

        if( emp[E].manzoku_cul() > 0 ) no = 1;////�����v��

	    fun.list_de(E);//���X�g����폜
	    emp[E].chan_tai = no;
	    fun.list_pe(E);//���X�g�ɒǉ�

	}
}