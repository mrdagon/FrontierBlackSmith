#pragma once

#define range(x,y,x2,y2) Inp.m_x >= x && Inp.m_x <= x+x2  && Inp.m_y >= y && Inp.m_y <= y+y2 //�}�E�X�͈͌v�Z
#define range2(x,y,x2,y2) X >= x && X <= x+x2  && Y >= y && Y <= y+y2 //�}�E�X�͈͌v�Z

#include <list>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iostream>

/*�֐���*/
int FUN::main()
{
	data.font[0]= CreateFontToHandle( NULL , 18 , 5 ) ;
	data.font[1]= CreateFontToHandle( NULL , 24 , 5 ) ;
	data.font[2]= CreateFontToHandle( NULL , 14 , 5 ) ;

	data.font[3]= CreateFontToHandle( "�l�r ����" , data.window_y/8 , 5 ) ;
	data.font[4]= CreateFontToHandle( "�l�r ����" , data.window_y/20 , 5 ) ;

	set_rand(GetNowCount());

	for(int H=0;H<HUN_M ;H++) hun[H].no  = H;
	for(int S=0;S<SHOP_M;S++) shop[S].no = S;
	for(int E=0;E<EMP_M;E++)  emp[E].no  = E;
	
	/*�f�[�^�̓ǂݍ���*/
	fun.gaibu_load();
	fun.make_define();
	fun.gra_load();
	fun.sound_load();
	fun.sound_volset();

	data.now_save = 0;
	data.mode = 0;

	//���t�`�F�b�N
	time_t timer;
	struct tm t_st;

	/* ���ݎ����̎擾 */			
	timer = time(NULL);
	/* ���ݎ������\���̂ɕϊ� */
	localtime_s(&t_st,&timer);

	int day = t_st.tm_year * 365 + t_st.tm_yday;

	sys.date = day;

	/*�V�i���I�e�X�g*/
	//EVE_FUN::Sin().eve_test();

	while(1)
	{
		fun.bgm_ok(0);
		if(fun.title() == -1) return 1;
		
		fun.gaibu_load();
		fun.make_tenin();
		fun.make_start();
		fun.make_map(0);

		fun.bgm_ok(1);
		int N = fun.data_load(data.now_save);//�f�[�^�̓ǂݍ���

		EVE_FUN::Sin().mana_setumei();
		EVE_FUN::Sin().seido_setumei();

        //�Ǎ����s��N=-1
		fun.name_set(N + 1);//���O������	
		make_map(N + 1);

		for(int S=0;S<SHOP_M;S++){
			shop[S].cul_seiz_kair();//�����l�Čv�Z
			shop[S].cul_kaihosei();
			shop[S].cul_timeido();
		}

		fun.work_main();

		fun.medal_check();

		if(fun.err_c()== -1) break;
	}

	return 1;
}
int FUN::title(){

	int L = 0;

	data.now_save = -1;

	while(1){
		fun.inp_check();
		L = draw.title();
		ScreenFlip();
		
		if(fun.err_c()== -1) return -1;
		if(Inp.m_LC == 1){
			switch(L){
				case 6:
					//�͂��߂���
					fun.select_mode();
				break;
				case 7:
					//�Â�����
					fun.load_mode();
				break;
				case 9://����
				case 10://��p
				case 11://�L�^
				case 12://���_��
					if(  !sys.play_flag[1] ) break;
					se_ok(4);
					fun.tutorial(17);
					if(L==9)fun.wep_db();
					if(L==10)fun.mana_db();
					if(L==11)fun.record_db();
					if(L==12)fun.medal_db();
                    break;
				case 14://�N���W�b�g
					if(L==14)fun.credit_db();
				break;
				case 15://�R���t�B�O
					se_ok(4);
					option();
				break;
				case 16://�p�X���[�h
					if( sys.pass_on == 1 || !sys.play_flag[1] ) break;
					input_pass();
				break;
				case 17://�I��
					return -1;
				break;
			}
		}

		if(data.now_save >= 0) break;
	}

	return 1;
}
int FUN::wep_db(){

	while(1)
	{
		fun.inp_check();
		draw.wep_db();
		ScreenFlip();
		if(Inp.m_RC == 1) break;
		if(fun.err_c()== -1) return -1;
	}

	return 1;
}
int FUN::mana_db(){


	EVE_FUN::Sin().mana_setumei();

	while(1){
		fun.inp_check();
		draw.mana_db();
		ScreenFlip();
		if(Inp.m_RC == 1) break;
		if(fun.err_c()== -1) return -1;
	}

	return 1;
}
int FUN::record_db(){

	while(1){
		fun.inp_check();
		draw.record_db();
		ScreenFlip();
		if(Inp.m_RC == 1) break;
		if(fun.err_c()== -1) return -1;
	}

	return 1;
}
int FUN::medal_db(){
	
	medal_check();

	while(1){
		fun.inp_check();
		draw.medal_db();
		ScreenFlip();
		if(Inp.m_RC == 1) break;
		if(fun.err_c()== -1) return -1;
	}

	return 1;
}
int FUN::credit_db(){

	while(1)
	{
		fun.inp_check();
		draw.credit_db();
		ScreenFlip();
		if(Inp.m_RC == 1) break;
		if(fun.err_c()== -1) return -1;
	}

	return 1;
}

int FUN::game_over(){

	fun.tutorial(18);
	
	//��ʂ��O���[
	draw.work();
	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 200) ;
	DrawBox(0,0,data.window_x,data.window_y,GetColor(0,0,0),1);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

	int SEL = 0;

	while(1){
		fun.inp_check();
		if(fun.err_c()== -1) return -1;//�����I��
		SEL = draw.game_over();
		if( SEL > 0) break;
		ScreenFlip();
	}
	//�L�^�X�V���̂����
	game_rerecord();//�L�^�X�V����
	medal_check();//���_���擾����

	return SEL;
}
int FUN::select_mode(){

	//�V�K�Q�[�����[�h
	int L = -1;
	load_rabel();

	data.mode = -1;
	data.nando = -1;
	data.new_load = 0;

	while(1){
		fun.inp_check();
		if(fun.err_c()== -1) return -1;//�����I��
		if(data.mode == -1)	draw.select_mode();
		else				draw.select_nanndo();
		if(data.mode == -2) break;
		if(data.mode != -1 && data.nando != -1){
			//�m�F�E�B���h�E
			char str[256];
			sprintf_s(str,"%s�@%s--����ŃQ�[�����n�߂܂����H",data.mode_n[data.mode+1].c_str(),data.nanndo_n[data.nando+1].c_str());

			if( draw.kakunin(str,0) == 1){
				//���x���ǉ�
				data.now_save = rabel.cnt;
				rabel.cnt++;
				rabel.list.reserve(rabel.cnt);
				rabel.list.push_back(SAVE_RABEL::DATA());
				
				time_t timer;
				struct tm t_st;

				/* ���ݎ����̎擾 */			
				timer = time(NULL);
			    /* ���ݎ������\���̂ɕϊ� */
			    localtime_s(&t_st,&timer);
				char str2[128];
				sprintf_s(str2,"%d_%d_%d_%2d%2d%2d.dat",t_st.tm_year+1900,t_st.tm_mon,t_st.tm_mday,t_st.tm_hour,t_st.tm_min,t_st.tm_sec);
				
				rabel.list[data.now_save].name = str2;
				
				return 1;//���[�h�I�����Ď��s
			}else{
				data.mode = -1;
				data.nando = -1;
			}
		}
		ScreenFlip();
	}

	return -1;
}
int FUN::load_mode(){

	//���x���̓ǂݍ���
	load_rabel();
	//���X�g�\�����đI��
	int R = 0;

	while(1){
		fun.inp_check();
		if(fun.err_c()== -1) return -1;//�����I��

		R = draw.select_save();

		if( R == -2 ) return 1;//�L�����Z��
		if( R >= 0){//�f�[�^�I��
			data.now_save = R;
			break;
		}

		data.new_load = 1;

		ScreenFlip();
	}

	return 1;
}
int FUN::option(){

	int OK = 0;//�ύXor�L�����Z���t���O
	int size;
	int wide = data.wide;
	int full = opt.full_scr;
	int bgm = opt.bgm_size;
	int wav = opt.wev_size;
	int vram = opt.v_ram;

	if(opt.window_x<=1024)			size = 0;
	else if(opt.window_x<=1280)		size = 1;
	else if(opt.window_x<=1440)		size = 2;
	else if(opt.window_x<=1600)		size = 3;
	else							size = 4;

	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 200) ;
	DrawBox(0,0,data.window_x,data.window_y,GetColor(0,0,0),1);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

	int PL;

	while(1){
		fun.inp_check();
		//�ύX����
		if(Inp.m_x >= data.window_x/2 && Inp.m_x < data.window_x/2 + 90 && Inp.m_LC == 1)			PL = -1;
		else if(Inp.m_x >= data.window_x/2+90 && Inp.m_x < data.window_x/2 + 180 && Inp.m_LC == 1)	PL = 1;
		else																						PL = 0;

		if( Inp.m_x >= data.window_x/2+183 &&
			Inp.m_x <= data.window_x/2+223 &&
			Inp.m_y >= data.window_y/2-200 &&
			Inp.m_y <= data.window_y/2-160 &&
			Inp.m_LC == 1){
			break;
		}
		if(Inp.m_RC == 1){
			break;
		}


		if(Inp.m_LC == 1 && Inp.m_y>data.window_y/2 - 150)switch((Inp.m_y - data.window_y/2 + 150)/40){
			case 0://�E�B���h�E�T�C�Y
				size += PL;
				if(size <wide)size = wide;
				if(size >4)size = 4;
				se_ok(6);
			break;
			case 1://�A�X�y�N�g��4:3 16:9
				wide = (wide + 1)%2;
				if(size < wide)size = wide;
				se_ok(6);
			break;
			case 2://�t���X�N���[��or�E�B���h�E
				full = (full + 1)%2;
				se_ok(6);
			break;
			case 3://Vram
				vram = (vram + 1)%2;
				se_ok(6);
			break;
			case 4://BGM
				bgm += PL * 10;
				if(bgm < 0 ) bgm = 0;
				if(bgm >100) bgm = 100;
				se_ok(6);
			break;
			case 5://���ʉ�
				wav += PL * 10;
				if(wav <0  ) wav = 0;
				if(wav >100) wav = 100;
				se_ok(6);
			break;
			case 7://OK&�L�����Z��
				if(Inp.m_x >= data.window_x/2-215 && Inp.m_x <= data.window_x/2-25){
					OK = 1;				
					se_ok(6);
				}
				if(Inp.m_x >= data.window_x/2-5   && Inp.m_x <= data.window_x/2+185){
					OK = -1;
					se_ok(3);
				}
			break;
		}

		draw.option(size,wide,full,bgm,wav,vram);
		ScreenFlip();
		if(fun.err_c()== -1 || OK != 0) break;//�G���[or
	}

	if(OK == 1){
		switch(size){
			case 0:opt.window_x = 1024;break;
			case 1:opt.window_x = 1280;break;
			case 2:opt.window_x = 1440;break;
			case 3:opt.window_x = 1600;break;
			case 4:opt.window_x = 1920;break;
		}		
		if(wide == 0)	opt.window_y = opt.window_x/4*3;
		else			opt.window_y = opt.window_x/16*9;
		data.wide = wide;
		opt.full_scr = full;
		opt.v_ram = vram;
		opt.bgm_size = bgm;
		opt.wev_size = wav;

		int mx = GetSystemMetrics(SM_CXSCREEN);
		int my = GetSystemMetrics(SM_CYSCREEN);


		if(opt.full_scr == 1){//�t���X�N���[��
			data.window_x = mx;
			data.window_y = my;
		}else{
			data.window_x = min(opt.window_x , mx);
			data.window_y = min(opt.window_y , my);
		}

		SetGraphMode( data.window_x , data.window_y ,16) ;//�O���t�B�b�N���[�h&�𑜓x����
		SetScreenMemToVramFlag( opt.v_ram ) ;//�u�������g�p���Ȃ�
		SetDrawScreen( DX_SCREEN_BACK ) ;//�`�ʐ�𗠉�ʂɐݒ�
		SetTransColor( 190 , 179 , 145 ) ;// ���ߐF��ύX
		gra_load(/*�摜�̓ǂݍ���*/);

		SetVolumeMusic( opt.bgm_size*opt.bgm_size*255/10000 );
		sound_volset();//���ʍČv�Z
	}

	return 1;
}
int FUN::tutorial_menu(){
	int N = 0;//�I��ԍ�

	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 200) ;
	DrawBox(0,0,data.window_x,data.window_y,GetColor(0,0,0),1);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

	while(1){
		fun.inp_check();
		
		N = draw.tutorial_menu();
		ScreenFlip();

		if( Inp.m_x >= data.window_x/2+258 &&
			Inp.m_x <= data.window_x/2+298 &&
			Inp.m_y >= data.window_y/2-280 &&
			Inp.m_y <= data.window_y/2-240 &&
			Inp.m_LC == 1){
			break;
		}

		if(N>=0 && N<19 && Inp.m_LC == 1){
			if(sys.help_flag[N] == 1){
				tutorial(N,1);
				draw.work();
				SetDrawBlendMode( DX_BLENDMODE_ALPHA , 200) ;
				DrawBox(0,0,data.window_x,data.window_y,GetColor(0,0,0),1);
				SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
			}
		}

		if( Inp.m_RC == 1) break;

		if(fun.err_c()== -1) break;//�G���[or
	}

	return 1;
}
int FUN::tutorial(int N,int OK){

	int PA = 1;
	int PM = 1;
	int WIDE = 980;
	int HIGH = 720;

	if(OK == 0 && sys.help_flag[N] == 1) return 1;//��x�����̂̓X�L�b�v

	//��ʂ��O���[
	//draw.work();
	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 200) ;
	DrawBox(0,0,data.window_x,data.window_y,GetColor(0,0,0),1);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

	while(1){
		//�w�i���\��
		draw.waku(data.window_x/2-WIDE/2	,data.window_y/2-HIGH/2   ,WIDE    ,HIGH,3);

		PM = draw.tutorial_00(PA,N);

		//draw.win_tmes("�e�X�g@",40,40,5,3);

		if(PA != 1)	DrawRotaGraph(data.window_x/2+WIDE/2-130,data.window_y/2+HIGH/2-30,2,0,gra.ico[74],0,1);
		if(PA != PM)DrawRotaGraph(data.window_x/2+WIDE/2- 25,data.window_y/2+HIGH/2-30,2,0,gra.ico[74],0);

		DrawRotaGraph(data.window_x/2+WIDE/2-30,data.window_y/2-HIGH/2+35,2,0,gra.ico[57],0);

		//�؁[�����\��
		draw.suu_bmf(data.window_x/2+WIDE/2-100,data.window_y/2+HIGH/2-30,3,PA,0);
		draw.mes(	 data.window_x/2+WIDE/2- 75,data.window_y/2+HIGH/2-35,"/",color.siro,color.kuro,0);
		draw.suu_bmf(data.window_x/2+WIDE/2- 50,data.window_y/2+HIGH/2-20,2,PM,0);

		ScreenFlip();

		//���씻��
		while(1){
			fun.inp_check();

			if(Inp.m_LC+Inp.m_RC == 1 ){
				if(Inp.m_RC == 1) PA--;
				else if(Inp.m_y > data.window_y/2+HIGH/2-50 && Inp.m_y < data.window_y/2+HIGH/2-10 && Inp.m_x < data.window_x/2+WIDE/2-110 && Inp.m_x > data.window_x/2+WIDE/2-150) PA--;
				else PA++;
				if(PA < 1 ) PA = 1;
				if(PA > PM) PA = PM;
				break;
			}


			if(Inp.m_LC == 1 &&
				Inp.m_y > data.window_y/2-HIGH/2+15 &&
				Inp.m_y < data.window_y/2-HIGH/2+55 &&
				Inp.m_x > data.window_x/2+WIDE/2-50 &&
				Inp.m_x < data.window_x/2+WIDE/2-10){
					break;
			}

			if(fun.err_c()== -1) break;
		}

		if(Inp.m_LC == 1 &&
			Inp.m_y > data.window_y/2-HIGH/2+15 &&
			Inp.m_y < data.window_y/2-HIGH/2+55 &&
			Inp.m_x > data.window_x/2+WIDE/2-50 &&
			Inp.m_x < data.window_x/2+WIDE/2-10){
			break;
		}
		if(fun.err_c()== -1) break;
	}

	sys.help_flag[N] = 1;

	return 1;
}
int FUN::game_rerecord(){
	//���ʂ̍X�V
	//���X�����̂�
	int t_s = 0;
	int t_m = 0;
	int t_c = 0;
	int t_h = 0;

	for(int i=0;i<DAY_M;i++){
		t_s += shop[P].sellc_day[i];
		t_m += shop[P].seizc_day[i];
		t_c += shop[P].seiz_day[i];
	}

	for(int i=0;i<MANTH_M;i++){
		t_h += shop[P].emp_mon[i];
	}

	if(sys.score_record[data.mode][0] < t_s)				sys.score_record[data.mode][0] = t_s;//�̔���
	if(sys.score_record[data.mode][1] < shop[P].g_cust)		sys.score_record[data.mode][1] = shop[P].g_cust;//���q��
	if(sys.score_record[data.mode][2] < data.goal_sell_t)	sys.score_record[data.mode][2] = data.goal_sell_t;//����グ-���v
	if(sys.score_record[data.mode][3] < data.goal_sell[0])	sys.score_record[data.mode][3] = data.goal_sell[0];//����グ
	if(sys.score_record[data.mode][4] < data.goal_sell[1])	sys.score_record[data.mode][4] = data.goal_sell[1];//����グ
	if(sys.score_record[data.mode][5] < data.goal_sell[2])	sys.score_record[data.mode][5] = data.goal_sell[2];//����グ
	if(sys.score_record[data.mode][6] < data.goal_sell[3])	sys.score_record[data.mode][6] = data.goal_sell[3];//����グ
	if(sys.score_record[data.mode][7] < t_m)				sys.score_record[data.mode][7] = t_m;//������
	if(sys.score_record[data.mode][8] < t_c)				sys.score_record[data.mode][8] = t_c;//������
	if(sys.score_record[data.mode][9] < t_h)				sys.score_record[data.mode][9] = t_h;//�l����
	if(sys.score_record[data.mode][10] < data.goal_turu)	sys.score_record[data.mode][10] = data.goal_turu;//��͂�����
	if(sys.score_record[data.mode][11] < shop[P].kabu_price)sys.score_record[data.mode][11] = (int)shop[P].kabu_price;//����
	if(sys.score_record[data.mode][12] < data.goal_wepcre)	sys.score_record[data.mode][12] = data.goal_wepcre;//�J����
	if(sys.score_record[data.mode][14] < data.jinkou)		sys.score_record[data.mode][14] = data.jinkou;//�l��
	if(sys.score_record[data.mode][15] < shop[P].money)		sys.score_record[data.mode][15] = int(shop[P].money);//����

    if( data.game_over / 100 != P ) return 1;//�s�k��

	if(sys.score_record[data.mode][13] > data.day)			sys.score_record[data.mode][13] = data.day;//�N���A����
	sys.score_record[data.mode][16]++;//�N���A��
	if(sys.score_record[data.mode][17] < data.nando+1) sys.score_record[data.mode][17] = data.nando+1;//��Փx

    //��Փx�̊J��        
    if( sys.nanndo_flag < data.nando+1 ) sys.nanndo_flag = data.nando+1;

	sys.win_cnt[data.game_over % 100]++;

	return 1;
}
int FUN::medal_check(){

    bool isGet = false;
	//�M�͎擾����
	for(int M=0;M<100;M++){
		int OK = 0;
		if(sys.medal_cnt[M] > 0) continue;//�擾�ς݂Ȃ�
		//��������
		switch(M){
			case 0://�o�c����
			case 1:
			case 2:
				OK = sys.total_day;
				break;
			case 3://�̔���
			case 4:
			case 5:
				OK = sys.score_record[0][0];
				break;
			case 6://���q��
			case 7:
			case 8:
				OK = sys.score_record[0][1];
				break;
			case 9://����グ
				OK = sys.score_record[0][3];
				break;
			case 10:
				OK = sys.score_record[0][4];
				break;
			case 11:
				OK = sys.score_record[0][5];
				break;
			case 12:
				OK = sys.score_record[0][6];
				break;
			case 13:
				OK = sys.score_record[0][2];
				break;
			case 14://������
			case 15:
			case 16:
				OK = sys.score_record[0][7];
				break;
			case 17://����}��
			case 18:
			case 19:
			case 20:
				for(int i=(M-17)*100;i<(M-16)*100;i++)
				{
					if( sys.wep_maket[i] > 0 ) OK++;
				}
				break;
			case 21://��p�}��
			case 22:
			case 23:
			case 24:
			case 25:
				for(int i=(M-21)*60;i<(M-20)*60;i++)
				{
					if( sys.mana_total[i] > 0 ) OK++;
				}
				break;
			case 26://�`���[�g���A��
				for(int i=0;i<100;i++)
				{
					if(sys.help_flag[i] > 0 ) OK++;					
				}
				break;
			case 27://��������
			case 28:
			case 29:
			case 30:
			case 31:
			case 32:
			case 33:
			case 34:
			case 35:
			case 36:
			case 37:
			case 38:
				OK = sys.win_cnt[M-27];
				break;
			case 39://�G���f�B���O
			case 40:
				OK = sys.win_cnt[M-27];
				break;
			case 41://�V�i���I
			case 42:
			case 43:
			case 44:
			case 45:
			case 46:
			case 47:
			case 48:
			case 49:
			case 50:
			case 51:
			case 52:
			case 53:
			case 54:
			case 55:
			case 56:
			case 57:
			case 58:
			case 59:
			case 60:
			case 61:
			case 62:
			case 63:
			case 64:
			case 65:
			case 66:
			case 67:
			case 68:
			case 69:
			case 70:
			case 71:
			case 72:
			case 73:
			case 74:
			case 75:		
			case 76:
			case 77:
			case 78:
			case 79:
			case 80:
			case 81:
			case 82:
			case 83:
			case 84:
			case 85:
			case 86:
			case 87:
			case 88:
			case 89:
			case 90:
			case 91:
			case 92:
			case 93:
			case 94:
				OK = sys.score_record[(M-41)/3][17];
				break;
			case 95://�A���P�[�g
				OK = sys.pass_on;
				break;
			case 96://���_������
				for(int i=0;i<100;i++)
				{
					if( sys.medal_cnt[i] > 0 && sys.medal_gold[i] == 2) OK++;
				}
				break;
			case 97://���_������
				for(int i=0;i<100;i++)
				{
					if( sys.medal_cnt[i] > 0 && sys.medal_gold[i] == 1) OK++;
				}
				break;
			case 98://���_������
				for(int i=0;i<100;i++)
				{
					if( sys.medal_cnt[i] > 0 && sys.medal_gold[i] == 0) OK++;
				}
				break;
			case 99://���_�������v
				for(int i=0;i<100;i++)
				{
					if( sys.medal_cnt[i] > 0 ) OK++;
				}
				break;
		}

		if( OK < sys.medal_nanndo[M] ) continue;
        isGet = true;
		//���ʏ���
		sys.medal_cnt[M]++;
		char str[256];
		sprintf_s(str,"�u%s�v--�M�͂��l�����܂����I",sys.medal_name[M].c_str());
		draw.kakunin(str,1);

		//�J������
		switch(M){
			case 0:
				sys.play_flag[1] = true;
				draw.kakunin("�u���R�o�ρv���I���\�ɁI",1);
			break;		
			case 98:
				sys.play_flag[2] = true;
				draw.kakunin("�u���_���̉��v���I���\�ɁI",1);
			break;
			case 7:
				sys.play_flag[3] = true;
				draw.kakunin("�u�q����`�v���I���\�ɁI",1);
			break;
			case 4:
				sys.play_flag[4] = true;
				draw.kakunin("�u��q�����v���I���\�ɁI",1);
			break;
			case 1:
				sys.play_flag[5] = true;
				draw.kakunin("�u������Ăāv���I���\�ɁI",1);
			break;
			case 44:
				sys.play_flag[6] = true;
				draw.kakunin("�u�V�F�A�m���P�v���I���\�ɁI",1);
			break;
			case 60:
				sys.play_flag[7] = true;
				draw.kakunin("�u��͂���D���v���I���\�ɁI",1);
			break;
			case 63:
				sys.play_flag[8] = true;
				draw.kakunin("�u�J��őO���v���I���\�ɁI",1);
			break;
			case 65:
				sys.play_flag[9] = true;
				draw.kakunin("�u���o�̕��v���I���\�ɁI",1);
			break;
			case 68:
				sys.play_flag[10] = true;
				draw.kakunin("�u���ɂ̑��v���I���\�ɁI",1);
			break;
			case 71:
				sys.play_flag[11] = true;
				draw.kakunin("�u�����̌��v���I���\�ɁI",1);
			break;
			case 74:
				sys.play_flag[12] = true;
				draw.kakunin("�u�����̋|�v���I���\�ɁI",1);
			break;
			case 13:
				sys.play_flag[13] = true;
				draw.kakunin("�u�E�F�|���}�C�X�^�[�v���I���\�ɁI",1);
			break;
			case 15:
				sys.play_flag[14] = true;
				draw.kakunin("�u�M������v���I���\�ɁI",1);
			break;
			case 5:
				sys.play_flag[15] = true;
				draw.kakunin("�u��n���^�[����v���I���\�ɁI",1);
			break;
			case 2:
				sys.play_flag[17] = true;
				draw.kakunin("�u����̏I���v���I���\�ɁI",1);
			break;
			case 95:
                sys.play_flag[2] = true;
                sys.play_flag[3] = true;
                sys.play_flag[4] = true;
                sys.play_flag[5] = true;
                sys.play_flag[6] = true;
                sys.play_flag[9] = true;
                sys.play_flag[14] = true;
				draw.kakunin("�F��ȃ��[�h���J�����ꂽ�I",1);
			break;
		}
	}

    if( isGet ) sys_save();

	return 1;
}
/*�f�[�^�ۑ�*/
int FUN::data_save(int N/*�ۑ��ǂݍ��݉��*/){

	FILE *fp;
	errno_t err;
	
	std::string name;

	SetCurrentDirectory(data.szDir);
	name = "File/save/" + rabel.list[N].name;

	if( (err = fopen_s( &fp, name.c_str(), "wb" )) !=0 ) return -1;
	//����������������������������������������������������������������������������
	//��{�f�[�^
	fwrite(&data.play,sizeof(int),1,fp);//�v���C���[����
	fwrite(&data.nando,sizeof(int),1,fp);//��Փx
	fwrite(&data.mode,sizeof(int),1,fp);//�Q�[�����[�h
	fwrite(&data.day,sizeof(int),1,fp);//���t
	fwrite(&data.play_time,sizeof(int),1,fp);//���v���C����
	fwrite(&data.game_over,sizeof(int),1,fp);//���v���C����
	fwrite(&data.ver,sizeof(int),1,fp);//�o�[�W����

	fwrite(&data.mon,sizeof(int),1,fp);//���t
	fwrite(&data.time,sizeof(int),1,fp);//����
	fwrite(&data.tenki,sizeof(int),1,fp);//�V�C

	fwrite(&data.jinkou,sizeof(int),1,fp);//�l��
	fwrite(&data.jinkou_max,sizeof(int),1,fp);//�l��
	fwrite(&data.jinkou_up,sizeof(int),1,fp);
	fwrite(&data.total_des,sizeof(int),1,fp);//������
	fwrite(data.des_mon,sizeof(int),MANTH_M,fp);//���Ҍ���
	fwrite(data.jinkou_mon,sizeof(int),MANTH_M,fp);//�l������

	fwrite(&data.shop_cnt,sizeof(int),1,fp);

	fwrite(data.eve_flag,sizeof(int),EVE_M,fp);//�C�x���g�p�t���O

	fwrite(&data.creame_rate,sizeof(int),1,fp);
	fwrite(&data.kairyou_rate,sizeof(int),1,fp);
	fwrite(&data.hirameki_rate,sizeof(int),1,fp);

	fwrite(&data.taiguu_ok,sizeof(int),1,fp);
	fwrite(data.taikai,sizeof(int),2,fp);

	fwrite(&data.boom,sizeof(int),1,fp);
	fwrite(&data.boom_rest,sizeof(int),1,fp);

	fwrite(&data.kami_ikari,sizeof(int),1,fp);//�_�̓{��c�����

	fwrite(data.kabu_cnt,sizeof(int),5,fp);
	fwrite(data.kabu_price,sizeof(double),5,fp);
	fwrite(data.wep_ganso,sizeof(int),WEP_M,fp);

	fwrite(&data.goal_cust  ,sizeof(int),1,fp);
	fwrite(&data.goal_kabu  ,sizeof(int),1,fp);
	fwrite(&data.goal_sell_t,sizeof(int),1,fp);
	fwrite(data.goal_sell   ,sizeof(int),4,fp);
	fwrite(&data.goal_turu  ,sizeof(int),1,fp);
	fwrite(&data.goal_wepcre,sizeof(int),1,fp);
	fwrite(&data.goal_money ,sizeof(int),1,fp);
	fwrite(&data.goal_taikai,sizeof(int),1,fp);
	fwrite(&data.goal_boss  ,sizeof(int),1,fp);
	
	fwrite(&data.exp_rate	,sizeof(int),1,fp);
	fwrite(data.req_act		,sizeof(int),12,fp);


	//����������������������������������������������������������������������������
	//�`���ҏ��
	for(int H=0;H<data.jinkou_max;H++){
		fwrite(&hun[H].life,sizeof(int),1,fp);//������
		fwrite(&hun[H].lv,sizeof(int),1,fp);//���x��
		fwrite(&hun[H].exp,sizeof(int),1,fp);//�o���l
		fwrite(&hun[H].job,sizeof(int),1,fp);//�E��
		fwrite(hun[H].sta,sizeof(int),4,fp);//�X�e�[�^�X
		fwrite(&hun[H].hp,sizeof(int),1,fp);//����HP
		fwrite(&hun[H].skill,sizeof(int),1,fp);//���Z
		fwrite(&hun[H].wep_t,sizeof(int),1,fp);//������
		fwrite(&hun[H].rank,sizeof(int),1,fp);//�W���u�����N
		fwrite(&hun[H].dun_lv,sizeof(int),1,fp);//�_���W�������x��

		fwrite(&hun[H].money,sizeof(int),1,fp);//���ݎ���
		fwrite(&hun[H].wep_c,sizeof(int),1,fp);//���폊����
		fwrite(hun[H].wep_a,sizeof(double),8,fp);//����U��
		fwrite(hun[H].wep_d,sizeof(int),8,fp);//����ϋv
		fwrite(hun[H].wep_s,sizeof(int),8,fp);//����ϋv
		fwrite(hun[H].shop_wepn,sizeof(int),SHOP_M,fp);//�X�i�����m��
		fwrite(hun[H].shop_koukan,sizeof(int),SHOP_M,fp);//�X�D���x
		fwrite(hun[H].senden_boost,sizeof(int),SHOP_M,fp);//�X�D���x
		fwrite(hun[H].like_t,sizeof(int),3,fp);//�����A�������悳�A�����̉e���x
	//�s�����
		fwrite(&hun[H].act,sizeof(int),1,fp);//�s�����//�ҋ@�A�X���A
		fwrite(&hun[H].act_no,sizeof(int),1,fp);//�X�ԍ��A�_���W�����ԍ�
		fwrite(&hun[H].b_w,sizeof(int),1,fp);//�u���b�N�x//����,�������A�X�g���X�Ⴂ
		fwrite(&hun[H].stress,sizeof(int),1,fp);//��������
		fwrite(&hun[H].wait,sizeof(int),1,fp);//�ҋ@����
		fwrite(&hun[H].talk_max,sizeof(int),1,fp);//�Q�[�W�ő�
		fwrite(&hun[H].talk_emp,sizeof(int),1,fp);//���ݑΉ����Ă���X��
		fwrite(&hun[H].x,sizeof(int),1,fp);
		fwrite(&hun[H].y,sizeof(int),1,fp);
		fwrite(&hun[H].vx,sizeof(int),1,fp);
		fwrite(hun[H].p_card,sizeof(int),SHOP_M,fp);
	}
	//����������������������������������������������������������������������������
	//���R�[�h
	for(int S=0;S<SHOP_M;S++){
		int D = data.day+1;
		int M = data.day/28+1;
		fwrite(shop[S].sellc_day,sizeof(int),D,fp);//�̔���
		fwrite(shop[S].sell_day,sizeof(int),D,fp);//����グ
		fwrite(shop[S].cust_day,sizeof(int),D*4,fp);//�q��
		fwrite(shop[S].seizc_day,sizeof(int),D,fp);//������
		fwrite(shop[S].seiz_day,sizeof(int),D,fp);//������
		fwrite(shop[S].shera_wepd,sizeof(int),D*4,fp);//�e����̔̔��V�F�A
		
		fwrite(shop[S].sellc_mon,sizeof(int),M,fp);//�̔���
		fwrite(shop[S].sell_mon,sizeof(int),M,fp);//����グ
		fwrite(shop[S].cust_mon,sizeof(int),M,fp);//�q��
		fwrite(shop[S].seizc_mon,sizeof(int),M,fp);//������
		fwrite(shop[S].seiz_mon,sizeof(int),M,fp);//������

		fwrite(shop[S].emp_mon,sizeof(int),M,fp);//�ٗp��//�����Ɍv�Z
		fwrite(shop[S].manege_mon,sizeof(int),M,fp);//�o�c��p��p
		fwrite(shop[S].etc_mon,sizeof(int),M,fp);//��,���q�����Ɍv�Z
		fwrite(shop[S].incom_mon,sizeof(int),M,fp);//���v�����Ɍv�Z
		fwrite(shop[S].nougu_mon,sizeof(int),M,fp);//���v�����Ɍv�Z
		fwrite(shop[S].total_mon,sizeof(int),M,fp);//���Y//�����Ɍv�Z
		fwrite(shop[S].kabu_mon,sizeof(int),M,fp);
		fwrite(shop[S].shera_wepm,sizeof(int),M*4,fp);//�e����̔̔��V�F�A
		
	}
	//����������������������������������������������������������������������������
	//�X
	for(int S=0;S<SHOP_M;S++){
		fwrite(&shop[S].emp_cnt,sizeof(int),1,fp);
		fwrite(&shop[S].emp_kou,sizeof(int),1,fp);
		fwrite(shop[S].emp_list,sizeof(int),EMP_M,fp);//�X�����X�g

		fwrite(&shop[S].money,sizeof(double),1,fp);//����
		fwrite(&shop[S].b_w,sizeof(double),1,fp);//�u���b�N�x
		fwrite(&shop[S].koubou_t,sizeof(int),1,fp);//�c�Ǝ���
		fwrite(&shop[S].koubou_n,sizeof(int),1,fp);

		fwrite(shop[S].create_get,sizeof(int),3,fp);//�J���o���l
		fwrite(shop[S].create_exp,sizeof(int),3,fp);//�J���o���l
		fwrite(shop[S].create_lv,sizeof(int),3,fp);//�J����

		fwrite(&shop[S].nougu_req,sizeof(int),1,fp);//�_�k���v��

		fwrite(shop[S].wep_rest,sizeof(int),WEP_M,fp);//�݌ɐ�
		fwrite(shop[S].wep_cre,sizeof(int),WEP_M,fp);//�J���� -1�J���s�� 0�J���\�@1�J������
		fwrite(shop[S].wep_hday,sizeof(int),WEP_M,fp);//�M���Ă���̓���
		fwrite(shop[S].wep_make,sizeof(int),WEP_M,fp);//�J�������Y�i�s�x
		fwrite(shop[S].wep_kaicnt,sizeof(int),WEP_M,fp);//�J���E���ǐi�s�x
		fwrite(shop[S].wep_kaiexp,sizeof(int),WEP_M,fp);//
		fwrite(shop[S].wep_make_t,sizeof(int),WEP_M,fp);//�����Y��

		fwrite(shop[S].ninki_kai,sizeof(int),WEP_M,fp);//�l�C
		fwrite(shop[S].atk_kai,sizeof(int),WEP_M,fp);//�U��
		fwrite(shop[S].dur_kai,sizeof(int),WEP_M,fp);//�ϋv
		fwrite(shop[S].cost_kai,sizeof(int),WEP_M,fp);//�R�X�g
		fwrite(shop[S].time_kai,sizeof(int),WEP_M,fp);//����

		fwrite(&shop[S].yasuuri,sizeof(int),1,fp);//��ي���
		fwrite(&shop[S].price_rate,sizeof(int),1,fp);//��ي���
		fwrite(&shop[S].yasuuri_efe,sizeof(double),1,fp);

		fwrite(shop[S].bumon_lv,sizeof(int),5,fp);//����		MAX�` ��`�n��p�̌��ʂ��オ��A��`��p�M���\��

		fwrite(shop[S].bumon_exp,sizeof(int),5,fp);//����		MAX�` ��`�n��p�̌��ʂ��オ��A��`��p�M���\��

		fwrite(&shop[S].senden_b,sizeof(int),1,fp);//��`����		MAX�` ��`�n��p�̌��ʂ��オ��A��`��p�M���\��
		fwrite(&shop[S].mensetu_lv,sizeof(int),1,fp);//��`����		MAX�` ��`�n��p�̌��ʂ��オ��A��`��p�M���\��
	
		fwrite(&shop[S].total_saiyou,sizeof(int),1,fp);
		fwrite(&shop[S].total_yame,sizeof(int),1,fp);

		fwrite(&shop[S].lv_ave,sizeof(double),1,fp);
		fwrite(&shop[S].pay_ave,sizeof(double),1,fp);
		fwrite(&shop[S].mon_ave,sizeof(double),1,fp);
		fwrite(&shop[S].bw_bonus,sizeof(double),1,fp);

		fwrite(&shop[S].yasumi_max,sizeof(int),1,fp);//�x����		���̐��܂ŋx��ł���������
		fwrite(&shop[S].zangyou,sizeof(int),1,fp);//���o�c�Ǝ���	15������

		fwrite(shop[S].kabu_cnt,sizeof(int),5,fp);//�����		������ł̌��́A��[�łt�o
		fwrite(&shop[S].kabu_max,sizeof(int),1,fp);//�����		������ł̌��́A��[�łt�o
		fwrite(&shop[S].kabu_price,sizeof(double),1,fp);//�����		������ł̌��́A��[�łt�o
		fwrite(shop[S].kabu_rank,sizeof(int),5,fp);//�����		������ł̌��́A��[�łt�o

		fwrite(&shop[S].seizou_b,sizeof(int),1,fp);//�X������		�q�A�葬�x�ቺ
		fwrite(&shop[S].kairyou_b,sizeof(int),1,fp);//�X������		�q�A�葬�x�ቺ
		fwrite(&shop[S].tukare_b,sizeof(int),1,fp);//���l�r������
		fwrite(&shop[S].sekkyaku_b,sizeof(int),1,fp);//�X������		�q�A�葬�x�ቺ
		fwrite(&shop[S].kaihatu_b,sizeof(int),1,fp);//���l�r������
		fwrite(&shop[S].sabaki_b,sizeof(int),1,fp);//�X������		�q�A�葬�x�ቺ
		fwrite(&shop[S].stress_b,sizeof(int),1,fp);//���l�r������
		fwrite(&shop[S].yaruki_b,sizeof(int),1,fp);//�X������		�q�A�葬�x�ቺ
		fwrite(&shop[S].sinn_b,sizeof(int),1,fp);

		fwrite(&shop[S].size,sizeof(int),1,fp);
		fwrite(&shop[S].kouji,sizeof(int),1,fp);

		fwrite(&shop[S].souko_now,sizeof(int),1,fp);//�q�Ɍ���//���X���Ԃɉe��
		fwrite(&shop[S].souko_max,sizeof(int),1,fp);//�q�ɍő吔

		fwrite(&shop[S].tana_now,sizeof(int),1,fp);//�I���ݐ�//�W�q�͂ɉe��
		fwrite(shop[S].tana_now_t,sizeof(int),4,fp);//�e������

		fwrite(&shop[S].teikyuu,sizeof(int),1,fp);//��x���A�ő�P��
		fwrite(&shop[S].cust_cnt,sizeof(int),1,fp);//���q��
		fwrite(shop[S].cust_cnt_t,sizeof(int),4,fp);//�����ޖ��̗��q��
		fwrite(shop[S].cust_wep,sizeof(int),4,fp);//�����ޕʗ��q��
		fwrite(shop[S].cust_list,sizeof(int),SHOP_SP,fp);//���X�q���X�g
		fwrite(shop[S].cust_gold,sizeof(int),SHOP_SP,fp);//���X�q����S�[���h

		fwrite(&shop[S].p_mp,sizeof(double),1,fp);//�ő�}�l�W�����g�|�C���g
		fwrite(&shop[S].n_mp,sizeof(double),1,fp);//���݃}�l�W�����g�|�C���g
		fwrite(&shop[S].use_mana,sizeof(int),1,fp);//�J�z�}�l�W�����g�|�C���g
		fwrite(shop[S].mana_ok,sizeof(int),MANA_M,fp);//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��
		fwrite(shop[S].syou_mp,sizeof(int),MANA_M,fp);//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��
		fwrite(shop[S].syou_money,sizeof(int),MANA_M,fp);//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��
		fwrite(shop[S].mana_rest,sizeof(int),MANA_M,fp);//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��
		fwrite(shop[S].mana_cnt,sizeof(int),MANA_M,fp);//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��
		fwrite(shop[S].mana_day,sizeof(int),MANA_M,fp);//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��

		fwrite(&shop[S].holiday,sizeof(int),1,fp);//�e����̔̔��V�F�A
		fwrite(&shop[S].timeido,sizeof(double),1,fp);

		fwrite(shop[S].mana_b,sizeof(int),MANA_T,fp);//��p�g�p�l�o�␳
		fwrite(shop[S].mana_gb,sizeof(int),MANA_T,fp);//��p�g�p�����␳

		fwrite(&shop[S].kaihuku_b,sizeof(int),1,fp);//�񕜕␳�A�V����
		fwrite(&shop[S].kaihuku_bs,sizeof(int),1,fp);//�񕜕␳�A�V����
		fwrite(&shop[S].exp_b,sizeof(int),1,fp);//�o���l�␳
		fwrite(&shop[S].exp_bs,sizeof(int),1,fp);//�o���l�␳�A�V����
		fwrite(&shop[S].monster_b,sizeof(int),1,fp);//�N���[�}�[�������␳
		fwrite(&shop[S].syakai_b,sizeof(int),1,fp);//�Љ�l�x�ω��{�[�i�X
		fwrite(&shop[S].hp_up_b,sizeof(int),1,fp);//HP������
		fwrite(&shop[S].sei_up_b,sizeof(int),1,fp);//����������
		fwrite(&shop[S].kai_up_b,sizeof(int),1,fp);//�J��������
		fwrite(&shop[S].kya_up_b,sizeof(int),1,fp);//�q�J������
		fwrite(&shop[S].sek_up_b,sizeof(int),1,fp);//�ڋq������

		fwrite(&shop[S].mp_ninnzuu,sizeof(int),1,fp);//�l���ɂ��l�o�񕜃{�[�i�X
	
		fwrite(&shop[S].sk_pup,sizeof(int),1,fp);//�X�L�������m��
		fwrite(&shop[S].sk_rup,sizeof(int),1,fp);//�X�L�����]�m��
		fwrite(&shop[S].sk_qup,sizeof(int),1,fp);//�H�X�L���ω��m��

		fwrite(&shop[S].kabu_buy,sizeof(int),1,fp);//�������
		fwrite(&shop[S].nougu_up,sizeof(int),1,fp);
		fwrite(&shop[S].kyuuryou_b,sizeof(int),1,fp);//�V������
		fwrite(&shop[S].risoku_rate,sizeof(int),1,fp);//�؋�����
		fwrite(&shop[S].risi_rate,sizeof(int),1,fp);//�������q
		fwrite(&shop[S].cost_b,sizeof(int),1,fp);//�R�X�g�␳
		fwrite(&shop[S].atk_b,sizeof(int),1,fp);//�U���̓{�[�i�X

		fwrite(&shop[S].kaicost_b,sizeof(int),1,fp);//�J���R�X�g�␳

		fwrite(&shop[S].bukimatu_b,sizeof(int),1,fp);//����Ղ�{�[�i�X
		fwrite(&shop[S].turumatu_b,sizeof(int),1,fp);//��͂��Ղ�{�[�i�X
		fwrite(&shop[S].tax_b,sizeof(int),1,fp);//�ŋ���

		fwrite(shop[S].hirameki_b,sizeof(int),WEP_T,fp);//�����ʑM���␳
		fwrite(&shop[S].hirameki_dayb,sizeof(int),1,fp);//�����ʑM���␳

		fwrite(&shop[S].kaizen_week,sizeof(int),1,fp);

		fwrite(shop[S].ken_b,sizeof(int),KEN_T,fp);//�����o���␳

		fwrite(&shop[S].dur_b,sizeof(int),1,fp);

		fwrite(&shop[S].otona_b,sizeof(int),1,fp);//��l�����␳

		fwrite(shop[S].ninki_b,sizeof(int),NIN_T,fp);//�W�q�␳�A������

		fwrite(&shop[S].koukan_down,sizeof(int),1,fp);

		fwrite(&shop[S].saitei_koukan,sizeof(int),1,fp);//�D���x�Œ�l

		fwrite(&shop[S].jisyoku_b,sizeof(int),1,fp);//���E�m���␳

		fwrite(&shop[S].eve_efe,sizeof(int),1,fp);//�C�x���g�ɂ��������
		fwrite(&shop[S].eve_turn,sizeof(int),1,fp);//������ʎc�莞��

		fwrite(&shop[S].medama_max,sizeof(int),1,fp);
		fwrite(shop[S].wep_medama,sizeof(int),7,fp);

		fwrite(&shop[S].g_cust,sizeof(int),1,fp);
		fwrite(&shop[S].g_sell_t,sizeof(int),1,fp);
		fwrite(shop[S].g_sell,sizeof(int),4,fp);
		fwrite(&shop[S].g_cust,sizeof(int),1,fp);
		fwrite(&shop[S].g_taikai,sizeof(int),1,fp);
		fwrite(&shop[S].g_boss,sizeof(int),1,fp);
		
		fwrite(shop[S].wep_sb,sizeof(int),12,fp);

		fwrite(&shop[S].kyuubo,sizeof(int),1,fp);

		fwrite(shop[S].ai_like, sizeof(int), 5, fp);
	}
	//����������������������������������������������������������������������������
	//�J����
	for(int E=0;E<EMP_M;E++){
		fwrite(&emp[E].name_no	,sizeof(int),1,fp);
		fwrite(&emp[E].shop_n	,sizeof(int),1,fp);//�z���X�A���E�X
		fwrite(emp[E].shop_like	,sizeof(int),SHOP_M,fp);//�D���x
		fwrite(&emp[E].now_job	,sizeof(int),1,fp);//���ݏ� 0���E 1�A�E 2���� 3�j�[�g
		fwrite(emp[E].mensetu	,sizeof(int),SHOP_M*5,fp);//�ʐڏ�
		fwrite(emp[E].req_jinji	,sizeof(int),5,fp);
		fwrite(&emp[E].job		,sizeof(int),1,fp);//�E��
		fwrite(&emp[E].shift	,sizeof(int),1,fp);//�V�t�g
		fwrite(&emp[E].shift_n	,sizeof(int),1,fp);//�V�t�g�ύX
		fwrite(&emp[E].sun		,sizeof(double),1,fp);
		fwrite(&emp[E].lv		,sizeof(int),1,fp);//���x��
		fwrite(&emp[E].req_turn	,sizeof(int),1,fp);//�o���^�[��
		fwrite(&emp[E].exp		,sizeof(int),1,fp);//�o���l
		fwrite(&emp[E].hp		,sizeof(double),1,fp);//�c��HP
		fwrite(&emp[E].tension	,sizeof(int),1,fp);//���C
		fwrite(&emp[E].b_w		,sizeof(double),1,fp);//�u���b�N�x
		fwrite(&emp[E].konjyou	,sizeof(int),1,fp);//�����A��߂ɂ���
		fwrite(&emp[E].konjyou_k,sizeof(int),1,fp);//�����A��߂ɂ���
		fwrite(&emp[E].rest		,sizeof(int),1,fp);//����A���׊���
		fwrite(&emp[E].pay_money,sizeof(int),1,fp);//���ݒ���
		fwrite(&emp[E].req_money,sizeof(int),1,fp);//�v������
		fwrite(&emp[E].req_money_h,sizeof(int),1,fp);//�v������
		fwrite(&emp[E].chan_tai	,sizeof(int),1,fp);//�ҋ��ύX 0���̂܂܁@-1���� 1�`����
		fwrite(emp[E].st		,sizeof(int),3,fp);//�X�e�[�^�X
		fwrite(emp[E].st_st		,sizeof(int),3,fp);//�X�e�[�^�X
		fwrite(emp[E].st_up		,sizeof(int),3,fp);//�X�e�[�^�X
		fwrite(&emp[E].skill	,sizeof(int),1,fp);//�X�L��
		fwrite(&emp[E].grow_t	,sizeof(int),1,fp);//�����^�C�v
		fwrite(&emp[E].wait		,sizeof(int),1,fp);//�ҋ@����
		fwrite(&emp[E].kinzoku	,sizeof(int),1,fp);//�ŏ��Ɍق�����
		fwrite(&emp[E].sell_now	,sizeof(int),1,fp);//�������������z
		fwrite(&emp[E].eve_flag	,sizeof(int),1,fp);//�挎���������z
		fwrite(&emp[E].work_cnt	,sizeof(int),1,fp);//�挎���������z
		fwrite(&emp[E].pb_count	,sizeof(int),1,fp);//�挎���������z
		fwrite(&emp[E].pb_rest	,sizeof(int),1,fp);//�挎���������z
		fwrite(&emp[E].intai	,sizeof(int),1,fp);
		fwrite(&emp[E].req_rate	,sizeof(int),1,fp);
	}
	//����������������������������������������������������������������������������
	//�_���W����
	for(int D=0;D<DUN_M;D++){
		fwrite(&dun[D].type		,sizeof(int),1,fp);//�_���W�����^�C�v//��A�R�A���A�X�A��A��
		fwrite(&dun[D].boss_t	,sizeof(int),1,fp);//�{�X�^�C�v
		fwrite(&dun[D].boss_max	,sizeof(int),1,fp);//�{�X�ő�̗�
		fwrite(&dun[D].boss_hp	,sizeof(int),1,fp);//�{�X�c��̗�
		fwrite(&dun[D].clear_f	,sizeof(int),1,fp);//������
		fwrite(dun[D].ene_t		,sizeof(int),8,fp);//�o���G��//���m���A�����푰���������X�g����
		fwrite(&dun[D].seek		,sizeof(int),1,fp);
		fwrite(dun[D].root_t	,sizeof(int),5,fp);
		fwrite(dun[D].root_p	,sizeof(int),5,fp);
		fwrite(dun[D].root_k	,sizeof(int),5,fp);
	}
	//����������������������������������������������������������������������������
	//���퉿�i
	for(int W=0 ; W<WEP_M ; W++ ){
		fwrite(&wep[W].price	,sizeof(int) , 1 , fp );
	}


	//�E�B���h�E�֘A
	fwrite(wind.x,sizeof(int),WIN_M,fp);
	fwrite(wind.y,sizeof(int),WIN_M,fp);//�E�B���h�E�ʒu
	fwrite(wind.sy,sizeof(int),WIN_M,fp);//�E�B���h�E�傫��
	fwrite(wind.smax,sizeof(int),WIN_M,fp);//�ő�x
	fwrite(wind.sf,sizeof(int),WIN_M,fp);//�T�C�Y�t���O
	fwrite(wind.scr,sizeof(int),WIN_M,fp);//�X�N���[����
	fwrite(wind.scr_on,sizeof(int),WIN_M,fp);
	fwrite(wind.scrm,sizeof(int),WIN_M,fp);//�X�N���[���ő�l
	fwrite(wind.hide,sizeof(int),WIN_M,fp);//�d�Ȃ���
	fwrite(wind.on,sizeof(int),WIN_M,fp);//�\�����
	fwrite(wind.ok,sizeof(int),WIN_M,fp);//�\�����

	fwrite(&wind.wep_sort,sizeof(int),1,fp);//����\�[�g���

	fwrite(&wind.emp_hyouji,sizeof(int),1,fp);//�ٗp�\���^�C�v
	fwrite(&wind.req_hyouji,sizeof(int),1,fp);
	fwrite(&wind.mana_hyouji,sizeof(int),1,fp);
	fwrite(&wind.mana_rock,sizeof(int),1,fp);

	fwrite(&wind.syu_set,sizeof(int),1,fp);//���ݕ\�����x
	fwrite(&wind.syu_now,sizeof(int),1,fp);//���ݕ\��
	fwrite(&wind.syu_year,sizeof(int),1,fp);
	fwrite(&wind.syu_mon,sizeof(int),1,fp);
	fwrite(&wind.syu_day,sizeof(int),1,fp);
	fwrite(wind.syu_hyouji,sizeof(int),13,fp);

	fwrite(wind.req_list,sizeof(int),EMP_M,fp);//���l���X�g
	fwrite(wind.kai_list,sizeof(int),WEP_M,fp);//�J�����X�g
	fwrite(wind.mana_list,sizeof(int),MANA_M,fp);//�}�l�W���X�g

	fwrite(&wind.req_m,sizeof(int),1,fp);
	fwrite(&wind.kai_m,sizeof(int),1,fp);
	fwrite(&wind.mana_m,sizeof(int),1,fp);

	//����������������������������������������������������������������������������
	//����E�B���h�E
	fwrite(wind.wfold_h,sizeof(int),7,fp);//�t�H���_����
	fwrite(wind.wfold_cnt,sizeof(int),7,fp);//�t�H���_����
	fwrite(wind.wfold_list,sizeof(int),7*WEP_M,fp);//
	//����������������������������������������������������������������������������
	//�l���E�B���h�E
	fwrite(wind.efold_h,sizeof(int),WEP_M+4,fp);//�t�H���_����
	fwrite(wind.efold_cnt,sizeof(int),WEP_M+4,fp);//�t�H���_����
	fwrite(wind.efold_mem,sizeof(int),(WEP_M+4)*100,fp);//�l
	fwrite(wind.efold_s,sizeof(int),WEP_M,fp);//�t�H���_����
	fwrite(wind.tfold_h,sizeof(int),20,fp);//�ҋ��t�H���_
	fwrite(wind.tfold_cnt,sizeof(int),20,fp);//�t�H���_����
	fwrite(wind.tfold_mem,sizeof(int),2000,fp);//�l
	//����������������������������������������������������������������������������
	//���O
	fwrite(&logu.cnt,sizeof(int),1,fp);//���݃��O��
	fwrite(&logu.mode,sizeof(int),1,fp);//���݃��O��

	for(int I=0;I<logu.cnt;I++){
		fwrite(&logu.log[I].type,sizeof(int),1,fp);//���O�F�����e
		fwrite(&logu.log[I].shop,sizeof(int),1,fp);//���O�F�����e
		fwrite(&logu.log[I].date,sizeof(int),1,fp);//���O�F�����e
		fwrite(logu.log[I].str,sizeof(char),64,fp);//���O�F�����e
	}

	//����������������������������������������������������������������������������
	//�C�x���g���
	for(int E=0;E < EVE_M;E++){
		fwrite(&eve[E].turn_req,sizeof(int),1,fp);//��������
	}
	fclose(fp);

	fun.sys_save();

	return 1;
}/*�f�[�^�̕ۑ�*/
int FUN::data_load(int N){

	if( data.new_load == 0) return -1;

	FILE *fp;
	errno_t err;

	std::string name;

	SetCurrentDirectory(data.szDir);

	name = "File/save/" + rabel.list[N].name;

	if( (err = fopen_s( &fp, name.c_str(), "rb" )) !=0 ) return -1;
	//����������������������������������������������������������������������������
	//��{�f�[�^
	fread(&data.play,sizeof(int),1,fp);//�v���C���[����
	fread(&data.nando,sizeof(int),1,fp);//��Փx
	fread(&data.mode,sizeof(int),1,fp);//�Q�[�����[�h
	fread(&data.day,sizeof(int),1,fp);//���t
	fread(&data.play_time,sizeof(int),1,fp);//���v���C����
	fread(&data.game_over,sizeof(int),1,fp);//���v���C����
	fread(&data.ver,sizeof(int),1,fp);//�o�[�W����

	//�����܂Ńw�b�_�[
	fread(&data.mon,sizeof(int),1,fp);//���t
	fread(&data.time,sizeof(int),1,fp);//����
	fread(&data.tenki,sizeof(int),1,fp);//�V�C

	fread(&data.jinkou,sizeof(int),1,fp);//�l��
	fread(&data.jinkou_max,sizeof(int),1,fp);//�l��
	fread(&data.jinkou_up,sizeof(int),1,fp);
	fread(&data.total_des,sizeof(int),1,fp);//������
	fread(data.des_mon,sizeof(int),MANTH_M,fp);//���Ҍ���
	fread(data.jinkou_mon,sizeof(int),MANTH_M,fp);//�l������

	fread(&data.shop_cnt,sizeof(int),1,fp);

	fread(data.eve_flag,sizeof(int),EVE_M,fp);//�C�x���g�p�t���O

	fread(&data.creame_rate,sizeof(int),1,fp);
	fread(&data.kairyou_rate,sizeof(int),1,fp);
	fread(&data.hirameki_rate,sizeof(int),1,fp);

	fread(&data.taiguu_ok,sizeof(int),1,fp);
	fread(data.taikai,sizeof(int),2,fp);

	fread(&data.boom,sizeof(int),1,fp);
	fread(&data.boom_rest,sizeof(int),1,fp);

	fread(&data.kami_ikari,sizeof(int),1,fp);//�_�̓{��c�����

	fread(data.kabu_cnt,sizeof(int),5,fp);
	fread(data.kabu_price,sizeof(double),5,fp);
	fread(data.wep_ganso,sizeof(int),WEP_M,fp);

	fread(&data.goal_cust  ,sizeof(int),1,fp);
	fread(&data.goal_kabu  ,sizeof(int),1,fp);
	fread(&data.goal_sell_t,sizeof(int),1,fp);
	fread(data.goal_sell   ,sizeof(int),4,fp);
	fread(&data.goal_turu  ,sizeof(int),1,fp);
	fread(&data.goal_wepcre,sizeof(int),1,fp);
	fread(&data.goal_money ,sizeof(int),1,fp);
	fread(&data.goal_taikai,sizeof(int),1,fp);
	fread(&data.goal_boss  ,sizeof(int),1,fp);
	
	fread(&data.exp_rate	,sizeof(int),1,fp);
	fread(data.req_act		,sizeof(int),12,fp);

	//����������������������������������������������������������������������������
	//�`���ҏ��
	for(int H=0;H<data.jinkou_max;H++){
		fread(&hun[H].life,sizeof(int),1,fp);//������
		fread(&hun[H].lv,sizeof(int),1,fp);//���x��
		fread(&hun[H].exp,sizeof(int),1,fp);//�o���l
		fread(&hun[H].job,sizeof(int),1,fp);//�E��
		fread(hun[H].sta,sizeof(int),4,fp);//�X�e�[�^�X
		fread(&hun[H].hp,sizeof(int),1,fp);//����HP
		fread(&hun[H].skill,sizeof(int),1,fp);//���Z
		fread(&hun[H].wep_t,sizeof(int),1,fp);//������
		fread(&hun[H].rank,sizeof(int),1,fp);//�W���u�����N
		fread(&hun[H].dun_lv,sizeof(int),1,fp);//�_���W�������x��

		fread(&hun[H].money,sizeof(int),1,fp);//���ݎ���
		fread(&hun[H].wep_c,sizeof(int),1,fp);//���폊����
		fread(hun[H].wep_a,sizeof(double),8,fp);//����U��
		fread(hun[H].wep_d,sizeof(int),8,fp);//����ϋv
		fread(hun[H].wep_s,sizeof(int),8,fp);//����ϋv
		fread(hun[H].shop_wepn,sizeof(int),SHOP_M,fp);//�X�i�����m��
		fread(hun[H].shop_koukan,sizeof(int),SHOP_M,fp);//�X�D���x
		fread(hun[H].senden_boost,sizeof(int),SHOP_M,fp);//�X�D���x
		fread(hun[H].like_t,sizeof(int),3,fp);//�����A�������悳�A�����̉e���x
		//�s�����
		fread(&hun[H].act,sizeof(int),1,fp);//�s�����//�ҋ@�A�X���A
		fread(&hun[H].act_no,sizeof(int),1,fp);//�X�ԍ��A�_���W�����ԍ�
		fread(&hun[H].b_w,sizeof(int),1,fp);//�u���b�N�x//����,�������A�X�g���X�Ⴂ
		fread(&hun[H].stress,sizeof(int),1,fp);//��������
		fread(&hun[H].wait,sizeof(int),1,fp);//�ҋ@����
		fread(&hun[H].talk_max,sizeof(int),1,fp);//�Q�[�W�ő�
		fread(&hun[H].talk_emp,sizeof(int),1,fp);//���ݑΉ����Ă���X��
		fread(&hun[H].x,sizeof(int),1,fp);
		fread(&hun[H].y,sizeof(int),1,fp);
		fread(&hun[H].vx,sizeof(int),1,fp);
		fread(hun[H].p_card,sizeof(int),SHOP_M,fp);
	}
	//����������������������������������������������������������������������������
	//���R�[�h
	for(int S=0;S<SHOP_M;S++){
		int D = data.day+1;
		int M = data.day/28+1;
		fread(shop[S].sellc_day,sizeof(int),D,fp);//�̔���
		fread(shop[S].sell_day,sizeof(int),D,fp);//����グ
		fread(shop[S].cust_day,sizeof(int),D*4,fp);//�q��
		fread(shop[S].seizc_day,sizeof(int),D,fp);//������
		fread(shop[S].seiz_day,sizeof(int),D,fp);//������
		fread(shop[S].shera_wepd,sizeof(int),D*4,fp);//�e����̔̔��V�F�A
		
		fread(shop[S].sellc_mon,sizeof(int),M,fp);//�̔���
		fread(shop[S].sell_mon,sizeof(int),M,fp);//����グ
		fread(shop[S].cust_mon,sizeof(int),M,fp);//�q��
		fread(shop[S].seizc_mon,sizeof(int),M,fp);//������
		fread(shop[S].seiz_mon,sizeof(int),M,fp);//������

		fread(shop[S].emp_mon,sizeof(int),M,fp);//�ٗp��//�����Ɍv�Z
		fread(shop[S].manege_mon,sizeof(int),M,fp);//�o�c��p��p
		fread(shop[S].etc_mon,sizeof(int),M,fp);//��,���q�����Ɍv�Z
		fread(shop[S].incom_mon,sizeof(int),M,fp);//���v�����Ɍv�Z
		fread(shop[S].nougu_mon,sizeof(int),M,fp);//���v�����Ɍv�Z
		fread(shop[S].total_mon,sizeof(int),M,fp);//���Y//�����Ɍv�Z
		fread(shop[S].kabu_mon,sizeof(int),M,fp);
		fread(shop[S].shera_wepm,sizeof(int),M*4,fp);//�e����̔̔��V�F�A	
	}
	//����������������������������������������������������������������������������
	//�X
	for(int S=0;S<SHOP_M;S++){
		fread(&shop[S].emp_cnt,sizeof(int),1,fp);
		fread(&shop[S].emp_kou,sizeof(int),1,fp);
		fread(shop[S].emp_list,sizeof(int),EMP_M,fp);//�X�����X�g

		fread(&shop[S].money,sizeof(double),1,fp);//����
		fread(&shop[S].b_w,sizeof(double),1,fp);//�u���b�N�x
		fread(&shop[S].koubou_t,sizeof(int),1,fp);//�c�Ǝ���
		fread(&shop[S].koubou_n,sizeof(int),1,fp);

		fread(shop[S].create_get,sizeof(int),3,fp);//�J���o���l
		fread(shop[S].create_exp,sizeof(int),3,fp);//�J���o���l
		fread(shop[S].create_lv,sizeof(int),3,fp);//�J����

		fread(&shop[S].nougu_req,sizeof(int),1,fp);//�_�k���v��

		fread(shop[S].wep_rest,sizeof(int),WEP_M,fp);//�݌ɐ�
		fread(shop[S].wep_cre,sizeof(int),WEP_M,fp);//�J���� -1�J���s�� 0�J���\�@1�J������
		fread(shop[S].wep_hday,sizeof(int),WEP_M,fp);//�M���Ă���̓���
		fread(shop[S].wep_make,sizeof(int),WEP_M,fp);//�J�������Y�i�s�x
		fread(shop[S].wep_kaicnt,sizeof(int),WEP_M,fp);//�J���E���ǐi�s�x
		fread(shop[S].wep_kaiexp,sizeof(int),WEP_M,fp);//
		fread(shop[S].wep_make_t,sizeof(int),WEP_M,fp);//�����Y��

		fread(shop[S].ninki_kai,sizeof(int),WEP_M,fp);//�l�C
		fread(shop[S].atk_kai,sizeof(int),WEP_M,fp);//�U��
		fread(shop[S].dur_kai,sizeof(int),WEP_M,fp);//�ϋv
		fread(shop[S].cost_kai,sizeof(int),WEP_M,fp);//�R�X�g
		fread(shop[S].time_kai,sizeof(int),WEP_M,fp);//����

		fread(&shop[S].yasuuri,sizeof(int),1,fp);//��ي���
		fread(&shop[S].price_rate,sizeof(int),1,fp);//��ي���
		fread(&shop[S].yasuuri_efe,sizeof(double),1,fp);//��ي���

		fread(shop[S].bumon_lv,sizeof(int),5,fp);//����		MAX�` ��`�n��p�̌��ʂ��オ��A��`��p�M���\��

		fread(shop[S].bumon_exp,sizeof(int),5,fp);//����		MAX�` ��`�n��p�̌��ʂ��オ��A��`��p�M���\��

		fread(&shop[S].senden_b,sizeof(int),1,fp);//��`����		MAX�` ��`�n��p�̌��ʂ��オ��A��`��p�M���\��
		fread(&shop[S].mensetu_lv,sizeof(int),1,fp);//��`����		MAX�` ��`�n��p�̌��ʂ��オ��A��`��p�M���\��
	
		fread(&shop[S].total_saiyou,sizeof(int),1,fp);
		fread(&shop[S].total_yame,sizeof(int),1,fp);

		fread(&shop[S].lv_ave,sizeof(double),1,fp);
		fread(&shop[S].pay_ave,sizeof(double),1,fp);
		fread(&shop[S].mon_ave,sizeof(double),1,fp);
		fread(&shop[S].bw_bonus,sizeof(double),1,fp);

		fread(&shop[S].yasumi_max,sizeof(int),1,fp);//�x����		���̐��܂ŋx��ł���������
		fread(&shop[S].zangyou,sizeof(int),1,fp);//���o�c�Ǝ���	15������

		fread(shop[S].kabu_cnt,sizeof(int),5,fp);//�����		������ł̌��́A��[�łt�o
		fread(&shop[S].kabu_max,sizeof(int),1,fp);//�����		������ł̌��́A��[�łt�o
		fread(&shop[S].kabu_price,sizeof(double),1,fp);//�����		������ł̌��́A��[�łt�o
		fread(shop[S].kabu_rank,sizeof(int),5,fp);//�����		������ł̌��́A��[�łt�o

		fread(&shop[S].seizou_b,sizeof(int),1,fp);//�X������		�q�A�葬�x�ቺ
		fread(&shop[S].kairyou_b,sizeof(int),1,fp);//�X������		�q�A�葬�x�ቺ
		fread(&shop[S].tukare_b,sizeof(int),1,fp);//���l�r������
		fread(&shop[S].sekkyaku_b,sizeof(int),1,fp);//�X������		�q�A�葬�x�ቺ
		fread(&shop[S].kaihatu_b,sizeof(int),1,fp);//���l�r������
		fread(&shop[S].sabaki_b,sizeof(int),1,fp);//�X������		�q�A�葬�x�ቺ
		fread(&shop[S].stress_b,sizeof(int),1,fp);//���l�r������
		fread(&shop[S].yaruki_b,sizeof(int),1,fp);//�X������		�q�A�葬�x�ቺ
		fread(&shop[S].sinn_b,sizeof(int),1,fp);

		fread(&shop[S].size,sizeof(int),1,fp);
		fread(&shop[S].kouji,sizeof(int),1,fp);

		fread(&shop[S].souko_now,sizeof(int),1,fp);//�q�Ɍ���//���X���Ԃɉe��
		fread(&shop[S].souko_max,sizeof(int),1,fp);//�q�ɍő吔

		fread(&shop[S].tana_now,sizeof(int),1,fp);//�I���ݐ�//�W�q�͂ɉe��
		fread(shop[S].tana_now_t,sizeof(int),4,fp);//�e������

		fread(&shop[S].teikyuu,sizeof(int),1,fp);//��x���A�ő�P��
		fread(&shop[S].cust_cnt,sizeof(int),1,fp);//���q��
		fread(shop[S].cust_cnt_t,sizeof(int),4,fp);//�����ޖ��̗��q��
		fread(shop[S].cust_wep,sizeof(int),4,fp);//�����ޕʗ��q��
		fread(shop[S].cust_list,sizeof(int),SHOP_SP,fp);//���X�q���X�g
		fread(shop[S].cust_gold,sizeof(int),SHOP_SP,fp);//���X�q����S�[���h

		fread(&shop[S].p_mp,sizeof(double),1,fp);//�ő�}�l�W�����g�|�C���g
		fread(&shop[S].n_mp,sizeof(double),1,fp);//���݃}�l�W�����g�|�C���g
		fread(&shop[S].use_mana,sizeof(int),1,fp);//�J�z�}�l�W�����g�|�C���g
		fread(shop[S].mana_ok,sizeof(int),MANA_M,fp);//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��
		fread(shop[S].syou_mp,sizeof(int),MANA_M,fp);//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��
		fread(shop[S].syou_money,sizeof(int),MANA_M,fp);//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��
		fread(shop[S].mana_rest,sizeof(int),MANA_M,fp);//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��
		fread(shop[S].mana_cnt,sizeof(int),MANA_M,fp);//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��
		fread(shop[S].mana_day,sizeof(int),MANA_M,fp);//�o�c�헪�g�p�� -1�g�p�s�� 0�g�p�\�@1�g�p��

		fread(&shop[S].holiday,sizeof(int),1,fp);//�e����̔̔��V�F�A
		fread(&shop[S].timeido,sizeof(double),1,fp);

		fread(shop[S].mana_b,sizeof(int),MANA_T,fp);//��p�g�p�l�o�␳
		fread(shop[S].mana_gb,sizeof(int),MANA_T,fp);//��p�g�p�����␳

		fread(&shop[S].kaihuku_b,sizeof(int),1,fp);//�񕜕␳�A�V����
		fread(&shop[S].kaihuku_bs,sizeof(int),1,fp);//�񕜕␳�A�V����
		fread(&shop[S].exp_b,sizeof(int),1,fp);//�o���l�␳
		fread(&shop[S].exp_bs,sizeof(int),1,fp);//�o���l�␳�A�V����
		fread(&shop[S].monster_b,sizeof(int),1,fp);//�N���[�}�[�������␳
		fread(&shop[S].syakai_b,sizeof(int),1,fp);//�Љ�l�x�ω��{�[�i�X
		fread(&shop[S].hp_up_b,sizeof(int),1,fp);//HP������
		fread(&shop[S].sei_up_b,sizeof(int),1,fp);//����������
		fread(&shop[S].kai_up_b,sizeof(int),1,fp);//�J��������
		fread(&shop[S].kya_up_b,sizeof(int),1,fp);//�q�J������
		fread(&shop[S].sek_up_b,sizeof(int),1,fp);//�ڋq������

		fread(&shop[S].mp_ninnzuu,sizeof(int),1,fp);//�l���ɂ��l�o�񕜃{�[�i�X
	
		fread(&shop[S].sk_pup,sizeof(int),1,fp);//�X�L�������m��
		fread(&shop[S].sk_rup,sizeof(int),1,fp);//�X�L�����]�m��
		fread(&shop[S].sk_qup,sizeof(int),1,fp);//�H�X�L���ω��m��

		fread(&shop[S].kabu_buy,sizeof(int),1,fp);//�������
		fread(&shop[S].nougu_up,sizeof(int),1,fp);
		fread(&shop[S].kyuuryou_b,sizeof(int),1,fp);//�V������
		fread(&shop[S].risoku_rate,sizeof(int),1,fp);//�؋�����
		fread(&shop[S].risi_rate,sizeof(int),1,fp);//�������q
		fread(&shop[S].cost_b,sizeof(int),1,fp);//�R�X�g�␳
		fread(&shop[S].atk_b,sizeof(int),1,fp);//�U���̓{�[�i�X

		fread(&shop[S].kaicost_b,sizeof(int),1,fp);//�J���R�X�g�␳

		fread(&shop[S].bukimatu_b,sizeof(int),1,fp);//����Ղ�{�[�i�X
		fread(&shop[S].turumatu_b,sizeof(int),1,fp);//��͂��Ղ�{�[�i�X
		fread(&shop[S].tax_b,sizeof(int),1,fp);//�ŋ���

		fread(shop[S].hirameki_b,sizeof(int),WEP_T,fp);//�����ʑM���␳
		fread(&shop[S].hirameki_dayb,sizeof(int),1,fp);//�����ʑM���␳

		fread(&shop[S].kaizen_week,sizeof(int),1,fp);

		fread(shop[S].ken_b,sizeof(int),KEN_T,fp);//�����o���␳

		fread(&shop[S].dur_b,sizeof(int),1,fp);

		fread(&shop[S].otona_b,sizeof(int),1,fp);//��l�����␳

		fread(shop[S].ninki_b,sizeof(int),NIN_T,fp);//�W�q�␳�A������

		fread(&shop[S].koukan_down,sizeof(int),1,fp);

		fread(&shop[S].saitei_koukan,sizeof(int),1,fp);//�D���x�Œ�l

		fread(&shop[S].jisyoku_b,sizeof(int),1,fp);//���E�m���␳

		fread(&shop[S].eve_efe,sizeof(int),1,fp);//�C�x���g�ɂ��������
		fread(&shop[S].eve_turn,sizeof(int),1,fp);//������ʎc�莞��

		fread(&shop[S].medama_max,sizeof(int),1,fp);
		fread(shop[S].wep_medama,sizeof(int),7,fp);

		fread(&shop[S].g_cust,sizeof(int),1,fp);
		fread(&shop[S].g_sell_t,sizeof(int),1,fp);
		fread(shop[S].g_sell,sizeof(int),4,fp);
		fread(&shop[S].g_cust,sizeof(int),1,fp);
		fread(&shop[S].g_taikai,sizeof(int),1,fp);
		fread(&shop[S].g_boss,sizeof(int),1,fp);

		fread(shop[S].wep_sb,sizeof(int),12,fp);

		fread(&shop[S].kyuubo,sizeof(int),1,fp);

		fread(shop[S].ai_like, sizeof(int), 5, fp);
	}
	//����������������������������������������������������������������������������
	//�J����
	for(int E=0;E<EMP_M;E++){
		fread(&emp[E].name_no	,sizeof(int),1,fp);
		fread(&emp[E].shop_n	,sizeof(int),1,fp);//�z���X�A���E�X
		fread(emp[E].shop_like	,sizeof(int),SHOP_M,fp);//�D���x
		fread(&emp[E].now_job	,sizeof(int),1,fp);//���ݏ� 0���E 1�A�E 2���� 3�j�[�g
		fread(emp[E].mensetu	,sizeof(int),SHOP_M*5,fp);//�ʐڏ�
		fread(emp[E].req_jinji	,sizeof(int),5,fp);
		fread(&emp[E].job		,sizeof(int),1,fp);//�E��
		fread(&emp[E].shift		,sizeof(int),1,fp);//�V�t�g
		fread(&emp[E].shift_n	,sizeof(int),1,fp);//�V�t�g�ύX
		fread(&emp[E].sun		,sizeof(double),1,fp);
		fread(&emp[E].lv		,sizeof(int),1,fp);//���x��
		fread(&emp[E].req_turn	,sizeof(int),1,fp);//�o���^�[��
		fread(&emp[E].exp		,sizeof(int),1,fp);//�o���l
		fread(&emp[E].hp		,sizeof(double),1,fp);//�c��HP
		fread(&emp[E].tension	,sizeof(int),1,fp);//���C
		fread(&emp[E].b_w		,sizeof(double),1,fp);//�u���b�N�x
		fread(&emp[E].konjyou	,sizeof(int),1,fp);//�����A��߂ɂ���
		fread(&emp[E].konjyou_k ,sizeof(int),1,fp);//�����A��߂ɂ���
		fread(&emp[E].rest		,sizeof(int),1,fp);//����A���׊���
		fread(&emp[E].pay_money	,sizeof(int),1,fp);//���ݒ���
		fread(&emp[E].req_money	,sizeof(int),1,fp);//�v������
		fread(&emp[E].req_money_h,sizeof(int),1,fp);//�v������
		fread(&emp[E].chan_tai	,sizeof(int),1,fp);//�ҋ��ύX 0���̂܂܁@-1���� 1�`����
		fread(emp[E].st			,sizeof(int),3,fp);//�X�e�[�^�X
		fread(emp[E].st_st		,sizeof(int),3,fp);//�X�e�[�^�X
		fread(emp[E].st_up		,sizeof(int),3,fp);//�X�e�[�^�X
		fread(&emp[E].skill		,sizeof(int),1,fp);//�X�L��
		fread(&emp[E].grow_t	,sizeof(int),1,fp);//�����^�C�v
		fread(&emp[E].wait		,sizeof(int),1,fp);//�ҋ@����
		fread(&emp[E].kinzoku	,sizeof(int),1,fp);//�ŏ��Ɍق�����
		fread(&emp[E].sell_now	,sizeof(int),1,fp);//�������������z
		fread(&emp[E].eve_flag	,sizeof(int),1,fp);//�挎���������z
		fread(&emp[E].work_cnt	,sizeof(int),1,fp);//�挎���������z
		fread(&emp[E].pb_count	,sizeof(int),1,fp);//�挎���������z
		fread(&emp[E].pb_rest	,sizeof(int),1,fp);//�挎���������z
		fread(&emp[E].intai	,sizeof(int),1,fp);//���ފm��
		fread(&emp[E].req_rate	,sizeof(int),1,fp);
	}
	//����������������������������������������������������������������������������
	//�_���W����
	for(int D=0;D<DUN_M;D++){
		fread(&dun[D].type		,sizeof(int),1,fp);//�_���W�����^�C�v//��A�R�A���A�X�A��A��
		fread(&dun[D].boss_t	,sizeof(int),1,fp);//�{�X�^�C�v
		fread(&dun[D].boss_max	,sizeof(int),1,fp);//�{�X�ő�̗�
		fread(&dun[D].boss_hp	,sizeof(int),1,fp);//�{�X�c��̗�
		fread(&dun[D].clear_f	,sizeof(int),1,fp);//������
		fread(dun[D].ene_t		,sizeof(int),8,fp);//�o���G��//���m���A�����푰���������X�g����
		fread(&dun[D].seek		,sizeof(int),1,fp);
		fread(dun[D].root_t		,sizeof(int),5,fp);
		fread(dun[D].root_p		,sizeof(int),5,fp);
		fread(dun[D].root_k		,sizeof(int),5,fp);
	}
	//����������������������������������������������������������������������������
	//���퉿�i
	for(int W=0 ; W<WEP_M ; W++ ){
		fread(&wep[W].price	,sizeof(int) , 1 , fp );
	}

	//�E�B���h�E�֘A
	fread(wind.x,sizeof(int),WIN_M,fp);
	fread(wind.y,sizeof(int),WIN_M,fp);//�E�B���h�E�ʒu
	fread(wind.sy,sizeof(int),WIN_M,fp);//�E�B���h�E�傫��
	fread(wind.smax,sizeof(int),WIN_M,fp);//�ő�x
	fread(wind.sf,sizeof(int),WIN_M,fp);//�T�C�Y�t���O
	fread(wind.scr,sizeof(int),WIN_M,fp);//�X�N���[����
	fread(wind.scr_on,sizeof(int),WIN_M,fp);
	fread(wind.scrm,sizeof(int),WIN_M,fp);//�X�N���[���ő�l
	fread(wind.hide,sizeof(int),WIN_M,fp);//�d�Ȃ���
	fread(wind.on,sizeof(int),WIN_M,fp);//�\�����
	fread(wind.ok,sizeof(int),WIN_M,fp);//�\�����

	fread(&wind.wep_sort,sizeof(int),1,fp);//����\�[�g���

	fread(&wind.emp_hyouji,sizeof(int),1,fp);//�ٗp�\���^�C�v
	fread(&wind.req_hyouji,sizeof(int),1,fp);
	fread(&wind.mana_hyouji,sizeof(int),1,fp);
	fread(&wind.mana_rock,sizeof(int),1,fp);

	fread(&wind.syu_set,sizeof(int),1,fp);//���ݕ\�����x
	fread(&wind.syu_now,sizeof(int),1,fp);//���ݕ\��
	fread(&wind.syu_year,sizeof(int),1,fp);
	fread(&wind.syu_mon,sizeof(int),1,fp);
	fread(&wind.syu_day,sizeof(int),1,fp);
	fread(wind.syu_hyouji,sizeof(int),13,fp);

	fread(wind.req_list,sizeof(int),EMP_M,fp);//���l���X�g
	fread(wind.kai_list,sizeof(int),WEP_M,fp);//�J�����X�g
	fread(wind.mana_list,sizeof(int),MANA_M,fp);//�}�l�W���X�g

	fread(&wind.req_m,sizeof(int),1,fp);
	fread(&wind.kai_m,sizeof(int),1,fp);
	fread(&wind.mana_m,sizeof(int),1,fp);
	//����������������������������������������������������������������������������
	//����E�B���h�E
	fread(wind.wfold_h,sizeof(int),7,fp);//�t�H���_����
	fread(wind.wfold_cnt,sizeof(int),7,fp);//�t�H���_����
	fread(wind.wfold_list,sizeof(int),7*WEP_M,fp);//
	//����������������������������������������������������������������������������
	//�l���E�B���h�E
	fread(wind.efold_h,sizeof(int),WEP_M+4,fp);//�t�H���_����
	fread(wind.efold_cnt,sizeof(int),WEP_M+4,fp);//�t�H���_����
	fread(wind.efold_mem,sizeof(int),(WEP_M+4)*100,fp);//�l
	fread(wind.efold_s,sizeof(int),WEP_M,fp);//�t�H���_����
	fread(wind.tfold_h,sizeof(int),20,fp);//�ҋ��t�H���_
	fread(wind.tfold_cnt,sizeof(int),20,fp);//�t�H���_����
	fread(wind.tfold_mem,sizeof(int),2000,fp);//�l
	//����������������������������������������������������������������������������
	//���O
	fread(&logu.cnt,sizeof(int),1,fp);//���݃��O��
	fread(&logu.mode,sizeof(int),1,fp);//���݃��O��

	logu.log.reserve(logu.cnt);//�z��m��

	for(int I=0;I<logu.cnt;I++){
		logu.log.push_back(LOG::LOGG());
		fread(&logu.log[I].type,sizeof(int),1,fp);//���O�F�����e
		fread(&logu.log[I].shop,sizeof(int),1,fp);//���O�F�����e
		fread(&logu.log[I].date,sizeof(int),1,fp);//���O�F�����e
		fread(&logu.log[I].str,sizeof(logu.log[I].str),1,fp);//���O�F�����e
	}

	//����������������������������������������������������������������������������
	//�C�x���g���
	for(int E=0;E < EVE_M;E++){
		fread(&eve[E].turn_req,sizeof(int),1,fp);//��������
	}
	fclose(fp);

	return 0;
}/*�f�[�^�̓ǂݍ���*/
int FUN::sys_save(){

	FILE *fp;
	errno_t err;
	
	std::string name;

	SetCurrentDirectory(data.szDir);
	name = "File/save/system.sys";

	if( (err = fopen_s( &fp, name.c_str(), "wb" )) !=0 ) return -1;

	fwrite(sys.help_flag,sizeof(int),100,fp);//�t�H���_����
	fwrite(&sys.clear,sizeof(int),1,fp);
	fwrite(&sys.pass_on,sizeof(int),1,fp);

	fwrite(sys.medal_cnt,sizeof(int),100,fp);
	//
	fwrite(&sys.total_sell,sizeof(int),1,fp);//�̔�����
	fwrite(&sys.total_cust,sizeof(int),1,fp);//�����q��

	fwrite(sys.total_sellc,sizeof(int),4,fp);//������グ�A�����ʁ�
	fwrite(&sys.total_make,sizeof(int),1,fp);//����������
	fwrite(&sys.total_makec,sizeof(int),1,fp);//�������R�X�g��
	fwrite(&sys.total_kyuuryou,sizeof(int),1,fp);//���v������
	fwrite(&sys.total_matokku,sizeof(int),1,fp);//����͂���
	fwrite(&sys.total_kaihatu,sizeof(int),1,fp);//�J���񐔁�
	fwrite(&sys.total_senden,sizeof(int),1,fp);//��`��
	fwrite(&sys.total_day,sizeof(int),1,fp);//�o�c������
	fwrite(&sys.total_koyou,sizeof(int),1,fp);//�ٗp�񐔁�
	fwrite(&sys.total_kaiko,sizeof(int),1,fp);//���ى񐔁�
	fwrite(&sys.total_jisyoku,sizeof(int),1,fp);//���E�񐔁�
	fwrite(&sys.total_haijin,sizeof(int),1,fp);//�p�l���񐔁�

	fwrite(sys.score_record,sizeof(int),20*18,fp);

	fwrite(sys.mana_total,sizeof(int),300,fp);//��p�݌v�g�p
	fwrite(sys.wep_maxlv,sizeof(int),400,fp);//�ō����x��
	fwrite(sys.wep_maket,sizeof(int),400,fp);//������
	fwrite(sys.wep_cret,sizeof(int),400,fp);//�J����
	
	fwrite(&sys.nanndo_flag,sizeof(int),1,fp);//
	fwrite(sys.play_flag,sizeof(bool),18,fp);//
	fwrite(sys.win_cnt,sizeof(int),14,fp);//

	//�R���t�B�O�l
	fwrite(&opt.window_x,sizeof(int),1,fp);//�𑜓x
	fwrite(&opt.window_y,sizeof(int),1,fp);	
	fwrite(&opt.bgm_size ,sizeof(int),1,fp);//����
	fwrite(&opt.wev_size ,sizeof(int),1,fp);
	fwrite(&opt.full_scr ,sizeof(int),1,fp);//�t���X�N���[��	
	fwrite(&opt.v_ram    ,sizeof(int),1,fp);//V����
	fwrite(&opt.speed_max,sizeof(int),1,fp);//�Q�[���X�s�[�h

	if(data.window_x / 4 == data.window_y /3) data.wide = 0;
	else									  data.wide = 1;

	fclose(fp);
	return 1;

}
int FUN::sys_load(){

	FILE *fp;
	errno_t err;
	
	std::string name;
	SetCurrentDirectory(data.szDir);

	name = "File/save/system.sys";

	if( (err = fopen_s( &fp, name.c_str(), "rb" )) !=0 ){
		opt.window_x = 1024;
		opt.window_y = 768;
		opt.bgm_size = 50;
		opt.wev_size = 50;
		opt.full_scr = 0;
		opt.v_ram    = 0;
		opt.speed_max= 32;
		SetVolumeMusic( opt.bgm_size*opt.bgm_size*256/10000 ) ;
		return -1;
	}

	fread(sys.help_flag,sizeof(int),100,fp);//�t�H���_����
	fread(&sys.clear,sizeof(int),1,fp);
	fread(&sys.pass_on,sizeof(int),1,fp);

	fread(sys.medal_cnt,sizeof(int),100,fp);
	//
	fread(&sys.total_sell,sizeof(int),1,fp);//�̔�����
	fread(&sys.total_cust,sizeof(int),1,fp);//�����q��

	fread(sys.total_sellc,sizeof(int),4,fp);//������グ�A�����ʁ�
	fread(&sys.total_make,sizeof(int),1,fp);//����������
	fread(&sys.total_makec,sizeof(int),1,fp);//�������R�X�g��
	fread(&sys.total_kyuuryou,sizeof(int),1,fp);//���v������
	fread(&sys.total_matokku,sizeof(int),1,fp);//����͂���
	fread(&sys.total_kaihatu,sizeof(int),1,fp);//�J���񐔁�
	fread(&sys.total_senden,sizeof(int),1,fp);//��`��
	fread(&sys.total_day,sizeof(int),1,fp);//�o�c������
	fread(&sys.total_koyou,sizeof(int),1,fp);//�ٗp�񐔁�
	fread(&sys.total_kaiko,sizeof(int),1,fp);//���ى񐔁�
	fread(&sys.total_jisyoku,sizeof(int),1,fp);//���E�񐔁�
	fread(&sys.total_haijin,sizeof(int),1,fp);//�p�l���񐔁�

	fread(sys.score_record,sizeof(int),20*18,fp);

	fread(sys.mana_total,sizeof(int),300,fp);//��p�݌v�g�p
	fread(sys.wep_maxlv,sizeof(int),400,fp);//�ō����x��
	fread(sys.wep_maket,sizeof(int),400,fp);//������
	fread(sys.wep_cret,sizeof(int),400,fp);//�J����

	fread(&sys.nanndo_flag,sizeof(int),1,fp);//
	fread(sys.play_flag,sizeof(bool),18,fp);//
	fread(sys.win_cnt,sizeof(int),14,fp);//

	//�R���t�B�O�l
	fread(&opt.window_x,sizeof(int),1,fp);//�𑜓x
	fread(&opt.window_y,sizeof(int),1,fp);	
	fread(&opt.bgm_size ,sizeof(int),1,fp);//����
	fread(&opt.wev_size ,sizeof(int),1,fp);
	fread(&opt.full_scr ,sizeof(int),1,fp);//�t���X�N���[��	
	fread(&opt.v_ram    ,sizeof(int),1,fp);//V����
	fread(&opt.speed_max,sizeof(int),1,fp);//�Q�[���X�s�[�h


	SetVolumeMusic( opt.bgm_size*opt.bgm_size*256/10000 ) ;

	fclose(fp);

	return 1;
}
int FUN::load_rabel(){

	HANDLE hSearch;
	WIN32_FIND_DATA fd;

	rabel.cnt = 0;

	SetCurrentDirectory(data.szDir);
	SetCurrentDirectory("File/save");

	hSearch = FindFirstFile( _T("*.dat"), &fd );

	if( hSearch == INVALID_HANDLE_VALUE )
	{
		return 0;//�t�@�C������
	}

	int CNT = 0;

	//�t�H���_�𒲂ׂāA���X�g���X�V
	while( TRUE ){

		rabel.list.reserve(CNT+1);
		rabel.list.push_back(SAVE_RABEL::DATA());

		rabel.list[CNT].name = fd.cFileName;

		CNT++;

		if( !FindNextFile( hSearch, &fd ) )
		{
			if( GetLastError() == ERROR_NO_MORE_FILES )
			{
				break;    // �񋓏I��
			}
			else
			{
				break;    // �G���[
			}
		}
	}
	
	rabel.cnt = CNT;

	std::string name;
	FILE *fp;
	errno_t err;

	
	for(int i=0;i<rabel.cnt;i++){
		name = rabel.list[i].name;

		if( (err = fopen_s( &fp, name.c_str(), "rb" )) == 0 ){
			fread(&rabel.list[i].shop,sizeof(int),1,fp);//�v���C���[����
			fread(&rabel.list[i].dif,sizeof(int),1,fp);//��Փx
			fread(&rabel.list[i].mode,sizeof(int),1,fp);//�Q�[�����[�h
			fread(&rabel.list[i].day,sizeof(int),1,fp);//���t
			fread(&rabel.list[i].time,sizeof(int),1,fp);//�v���C����
			fread(&rabel.list[i].game_over,sizeof(int),1,fp);//�N���A���
			fread(&rabel.list[i].ver,sizeof(int),1,fp);//�f�[�^�̃o�[�W����

			fclose(fp);
		}
	}
	//�f�B���N�g���߂�
	SetCurrentDirectory(data.szDir);

	return 1;
}
/*�����ݒ�̍쐬*/
int FUN::make_define(){

	shop[0].name = "�t�����e�B�A�X�~�X";
	shop[1].name = "�J�m������H�[";
	shop[2].name = "�z���C�g�i�C�g";
	shop[3].name = "�Ɍ����b��";
	shop[4].name = "�S�����m�X�E�F�|���Y";

	shop[0].color = GetColor(255,0,0);
	shop[1].color = GetColor(0,255,0);
	shop[2].color = GetColor(255,128,0);
	shop[3].color = GetColor(0,0,255);
	shop[4].color = GetColor(0,0,0);
	
	shop[0].icon = 106;
	shop[1].icon = 107;
	shop[2].icon = 108;
	shop[3].icon = 109;
	shop[4].icon = 110;

	data.win_name[0] = "���q���";data.win_name_s[0] = "���q";
	data.win_name[1] = "������";data.win_name_s[1] = "����";
	data.win_name[2] = "�X�ܕ��i";data.win_name_s[2] = "�X��";
	data.win_name[3] = "���l���";data.win_name_s[3] = "���l";
	data.win_name[4] = "�X�����";data.win_name_s[4] = "�X��";
	data.win_name[5] = "�E�l���";data.win_name_s[5] = "�E�l";
	data.win_name[6] = "��Џ��";data.win_name_s[6] = "���";
	data.win_name[7] = "�o�c���O";data.win_name_s[7] = "���O";
	data.win_name[8] = "���x���";data.win_name_s[8] = "���x";
	data.win_name[9] = "�o�c�헪";data.win_name_s[9] = "�o�c";
	data.win_name[10] = "�o�c�ڕW";data.win_name_s[10] = "�ڕW";
	data.win_name[11] = "�n�}�\��";data.win_name_s[11] = "�n�}";

	sprintf_s(data.week[0],"MON");
	sprintf_s(data.week[1],"TUE");
	sprintf_s(data.week[2],"WED");
	sprintf_s(data.week[3],"THU");
	sprintf_s(data.week[4],"FRI");
	sprintf_s(data.week[5],"STA");
	sprintf_s(data.week[6],"SUN");
	sprintf_s(data.week[7],"NON");

	sprintf_s(data.tainame[0],"�\�\");
	sprintf_s(data.tainame[1],"����");
	sprintf_s(data.tainame[2],"����");
	sprintf_s(data.tainame[3],"����");

	sprintf_s(data.skill_job[0],"�Ȃ�");
	sprintf_s(data.skill_info[0],"��������");

	sprintf_s(data.skill_job[1],"����");
	sprintf_s(data.skill_info[1],"��{�񕜗�1.2�{");

	sprintf_s(data.skill_job[2],"������");
	sprintf_s(data.skill_info[2],"��{�񕜗�1.5�{");
	
	sprintf_s(data.skill_job[3],"�m�[�V�C");
	sprintf_s(data.skill_info[3],"�X�g���X�����܂�ɂ���");

	sprintf_s(data.skill_job[4],"�_�o��");
	sprintf_s(data.skill_info[4],"�X�g���X�����܂�₷��");

	sprintf_s(data.skill_job[5],"�a��");
	sprintf_s(data.skill_info[5],"���ׂ����ɂȂ�₷��");

	sprintf_s(data.skill_job[6],"�s��");
	sprintf_s(data.skill_info[6],"���ׂ����ɂȂ�Ȃ�");

	sprintf_s(data.skill_job[7],"���C��");
	sprintf_s(data.skill_info[7],"���C���オ��₷��");

	sprintf_s(data.skill_job[8],"�T�{���");
	sprintf_s(data.skill_info[8],"���C���オ��ɂ���");

	sprintf_s(data.skill_job[9],"�t�@�C�g�ꔭ�I");
	sprintf_s(data.skill_info[9],"���C���ƂĂ��オ��₷��");

	sprintf_s(data.skill_job[10],"�V��");
	sprintf_s(data.skill_info[10],"LVUP�K�v�o��������");

	sprintf_s(data.skill_job[11],"�ǂ����q");
	sprintf_s(data.skill_info[11],"LVUP�K�v�o������{");

	sprintf_s(data.skill_job[12],"�J���X�}");
	sprintf_s(data.skill_info[12],"�X�e�[�^�X�㏸��������");

	sprintf_s(data.skill_job[13],"�}��");
	sprintf_s(data.skill_info[13],"�X�e�[�^�X�㏸�����Ⴂ");

	sprintf_s(data.skill_job[14],"�Ŕ�");
	sprintf_s(data.skill_info[14],"��`���ʂƖ��������オ��");

	sprintf_s(data.skill_job[15],"��������");
	sprintf_s(data.skill_info[15],"��ɔ̔����{�P");

	sprintf_s(data.skill_job[16],"���펫�T");
	sprintf_s(data.skill_info[16],"�S���O�̃}�C�i�X�␳����");

	sprintf_s(data.skill_job[17],"���n�b�s�[");
	sprintf_s(data.skill_info[17],"����̔���̍D���x�Q�{");

	sprintf_s(data.skill_job[18],"�X�}�C��");
	sprintf_s(data.skill_info[18],"�D���x�㏸1.5�{");

	sprintf_s(data.skill_job[19],"�����z");
	sprintf_s(data.skill_info[19],"�D���x�ω��Ȃ�");

	sprintf_s(data.skill_job[20],"�o�c�w");
	sprintf_s(data.skill_info[20],"�l�o�񕜁{0.2");

	sprintf_s(data.skill_job[21],"�挩�̖�");
	sprintf_s(data.skill_info[21],"�l�o�񕜁{0.5");
	
	sprintf_s(data.skill_job[22],"�������炸");
	sprintf_s(data.skill_info[22],"�����ɕ�������𔄂邱�Ƃ�����");

	sprintf_s(data.skill_job[23],"����������");
	sprintf_s(data.skill_info[23],"��ɂS�����ɕ���𔄂�");
	
	sprintf_s(data.skill_job[24],"�萯�p");
	sprintf_s(data.skill_info[24],"���E�҂̃X�e�[�^�X���������㏸");

	sprintf_s(data.skill_job[25],"���Ɩ�");
	sprintf_s(data.skill_info[25],"��`���ʂƖ��������オ��");

	sprintf_s(data.skill_job[26],"���~");
	sprintf_s(data.skill_info[26],"�����̗v���z���ʏ��荂��");

	sprintf_s(data.skill_job[27],"���~");
	sprintf_s(data.skill_info[27],"�����̗v���z���ʏ���Ⴂ");

	sprintf_s(data.skill_job[28],"���m");
	sprintf_s(data.skill_info[28],"�����o��1.2�{");

	sprintf_s(data.skill_job[29],"�����m");
	sprintf_s(data.skill_info[29],"�����o���l1.5�{");

	sprintf_s(data.skill_job[30],"���d��");
	sprintf_s(data.skill_info[30],"�J�����x2.0�{�A�M���m��1.2�{");

	sprintf_s(data.skill_job[31],"������");
	sprintf_s(data.skill_info[31],"�J�����x3.0�{�A�M���m��1.5�{");

	sprintf_s(data.skill_job[32],"�Ȃ�");
	sprintf_s(data.skill_info[32],"��������");

	sprintf_s(data.skill_job[33],"�J�C�[����");
	sprintf_s(data.skill_info[33],"���ǌo��2.0�{");

	sprintf_s(data.skill_job[34],"�C�m�x�[�^�[");
	sprintf_s(data.skill_info[34],"���ǌo��3.0�{");

	sprintf_s(data.skill_job[35],"�V�׋S");
	sprintf_s(data.skill_info[35],"���ǌo��-1.0�{");

	sprintf_s(data.skill_vs[0],"���");
	sprintf_s(data.skill_vs[1],"��s");
	sprintf_s(data.skill_vs[2],"����");
	sprintf_s(data.skill_vs[3],"�S��");
	sprintf_s(data.skill_vs[4],"�ɑ�");
	sprintf_s(data.skill_vs[5],"����");
	sprintf_s(data.skill_vs[6],"�ҍU");
	sprintf_s(data.skill_vs[7],"�A��");
	sprintf_s(data.skill_vs[8],"�ђ�");
	sprintf_s(data.skill_vs[9],"���e");
	sprintf_s(data.skill_vs[10],"�K��");
	sprintf_s(data.skill_vs[11],"�Đ�");
	sprintf_s(data.skill_vs[12],"�ˌ�");
	sprintf_s(data.skill_vs[13],"��P");
	sprintf_s(data.skill_vs[14],"���");
	sprintf_s(data.skill_vs[15],"���e");
	sprintf_s(data.skill_vs[16],"���");
	sprintf_s(data.skill_vs[17],"�K�^");
	sprintf_s(data.skill_vs[18],"�V��");

	data.nanndo_n[0] = "NOT CLEARD";
	data.nanndo_n[1] = "Normal";
	data.nanndo_n[2] = "Hard";
	data.nanndo_n[3] = "Maniac";
	data.nanndo_n[4] = "Death March";

	data.mode_n[0] = "�����L�^";
	data.mode_n[1] = "�V�i���I";
	data.mode_n[2] = "���R�o��";//�t���[���[�h�A�ڕW���T��
	data.mode_n[3] = "���_���̉�";//���_�����ŋ���
	data.mode_n[4] = "�q����`";//�����ڕW
	data.mode_n[5] = "��q����";//�q���ڕW
	data.mode_n[6] = "������Ă�";//�����ڕW
	data.mode_n[7] = "�V�F�ANo1";//�̔��ڕW
	data.mode_n[8] = "��͂���D��";//��͂����ڕW
	data.mode_n[9] = "�J��őO��";//�P�X�̂݃{�X�U����
	data.mode_n[10] = "���o�̕�";//�J�m����-��͂�or��
	data.mode_n[11] = "���ɂ̑�";//�z���C�g�i�C�g-���D��or��
	data.mode_n[12] = "�����̌�";//����-�J��or��
	data.mode_n[13] = "�����̋|";//�S�����m�X-����or�|
	data.mode_n[14] = "�E�F�|���}�C�X�^�[";//�l�핐��ǂꂩ
	data.mode_n[15] = "�A�C�X�G�C�W";//���E�Ғ�����
	data.mode_n[16] = "�M������";//�M�������ƂĂ�����
	data.mode_n[17] = "��n���^�[����";//�n���^�[���ƂĂ�����
	data.mode_n[18] = "����̏I���";//�n���^�[�������Ȃ�

	for(int i=0;i<12;i++){
		wind.hide[i]=i;
		wind.x[i]=i*50;
		wind.y[i]=100+i*50;
		wind.sx[i]=300;
		wind.sy[i]=400;
		wind.scr[i]=0;
		wind.scrm[i]=600;//�ő�X�N���[��
		wind.smax[i]=1024;//�ő�
		wind.smini[i]=48;
		wind.scr_on[i]=1;
	}

	//��{�傫��
	wind.sx[0]=200;
	wind.sx[1]=350;
	wind.sx[3]=310;
	wind.sx[4]=350;
	wind.sx[5]=400;
	wind.sx[9]=415;
	//�ŏ��T�C�Y��
	wind.smini[0]=140;
	wind.smini[1]=110;
	wind.smini[3]=75;
	wind.smini[4]=110;
	wind.smini[5]=110;
	wind.smini[8]=86;
	wind.scrm[8]=510-38;
	wind.smax[8]=540;
	wind.smini[9]=76+38;

	wind.drag = -1;//�͂�ł��Ȃ�

	opt.speed_def = 1;
	Inp.d_no = -1;
	wind.info_taiguu = -1;

	//��p��{���ԃ����N���ɕ��ёւ���
	data.mana_max[0] = 50;
	data.mana_max[1] = 37;
	data.mana_max[2] = 26;
	data.mana_max[3] = 33;
	data.mana_max[4] = 36;

	int MI = 1;

	for(int MR=1;MR<=10;MR++){
		for(int i=1;i<=50;i++){
			if(mana[i].rank == MR){
				data.mana_index[MI] = i;
				MI++;
			}
		}
	}

	MI = 61;
	for(int MR=1;MR<=10;MR++){
		for(int i=61;i<=97;i++){
			if(mana[i].rank == MR){
				data.mana_index[MI] = i;
				MI++;
			}
		}
	}


	MI = 121;
	for(int MR=1;MR<=10;MR++){
		for(int i=121;i<=140;i++){
			if(mana[i].rank == MR){
				data.mana_index[MI] = i;
				MI++;
			}
		}
	}


	MI = 181;
	for(int MR=1;MR<=10;MR++){
		for(int i=181;i<=204;i++){
			if(mana[i].rank == MR){
				data.mana_index[MI] = i;
				MI++;
			}
		}
	}


	MI = 241;
	for(int MR=1;MR<=10;MR++){
		for(int i=241;i<=276;i++){
			if(mana[i].rank == MR){
				data.mana_index[MI] = i;
				MI++;
			}
		}
	}



	return 1;
}
int FUN::make_dungeon(){

	int r,j,c;

	for(int D = 0;D<DUN_M;D++){
		r = Rand(350 + D*3);
		c = Rand(2);
		if(D == 0 || D == 99) dun[D].type = 0;//��//�Ƃ肠������
		else if (D%10 == 0  ) dun[D].type = 7;//���
		else if(r < 150)	  dun[D].type = 1;//�X
		else if(r < 200)	  dun[D].type = 2;//���A
		else if(r < 250 + D)  dun[D].type = 4;//�R
		else if(r < 300 + D)  dun[D].type = 5;//�鋫(��)
		else if(r < 350 + D)  dun[D].type = 6;//��
		//�o���G�^�C�v
		for(j=0;j<8;j++){
			//�Ƃ肠����
			dun[D].ene_t[j] = Rand(11)*4 + c;
			if(D>Rand(1000)) dun[D].ene_t[j] = 10+c;
		}
		//�{�X�^�C�v,�o���G���烉���_��
		dun[D].boss_t = dun[D].ene_t[0]/4*4+3;
		dun[D].boss_hp = ene[dun[D].boss_t].st[0] * (100 + D*2);
		dun[D].boss_max = dun[D].boss_hp;
		//���[�g������
		dun[D].seek = -1;
		dun[D].root_t[0] = 0;
		dun[D].root_t[1] = 0;
		dun[D].root_t[2] = 0;
		dun[D].root_t[3] = 0;
		dun[D].root_t[4] = 0;
		dun[D].root[0] = 0;
		dun[D].root[1] = 0;
		dun[D].root[2] = 0;
		dun[D].root[3] = 0;
		dun[D].root[4] = 0;
		dun[D].clear_f = 0;
	}
	//��0��99
	//�X	200
	//���A  100
	//��	50 + LVP
	//��	LVP * 2
	//���LV10�̔{��

	//���_�Ƒ��_���W�����̂ݔ����ς�
	dun[0].boss_hp = 0;
	dun[0].seek = 100;//�����ς�
	dun[1].seek = 1;
	dun[0].root_t[0] = dun[0].root_k[0]-1;

	return 1;
}/*�_���W�����̍쐬*/
int FUN::make_hunter(int L,int J){
	int i,N;

	if(J==-1){
			J= Rand(99);
			if(J<17)		J = 0;//��A//17%
			else if(J<27)	J =16;//��B//10%
			else if(J<42)	J = 4;//��A//15%
			else if(J<53)	J =20;//��B//11%
			else if(J<68)	J = 8;//��A//15%
			else if(J<79)	J =24;//��B//11%
			else if(J<90)	J =12;//�|A//11%
			else 			J =28;//�|B//10%
	}
		
	for(N= 0;N<HUN_M;N++){
		if(hun[N].life <= 0)break;
	}

	if(N>=HUN_M ) return -1;

	//�`���҂̍쐬
	hun[N].life = 20;
	hun[N].act = 0;
	hun[N].wait = Rand(255);
	hun[N].act_no = 0;
	hun[N].exp = H_LV_UP * L;
	hun[N].lv = 0;
	hun[N].job = J;
	hun[N].skill = 0;
	hun[N].money = 200000+Rand(100000);
	hun[N].wep_a[0] = 300+Rand(200);
	hun[N].wep_a[1] = 300+Rand(200);
	hun[N].wep_a[2] = 300+Rand(200);
	hun[N].wep_a[3] = 300+Rand(200);
	hun[N].wep_d[0] = Rand(40)+20;
	hun[N].wep_d[1] = Rand(40)+20;
	hun[N].wep_d[2] = Rand(40)+20;
	hun[N].wep_d[3] = Rand(40)+20;
	hun[N].wep_s[0] = 0;
	hun[N].wep_s[1] = 0;
	hun[N].wep_s[2] = 0;
	hun[N].wep_s[3] = 0;
	hun[N].wep_c = Rand(3)+1;//����1~4��
	hun[N].dun_lv = 1;
	hun[N].sta[0] = jobs[J].st_st[0]*2;
	hun[N].sta[1] = jobs[J].st_st[1];
	hun[N].sta[2] = jobs[J].st_st[2];
	hun[N].sta[3] = jobs[J].st_st[3];
	hun[N].wep_t  = jobs[J].wep_t;
	hun[N].p_card[0] = 0;
	hun[N].p_card[1] = 0;
	hun[N].p_card[2] = 0;
	hun[N].p_card[3] = 0;
	hun[N].p_card[4] = 0;
	//����ƃu���b�N�x�̊֌W
	switch(hun[N].wep_t){
		case 0:hun[N].b_w= 30 + Rand(40);break;//��
		case 1:hun[N].b_w= Rand(60);break;//��
		case 2:hun[N].b_w= Rand(50)+50;break;//��
		case 3:hun[N].b_w= Rand(100);break;//�|
	}
	//�W�q�e���x
	hun[N].like_t[0] = 75 + Rand(50);//����
	hun[N].like_t[1] = Rand(200);//�������悳
	hun[N].like_t[2] = 200-hun[N].like_t[1];//����
	for(i=0;i<SHOP_M;i++){
		hun[N].shop_koukan[i] = 50+shop[i].sinn_b;//�����D���x
		hun[N].sinazoroe(i);
		hun[N].senden_boost[i] = 100;
		if(hun[N].shop_wepn[i]<100) hun[N].shop_wepn[i]=100;
	}

	hun[N].lv_up();//���x���㏸����

	data.jinkou++;

	if(N>data.jinkou_max) data.jinkou_max=N;

	return 1;
}/*�n���^�[�̍쐬*/
int FUN::make_tenin(){

	//������
	for(int i=0;i<EMP_M;i++){
		emp[i].st[0] =  emp[i].st_st[0];
		emp[i].st[1] =  emp[i].st_st[1];
		emp[i].st[2] =  emp[i].st_st[2];
		emp[i].now_job = 3;//���Q	
		emp[i].req_jinji[0] = Rand(100);
		emp[i].req_jinji[1] = Rand(100);
		emp[i].req_jinji[2] = Rand(100);
		emp[i].req_jinji[3] = Rand(100);
		emp[i].req_jinji[4] = Rand(100);
		emp[i].req_jinji[fun.Rand(4)] = 0;
		emp[i].exp = 0;
		emp[i].eve_flag = 0;
		emp[i].chan_tai = 0;
		emp[i].kinzoku = 0;
		for(int j=0;j<25;j++){
			emp[i].mensetu[j/5][j%5] = 0;
		}
		emp[i].pb_count = 0;
		emp[i].pb_rest = 0;
		emp[i].work_cnt = 0;
		emp[i].wait = 0;
		emp[i].rest = 0;
		emp[i].sell_now = 0;
		emp[i].shop_like[0] = 0;
		emp[i].shop_like[1] = 0;
		emp[i].shop_like[2] = 0;
		emp[i].shop_like[3] = 0;
		emp[i].shop_like[4] = 0;
		emp[i].sun = 0;
		emp[i].hp = 100;
		emp[i].tension = 100;
		emp[i].eve_flag = 0;
		emp[i].kinzoku  = 0;
		emp[i].now_job  = 3;
		emp[i].intai	= 0;
		emp[i].shop_n   = -1;
	}

	return 1;
}
int FUN::make_start(){
	//�j���[�Q�[������������	
	logu.cnt = 0;
	logu.log.clear();

	data.day  = -1;
	data.play_time = 0;
	data.hirameki_rate = 100;
	data.kairyou_rate  = 100;
	data.taiguu_ok = 0;
	data.boom = 0;
	data.boom_rest = 0;//�u�[���c�����
	data.kami_ikari = 0;

	data.jinkou_max = 0;
	data.jinkou = 0;

	data.game_over = -1;
	data.goal_cust = 0;//�ڕW���q��
	data.goal_kabu = 0;
	data.goal_sell_t = 0;
	data.goal_sell[0] = 0;
	data.goal_sell[1] = 0;
	data.goal_sell[2] = 0;
	data.goal_sell[3] = 0;
	data.goal_turu = 0;
	data.goal_wepcre = 0;
	data.goal_money = 0;
	data.goal_taikai = 0;
	data.goal_boss = 0;

	data.exp_rate = 100;
	data.st_rate = 100;

	for(int i = 0;i<HUN_M;i++){
		hun[i].life = 0;
	}

	//���ʍs����
	data.req_act[0] = 1300;
	data.req_act[1] = 1500;
	data.req_act[2] = 1700;
	data.req_act[3] = 1450;
	data.req_act[4] = 1300;
	data.req_act[5] = 1200;
	data.req_act[6] = 1150;
	data.req_act[7] = 1100;
	data.req_act[8] = 1050;
	data.req_act[9] = 1000;
	data.req_act[10] = 900;
	data.req_act[11] = 1100;

	for(int N=0;N<12;N++)wind.ok[N] = 1;//�E�B���h�E�J��

	for(int E = 0;E<EVE_M;E++) data.eve_flag[E] = 0;//�C�x���g�t���O������
	data.eve_flag[1] = 1;

	data.creame_rate = 100;

	for(int S = 0;S<5;S++){//����������
		data.kabu_cnt[S] = 500;
		data.kabu_price[S] = 10000;
	}

	for(int S = 0;S<SHOP_M;S++){
		shop[S].reset();
	}

	for(int i=0;i<7;i++){//�\�����X�g������
		wind.wfold_cnt[i]=0;
		wind.wfold_h[i]=40;
	}
	for(int i=0;i<WEP_M+4;i++){
		wind.efold_cnt[i]     = 0;
		wind.efold_h[i]     = 40;
	}
	for(int i=0;i<WEP_M;i++){
		wind.efold_s[i] = -1;
	}
	for(int i=0;i<20;i++){
		wind.tfold_cnt[i%10][i/10]=0;
		wind.tfold_h[i%10][i/10]=40;
	}

	fun.make_dungeon();//�_���W�����̍쐬

	wind.syu_now = 1;	

	//�X�g�[���[���[�h�ȊO�̓C�x���g�ω�
	if( data.mode != 0){
		for(int E=101;E<EMP_M;E++){
			if(emp[E].req_turn == 0) continue;
			emp[E].req_turn--;
			if(emp[E].req_turn == 0){
				emp[E].now_job = 0;
				emp[E].select_shop();
			}
		}
	}

	//��������
	for(int S=0;S<5;S++){
		shop[S].wep_cre[0] = 2;
		shop[S].wep_cre[100] = 2;
		shop[S].wep_cre[200] = 2;
		shop[S].wep_cre[300] = 2;
		shop[S].wep_cre[NOU_NO] = 2;
		shop[S].wep_rest[0] = 50;
		shop[S].wep_rest[100] = 50;
		shop[S].wep_rest[200] = 50;
		shop[S].wep_rest[300] = 50;
	}

	//���탊�X�g�ǉ�
	wind.efold_s[0] = 0;
	fun.list_pw(0);
	fun.list_pw(100);
	fun.list_pw(200);
	fun.list_pw(300);
	if(data.mode != 0)fun.list_pw(NOU_NO);

	for(int S=0;S<5;S++)
    {
		shop[S].money = 3000000;
	}

	data.creame_rate   = 80 + data.nando * 20;
	data.hirameki_rate = 150 - data.nando * 10;

	for(int S=0;S<5;S++)
	{
        if( S == P) continue;

        if(data.nando > 1)
        {
		    shop[S].ken_b[0] += data.nando * 6 - 3;
		    shop[S].ken_b[1] += data.nando * 6 - 3;
		    shop[S].ken_b[2] += data.nando * 6 - 3;
        }
		shop[S].kabu_price = 10000 + data.nando * 1000;
	}
   
	switch(data.mode)
	{
		case  0:mode00_set();break;
		case  1:mode01_set();break;
		case  2:mode02_set();break;
		case  3:mode03_set();break;
		case  4:mode04_set();break;
		case  5:mode05_set();break;
		case  6:mode06_set();break;
		case  7:mode07_set();break;
		case  8:mode08_set();break;
		case  9:mode09_set();break;
		case 10:mode10_set();break;
		case 11:mode11_set();break;
		case 12:mode12_set();break;
		case 13:mode13_set();break;
		case 14:mode14_set();break;
		case 15:mode15_set();break;
		case 16:mode16_set();break;
		case 17:mode17_set();break;
	}
     
    if(data.mode != 0)
    {
    	shop[P].money = 1000000 * (4 - data.nando);
        if(data.nando == 0)
        {
            shop[P].ken_b[0] += 5;
            shop[P].ken_b[1] += 5;
            shop[P].ken_b[2] += 5;
    	    shop[P].money = 5000000;
        }
    }

	//�n���^�[��������
	for(int i=0;i< data.jinkou_start;i++){
		make_hunter(1+Rand(2));
	}

	fun.wep_price( 1.0 - 0.05 * data.nando );

	data.goal_cust    *= data.nando + 1;//�ڕW���q��
	data.goal_kabu    += data.goal_kabu * data.nando / 5;
	data.goal_sell_t  *= data.nando + 1;
	data.goal_sell[0] *= data.nando + 1;
	data.goal_sell[1] *= data.nando + 1;
	data.goal_sell[2] *= data.nando + 1;
	data.goal_sell[3] *= data.nando + 1;
	data.goal_turu	  *= data.nando + 1;
	data.goal_wepcre  *= data.nando + 1;
	data.goal_money   *= data.nando + 1;
	data.goal_taikai  *= data.nando + 1;
	data.goal_boss	  *= data.nando + 1;

	for(int W=0;W<WEP_M;W++){
		data.wep_ganso[W] = -1;
	}

	data.wep_ganso[0]	= 5;
	data.wep_ganso[100] = 5;
	data.wep_ganso[200] = 5;
	data.wep_ganso[300] = 5;
	data.wep_ganso[NOU_NO] = 5;

	for(int i=0;i<EMP_M;i++){
		if(i==300) i++;
		if(i>100) emp[i].make();
		emp[i].lv_up();
		if(i>100 && emp[i].req_turn == 1){
			emp[i].now_job = 0;
			emp[i].shop_n = -1;
			emp[i].select_shop();
		}
	}

	//�݌ɐ��v�Z
	zaiko_cnt();
	work_day_s();
	for(int S=0;S<SHOP_M;S++) shop[S].cul_ave();//���σ��x���Ƃ��v�Z
	data.boom = data.boom;	

	for(int i=0;i<11;i++){
		wind.on[i] =0;
		wind.hide[i]=i;
		wind.x[i]=i*50;
		wind.y[i]=100+i*50;
		wind.sx[i]=300;
		wind.sy[i]=400;
		wind.scr[i]=0;
		wind.scrm[i]=600;//�ő�X�N���[��
		wind.smax[i]=1024;//�ő�
		wind.smini[i]=50;
		wind.scr_on[i]=1;
	}

	//��{�傫��
	wind.sx[0]=200;
	wind.sx[1]=350;
	wind.sx[3]=310;
	wind.sx[4]=350;
	wind.sx[5]=350;
	wind.sx[9]=315;
	wind.sx[10]=400;
	wind.sy[10]=400;
	//�ŏ��T�C�Y��
	wind.smini[0]=140;
	wind.smini[1]=110;
	wind.smini[3]=75;
	wind.smini[4]=110;
	wind.smini[5]=110;
	wind.smini[8]=86;
	wind.scrm[8]=510-38;
	wind.smax[8]=540;
	wind.smini[9]=76;
	wind.smini[10]=400;
	wind.smax[10]=400;

	wind.mana_hyouji = 5;

	wind.drag = -1;//�͂�ł��Ȃ�

	return 1;
}/*�����X�e�[�^�X�̑��*/
int FUN::mode00_set(){
	//�V�i���I���[�h
	//
	//�V�i���I�ɂ����ăQ�[�����i��
	data.play = 0;
	data.shop_cnt = 1;
	data.jinkou_up = 0;
	data.jinkou_start = 0;

	//�E�B���h�E����
	for(int N=0;N<12;N++)wind.ok[N] = 0;

	data.creame_rate   = 0;
	shop[0].money		 = 3000000;//����
	shop[1].money		 = 5000000;//����
	shop[2].money		 = 10000000;//����
	shop[3].money		 = 10000000;//����
	shop[4].money		 = 50000000;//����

	for(int i=0 ; i<5;i++) shop[i].nougu_req = 0;
	for(int i=0 ; i<5;i++) shop[0].bumon_lv[i] = 0;

	shop[0].wep_cre[NOU_NO] = -1;
	shop[0].wep_rest[0] = 0;
	shop[0].wep_rest[100] = 0;
	shop[0].wep_rest[200] = 0;
	shop[0].wep_rest[300] = 0;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[3].plus(0);

	emp[12].plus(1);
	emp[13].plus(1);
	emp[14].plus(1);
	emp[15].plus(1);
	emp[39].plus(1);
	emp[49].plus(1);

	emp[17].plus(2);
	emp[18].plus(2);
	emp[19].plus(2);
	emp[21].plus(2);
	emp[40].plus(2);
	emp[41].plus(2);
	emp[50].plus(2);
	emp[51].plus(2);
	
	emp[23].plus(3);
	emp[24].plus(3);
	emp[25].plus(3);
	emp[26].plus(3);
	emp[42].plus(3);
	emp[43].plus(3);
	emp[44].plus(3);
	emp[52].plus(3);
	emp[53].plus(3);
	emp[54].plus(3);

	emp[28].plus(4);
	emp[29].plus(4);
	emp[30].plus(4);
	emp[31].plus(4);

	//�C�x���g�X��
	for(int i=0;i<100;i++){
		emp[i].eve_flag = 1;
	}

	return 1;
}
int FUN::mode01_set(){
	//���R�o��
	data.play = 0;
	data.shop_cnt = 5;
	data.jinkou_up = 30;
	data.jinkou_start = 200;

	//��������
	data.goal_cust   = 5000;
	data.goal_kabu   = 100000000;
	data.goal_sell_t = 50000000;
	data.goal_turu   = 2000;
	data.goal_money  = 30000000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[2].plus(0);
	emp[3].plus(0);

	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode02_set(){
	//���_���̉�
	data.play = 0;
	data.shop_cnt = 5;
	data.jinkou_up = 30;
	data.jinkou_start = 200;

	//��������
	//�ǂꂩ����P��
	data.goal_sell[0] = 20000000;
	data.goal_sell[1] = 20000000;
	data.goal_sell[2] = 20000000;
	data.goal_sell[3] = 20000000;

	//�M�̓{�[�i�X������

	//�����]�ƈ�
	emp[1].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode03_set(){
	//�q����`
	data.play = 0;
	data.shop_cnt = 5;
	data.jinkou_up = 30;
	data.jinkou_start = 200;

	//��������-�������
	data.goal_money = 30000000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[6].plus(0);

	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode04_set(){
	//��q����
	data.play = 0;
	data.shop_cnt = 5;
	data.jinkou_up = 30;
	data.jinkou_start = 200;

	//��������
	data.goal_cust = 7000;
	
	//�����]�ƈ�
	emp[1].plus(0);
	emp[15].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode05_set(){
	//�����͗x��
	data.play = 0;
	data.shop_cnt = 5;
	data.jinkou_up = 30;
	data.jinkou_start = 200;

	//��������
	data.goal_kabu = 100000000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[14].plus(0);

	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode06_set(){
	//�V�F�A�m�n�P
	data.play = 0;
	data.shop_cnt = 5;
	data.jinkou_up = 30;
	data.jinkou_start = 200;

	//��������
	data.goal_sell_t = 60000000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[26].plus(0);

	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode07_set(){
	//��͂���D��
	data.play		  = 0;
	data.shop_cnt	  = 5;
	data.jinkou_up	  = 20 + data.nando*2;
	data.jinkou_start = 200 + data.nando*20;
	//��������
	data.goal_turu = 1000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode08_set(){
	//�J��őO��
	data.play		  = 0;
	data.shop_cnt	  = 1;
	data.jinkou_up	  = 15;
	data.jinkou_start = 70;
	//��������
	data.goal_boss = 30;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode09_set(){
	//���o�̕�
	data.play		  = 1;
	data.shop_cnt	  = 5;
	data.jinkou_up	  = 30;
	data.jinkou_start = 200;
	//��������
	data.goal_sell[2] = 20000000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode10_set(){
	//���ɂ̑�
	data.play		  = 2;
	data.shop_cnt	  = 5;
	data.jinkou_up	  = 30;
	data.jinkou_start = 200;
	//��������
	data.goal_sell[1] = 20000000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode11_set(){
	//�����̌�
	data.play		  = 3;
	data.shop_cnt	  = 5;
	data.jinkou_up	  = 30;
	data.jinkou_start = 200;
	//��������
	data.goal_sell[0] = 20000000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode12_set(){
	//�����̋|
	data.play		  = 4;
	data.shop_cnt	  = 5;
	data.jinkou_up	  = 30;
	data.jinkou_start = 200;
	//��������
	data.goal_sell[3] = 20000000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode13_set(){
	//�E�F�|���}�X�^�[
	data.play		  = 0;
	data.shop_cnt	  = 5;
	data.jinkou_up	  = 30;
	data.jinkou_start = 200;
	//��������
	data.goal_sell[0] = 20000000;
	data.goal_sell[1] = 20000000;
	data.goal_sell[2] = 20000000;
	data.goal_sell[3] = 20000000;
	data.goal_sell_t  = 60000000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode14_set(){
	//�A�C�X�G�C�W
	data.play		  = 0;
	data.shop_cnt	  = 5;
	data.jinkou_up	  = 20 - data.nando*2;
	data.jinkou_start = 200 - data.nando*20;
	//��������
	data.goal_money  = 20000000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode15_set(){
	//�M������
	data.play		  = 0;
	data.shop_cnt	  = 5;
	data.jinkou_up	  = 30;
	data.jinkou_start = 200;
	//��������
	data.goal_wepcre = 30;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);
	//���l�𑝂₷

	return 1;
}
int FUN::mode16_set(){
	//��n���^�[����
	data.play		  = 0;
	data.shop_cnt	  = 5;
	data.jinkou_up	  = 100 + data.nando*20;
	data.jinkou_start = 200 + data.nando*20;
	//��������
	data.goal_sell_t = 50000000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}
int FUN::mode17_set(){
	//�S�̂�Ƃ萢��
	//
	data.play		  = 0;
	data.shop_cnt	  = 5;
	data.jinkou_up	  = 0;
	data.jinkou_start = 1000;
	//��������
	data.goal_cust   = 5000;

	//�����]�ƈ�
	emp[1].plus(0);
	emp[13].plus(1);
	emp[17].plus(2);
	emp[23].plus(3);
	emp[28].plus(4);

	return 1;
}

int FUN::make_map(int R){
	//�}�b�v�̍쐬
	set_map( 0, 25,25);
	set_map( 1, 80,80);
	set_map( 2, 35,110);
	set_map( 3, 125,23);
	set_map( 4, 90,140);
	set_map( 5, 160,80);
	set_map( 6, 40,205);
	set_map( 7, 150,150);
	set_map( 8, 280,25);
	set_map( 9, 30,300);
	set_map(10, 210,200);

	set_map(11, 400,30);
	set_map(12, 40,400);
	set_map(13, 160,300);
	set_map(14, 340,190);
	set_map(15, 270,110);
	set_map(16, 275,280);
	set_map(17, 310,330);
	set_map(18, 100,350);
	set_map(19, 340,400);

	set_map(20, 107,430);
	set_map(21, 380,280);
	set_map(22, 380,434);
	set_map(23, 215,390);
	set_map(24, 425,200);
	set_map(25, 420,500);
	set_map(26, 467,261);
	set_map(27, 171,464);
	set_map(28, 280,450);
	set_map(29, 480,450);

	set_map(30, 440,350);
	set_map(31, 550,240);
	set_map(32, 550,325);
	set_map(33, 560,440);
	set_map(34, 100,540);
	set_map(35, 607,514);
	set_map(36, 220,515);
	set_map(37, 240,577);
	set_map(38, 287,620);
	set_map(39, 320,720);

	set_map(40, 674,211);
	set_map(41, 180,675);
	set_map(42, 721,434);
	set_map(43, 625,127);
	set_map(44, 741,153);
	set_map(45, 410,650);
	set_map(46, 513,565);
	set_map(47, 806,183);
	set_map(48, 684,92);
	set_map(49, 755,102);

	set_map(50, 630,310);
	set_map(51, 837,132);
	set_map(52, 523,644);
	set_map(53, 680,24);
	set_map(54, 760,40);
	set_map(55, 750,340);
	set_map(56, 815,80);
	set_map(57, 805,25);
	set_map(58, 890,100);
	set_map(59, 550,730);

	set_map(60, 875,352);
	set_map(61, 980,295);
	set_map(62, 975,370);
	set_map(63, 1070,370);
	set_map(64, 920,430);
	set_map(65, 1120,450);
	set_map(66, 465,741);
	set_map(67, 860,470);
	set_map(68, 910,530);
	set_map(69, 510,810);

	set_map(70, 380,800);
	set_map(71, 796,525);
	set_map(72, 1050,202);
	set_map(73, 455,940);
	set_map(74, 328,883);
	set_map(75, 973,711);
	set_map(76, 1190,490);
	set_map(77, 876,736);
	set_map(78, 1180,250);
	set_map(79, 870,30);

	set_map(80, 915,647);
	set_map(81, 613,913);
	set_map(82, 1022,516);
	set_map(83, 275,790);
	set_map(84, 1278,663);
	set_map(85, 990,780);
	set_map(86, 1342,709);
	set_map(87, 1218,565);
	set_map(88, 1206,730);
	set_map(89, 1285,778);

	set_map(90, 1239,854);
	set_map(91, 1360,610);
	set_map(92, 1444,608);
	set_map(93, 1355,302);
	set_map(94, 1447,296);
	set_map(95, 1028,820);
	set_map(96, 1430,440);
	set_map(97, 1465,541);
	set_map(98, 1162,854);
	set_map(99, 1440,220);

	if(R==1)return 1;//�}�b�v���W�C���̂�
	//���[�g��`
	set_root(0 ,1 ,  0);//�T�������ŏI��
	set_root(0 ,2 ,  0);
	set_root(0 ,3 ,  0);

	set_root(2 ,4 , 20);
	set_root(2 ,6 , 60);

	set_root(3 ,5 , 40);

	set_root(4 ,7 , 60);

	set_root(5 ,7 , 40);
	set_root(5 ,8 , 70);

	set_root(6 ,9 , 60);

	set_root(7 ,10,100);

	set_root(8 ,11, 60);

	set_root(9 ,12, 50);

	set_root(10,13, 30);
	set_root(10,14, 60);
	set_root(10,15, 90);

	set_root(12,18,100);

	set_root(13,16, 60);

	set_root(14,16, 40);
	set_root(14,21,100);

	set_root(16,17, 20);

	set_root(17,19, 40);
	set_root(18,20, 40);
	set_root(19,22, 60);
	set_root(20,23, 50);
	set_root(21,24, 50);
	set_root(21,26, 50);
	set_root(22,25, 50);
	set_root(22,29,100);
	set_root(23,27, 50);
	set_root(23,28, 60);
	set_root(26,30, 30);
	set_root(26,31, 50);
	set_root(26,32, 80);
	set_root(27,34,101);
	set_root(28,36,100);
	set_root(29,33, 60);
	set_root(30,33, 60);
	set_root(31,40,101);
	set_root(32,42, 60);
	set_root(33,35, 40);
	set_root(35,42, 60);
	set_root(35,46,101);
	set_root(36,37, 20);
	set_root(37,38, 20);
	set_root(37,41, 20);
	set_root(38,39, 20);
	set_root(38,45,101);
	set_root(39,45,101);
	set_root(40,43, 30);
	set_root(40,44, 40);
	set_root(40,50,100);
	set_root(43,48, 60);
	set_root(44,47, 60);
	set_root(44,49, 60);
	set_root(45,52, 80);
	set_root(46,52, 60);
	set_root(47,51, 40);
	set_root(48,49, 20);
	set_root(48,53, 40);
	set_root(48,54, 60);
	set_root(49,54, 50);
	set_root(49,56, 70);
	set_root(50,55, 60);
	set_root(51,56, 60);
	set_root(51,58, 70);
	set_root(52,59,100);
	set_root(53,54, 20);
	set_root(54,57, 40);
	set_root(55,60, 50);
	set_root(56,57, 10);
	set_root(56,79,101);//boss
	set_root(57,79,101);//boss
	set_root(58,79,101);//boss
	set_root(59,66, 50);
	set_root(60,61, 10);//boss
	set_root(60,62, 40);//boss
	set_root(60,64, 90);//boss
	
	set_root(61,72,101);//boss
	set_root(62,63, 10);//boss
	set_root(63,65, 20);//boss
	set_root(63,78,101);//boss
	set_root(64,67, 30);//boss
	set_root(65,76,101);//boss
	set_root(66,69, 30);//boss
	set_root(66,70, 40);//boss
	set_root(67,68, 10);//boss
	set_root(67,71, 40);//boss
	set_root(68,80,101);//boss
	set_root(68,82,101);//boss
	set_root(69,73, 40);//boss
	set_root(69,81,101);//boss
	set_root(70,74, 40);//boss
	set_root(74,83,101);//boss
	set_root(76,87,101);//boss
	set_root(80,75,  0);//boss
	set_root(80,77,  0);//boss
	set_root(75,85,100);//boss
	set_root(77,85, 80);//boss
	set_root(85,95,101);//boss
	
	set_root(82,87, 60);//boss
	
	set_root(87,84, 10);//boss
	
	set_root(84,86, 20);//boss
	set_root(84,88, 40);//boss
	set_root(84,89, 60);//boss
	set_root(84,91,101);//boss
	
	set_root(89,90, 20);//boss
	set_root(90,98,101);//boss
	
	set_root(91,92, 20);//boss
	set_root(92,97, 30);//boss
	set_root(97,96, 40);//boss
	set_root(96,93, 50);//boss
	set_root(93,94, 60);//boss
	set_root(94,99,101);//boss

	return 1;
}
int FUN::set_map(int N,int X,int Y){

	dun[N].x = X*(data.window_y-96)/1000;
	dun[N].y = Y*(data.window_y-96)/1000+96;

	return 1;
}
int FUN::set_root(int A,int B,int N ){

	//Len = 55�@�ň��
	double K = 1;

    N /= 2;

	int Len =  (dun[A].x - dun[B].x) * (dun[A].x - dun[B].x);
	Len += (dun[A].y - dun[B].y) * (dun[A].y - dun[B].y);
	Len = int(sqrt( double(Len) ));

	if( N != 0 )
	{
		K = 100 / N;
	}

	int i;
	for(i=0;i<5;i++){
		if(dun[A].root[i]!=0)continue;
		dun[A].root[i]=B;
		dun[A].root_k[i]= int(Len * K);
		if(N != 101) dun[A].root_p[i]=N/2;
		else		 dun[A].root_p[i]=N;
		break;
	}

	return 1;
}
/*�f�[�^�̓ǂݍ���*/
int FUN::gaibu_load(){

	//����f�[�^�ǂݍ���
	FILE *fp;
	errno_t err;
	int i;
	
	SetCurrentDirectory(data.szDir);

	if( (err = fopen_s( &fp, "File/data/wep.dat", "rb" )) !=0 ) return -1;

	BYTE r_data[500];
	BYTE L[1];

	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].rank=r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].atk=r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].dur=r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].ninki[1]=r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].ninki[0]=r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].ninki[2]=r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].price=(int)r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].seizou_cost=r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].make_time=r_data[i];// * 54
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].create_time=r_data[i];// * 5400 * 30
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].req_clv[0]=r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].req_clv[1]=r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].req_clv[2]=r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].req_mana=r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].req_mana+=r_data[i];

	for(i=0;i<WEP_M;i++)
    {
		if(wep[i].ninki[0]	   >0) wep[i].zoku = 0;
		else if(wep[i].ninki[1]>0) wep[i].zoku = 1;
		else if(wep[i].ninki[2]>0) wep[i].zoku = 2;
		else					   wep[i].zoku = 3;

		if(wep[i].req_mana == 0){
			wep[i].req_mana = -1;
			shop[0].wep_cre[i] = 0;
			shop[1].wep_cre[i] = 0;
			shop[2].wep_cre[i] = 0;
			shop[3].wep_cre[i] = 0;
			shop[4].wep_cre[i] = 0;
		}else{
			shop[0].wep_cre[i] = -1;
			shop[1].wep_cre[i] = -1;
			shop[2].wep_cre[i] = -1;
			shop[3].wep_cre[i] = -1;
			shop[4].wep_cre[i] = -1;
		}

		wep[i].type = i/100;//����^�C�v
	}

	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].gazou = r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].kairyou_up = r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].color=r_data[i];

	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].mtype = r_data[i];
	fread(r_data,1,WEP_M,fp);for(i=0;i<WEP_M;i++) wep[i].mzoku = r_data[i];
 
  
	for(i=0;i<WEP_M;i++){
		fread(L,1,1,fp);//���������ǂݍ���
		char str[1000];
		fread(str,L[0],1,fp);
		str[L[0]] = 0;
		wep[i].name = str;

		fread(L,1,1,fp);//���������ǂݍ���
		fread(str,L[0],1,fp);
		for(int C=0;C<L[0]-1;C++){
			if(str[C] == 13 && str[C+1] == 10){
				str[C] = '-';
				str[C+1] = '-';
			}
		}
		str[L[0]] = 0;
		wep[i].info = str;

		fun.wep_st_cul(i);
	}
	fclose(fp);
	//�W���u�f�[�^�ǂݍ���
	if( (err = fopen_s( &fp, "File/data/job.dat", "rb" )) !=0 ) return -1;
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].wep_t=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].rank=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].rank_up=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].next_J[0]=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].next_J[1]=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].next_J[2]=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].st_st[0]=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].st_up[0]=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].st_st[1]=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].st_up[1]=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].st_st[2]=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].st_up[2]=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].st_st[3]=r_data[i];
	fread(r_data,1,JOB_M,fp);for(i=0;i<JOB_M;i++) jobs[i].st_up[3]=r_data[i];
	for(i=0;i<JOB_M;i++){
		jobs[i].gra = jobs[i].next_J[1];
		fread(L,1,1,fp);//���������ǂݍ���
		fread(jobs[i].name,L[0],1,fp);
	}

	fclose(fp);
	//�J���҃f�[�^�ǂݍ���
	if( (err = fopen_s( &fp, "File/data/menber.dat", "rb" )) !=0 ) return -1;
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].gra=r_data[i];//�摜
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].gra+=r_data[i]*100;//�F
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].job=r_data[i];//�E��
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].b_w=r_data[i];//�u���b�N�x
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].konjyou=r_data[i];//����
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].lv=r_data[i];//�������x��
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].st_st[0]=r_data[i];//�X�e�[�^�X_LV1
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].st_st[1]=r_data[i];
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].st_st[2]=r_data[i];
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].st_up[0]=r_data[i];
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].st_up[1]=r_data[i];
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].st_up[2]=r_data[i];
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].skill=r_data[i];//�X�L��
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].grow_t=r_data[i];//�����^�C�v
	fread(r_data,1,EMP_M,fp);for(i=0;i<EMP_M;i++) emp[i].req_turn=r_data[i];//�o����
	char kari_n[255];
	for(i=0;i<EMP_M;i++){
		fread(L,1,1,fp);//���������ǂݍ���
		fread(kari_n,L[0],1,fp);
		kari_n[L[0]] = NULL;
		emp[i].st[0] = emp[i].st_st[0];
		emp[i].st[1] = emp[i].st_st[1];
		emp[i].st[2] = emp[i].st_st[2];
		emp[i].name = kari_n;
		emp[i].exp = (emp[i].lv-1) * (emp[i].lv-1) * 2000;
		emp[i].pay_money = 150;//����15��
		emp[i].req_money = 150;//����15��
		emp[i].req_rate = 100;
		emp[i].b_w		 = 70;//����90%
		if(emp[i].job == 0)emp[i].shift_n =0;
		emp[i].lv = 1;
	}
	fclose(fp);

	//�����f�[�^�ǂݍ���
	if( (err = fopen_s( &fp, "File/data/enemy.dat", "rb" )) !=0 ) return -1;
	fread(r_data,1,ENE_M,fp);for(i=0;i<ENE_M;i++) ene[i].skill=r_data[i];
	fread(r_data,1,ENE_M,fp);for(i=0;i<ENE_M;i++) ene[i].st[0]=r_data[i];
	fread(r_data,1,ENE_M,fp);for(i=0;i<ENE_M;i++) ene[i].st[1]=r_data[i];
	fread(r_data,1,ENE_M,fp);for(i=0;i<ENE_M;i++) ene[i].st[2]=r_data[i];
	fread(r_data,1,ENE_M,fp);for(i=0;i<ENE_M;i++) ene[i].st[3]=r_data[i];
	fread(r_data,1,ENE_M,fp);for(i=0;i<ENE_M;i++) ene[i].exp=r_data[i];
	fread(r_data,1,ENE_M,fp);for(i=0;i<ENE_M;i++) ene[i].money=r_data[i];
	for(i=0;i<ENE_M;i++){
		fread(L,1,1,fp);//���������ǂݍ���
		fread(ene[i].name,L[0],1,fp);
	}
	fclose(fp);
	//��p�f�[�^�ǂݍ���
	if( (err = fopen_s( &fp, "File/data/tactics.dat", "rb" )) !=0 ) return -1;
	fread(r_data,1,MANA_M,fp);for(i=0;i<MANA_M;i++)   mana[i].rank = r_data[i];
	fread(r_data,1,MANA_M,fp);for(i=0;i<MANA_M*5;i++) shop[i/MANA_M].syou_mp[i%MANA_M] = r_data[i%MANA_M]*5;
	fread(r_data,1,MANA_M,fp);for(i=0;i<MANA_M*5;i++) shop[i/MANA_M].syou_money[i%MANA_M] = r_data[i%MANA_M]*1000;
	fread(r_data,1,MANA_M,fp);for(i=0;i<MANA_M;i++)   mana[i].b_w_u = r_data[i];
	fread(r_data,1,MANA_M,fp);for(i=0;i<MANA_M;i++)   mana[i].b_w_d = r_data[i];
	fread(r_data,1,MANA_M,fp);for(i=0;i<MANA_M;i++)   mana[i].b_w_c = double(r_data[i])/10;
	fread(r_data,1,MANA_M,fp);for(i=0;i<MANA_M*5;i++) shop[i/MANA_M].mana_rest[i%MANA_M] = r_data[i%MANA_M];//�g�p��
	fread(r_data,1,MANA_M,fp);for(i=0;i<MANA_M;i++)   mana[i].seido = r_data[i];

	for(i=0;i<MANA_M;i++){
		mana[i].type = i/60;
		mana[i].icon = data.mana_icon[i/60];
		if(mana[i].b_w_d==0){//����
			mana[i].b_w_u=99999;
			mana[i].b_w_d=-99999;
		}else if(mana[i].b_w_d==1){//�u���b�N
			mana[i].b_w_d=mana[i].b_w_u;
			mana[i].b_w_u=99999;
		}else if(mana[i].b_w_d==2){//�z���C�g
			mana[i].b_w_d=-99999;
			mana[i].b_w_c*=-1;
		}
	}

	for(i=0;i<MANA_M;i++){
		char str[1000];
		fread(L,1,1,fp);//���������ǂݍ���
		fread(str,L[0],1,fp);
		str[L[0]] = NULL;
		mana[i].name = str;

		
		fread(L,1,1,fp);
		fread(str,L[0],1,fp);
		str[L[0]] = NULL;
		for(int C=0;C<L[0]-1;C++){
			if(str[C] == 13 && str[C+1] == 10){
				str[C] = '-';
				str[C+1] = '-';
			}
		}
		mana[i].help = str;
		mana[i].seido_h = str;

		fread(L,1,1,fp);
		fread(str,L[0],1,fp);
		str[L[0]] = NULL;
		for(int C=0;C<L[0]-1;C++){
			if(str[C] == 13 && str[C+1] == 10){
				str[C] = '-';
				str[C+1] = '-';
			}
		}
		//mana[i].zukan = str;
		mana[i].zukan = mana[i].help + "--"+ str;//�b��

	}
	fclose(fp);
	//�C�x���g�f�[�^�ǂݍ���
	if( (err = fopen_s( &fp, "File/data/event.dat", "rb" )) !=0 ) return -1;
	fread(r_data,1,EVE_M,fp);for(i=0;i<EVE_M;i++) eve[i].flag_req[0] = r_data[i];
	fread(r_data,1,EVE_M,fp);for(i=0;i<EVE_M;i++) eve[i].flag_req[1] = r_data[i];
	fread(r_data,1,EVE_M,fp);for(i=0;i<EVE_M;i++) eve[i].flag_req[2] = r_data[i];
	fread(r_data,1,EVE_M,fp);for(i=0;i<EVE_M;i++) eve[i].flag_nreq[0] = r_data[i];
	fread(r_data,1,EVE_M,fp);for(i=0;i<EVE_M;i++) eve[i].flag_nreq[1] = r_data[i];
	fread(r_data,1,EVE_M,fp);for(i=0;i<EVE_M;i++) eve[i].flag_nreq[2] = r_data[i];
	fread(r_data,1,EVE_M,fp);for(i=0;i<EVE_M;i++) eve[i].turn_req = (r_data[i]-1)*28*12;
	fread(r_data,1,EVE_M,fp);for(i=0;i<EVE_M;i++) eve[i].turn_req += (r_data[i]-1)*28;
	fread(r_data,1,EVE_M,fp);for(i=0;i<EVE_M;i++) eve[i].turn_req += (r_data[i]-1);
	fread(r_data,1,EVE_M,fp);for(i=0;i<EVE_M;i++) eve[i].time_req = r_data[i];

	for(int i=0;i<EVE_M;i++){
		for(int j=0;j<3;j++){
			if(eve[i].flag_req[j] == 0) eve[i].flag_req[j] = 1;
		}
	}
	//�M�̓f�[�^�ǂݍ���
	if( (err = fopen_s( &fp, "File/data/medal.dat", "rb" )) !=0 ) return -1;

	int LN;

	for(int i = 0;i<100;i++)
	{
		fread(&sys.medal_gold[i]  ,sizeof(int),1,fp);
		fread(&sys.medal_nanndo[i],sizeof(int),1,fp);
	}

	for(i=0;i<100;i++){
		fread(&LN,sizeof(int),1,fp);//���������ǂݍ���
		char str[1000];
		fread(str,LN,1,fp);
		str[LN] = 0;
		sys.medal_name[i] = str;

		fread(&LN,sizeof(int),1,fp);//���������ǂݍ���
		fread(str,LN,1,fp);
		str[LN] = 0;
		for(int C=0;C<LN-1;C++){
			if(str[C] == 13 && str[C+1] == 10){
				str[C] = '-';
				str[C+1] = '-';
			}
		}
		sys.medal_info[i] = str;
	}

	fclose(fp);
	return 1;

}/*�O���t�@�C���̓ǂݍ���*/
int FUN::wep_price(double rate){

	for( int W = 0 ; W < WEP_M ; W++ ){
		wep[W].price = int(wep[W].priceOri * rate);
	}

	return 1;
}
int FUN::name_set(int N){

	FILE *fp;
	errno_t err;
	//�X�����ǂݍ���
	//���O�f�[�^�ǂݍ���
	std::vector<std::string> name_man;
	std::vector<std::string> name_woman;
	std::vector<int> man_c;
	std::vector<int> wom_c;
	char readline[256];
	int c = 0;
	//���O�ꗗ�����p
	if( (err = fopen_s( &fp, "File/data/otoko.txt", "r" )) !=0 ) return -1;
	while(fgets(readline, 256, fp) != NULL){
		if(readline[strlen(readline)-1] == '\n'){
			readline[strlen(readline)-1] = NULL;
		}
		name_man.push_back(readline);
		man_c.push_back(c);
		c++;
	}
	fclose(fp);

	c = 0;
	if( (err = fopen_s( &fp, "File/data/onnna.txt", "r" )) !=0 ) return -1;
	while(fgets(readline, 256, fp) != NULL){		
		if(readline[strlen(readline)-1] == '\n'){
			readline[strlen(readline)-1] = NULL;
		}
		name_woman.push_back(readline);
		wom_c.push_back(c);
		c++;
	}
	fclose(fp);

	if(N == 0)
    {//���O�ԍ��Z�b�g
		random_shuffle(man_c.begin(), man_c.end());
		random_shuffle(wom_c.begin(), wom_c.end());

		int M = 0;
		int W = 0;

		for(int i= 100;i<EMP_M;i++){
			switch( emp[i].gra%100 ){
				case 0://�X���E�j
				case 4://�|�j�e
				case 5://�|��
				case 7://�n�Q
				case 10://���N�E�j
				case 12://�V�l�E�j
				case 20://�����E�j
				case 22://����
				case 30://�c���E�j
				case 31://���炭��
				case 32://���l
					emp[i].name_no = man_c[M];
					M++;
				break;
				case 1://�X���E��
				case 3://����
				case 11://���N�E��
				case 13://�V�l�E��
				case 14://����
				case 19://�����E��
				case 29://�c���E��
				case 37://�����m
					emp[i].name_no = 10000 + wom_c[W];
					W++;
				break;
				case 26://����
					if(Rand(1) == 0){
						emp[i].name_no = man_c[M];
						M++;
					}else{
						emp[i].name_no = 10000 + wom_c[W];
						W++;
					}
				break;
			}
		}
	}

	for(int i=100;i<EMP_M;i++){
		if(emp[i].name_no < 10000) emp[i].name = name_man[emp[i].name_no];
		else					   emp[i].name = name_woman[emp[i].name_no-10000];
	}


	return 1;
}
int FUN::wep_st_cul(int N){

	double rank_b = 0;
	double atk_b = 0;
	double dur_b = 0;
	double ninki_b = 0;
	double price_b = 0;
	double make_b = 0;
	double time_b = 0;
	double kaihatu_b = 10;
	double def_b = 0;
	double total_b = 0;
	double kari = 0;

	if(wep[N].req_clv[0] >= wep[N].req_clv[1] && wep[N].req_clv[0] >= wep[N].req_clv[2]){
		kaihatu_b += wep[N].req_clv[0];
		if(wep[N].req_clv[1] + 5 - wep[N].req_clv[0] * 7 / 8 > 0  && wep[N].req_clv[1]){
			kari += wep[N].req_clv[1] + 5 - wep[N].req_clv[0] * 7 / 8;
		}
		if(wep[N].req_clv[2] + 5 - wep[N].req_clv[0] * 7 / 8 > 0  && wep[N].req_clv[2]){
			kari += wep[N].req_clv[2] + 5 - wep[N].req_clv[0] * 7 / 8;
		}
	}else if(wep[N].req_clv[1] >= wep[N].req_clv[2]){
		kaihatu_b += wep[N].req_clv[1];
		if(wep[N].req_clv[1] + 5 - wep[N].req_clv[1] * 7 / 8 > 0  && wep[N].req_clv[1]){
			kari += wep[N].req_clv[1] + 5 - wep[N].req_clv[1] * 7 / 8;
		}
		if(wep[N].req_clv[2] + 5 - wep[N].req_clv[1] * 7 / 8 > 0  && wep[N].req_clv[2]){
			kari += wep[N].req_clv[2] + 5 - wep[N].req_clv[1] * 7 / 8;
		}
	}else {
		kaihatu_b += wep[N].req_clv[2];
		if(wep[N].req_clv[1] + 5 - wep[N].req_clv[2] * 7 / 8 > 0  && wep[N].req_clv[1]){
			kari += wep[N].req_clv[1] + 5 - wep[N].req_clv[2] * 7 / 8;
		}
		if(wep[N].req_clv[2] + 5 - wep[N].req_clv[2] * 7 / 8 > 0  && wep[N].req_clv[2]){
			kari += wep[N].req_clv[2] + 5 - wep[N].req_clv[2] * 7 / 8;
		}
	}

    kaihatu_b *= (200 + kari) / 200;
    rank_b = 10 + (kaihatu_b - 10) / 2;

    def_b = kaihatu_b * 9 + rank_b;

    atk_b = def_b / 4;
    dur_b = 25 + def_b / 25;
    ninki_b = def_b / 4;
    price_b = def_b * 3 / 8;
    make_b = 30 + (kaihatu_b - 10) / 3;
    time_b = 5 + def_b / 20;

    //����큕�l�C��␳�A�f�[�^�x�[�X�␳
	int NT =0;
	if(wep[N].ninki[0] > 0){//����
        make_b *= 1.2;
        atk_b *= 1.1;
		NT = 0;
	}else if(wep[N].ninki[2] > 0){//�������悳
        price_b *= 1.2;
        time_b *= 1.4;
        ninki_b *= 1.1;
		NT = 2;
	}else{//�₷��
        dur_b *= 1.4;
        atk_b *= 0.9;
        price_b *= 0.8;
		NT = 1;
	}

    if(N < 100){
        atk_b *= 1.07;
        dur_b *= 0.8;
        price_b *= 0.8;	
	}else if(N < 200){
        time_b *= 1.1;
	}else if(N < 300){
        atk_b *= 1.14;
        dur_b *= 1.2;
        time_b *= 1.2;
	}else if(N < 400){
        atk_b *= 0.93;
        dur_b *= 1.4;
        price_b *= 1.4;
        time_b *= 1.3;
	}

	wep[N].atk		   = (int)(atk_b * wep[N].atk / 100);
	wep[N].dur		   = (int)(dur_b * wep[N].dur / 100);
	wep[N].ninki[NT]   = (int)(ninki_b * wep[N].ninki[NT] / 100);
	wep[N].price	   = (int)(price_b * wep[N].price / 7);
	wep[N].priceOri    = wep[N].price;
    wep[N].seizou_cost = (int)(make_b * wep[N].make_time / 100);
    wep[N].make_time   = (int)(time_b * wep[N].make_time * 54 / 100);
	wep[N].create_time = (int)(kaihatu_b * wep[N].create_time * 54 *30);

    int mp = wep[N].ninki[0] + wep[N].ninki[1] + wep[N].ninki[2];
    //��{����
	if(N%100<30)
    {
		wep[N].mtype = mp;
		wep[N].mzoku = 0;
	}
    else if( (N%100-30) % 8 < 4 )
    {
		wep[N].mtype = mp;
		wep[N].mzoku = 0;
	}
    else
    {
		wep[N].mtype = 0;
        wep[N].mzoku = mp * 2 / 3;
	}

	return 1;
}
int FUN::gra_load(/*�摜�̓ǂݍ���*/){

	SetCurrentDirectory(data.szDir);

	color.siro	=GetColor(255,255,255);
	color.kuro	=GetColor(0,0,0);
	color.aka	=GetColor(255,0,0);
	color.ao	=GetColor(0,0,255);
	color.hai	=GetColor(128,128,128);

	data.font[0]= CreateFontToHandle( NULL , 18 , 5 ) ;
	data.font[1]= CreateFontToHandle( NULL , 24 , 5 ) ;
	data.font[2]= CreateFontToHandle( NULL , 14 , 5 ) ;

	char dir_name[60];
	int i;
	for(i=0;i<40;i++){//���j�b�g�摜
		sprintf_s(dir_name,"File/unit/%d%d_r.bmp",i/10,i%10);
		LoadDivGraph(dir_name,12, 3 , 4 , 16 , 16 , gra.unit[i]);
		sprintf_s(dir_name,"File/unit/%d%d_g.bmp",i/10,i%10);
		LoadDivGraph(dir_name,12, 3 , 4 , 16 , 16 , gra.unit[i+100]);
		sprintf_s(dir_name,"File/unit/%d%d_b.bmp",i/10,i%10);
		LoadDivGraph(dir_name,12, 3 , 4 , 16 , 16 , gra.unit[i+200]);
	}

	//�V�X�e���摜
	LoadDivGraph("File/system/emo.bmp",20, 5 , 4 , 14 , 18 , gra.emo);

	for(i=0;i<WEP_M;i++){//����摜
		int G = wep[i].gazou;
		if( G== 0) continue;
		if(i%10== 0 || i%10 >5)	sprintf_s(dir_name,"File/icon/w_%d%d%d.png",(G)/100%10,(G)/10%10,G%10);
		else					sprintf_s(dir_name,"File/icon/w_%d%d%d.png",(G)/100%10,(G)/10%10,G%10);
		gra.wep[i]=LoadGraph(dir_name);
		wep[i].color =(wep[i].color * 36 / 25 + 180) % 360 - 180; 
		GraphFilter( gra.wep[i], DX_GRAPH_FILTER_HSB, 0, wep[i].color , 0, 0) ;
	}

	for(i=0;i<gra.icon_m;i++){//�A�C�R���摜
		sprintf_s(dir_name,"File/icon2/s_%d%d%d.png",i/100%10,i/10%10,i%10);
		gra.ico[i]=LoadGraph(dir_name);
	}

	for(i=0;i<18;i++){//�ړ���
		sprintf_s(dir_name,"File/system/move_%d%d.png",i/10%10,i%10);
		gra.move[i]=LoadGraph(dir_name);
	}

	//�}�b�v�摜
	gra.map=LoadGraph("File/system/map.bmp");

	LoadDivGraph("File/system/winskin.bmp",99, 3 , 33 , 10 , 10 , gra.win);//�E�B���h�E�X�L��

	LoadDivGraph( "File/system/font.bmp" , 60 , 10 , 6 , 10 , 10 , gra.moji);//�t�H���g�摜
	LoadDivGraph( "File/system/dot_font.bmp" , 80 , 10 , 8 , 8 , 8 , gra.moji_b);//�t�H���g�摜

	//�w�i�摜
	gra.back[0] = LoadGraph("File/system/����01.jpg");
	gra.back[1] = LoadGraph("File/system/����02.jpg");
	gra.back[2] = LoadGraph("File/system/����03.jpg");
	gra.back[3] = LoadGraph("File/system/�w�i04.jpg");
	gra.back[4] = LoadGraph("File/system/�w�i05.jpg");
	gra.back[5] = LoadGraph("File/system/�w�i06.jpg");
	gra.back[6] = LoadGraph("File/system/�w�i07.jpg");
	gra.back[7] = LoadGraph("File/system/�w�i08.jpg");
	gra.back[8] = LoadGraph("File/system/�w�i09.jpg");
	gra.back[9] = LoadGraph("File/system/�w�i10.jpg");


	//���o��
	gra.huki[0] = LoadGraph("File/system/huki_00.bmp");
	gra.huki[1] = LoadGraph("File/system/huki_01.bmp");

	//�^�C�g��
	gra.title[0] = LoadGraph("File/system/title1.jpg");
	gra.title[1] = LoadGraph("File/system/title2.jpg");
	gra.title[2] = LoadGraph("File/system/title3.jpg");
	gra.title[3] = LoadGraph("File/system/title4.jpg");
	gra.title[4] = LoadGraph("File/system/title5.jpg");
	gra.title[5] = LoadGraph("File/system/title6.jpg");
	gra.title[6] = LoadGraph("File/system/title7.jpg");
	gra.title[7] = LoadGraph("File/system/title8.jpg");
	gra.title[8] = LoadGraph("File/system/title9.jpg");
	gra.title[9] = LoadGraph("File/system/title10.jpg");

	gra.shop[0] = LoadGraph("File/system/�O��01.jpg");
	gra.shop[1] = LoadGraph("File/system/�O��02.jpg");
	gra.shop[2] = LoadGraph("File/system/�O��03.jpg");
	gra.shop[3] = LoadGraph("File/system/�O��04.jpg");
	gra.shop[4] = LoadGraph("File/system/�O��05.jpg");

	//�^�C�g��
	gra.title_txt = LoadGraph("File/system/title.png");

	for(i=0;i<10;i++){//�ړ���
		sprintf_s(dir_name,"File/system/t_sub%d.png",i);
		gra.title_sub[i]=LoadGraph(dir_name);
		GraphFilter( gra.title_sub[i], DX_GRAPH_FILTER_INVERT ) ;
	}

	return 1;
}
int FUN::sound_load(void/*�����f�[�^�̓ǂݍ���*/){

	int i = 0;

	//for(i=0;i<100;i++){
	//	sou.se[i] = LoadSoundMem("File/sound/cursor01.wav");
	//}

	sou.se[0] = LoadSoundMem("File/sound/coin05.wav");
	sou.se[1] = LoadSoundMem("File/sound/coin06.wav");
	sou.se[2] = LoadSoundMem("File/sound/pyoro68.wav");
	sou.se[3] = LoadSoundMem("File/sound/kachi11.wav");
	sou.se[4] = LoadSoundMem("File/sound/paper00.wav");
	sou.se[5] = LoadSoundMem("File/sound/eco03.wav");
	sou.se[6] = LoadSoundMem("File/sound/weapon00.wav");
	sou.se[7] = LoadSoundMem("File/sound/tm2_bird002.wav");
	sou.se[8] = LoadSoundMem("File/sound/voice006.wav");
	sou.se[9] = LoadSoundMem("File/sound/coin04.wav");
	sou.se[10] = LoadSoundMem("File/sound/pyoro33.wav");

	return 1;
}
int FUN::sound_volset(void){
	int i=0;

	for(i=0;i<100;i++){
		ChangeVolumeSoundMem( 255 * opt.wev_size * opt.wev_size / 10000, sou.se[i] ) ;
	}

	return 1;
}
/*�c�ƃt�F�C�Y*/
int FUN::work_main(){

	int time = GetNowCount()/1000;
	int time_s = data.play_time;
	opt.speed = 1;
    opt.speed_max = 1;

	while(1){

		data.play_time = time_s + GetNowCount()/1000 - time;

		fun.inp_check();//���̓`�F�b�N

		if(fun.work_sousa() == -1)break;//�v���C���[����

		if(data.game_over != -1) opt.speed = 0;

		if(opt.speed != 0){
			fun.customer_act();//�q�s��
			fun.shop_act();//�X����
			fun.make_create();//�������J������

			if(data.time==4800)fun.data_save(data.now_save);//�����Z�[�u
		
			if(data.time % 600 == 0) fun.eve_check();
			
			if(data.time>=4800 && data.time<=10200 && data.time%100 == 0){//8������s���J�n	
				fun.tansaku_syori();//�T������
			}

			data.time++;
			if(data.time == 10800 && data.day%28 == 27 && (data.mode != 0 || data.day>28)){//�����m�F				

				opt.speed = 0;
				wind.on[3] = 1;
				wind.on[4] = 1;
				wind.on[5] = 1;
				window_sort(3);
				window_sort(4);
				window_sort(5);
				wind.emp_hyouji = 6;
				wind.ts_hyouji = 1;
				data.taiguu_ok = 1;//�ҋ��ύX�\�ɂ���
				draw.kakunin("�����ł�--�ҋ��̕ύX--�ٗp�̊m�F�����܂��傤",1);
                
                //�����xA�����̓X���������ASA�͐����u���ɂ���
                shop[P].getumatu();


				se_ok(4);
			}

			if(data.time >= 11100)
			{//18:30���ň�����I���A�ő�10���ԁ@8~17�ŋx�e��������{

				if(data.game_over == -1 && data.mode > 0)
				{
					for(int S=0;S<data.shop_cnt;S++	  )
					{
						int GT = shop[S].goal_check();
						if(GT != -1)
						{
							data.game_over = S*100 + GT;
							if( fun.game_over() == 1)
							{
									fun.data_save(data.now_save);
									return 1;
							}
						}
					}
				}

				work_day_s();
				if(data.day%28 ==0){
					wind.ts_hyouji = 0;
					wind.syousai_hyouji = 1;//�ڍו\�����[�h
					data.taiguu_ok = 0;//�ҋ��ύX�\�ɂ���
					if(opt.speed != 10000)opt.speed = 0;
					wind.graph_hyouuji = 0;
					wind.syu_year = (data.day-1)/336;//�N���I�[�o�[
					wind.syu_mon  = (data.mon-1)%12;//�N���I�[�o�[
					wind.syu_day  = data.day;//�N���I�[�o�[
					wind.syu_set  = 1;
					se_ok(0);
				}
			}

		}

		if(opt.speed<=0 || data.time % opt.speed == 0)
		{//�`�揈��
			draw.work();
			ScreenFlip();
		}

		if(fun.err_c()== -1) break;
	}

	fun.data_save(data.now_save);

	return 1;
}
int FUN::work_month_s(/*���͂��ߏ���*/){

	for(int S = 0;S<data.shop_cnt;S++) shop[S].mon_start();

	int kabu_pre[5];
	for(int N=0;N<5;N++)kabu_pre[N] = shop[N].kabu_max;//���������x�p
	for(int E = 0;E<EMP_M;E++)		   emp[E].mon_start();
	for(int N=0;N<5;N++)shop[N].kabu_price = shop[N].kabu_price*kabu_pre[N]/shop[N].kabu_max;//�����Čv�Z
	
	for(int S = 0;S<data.shop_cnt;S++) shop[S].cul_ave();

	//�j�Y�����F������
	data.jinkou_mon[data.mon-1] = data.jinkou;
	cul_mensetu();

	//�l���������{
	data.jinkou_up++;

	return 1;
}
int FUN::work_day_s(/*���͂��ߏ���*/){

	int SE = 0;

	data.time=4200;
	data.day++;
	data.mon = data.day/28;
	sys.total_day++;

	//�V�󏈗�
	data.tenki = Rand(100);
	if(data.tenki < 70)		 data.tenki = 0;
	else if(data.tenki < 90) data.tenki = 1;
	else if(data.tenki < 98) data.tenki = 2;
	else					 data.tenki = 3;

	for(int S=0;S<data.shop_cnt;S++	  ) shop[S].day_mana();//�o�c��p�g�p
	if(data.day%28==0 && data.day != 0)	work_month_s();//��������
	for(int E=0;E<EMP_M;E++)		    emp[E].day_start();
	for(int S=0;S<data.shop_cnt;S++)	shop[S].day_start();//������

	//�n���^�[�̍s����ԏ�����
	for(int H=0;H<HUN_M;H++)     hun[H].act = 0;
	
	if(wind.syu_now == 1){
		if(data.day < DAY_M){
			wind.syu_year = data.day/336;//�N���I�[�o�[
			wind.syu_mon  = data.mon%12;//�N���I�[�o�[
			wind.syu_day  = data.day;//�N���I�[�o�[
		}else{
			wind.syu_year = YEAR_M-1;//�N���I�[�o�[
			wind.syu_mon  = 11;//�N���I�[�o�[
			wind.syu_day  = data.day-1;//�N���I�[�o�[
		}
	}
	//�u�[������
	data.boom_rest --;
	if(data.boom_rest <= 0){
		fun.eve_boom();
	}
	//�����_���C�x���g
	for(int S=0;S<data.shop_cnt;S++){
		if( shop[S].eve_random() == 1 && S == P){
			fun.se_ok(10);
		}
	}

	//�`���ґ���
	int CNT;
	if(data.day%28==0) CNT = data.jinkou_up / 2;//���P
	else			   CNT = (fun.Rand(data.jinkou_up)+5)/10;//����ȊO
	
	if(data.boom == 1) CNT *= 2;//�n���^�[�u�[��

	for(;CNT>0;CNT--)  make_hunter(1);
	
	//��p�������X�V
	EVE_FUN::Sin().mana_setumei();
	EVE_FUN::Sin().seido_setumei();

	list_sort();

	return 1;
}
int FUN::cul_mensetu(){

	for(int i=0;i<EMP_M;i++){
		for(int S=0;S<SHOP_M;S++){
			if(emp[i].req_jinji[0] <= shop[S].mensetu_lv )emp[i].mensetu[0][S] = 1;
			if(emp[i].req_jinji[1] <= shop[S].mensetu_lv )emp[i].mensetu[1][S] = 1;
			if(emp[i].req_jinji[2] <= shop[S].mensetu_lv )emp[i].mensetu[2][S] = 1;
			if(emp[i].req_jinji[3] <= shop[S].mensetu_lv )emp[i].mensetu[3][S] = 1;			
			if(emp[i].req_jinji[4] <= shop[S].mensetu_lv )emp[i].mensetu[4][S] = 1;
			if(emp[i].skill == 0)	   emp[i].mensetu[4][S] = 1;//�X�L���Ȃ��Ȃ�P�O�O������
		}
	}

	return 1;
}
int FUN::tansaku_syori(){
	int HIT = 0;

	//���[�g�T������
	for(int D=0;D<100;D++){
		if(dun[D].seek<=0)continue;
		dun[D].seek = min(100,dun[D].clear_f / 10 + 1);//�T���x�v�Z
		for(int R=0;R<5;R++){
			if(dun[D].root[R]>0 && dun[D].root_p[R]>=0){//�T����
				if(dun[D].root_t[R]==0){//��������
					if(dun[D].seek>=dun[D].root_p[R]){
						dun[D].root_t[R]++;
						dun[dun[D].root[R]].seek = max(0,dun[dun[D].root[R]].seek);
						HIT ++;//�����t���O
						}
					continue;
				}
				dun[D].root_t[R]+=3;
				if(dun[D].root_t[R]>=dun[D].root_k[R]){//�S�[��
					//���[�g�����_���W��������
					dun[dun[D].root[R]].seek = max(1,dun[dun[D].root[R]].seek);
					dun[D].root_p[R] = -1;
				}
			}
		}
	}

	if(HIT> 0){
		for(int S = 0; S< data.shop_cnt;S++){
			if(shop[S].mana_cnt[M_NKAR] > 0){
				shop[S].start_sell(80,7);
			}
		}
	}

	return 1;
}
/*���쏈��*/
int FUN::work_sousa(/*�E�B���h�E���^�u�ėp����*/){

	int i,j;

	wind.info_t = -1;//�w���v����
	wind.info_no = -1;

	if(Inp.m_RC == 1){//�C���t�H�\��
		wind.info_on = 1 - wind.info_on;
	}

	//�v���C���[�����؂�ւ�
	//if(Inp.m_RO >0 && Inp.m_LO >0 && Inp.m_H != 0)
	//{
	//	data.play= (data.play + 1)%5;
	//	list_sort(1);
	//	se_ok(4);
	//	return 1;
	//}

	if(wind.syousai_hyouji>0){
		window_s11(Inp.m_x-data.window_x/2+300,Inp.m_y-data.window_y/2+250);
		return 1;
	}

	if(range( 15,5,180,20) == 1){
		wind.info_no = 20;
		wind.info_t = 12;
	}else if(range(225,5, 80,20) == 1){
		wind.info_no = 21;
		wind.info_t = 12;
	}else if(range(325,5, 65,20) == 1){
		wind.info_no = 22;
		wind.info_t = 12;
	}else if(range(410,5, 65,20) == 1){
		wind.info_no = 23;
		wind.info_t = 12;
	}else if(range(500,5, 65,20) == 1){
		wind.info_no = 24;
		wind.info_t = 12;
	}else if(range(695,5,110,20) == 1){
		wind.info_no = 25;
		wind.info_t = 12;
	}else if(range(830,5,180,20) == 1){
		wind.info_no = 26;
		wind.info_t = 12;
	}else if( data.window_x == 1024 && range(600,32,124, 64) == 1){
		wind.info_no = 27;
		wind.info_t = 12;
	}else if( data.window_x != 1024 && range(600,32,320, 64) == 1){
		wind.info_no = 27;
		wind.info_t = 12;
	}

	if(Inp.m_y>32 && Inp.m_y<96 && Inp.m_x<data.window_x - 20){//�^�u����&�R���t�B�O���^�C�g��
		i=Inp.m_x/48;
		
		if(Inp.m_x > data.window_x-60){//�^�C�g����
			wind.info_no = 12;
			wind.info_t = 12;
			if(Inp.m_LC == 1 && draw.kakunin("�^�C�g����ʂ֖߂�܂����H--(�L�^�͎����ł���܂�)",0)==1) return -1;
		}else if(Inp.m_x > data.window_x -110){//�R���t�B�O
			wind.info_no = 13;
			wind.info_t = 12;
			if(Inp.m_LC == 0) return 1;
			se_ok(4);
			option();
			return 1;
		}else if(Inp.m_x > data.window_x -230 + 36 + 54){//�Q�[���X�s�[�h�{��
			wind.info_no = 14;
			wind.info_t = 12;
			if(Inp.m_LC == 0) return 1;

            opt.speed_max *= 2;
            if( opt.speed_max > 64) opt.speed_max = 64;
            opt.speed = opt.speed_max;
			se_ok(3);
			return 1;
		}else if(Inp.m_x > data.window_x -230 + 36 + 18 ){//�Q�[���X�s�[�h�ύX
			wind.info_no = 14;			
			wind.info_t = 12;
			if(Inp.m_LC == 0) return 1;

            opt.speed = opt.speed_max;
			se_ok(3);
		}else if(Inp.m_x > data.window_x -230 + 36){//�Q�[���X�s�[�h����
			wind.info_no = 14;			
			wind.info_t = 12;
			if(Inp.m_LC == 0) return 1;

            opt.speed_max /= 2;
            if( opt.speed_max < 1) opt.speed_max = 1;
            opt.speed = opt.speed_max;
			se_ok(3);
		}else if(Inp.m_x > data.window_x -230){//�Q�[���X�s�[�h0
			wind.info_no = 14;
			wind.info_t = 12;
			if(Inp.m_LC == 0) return 1;
            opt.speed = 0;
			se_ok(3);
		}else if(Inp.m_x > data.window_x -280){//�w���v
			wind.info_no = 15;			
			wind.info_t = 12;
			if(Inp.m_LC == 0) return 1;
			tutorial_menu();
		}else{//�e�E�B���h�E�o������
			if(wind.ok[i] == 0 || i>=12) return 1;
			wind.info_no = i;
			wind.info_t = 12;
			if(Inp.m_LC == 0) return 1;
			wind.on[i]=1 - wind.on[i];
			se_ok(4);
			if(wind.on[i]==1)window_sort(i);
		}
	}else{//�E�B���h�E��������
		for(j=0;j<12;j++){
			if(wind.on[11] == 1)break;
			i=wind.hide[j];
			//�������N���b�N
			if( Inp.m_x>=wind.x[i] &&
				Inp.m_x<=wind.x[i]+wind.sx[i] &&
				Inp.m_y>=wind.y[i] &&
				Inp.m_y<=wind.y[i]+wind.sy[i] && wind.on[i]==1){
				//�E�B���h�E����
				if(Inp.m_x>=wind.x[i]+wind.sx[i]-26 && Inp.m_y<=wind.y[i]+32 && Inp.m_LC==1){
					wind.on[i]=0;				
					se_ok(4);
					break;
				}
				//�E�B���h�E�ő剻/�ŏ���
				else if(Inp.m_x>=wind.x[i]+wind.sx[i]-52 && Inp.m_y<=wind.y[i]+32 && Inp.m_LC==1){
					if(wind.sy[i] == wind.smax[i] || wind.sy[i] == wind.scrm[i] + 40) wind.sy[i] = wind.smini[i];
					else															  wind.sy[i] = wind.scrm[i] + 40;

					if(wind.sy[i] > wind.smax[i])		   wind.sy[i] = wind.smax[i];
					else	if(wind.sy[i] < wind.smini[i]) wind.sy[i] = wind.smini[i];
					se_ok(4);					
					wind.info_no = i;
					wind.info_t = 12;
					break;
				}
				//�X�N���[���R���g���[������
				else if(wind.scr_on[i]==1 && Inp.m_y>=wind.y[i]+28 && wind.x[i]+wind.sx[i]-24<Inp.m_x && Inp.m_LC == 1){
					wind.drag = 10+i;
					wind.scr_ccy = wind.scr[i];
					wind.scr_cy = Inp.m_y-wind.y[i]-28;
					window_sort(i);
					break;
				}
				//�E�B���h�E���������
				else if(Inp.m_y<=wind.y[i]+6  && Inp.m_LC==1){
					wind.sc=i+11;
					window_sort(i);
					break;
				}
				//�E�B���h�E�͂�
				else if(Inp.m_y<=wind.y[i]+28){
					if(Inp.m_LC == 1){
						wind.drag=i;
						wind.dx=Inp.m_x-wind.x[i];
						wind.dy=Inp.m_y-wind.y[i];
						window_sort(i);
					}
					wind.info_no = i;
					wind.info_t = 12;
					break;
				}
				//�E�B���h�E����������
				else if(Inp.m_y>=wind.y[i]+wind.sy[i]-16  && Inp.m_LC==1){
					wind.sc=i;
					window_sort(i);
					break;
				}
				//����
				else if(Inp.m_y>=wind.y[i]+28){
						if(Inp.m_LC || Inp.m_RC || Inp.m_H !=0)	window_sort(i);
						work_sousa_n(Inp.m_x-wind.x[i],Inp.m_y-wind.y[i]-28,i);
					   break;
				}else if(Inp.m_LD==1){
					break;
				}
			}
		}
	}
	//�g��k������
	if(Inp.m_LO>0 && wind.drag!=-1){
		if(wind.drag<11){
		wind.x[wind.drag]=Inp.m_x-wind.dx;
		wind.y[wind.drag]=Inp.m_y-wind.dy;
		//if(wind.y[wind.drag]<96)wind.y[wind.drag]=96;
		//if(wind.y[wind.drag]>data.window_y-wind.sy[wind.drag])wind.y[wind.drag]=data.window_y-wind.sy[wind.drag];
		//if(wind.x[wind.drag]<0)wind.x[wind.drag]=0;
		//if(wind.x[wind.drag]>data.window_x-wind.sx[wind.drag])wind.x[wind.drag]=data.window_x-wind.sx[wind.drag];
		}else{//�X�N���[������
			i=wind.drag-10;
			wind.scr[i]=wind.scr_ccy + ((Inp.m_y-wind.y[i]-28-wind.scr_cy)*100/(wind.sy[i]-44))*wind.scrm[i]/100;//-(wind.sy[i]-44)/2;
		}
	}else{
		wind.drag=-1;
	}

	for(int i=0;i<11;i++){
		if(wind.y[i]<96)wind.y[i]=96;
		if(wind.y[i]>data.window_y-wind.sy[i])wind.y[i]=data.window_y-wind.sy[i];
		if(wind.x[i]<0)wind.x[i]=0;
		if(wind.x[i]>data.window_x-wind.sx[i])wind.x[i]=data.window_x-wind.sx[i];
		if(wind.sy[i] > data.window_y - 96 ) wind.sy[i] = data.window_y - 96;
	}


	//�E�B���h�E�T�C�Y�ύX����
	if(Inp.m_LO>0 && wind.sc!=-1){
		int wss = wind.sc%11;

		if(wind.sc<11){
			wind.sy[wind.sc]=(Inp.m_y-wind.y[wind.sc]);
			if(wind.sy[wind.sc]<wind.smini[wss])wind.sy[wind.sc]=wind.smini[wss];
			if(wind.sy[wind.sc]>wind.smax[wind.sc])wind.sy[wind.sc]=wind.smax[wind.sc];
		}else{
			if(Inp.m_y<96)Inp.m_y=96;
			wind.sy[wss]-=Inp.m_y-wind.y[wss];
			if(wind.sy[wss]<wind.smini[wss])wind.sy[wss]=wind.smini[wss];
			else if(wind.sy[wss]>wind.smax[wss])wind.sy[wss]=wind.smax[wss];
			else wind.y[wss]+=Inp.m_y-wind.y[wss];
			if(wind.y[wss]>data.window_y-28)wind.y[wss]=data.window_y-28;
		}
	}else{
		wind.sc=-1;
	}
	//�z�C�[������
	wind.scr[wind.hide[0]]-=Inp.m_H*25;
	//�X�N���[�����E�v�Z
	for(i=0;i<11;i++){
		if(wind.scr[i]+(wind.sy[i]-38)>wind.scrm[i])wind.scr[i]=wind.scrm[i]-wind.sy[i]+38;
		if(wind.scr[i]<0) wind.scr[i]=0;
		if(wind.x[i] > data.window_x - 28) wind.x[i] = data.window_x -28;
		if(wind.y[i] > data.window_y - 28) wind.y[i] = data.window_y -28;
		if(wind.x[i] < 0) wind.x[i] = 0;
		if(wind.y[i] < 96){
			wind.y[i] = 96;
		}
	}
	//�h���b�O����
	if(Inp.m_LD == 1){
		Inp.d_no = -1;
		Inp.d_type = -1;
	}

	//�ҋ��ύX�C���t�H
	if(wind.info_no != wind.info_taiguu || wind.info_t <5 || wind.info_t>6){
		wind.info_taiguu = -1;
	}

	if(wind.info_t == -1){
		for(i=0;i<100;i++){//�_���W�����w���v
			if( range(dun[i].x-16,dun[i].y-16,32,32) == 1 && dun[i].seek>0){
				wind.info_no = i;
				wind.info_t = 11;
				break;
			}
		}
	}


	return 1;
}
int FUN::work_sousa_n(int X,int Y,int N/*�E�B���h�E�ŗL����*/){

	wind.info_t = N+1;

	switch(N){
		case 0:window_s01(X,Y);break;
		case 1:window_s02(X,Y);break;
		case 2:window_s03(X,Y);break;
		case 3:window_s04(X,Y);break;
		case 4:window_s05(X,Y);break;
		case 5:window_s06(X,Y);break;
		case 6:window_s07(X,Y);break;
		case 7:window_s08(X,Y);break;
		case 8:window_s09(X,Y);break;
		case 9:window_s10(X,Y);break;
	}

	return 1;
}
int FUN::window_sort(int W/*�E�B���h�E���я��ύX*/){

	for(int i=10;i>0;i--){
		if(wind.hide[i]==W){
			wind.hide[i]=wind.hide[i-1];
			wind.hide[i-1]=W;			
		}
	}

	return 1;
}
int FUN::window_s01(int X,int Y/*�q���*/){

	if(Y<110){
		wind.info_no=HUN_M;//�㕔�E�B���h�E
		wind.info_t = 1;
	}else if(Y+wind.scr[0]>119){
		if(shop[P].cust_list[(Y+wind.scr[0]-119)/20] != -1 ){
			wind.info_no = shop[P].cust_list[(Y+wind.scr[0]-119)/20];
			wind.info_t = 1;
		}
	}

	return 1;
}
int FUN::window_s02(int X,int Y/*������*/){
	//�N���b�N����
	int W_H = 78;//����
	int N;//�I���ʒu,�����Ȃ�������0
	int FN = -1;//�h���b�v�p�t�H���_�ԍ�
	if(X>6 && X<40) N = 0;//�^�u�̈ʒu
	else			N = X/40;
	int WN = -1;//�C���t�H�ʒu
	int i;

	//�\�[�g����
	if(Y>6 && Y<38){
		WN = 2000 + (X-6)/54;
		if(Inp.m_LC == 1){
			if(wind.wep_sort == (X-6)/54 )	sort_wep();
			else							wind.wep_sort = (X-6)/54;
		
			se_ok(6);
		}
	}else if(Y>=38 && Y<=72){
		WN = 2006;
	}

	//�C���t�H����
	for(i=0;i<7;i++){
		if(Y+wind.scr[1]>= W_H && Y+wind.scr[1]<= W_H + 35 && N==0){//�^�u����
				WN = 1000 + i;
				FN = i;
			break;
		}else if(Y+wind.scr[1]> W_H && Y+wind.scr[1]< W_H + wind.wfold_h[i]  && N!=0){//����A�C�R��
			N += (Y-W_H+wind.scr[1])/40*7;
			if(N<=wind.wfold_cnt[i]){
				WN = wind.wfold_list[i][N-1];
			}
			FN = i;
			break;
		}
		W_H += wind.wfold_h[i]+4;
	}

	wind.info_no = WN;

	if(Inp.m_LC == 1 && WN != -1 && WN<1000){//�͂ށE���큕�^�u
		Inp.d_no = WN;
		Inp.d_type = 2;
		se_ok(6);
	}
	//�h���b�v����
	if(Inp.m_LD == 1 && FN>=0 && Inp.d_no>=0 && wind.ts_hyouji == 0){
		if(Inp.d_type == 2 && Inp.d_no<1000){//����h���b�v�ňʒu�ύX
			if(FN != 0 || wind.wfold_cnt[0] < shop[P].medama_max){
				list_mw(FN);
				se_ok(3);
			}
		}
		if(Inp.d_no<1000 && Inp.d_type == 6 && WN>=0 && WN<1000){//�l�ރh���b�v
			//�V�t�g��ύX
			if(Inp.d_type == 5){//�X��
				list_de(Inp.d_no);
				emp[Inp.d_no-1000].shift_n = wep[WN].type;
				list_pe(Inp.d_no);
				se_ok(3);
			}else if(Inp.d_type == 6){//�E�l
				list_de(Inp.d_no);
				emp[Inp.d_no].shift_n = WN;
				list_pe(Inp.d_no);
				se_ok(3);
			}
		}
	}
	return 1;
}
int FUN::window_s03(int X,int Y/*�X�O���i*/){
	//�N���b�N����
	//int N =(Y+wind.scr[2])/40;//�I�����X�g�ʒu
	//int WN = wind.kai_list[N];
	wind.info_no= 0;//�㕔�E�B���h�E
	wind.info_t = 3;


	return 1;
}
int FUN::window_s04(int X,int Y/*���l���*/){
	//�N���b�N����
	int XPP  = (X-6)/40;//�I�����X�g�ʒu
	int YPP = (Y-42+wind.scr[3])/40;
	int XP=0,YP=-1,T=-1,E=-1,N = -1;

	if( X >= 286 ) XPP--;

	if(Y>6 && Y<38){//�\������
		wind.info_no = 1000+(X-6)/36+2;//�\�[�g�^�u
		if(Inp.m_LC == 1 && wind.info_no < 2007){
			if(wind.req_hyouji == (X-6)/36 )	sort_req((X-6)/36);
			else								wind.req_hyouji  = (X-6)/36;
			se_ok(6);
		}
		return 1;
	}


	for(int i=0;i<wind.req_m;i++){
		E = wind.req_list[i];
		if( T != emp[E].job ){
			T = emp[E].job;
			XP=0;
			YP++;
			if(YPP == YP){//�^�C�g������
				wind.info_no = 1000 + T;
				return 1;
			}
			YP++;
		}

		if(XP>=7){
			XP=0;
			YP++;
		}
		if(XPP == XP && YPP == YP){
			N = wind.req_list[i];
			wind.info_no = N;
			break;
		}
		XP++;
	}

	//���N���b�N�A�ʐ�
	//�E�h���b�O�{���N���b�N�A�ʐڂȂ��̗p
	if(N!=0 && Inp.m_LC == 1 ){
		//����or����ς݂Ȃ����
		emp[N].now_job = (emp[N].now_job + 2)%4;
		se_ok(3+emp[N].now_job/2*3);
	}
	return 1;
}
int FUN::window_s05(int X,int Y/*�l�����E�X��*/){

	int W_H = 78;//����
	int N;//�I���ʒu,�����Ȃ�������0
	int FN = -1,FW=0,FC=0,E=0;//�h���b�v�p�t�H���_�ԍ�
	if(X>6 && X<40) N = 0;//�^�u�̈ʒu
	else			N = X/40;//�^�u�ł͂Ȃ�
	int WN = -1;//�C���t�H�ʒu
	int i=0,I=0,S=0;

	if(Y>6 && Y<38){//�\������
		wind.info_no = 2000+(X-6)/36;//�\�[�g�^�u
		if(Inp.m_LC == 1){
			if( (X-6)/36 >6 )						wind.ts_hyouji = 1 - wind.ts_hyouji;
			else if(wind.emp_hyouji == (X-6)/36 )	sort_emp(0);
			else									wind.emp_hyouji  = (X-6)/36;
			if(data.taiguu_ok == 0) wind.ts_hyouji = 0;
			se_ok(6);
		}
	}

	if(Y<74){
		if(Y>=38)wind.info_no = 2009;
		return 1;
	}

	//�ʒu����
	if(wind.ts_hyouji == 0){
		//�V�t�g
		for(i=WEP_M;i<WEP_M+4;i++){
			FN = i;
			if(Y+wind.scr[4] > W_H && Y+wind.scr[4] < W_H+35 && N==0){//�^�u����
				WN = 1000+i;
				break;
			}else if(Y+wind.scr[4]>W_H && Y+wind.scr[4]< W_H + wind.efold_h[i] && N!= 0){
				N += (Y-W_H+wind.scr[4])/40*7;//�t�H���_���ł̈ʒu�Čv�Z
				if(N<=wind.efold_cnt[i]){//�t�H���_���ŃA�C�R������			
					WN = wind.efold_mem[i][N-1];
				}
				break;
			}
			W_H += wind.efold_h[i] +4;
		}
	}else{
		//�ҋ�
		for(i=0;i<4;i++){//
			FN = i;
			if(Y+wind.scr[4] > W_H && Y+wind.scr[4] < W_H+35 && N==0){//�^�u����
				WN = 1000+i+ wind.ts_hyouji*1010;
				break;
			}else if(Y+wind.scr[4]>W_H && Y+wind.scr[4]< W_H + wind.tfold_h[i][0] && N!= 0){
				N += (Y-W_H+wind.scr[4])/40*7;//�t�H���_���ł̈ʒu�Čv�Z
				if(N<=wind.tfold_cnt[i][0]){
					WN = wind.tfold_mem[i][0][N-1];
				}
				break;
			}
			W_H += wind.tfold_h[i][0] +4;
		}
	}

	wind.info_no = WN;

	//����
	if(WN != -1 && WN <1000){
		if(Inp.m_LC == 1){//�͂�
			Inp.d_no = WN;
			Inp.d_type = 5;
			se_ok(6);
		}
	}


	//�h���b�v����
	if(Inp.m_LD == 1  && Inp.d_no>=0 && FN != -1){//�^�u�ȊO�Ƀh���b�v
		if( Inp.d_no < 1000 && Inp.d_type == 5 ){//�]�ƈ��h���b�v
			list_de(Inp.d_no);//���X�g����폜
			if(wind.ts_hyouji == 0)	emp[Inp.d_no].shift_n = FN-WEP_M;
			else					emp[Inp.d_no].chan_tai = FN;
			list_pe(Inp.d_no);//���X�g�ɒǉ�
			se_ok(3);
		}
		if( Inp.d_no <1000 && ( Inp.d_type == 2 || Inp.d_type ==3 ) && WN>=0 && wind.ts_hyouji == 0){//����n�h���b�v
			if(WN<1000){
				list_de(WN);//���X�g����폜
				emp[WN].shift_n = wep[Inp.d_no].type;
				list_pe(WN);//���X�g����폜
				se_ok(3);
			}
		}
	}

	return 1;
}
int FUN::window_s06(int X,int Y/*�l�����E�E�l*/){

	int W_H = 78;//����
	int N;//�I���ʒu,�����Ȃ�������0
	int FN = -1,FW=0,FC=0,E=0;//�h���b�v�p�t�H���_�ԍ�
	if(X>6 && X<40) N = 0;//�^�u�̈ʒu
	else			N = X/40;//�^�u�ł͂Ȃ�
	int WN = -1;//�C���t�H�ʒu
	int i=0;

	if(Y>6 && Y<38){//�\������
		wind.info_no = 2000+(X-6)/36;//�\�[�g�^�u
		if(Inp.m_LC == 1){
			if( (X-6)/36 >6 )						wind.ts_hyouji = 1 - wind.ts_hyouji;
			else if(wind.emp_hyouji == (X-6)/36 )	sort_emp(1);
			else									wind.emp_hyouji  = (X-6)/36;
			if(data.taiguu_ok == 0) wind.ts_hyouji = 0;
			se_ok(6);
		}
	}
	if(Y>40 && Y<78){//�c�Ǝ���
		i = (X-36)/3;
		if(Inp.m_LC == 1 && X>240 && X <330 && wind.ok[9]==1){
			if(X<285) shop[P].koubou_n-=3;
			else	  shop[P].koubou_n+=3;
		}
		if(shop[P].koubou_n<48 - 12*shop[P].mana_cnt[4]) shop[P].koubou_n=48 - 12*shop[P].mana_cnt[4];
		if(shop[P].koubou_n>shop[P].zangyou			   ) shop[P].koubou_n=shop[P].zangyou;
	}

	if(Y<78){
		if(Y>=38)wind.info_no = 2009;
		return 1;
	}

	//�ʒu����
	if(wind.ts_hyouji == 0){
		for(i=0;i<WEP_M;i++){//�V�t�g
			FN = wind.efold_s[i];
			if(FN <0){
				i = -1;
				break;
			}
			if(Y+wind.scr[5] > W_H && Y+wind.scr[5] < W_H+wind.efold_h[FN] && N==0){//�^�u����
				WN = 1000+i;
				break;
			}else if(Y+wind.scr[5]>W_H && Y+wind.scr[5]< W_H + wind.efold_h[FN] && N!= 0){
				N += (Y-W_H+wind.scr[5])/40*7;//�t�H���_���ł̈ʒu�Čv�Z
				if(N<=wind.efold_cnt[FN]){		
					WN = wind.efold_mem[FN][N-1];
				}else WN = 1000+i;//�^�u�h���b�O�Ɠ���
				break;
			}
			W_H += wind.efold_h[FN] +4;
		}
	}else{
		for(i=0;i<4;i++){//�ҋ�
			FN = i;
			if(Y+wind.scr[4] > W_H && Y+wind.scr[4] < W_H+35 && N==0){//�^�u����
				WN = 2010+i;
				break;
			}else if(Y+wind.scr[4]>W_H && Y+wind.scr[4]< W_H + wind.tfold_h[i][1] && N!= 0){
				N += (Y-W_H+wind.scr[4])/40*7;//�t�H���_���ł̈ʒu�Čv�Z
				if(N<=wind.tfold_cnt[i][1]){
					WN = wind.tfold_mem[i][1][N-1];
				}
				break;
			}
			W_H += wind.tfold_h[i][1] +4;
		}
	}
	wind.info_no = WN;

	//�͂ޑ���
	if(WN != -1 && WN < 2000){
		if(Inp.m_LC == 1){
			Inp.d_no = WN;
			Inp.d_type = 6;
			se_ok(6);
		}
	}
	//�t�H���_�����
	if(Inp.m_LC == 1 && WN >= 1000 && wind.ts_hyouji == 0){
		if(wind.efold_cnt[FN]<=0 && X>300 && X<320){
			list_df(wind.efold_s[WN-1000]);
			Inp.d_no = 0;
			Inp.d_type = 0;
			wind.info_no = -1;
			return 1;
		}
	}
	//�h���b�v����
	if(Inp.m_LD == 1 && FN != -1  && Inp.d_no>=0){
		//�^�u�ȊO�Ƀh���b�v
		if( Inp.d_no < 1000 && Inp.d_type == 6 ){//�]�ƈ��h���b�v			
			list_de(Inp.d_no);//���X�g����폜
			if(wind.ts_hyouji == 0) emp[Inp.d_no].shift_n = FN;
			else					emp[Inp.d_no].chan_tai = FN;
			list_pe(Inp.d_no);//���X�g�ɒǉ�
			se_ok(3);
		}
		if(wind.ts_hyouji == 1) return 1;

		if(WN>=0 && WN<1000){//����n�h���b�v
			if(Inp.d_no <1000 && ( Inp.d_type == 2 || Inp.d_type ==3 ) ){//����h���b�v
				if(wind.efold_cnt[Inp.d_no]<3 || shop[P].wep_cre[Inp.d_no]==2){
					list_de(WN);//���X�g����폜
					emp[WN].shift_n = Inp.d_no;
					list_pe(WN);//���X�g����폜
					se_ok(3);
				}
			}
			if( Inp.d_no>=1000){//����^�u��l�Ƀh���b�v
				if(wind.efold_cnt[Inp.d_no-1000]<3 || shop[P].wep_cre[Inp.d_no-1000]==2){
					list_de(WN);//���X�g����폜
					emp[WN].shift_n = wind.efold_s[Inp.d_no-1000];
					list_pe(WN);//���X�g����폜
					se_ok(3);
				}
			}
		}

		if(WN>=1000){//����^�u�𕐊�^�u�Ƀh���b�v
			if(Inp.d_no <1000 && ( Inp.d_type == 2 || Inp.d_type ==3 ) && FN != Inp.d_no){//����h���b�v//�����o�[�S���ύX		
				for(i=0;i<EMP_M;i++){
					if(wind.efold_cnt[Inp.d_no]>=3 && shop[P].wep_cre[Inp.d_no]!=2) break;
					if(FN == emp[i].shift_n && emp[i].now_job== 1 && emp[i].job==1 && emp[i].shop_n==P){
						list_de(i);//���X�g����폜
						emp[i].shift_n = Inp.d_no;
						list_pe(i);//���X�g����폜
					}
				}
				se_ok(3);
			}
			if(Inp.d_no>=1000){
				wind.efold_s[i] = wind.efold_s[Inp.d_no-1000];
				wind.efold_s[Inp.d_no-1000] = FN;
				se_ok(3);
			}
		}
	}

	return 1;
}
int FUN::window_s07(int X,int Y/*�X�܏��*/){

	wind.info_no = (Y+ wind.scr[6] -6) /27;

	int XP = 0,YP = 330-wind.scr[6]+135,CNT = 0;
	for(int M=0;M<MANA_M;M++){
		if(M % 60 == 0){//���x���\��
			if(CNT > 0) YP += 40;
			CNT = 0;
			if( range2(0,YP,300,30) == 1 ){
				wind.info_no = 2000 + M / 60;
				return 1;
			}
			XP=0;
			YP+=30;
		}

		if(shop[P].mana_cnt[M] > 0 && mana[M].seido==1){
			if(XP >= 240){
				XP  = 0;
				YP += 40;
			}
			if(range2(XP+20,YP,40,40) == 1){
				wind.info_no = 1000+M;
				return 1;
			}
			XP+=40;
			CNT = 1;
		}

	}
	return 1;
}
int FUN::window_s08(int X,int Y/*�s�����O*/){

	if(Y>6 && Y<38)
	{//�\������

		wind.info_no = 1000+(X-6)/54;//�\�[�g�^�u

		if(Inp.m_LC == 1 && wind.info_no < 1001 + data.shop_cnt)
		{
			logu.mode = (X-6)/54;
			se_ok(6);
		}else{
			wind.info_no = 1000;			
		}
		return 1;
	}

	wind.info_no = (Y+ wind.scr[7]-4)/24;

	return 1;
}
int FUN::window_s09(int X,int Y/*���x�A�V�F�A���*/){
	int N = -1;

	//�\�[�g����
	if(Y>6 && Y<38){
		if(X>6+36*0  && X<38+36*0 ) N = 0;//�N
		if(X>6+36*1  && X<38+36*1 ) N = 1;//��
		if(X>6+36*2  && X<38+36*2 ) N = 2;//��
		if(X>212  && X<272 && wind.syu_set !=2)	N = 3;//�ڍו\��
		wind.info_no = N;
		if(Inp.m_LC == 1){
			switch(N){
				case 0:
				case 1:
				case 2:
					wind.syu_set = N;
					se_ok(6);
				break;
				case 3:
					wind.syousai_hyouji = 1;//�ڍו\�����[�h
					opt.speed = 0;
					wind.graph_hyouuji = 0;
				break;
			}
		}
	}else if(Y>45 && Y<85){
		if(Y>50 && Y<76 && X>215 && X<265 && Inp.m_LC == 1){
			wind.syu_now = (wind.syu_now+1)%2;
			se_ok(6);
		}
		if(Y<65) N= 1;
		else	 N=-1;
		if(Inp.m_LC == 1 || Inp.m_LG%(20*max(opt.speed,1)) == 20*max(opt.speed,1) -1 ){
			if(X>30  && X<70  && data.day>=336)						{wind.syu_now = 0;wind.syu_day +=N*336;se_ok(6);}
			if(X>95  && X<135 && wind.syu_set>0 && data.day>=28  )	{wind.syu_now = 0;wind.syu_day +=N*28;se_ok(6);}
			if(X>155 && X<195 && wind.syu_set>1 )					{wind.syu_now = 0;wind.syu_day +=N;se_ok(6);}
		}
	}

	if(Y>45 && Y<85){
		wind.info_no = 4;
	}

	if(wind.syu_day < 0)		wind.syu_day = min(data.day,DAY_M-1);
	if(wind.syu_day > data.day || wind.syu_day > DAY_M-1) wind.syu_day = 0;

	wind.syu_year = wind.syu_day/336;//�N���I�[�o�[
	wind.syu_mon  = wind.syu_day/28%12;//�N���I�[�o�[

	if(wind.syu_now == 1){
		if(data.day < DAY_M){
			wind.syu_year = data.day/336;//�N���I�[�o�[
			wind.syu_mon  = data.mon%12;//�N���I�[�o�[
			wind.syu_day  = data.day;//�N���I�[�o�[
		}else{
			wind.syu_year = YEAR_M-1;//�N���I�[�o�[
			wind.syu_mon  = 11;//�N���I�[�o�[
			wind.syu_day  = data.day-1;//�N���I�[�o�[
		}
	}

	if(Y+wind.scr[8]-85>0){
		wind.info_no = (Y+wind.scr[8]-85)/30+5;
	}

	return 1;
}
int FUN::window_s10(int X,int Y/*�o�c�헪�E�B���h�E*/){

	int N = -1;//�I�����X�g�ʒu
	int XPP = X/40;
	int XP  = 0;
	int YPP = Y;
	int YP  = -wind.scr[9] + 38;
	//�E�h���b�Oor���N���b�N


	if(Y>8 && Y<40){//�\������
		wind.info_no = 3000+(X-6)/36;//�\�[�g�^�u
		if(Inp.m_LC == 1 && wind.info_no < 3008){
			if(wind.info_no >= 3006 )	wind.mana_rock = 1 - wind.mana_rock;
			else						wind.mana_hyouji  = (X-6)/36;
			fun.list_sort();
			se_ok(6);
		}
		return 1;
	}

	if(Y<72){//�c��l�o�̏�
		wind.info_no = 2000;
		return 1;
	}


	int MR = 0;
	for(int i=0;i<wind.mana_m;i++){
		int M  = wind.mana_list[i];
		int MT = mana[wind.mana_list[i]].type;
		int MRR = 0;
		while(MR <= MT){
			if(MR != MT && wind.mana_hyouji != 5){
				MR = MT;
			}

			if(MRR == 0){
				YP += 50;
				MRR = 1;
			}
			XP=0;
			if(YPP >YP && YPP<YP+30){//�^�u�̏�
				wind.info_no = 1000 + MR;
				return 1;
			}
			YP+=30;
			MR++;
		}

		if(XP>=7){
			XP=0;
			YP+=40;
		}
		if(XPP == XP && YPP > YP && YPP <YP+40){
			N = M;
			wind.info_no = N;
			break;
		}
		XP++;
	}


	if(Y>44 && N>0 && Inp.m_LC == 1){
		if(shop[P].mana_ok[N] != 1){
			se_ok(6);//�g�p�s�\
		}else if(shop[P].use_mana != N){
			shop[P].use_mana = N;
			se_ok(3);
		}else{
			shop[P].use_mana =-1;
			se_ok(6);
		}
	}

	return 1;
}
int FUN::window_s11(int X,int Y/*���Z���*/){
	int N = (Y-10)/30+4;

	//�N���ύX
	if(Inp.m_RC == 1)
    {
		wind.syousai_hyouji = 0;
		opt.speed = 0;
	}

	if(Inp.m_LC == 1){//�O���t�\���ȊO�N���b�N

		if(Y>=-50 && Y<=0 && X>=0 && X<=600){//�^�C�g������
			if(X<=125 && X>= 75){
				if(wind.graph_hyouuji == 0){
					wind.syu_now = 0;
					if( wind.syu_set == 0 && data.day>=336) {wind.syu_day -=336;se_ok(6);}
					if( wind.syu_set == 1 && data.day>=28 ) {wind.syu_day -=28;se_ok(6);}
				}else{
					wind.graph_hyouuji--;
				}
			}
			if(X>=475 && X<= 525){
				if(wind.graph_hyouuji == 0){
					wind.syu_now = 0;
					if( wind.syu_set == 0 && data.day>=336) {wind.syu_day +=336;se_ok(6);}
					if( wind.syu_set == 1 && data.day>=28 ) {wind.syu_day +=28;se_ok(6);}
				}else{
					wind.graph_hyouuji++;
				}
			}
			if(X>=545 && X<= 595)
            {
				opt.speed = 0;
				wind.syousai_hyouji = 0;
			}


			if(wind.graph_hyouuji == 18)wind.graph_hyouuji = 34;
			if(wind.graph_hyouuji == 35)wind.graph_hyouuji = 19;

			if(wind.syu_day < 0)		wind.syu_day = data.day;
			if(wind.syu_day > data.day) wind.syu_day = 0;

			if(wind.syu_day > data.day){
				wind.syu_day = wind.syu_day%336;
			}

			wind.syu_year = wind.syu_day/336;//�N���I�[�o�[
			wind.syu_mon  = wind.syu_day/28%12;//�N���I�[�o�[

			return 1;
		}else if(X>=0 && X<600 && Y >= 0 && Y< 520){
			if(wind.graph_hyouuji == 0){
				wind.graph_hyouuji = N+14;
				wind.graph_hyouuji = max(19,wind.graph_hyouuji);
				wind.graph_hyouuji = min(35,wind.graph_hyouuji);
			}
			else						wind.graph_hyouuji = 0;
		}
	}

	if(wind.graph_hyouuji != 0){
		N = 21;
	}

	if(Y>=-50 && Y<=0 && X>=100 && X<=500){
		wind.info_no = 20;
		wind.info_t = 9;
	}else if(X>=40 && X<580 && Y >= 10 && Y< 520){//�w���v���ʔԍ�
		if(N == 4) N = 20;
		if(N>=18)  N +=4;
		wind.info_no = N;
		wind.info_t = 9;
	}

	return 1;
}
int FUN::list_sort(int R){
	//�e�E�B���h�E�̕\�����X�V
	int I,J;

	if(R==0){//�ʏ�
		//�J�����X�g//�J���ς݂̂�����
		for(I=0;I<wind.kai_m;I++){
			if(shop[P].wep_cre[wind.kai_list[I]] != 1){
				for(J=I;J<wind.kai_m-1;J++){
					wind.kai_list[J]   = wind.kai_list[J+1];
				}
				wind.kai_m--;
			}
		}
	}else{//���͐؂�ւ�
		//�J�������탊�X�g
		wind.kai_m = 0;

		//����t�H���_
		for(I=0;I<7;I++){
			wind.wfold_cnt[I] = 0;
			wind.wfold_h[I] = 40;
		}
		for(I=0;I<20;I++){
			wind.tfold_cnt[I%10][I/10] = 0;
			wind.tfold_h[I%10][I/10] = 40;
		}

		for(I=0;I<WEP_M;I++){
			wind.efold_s[I] = -1;
			if(shop[P].wep_cre[I] == 1){//�J�����X�g
				wind.kai_list[wind.kai_m] = I;
				wind.kai_m++;
				wind.wfold_list[1][wind.wfold_cnt[1]]=I;
				wind.wfold_cnt[1]++;
			}else if(shop[P].wep_cre[I] == 2){//���i���X�g
				wind.wfold_list[1][wind.wfold_cnt[1]]=I;
				wind.wfold_cnt[1]++;
			}
		}
		wind.wfold_h[0] = 40 + (wind.wfold_cnt[0]-1)/7*40;
		//�]�ƈ�
		for(int I=0;I<WEP_M+4;I++){
			wind.efold_h[I] = 40;
			wind.efold_cnt[I] = 0;
		}

		for(int I=0;I<shop[P].emp_cnt;I++){
			list_pe(shop[P].emp_list[I]);
		}
	}

	//���l���X�g
	wind.req_m=0;
	for(I=0;I<EMP_M;I++){
		if(emp[I].now_job!=3 && emp[I].now_job != 1 && emp[I].shop_n==P){//���Eor����
			wind.req_list[wind.req_m] = I;
			wind.req_m++;
		}
	}
	sort_req(0);//���x���Ő���

	//data.mana_index

	//�o�c�헪���X�g
	wind.mana_m = 0;
	for(int i=0;i<MANA_M;i++){
		int I = data.mana_index[i];

		if(shop[P].mana_rest[I] <= 0 ||  (shop[P].mana_ok[I] != 1 && wind.mana_rock == 0)) continue;
		//BW����
		if(shop[P].b_w < mana[I].b_w_d || shop[P].b_w > mana[I].b_w_u ) continue;

		if(wind.mana_hyouji != 5 && mana[I].type != wind.mana_hyouji) continue;
		wind.mana_list[wind.mana_m] = I;
		wind.mana_m ++;
	}

	return 1;
}
int FUN::list_dw(int W){
	int i,f,del=0;
	//���X�g����폜
	for(f=0;f<7;f++){
		for(i=0;i<wind.wfold_cnt[f];i++){
			if(wind.wfold_list[f][i] == W){
				wind.wfold_list[f][i]   = wind.wfold_list[f][i+1];
				wind.wfold_list[f][i+1] = W;
				del = 1;
			}
		}
		if(del == 1){
			wind.wfold_cnt[f]--;
			wind.wfold_h[f] = 40 + (wind.wfold_cnt[f]-1)/7*40;
			break;
		}
	}
	return 1;
}
int FUN::list_pw(int W){
	//�V���i�ɒǉ�
	wind.wfold_list[1][wind.wfold_cnt[1]] = W;
	wind.wfold_cnt[1]++;//
	wind.wfold_h[1] = 40 + (wind.wfold_cnt[1]-1)/7*40;
	return 1;
}
int FUN::list_mw(int W){
	int i,f,del;
	//���X�g����폜
	for(f=0,del=0;f<7;f++){
		for(i=0;i<wind.wfold_cnt[f];i++){
			if(wind.wfold_list[f][i] == Inp.d_no){
				wind.wfold_list[f][i]   = wind.wfold_list[f][i+1];
				wind.wfold_list[f][i+1] = Inp.d_no;
				del = 1;
			}
		}
		if(del == 1){
			wind.wfold_cnt[f]--;
			wind.wfold_h[f] = 40 + (wind.wfold_cnt[f]-1)/7*40;
			break;
		}
	}
	//���X�g�ɒǉ�
	if(W>=2 && W<=5){
		W = wep[Inp.d_no%WEP_M].type+2;
		if(Inp.d_no == NOU_NO) W = 1;//�_��̓u�b�N�}�[�N����
	}

	wind.wfold_list[W][wind.wfold_cnt[W]] = Inp.d_no;
	wind.wfold_cnt[W]++;
	wind.wfold_h[W] = 40 + (wind.wfold_cnt[W]-1)/7*40;

	return 1;
}
int FUN::list_de(int E){

	int i,N,F;
	int OK = 0;

	//���X�g����폜
	N = emp[E].shift_n + WEP_M*(1-emp[E].job);//0~399

	for(i=0;i<wind.efold_cnt[N];i++){
		if(wind.efold_mem[N][i] == E){
			wind.efold_mem[N][i]   = wind.efold_mem[N][i+1];
			wind.efold_mem[N][i+1] = E;
			OK=1;//�����ς�
		}
	}

	if(OK==1){//���ɂ�����t�H���_����폜
		wind.efold_cnt[N] --;
		wind.efold_h[N]	 = 40+(wind.efold_cnt[N]-1)/7*40;
	}

	OK = 0;
	//�ҋ��t�H���_����폜
	N = emp[E].chan_tai;
	F = emp[E].job;
	for(i=0;i<wind.tfold_cnt[N][F];i++){
		if(wind.tfold_mem[N][F][i] == E){
			wind.tfold_mem[N][F][i]   = wind.tfold_mem[N][F][i+1];
			wind.tfold_mem[N][F][i+1] = E;
			OK=1;//�����ς�
		}
	}

	if(OK==1){//���ɂ�����t�H���_����폜
		wind.tfold_cnt[N][F] --;
		wind.tfold_h[N][F]	 = 40+(wind.tfold_cnt[N][F]-1)/7*40;
	}

	return 1;
}
int FUN::list_pe(int E){
	//�l�����X�g�Ō���ɒǉ�
	int i;
	int OK = 0;
	int N;
	int F;
	//���X�g�ɒǉ�
	N = emp[E].shift_n + WEP_M*(1-emp[E].job);//400~404

	if(emp[E].job == 1){//�t�H���_�L������
		for(i=0;i<WEP_M;i++){
			if(wind.efold_s[i] == N){
				OK = 1;
				break;
			}else if(wind.efold_s[i] == -1){
				OK = -1;
				break;
			}
		}

		if( OK == -1){//�t�H���_�ǉ�
			for(F=WEP_M-1;F>0;F--){//�O���󂯂�
				wind.efold_s[F] = wind.efold_s[F-1];
			}
			wind.efold_s[0] = emp[E].shift_n;//�擪�ɒǉ�
		}
	}

	//���X�g�ɒǉ�
	//if(N > 804){
	//	E = 1;
	//}

	wind.efold_mem[N][wind.efold_cnt[N]] = E;
	wind.efold_cnt[N] ++;
	wind.efold_h[N] = 40+(wind.efold_cnt[N]-1)/7*40;

	//�ҋ��t�H���_�ɒǉ�
	N = emp[E].chan_tai;
	F = emp[E].job;
	wind.tfold_mem[N][F][wind.tfold_cnt[N][F]] = E;
	wind.tfold_cnt[N][F]++;
	wind.tfold_h[N][F] = 40+(wind.tfold_cnt[N][F]-1)/7*40;
	return 1;
}
int FUN::list_df(int F){
	//�t�H���_�̍폜
	int i,OK=0;

	for(i = 0;i<WEP_M-1;i++){//�폜���Ă���ȍ~����O�ɋl�߂�
		if(wind.efold_s[i] == F) OK = 1;
		if(OK == 0) continue;
		wind.efold_s[i] = wind.efold_s[i+1];
	}
	wind.efold_cnt[WEP_M-1] = -1;

	return 1;
}
int FUN::sort_wep(){
	//�e�t�H���_���Ƀ\�[�g
	int W,PPP,LOW,NO;

	for(int c = 0;c<7;c++){
		for(int i = 0;i<wind.wfold_cnt[c]-1;i++){
			LOW = 0;
			NO = i;
			for(int j=i;j<wind.wfold_cnt[c];j++){
				W = wind.wfold_list[c][j];
				switch(wind.wep_sort){
					case 0:PPP = int(wep[W].atk * shop[P].atk_j[W]);break;
					case 1:PPP = int(wep[W].dur * shop[P].dur_j[W]);break;//�ϋv
					case 2:PPP = int((wep[W].ninki[0] + wep[W].ninki[1] + wep[W].ninki[2]) * shop[P].ninki_j[W]);break;//�l�C
					case 3:PPP = int(wep[W].make_time * shop[P].time_j[W]);break;//�H��
					case 4:PPP = wep[W].price;break;//�l�i
					case 5:PPP = int(wep[W].price * (shop[P].price_rate - wep[W].seizou_cost * shop[P].cost_j[W] )/100);break;//�ׂ�
				}
				if(PPP > LOW){
					LOW = PPP;
					NO = j;
				}
			}
			if(NO != i){
				std::swap(wind.wfold_list[c][i],wind.wfold_list[c][NO]);
			}
			
		}
	}

	return 1;
}
int FUN::sort_emp(int J){

	int E,PPP,LOW,NO,WN;
	int R = wind.emp_hyouji;

	if(wind.ts_hyouji == 0){//�V�t�g���ёւ�
		if(J==0){//�X��
			for(int i=WEP_M;i<WEP_M+4;i++){
				for(int c=0;c<wind.efold_cnt[i];c++){
					LOW = 0;
					NO = c;
					for(int j=c;j<wind.efold_cnt[i];j++){
						E = wind.efold_mem[i][j];
						PPP = sort_emp_st(E,R);
						if(PPP>LOW){
							LOW = PPP;
							NO =j;
						}
					}
					if(NO != c) std::swap(wind.efold_mem[i][c],wind.efold_mem[i][NO]);
				}
			}
		}else{//�E�l
			for(int i=0;i<WEP_M;i++){
				WN = wind.efold_s[i];
				if(WN==-1) break;
				for(int c=0;c<wind.efold_cnt[WN];c++){
					LOW = 0;
					NO = c;
					for(int j=c;j<wind.efold_cnt[WN];j++){
						E = wind.efold_mem[WN][j];
						PPP = sort_emp_st(E,R);
						if(PPP>LOW){
							LOW = PPP;
							NO =j;
						}
					}
					if(NO != c) std::swap(wind.efold_mem[WN][c],wind.efold_mem[WN][NO]);
				}
			}
		}

	}else{//�ҋ��ύX
		for(int i = 0;i<10;i++){
			for(int c =0;c<wind.tfold_cnt[i][J] -1;c++){
				LOW = 0;
				NO = c;
				for(int j=c;j<wind.tfold_cnt[i][J];j++){
					E = wind.tfold_mem[i][J][j];
					PPP = sort_emp_st(E,R);
					if(PPP>LOW){
						LOW = PPP;
						NO =j;
					}
				}
				if(NO != c){
					std::swap(wind.tfold_mem[i][J][c],wind.tfold_mem[i][J][NO]);
				}
			}
		}
		//�ҋ��ύX�����܂�
	}



	return 1;
}
int FUN::sort_emp_st(int E,int R){

	switch(R){
		case 0:return emp[E].st[0];
		case 1:return emp[E].lv;
		case 2:return emp[E].st[1];
		case 3:return emp[E].st[2];
		case 4:return emp[E].pay_money;
		case 5:return int(emp[E].b_w);
		case 6:return emp[E].pay_money * 10 / max(emp[E].req_money,1);
	}

	return 0;
}
int FUN::sort_req(int R){

	int E,PPP,LOW,NO;

	if(R != -1){
		R = wind.req_hyouji;
	}
	
	for(int i = 0;i<wind.req_m - 1;i++){
		LOW = 0;
		NO = i;
		for(int j=i;j<wind.req_m;j++){
			E = wind.req_list[j];
			PPP = 10000-emp[E].job*10000;
			switch(R){
				case 0:PPP += emp[E].lv;					break;//LV
				case 1:PPP += emp[E].st[0] * emp[E].mensetu[0][P];break;//HP
				case 2:PPP += emp[E].st[1] * emp[E].mensetu[1][P];break;//�X�e1
				case 3:PPP += emp[E].st[2] * emp[E].mensetu[2][P];break;//�X�e2
				case 4:PPP += emp[E].skill * emp[E].mensetu[4][P] + emp[E].mensetu[4][P];break;//�X�L��
				case 5:PPP += emp[E].konjyou * emp[E].mensetu[3][P];break;//����
				case 6:PPP += emp[E].pay_money;break;//����
			}
			if(PPP > LOW){
				LOW = PPP;
				NO = j;
			}
		}
		if(NO != i){
			std::swap(wind.req_list[i],wind.req_list[NO]);
		}

	}
	return 1;
}
/*�c�ƃt�F�C�Y��������*/
int FUN::customer_act(/*�q����*/){

	for(int C=0;C<data.jinkou_max;C++){
		if(hun[C].life <= 0) continue;//���Sor���o�^
		if(hun[C].wait>0){//�ҋ@��or���ԊO
			hun[C].wait--;
			if(hun[C].act == 5 && hun[C].act_no == P && hun[C].wait<=30){
				hun[C].y--;
			}else if(hun[C].act == 4 && hun[C].act_no == P){
				hun[C].y++;
			}else hun[C].x+=hun[C].vx;
			continue;
		}else{
			if(hun[C].act==0)		 hun[C].select_act();//�s���I��
			else if(hun[C].act == 5) hun[C].shop_enter();//���X
			else					 hun[C].act_now();//�X���s��
			
		}
	}
	return 1;
}
int FUN::shop_act(/*�X�܏���*/){
	int S,H,C;
	//�X���̑ҋ@���Ԍ���
	for(S=0;S<SHOP_M;S++){
		for(H=0;H<shop[S].emp_cnt;H++){
			int E = shop[S].emp_list[H];
			if(emp[E].rest > 0){//�x�ݒ��͑Ή��s�\
				emp[E].wait=1;
				continue;
			}
			emp[E].wait--;
		}
	}

	//�q�֑Ή��\���`�F�b�N
	for(S=0;S<SHOP_M;S++){
		for(H=0;H<SHOP_SP;H++){
			if(shop[S].cust_list[H] <0 )continue;
			C = shop[S].cust_list[H];
			if(hun[C].act == 1 || hun[C].act == 3){//�qor�N���[�}�[�̂ݑΉ��\
				emp_act(S,C);
			}
		}
	}
	return 1;
}
int FUN::emp_act(int S,int C){
	//�V�t�g�������X�����烉���_���őI��
	//�������ALL���烉���_��
	int T[EMP_M];//�S�����X�g
	int TA[EMP_M];//�S�S�����X�g
	int TC=0,TAC=0,I,E;//�S���J�E���g

	for(I=0;I<shop[S].emp_cnt;I++){
		E=shop[S].emp_list[I];
		if(		emp[E].wait<= 0 //�ҋ@��
			&&	emp[E].job == 0 //�X�S��
			&&  emp[E].rest<= 0){//�x���Ŗ���
			if(emp[E].shift == hun[C].wep_t){//�S��
				T[TC] = E;
				TC++;
			}else{//�S���ȊO
				TA[TAC] = E;
				TAC++;
			}
		}
	}

	if(TC > 0){//�S����
		hun[C].taiou_emp(T[Rand(TC-1)],0);
	}else if(TAC > 0){//�S�S����
		hun[C].taiou_emp(TA[Rand(TAC-1)],1);
	}

	return 1;
}
int FUN::make_create(){

	int W,S,E,MT,CT,KT;

	//����̐����i�s�l�{
	for(S=0;S<data.shop_cnt;S++){
		if(data.time<4800 || data.time>4800+shop[P].koubou_t*100) continue;
		for(W=0;W<WEP_M;W++){

			if(shop[S].wep_make_now[W] <= 0) continue;
			shop[S].wep_make[W]   += shop[S].wep_make_now[W];
			shop[S].wep_kaiexp[W] += shop[S].wep_kai_now[W];

			KT = (500+shop[S].wep_kaicnt[W]*50) * 5400 * 30;
			CT = wep[W].create_time;
			MT = int(wep[W].make_time * 100 * shop[S].time_j[W]);
			
			if(shop[S].wep_kaiexp[W] > KT)shop[S].kairyou(W);
			if(shop[S].wep_make[W] >= CT && shop[S].wep_cre[W]!=2)		shop[S].kaihatu(W);
			else if(shop[S].wep_make[W] >= MT && shop[S].wep_cre[W]==2) shop[S].make(W);
		}

		if(data.time%100==0){
			for(W=0;W<shop[S].emp_cnt;W++){//�o���l����J�v�Z//55��
				E = shop[S].emp_list[W];
				if(emp[E].job == 1 && emp[E].rest<1 && emp[E].shift>0){//�H�[

					emp[E].hp_lose(50);
					emp[E].exp+=int(shop[S].lv_ave*5);
					emp[E].lv_up();
				}
			}
			for(W=0;W<3;W++){
				shop[S].create_exp[W] += shop[S].create_get[W];
				if(shop[S].create_lv[W] == 50) continue;
				//�J�����x���㏸
				if(shop[S].create_exp[W] > (shop[S].create_lv[W]+7) * WEP_EXP_RATE){
					shop[S].create_exp[W] -= (shop[S].create_lv[W]+7) * WEP_EXP_RATE;
					shop[S].create_lv[W] ++;
					shop[S].syou_mp[181 + W]++;
					shop[S].syou_money[181 + W] += 100;
					if(shop[S].mana_cnt[M_NTEC]>0)shop[S].hirameki_dayb += 10;
				}
			}
		}
	}

	return 1;
}
/*�����q�����퓬�n*/
int LOG::add(const char* M,int T,int S/*���O�ǉ�*/){

	if( T== 13 && S != P && S != 5) return 1;

	logu.log.reserve(logu.cnt+1);

	logu.log.push_back(LOGG());

	logu.log[logu.cnt].date = data.day;
	logu.log[logu.cnt].shop = S;
	logu.log[logu.cnt].type = T;
	//logu.log[logu.cnt].str = M;
	sprintf_s(logu.log[logu.cnt].str,M);

	logu.cnt++;

	return 1;
}
int FUN::zaiko_cnt(/*�݌ɐ��Čv�Z*/){
	//�e�V���b�v�̍݌ɐ����v�Z����
	int S,W,SC[5];

	for(S=0;S<SHOP_M;S++){
		SC[S] = shop[S].tana_now;

		shop[S].souko_now=0;
		shop[S].tana_now=0;
		shop[S].tana_now_t[0]=0;
		shop[S].tana_now_t[1]=0;
		shop[S].tana_now_t[2]=0;
		shop[S].tana_now_t[3]=0;

		for(W=0;W<WEP_M;W++){
			if(shop[S].wep_rest[W]<=0)continue;
			shop[S].souko_now += shop[S].wep_rest[W];
			if(W == NOU_NO) continue;
			shop[S].tana_now++;
			shop[S].tana_now_t[wep[W].type]++;
		}

		if( SC[S] != shop[S].tana_now){
			SC[0] = -1;
		}
	}

	return SC[0];
}
int FUN::sell_data_cul(int N/*���x���v�Z*/){
	int i,R,S,T,HL[16];

	shop[P].kabu_mon[data.mon] = (int)shop[P].kabu_price;
	data.jinkou_mon[data.mon]  = data.jinkou;

	if(N==2){
		for(i=0;i<12;i++){
			HL[i] = wind.syu_hyouji[i];
		}
		for(i=0;i<4;i++){
			HL[i+12] = wind.shear_s[P][i];
		}
	}

	for(i=0;i<11;i++){
		wind.syu_hyouji[i]=0;
	}

	for(T=0;T<4;T++){
		for(S=0;S<SHOP_M;S++){
			wind.shear_p[S][T]  = 0;
			wind.shear_s[S][T]  = 0;
		}
		wind.shear_t[T]  = 0;
	}

	switch(wind.syu_set){
		case 0://�N
			if(N!=1)	R = wind.syu_year * 12;
			else		R = wind.syu_year * 12 - 12;//�O�N
			for(i=R;i<R+12;i++){
				wind.syu_hyouji[0] += shop[P].sellc_mon[i];
				wind.syu_hyouji[1] += shop[P].sell_mon[i];
				wind.syu_hyouji[2] += shop[P].cust_mon[i];
				wind.syu_hyouji[3] += shop[P].seizc_mon[i];
				wind.syu_hyouji[4] += shop[P].seiz_mon[i];
				for(T=0;T<4;T++){
					for(S=0;S<SHOP_M;S++){
						wind.shear_s[S][T] +=shop[S].shera_wepm[i][T];
						wind.shear_t[T]    +=shop[S].shera_wepm[i][T];
					}
				}
				wind.syu_hyouji[5] += shop[P].emp_mon[i];
				wind.syu_hyouji[6] += shop[P].manege_mon[i];
				wind.syu_hyouji[7] += shop[P].etc_mon[i];
				wind.syu_hyouji[8] += shop[P].incom_mon[i];
				wind.syu_hyouji[9] += shop[P].total_mon[i];
			}
			if( (wind.syu_year*12+11) * 28 < data.day){
				wind.syu_hyouji[10] = data.jinkou_mon[wind.syu_year*12+11];//�N���̐l���Ɗ���
				wind.syu_hyouji[11] = shop[P].kabu_mon[wind.syu_year*12+11];
			}else{
				wind.syu_hyouji[10] = data.jinkou_mon[data.day/28-1];//�N���̐l���Ɗ���
				wind.syu_hyouji[11] = shop[P].kabu_mon[data.day/28-1];
			}
		break;
		case 1://��
			if(N!=1)	R= wind.syu_year * 12 + wind.syu_mon;
			else		R= wind.syu_year * 12 + wind.syu_mon -1;//�O��
			for(T=0;T<4;T++){
				for(S=0;S<SHOP_M;S++){
					wind.shear_s[S][T] +=shop[S].shera_wepm[R][T];
					wind.shear_t[T]    +=shop[S].shera_wepm[R][T];
				}
			}
			wind.syu_hyouji[0] = shop[P].sellc_mon[R];
			wind.syu_hyouji[1] = shop[P].sell_mon[R];
			wind.syu_hyouji[2] = shop[P].cust_mon[R];
			wind.syu_hyouji[3] = shop[P].seizc_mon[R];
			wind.syu_hyouji[4] = shop[P].seiz_mon[R];
			wind.syu_hyouji[5] = shop[P].emp_mon[R];
			wind.syu_hyouji[6] = shop[P].manege_mon[R];
			wind.syu_hyouji[7] = shop[P].etc_mon[R];
			wind.syu_hyouji[8] = shop[P].incom_mon[R];
			wind.syu_hyouji[9] = shop[P].total_mon[R];
			wind.syu_hyouji[10] = data.jinkou_mon[R];
			wind.syu_hyouji[11] = shop[P].kabu_mon[R];
			break;
		case 2://��
			R = wind.syu_day;
			wind.syu_hyouji[0] = shop[P].sellc_day[R];
			wind.syu_hyouji[1] = shop[P].sell_day[R];
			wind.syu_hyouji[2] = shop[P].cust_day[R][0] + shop[P].cust_day[R][1] + shop[P].cust_day[R][2] + shop[P].cust_day[R][3];
			wind.syu_hyouji[3] = shop[P].seizc_day[R];
			wind.syu_hyouji[4] = shop[P].seiz_day[R];
			for(T=0;T<4;T++){
				for(S=0;S<SHOP_M;S++){
					wind.shear_s[S][T] +=shop[S].shera_wepd[R][T];
					wind.shear_t[T]    +=shop[S].shera_wepd[R][T];
				}
			}
		break;
	}
	//�V�F�A�����v�Z
	for(T=0;T<4;T++){
		for(S=0;S<SHOP_M;S++){
			if(wind.shear_s[S][T]<=0) continue;			
			wind.shear_p[S][T]  = int((double(wind.shear_s[S][T])/wind.shear_t[T])*1000);
		}
	}

	if(N==2){//�O�N����v�Z
		for(i=0;i<12;i++){
			if(HL[i] == 0)  wind.syu_pars[i] = 0;
			else			wind.syu_pars[i] = int(double(wind.syu_hyouji[i])*1000/HL[i]);
			if(wind.syu_pars[i]>99999) wind.syu_pars[i] = 99999;
		}
		for(i=0;i<4;i++){
			if(HL[i+12] == 0)   wind.syu_pars[i+12] = 0;
			else				wind.syu_pars[i+12] = int(double(wind.shear_s[P][i])*1000/HL[i+12]);
			if(wind.syu_pars[i+12]>99999) wind.syu_pars[i+12] = 99999;
		}

		if( wind.syu_year == 0 && (wind.syu_set == 0 || wind.syu_mon == 0) ){
			for(i=0;i<16;i++){
				wind.syu_pars[i] = 0;
			}
		}
	}

	return 1;
}
/*�C�x���g����*/
int FUN::eve_check(/*�C�x���g�������菈��*/){

	//�C�x���g����
	for(int i=0;i<100;i++){//�Ƃ肠�����^�[����������		
		if(data.mode != 0 && i >= 22 ) break;
		if(i < 20 && i !=  data.mode) continue;
		//0~19�e���[�h��p
		//20,21�Ղ�
		//22�`mode0��p�C�x���g
		EVE_FUN::Sin().eve_line = -1;//���������p
		if( 
			data.time/600 == eve[i].time_req &&
			data.day == eve[i].turn_req &&
			EVE_FUN::Sin().eve_ok(i) )
		{
			fun.eve_syori(i);
		}
	}

	return 1;
}
int FUN::eve_syori(int E/*�C�x���g��������*/){

	wind.info_on = 0;//�����E�B���h�E����
	opt.speed = 0;

	//����������
	int skip_cnt = 0;
	EVE_FUN::Sin().reset();	
	EVE_FUN::Sin().eve_next = 1;

	while(1)
	{
		fun.inp_check();//���̓`�F�b�N
		
		if(Inp.m_RO == 1 && Inp.m_LO == 1 ) break;

		if(Inp.m_RO == 1)
		{
			skip_cnt++;
			if(EVE_FUN::Sin().eve_wait > 0)EVE_FUN::Sin().eve_wait -= 10;
			if(EVE_FUN::Sin().eve_wait<=0 && skip_cnt>=10)
			{
				EVE_FUN::Sin().eve_next = 1;
				skip_cnt=0;
			}
		}

		if( Inp.m_LC == 1  && EVE_FUN::Sin().eve_wait<=0)
		{
			EVE_FUN::Sin().eve_next = 1;
			skip_cnt = 0;
		}else{
			if(EVE_FUN::Sin().eve_wait>0) EVE_FUN::Sin().eve_wait --;
		}

		bool isMoved = true;
		for( int i=0;i<36;i++)
		{
			if( act[i]->mx != 0 || act[i]->my != 0 ) isMoved = false;
		}

		if( EVE_FUN::Sin().eve_wait<=0 && EVE_FUN::Sin().eve_next == 1 && isMoved)
		{
			EVE_FUN::Sin().eve_next = 0;
			for(int i=0;i<36;i++)
			{
				act[i]->emo = -1;
				act[i]->huki_w = 0;
			}
			EVE_FUN::Sin().eve_switch(E);
			EVE_FUN::Sin().eve_line++;
		}

		draw.drama();//�`��
		ScreenFlip();//��ʔ��f

		if( fun.err_c()== -1)
		{
			//�C�x���g�����I��
			break;
		}

		if( EVE_FUN::Sin().eve_end == 1) break;
	}

	//�C�x���g�I����
	data.eve_flag[E] = 1;//�C�x���g�t���O�n�m

	EVE_FUN::Sin().eve_efe( E );

	opt.speed = 0;

	return 1;
}
int FUN::eve_boom(){

	int N;
	while(1){
		N = fun.Rand(8) + 1;
		if(N != data.boom && N != 2){
			data.boom = N;
			data.boom_rest = 28;
			break;
		}
	}

	switch(data.boom){
		case  0:logu.add("�u�[�����Ȃ��I",13,5);break;
		case  1:logu.add("�n���^�[�ɂȂ�u�[���I",13,5);break;
		case  2:logu.add("�N���[�����u�[���I",13,5);break;
		case  3:logu.add("�����u�[���I",13,5);break;
		case  4:logu.add("�����u�[���I",13,5);break;
		case  5:logu.add("�����u�[���I",13,5);break;
		case  6:logu.add("�|���u�[���I",13,5);break;
		case  7:logu.add("�悻�����킪�u�[���I",13,5);break;
		case  8:logu.add("������ꕐ�킪�u�[���I",13,5);break;
		case  9:logu.add("�R�X�p���킪�u�[���I",13,5);break;		
	}

	return 1;
}
int FUN::input_pass(){
	char test[5];

	int X,Y,N;

	X = data.window_x/2-200;
	Y = data.window_y/2-60;

	draw.waku(X,Y,400,120,0);

	draw.mes(X+10,Y+10,"�p�X���[�h����͂��ĉ�����",color.siro,color.kuro,0);
	draw.mes(X+10,Y+30,"(ESC�ŃL�����Z���A�G���^�[�Ō���)",color.siro,color.kuro,0);

	if(KeyInputString( X+50 , Y+75 ,4 , test ,true ) == 1){
		//���̓`�F�b�N
		N = atoi(test);
		if(N == 4696){
			sys.pass_on = 1;
			medal_check();
			sys_save();
		}
	}

	return 1;
}
/*�V�X�e������*/
int FUN::inp_check(/*���̓`�F�b�N*/){

	int I;
	char Buf[256];
	//����`�F�b�N
	GetMousePoint( &Inp.m_x , &Inp.m_y ) ;

	if(Inp.m_x < 0)				Inp.m_x = 0;
	if(Inp.m_x > data.window_x)	Inp.m_x = data.window_x;
	if(Inp.m_y < 0)				Inp.m_y = 0;
	if(Inp.m_y > data.window_y)	Inp.m_y = data.window_y;

	Inp.m_H = GetMouseWheelRotVol() ;
	GetHitKeyStateAll( Buf ) ;

	if( ( GetMouseInput() & MOUSE_INPUT_LEFT ) != 0 ){// ������Ă���
		if(Inp.m_LO==0)Inp.m_LC=1;
		else		 Inp.m_LC=0;
		Inp.m_LO=1;
		Inp.m_LD=0;
		Inp.m_LG++;
	}else{
		Inp.m_LD=Inp.m_LO;
		Inp.m_LC=0;// ������Ă��Ȃ�
		Inp.m_LO=0;
		Inp.m_LG=0;
	}

	if( ( GetMouseInput() & MOUSE_INPUT_RIGHT ) != 0 ){// ������Ă���
		if(Inp.m_RO==0)Inp.m_RC=1;
		else		 Inp.m_RC=0;
		Inp.m_RO=1;
		Inp.m_RD=0;
		Inp.m_RG++;
	}else{
		Inp.m_RD=Inp.m_RO;
		Inp.m_RC=0;// ������Ă��Ȃ�
		Inp.m_RO=0;
		Inp.m_RG=0;
	}
	
	//�L�[����
	for(I=0;I<256;I++){
		Inp.p_k[I]=0;
		if( Buf[ I ] == 1 ){
			if(Inp.d_k[I]==0)Inp.p_k[I]=1;
			Inp.d_k[I]=1;
		}else	Inp.d_k[I]=0;
	}
	return 1;
}
int FUN::err_c(/*�G���[�`�F�b�N*/){

	if( ProcessMessage() == -1 || CheckHitKey( KEY_INPUT_ESCAPE ) == 1){//ESC�������G���[�ŏI��
		return -1;
	}

	return 1;
}
int FUN::se_ok(int S/*���ʉ�*/){

	if(opt.wev_size<=0)return 1;
	PlaySoundMem( sou.se[S] , DX_PLAYTYPE_BACK ) ;
	return 1;
}
int FUN::bgm_ok(int M/*�a�f�l*/){

	switch(M){
		case 0:PlayMusic( "File/music/c18.mp3" , DX_PLAYTYPE_LOOP ) ;break;
		case 1:PlayMusic( "File/music/v4.mp3" , DX_PLAYTYPE_LOOP ) ;break;
	}
	SetVolumeMusic( opt.bgm_size*opt.bgm_size*256/10000 ) ;

	return 1;
}
#define NN 624
#define MM 397
#define MATRIX_A 0x9908b0dfUL   /* constant vector a */
#define UPPER_MASK 0x80000000UL /* most significant w-r bits */
#define LOWER_MASK 0x7fffffffUL /* least significant r bits */
static unsigned long mt[NN]; /* the array for the state vector  */
static int mti=NN+1; /* mti==N+1 means mt[N] is not initialized */
int FUN::Rand(int R){

    unsigned long y;
    static unsigned long mag01[2]={0x0UL, MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */

    if (mti >= NN) { /* generate N words at one time */
        int kk;

        if (mti == NN+1)   /* if init_genRand() has not been called, */
            set_rand(5489UL); /* a default initial seed is used */

        for (kk=0;kk<NN-MM;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+MM] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        for (;kk<NN-1;kk++) {
            y = (mt[kk]&UPPER_MASK)|(mt[kk+1]&LOWER_MASK);
            mt[kk] = mt[kk+(MM-NN)] ^ (y >> 1) ^ mag01[y & 0x1UL];
        }
        y = (mt[NN-1]&UPPER_MASK)|(mt[0]&LOWER_MASK);
        mt[NN-1] = mt[MM-1] ^ (y >> 1) ^ mag01[y & 0x1UL];

        mti = 0;
    }
  
    y = mt[mti++];

    /* Tempering */
    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680UL;
    y ^= (y << 15) & 0xefc60000UL;
    y ^= (y >> 18);

	if(R<0)R=0;

    return (long)(y>>1)%(R+1);
}
int FUN::set_rand(unsigned long S){
	mt[0]= S & 0xffffffffUL;
    for (mti=1; mti<NN; mti++) {
        mt[mti] = 
	    (1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti); 
        /* See Knuth TAOCP Vol2. 3rd Ed. P.106 for multiplier. */
        /* In the previous versions, MSBs of the seed affect   */
        /* only MSBs of the array mt[].                        */
        /* 2002/01/09 modified by Makoto Matsumoto             */
        mt[mti] &= 0xffffffffUL;
        /* for >32 bit machines */
    }
	return 1;
}
int FUN::Max(int a,int b,int c,int d,int e,int f){

	int N = 0;
	int C = a;

	if(C < b){N = 1;C = b;}
	if(C < c){N = 2;C = c;}
	if(C < d){N = 3;C = d;}
	if(C < e){N = 4;C = e;}
	if(C < f){N = 5;C = f;}

	return N;
}
int FUN::Min(int a,int b,int c,int d,int e,int f){

	int N = 0;
	int C = a;

	if(C > b){N = 1;C = b;}
	if(C > c){N = 2;C = c;}
	if(C > d){N = 3;C = d;}
	if(C > e){N = 4;C = e;}
	if(C > f){N = 5;C = f;}

	return N;
}