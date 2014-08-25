#pragma once

int HUNTER::sinazoroe(int S){

	int W;
	int STR=0,KAK=0,CHE=0;

	for(W=0;W<WEP_M;W++)
	{
		if( shop[S].wep_rest[W]>0 &&
			(wep[W].type == wep_t || data.boom-3 == wep_t)	&&
			money/10 > wep[W].price * shop[S].price_rate ){//������v���݌ɗL��
			if(wep[W].ninki[0]>0)		STR = max(STR,int(wep[W].ninki[0] * shop[S].ninki_j[W] * shop[S].ninki_b[0]/10));
			else if(wep[W].ninki[1]>0)	KAK = max(KAK,int(wep[W].ninki[1] * shop[S].ninki_j[W] * shop[S].ninki_b[1]/10));
			else						CHE = max(CHE,int(wep[W].ninki[2] * shop[S].ninki_j[W] * shop[S].ninki_b[2]/10));
		}
	}
	STR *= like_t[0];
	KAK *= like_t[1];
	CHE *= like_t[2];
	if(data.boom == 7) STR *= 2;
	if(data.boom == 8) KAK *= 2;
	if(data.boom == 9) CHE *= 2;

	if(shop_koukan[S] <=0 ) shop_koukan[S] = 1;

	//�i�����Čv�Z
	shop_wepn[S] = STR + KAK + CHE;

	return shop_wepn[S];
}
int HUNTER::select_byte()
{
	//LV�ɉ����Ă����{
	money += 10000 + 1000* lv * 1000;
	
	act = 0;
	wait = 600;//�ꎞ��

	for(int S=0;S<data.shop_cnt;S++)
	{
		sinazoroe(S);
	}
	return 1;
}
int HUNTER::select_rest(){
	//HP�� + �ҋ@�v�Z

	hp += sta[0]/2;
	if(hp > sta[0]) hp = sta[0];

	wait = 1200;//�񎞊�

	return 1;
}
int HUNTER::select_shop(){

	int shop_p[SHOP_M];
	int S;
	int MAXS=0;
	int MINS=100000;
	//�e�X�̖��͒l���v�Z�A���[���b�g�I��
	for(S=0;S<data.shop_cnt;S++){
		if(shop[S].holiday == 1)shop_p[S] = 0;
		else					shop_p[S] = shop_wepn[S];
		if(shop_p[S] > MAXS ) MAXS = shop_p[S];//�ő�l&�Œ�l�X�V
		if(shop_p[S] < MINS ) MINS = shop_p[S];
	}

	for(S=0;S<data.shop_cnt;S++){
		if(shop_p[S] == MAXS)		shop_p[S]*=2;//�i�����ō��A���͂Q�{
		else if(shop_p[S] == MINS)  shop_p[S]-= shop_p[S]/2;//�Œ�Ȃ甼��
		shop_p[S]=shop_p[S]/100*(shop_koukan[S]);
		shop_p[S] = shop_p[S] * senden_boost[S] / 100;//�D���x�␳
		senden_boost[S] = 100;
	}

	int shop_t = 0;//�g�[�^�����͒l
	for(S=0;S<data.shop_cnt;S++){
		shop_t += shop_p[S];
	}

	//���[���b�g�I��
	int R = fun.Rand(shop_t);
	for(S=0;S<data.shop_cnt;S++){
		R -= shop_p[S];
		if(R<=0 && shop_p[S]>0){
			act_no = S;
			break;
		}
	}

	//����𔃂��Ȃ�or�X���������ȏꍇ�͋����J��
	if(shop_t <= 0 || shop[S].cust_cnt>=SHOP_SP){
		return 3;
	}

	act = 5;//�X���ҋ@

	wait = 180;//���X�ɂ����鎞��
	vx = fun.Rand(1)*2 -1;
	x = 150 - vx * (144+fun.Rand(12));
	y = 30;
	if(S != P && fun.Rand(1) == 0) x = vx*300;

	act_no = S;//�X�ԍ��ƕi�����͐�Ɍv�Z
	sinazoroe(S);//�i�����Čv�Z

	return 0;
}
int HUNTER::select_item(){
	//���͒l�̓��Ń��[���b�g�I��
	int S = act_no;//�X
	int wep_m[WEP_M];
	int wep_n[WEP_M];
	int total_m;
	int W,L;
	int M_W=0;//���͍ő啐��
	int M_M=0;
	int M_C=-1;

	if(data.boom == 7) like_t[0] *= 2;
	if(data.boom == 8) like_t[1] *= 2;
	if(data.boom == 9) like_t[2] *= 2;

	int wep_now = wep_t;
	if( data.boom >= 3 && data.boom <= 6 )
	{
		if( GetRand(4) == 0 ) wep_now = data.boom-3;
	}

	for(W=0,L=0,total_m=0;W<WEP_M;W++){//���햣�͌v�Z
		if( wep[W].type == wep_now 	&&
			shop[S].wep_rest[W] > 0 &&
			cul_yosan() > wep[W].price * shop[S].price_rate &&
			W != NOU_NO	){
			if(wep[W].ninki[0]>0)		wep_m[L]  = int(wep[W].ninki[0] * shop[S].ninki_j[W] * like_t[0] * shop[S].ninki_b[0] / 100);
			else if(wep[W].ninki[1]>0)	wep_m[L]  = int(wep[W].ninki[1] * shop[S].ninki_j[W] * like_t[1] * shop[S].ninki_b[1] / 100);
			else if(wep[W].ninki[2]>0)	wep_m[L]  = int(wep[W].ninki[2] * shop[S].ninki_j[W] * like_t[2] * shop[S].ninki_b[2] / 100);

			total_m += wep_m[L];
			wep_n[L] = W;

			if(wep_m[L] >= M_M){
				if(M_M == wep_m[L])M_C++;
				else			   M_C=-1;
				if(fun.Rand(max(M_C,0)) == 0){
					M_M = wep_m[L];
					M_W = W;
				}
			}
			L++;
		}
	}

	if(data.boom == 7) like_t[0] /= 2;
	if(data.boom == 8) like_t[1] /= 2;
	if(data.boom == 9) like_t[2] /= 2;

	if(total_m<=0)return -1;

	if(fun.Rand(19)!=0) return M_W;//95%�̊m���ň�Ԗ��͒l����������

	double R = fun.Rand(total_m);

	for(W=0;W<L;W++){
		R-=wep_m[W];
		if(R<1){
			return wep_n[W];
		}
	}

	return -1;
}
int HUNTER::select_dungeon(){
	//�����̃��x���ɋ߂��_���W������I��or���U���_���W������I��
	//�_���W�����I��
	int i=0,N=0;

	if(fun.Rand(9) == 0){//���U���D��
		for(i=max(0,dun_lv/2-10);i<100;i++){//���x������-10�ȏ�̂ݑΏ�
			if(dun[i].seek>0 && dun[i].boss_hp>0){//�����ς݂Ń{�X����
				N = i;
				break;
			}
		}
	}//LV�D��

	if(N==0){
		N=1;
		for(i=dun_lv;i>0;i--){
			if(dun[i].seek>0){//�����ς�
				N = i;
			break;
			}
		}
	}

	vs_enemy(N);

	//�s������
	wait = 1200+fun.Rand(600);//�Q�`�R����

	int M = data.req_act[data.day/28%12];

	if(data.tenki == 2) M*= 2;
	else if(data.tenki == 3) M*= 3;

	wait = M + fun.Rand(M/2);

	return 1;
}
int HUNTER::shop_out(){
	//�ޏo�X����//���X�g��������āA��WAIT

	int	S = act_no;

	//���X�g����폜
	for(int i=0;i<SHOP_SP;i++){
		if(shop[S].cust_list[i] == no){
			shop[S].cust_list[i] = -1;
			shop[S].cust_cnt_t[wep_t]--;
			shop[S].cust_cnt--;
			break;
		}
	}

	act = 0;
	wait = 150;

	return 1;
}
int HUNTER::lv_up(){

	int T;

	while(exp >= H_LV_UP){
		T = job;
		sta[0] += jobs[T].st_up[0]/100 *5;
		life+=2;//���C�t+1
		if(jobs[T].st_up[0]%100>fun.Rand(99))sta[0]+=10;
		if(jobs[T].st_up[1]	  >fun.Rand(99))sta[1]++;
		if(jobs[T].st_up[2]	  >fun.Rand(99))sta[2]++;
		if(jobs[T].st_up[3]	  >fun.Rand(99))sta[3]++;
		exp -= H_LV_UP;
		lv ++;
		if(lv >= jobs[T].rank_up && rank == 0){//�N���X�`�F���W
			rank = 1;
			if(b_w/100	   < jobs[T].next_J[0])	job = T + 1;//bw�ɂ��A���W���u�ω�
			else if(b_w/100 > jobs[T].next_J[2])  job = T + 3;
			else										job = T + 2;
			life+=20;//���C�t10����
			sta[0] += jobs[T].st_st[0]*2;//�Œ萬��
			sta[1] += jobs[T].st_st[1];
			sta[2] += jobs[T].st_st[2];
			sta[3] += jobs[T].st_st[3];
			wep_t =   jobs[T].wep_t;//�����ω�
		}

		//�u�[���ω�
		if(fun.Rand(10) == 0 && data.boom >= 3 && data.boom <= 5){
			if(data.boom == 3	   && wep_t == 1) wep_t = 0;
			else if(data.boom == 4 && wep_t == 2) wep_t = 1;
			else if(data.boom == 5 && wep_t == 0) wep_t = 2;
		}
		//�D�ݕω�
		like_t[1]+=fun.Rand(1);
		if(like_t[2]>1)like_t[2]-=fun.Rand(1);
		if(data.boom == 7) like_t[0]++;
		if(data.boom == 8) like_t[1]++;
		if(data.boom == 9) like_t[2]++;
	}
	return 1;
}
int HUNTER::vs_enemy(int D){
	int T,i;
	bool TURN;
	int BOSS = 0;
	int H[2],A[2],B[2],S[2],SK[2],R[2],DAME[2],DUR[2],HIT[2],CRT[2];
	int MH;
	char str[100];
	//double DU;//�`���҃��x���v�Z

	//�G�^�C�v���{�X����
	T = dun[D].ene_t[fun.Rand(7)];
	if(dun[D].clear_f > 750 + D*75 && dun[D].boss_hp>0 && fun.Rand(15)==1){//�{�X�������T���ρ�
		BOSS = 1;
		T = dun[D].boss_t;
	}
	//�X�e�[�^�X���Ɍv�Z
	H[0] = hp;
	A[0] = int(sta[1]*(100+wep_a[0])/100);
	B[0] = sta[2];
	S[0] = sta[3];
	R[0] = 1;
	SK[0] = skill;
	switch(wep_t){//����������S��
		case 0:CRT[0] = 3;HIT[0] = 90;break;//��
		case 1:CRT[0] = 5;HIT[0] = 85;break;//��
		case 2:CRT[0] = 7;HIT[0] = 80;break;//��
		case 3:CRT[0] =10;HIT[0] = 75;break;//�|
	}
	DUR[0] = 0;
	H[1] = ene[T].st[0]*(D*7+75)/(300-D);
	MH = H[1];
	A[1] = ene[T].st[1]*(D*3+30)/(300-D)*(100+D)/100;
	B[1] = ene[T].st[2]*(D*3+30)/(300-D)*(100+D)/200;
	S[1] = ene[T].st[3]*(D*3+30)/(300-D);
	R[1] = 1;
	SK[1] = ene[T].skill;
	CRT[1] = 5;
	HIT[1] = 80;
	DUR[1] = 0;
	//�X�L������
	if(SK[0] == 16) SK[1] = 16;
	else if(SK[1] == 16)SK[0] = 16;
	else if(SK[0] == 3 && SK[1] ==8) SK[0] = 16;//�ђʌ���
	else if(SK[0] == 8 && SK[1] ==3) SK[1] = 16;

	if(BOSS == 1){
		H[1] = dun[D].boss_hp;
	}
	//���x������U���񐔂��v�Z
	if(S[0]>S[1]*3/2){//1.5�{
		R[0] = 2;
	}else if(S[0]*3/2<S[1]){
		R[1] = 2;
	}

	if(SK[0] == 13 && SK[1] != 13)		TURN = 0;//������or��P�����I
	else if(SK[0] != 13 && SK[1] == 13)	TURN = 1;
	else if(S[0] >= S[1])				TURN = 0;
	else								TURN = 1;

	//��{�_���[�W���v�Z
	DAME[0] = A[0] - B[1];
	DAME[1] = A[1] - B[0];
	if(DAME[0] <(A[0]+9)/10) DAME[0] = (A[0]+9)/10;
	if(DAME[1] <(A[1]+9)/10) DAME[1] = (A[1]+9)/10;

	//�X�L������
	for(i=0;i<2;i++){
		switch(SK[i]){
			case 0://���,�G��p
				if(wep_t !=0) DAME[0] = DAME[0]*2/3;
			break;
			case 1://��s,�G��p
				if(wep_t !=3) DAME[0] = DAME[0]*2/3;
			break;
			case 2://����
				DAME[(i+1)%2] = DAME[(i+1)%2]*2/3;
			break;
			case 3://�S��
				CRT[(i+1)%2] = -200;
			break;
			case 4://�ɑ�
				CRT[(i+1)%2] *= 2;
			break;
			case 5://����
				CRT[i] *= 2;
			break;
			case 6://�ҍU
				CRT[i] += 100;
				HIT[i] = HIT[i]*3/5;
			break;
			case 7://�A��
				R[i]++;
			break;
			case 8://�ђ�
				DAME[i] += B[(i+1)%2] /4;//����h��25%����
			break;
			case 9://���e
				DAME[i] = A[0];//�h�䖳���Œ�_���[�W
			break;
			case 10://�K��
				HIT[i]+=1000;
			break;
			case 12://�ˌ�
				DAME[0] *= 2;
				DAME[1] *= 2;
			break;
			case 14://���
				HIT[(i+1)%2] = HIT[(i+1)%2]*7/10;
			break;
			case 15://���e
				HIT[(i+1)%2] /= 2;
				DAME[(i+1)%2] = DAME[(i+1)%2]*3/2;
			break;
		}
	}

	while(1){
		for(i=0;i<R[TURN];i++){//�U���A��
			if(fun.Rand(100)>HIT[TURN]) continue;//��������
			H[!TURN] -= DAME[TURN];
			if(fun.Rand(100)<CRT[TURN]){//��S����
				H[!TURN] -= A[TURN];
				DUR[TURN]+=2;//�ϋv�����
			}
			DUR[TURN]++;
		}
		if(H[!TURN]<=0){
			if(SK[!TURN] == 11){//�Đ�
				SK[!TURN] = 0;
				H[!TURN] = 1;
			}else break;
		}
		TURN = !TURN;
		//��������//�����̂�
		if(TURN == 0){
			if(H[0] < sta[0]/5 && fun.Rand(2) == 0){//HP 1/5�@33%�œ���
				break;
			}
		}
	}

	if(BOSS==1)dun[D].boss_hp = H[1];

	hp = H[0];//HP�ύX

	double exp_late;
	if(D-lv>10)				exp_late = 32;
	else if(D-lv <-12)	    exp_late = 0.01;
	else					exp_late = pow(0.7,lv-D);

	if(SK[0] == 18) exp+= ene[T].exp *int(exp_late*150) /50;//�o���l�l��
	else			exp+= ene[T].exp *int(exp_late*150) /100;//�o���l�l��

	if(H[0]>0 && H[1]<=0){//�����A�����l��
		H[1]=0;//100�ł��傤�ǂ��炢	520
		money += ene[T].money *(20+D) / 2;
		dun[D].clear_f += 2;//�U���x+1
		if(BOSS==1)
        {//�{�X����
			exp += H_LV_UP*2;
			//money += 10000*D+100000;//LV�~1���f
			dun[D].clear_f = 1000;//�U������
			if(shop[wep_s[0]].mana_cnt[M_KOUT] > 0)	shop[wep_s[0]].senden_syori(25,450);
			else									shop[wep_s[0]].senden_syori(25,150);
			sprintf_s(str,"%s�̕��킪��l�C�I�I�I",shop[wep_s[0]].name.c_str());
			logu.add(str,15,5);
			sprintf_s(str,"Lv%d�_���W����BOSS����",D);
			logu.add(str,15,5);
			fun.se_ok(8);
			shop[P].g_boss++;
		}
		//���x�������Ȃ�1/2��+1
		//�������x���������������N�͍���
		//�_���W�������x�����`���҃��x���̍�������K�p
		if( dun_lv < D+1 && dun_lv < lv+1)
        {
			dun_lv++;
		}
	}else{//�s�k
		dun_lv-=(dun_lv/5+10);//�n���^�[���x���ቺ

		if(H[0]<=0){
			life--;//HP0�ɂȂ����ꍇ
			if(life<100 && fun.Rand(life*10) == 0){//���C�t�Ⴂ�Ǝ��ɈՂ�
				//���S
				life=0;
				data.total_des++;//������
				data.des_mon[data.mon]++;//������
				data.jinkou --;
			}
		}
	}


	//�n���^�[���x�����E
	if(dun_lv<=0) dun_lv=1;
	else if(dun_lv>99) dun_lv=99;
	//�ϋv�ቺ����
	DUR[0] = fun.Rand(4)+3;

	if(SK[1] == 3) DUR[0] *= 2;//�|�X�L��

	wep_d[0] -= DUR[0];//����5�ቺ
	
	if(wep_d[0]<=0){
		wep_c--;
		for(i=0;i<wep_c;i++){
			wep_a[i] = wep_a[i+1];
			wep_d[i] = wep_d[i+1];
			wep_s[i] = wep_s[i+1];
		}
	}

	lv_up();//���x���A�b�v����

	return 1;
}
int HUNTER::taiou_emp(int E,int A){
	//�Ή����ԁA�ҋ@���Ԃ��v�Z
	if(stress==5) A = 250;//�N���[�}�[�͒S���֌W����
	else if(A==0 || emp[E].skill == 16)	A = 50;//�S��or���펫��
	else								A = 60;

	talk_emp = E;
	stress = act;//1�ʏ�,3�N���[�}�[

	wait = (510 - b_w/40)*A/emp[E].st[1]*200/emp[E].tension;
	if(stress == 5) wait *=5;//�N���[�}�[�͂T�{

	if(wait<=0) wait = 1;

	talk_max = wait;

	emp[E].wait = wait;

	act = 2;
	return 1;
}
int HUNTER::select_act(){
	int S=0,D=0,R=0,T=0,Z=0;
	//�m���v�Z
	if(wep_c<5){//�X�m��
		switch(data.time/600){
			case 9: S= 300;break;
			case 10:S= 500;break;
			case 11:S= 700;break;
			case 12:S= 600;break;
			case 13:S=1000;break;
			case 14:S= 900;break;
			case 15:S= 800;break;
			case 16:S= 700;break;
			case 17:S= 600;break;
			default:S= 500;break;
		}
		if(data.holiday == 1 && S != 0)S = S*13/10;//�x���O������
	}
	//�`���m��
	switch(data.tenki){
		case 0:D = 20000;break;//����
		case 1:D = 15000;break;//�܂�
		case 2:D = 10000;break;//�J
		case 3:D =  2000;break;//���J�Ƃ�
	}
	//�x��//���������̗͂̂Q��//�ő�1000000
	R = (int)pow(double(hp-sta[0])*1000/sta[0],2.0);

	//�m���v�Z
	T = fun.Rand(S+D+R)+1;

	if(T<=S			) Z = 0;
	else if(T<=S+D	) Z = 1;
	else if(T<=S+D+R) Z = 2;
	else			  Z = 3;

	int money_rimit = 100000;

	if(wep_t == 0) money_rimit = 1000 * (98 + lv * 2 + data.day / 7);
	if(wep_t == 1) money_rimit = 1200 * (98 + lv * 2 + data.day / 7);
	if(wep_t == 2) money_rimit = 1200 * (98 + lv * 2 + data.day / 7);
	if(wep_t == 3) money_rimit = 1700 * (98 + lv * 2 + data.day / 7);


	if(wep_c<=0){//����0�������������Ȃ��ΓX���o�C�g
		if(money < money_rimit) Z = 3;
		else					Z = 0;
	}
	if(hp<=0) Z = 2;//�̗�0�ȉ��Ȑ�΋x��
	if(data.time<4800 || data.time>10200) Z = 2;//�X��͋x�e����


	if(Z == 0)Z = select_shop();
	if(Z == 1)select_dungeon();
	if(Z == 2)select_rest();
	if(Z == 3)select_byte();

	return 1;
}
int HUNTER::sell_item(){

	int W = select_item();//�w�������I��
	int S = act_no;
	int E = talk_emp;
	int PRI;
	double RATE = 0.5;
	if(emp[E].skill == 18) RATE=0.75;
	else if(emp[E].skill == 17) RATE=1;

	if(act == 3){//�N���[�}�[
		emp[E].hp_lose(1200);
		emp[E].exp += int(shop[S].lv_ave*200);//�o���l10�{
		if(emp[E].skill != 19)shop_koukan[S] *= int(2*RATE);//�D���x�Q�{
	}else if(W>=0){
		int R = 1000;
		if(shop[S].mana_cnt[M_TENF] > 0) R /= 2;
		if(shop[S].mana_cnt[M_MATO] > 0) R /= 2;
		int S_CNT = 1;
		if(fun.Rand(R) < emp[E].st[2]*emp[E].tension/100){
			S_CNT = 2;
			if(fun.Rand(R) < emp[E].st[2]*emp[E].tension/150){
				S_CNT = 3;
				if(fun.Rand(R) < emp[E].st[2]*emp[E].tension/200){
					S_CNT = 4;
				}
			}
		}//�ő�S�̔�

		if(emp[E].skill == 15 && S_CNT<4) S_CNT++;
		if(emp[E].skill == 23		    ) S_CNT=4;

		PRI = wep[W].price * shop[S].price_rate;

		if(shop[S].medama_check(W) == 1) PRI = PRI * 8/10;

		if(p_card[S] == 1) PRI = PRI * 19 / 20;//�|�C���g�J�[�h
		if(shop[S].mana_cnt[M_TENF] >0 && fun.Rand(100) < 10) PRI = 0;//10%�Ŗ���

		S_CNT = min(S_CNT,shop[S].wep_rest[W]);
		if(S_CNT>1 && shop[S].mana_cnt[M_MATO] > 0) PRI =PRI * 9 / 10;


		for(int CNT=0;CNT<S_CNT;CNT++){
			shop[S].wep_rest[W] --;//������
			if(shop[S].wep_rest[W]<=0){
				shop[S].tana_now--;//����
				shop[S].tana_now_t[wep[W].type]--;
			}
			money -=   PRI;
			shop[S].money+=   PRI;
			emp[E].sell_now+= PRI;
			wep_a[wep_c] =	 wep[W].atk * shop[S].atk_j[W];
			wep_d[wep_c] = int(wep[W].dur * shop[S].dur_j[W]);
			wep_s[wep_c] = S;
			wep_c++;
			shop[S].souko_now--;
			shop[S].sellc_day[data.day] ++;
			shop[S].sell_day[data.day]               += PRI;
			shop[S].sellc_mon[data.mon] ++;
			shop[S].sell_mon[data.mon]               += PRI;			

			shop[S].shera_wepd[data.day][wep[W].type]+= PRI;
			shop[S].shera_wepm[data.mon][wep[W].type]+= PRI;

			shop[S].incom_mon[data.mon]           += PRI;//�����v

			if(S == P){
				draw.sell_t[W] += 10;
				if(draw.sell_t[W] > 30) draw.sell_t[W] = 30;
				sys.total_sell+=PRI;
				sys.total_sellc[wep[W].type]+=PRI;
			}
			shop[S].g_sell_t += PRI;
			shop[S].g_sell[wep[W].type] += PRI;

		}

		emp[E].exp += int(shop[S].lv_ave*25);
		if(shop[S].mana_cnt[M_PCAD]> 0) p_card[S] = 1;

		if(emp[E].shift == wep_t || emp[E].skill==16) emp[E].hp_lose(160);
		else										  emp[E].hp_lose(200);

		//�D���x�ω�
		if(emp[E].skill != 19){
			double KOUKAN = emp[E].st[2] + wep[W].atk * shop[S].atk_j[W] + wep[W].dur*shop[S].dur_j[W]*2;
			if(shop[S].mana_cnt[M_BURA]>0) KOUKAN = KOUKAN * 6/ 5;//�u�����h���S����
			for(int I=0;I<SHOP_M;I++)
            {//�D���x�ቺ
				shop_koukan[I] = max(shop_koukan[I] - int(KOUKAN / (30+p_card[I]*12+shop[I].mana_cnt[M_YURU]*12)),1+shop[I].mana_cnt[M_SURI]*49);
            }
			if(shop[S].mana_cnt[M_BURA]>0) KOUKAN = KOUKAN * 5/ 6;
			shop_koukan[S] = int(KOUKAN*RATE);//���X�D���x�Čv�Z
		}
	}else{//�~�������킪��������
		emp[E].exp += int(shop[S].lv_ave*25);
		if(emp[E].shift == wep_t || emp[E].skill==16) emp[E].hp_lose(240);
		else										  emp[E].hp_lose(300);
		shop_koukan[S] -= shop_koukan[S]/2;
	}

	emp[E].lv_up();

	act = 4;//�X����o��
	wait = 30;

	if(S == P){
		x = 150;
		y = 0;
	}

	return 1;
}
int HUNTER::time_up(){
	//�m���ŃN���[�}�[��or�ޓX

	int W,S;
	S = act_no;

	if(act == 3){
		act = 4;//�X���o��
		wait = 30;
		//�����D���đޏ�

		W = select_item();

		if( W <= 0)return 1;
		if(shop[S].wep_rest[W]<=0) return 1;//�D���镐�킪����

		shop[S].wep_rest[W] --;//������
		if(shop[S].wep_rest[W]<=0){
			shop[S].tana_now--;//����
			shop[S].tana_now_t[wep[W].type]--;
		}

		wep_a[wep_c] =	 wep[W].atk * shop[S].atk_j[W];//�U���͕␳
		wep_d[wep_c] = int(wep[W].dur * shop[S].dur_j[W]);
		wep_s[wep_c] = S;
		wep_c++;
		shop[S].souko_now--;
	}else if(crame_hantei(2)){//�N���[�}�[��
		act = 3;
		talk_max*=2;
		wait = talk_max;
		if(fun.Rand(1) != 0){
			shop_koukan[act_no] /=2 ;//�D���x����
			act = 4;//�X���o��
			wait = 30;
		}
	}else{
		shop_koukan[act_no] -= shop_koukan[act_no]/2 ;//�D���x����
		act = 4;//�X���o��
		wait = 30;
	}

	if(S == P && act == 4){
		x = 144 + fun.Rand(12);
		y =0;
	}

	return 1;
}
int HUNTER::act_now(){

	if(act == 1)	  time_up();//�X�g���X���E�I
	else if(act == 2) sell_item();//���I��
	else if(act == 3) time_up();//�N���[�}�[�ޏ�
	else if(act == 4) shop_out();//�ޓX
	return 1;
}
int HUNTER::shop_enter(){
	int S = act_no;
	act = 1;

	//�ʏ펞�ő�7.5%
	if(crame_hantei(1)) act = 3;//�N���[�}�[���X

	wait = b_w*5 + 600;

	talk_max = wait;
	if(act_no == P)x = vx*1000;

	for(int R=0;R<SHOP_SP;R++){
		if(shop[S].cust_list[R] == -1){
			shop[S].cust_list[R] = no;//�q���X�g�󂫂ɒǉ�
			break;
		}
	}
	shop[S].cust_cnt++;
	shop[S].cust_cnt_t[wep_t]++;
	shop[S].cust_day[data.day][wep_t]++;//���q�����v�{
	shop[S].cust_mon[data.mon]++;

	if(S == P){
		sys.total_cust++;
	}
	shop[S].g_cust++;

	return 1;
}
int HUNTER::crame_hantei(int N){

	int S = act_no;
	int CR = data.creame_rate;
	int BW_B = -50;
	if(data.boom == 5) CR *= 5;
	
	if(N != 1) BW_B = 0;

	CR *= shop[S].monster_b;
	CR *= N;

	CR = int((b_w + shop[S].b_w + BW_B)*CR*N / 3000);

	if(fun.Rand(10000) > 10000 - CR) return 1;//�N���[�}�[

	return 0;
}

int HUNTER::cul_yosan()
{
    return int(std::sqrt(money) * 33);
}