//using namespace fbs;
#pragma once

#define AI_ON 1//0�Ŏ��Ђ��`�h
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

	for(W=0;W<WEP_M;W++){//�J�������Y�\�Ȃ̂����X�g��
		if(shop[S].wep_cre[W]<=0 || W == NOU_NO) continue;
		T= wep[W].type;
		wep_cnt[T]	     += shop[S].wep_rest[T];
		no[list[T]][T]    = W;
		ninki[list[T]][T] = wep[W].ninki[0]+wep[W].ninki[1]+wep[W].ninki[2];
		if(shop[S].wep_cre[W]<=1) ninki[list[T]][T]=ninki[list[T]][T]*9/10;//90%���Z
		list[T] ++;
	}

	//�l�C���ɕ��ёւ�
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

	//���i����//�b��
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

		if(shop[S].wep_cre[no[wep_tc[T]][T]] == 1)//�J��
        {
			wep_kai[kai_cnt]=no[wep_tc[T]][T];//�J���\�胊�X�g
			wep_kp[kai_cnt]=0;//�����J����
			kai_cnt++;
			W--;
		}else if(shop[S].wep_cre[no[wep_tc[T]][T]] == 2){
			wep_n[W]  = no[wep_tc[T]][T];
			wep_rf[W] = shop[S].wep_rest[wep_n[W]];
            //�݌ɂ��������Ȃ�
			if(wep_rf[W]<=20) zero_cnt++;
			if(wep_rf[W]<=50) syou_cnt++;
			sei_cnt++;
			NH[T]+=20;
		}
		wep_tc[T]++;
	}

	set_emp(S);

	//�ғ����ԕύX
	shop[S].koubou_n = 54;

	return 1;
}
int AI::set_emp(int S){
	int E,C,K;
	
	if( S == P && AI_ON) return 1;

	if(P==S){//�v���C���[�w�c
		for(E=0;E<shop[S].emp_cnt;E++){
			fun.list_de(shop[S].emp_list[E]);
		}
	}

	//�X�����蓖��
	for(C=0;C<shop[S].emp_cnt;C++){	
		if(emp[shop[S].emp_list[C]].job == 0 ){
			emp[shop[S].emp_list[C]].shift= C%4;//�o�����X�z�u
		}else{
			emp[shop[S].emp_list[C]].shift_n= -1;//��U������
		}
	}

	//K = shop.emp_kou[S]-syou_cnt;//
	K = 1;//�Ƃ肠������J��
	if(K>kai_cnt) K=kai_cnt;

	
	//�J�����蓖��
	for(C=0;C<K;C++){
		emp_kai(S);
	}
	//�������蓖��
	emp_sei(S);

	if(P==S){//�v���C���[�X�ܗp
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
	//�m���x�������������`����
	//�����̍D���ȕ����D�悷��
	//�g���ĂȂ��n���̐�p��D�悷��
	//������x�����_��
	//�D��l���v�Z

	for(int i=0;i<MANA_M;i++)
	{
		if(shop[S].mana_ok[i]==1)
		{//AI����
			R = EVE_FUN::Sin().mana_ai(S,i);
			if (R > 0) R += shop[S].ai_like[i / 60];

			if( R > YUU_MAX )
			{
				YUU_MAX = R;
				M = i;
			}
		}
	}

	//�D��x����ԍ����z���g�p�I��
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

	//�X���ٗp
	int C,i;
	jinji_cul(S);

	C = custom_pre/200 - (shop[S].emp_cnt - shop[S].emp_kou) + kaico_cnt + 2;

	for(i=0;i<C;i++)
	{
		jinji_sel(S,0);
	}

	//�E�l�ٗp
	if( shop[S].souko_now > 500 ) return 1;//�݌ɑ�����

	if( data.jinkou / 75 > shop[S].emp_kou ) jinji_sel(S,1);

	return 1;
}
//�]���l�v�Z
int AI::emp_kai(int S){

	int N;//����ԍ�
	int E;//�X��
	int i;

	int SE = 0;//�X���ԍ�
	int MAX=0;//�ő�D��l

	if(shop[S].emp_kou == 0) return 1;

	for(i=0;i<shop[S].emp_cnt;i++){//��ԊJ���͂������l��I��
		E = shop[S].emp_list[i];
		if(emp[E].job == 0 ) continue;
		if(emp[E].shift_n != -1) continue;
		if(emp[E].st[2]>MAX){
			SE = E;
			MAX = emp[E].st[2];
		}
	}

	MAX=10000;
	for(i=0;i<kai_cnt;i++){//�J���Ώی���
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
	//�����\�胊�X�g
	int SE = -1;
	int MAX = 0;
	for(i=0;i<shop[S].emp_cnt;i++){//�����͂������l����I��
		E = shop[S].emp_list[i];
		if(emp[E].job == 0 ) continue;
		if(emp[E].shift_n != -1) continue;
		if(emp[E].st[1]>MAX){
			SE = E;
			MAX = emp[E].st[2];
		}
	}
	if(SE == -1) return 1;

	//���������I��
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
	//�l���]���v�Z

	for(int E=0;E<EMP_M;E++)
	{
		if(emp[E].shop_n != S || emp[E].now_job == 3) continue;
		//�X�e�[�^�X���v�݂̂Ŕ��ʁE��
		emp_hyou[E] = emp[E].st[0] + emp[E].st[1] + emp[E].st[2];
		if(emp[E].job==0){
			if(emp[E].rest<30)	tai_heikin+=int(emp[E].hp);
		}
		if(emp[E].now_job == 2) emp[E].now_job = 0;//��U�������
	}

	tai_husoku = 1000*(shop[S].emp_cnt - shop[S].emp_kou) - tai_heikin;//�s�����v
	if(tai_husoku<0) tai_husoku = 0;

	if(shop[S].emp_cnt - shop[S].emp_kou == 0)	tai_heikin = 1000;
	else										tai_heikin = tai_heikin/(shop[S].emp_cnt - shop[S].emp_kou);//���ϑ̗�

	//�挎�q���v�Z
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
	if(N!=-1) emp[N].now_job = 2;//����
	return 1;
}