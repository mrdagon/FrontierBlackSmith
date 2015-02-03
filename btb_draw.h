#pragma once

#include <string>
#include <list>
#include <sstream>
int DRA::work(/*�o�c���C��*/){

	//�n�}�Ə㉺�^�O�̕\��
	draw.wmap();
	//�E�B���h�E�̕\��
	int i,W;

	for(i=11;i>=0;i--){
		if(wind.on[11] == 1) break;//�n�}
		W=wind.hide[i];
		if(wind.on[W]==0)continue;
		//�E�B���h�E�\��
		if(opt.win_skin==0){
			waku(wind.x[W],wind.y[W],wind.sx[W],32,5);
			waku(wind.x[W],wind.y[W]+28,wind.sx[W],wind.sy[W]-28,3);
		}else{
			waku(wind.x[W],wind.y[W]+28,wind.sx[W],wind.sy[W]-28,1);
			waku(wind.x[W],wind.y[W],wind.sx[W],32,0);
		}
		//�E�B���h�E�A�C�R���\��
		waku_c(wind.x[W]+6,wind.y[W]+5,20,20,255,255,255);
		waku_c(wind.x[W]+wind.sx[W]-26,wind.y[W]+5,20,20,255,255,255);
		waku_c(wind.x[W]+wind.sx[W]-52,wind.y[W]+5,20,20,255,255,255);
		int ICO[11] = {5,6,95,8,9,10,11,12,13,14,86};
		DrawRotaGraph(wind.x[W]+16,wind.y[W]+15,1,0,gra.ico[ICO[W]],TRUE,0);
		DrawRotaGraph(wind.x[W]+wind.sx[W]-16,wind.y[W]+15,1,0,gra.ico[57],TRUE,0);//����
		DrawRotaGraph(wind.x[W]+wind.sx[W]-42,wind.y[W]+15,1,0,gra.ico[82],TRUE,0);//�g��k��
		if( W == 4 ) mes_bmf(wind.x[W]+20,wind.y[W]+18,"T",1);
		if( W == 5 ) mes_bmf(wind.x[W]+20,wind.y[W]+18,"S",1);
		//�ő偕�k��
		if(wind.scr_on[W]==1 && wind.sy[W]<wind.scrm[W]+38 && wind.sy[W] != wind.smini[W]){
			//�X�N���[���o�[�\��//�\���\�͈́Awind.sy[W]-45//-38
			waku(wind.x[W]+wind.sx[W]-20,wind.y[W]+32,16,wind.sy[W]-36,5);
			//�X�N���[���ʒu�v�Z
			int SY = wind.scr[W]*(wind.sy[W]-45)/wind.scrm[W];
			int SS = (wind.sy[W]-38)*(wind.sy[W]-45)/wind.scrm[W];
			if(SS<1)SS=1;
			DrawBox(wind.x[W]+wind.sx[W]-16,wind.y[W]+36+SY,wind.x[W]+wind.sx[W]-10 ,wind.y[W]+36+SY+SS,color.aka,1);
		}

		//�����\��
		mes(wind.x[W]+28,wind.y[W]+7,data.win_name[W].c_str(),color.siro,color.kuro,0);
		
		switch(W){
			case 0:draw.win_1b(wind.x[W],wind.y[W]+28);break;
			case 1:draw.win_2b(wind.x[W],wind.y[W]+28);break;
			case 2:draw.win_3b(wind.x[W],wind.y[W]+28);break;
			case 3:draw.win_4b(wind.x[W],wind.y[W]+28);break;
			case 4:draw.win_5b(wind.x[W],wind.y[W]+28);break;
			case 5:draw.win_6b(wind.x[W],wind.y[W]+28);break;
			case 6:draw.win_7b(wind.x[W],wind.y[W]+28);break;
			case 7:draw.win_8b(wind.x[W],wind.y[W]+28);break;
			case 8:draw.win_9b(wind.x[W],wind.y[W]+28);break;
			case 9:draw.win_10b(wind.x[W],wind.y[W]+28);break;
			case 10:draw.win_11b(wind.x[W],wind.y[W]+28);break;
		}
	}
	
	//�h���b�O�\��
	if(Inp.d_no>=0 && wind.syousai_hyouji == 0){
		if(Inp.d_type == 2 || Inp.d_type == 3){//����h���b�O
			draw.wep_icon(Inp.m_x,Inp.m_y,1.5,Inp.d_no);
		}else if(Inp.d_type == 5){//�X��
			DrawRotaGraph(Inp.m_x,Inp.m_y,3,0, gra.unit[emp[Inp.d_no].gra][1] ,TRUE,0);
		}else if(Inp.d_type == 6){//�E�l
			if(Inp.d_no<1000)DrawRotaGraph(Inp.m_x,Inp.m_y,3,0, gra.unit[emp[Inp.d_no].gra][1] ,TRUE,0);
			else draw.wep_icon(Inp.m_x,Inp.m_y,1.5,wind.efold_s[Inp.d_no-1000]);
		}
	}

	if(wind.syousai_hyouji > 0){//�ڍו\��
		if(wind.graph_hyouuji >= 1)	draw.waku_graph();
		else						draw.waku_syuusi();
	}

	//�_�C���N�g�w���v
	if(wind.info_on == 1)		win_help();//�_�C���N�g�w���v
	if(wind.info_taiguu >=0)    win_htai();//�ҋ��ω��l



	return 1;
}
//wmap�������̂ŒT��
int DRA::wmap(/*�n�}��*/){
	int XS=data.window_y/3*4;
	int YS=data.window_y;
	int R,G,B,i,D;
	int X[2],Y[2];

	//���ԂňÂ����ς��
	if(data.time < 4800){//�J�X�O
		R = 55 + (data.time-4200)/3;
		G = 55 + (data.time-4200)/3;
		B = 55 + (data.time-4200)/3;
	}else if(data.time < 10200){//5��
		R = 255;
		G = 255;
		B = 255;
	}else{
		R = max(255 - (data.time-10200)/3,0);
		G = max(255 - (data.time-10200)/3,0);
		B = max(255 - (data.time-10200)/3,0);
	}
	DrawBox(0,0,data.window_x,data.window_y,GetColor(R,G,B),1);

	if(data.wide == 1){
		DrawExtendGraph(0,96,data.window_y*4/3,data.window_y,gra.map,1);
	}else{
		DrawExtendGraph(0,96,data.window_y*4/3,data.window_y,gra.map,1);
	}
	SetDrawBright(R,G,B);

	//�o�H�\��
	for(D=0;D<100;D++){
		X[0] = dun[D].x;
		Y[0] = dun[D].y;
		for(i=0;i<5;i++){
			if(dun[D].root[i] == 0)break;//���[�g����
			if(dun[D].root_t[i] <= 0) continue;//�T���O
			X[1] = X[0]-(X[0]-dun[dun[D].root[i]].x)*dun[D].root_t[i]/dun[D].root_k[i];//�����v�Z
			Y[1] = Y[0]-(Y[0]-dun[dun[D].root[i]].y)*dun[D].root_t[i]/dun[D].root_k[i];

			if(dun[dun[D].root[i]].seek>0){//�ڕW�����ς�
				DrawLine(X[0],Y[0],X[1],Y[1],color.siro,2);
			}else{
				DrawLine(X[0],Y[0],X[1],Y[1],color.aka,1);
			}
		}
	}

	//�_���W�����\��
	for(i=0;i<100;i++){

		if(dun[i].seek<0) continue;

		if(dun[i].seek==0){
			SetDrawBlendMode( DX_BLENDMODE_ALPHA , 64 );//�ڕW���
			DrawRotaGraph(dun[i].x,dun[i].y,1,0,gra.move[dun[i].type],TRUE);
			SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
			continue;
		}

		if(dun[i].boss_hp<=0 || dun[i].seek<100){
			DrawRotaGraph(dun[i].x,dun[i].y,1,0,gra.move[dun[i].type+9],TRUE);//�p�Љ�
		}

		if(dun[i].seek<100){
			DrawRectGraph(dun[i].x-12,dun[i].y-12,0,0,24,6*(101-dun[i].seek)/25,gra.move[dun[i].type],TRUE,0);
		}
			
		if(dun[i].boss_hp>0 && dun[i].seek>=100){//�{�X�������
				DrawRotaGraph(dun[i].x	 ,dun[i].y	 ,1,0,gra.move[17],TRUE);
				DrawRectGraph(dun[i].x-12,dun[i].y-12,0,0,24,6*(dun[i].boss_hp*99/dun[i].boss_max+1)/25,gra.move[8],TRUE,0);
		}
		//�_���W����LV
		if(i>0)	suu_bmf(dun[i].x+8,dun[i].y-8,1,i,0);

	}
	SetDrawBright( 255,255,255 );

	//�e������
	int ccc[4] = {0,0,0,0};
	for(int i=0;i<data.jinkou_max;i++){
		if(hun[i].life>0){
			ccc[hun[i].wep_t]++;
		}
	}

	//��^�u
	waku(0,0,data.window_x,32,5);
	waku(0,32,600,64,3);
	if( data.window_x != 1024){
		waku(600,32,320,64,3);
		waku(920,32,data.window_x-920,64,3);
	}else{
		waku(600,32,124,64,3);
		waku(data.window_x-300,32,300,64,3);
	}

	waku(15,5,180,20,4);
	waku(225,5,80,20,4);
	waku(325,5,65,20,4);
	waku(410,5,65,20,4);
	waku(500,5,65,20,4);
	//waku(585,5,90,20,4);
	waku(695,5,110,20,4);
	waku(830,5,180,20,4);

	//�E�B���h�E�A�C�R��
	int ICO[12] = {5,6,95,8,9,10,11,12,13,14,86,98};
	for(int i=0;i<12;i++){
		waku_c(23+i*48-9*wind.on[i],
			 55-wind.on[i]*9,
			 18+wind.on[i]*18,
			 18+wind.on[i]*18,255,255-wind.on[i]*100,255-wind.on[i]*100);

		if(wind.ok[i]==0)	DrawRotaGraph(32+i*48,64,2,0,gra.ico[57],TRUE,0);
		else				DrawRotaGraph(32+i*48,64,1+wind.on[i],0,gra.ico[ICO[i]],TRUE,0);

		mes(18+i*48,40,data.win_name_s[i].c_str(),color.kuro,color.siro,2);
	}
	//�m���x������


	//�m���x�Q�[�W
	if( data.window_x != 1024){
		waku( 608,38,104,24,6);

		waku( 714,38,198,24,6);

		waku( 608,62,304,24,6);

		DrawRotaGraph(624,50,2,0,gra.ico[78],TRUE,0);

		mes(645,41,"�m���x",color.kuro,color.siro,0);

		int TX = (int)(shop[P].timeido / 10);
		if( TX > 300 ) TX = 300;

		for(int i=0;i<TX;i++){
			int color;
			int pp = (i%50) * 5;

			if( i < 50 )		color = GetColor(255,0,0);//�I�����W
			else if(i < 100)	color = GetColor(255,pp,0);//���F
			else if(i < 150)	color = GetColor(255 - pp,255,0);//��
			else if(i < 200)	color = GetColor(0  ,255 , pp);//��
			else if(i < 250)	color = GetColor(0, 255 - pp ,255);//��
			else				color = GetColor(0, 0 ,255);

			if(i== 0 || i == TX -1) DrawLine(612+i,66,612+i,82,color);
			else					DrawLine(612+i,65,612+i,83,color);
		}

		syou_bmf(870,50,(int)shop[P].timeido,0);
		mes(885,41,"�o",color.kuro,color.siro,0);
	}else{
		waku( 608,38,104,24,6);
		waku( 608,62,104,24,6);

		DrawRotaGraph(624,50,2,0,gra.ico[78],TRUE,0);

		//mes(645,41,"�m���x",color.kuro,color.siro,0);
		syou_bmf(700,50,(int)shop[P].timeido,0);

		int TX = (int)(shop[P].timeido / 30);
		if( TX > 100 ) TX = 100;

		for(int i=0;i<TX;i++){
			int color;
			int pp = (i%17) * 15;
			if( i < 17 )		color = GetColor(255,0,0);//�I�����W
			else if(i < 34)		color = GetColor(255, pp ,0);//���F
			else if(i < 51)		color = GetColor(255 - pp ,255,0);//��
			else if(i < 68)		color = GetColor(0  ,255 , pp );//��
			else if(i < 85)		color = GetColor(0, 255 - pp ,255);//��
			else				color = GetColor(0, 0 ,255);

			if(i== 0 || i == TX -1) DrawLine(610+i,66,610+i,82,color);
			else					DrawLine(610+i,65,610+i,83,color);
		}
	}

	//�w���v
	waku(data.window_x-280,46,36,36,7);
	DrawRotaGraph(data.window_x - 262,64,2,0,gra.ico[89],TRUE,0);//�w���v
	mes_bmf(data.window_x - 272,48,"help",1);

	//�Q�[���X�s�[�h
	waku( data.window_x-230,46,108,36,7);
	if(opt.speed == 0) waku_c(data.window_x-230      ,46,36,36,255,100,100);
	else               waku_c(data.window_x-230+36+18,46,36,36,255,100,100);

    //32x32
	DrawRotaGraph(data.window_x - 212    , 64 ,2,0,gra.ico[55],TRUE,0);
	DrawRotaGraph(data.window_x - 212+26 , 64 ,2,0,gra.ico[58],TRUE,0);
	DrawRotaGraph(data.window_x - 212+54 , 64 ,2,0,gra.ico[54],TRUE,0);
    DrawRotaGraph(data.window_x - 212+80 , 64 ,2,0,gra.ico[59],TRUE,0);


	mes_bmf(data.window_x - 170 ,48,"speed",1);

	suu_bmf(data.window_x - 153 ,70,2,opt.speed_max,2,7);
	mes_bmf(data.window_x - 170 ,74,"x",1);

	//suu_bmf(data.window_x - 171,70,2,opt.speed_def,2,5);
	//mes_bmf(data.window_x - 188,74,"x",1);

	mes_bmf(data.window_x - 223,74,"stop",1);

	//�I�v�V����
	waku(data.window_x-110,46,36,36,7);
	DrawRotaGraph(data.window_x - 92,64,2,0,gra.ico[79],TRUE,0);
	mes_bmf(data.window_x - 110,48,"option",1);
	//�^�C�g����
	waku(data.window_x-60,46,36,36,7);
	DrawRotaGraph(data.window_x - 42,64,2,0,gra.ico[65],TRUE,0);
	mes_bmf(data.window_x - 57,48,"title",1);

	char str[256];
	DrawRotaGraph(15,15,2,0,gra.ico[56],TRUE,0);
	sprintf_s(str,"%d�N %d�� %d��",200+data.day/336,1+data.mon%12,1+data.day%28);
	mes(30,6,str,color.siro,color.kuro,0);

	DrawRotaGraph(170,15,2,0,gra.ico[25+data.day%7],TRUE,0);
	//���v�A�C�R��
	DrawRotaGraph(225,15,2,0,gra.ico[77],TRUE,0);
	if(data.time<6000)		sprintf_s(str," %d",data.time/600);
	else					sprintf_s(str,"%d",data.time/600);
	mes(250,6,str,color.siro,color.kuro,0);
	if(data.time%60<30)	mes(270,6,":",color.siro,color.kuro,0);

	if(data.time%600<100)	sprintf_s(str," %d",data.time/10%60);
	else					sprintf_s(str,"%d",data.time/10%60);
	mes(280,6,str,color.siro,color.kuro,0);

	//�V�C�A�C�R��
	DrawRotaGraph(330,15,2,0,gra.ico[18+data.tenki],TRUE,0);
	switch(data.tenki){
		case 0:mes(350,6,"���V",color.siro,color.kuro,0);break;
		case 1:mes(350,6,"�ܓV",color.siro,color.kuro,0);break;
		case 2:mes(350,6,"�J�V",color.siro,color.kuro,0);break;
		case 3:mes(350,6,"���J",color.siro,color.kuro,0);break;
	}
	//�c�Ə�
	DrawRotaGraph(415,15,2,0,gra.ico[11],TRUE,0);

	int NO = 0;
	if(shop[P].kouji > 0){
		sprintf_s(str,"�H����");
		NO = shop[P].kouji % 10;
	}else if(shop[P].holiday >0){
		if(shop[P].teikyuu == data.day % 7)	sprintf_s(str,"��x");
		else								sprintf_s(str,"�Ջx");
	}else{
		if(shop[P].price_rate != 100) sprintf_s(str,"����");
		else						  sprintf_s(str,"�c��");
		NO = 100-shop[P].price_rate;
	}
	mes(435,6,str,color.siro,color.kuro,0);
	if(NO!=0)suu_bmf(470,22,2,NO,2);
	//���s
	DrawRotaGraph(500,15,2,0,gra.ico[35],TRUE,0);

	switch(data.boom){
		case  0:sprintf_s(str,"�Ȃ�");break;
		case  1:sprintf_s(str,"��l");break;
		case  2:sprintf_s(str,"�_�{");break;
		case  3:sprintf_s(str," �� ");break;
		case  4:sprintf_s(str," �� ");break;
		case  5:sprintf_s(str," �� ");break;
		case  6:sprintf_s(str," �|");break;
		case  7:sprintf_s(str,"����");break;
		case  8:sprintf_s(str,"�i�D");break;
		case  9:sprintf_s(str,"����");break;
	}
	mes(520,6,str,color.siro,color.kuro,0);

	//�l��
	DrawRotaGraph(700,15,2,0,gra.ico[5],TRUE,0);
	suu_bmf(770,16,2,data.jinkou,0);
	mes(782,6,"�l",color.siro,color.kuro,0);
	//����
	DrawRotaGraph(830,15,2,0,gra.ico[53],TRUE,0);
	//sprintf_s(str,"%d�f",shop[P].money);
	suu_bmf(978,16,2,int(shop[P].money),0);
	mes(990,6,"�f",color.siro,color.kuro,0);

	return 1;
}
int DRA::win_1b(/*�q���*/int X,int Y){

	int H;
	static double ber=9;

	//�X�N���[���ő�l�v�Z
	SetDrawArea(X+4,Y+4,X+wind.sx[0]-20,Y+112);

	for(H=999;H>=0;H--){
		if(shop[P].cust_list[H]>=0)break;
	}
	wind.scrm[0]=92+(H+1)*20;//�ő�X�N���[��

	//���q���v���ʉߐl��
	int i , YH=0;
	waku(X+30,Y+10,44,13,6);
	waku(X+83,Y+10,94,13,6);
	mes_bmf(X+42,Y+15,"now",1);
	mes_bmf(X+117,Y+15,"total",1);

	for(i=0;i<4;i++){
		YH+=20;
		//waku_c(X+7,Y+7+YH ,165,18,255,255,255);
		waku(X+7	,Y+7+YH ,18,18,6);	
		DrawRotaGraph(X+16,Y+14+YH,1,0,gra.ico[i],1,0);
		waku(X+27	,Y+7+YH ,50,18,6);	
		waku(X+80	,Y+7+YH ,100,18,6);
		mes(X+130,Y+8+YH,"/",color.siro,color.kuro,2);
		suu_bmf(X+65, Y+16+YH,1,shop[P].cust_cnt_t[i],0);//���ݐl��

		suu_bmf(X+120,Y+16+YH,1,shop[P].cust_day[data.day][i],0);//���v�q��
		suu_bmf(X+165,Y+16+YH,1, shop[0].cust_day[data.day][i] + shop[1].cust_day[data.day][i]
								+shop[2].cust_day[data.day][i] + shop[3].cust_day[data.day][i]
								+shop[4].cust_day[data.day][i] , 0);
	}

	//�q�̏��
	Y+=20;
	if(wind.sy[0]>165){
		SetDrawArea(X+4,Y+90,X+wind.sx[0]-20,Y+wind.sy[0]-60);
		for(int i=wind.scr[0]/20;i<(wind.sy[0]+wind.scr[0])/20;i++){
			H = shop[P].cust_list[i];
			if( H== -1)continue;
			waku(X+40,Y+98-wind.scr[0]+i*20,135,18,6);

			if(hun[H].act!=4){
				waku_c(X+42,Y+99-wind.scr[0]+i*20,hun[H].wait*131/hun[H].talk_max,16
					,(hun[H].act+2)%3/2*255,(hun[H].act+1)%3/2*255,hun[H].act%3/2*255);
			}
			DrawRotaGraph(X+15,Y+106-wind.scr[0]+i*20,1,0,gra.unit[jobs[hun[H].job].gra][1],1,0);
			DrawRotaGraph(X+31,Y+103-wind.scr[0]+i*20,1,0,gra.emo[16+hun[H].wep_t],1,0);
			suu_bmf(X+39,Y+110-wind.scr[0]+i*20,1,hun[H].lv,0);
		}
	}
	SetDrawArea(0,0,data.window_x,data.window_y);

	return 1;
}
int DRA::win_2b(/*������*/int X,int Y){

	//�ŏ㕔�Ƀ\�[�g�p�^�u
	int i,w,H,XC,YC,SH,IC;
	SetDrawArea(X+4,Y+4,X+wind.sx[1]-20,Y+wind.sy[1]-34);

	for(i=0;i<6;i++){
		if(wind.wep_sort!=i){
			waku(X+6+i*54,Y+6,50,32,8);
			SH = 0;
		}else{
			waku(X+6+i*54,Y+6,50,32,9);
			SH = 1;
		}
		switch(i){
			case 0: IC = 38;break;//�U����
			case 1: IC = 39;break;//�ϋv
			case 2: IC = 43;break;//�W�q��
			case 3: IC = 54;break;//�H��
			case 4: IC = 53;break;//���l
			case 5: IC = 32;break;//�ׂ�
		}
		DrawRotaGraph(X+31+54*i+SH,Y+22+SH,1+SH,0,gra.ico[IC],TRUE,0);
	}
	//�����舵������
	waku(X+6,Y+42,212,30,6);
	int LON[5];
	LON[0] = shop[P].tana_now_t[0]*210 / max(shop[P].tana_now,1);
	LON[1] = shop[P].tana_now_t[1]*210 / max(shop[P].tana_now,1);
	LON[2] = shop[P].tana_now_t[2]*210 / max(shop[P].tana_now,1);
	LON[3] = shop[P].tana_now_t[3]*210 / max(shop[P].tana_now,1);

	waku_c(X+7						,Y+43,LON[0],14,255,150,150);
	waku_c(X+7 +LON[0]				,Y+43,LON[1],14,150,255,150);
	waku_c(X+7 +LON[0]+LON[1]		,Y+43,LON[2],14,150,150,255);
	waku_c(X+7 +LON[0]+LON[1]+LON[2],Y+43,LON[3],14,120,120,120);
	if(LON[0]>0)DrawRotaGraph(X+7+LON[0]/2						,Y+49,1,0,gra.ico[0],1,0);
	if(LON[1]>0)DrawRotaGraph(X+7+LON[0]+LON[1]/2				,Y+49,1,0,gra.ico[1],1,0);
	if(LON[2]>0)DrawRotaGraph(X+7+LON[0]+LON[1]+LON[2]/2		,Y+49,1,0,gra.ico[2],1,0);
	if(LON[3]>0)DrawRotaGraph(X+7+LON[0]+LON[1]+LON[2]+LON[3]/2 ,Y+49,1,0,gra.ico[3],1,0);

	DrawRotaGraph(X+240 ,Y+49,1,0,gra.ico[43],1,0);
	mes(X+294,Y+42,"���",color.kuro,color.siro,2);
	suu_bmf(X+285,Y+50,2,shop[P].tana_now,0);

	//�݌Ɋ���
	for(i=0;i<4;i++)LON[i]=0;
	for(i=0;i<WEP_M;i++){
		LON[wep[i].type] += shop[P].wep_rest[i];
	}
	LON[0]-= shop[P].wep_rest[NOU_NO];//�_����������
	LON[4] = shop[P].wep_rest[NOU_NO];

	for(i=0;i<5;i++){
		LON[i] = LON[i]*210 / max(shop[P].souko_max,shop[P].souko_now);
	}

	if( shop[P].souko_now>=shop[P].souko_max ){

		while(1){
			if(LON[0]+LON[1]+LON[2]+LON[3]+LON[4] == 210){
				break;
			}else{
				if(LON[0]+LON[1]+LON[2]+LON[3]+LON[4] > 210) i = -1;
				else								         i =  1;

				if     (LON[0] > LON[1] && LON[0] > LON[2] && LON[0] > LON[3] && LON[0]>LON[4]) LON[0] += i;
				else if(LON[1] > LON[2] && LON[1] > LON[3] && LON[1] > LON[4])					LON[1] += i;
				else if(LON[2] > LON[3]	&& LON[2] > LON[4] )									LON[2] += i;
				else if(LON[3] > LON[4])														LON[3] += i;
				else																			LON[4] += i;
			}
		}
	}

	waku_c(X+7							   ,Y+57,LON[0],14,255,150,150);
	waku_c(X+7 +LON[0]					   ,Y+57,LON[1],14,150,255,150);
	waku_c(X+7 +LON[0]+LON[1]			   ,Y+57,LON[2],14,150,150,255);
	waku_c(X+7 +LON[0]+LON[1]+LON[2]	   ,Y+57,LON[3],14,120,120,120);
	waku_c(X+7 +LON[0]+LON[1]+LON[2]+LON[3],Y+57,LON[4],14,0,0,0);

	DrawRotaGraph(X+240 ,Y+64,1,0,gra.ico[61],1,0);
	mes(X+290,Y+57,"/",color.siro,color.kuro,2);
	if(shop[P].souko_now > shop[P].souko_max) SetDrawBright(255,100,100);
	suu_bmf(X+285,Y+65,1,shop[P].souko_now,0);
	if(shop[P].souko_now > shop[P].souko_max) SetDrawBright(255,255,255);
	suu_bmf(X+320,Y+65,1,shop[P].souko_max,0);

	//����t�H���_
	SetDrawArea(X+4,Y+76,X+wind.sx[1]-20,Y+wind.sy[1]-34);
	H=0;
	int WH = 290;
	for(i=0;i<7;i++){
		waku(6+X,78+Y-wind.scr[1]+H,40,30,6);
		if(i == 0) waku(36+X,78+Y-wind.scr[1]+H,5+40*shop[P].medama_max,wind.wfold_h[i],6);
		else	   waku(36+X,78+Y-wind.scr[1]+H,285,wind.wfold_h[i],6);
		

		switch(i){
			case 0:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[100],TRUE,0);break;//�ڋʏ��i
			case 1:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[22],TRUE,0);break;//�V���i
			case 2:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[0],TRUE,0);break;//��
			case 3:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[1],TRUE,0);break;//��
			case 4:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[2],TRUE,0);break;//��
			case 5:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[3],TRUE,0);break;//�|
			case 6:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[61],TRUE,0);break;//���̑�
		}
		XC=40+X;
		YC=H+Y+82-wind.scr[1];
		for(w=0;w<wind.wfold_cnt[i];w++){
			draw.win_2s(wind.wfold_list[i][w],XC,YC);
			XC+=40;
			if(w%7==6){
				XC=40+X;
				YC+=40;
			}
		}
		H +=wind.wfold_h[i]+4;
	}

	wind.scrm[1] = H + 76;

	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;
}
int DRA::win_3b(/*�X�ܕ��i*/int X,int Y){

	int WIDE = 2;
	int SG = shop[P].size;
	if(shop[P].kouji>0)
    {
        if(shop[P].size == 0 ) SG = 3;
        else                   SG = 4;
    }
	SetDrawArea(X+4,Y+4,X+wind.sx[2]-6,Y+wind.sy[2]-34);

	wind.smini[2] =240*WIDE+38;
	wind.smax[2] = 240*WIDE+38;
	wind.scrm[2] = 40*wind.kai_m;

	wind.sx[2] = 320*WIDE + 10;
	wind.sy[2] = 240*WIDE + 38;

	//���邳�ύX
	int R=255,G=255,B=255;

	if(data.time < 4800){//�J�X�O
		R= 55 + (data.time-4200)/3;G = R; B = R;
	}else if(data.time < 10200){//5��
		R=255,G=255,B=255;
	}else{
		R = max(255 - (data.time-10200)/3,0);G = R;B = R;
	}

	switch(data.tenki){
		case 1:R=R*3/4;break;
		case 2:R=R*2/3;break;
		case 3:R=R/2  ;break;
	}

	SetDrawBright(R,R,R);

	DrawRotaGraph(X+4+160*(WIDE),Y+4+120*(WIDE),WIDE,0,gra.shop[SG],0,0);
	//����\��
	if(shop[P].holiday == 1){
		if(SG == 0)					DrawExtendGraph(X+4+144*(WIDE),Y+4+96*(WIDE),X+4+176*(WIDE),Y+4+112*(WIDE),gra.ico[99],0);
		else if(SG == 1 || SG == 2)	DrawExtendGraph(X+4+144*(WIDE),Y+4+80*(WIDE),X+4+176*(WIDE),Y+4+112*(WIDE),gra.ico[99],0);
	}


	//�J�\��
	static int rain_x[200],rain_syoki = 0;

	if(rain_syoki == 0){
		for(int i=0;i<200;i++)rain_x[i] = fun.Rand(880);
		rain_syoki = 1;
	}

	if(data.tenki == 2){
		for(int i=0;i<100;i++){
			DrawStringToHandle(X+rain_x[i],Y+(data.time+i)%100*10,"/",color.siro,data.font[1]);
			if(opt.speed == 0) continue;
			rain_x[i]-=4;
			if( (data.time+i)%50 == 0) rain_x[i] = fun.Rand(880);
		}
	}else if(data.tenki == 3){
		for(int i=0;i<200;i++){
			DrawStringToHandle(X+rain_x[i],Y+(data.time+i)%100*10,"/",color.siro,data.font[1]);
			if(opt.speed == 0) continue;
			rain_x[i]-=4;
			if( (data.time+i)%50 == 0) rain_x[i] = fun.Rand(880);
		}
	}

	int M;

	for(int H=0;H<data.jinkou_max;H++){//�`���ҕ\��
		if(hun[H].act == 5 && hun[H].wait<30 && hun[H].act_no == P)	M = hun[H].wait/5%3 + 3;
		else if(hun[H].act == 4)									M = hun[H].wait/5%3;
		else if(hun[H].vx == -1)									M = hun[H].wait/5%3 + 6;
		else														M = hun[H].wait/5%3 + 9;

		if(hun[H].x>=-10 && hun[H].x<=310){
			DrawRotaGraph(X+(162+(hun[H].x-150)*3/2)*WIDE,Y+(110+hun[H].y*(H*4/3+data.jinkou_max)/data.jinkou_max)*WIDE,WIDE,0,gra.unit[jobs[hun[H].job].gra][M],1,0);
		}
	}


	SetDrawBright(255,255,255);

	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;
}
int DRA::win_4b(/*���l���*/int X,int Y){
	SetDrawArea(X+4,Y+4,X+wind.sx[3]-20,Y+wind.sy[3]-34);

	wind.smini[3] = 75;
	wind.scr_on[3] = 1;

	int XP = 6 ,YP = -44 , E = -1 , i , T = -1 , SH , IC;
	std::string name;

	for(i=0;i<7;i++){//���\���^�u
		if(wind.req_hyouji==i ){
			SH = 1;
		}else{
			SH = 0;
		}
		waku(X+6+i*36,Y+6,32,32,8+SH);
		SetDrawBright(255,255,255);
		switch(i){
			case 0:IC = 72;break;//LV
			case 1:IC = 44;break;//HP
			case 2:IC = 45;break;//ST1
			case 3:IC =  7;break;//ST2
			case 4:IC = 91;break;//�X�L��
			case 5:IC = 73;break;//����
			case 6:IC = 53;break;//����
		}
		DrawRotaGraph(X+22+36*i+SH,Y+22+SH,1+SH,0,gra.ico[IC],TRUE,0);
	}

	Y+=36;
	SetDrawArea(X+4,Y+4,X+wind.sx[3]-20,Y+wind.sy[3]-34-36);
	Y-=wind.scr[3];

	for(i=0;i<wind.req_m;i++){
		E= wind.req_list[i];
		if( T != emp[E].job){
			T = emp[E].job;
			XP = 6;
			YP+=50;
			waku_c(X+6,Y+YP,280,25,200,200,200);
			switch(T){
				case 0:name = "�X��";IC = 46;break;
				case 1:name = "�E�l";IC = 45;break;
			}
			DrawRotaGraph(X+XP+12,Y+YP+12,1,0,gra.ico[IC],TRUE,0);
			mes(X+XP+28,Y+YP+6,name.c_str(),color.kuro,color.siro,2);
			YP+=30;
		}

		E= wind.req_list[i];
		if(XP>40*7){
			XP=6;
			YP+=40;
		}

		waku_c(X+XP,Y+YP,40,40,255,255,255);
		if(emp[E].now_job == 2)	waku_c(2+X+XP,2+Y+YP,36,36,255,150,150);//R����
		if(emp[E].mensetu[P] == 0){//�ʐڑO
			mes(10+X+XP,10+Y+YP,"�H",color.kuro,color.siro,1);
		}else{
			//�摜
			DrawRotaGraph(20+X+XP,20+Y+YP,2,0,gra.unit[emp[E].gra][1],TRUE,0);
			//���x��
			switch(wind.req_hyouji){
				case 0:
					mes_bmf(14+X+XP,30+Y+YP,"L",1);
					suu_bmf(32+X+XP,30+Y+YP,2,emp[E].lv,2,5);break;//LV
				case 1:
					if(emp[E].mensetu[0][P] == 1)	suu_bmf(32+X+XP,30+Y+YP,2,(int)sqrt((double)emp[E].st[0]*100),2,5);
					else							mes_bmf(14+X+XP,30+Y+YP,"???",1);
				break;//HP
				case 2:
					if(emp[E].mensetu[1][P] == 1)	suu_bmf(32+X+XP,30+Y+YP,2,emp[E].st[1],2,5);
					else							mes_bmf(14+X+XP,30+Y+YP,"???",1);
					break;//ST1
				case 3:
					if(emp[E].mensetu[2][P] == 1)	suu_bmf(32+X+XP,30+Y+YP,2,emp[E].st[2],2,5);
					else							mes_bmf(14+X+XP,30+Y+YP,"???",1);
					break;//ST2
				case 4:
					if(emp[E].mensetu[4][P] == 1){
						std::string str;
						str = data.skill_job[emp[E].skill];
						if(str.length() > 4)	str[4] = NULL;
						waku_c(4+X+XP,20+Y+YP,32,17,64,64,64);
						mes(6+X+XP,22+Y+YP,str.c_str(),color.siro,color.kuro,2);
					}
					else							mes_bmf(14+X+XP,30+Y+YP,"???",1);
					break;//�X�L��
				case 5:
					if(emp[E].mensetu[3][P] == 1)	suu_bmf(32+X+XP,30+Y+YP,2,emp[E].konjyou,2,5);
					else							mes_bmf(14+X+XP,30+Y+YP,"???",1);
					break;//����
				case 6:
					suu_bmf(24+X+XP,28+Y+YP,2,emp[E].req_money/10,2,5);
					suu_bmf(34+X+XP,30+Y+YP,1,emp[E].req_money%10,2,5);
				break;//����
			}
		}
		//�E��
		DrawRotaGraph(10+X+XP,10+Y+YP,1,0,gra.ico[46-emp[E].job],TRUE,0);

		XP += 40;
	}
	wind.scrm[3] = YP + 80;
	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;
}
int DRA::win_5b(/*�X�����*/int X,int Y){
	int i,c,H,XC,YC,SH,IC;

	wind.smax[4] = 1000;

	SetDrawArea(X+4,Y+4,X+wind.sx[4]-20,Y+wind.sy[4]-34);

	for(i=0;i<7;i++){//���\���^�u

		if(wind.emp_hyouji==i){
			SH = 1;
		}else{
			SH = 0;
		}
		waku(X+6+i*36,Y+6,32,32,8+SH);

		SetDrawBright(255,255,255);
		switch(i){
			case 0:IC = 44;break;//HP
			case 1:IC = 72;break;//LV
			case 2:IC = 93;break;//ST1
			case 3:IC = 46;break;//ST2
			case 4:IC = 53;break;//����
			case 5:IC = 48;break;//����
			case 6:IC = 50;break;//����
		}
		DrawRotaGraph(X+22+36*i+SH,Y+22+SH,1+SH,0,gra.ico[IC],TRUE,0);
	}
	if(data.taiguu_ok == 1){
		SH = wind.ts_hyouji;
		SetDrawBright(255,0,0);
		waku(X+6+7*36,Y+6,68,32,8+SH);
		SetDrawBright(255,255,255);
		DrawRotaGraph(X+40+36*7+SH,Y+22+SH,1+SH,0,gra.ico[32],TRUE,0);
	}
	//�e�R�[�i�[�̉ғ���
	//�X�ʋq��//��ԋq�������X����ɂ���
	waku_c(X+255,Y+48,65,24,255,255,255);//�ő�
	suu_bmf(X+275,Y+60,2,(EIGYOU_T+48)/6,0);
	mes(X+280,Y+50,":",color.siro,color.kuro,0);
	suu_bmf(X+295,Y+60,2,(EIGYOU_T+48)%6,0);
	suu_bmf(X+310,Y+60,2,0,0);
	SetDrawBright(255,255,255);
	waku_c(X+34,Y+50,EIGYOU_T*3+4,20,255,255,255);//����
	waku_c(X+36,Y+52,EIGYOU_T*3,16,50,50,255);//����
	DrawRotaGraph(X+24,Y+56,2,0,gra.ico[77],TRUE,0);
	suu_bmf(X+55,Y+60,2,8,0);
	mes(X+60,Y+50,":",color.siro,color.kuro,0);
	suu_bmf(X+75,Y+60,2,0,0);
	suu_bmf(X+90,Y+60,2,0,0);
	SetDrawArea(X+4,Y+76,X+wind.sx[4]-20,Y+wind.sy[4]-34);
	//�\��//����͍ő�16��ނ܂�
	H=0;
	if(wind.ts_hyouji == 0){//�V�t�g�ύX
		for(i=WEP_M;i<WEP_M+4;i++){
			waku(6+X,78+Y-wind.scr[4]+H,40,30,6);
			waku(36+X,78+Y-wind.scr[4]+H,290,wind.efold_h[i],6);
			switch(i-WEP_M){
				case 0:DrawRotaGraph(22+X,94+Y-wind.scr[4]+H,2,0,gra.ico[0],TRUE,0);break;
				case 1:DrawRotaGraph(22+X,94+Y-wind.scr[4]+H,2,0,gra.ico[1],TRUE,0);break;
				case 2:DrawRotaGraph(22+X,94+Y-wind.scr[4]+H,2,0,gra.ico[2],TRUE,0);break;
				case 3:DrawRotaGraph(22+X,94+Y-wind.scr[4]+H,2,0,gra.ico[3],TRUE,0);break;
			}
			//�l���`��
			XC=40+X;
			YC=H+Y+82-wind.scr[4];
			for(c=0;c<wind.efold_cnt[i];c++){
				draw.win_5s(wind.efold_mem[i][c],XC,YC);
				XC+=40;
				if(c%7==6){
					XC=40+X;
					YC+=40;
				}
			}
			//�t�H���_�ʒu�␳
			H +=wind.efold_h[i]+4;
		}
	}else{//�ҋ��ύX
		for(i=0;i<4;i++){
			int ICO;
			waku(6+X,78+Y-wind.scr[4]+H,40,30,6);
			waku(36+X,78+Y-wind.scr[4]+H,290,wind.tfold_h[i][0],6);
			switch(i){
				case 0:ICO = 74;break;
				case 1:ICO = 32;break;
				case 2:ICO = 33;break;
				case 3:ICO = 24;break;
			}
			DrawRotaGraph(22+X,94+Y-wind.scr[4]+H,2,0,gra.ico[ICO],TRUE,0);
			//�l���`��
			XC=40+X;
			YC=H+Y+82-wind.scr[4];
			for(c=0;c<wind.tfold_cnt[i][0];c++){
				draw.win_5s(wind.tfold_mem[i][0][c],XC,YC);
				XC+=40;
				if(c%7==6){
					XC=40+X;
					YC+=40;
				}
			}
			//�t�H���_�ʒu�␳
			H +=wind.tfold_h[i][0]+4;
		}
	}


	wind.scrm[4] = H + 76;

	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;
}
int DRA::win_6b(/*�E�l���*/int X,int Y){
	int i,c,H,XC,YC,SH,IC,WN;

	SetDrawArea(X+4,Y+4,X+wind.sx[5]-20,Y+wind.sy[5]-34);

	for(i=0;i<7;i++){//���\���^�u

		if(wind.emp_hyouji==i){
			SH = 1;
		}else{
			SH = 0;
		}
		waku(X+6+i*36,Y+6,32,32,8+SH);

		SetDrawBright(255,255,255);
		switch(i){
			case 0:IC = 44;break;//HP
			case 1:IC = 72;break;//LV
			case 2:IC = 45;break;//ST1
			case 3:IC = 7;break;//ST2
			case 4:IC = 53;break;//����
			case 5:IC = 48;break;//����
			case 6:IC = 50;break;//����
		}
		DrawRotaGraph(X+22+36*i+SH,Y+22+SH,1+SH,0,gra.ico[IC],TRUE,0);
	}
	if(data.taiguu_ok == 1){
		SH = wind.ts_hyouji;
		SetDrawBright(255,0,0);
		waku(X+6+7*36,Y+6,68,32,8+SH);
		SetDrawBright(255,255,255);
		DrawRotaGraph(X+40+36*7+SH,Y+22+SH,1+SH,0,gra.ico[32],TRUE,0);
	}
	//�ғ�����
	if(shop[P].koubou_n<shop[P].koubou_t)		SetDrawBright(255,150,150);
	else if(shop[P].koubou_n>shop[P].koubou_t)	SetDrawBright(150,150,255);
	waku_c(X+255,Y+48,65,24,255,255,255);//�ő�
	suu_bmf(X+275,Y+60,2,(shop[P].koubou_n+48)/6,0);
	mes(X+280,Y+50,":",color.siro,color.kuro,0);
	suu_bmf(X+295,Y+60,2,(shop[P].koubou_n+48)%6,0);
	suu_bmf(X+310,Y+60,2,0,0);
	SetDrawBright(255,255,255);
	waku_c(X+34,Y+48,4+shop[P].zangyou*3,24,255,255,255);//�ő�
	waku_c(X+36,Y+52,shop[P].koubou_t*3,16,50,255,50);//����
	waku_c(X+36+shop[P].koubou_n*3-2,Y+50,5,20,255,50,50);//�\��
	DrawRotaGraph(X+24,Y+56,2,0,gra.ico[77],TRUE,0);
	suu_bmf(X+55,Y+60,2,8,0);
	mes(X+60,Y+50,":",color.siro,color.kuro,0);
	suu_bmf(X+75,Y+60,2,0,0);
	suu_bmf(X+90,Y+60,2,0,0);
	if(wind.ok[9] == 1){
		DrawRotaGraph(X+250,60+Y,1,PI,gra.ico[59],TRUE,0);
		DrawRotaGraph(X+320,60+Y,1,0,gra.ico[59],TRUE,0);
	}
	SetDrawArea(X+4,Y+76,X+wind.sx[5]-20,Y+wind.sy[5]-34);
	//�\��//
	H=0;

	if(wind.ts_hyouji == 0){
		for(i=0;i<WEP_M;i++){
			WN = wind.efold_s[i];
			if(WN == -1)break;//�H�[�̓t�H���_�\���X�L�b�v�L
			waku(6+X,78+Y-wind.scr[5]+H,40,30,6);
			waku(36+X,78+Y-wind.scr[5]+H,290,wind.efold_h[WN],6);
			//���퓯��or�t�H���_���݂ŗΕ\��
			if( (WN == Inp.d_no && Inp.d_type <=3) || (Inp.d_no-1000 == i && Inp.d_type == 6)){
				waku_c( 8+X,80+Y-wind.scr[5]+H,40,26,100,255,100);
				waku_c(38+X,80+Y-wind.scr[5]+H,286,wind.efold_h[WN]-4,100,255,100);
			}
			wep_icon(22+X,94+Y-wind.scr[5]+H,1,WN);//�^�u�̃A�C�R��
			if(draw.kai_t[WN] > 0){
				draw.kai_t[WN] --;
				SetDrawBright(255,100,100);	
				mes_bmf2(22+X,94+Y-wind.scr[5]+H + draw.kai_t[WN] / 5 ,"up",2);
				SetDrawBright(255,255,255);	
			}
			if(shop[P].wep_cre[WN] != 2){//�J�������\��
				waku_c(160+X,92+Y-wind.scr[5]+H,154,20,170,170,255);
				//�J����
				if(shop[P].wep_make_now[WN]>0)	c=100;
				else							c=150;
				waku_c(160+X,92+Y-wind.scr[5]+H,int(double(shop[P].wep_make[WN])/wep[WN].create_time*154),20,255,c,c);
				suu_bmf(291+X,102+Y-wind.scr[5]+H,2,int(double(shop[P].wep_make[WN])/wep[WN].create_time*100),0);
				mes(300+X,92+Y-wind.scr[5]+H,"%",color.kuro,color.siro,0);
				DrawRotaGraph(X+28,86+Y-wind.scr[5]+H,1,0,gra.ico[7],0);
			}else{
				if(shop[P].wep_rest[WN]<=0)SetDrawBright(255,100,100);
				mes_bmf(10+X,110+Y-wind.scr[5]+H,"X",1);					
				suu_bmf(30+X,110+Y-wind.scr[5]+H,2,shop[P].wep_rest[WN],2,5);
				SetDrawBright(255,255,255);
			}
			//�S��0�̃t�H���_
			if(wind.efold_cnt[WN]<=0){//����0�Ȃ����{�^����t����
				DrawRotaGraph(310+X,90+Y-wind.scr[5]+H,1,0,gra.ico[57],TRUE,0);
			}
			//�l���`��
			XC=40+X;
			YC=H+Y+82-wind.scr[5];
			for(c=0;c<wind.efold_cnt[WN];c++){
				draw.win_5s(wind.efold_mem[WN][c],XC,YC);
				XC+=40;
				if(c%7==6){
					XC=40+X;
					YC+=40;
				}
			}
			//�t�H���_�ʒu�␳
			H +=wind.efold_h[WN]+4;
		}
	}else{//�ҋ��ύX
		for(i=0;i<4;i++){
			int ICO;
			waku(6+X,78+Y-wind.scr[5]+H,40,30,6);
			waku(36+X,78+Y-wind.scr[5]+H,290,wind.tfold_h[i][1],6);
			switch(i){
				case 0:ICO = 74;break;
				case 1:ICO = 32;break;
				case 2:ICO = 33;break;
				case 3:ICO = 24;break;
			}
			DrawRotaGraph(22+X,94+Y-wind.scr[5]+H,2,0,gra.ico[ICO],TRUE,0);
			//�l���`��
			XC=40+X;
			YC=H+Y+82-wind.scr[5];
			for(c=0;c<wind.tfold_cnt[i][1];c++){
				draw.win_5s(wind.tfold_mem[i][1][c],XC,YC);
				XC+=40;
				if(c%7==6){
					XC=40+X;
					YC+=40;
				}
			}
			//�t�H���_�ʒu�␳
			H +=wind.tfold_h[i][1]+4;
		}
	}
	wind.scrm[5] = H + 76;

	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;
}
int DRA::win_7b(/*��Џ��*/int X,int Y){

	SetDrawArea(X+4,Y+4,X+wind.sx[6]-20,Y+wind.sy[6]-34);


	int XP,YP=Y+6-wind.scr[6],i;
	int ICO,LV = 0;
	std::string NAME,TANI;

	//+shop.cnt *27

	//��{�g
	for(i=0;i<17;i++){
		if(i==0)XP=6;
		else if(i==8 || i==12) XP = 12; 
		else XP = 20;
		switch(i){
			case 0 :XP = 6;ICO=11;NAME = shop[P].name;break;
			case 1 :XP =20;ICO=53;NAME = "����";TANI="�f";break;
			case 2 :XP =20;ICO=9;NAME  = "����LV";TANI="";break;
			case 3 :XP =20;ICO=47;NAME = "�u���b�N�x";TANI="��";break;
			case 4 :XP =20;ICO=78;NAME = "�m���x";TANI = "��";break;
			case 5 :XP =20;ICO=62;NAME = "�_��[�i";TANI="��";break;
			case 6 :XP =20;ICO=51;NAME = "�x��";TANI="��";break;
			case 7 :XP =12;ICO=7;NAME  = "�Z�p���x��";TANI = "";break;
			case 8 :XP =20;ICO=1;NAME  = "����";break;
			case 9 :XP =20;ICO=2;NAME  = "�B�S";break;
			case 10:XP =20;ICO=3;NAME  = "�׍H";break;
			case 11:XP =12;ICO=42;NAME = "����";break;
			case 12:XP =20;ICO=-1;NAME = "���Њ�" ;TANI="�f";break;
			case 13:XP =20;ICO=-1;NAME = "���" ;TANI="�f";break;
			case 14:XP =20;ICO=-1;NAME = "�z�R��" ;TANI="�f";break;
			case 15:XP =20;ICO=-1;NAME = "������" ;TANI="�f";break;
			case 16:XP =20;ICO=-1;NAME = "�V����" ;TANI="�f";break;
		}
		if(XP == 20){
			waku(X+20,YP,100,25,6);
			waku(X+122,YP,150,25,6);
		}else{
			waku_c(X+XP,YP,272-XP,25,200,200,200);
		}
		if(ICO == -1){
			mes(X+XP+6,YP+6,NAME.c_str(),color.kuro,color.siro,2);
		}else{
			mes(X+XP+26,YP+6,NAME.c_str(),color.kuro,color.siro,2);
		}
		if(ICO>=0)DrawRotaGraph(X+XP+14,YP+13,1,0,gra.ico[ICO],TRUE,0);//����

		int GL = 0;
		if(i >= 8 && i<=10){//�Q�[�W�\��
			GL = shop[P].create_exp[i-8]*7/(shop[P].create_lv[i-8]+7) / WEP_EXP_RATE2;
			waku_c( X+125,YP+2,144,21,255,150,150);
			GL = GL * 140/144;
			waku_c( X+127,YP+4,GL,17,255,50,50);
			mes_bmf(X+77 ,YP+12,"LV",1);
			suu_bmf(X+111,YP+12,2,shop[P].create_lv[i-8],0);
		}
		if(i >=12){//�����\��
			GL = int(shop[P].kabu_rate[i-12]*1.44);
			waku_c( X+125,YP+2,GL,21,0,255,50);
			if(i==12) GL = (int)shop[P].kabu_price;
			else	  GL = (int)data.kabu_price[i-12];
			suu_bmf(X+240,YP+12,2,GL,0);
			syou_bmf(X+112,YP+12,int(shop[P].kabu_rate[i-12]*10),0);
		}
		mes(X+XP+230,YP+6,TANI.c_str(),color.kuro,color.siro,2);
		YP+=27;
	}
	//�u���b�N�x
	YP = Y-wind.scr[6]-6;
	if(shop[P].money<0)	SetDrawBright(255,150,150);//����
	suu_bmf(X+240,YP+27*2,2,abs(int(shop[P].money)),0);
	SetDrawBright(255,255,255);

	syou_bmf(X+240,YP+27*3,int(shop[P].lv_ave*10),0);//���x��
	syou_bmf(X+240,YP+27*4,int(shop[P].b_w*10),0);//�u���b�N�x
	syou_bmf(X+240,YP+27*5,int(shop[P].timeido),0);//�m���x
	suu_bmf(X+180,YP+27*6,2,shop[P].wep_rest[NOU_NO],0);//�_��݌�/�v����
	suu_bmf(X+240,YP+27*6,1,shop[P].nougu_req,0);
	mes(X+195,YP+27*6-8,"/",color.kuro,color.siro,2);
	
	int YB = 4;

	switch(shop[P].teikyuu){
		case -1:mes(X+130,YP+27*7-10,"��x����",color.kuro,color.siro,2);YB=0;break;
		case 0:mes(X+140,YP+27*7-10,"���j��",color.kuro,color.siro,2);break;
		case 1:mes(X+140,YP+27*7-10,"�Ηj��",color.kuro,color.siro,2);break;
		case 2:mes(X+140,YP+27*7-10,"���j��",color.kuro,color.siro,2);break;
		case 3:mes(X+140,YP+27*7-10,"�ؗj��",color.kuro,color.siro,2);break;
		case 4:mes(X+140,YP+27*7-10,"���j��",color.kuro,color.siro,2);break;
		case 5:mes(X+140,YP+27*7-10,"�y�j��",color.kuro,color.siro,2);break;
		case 6:mes(X+140,YP+27*7-10,"���j��",color.kuro,color.siro,2);break;
	}
	suu_bmf(X+240,YP+27*7,2,shop[P].yasumi_max-YB,0);//�ő�x��

	mes_bmf(X+200,YP+27*7-2,"+",1);

	//��А��x�ꗗ
	win_7_seido(X,Y-wind.scr[6]+465);

	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;

}
int DRA::win_8b(/*���O*/int X,int Y){

	int C = 0;
	int SM[6]={0,1,2,3,4,5};

	SM[0] = P;
	if(P > 0) SM[1] = 0;
	if(P > 1) SM[2] = 1;
	if(P > 2) SM[3] = 2;
	if(P > 3) SM[4] = 3;

	wind.sx[7] = 360;
	wind.smini[7] = 80;
	wind.smax[7] = data.window_y - 96;

	//�ŏ㕔�Ƀ\�[�g�p�^�u
	SetDrawArea(X+4,Y+4,X+wind.sx[7]-20,Y+wind.sy[7]-34);

	for(int i=0;i<data.shop_cnt+1;i++){
		int IC,SH;
		if(logu.mode != i){
			waku(X+6+i*54,Y+6,50,32,8);
			SH = 0;
		}else{
			waku(X+6+i*54,Y+6,50,32,9);
			SH = 1;
		}
		switch(i){
			case 0: IC = 4;break;//�S��
			case 1: IC = shop[SM[0]].icon;break;//���X�̂�
			case 2: IC = shop[SM[1]].icon;break;//���X�`
			case 3: IC = shop[SM[2]].icon;break;//���X�a
			case 4: IC = shop[SM[3]].icon;break;//���X�b
			case 5: IC = shop[SM[4]].icon;break;//���X�c
		}
		DrawRotaGraph(X+31+54*i+SH,Y+22+SH,1+SH,0,gra.ico[IC],TRUE,0);
	}
	
	SetDrawArea(X+4,Y+40,X+wind.sx[7]-20,Y+wind.sy[7]-34);

	int D= 0;

	int Col[6][3];
	int IC[17];

	Col[0][0] = 255;Col[0][1]=200;Col[0][2]=200;
	Col[1][0] = 200;Col[1][1]=255;Col[1][2]=200;
	Col[2][0] = 255;Col[2][1]=255;Col[2][2]=255;
	Col[3][0] = 200;Col[3][1]=200;Col[3][2]=255;
	Col[4][0] = 150;Col[4][1]=150;Col[4][2]=150;
	Col[5][0] = 255;Col[5][1]=255;Col[5][2]=200;
	IC[0] = 11;
	IC[1] = 53;
	IC[2] = 45;
	IC[3] = 7;
	IC[4] = 78;
	IC[5] = 9;
	IC[6] = 9;
	IC[9] = 78;
	IC[10] = 78;
	IC[11] = 45;
	IC[12] = 45;
	IC[13] = 35;
	IC[14] = 17;
	IC[15] = 112;
	IC[16] = 111;

	for(int I=logu.cnt-1;I>=0;I--){
		int S = logu.log[I].shop;
		int T = logu.log[I].type;

		//���[�h�̂���ăX�L�b�v����
		if(logu.mode != 0 && logu.log[I].shop != SM[logu.mode-1]){
			continue;
		}

		//���t�\��
		if(logu.log[I].date != D){
			D = logu.log[I].date;
			waku_c(X+8,Y+44-wind.scr[7]+C,85,18,195,165,132);
			char str[32];
			sprintf_s(str," %d/ %d/ %d",D/28/12+1,D/28%10+1,D%28+1);
			mes(X+16,Y+46-wind.scr[7]+C,str,color.siro,color.kuro,2);
			C+=18;
		}
		waku_c(X+8,Y+44-wind.scr[7]+C,320,22,Col[S][0],Col[S][1],Col[S][2]);
		if(T > 1000){
			DrawRotaGraph(X+24,55+Y-wind.scr[7]+C,1,0,gra.wep[T%1000],TRUE,0);

		}else{
			DrawRotaGraph(X+24,55+Y-wind.scr[7]+C,1,0,gra.ico[IC[T]],TRUE,0);
		}

		mes(X+36,Y+46-wind.scr[7]+C,logu.log[I].str,color.kuro,color.siro,0);

		C+=23;
	}

	wind.scrm[7] =min(C+40,10000);

	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;
}
int DRA::win_9b(/*���x���*/int X,int Y){

	int i,HY,HX,HS,IC;
	char str[2][10];

	wind.smax[8] = 540;
	//�\���I���{�^��
	SetDrawArea(X+4,Y+4,X+wind.sx[8]-20,Y+wind.sy[8]-34);
	for(i=0;i<3;i++){
		if(i != wind.syu_set)		waku(X+6+i*36,Y+6,32,32,8);
		else						waku(X+6+i*36,Y+6,32,32,9);
	}

	mes(X+10 +(wind.syu_set+3)%4/3,Y+8+(wind.syu_set+3)%4/3,"�N",color.siro,color.kuro,1);
	mes(X+46 +(wind.syu_set+2)%4/3,Y+8+(wind.syu_set+2)%4/3,"��",color.siro,color.kuro,1);
	mes(X+82 +(wind.syu_set+1)%4/3,Y+8+(wind.syu_set+1)%4/3,"��",color.siro,color.kuro,1);

	if(wind.syu_set !=2){
		waku(X+212,Y+6,60,32,8+wind.syousai_hyouji);
		mes(X+215+wind.syousai_hyouji,Y+8+wind.syousai_hyouji,"�ڍ�",color.siro,color.kuro,1);
	}

	//�N�����I��
	waku(X+8,Y+45,270,40,6);
	mes(X+80,Y+55,"�N",color.kuro,color.siro,0);
	suu_bmf(X+65,Y+65,2,wind.syu_year+200,0);
	DrawRotaGraph(X+50,79+Y,1,PI/2,gra.ico[59],TRUE,0);
	DrawRotaGraph(X+50,49+Y,1,-PI/2,gra.ico[59],TRUE,0);
	if(wind.syu_set>0){
		DrawRotaGraph(X+115,79+Y,1,PI/2,gra.ico[59],TRUE,0);
		DrawRotaGraph(X+115,49+Y,1,-PI/2,gra.ico[59],TRUE,0);
		mes(X+140,Y+55,"��",color.kuro,color.siro,0);
		suu_bmf(X+125,Y+65,2,wind.syu_mon+1,0);
	}
	if(wind.syu_set>1){
		DrawRotaGraph(X+175,79+Y,1,PI/2,gra.ico[59],TRUE,0);
		DrawRotaGraph(X+175,49+Y,1,-PI/2,gra.ico[59],TRUE,0);
		mes(X+190,Y+55,"��",color.kuro,color.siro,0);
		suu_bmf(X+180,Y+65,2,(wind.syu_day)%28+1,0);
	}
	
	waku(X+215,Y+50,50,26,8+wind.syu_now);
	mes(X+220+wind.syu_now,Y+48+wind.syu_now,"now",color.siro,color.kuro,1);

	SetDrawArea(X+4,Y+86,X+wind.sx[8]-20,Y+wind.sy[8]-34);

	for(i=0;i<14;i++){
		if(i<2 || i>5)	waku(X+8,Y+85-wind.scr[8]+i*30,270,25,6);
		else			waku(X+18,Y+85-wind.scr[8]+i*30,260,25,6);
	}

	fun.sell_data_cul();
	//������
	for(i=0;i<4;i++){//�V�F�A�\��
		HY=147+Y+i*30;
		HX = X+75;HS= wind.shear_p[P][i]/5;
		waku_c(HX,HY-wind.scr[8],HS,21,255,100,100);
		HX +=HS ;HS = wind.shear_p[(P+4)%5][i]/5;
		waku_c(HX,HY-wind.scr[8],200+75+X-HX,21,100,100,100);
		DrawRotaGraph(X+28,HY+9-wind.scr[8],1,0,gra.ico[i],TRUE,0);
		suu_bmf(X+55,HY+13-wind.scr[8],2,wind.shear_p[P][i]/10,2,6);
		suu_bmf(X+65,HY+15-wind.scr[8],1,wind.shear_p[P][i]%10,2);
	}

	int N;

	for(i=0;i<14;i++){
		HY =  90+Y+i*30;
		switch(i){
			case  0:strcpy_s(str[0],"����")		;strcpy_s(str[1],"��");IC = 5 ;N= wind.syu_hyouji[0];break;
			case  1:strcpy_s(str[0],"������")	;strcpy_s(str[1],"�f");IC = 32;N= wind.syu_hyouji[1];break;
			case  2:							;strcpy_s(str[1],"�f");IC = -1;N= wind.shear_s[P][0];break;
			case  3:							;strcpy_s(str[1],"�f");IC = -1;N= wind.shear_s[P][1];break;
			case  4:							;strcpy_s(str[1],"�f");IC = -1;N= wind.shear_s[P][2];break;
			case  5:							;strcpy_s(str[1],"�f");IC = -1;N= wind.shear_s[P][3];break;
			case  6:strcpy_s(str[0],"�q��")		;strcpy_s(str[1],"�l");IC = 5 ;N= wind.syu_hyouji[2];break;
			case  7:strcpy_s(str[0],"������")	;strcpy_s(str[1],"��");IC = 45;N= wind.syu_hyouji[3];break;
			case  8:strcpy_s(str[0],"������")	;strcpy_s(str[1],"�f");IC = 33;N= wind.syu_hyouji[4];break;
			case  9:strcpy_s(str[0],"�l����")	;strcpy_s(str[1],"�f");IC = 33;N= wind.syu_hyouji[5];break;
			case 10:strcpy_s(str[0],"�o�c��")	;strcpy_s(str[1],"�f");IC = 33;N= wind.syu_hyouji[6];break;
			case 11:strcpy_s(str[0],"��,���q��");strcpy_s(str[1],"�f");IC = 53;N= wind.syu_hyouji[7];break;
			case 12:strcpy_s(str[0],"���v")		;strcpy_s(str[1],"�f");IC = 53;N= wind.syu_hyouji[8];break;
			case 13:strcpy_s(str[0],"����")		;strcpy_s(str[1],"�f");IC = 53;N= wind.syu_hyouji[11];break;
		}

		mes(X+251,HY-wind.scr[8]-1,str[1],color.kuro,color.siro,0);

		if(IC>0){
			mes(X+36,HY-wind.scr[8],str[0],color.kuro,color.siro,0);
			DrawRotaGraph(X+24,9+HY-wind.scr[8],1,0,gra.ico[IC],TRUE,0);
		}

		if(wind.syu_set > 1 && i>=9){
			mes_bmf(X+146,HY+9-wind.scr[8],"NO data",2);			
		}else{
			if(N < 0){
				SetDrawBright(255,100,100);
				N = abs(N);
			}
			suu_bmf(X+240,HY+9-wind.scr[8],2,N,0);
			SetDrawBright(255,255,255);
		}
	}

	SetDrawBright(255,255,255);

	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;
}
int DRA::win_10b(/*�o�c�헪�E�B���h�E*/int X,int Y){

	double N_MP = shop[P].n_mp;
	int U_MP = shop[P].use_mana;
	int S_MP = 0;		
	if( shop[P].use_mana > 0) S_MP = shop[P].syou_mp[U_MP] * shop[P].mana_b[mana[U_MP].type] / 100;
	N_MP -= S_MP;
	wind.smini[9]=76+38;

	SetDrawArea(X+4,Y+4,X+wind.sx[9]-20,Y+80);

	int SH = 0,IC = 0;

	for(int i=0;i<7;i++){//���\���^�u

		SH = 0;
		if(wind.mana_hyouji == i )		  SH = 1;	
		if(i == 6 && wind.mana_rock == 1) SH = 1;

		if(i==6) waku(X+6+i*36,Y+8,64,32,8+SH);
		else	 waku(X+6+i*36,Y+8,32,32,8+SH);

		SetDrawBright(255,255,255);
		switch(i){
			case 0:IC = data.mana_icon[0];break;//1
			case 1:IC = data.mana_icon[1];break;//2
			case 2:IC = data.mana_icon[2];break;//3
			case 3:IC = data.mana_icon[3];break;//4
			case 4:IC = data.mana_icon[4];break;//5
			case 5:IC = 4;break;//ALL
			case 6:IC = 49;break;//���C���\��
		}
		if(i<6)			DrawRotaGraph(X+22+36*i+SH,Y+24+SH,1+SH,0,gra.ico[IC],TRUE,0);
		else			DrawRotaGraph(X+38+36*i+SH,Y+24+SH,1+SH,0,gra.ico[IC],TRUE,0);
	}

	Y+=38;

	waku(X+6,Y+6,280,36,6);

	waku_c(X+57,Y+7,int(shop[P].n_mp),34,150,150,255);//����O�l
	waku_c(X+57,Y+7,int(S_MP)		 ,34,255,150,150);//�����l

	DrawRotaGraph(X+24,Y+24,2,0,gra.ico[14],TRUE,0);
	mes_bmf(X+34,Y+28,"MP",2);

	if(N_MP<0)SetDrawBright(255,100,100);
	syou_bmf(X+210,Y+24,int(N_MP*10),0);
	SetDrawBright(255,255,255);

	mes(X+226,Y+16,"/",color.kuro,color.siro,2);

	mes_bmf(X+234,Y+30,"+",1);
	syou_bmf(X+274,Y+30,int(shop[P].p_mp*10),0);

	SetDrawArea(X+4,Y+42,X+wind.sx[9]-20,max(Y+wind.sy[9]-72,Y+42));

	int YP=6-wind.scr[9]-10,XP = 6;
	int MR = 0;
	std::string name;


	for(int i=0;i<wind.mana_m;i++){
		int M = wind.mana_list[i];
		int MT = mana[wind.mana_list[i]].type;
		int MRR = 0;
		while(MR <= MT){
			if(MR != MT && wind.mana_hyouji != 5){
				MR = MT;
			}
			//�^�O�\��
			XP=6;
			if(MRR==0){
				YP+=50;
				MRR = 1;
			}
			switch(MR){
				case 0:name = "�o�c";break;
				case 1:name = "����";break;
				case 2:name = "�H��";break;
				case 3:name = "�J��";break;
				case 4:name = "��`";break;
			}
			waku_c(X+6,Y+YP  ,280,25,200,200,255);
			waku_c(X+8,Y+YP+2,76,21,150,150,255);
			int EXP = shop[P].bumon_exp[MR]*2 / (shop[P].bumon_lv[MR] * shop[P].bumon_lv[MR] + 4);
			DrawRotaGraph(X+XP+14,Y+YP+12,1,0,gra.ico[data.mana_icon[mana[wind.mana_list[i]].type]],TRUE,0);
			waku_c(X+6+78,Y+YP+2,EXP,21,255,150,150);
			mes(X+6+28,Y+YP+6,name.c_str(),color.kuro,color.siro,2);
			mes_bmf(X+6+86,Y+YP+16,"LV",1);
			suu_bmf(X+6+118,Y+YP+14,2,shop[P].bumon_lv[MR],0);
			YP+=30;
			MR++;
		}
		
		if(XP>40*7){
			XP=6;
			YP+=40;
		}

		draw.mana_icon(X+XP,Y+YP,M,0);
		
		XP+=40;
	}

	wind.scrm[9]=YP+74+wind.scr[9];

	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;
}
int DRA::win_11b(int X,int Y){
	//�S�̘g�\��
	SetDrawArea(X+4,Y+4,X+wind.sx[10]-20,Y+wind.sy[10]-34);

	Y -= wind.scr[10];

	mes_bmf(X+20,Y-20,"Mode Info",2);

	//���[�h��
	waku_c(X+16,Y+20,370,30,255,255,255);
	mes(X+30,Y+26,"���[�h:",color.kuro,color.siro,0);
	mes(X+110,Y+26,data.mode_n[data.mode+1].c_str(),color.kuro,color.siro,0);

	//��Փx
	waku_c(X+16,Y+60,370,30,255,255,255);
	mes(X+30,Y+66,"��Փx:",color.kuro,color.siro,0);
	mes(X+110,Y+66,data.nanndo_n[data.nando+1].c_str(),color.kuro,color.siro,0);
	//��������
	waku_c(X+16,Y+100,370,60,255,255,255);

	switch(data.mode){
		case 0:
			mes_str(X+30,Y+110,"��Ђ�傫�����悤�I--",color.kuro,color.siro,0);
		break;
		case 1:
			mes_str(X+30,Y+110,"�����ꂩ�̏���������ڎw�����I--",color.kuro,color.siro,0);
		break;
	}
	//�����������Q�[�W(�ő�R��)

	//�������q�|��

	std::string str;
	double NB;//�ڕW�l
	double NP;//����
	int YP=30;

	waku_c(X+16,Y+170,90,30,255,255,255);
	mes(X+21,Y+178,"��������",color.kuro,color.siro,0);


	double na[5] ={0,0,0,0,0};

	for(int i=0;i<12;i++){
		int yp = 0;

		switch(i){		
			case 0:
				str = "�����q��";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_cust;
				NB = data.goal_cust;
			break;
			case 1:
				str = "�������z";//���������z
				for(int s= 0;s<5;s++) na[s] = shop[s].g_kabu;
				NB = data.goal_kabu;
			break;
			case 2:
				str = "���̔��z";//�����̔���
				for(int s= 0;s<5;s++) na[s] = shop[s].g_sell_t;
				NB = data.goal_sell_t;
			break;
			case 3:
				str = "���̔��z";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_sell[0];
				NB = data.goal_sell[0];
			break;
			case 4:
				str = "���̔��z";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_sell[1];
				NB = data.goal_sell[1];
			break;
			case 5:
				str = "���̔��z";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_sell[2];
				NB = data.goal_sell[2];
			break;
			case 6:
				str = "�|�̔��z";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_sell[3];
				NB = data.goal_sell[3];
			break;
			case 7:
				str = "�ߚ{����";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_turu;
				NB = data.goal_turu;
			break;
			case 8:
				str = "�J����";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_wepcre;
				NB = data.goal_wepcre;
			break;
			case 9:
				str = "����";
				for(int s= 0;s<5;s++) na[s] = shop[s].money;
				NB = data.goal_money;
			break;
			case 10:
				str = "�����";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_taikai;
				NB = data.goal_taikai;
			break;
			case 11:
				str = "�{�X����";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_boss;
				NB = data.goal_boss;
			break;
		}

		if(NB <= 0) continue;

		waku_c(X+16,Y+170+YP,68,67,255,255,255);
		waku_c(X+88,Y+170+YP,300,50,255,255,255);
		waku_c(X+88,Y+222+YP,300,15,255,255,255);
		mes(X+21	  ,Y+195+YP,str.c_str(),color.kuro,color.siro,2);

		int col[3];

		for(int s=0;s < 5;s++){

			switch(s){
				case 0:col[0] = 255; col[1] =   0; col[2] =   0;break;
				case 1:col[0] =   0; col[1] = 255; col[2] =   0;break;
				case 2:col[0] = 255; col[1] = 128; col[2] =   0;break;
				case 3:col[0] =   0; col[1] =   0; col[2] = 255;break;
				case 4:col[0] =   0; col[1] =   0; col[2] =   0;break;
			}

			NP = na[s]*1000/NB;
			if(NP < 0 ) NP = 0;

			if(s == P){//���_����
				suu_bmf(X+200 ,Y+230+YP,1,int(na[s]),0);
				mes(X+210	  ,Y+220+YP,"/",color.kuro,color.siro,2);
				suu_bmf(X+300 ,Y+230+YP,1,int(NB),0);

				syou_bmf(X+360,Y+227+YP,int(NP),0);
				mes(X+370,Y+220+YP,"%",color.kuro,color.siro,2);			
			}

			//�Q�[�W������
			waku_c(X+90,Y+172+YP+yp,296*int(NP)/1000,8,
				col[0],
				col[1],
				col[2]);

			DrawRotaGraph(X+90+int(296*NP/1000),Y+172+YP+yp,1,0,gra.ico[shop[s].icon],false);

			yp+=9;
		}

		YP+=70;
	}

	//�������A�Q�[�W�A���ݒl
	
	wind.smini[10]=200;
	wind.scrm[10]=215+YP - 38;
	wind.smax[10]=215+YP;


	SetDrawArea(0,0,data.window_x,data.window_y);

	return 1;
}

int DRA::waku_syuusi(){
	int X = data.window_x/2-300;
	int Y = data.window_y/2-250;
	int HY,i,IC,N,NP,HX,HS;
	char str[2][10];

	//�w�i�Â�����
	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 200) ;
	DrawBox(0,0,data.window_x,data.window_y,GetColor(0,0,0),1);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

	waku( X , Y-50 ,600,50,3);
	waku( X , Y ,600,530,3);

	waku(X+500,8+Y,75,25,6);
	waku(X+15,10+Y,480,25,6);
	mes(X+40 ,12+Y,"���ږ�",color.kuro,color.siro,0);

	waku(X+85,Y-40,30,30,6);
	waku(X+485,Y-40,30,30,6);

	DrawRotaGraph(X+100,Y-25,1, 0,gra.ico[58],TRUE,0);
	DrawRotaGraph(X+500,Y-25,1, 0,gra.ico[59],TRUE,0);
	waku(X+555,Y-40,30,30,6);
	DrawRotaGraph(X+570,Y-25,2,0,gra.ico[57],TRUE,0);//����

	if(wind.syu_set == 1){//���\��
		mes(X+220,Y-35,"�N�@�@���@���x��",color.kuro,color.siro,0);
		suu_bmf(X+210,Y-24,2,wind.syu_year+200,0);
		suu_bmf(X+260,Y-24,2,wind.syu_mon%12+1,0);
		mes(X+510,10+Y,"�O����",color.kuro,color.siro,0);
		if(wind.syu_mon>0 || wind.syu_year>0){//�ŏ��̌��͌v�Z���Ȃ�
			fun.sell_data_cul(1);//�O��or�O�N�v�Z
		}
		fun.sell_data_cul(2);
	}else{//�N�\��
		mes(X+220,Y-35,"�N�@�@�@�@���x��",color.kuro,color.siro,0);	
		suu_bmf(X+210,Y-24,2,wind.syu_year+200,0);
		mes(X+510,10+Y,"�O�N��",color.kuro,color.siro,0);
		if(wind.syu_year>0){//�ŏ��̔N�͌v�Z���Ȃ�
			fun.sell_data_cul(1);//�O��or�O�N�v�Z
		}
		fun.sell_data_cul(2);
	}

	for(i=0;i<4;i++){//�V�F�A�\��
		HY=100+Y+i*30;		
		waku(X+45,HY-2,450,25,6);
		if(wind.shear_t[i]>0){
			HX = X+105;HS= wind.shear_p[P][i]/3		; waku_c(HX,HY,HS,21,255,100,100);
			HX +=HS ;HS = wind.shear_p[(P+4)%5][i]/3; waku_c(HX,HY,333+75+X-HX,21,100,100,100);
		}
		DrawRotaGraph(X+58,HY+9,1,0,gra.ico[i],TRUE,0);
		suu_bmf(X+85,HY+13,2,wind.shear_p[P][i]/10,2,6);
		suu_bmf(X+95,HY+15,1,wind.shear_p[P][i]%10,2);
	}

	for(i=0;i<16;i++){
		HY =  40+Y+i*30;
		switch(i){
			case  0:strcpy_s(str[0],"�̔���")	;strcpy_s(str[1],"��");IC = 5 ;N= wind.syu_hyouji[0];NP = wind.syu_pars[0];break;
			case  1:strcpy_s(str[0],"������")	;strcpy_s(str[1],"�f");IC = 32;N= wind.syu_hyouji[1];NP = wind.syu_pars[1];break;
			case  2:							;strcpy_s(str[1],"�f");IC = -1;N= wind.shear_s[P][0];NP = wind.syu_pars[12];break;
			case  3:							;strcpy_s(str[1],"�f");IC = -1;N= wind.shear_s[P][1];NP = wind.syu_pars[13];break;
			case  4:							;strcpy_s(str[1],"�f");IC = -1;N= wind.shear_s[P][2];NP = wind.syu_pars[14];break;
			case  5:							;strcpy_s(str[1],"�f");IC = -1;N= wind.shear_s[P][3];NP = wind.syu_pars[15];break;
			case  6:strcpy_s(str[0],"���q��")	;strcpy_s(str[1],"�l");IC = 5 ;N= wind.syu_hyouji[2];NP = wind.syu_pars[2];break;
			case  7:strcpy_s(str[0],"������")	;strcpy_s(str[1],"��");IC = 45;N= wind.syu_hyouji[3];NP = wind.syu_pars[3];break;
			case  8:strcpy_s(str[0],"������")	;strcpy_s(str[1],"�f");IC = 33;N= wind.syu_hyouji[4];NP = wind.syu_pars[4];break;
			case  9:strcpy_s(str[0],"�l����")	;strcpy_s(str[1],"�f");IC = 33;N= wind.syu_hyouji[5];NP = wind.syu_pars[5];break;
			case 10:strcpy_s(str[0],"�o�c��")	;strcpy_s(str[1],"�f");IC = 33;N= wind.syu_hyouji[6];NP = wind.syu_pars[6];break;
			case 11:strcpy_s(str[0],"�Ł����q") ;strcpy_s(str[1],"�f");IC = 53;N= wind.syu_hyouji[7];NP = wind.syu_pars[7];break;
			case 12:strcpy_s(str[0],"���v")		;strcpy_s(str[1],"�f");IC = 53;N= wind.syu_hyouji[8];NP = wind.syu_pars[8];break;
			case 13:strcpy_s(str[0],"������")	;strcpy_s(str[1],"�f");IC = 53;N= wind.syu_hyouji[9];NP = wind.syu_pars[9];break;
			case 14:strcpy_s(str[0],"����")		;strcpy_s(str[1],"�f");IC = 53;N= wind.syu_hyouji[11];NP = wind.syu_pars[11];break;
			case 15:strcpy_s(str[0],"�l��")		;strcpy_s(str[1],"�l");IC = 53;N= wind.syu_hyouji[10];NP = wind.syu_pars[10];break;
		}
		waku(X+500,HY-2,75,25,6);
		if(IC>0){
			waku(X+10,HY-2,485,25,6);
			mes(X+36,HY,str[0],color.kuro,color.siro,0);
			DrawRotaGraph(X+24,9+HY,1,0,gra.ico[IC],TRUE,0);
		}
		mes(X+470,HY,str[1],color.kuro,color.siro,0);

		if(NP < 1000){
			SetDrawBright(255,100,100);
		}else{
			SetDrawBright(150,150,255);
		}
		if(NP>0){
			suu_bmf(X+560,HY+9,2,NP/10,0);
			suu_bmf(X+570,HY+11,1,NP%10,0);
		}else{
			SetDrawBright(255,255,255);
			if(NP!=0 && i>10 && i<13){
				if(N>0)	mes(X+510,HY,"������",color.kuro,color.siro,0);
				else	mes(X+510,HY,"�Ԏ���",color.aka,color.siro,0);
			}else{
				mes(X+510,HY,"�\�\�\",color.kuro,color.siro,0);
			}
		}
		SetDrawBright(255,255,255);
		if(N < 0){
			SetDrawBright(255,100,100);
			N = abs(N);
		}
		suu_bmf(X+460,HY+9,2,N,0);
		SetDrawBright(255,255,255);
	}

	return 1;
}
int DRA::waku_graph(){
	int X = data.window_x/2-300;
	int Y = data.window_y/2-250;
	int IC = 0;
	char str[100]="test";

	//�w�i�Â�����
	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 200) ;
	DrawBox(0,0,data.window_x,data.window_y,GetColor(0,0,0),1);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

	waku( X , Y-50  ,600,50,3);
	waku( X , Y		,600,530,3);

	waku(X+85,Y-40,30,30,6);
	waku(X+485,Y-40,30,30,6);

	DrawRotaGraph(X+100,Y-25,1, 0,gra.ico[58],TRUE,0);
	DrawRotaGraph(X+500,Y-25,1, 0,gra.ico[59],TRUE,0);
	waku(X+555,Y-40,30,30,6);
	DrawRotaGraph(X+570,Y-25,2,0,gra.ico[57],TRUE,0);//����

	if(wind.syu_set == 1){//���\��
		mes(X+220,Y-35,"�N�@�@��",color.kuro,color.siro,0);
		suu_bmf(X+210,Y-24,2,wind.syu_year+200,0);
		suu_bmf(X+260,Y-24,2,wind.syu_mon%12+1,0);
	}else{//�N�\��
		mes(X+220,Y-35,"�N",color.kuro,color.siro,0);	
		suu_bmf(X+210,Y-24,2,wind.syu_year+200,0);
	}

	switch(wind.graph_hyouuji){
		case  0+19:strcpy_s(str," �̔���")	;IC=5	;break;
		case  1+19:strcpy_s(str," ������")	;IC=32	;break;
		case  2+19:strcpy_s(str," ������")	;IC=0	;break;
		case  3+19:strcpy_s(str," ������")	;IC=1	;break;
		case  4+19:strcpy_s(str," ������")	;IC=2	;break;
		case  5+19:strcpy_s(str," �|����")	;IC=3	;break;
		case  6+19:strcpy_s(str," ���q��")	;IC=5	;break;
		case  7+19:strcpy_s(str," ������")	;IC=45	;break;
		case  8+19:strcpy_s(str," ������")	;IC=33	;break;
		case  9+19:strcpy_s(str," �l����")	;IC=33	;break;
		case 10+19:strcpy_s(str," �o�c��")	;IC=33	;break;
		case 11+19:strcpy_s(str,"�Ł����q");IC=53	;break;
		case 12+19:strcpy_s(str,"�@���v")	;IC=53	;break;
		case 13+19:strcpy_s(str," ������");IC=53	;break;
		case 14+19:strcpy_s(str,"�@����")	;IC=53	;break;
		case 15+19:strcpy_s(str,"�@�l��")	;IC=53	;break;
	}

	DrawRotaGraph(X+320,Y-25,2,0,gra.ico[IC],TRUE,0);
	mes(X+340,Y-35,str,color.kuro,color.siro,0);

	//�ő�l���v�Z
	int MAX=10,MIN=0,MAX_M= min(data.day/28+1,120);//�ő�l�ƍő匎
	int MAX_Y = MAX_M/12+1;
	int ST[120][5];
	int SM= data.shop_cnt;
	if(wind.graph_hyouuji == 15+19) SM=2;
	for(int S=0;S<SM;S++){
		for(int i=0;i<MAX_M;i++){
			switch(wind.graph_hyouuji){
				case  0+19:ST[i][S]=shop[S].sellc_mon[i]		;break;
				case  1+19:ST[i][S]=shop[S].sell_mon[i]			;break;
				case  2+19:ST[i][S]=shop[S].shera_wepm[i][0]	;break;
				case  3+19:ST[i][S]=shop[S].shera_wepm[i][1]	;break;
				case  4+19:ST[i][S]=shop[S].shera_wepm[i][2]	;break;
				case  5+19:ST[i][S]=shop[S].shera_wepm[i][3]	;break;
				case  6+19:ST[i][S]=shop[S].cust_mon[i]			;break;
				case  7+19:ST[i][S]=shop[S].seizc_mon[i]		;break;
				case  8+19:ST[i][S]=-shop[S].seiz_mon[i]		;break;
				case  9+19:ST[i][S]=-shop[S].emp_mon[i]			;break;
				case 10+19:ST[i][S]=-shop[S].manege_mon[i]		;break;
				case 11+19:ST[i][S]=shop[S].etc_mon[i]			;break;
				case 12+19:ST[i][S]=shop[S].incom_mon[i]		;break;
				case 13+19:ST[i][S]=shop[S].total_mon[i]		;break;
				case 14+19:ST[i][S]=shop[S].kabu_mon[i]			;break;
				case 15+19:
					if(S==0)ST[i][S]=data.jinkou_mon[i];
					else if(S==1)ST[i][S]=data.des_mon[i];
				break;
			}
			if(MAX < ST[i][S]) MAX = ST[i][S];
			if(MIN > ST[i][S]) MIN = ST[i][S];
		}
	}
	int i,L;

	MAX = MAX - MIN;
	L= MAX/10;//���C���͊�{10�{
	i=10;
	while(1){
		if(L<i*10){
			L = L - L%i;
			break;
		}
		i*=10;
	}

	if(L == 0) L=1;

	int XP=X+100;
	int YP=Y+480-int(double(-MIN)*400/MAX);
	int XP2,YP2;

	DrawBox(X+25,Y+25,X+575,Y+505,color.siro,1);//�S��
	DrawLine(X+25,int(YP),X+575,int(YP),color.kuro,1);//0���
	DrawLine(X+100,Y+25,X+100,Y+505,color.kuro,1);
	suu_bmf(X+90,YP,1,0,0);
	//���l�P��
	i = L;
	while(1){
		if(-MIN-i <= 0) break; 
		YP=Y+480-int(double(-MIN-i)*430/MAX);
		DrawLine(X+90,int(YP),X+575,int(YP),GetColor(150,150,255),1);//0���
		suu_bmf(X+75,YP,1,i,0);
		i += L;
	}
	i = L;
	while(1){
		if(-MIN+i >= MAX) break; 
		YP=Y+480-int(double(-MIN+i)*430/MAX);
		DrawLine(X+90,int(YP),X+575,int(YP),GetColor(150,150,255),1);//0���
		suu_bmf(X+75,YP,1,i,0);
		i += L;
	}

	//�O���t�\��
	for(int S=0;S<SM;S++){
		XP = X+100;
		YP = Y+480-int(double(ST[0][S]-MIN)*430/MAX);
		for(i=1;i<MAX_M;i++){
			XP2 = X+100+int(double(i+1)*450/MAX_M);
			if(i%12 == 0){
				DrawLine(XP2,Y+481,XP2,Y+25,GetColor(100,100,200),1);//0���
			}
			YP2 = Y+480-int(double(ST[i][S]-MIN)*430/MAX);
			DrawLine(XP,YP,XP2,YP2,shop[S].color,1);
			//f(i == wind.syu_year*12 + wind.syu_mon +1){
			//	DrawRotaGraph(XP,YP,2,0,gra.ico[90+S],TRUE,0);
			//	DrawCircle(XP,YP,3,color.ao,1);
			//}else{
				DrawCircle(XP,YP,3,shop[S].color,1);
			//}

			//if(i == wind.syu_year*12 + wind.syu_mon +1) DrawCircle(XP,YP,3,color.ao,1);
			//else	DrawCircle(XP,YP,3,color.aka,1);
	
			XP = XP2;
			YP = YP2;

			if(i == MAX_M-1){
				DrawCircle(XP,YP,3,shop[S].color,1);
				//if(wind.graph_hyouuji != 15+19)DrawRotaGraph(XP,YP,2,0,gra.ico[shop[S].icon],TRUE,0);
			}
		}
	}
	waku( X , Y+510	,600,60,3);
	if(wind.graph_hyouuji == 15+19){
		//�l��
		mes(X+30,Y+530,"�n���^�[��",color.kuro,color.siro,0);
		DrawLine(X+130,Y+540,X+230,Y+540,shop[0].color,2);
		mes(X+250,Y+530,"���Ґ�",color.kuro,color.siro,0);	
		DrawLine(X+325,Y+540,X+425,Y+540,shop[1].color,2);
		return 1;
	}
	//�\���F�Ή�
	for(int S=0;S<SM;S++){
		DrawRotaGraph(X+30+S*100,Y+540,2,0,gra.ico[shop[S].icon],TRUE,0);
		DrawLine(X+50+S*100,Y+540,X+100+S*100,Y+540,shop[S].color,2);
	}


	return 1;
}
int DRA::win_2s(int N,int X,int Y/*����A�C�R���q*/){

	int MP;//����,�J���i�s��
	int col;
	int PL,PS;
	int KAI = 0;//�J����or������
	if(shop[P].wep_cre[N] != 2) KAI = 1;

	//����\��
	if(N == Inp.d_no && Inp.d_type < 4)							waku_c(X,Y,32,32,100,255,100);//������ݒ�
	else if(Inp.d_type == 6 && emp[Inp.d_no].shift_n == N) 	waku_c(X,Y,32,32,150,255,150);//�V�t�g����
	else 	waku_c(X,Y,32,32,255,255,255);

	//�������x�g
	if(KAI == 1)	MP = min(shop[P].wep_make[N] * 128 / wep[N].create_time,128);
	else			MP = min(int(shop[P].wep_make[N] * 128 / wep[N].make_time / 100 * shop[P].time_j[N]),128);//0~100

	if(shop[P].wep_make_now[N]>0)	PL=0;
	else							PL=100;

	if( KAI == 1)								col = GetColor(50+PL,50+PL,50+PL);
	else	if( shop[P].wep_make_t[N]%2==0 )	col = GetColor(255,100+PL,100+PL);
	else										col = GetColor(100+PL,150+PL,255);

	DrawLine(X		,Y		,X+32	,Y	 ,col,2);
	DrawLine(X+32	,Y		,X+32	,Y+32,col,2);
	DrawLine(X		,Y+32	,X+32	,Y+32,col,2);
	DrawLine(X		,Y		,X		,Y+32,col,2);

	if( KAI == 1)								col = GetColor(100+PL,255,100+PL);
	else	if( shop[P].wep_make_t[N]%2==1 )	col = GetColor(255,100+PL,100+PL);
	else										col = GetColor(100+PL,150+PL,255);

	//�����i�s��a�P
	DrawLine(			X				,Y				,X+min(MP,32),Y,col,2);
	if(MP>32)DrawLine(	X+32			,Y				,X+32,Y+min(MP-32,32),col,2);
	if(MP>64)DrawLine(	X+max(96-MP,0)	,Y+32			,X+32,Y+32,col,2);
	if(MP>96)DrawLine(	X				,Y+128-MP,X,Y+32,col,2);

	draw.wep_icon(16+X,16+Y,1,N);

	if(KAI == 0){//������
		if(draw.sell_t[N] > 0){
			SetDrawBright(255,255-draw.sell_t[N]*20,255-draw.sell_t[N]*20);	
			draw.sell_t[N] -= opt.speed;
			if(draw.sell_t[N] < 0) draw.sell_t[N] = 0;
		}
		mes_bmf(X+4,Y+30,"X",1);
		suu_bmf(X+30,Y+30,1,shop[P].wep_rest[N],0);
		SetDrawBright(255,255,255);
	}else{//�J����
		DrawRotaGraph(X+24,Y+8,1,0,gra.ico[7],0);

	}

	//�X�e�[�^�X�\��
	switch(wind.wep_sort){
		case 0://�U����
			PL = int(wep[N].atk*shop[P].atk_j[N]);
			PS = 2;
		break;
		case 1://�ϋv
			PL = int(wep[N].dur*shop[P].dur_j[N]);
			PS = 2;
		break;
		case 2://�l�C���v
			PS = 2;
			if(wep[N].ninki[0]>0){
				SetDrawBright(150,150,255);
				PL = int(wep[N].ninki[0] * shop[P].ninki_j[N]);
			}else if(wep[N].ninki[1]>0){
				SetDrawBright(255,150,150);
				PL = int(wep[N].ninki[1] * shop[P].ninki_j[N]);
			}else{
				SetDrawBright(150,255,150);
				PL = int(wep[N].ninki[2] * shop[P].ninki_j[N]);
			}
		break;
		case 3://�H��
			PS = 2;
			PL = int(wep[N].make_time *10 * shop[P].time_j[N] / 100);
		break;
		case 4://�l�i
			PS = 2;
			PL = int(wep[N].price * shop[P].price_rate / 100);
		break;
		case 5://�ׂ�
			PS = 2;
			PL = int(wep[N].price * (shop[P].price_rate - wep[N].seizou_cost * shop[P].cost_j[N] ) / 100);
		break;
		default://��\��
			return 1;
		break;
	}

	if(wind.wep_sort >= 3){
		syou_bmf(X+30,Y+4*PS,PL,2,5);
	}else if(KAI == 0){
		suu_bmf(X+30,Y+4*PS,PS, PL,2,5);
	}
	
	SetDrawBright(255,255,255);	
	return 1;
}
int DRA::win_5s(int N,int X,int Y/*�l���A�C�R���q*/){

	int HP,MAN;

	if(Inp.d_type >= 5 && Inp.d_type <= 6 && Inp.d_no == N)	waku_c( X,   Y,32,32,100,255,100);//�I��
	else if(emp[N].shift != emp[N].shift_n)				waku_c( X,   Y,32,32,100,100,255);//�V�t�g�ύX
	else													waku_c( X,   Y,32,32,255,200,200);//�I��or���퓯��

	DrawRotaGraph(16+X,16+Y,2,0,gra.unit[emp[N].gra][1],TRUE,0);//�L�����摜

	int IC;
	if(emp[N].rest > 1		) IC = 7;
	else if(emp[N].rest > 0 ) IC = 8;
	else if(emp[N].tension >= 140) IC = 0;
	else if(emp[N].tension >= 120) IC = 1;
	else if(emp[N].tension >= 100) IC = 2;
	else if(emp[N].tension >= 80)  IC = 3;
	else						   IC = 4;

	if(emp[N].pb_rest > 0) SetDrawBright(255,255,0);
	if(emp[N].pb_rest < 0) SetDrawBright(122,122,122);

	DrawRotaGraph(22+X, 2+Y,1,0,gra.emo[IC],TRUE,0);//�̒����o��
	SetDrawBright(255,255,255);

	if(emp[N].rest>1){//�����×{
		suu_bmf(22+X,Y+4,1,emp[N].rest,2);//�x�ݓ���
	}

	//�c��̗�
	HP = int(emp[N].hp)*32/100;//0~100

	//�̗͕\��
	int COL;
	if(HP>24)		COL = GetColor(0,0,255);
	else if(HP>16)	COL = GetColor(200,200,0);
	else			COL = GetColor(255,0,0);

	DrawLine(X,Y+32,X+HP,Y+32,COL,3);

	switch(wind.emp_hyouji){
		case 0://HP
		suu_bmf(X+26,Y+26,2,int(emp[N].hp),2,5);
		break;
		case 1://LV
		mes_bmf(X+6,Y+26,"L",1);
		suu_bmf(X+26,Y+24,2,emp[N].lv,2,5);
		break;
		case 2://STA
		suu_bmf(X+26,Y+26,2,emp[N].st[1],2,5);
		break;
		case 3://STB
		suu_bmf(X+26,Y+26,2,emp[N].st[2],2,5);
		break;
		case 4://����
		suu_bmf(X+18,Y+26,2,emp[N].pay_money/10,2,5);
		suu_bmf(X+28,Y+28,1,emp[N].pay_money%10,2,5);
		break;
		case 5://����
			
		if		(int(emp[N].b_w)>=100)	{SetDrawBright( 255 , 255 , 255 ) ;mes_bmf(X+24,Y+24,"W",2);}
		else  if(int(emp[N].b_w)>= 80)	{SetDrawBright( 220 , 220 , 220 ) ;mes_bmf(X+24,Y+24,"W",2);}
		else  if(int(emp[N].b_w)>= 60)	{SetDrawBright( 190 , 190 , 190 ) ;mes_bmf(X+24,Y+24,"G",2);}
		else  if(int(emp[N].b_w)>= 40)	{SetDrawBright( 160 , 160 , 160 ) ;mes_bmf(X+24,Y+24,"G",2);}
		else  if(int(emp[N].b_w)>= 20)	{SetDrawBright( 120 , 120 , 120 ) ;mes_bmf(X+24,Y+24,"B",2);}
		else								{SetDrawBright( 0 , 0 , 0 )	  ;mes_bmf(X+24,Y+24,"B",2);}
		SetDrawBright( 255 , 255 , 255 ) ;
		break;
		case 6://����
		MAN = emp[N].manzoku_cul();
		//��������
		if(MAN<-20)			{SetDrawBright( 100 , 100 , 255 ) ;mes_bmf(X+24,Y+24,"S",2);}
		else  if(MAN<0)		{SetDrawBright( 200 , 200 , 255 ) ;mes_bmf(X+24,Y+24,"A",2);}
		else  if(MAN<50)									   mes_bmf(X+24,Y+24,"B",2);
		else  if(MAN<100)	{SetDrawBright( 255 , 200 , 200 ) ;mes_bmf(X+24,Y+24,"C",2);}
		else  if(MAN<200)	{SetDrawBright( 255 , 100 , 100 ) ;mes_bmf(X+24,Y+24,"D",2);}
		else				{SetDrawBright( 255 , 0 , 0 )	  ;mes_bmf(X+24,Y+24,"F",2);}
		SetDrawBright( 255 , 255 , 255 ) ;
		break;
	}


	if(draw.lv_t[N] > 0){//���x���㏸
		draw.lv_t[N] -= opt.speed;
		SetDrawBright( 255 , 100 , 100 ) ;
		mes_bmf2(X+14,Y+6 + draw.lv_t[N] / 5 ,"up",2);
		SetDrawBright( 255 , 255 , 255 ) ;
	}



	return 1;
}
int DRA::win_7_seido(int X,int Y){
	
	int XP=0,YP=0,CNT = 0;
	std::string name;

	for(int M=0;M<MANA_M;M++){

		if(M%60 == 0){//���x���\��
			if(CNT>0)YP+=40;
			CNT = 0;
			switch(M/60){
				case 0:name = "�o�c";break;
				case 1:name = "����";break;
				case 2:name = "�H��";break;
				case 3:name = "�J��";break;
				case 4:name = "��`";break;
			}
			XP=0;
			waku_c(X+12,Y+YP,260,25,150,250,150);
			mes(X+38,Y+YP+6,name.c_str(),color.kuro,color.siro,2);
			DrawRotaGraph(X+26,Y+YP+13,1,0,gra.ico[data.mana_icon[M/60]],TRUE,0);//����
			YP+=30;
		}

		if(shop[P].mana_cnt[M] > 0 && mana[M].seido==1){
			if(XP >= 240){
				XP  = 0;
				YP += 40;
			}
			draw.mana_icon(X+XP+20,Y+YP,M,1);
			XP+=40;
			CNT = 1;
		}

	}

	wind.scrm[6] = 428-38 + YP + 135 - 14;
	wind.smax[6] = data.window_y - 96;

	return 1;
}
int DRA::win_help(){
	//�w���v�E�B���h�E���C��

	if( wind.info_t <=0 || wind.info_no<0){
		win_hmes("");
		return 1;
	}

	switch(wind.info_t){
		case  1: win_1h();break;//�q�ꗗ
		case  2: win_2h();break;//���i�ꗗ
		case  3: win_3h();break;//�J��
		case  4: win_4h();break;//���l
		case  5: win_5h();break;//�l��/�X��
		case  6: win_6h();break;//�l��/�E�l
		case  7: win_7h();break;//���
		case  8: win_8h();break;//���O
		case  9: win_9h();break;//���x�E�V�F�A
		case 10:win_10h();break;//��p
		case 11:win_11h();break;//�}�b�v
		case 12:win_12h();break;//���̂ق�
	}

	return 1;
}
int DRA::win_1h(){

	int X,Y,H;
	int i,ICO,N,G;
	std::string str;

	if(wind.info_no == HUN_M){//�X����
		win_hmes("���݂̋q��/�{���̋q��/���X���܂߂��{���̋q��@");
	}

	if(wind.info_no >=0 && wind.info_no < HUN_M){//�q���

		H = wind.info_no;
		if(hun[H].act == 4) return 1;

		win_hmes("",360,194);
		if(Inp.m_x<data.window_x-360) X = Inp.m_x;
		else						  X = Inp.m_x - 360;
		if(Inp.m_y<data.window_y-183) Y = Inp.m_y;
		else						  Y = Inp.m_y - 183;
		//�q�A�C�R���A���x���A�����A�X�e�[�^�X�A�����A�������퐔

		DrawRotaGraph(X+20,Y+50,2,0,gra.unit[jobs[hun[H].job].gra][1],1,0);
		DrawRotaGraph(X+50,Y+50,2,0,gra.emo[16+hun[H].wep_t],1,0);
		suu_bmf(X+60,Y+60,2,hun[H].lv,2,6);
		//���o�[
		waku(X+80,Y+38,265,28,6);
		int iro[3];
		char jyoutai[10];

		switch(hun[H].act){
			case 1://�ҋ@
				iro[0] = 0;iro[1] = 255;iro[2] = 0;
				sprintf_s(jyoutai,10,"waiting");
			break;
			case 2://�ڋq��
				iro[0] = 0;iro[1] = 0;iro[2] = 255;
				sprintf_s(jyoutai,10,"shopping");
			break;
			case 3://�N���[�}�[
				iro[0] = 255;iro[1] = 0;iro[2] = 0;
				sprintf_s(jyoutai,10,"claiming");
			break;
			case 4:
				sprintf_s(jyoutai,10,"go out");
			break;
		}

		if(hun[H].act!=4){
			waku_c(X+82,Y+39,hun[H].wait*261/hun[H].talk_max,26
				,iro[0],iro[1],iro[2]);
		}

		mes_bmf(X+82,Y+39,jyoutai,2);

		for(i=0;i<5;i++){
			switch(i){
				case 0:str = "�̗�"		;ICO = 44;N=hun[H].sta[0]	  ;G=N/4   ;break;
				case 1:str = "�U��"		;ICO = 38;N=hun[H].sta[1]	  ;G=N*3	 ;break;
				case 2:str = "�h��"		;ICO = 39;N=hun[H].sta[2]     ;G=N*3	 ;break;
				case 3:str = "�q��"		;ICO = 54;N=hun[H].sta[3]	  ;G=N*3	 ;break;
				case 4:str = "�\�Z"		;ICO = 53;N=hun[H].cul_yosan();G=N/1000;break;
			}
			if(G>160)   G = 160;
			if(N>99999) N = 99999;

			waku(X+10,70+Y+i*22  ,60,20,6);
			waku(X+75,70+Y+i*22  ,105,20,6);
			mes(35+X,73+Y+i*22,str.c_str(),color.kuro,color.siro,2);
			DrawRotaGraph(20+X,80+Y+i*22,1,0,gra.ico[ICO],TRUE,0);

			if( i == 0){//�̗�
				waku_c(X+185,70+Y+i*22 ,G,20,255,100,100);
				waku_c(X+185,70+Y+i*22 ,hun[H].hp/4,20,255,150,0);
			}else{//����ȊO
				waku_c(X+185,71+Y+i*22 ,G,20,255,150+i%2*105,0);
			}
			suu_bmf(170+X,81+Y+i*22,2,N,0);
		}
	}

	return 1;
}
int DRA::win_2h(){
	if(wind.info_no<1000){//����
		wep_info(wind.info_no);
	}else {//�^�u,�\�[�g�{�^��
		switch(wind.info_no){
			case 1000:
				win_hmes("�ڋʏ��i@�����ɓ��ꂽ����͂Q�����Ŕ̔����W�q�{�Q�O��@����ɖڋʏ��i���ʂ𔭊����܂�@");
			break;
			case 1001:
				win_hmes("�V�����J�����ꂽ����͂��̃��X�g�ɓ���܂�@");
			break;
			case 1002:
				win_hmes("���n@");
			break;
			case 1003:
				win_hmes("���n@");
			break;
			case 1004:
				win_hmes("���n@");
			break;
			case 1005:
				win_hmes("�|�n@");
			break;
			case 1006:
				win_hmes("�������Ȃ�����͂����ցA�폜�͂���܂���@");
			break;
			case 2000:
				win_hmes("�U���͂�\��@�_�u���N���b�N�Ń\�[�g@");
			break;
			case 2001:
				win_hmes("�ϋv�͂�\��@�_�u���N���b�N�Ń\�[�g@");
			break;
			case 2002:
				win_hmes("�W�q�͂�\��@�_�u���N���b�N�Ń\�[�g@");
			break;
			case 2003:
				win_hmes("�������Ԃ�\��@�_�u���N���b�N�Ń\�[�g@");
			break;
			case 2004:
				win_hmes("������\��@�_�u���N���b�N�Ń\�[�g@");
			break;
			case 2005:
				win_hmes("�e����\��@�_�u���N���b�N�Ń\�[�g@");
			break;
			case 2006:
				win_hmes("���i�\���䗦�ƁA�q�ɂ̏��@");
			break;
		}
	}

	return 1;
}
int DRA::win_3h(){

	return 1;
	if(wind.info_no<1000){//�J������
		wep_info(wind.info_no);
	}
	return 1;
}
int DRA::win_4h(){

	if(wind.info_no<1000){//���l�ԍ�
		emp_info(wind.info_no);
	}else{
		switch(wind.info_no - 1000){
			case 0:
				win_hmes("�X���̋��E�҈ꗗ@");
			break;
			case 1:
				win_hmes("�E�l�̋��E�҈ꗗ@");
			break;
			case 2:
				win_hmes("���x����\��@�_�u���N���b�N�Ń\�[�g@");
			break;
			case 3:
				win_hmes("�g�o��\��@�_�u���N���b�N�Ń\�[�g@");
			break;
			case 4:
				win_hmes("�q�J�A�����͂�\��@�_�u���N���b�N�Ń\�[�g@");
			break;
			case 5:
				win_hmes("�ڋq�A�J���͂�\��@�_�u���N���b�N�Ń\�[�g@");
			break;
			case 6:
				win_hmes("�X�L����\��@�_�u���N���b�N�Ń\�[�g@");
			break;
			case 7:
				win_hmes("������\��@�_�u���N���b�N�Ń\�[�g@");
			break;
			case 8:
				win_hmes("�v��������\��@�_�u���N���b�N�Ń\�[�g@");
			break;
		}
	}

	return 1;
}
int DRA::win_5h(){

	if(wind.info_no<1000){//�X��
		emp_info(wind.info_no);
	}else{//�^�u
		switch(wind.info_no){
			case 1400:
				win_hmes("�V�t�g�E�������@");
			break;
			case 1401:
				win_hmes("�V�t�g�E�������@");
			break;
			case 1402:
				win_hmes("�V�t�g�E�������@");
			break;
			case 1403:
				win_hmes("�V�t�g�E�|�����@");
			break;
			case 2000:
				win_hmes("���݂g�o�\��@");
			break;
			case 2001:
				win_hmes("���x���\��@");
			break;
			case 2002:
				win_hmes("���͕\��@");
			break;
			case 2003:
				win_hmes("�ڋq�͕\��@");
			break;
			case 2004:
				win_hmes("�����\��@");
			break;
			case 2005:
				win_hmes("�Љ�l�x�\��@");
			break;
			case 2006:
				win_hmes("�����x�\��@");
			break;
			case 2007:
			case 2008:
				if(data.taiguu_ok == 1)win_hmes("�����̃V�t�g�\���؂�ւ�@");
			break;
			case 2009:
				win_hmes("�c�Ǝ��Ԃ͕ύX�o���܂���@");
			break;
			case 2010:
				win_hmes("�������̂܂�@");
			break;
			case 2011:
				win_hmes("�����������]�ƈ��͂��̃t�H���_��@�������P�O��(�����R�O���ȉ��̏ꍇ�R��)�グ�A���ЂɌX���܂�@");
			break;
			case 2012:
				win_hmes("�����������]�ƈ��͂��̃t�H���_��@�������P�O�������A�В{�ɌX���܂�@");
			break;
			case 2013:
				win_hmes("���ق������]�ƈ��͂��̃t�H���_��@���ق������͋������{����Ȃ��Ƃ����܂���@");
			break;
		}
	}
	return 1;
}
int DRA::win_6h(){

	if(wind.info_no<1000){//�E�l
		emp_info(wind.info_no);
	}else if(wind.info_no<2000){//�^�u
		wep_info(wind.efold_s[wind.info_no-1000]);
	}else{//�\�[�g�{�^����
		switch(wind.info_no){
			case 2000:
				win_hmes("���݂g�o�\��@");
			break;
			case 2001:
				win_hmes("���x���\��@");
			break;
			case 2002:
				win_hmes("�����͕\��@");
			break;
			case 2003:
				win_hmes("�J���͕\��@");
			break;
			case 2004:
				win_hmes("�����\��@");
			break;
			case 2005:
				win_hmes("�Љ�l�x�\��@");
			break;
			case 2006:
				win_hmes("�����x�\��@");
			break;
			case 2007:
			case 2008:
				if(data.taiguu_ok == 1)win_hmes("�����̃V�t�g�\���؂�ւ�@");
			break;
			case 2009:
				if(wind.ok[9] == 0)	win_hmes("�H�[�ғ�����@�ύX�o���܂���@");
				else				win_hmes("�H�[�ғ�����@���l���́����N���b�N�ŕύX@�T�̏��߂ɔ��f����܂�@");
			break;
			case 2010:
				win_hmes("�������̂܂�@");
			break;
			case 2011:
				win_hmes("�����������]�ƈ��͂��̃t�H���_��@�������P�O��(�����Q�O���ȉ��̏ꍇ�Q��)�グ�A���ЂɌX���܂�@");
			break;
			case 2012:
				win_hmes("�����������]�ƈ��͂��̃t�H���_��@�������P�O�������A�В{�ɌX���܂�@");
			break;
			case 2013:
				win_hmes("���ق������]�ƈ��͂��̃t�H���_��@���ق������͋������{����Ȃ��Ƃ����܂���@");
			break;
		}
	}

	return 1;
}
int DRA::win_7h(){

	switch(wind.info_no){//��Џ��
		case 0:
			win_hmes("�Ж�@");//�Ж�
		break;
		case 1:
			win_hmes("������@");//����
		break;
		case 2:
			win_hmes("����LV@");//�]�ƈ�
		break;
		case 3:
			win_hmes("�u���b�N�x@");//�u���b�N�x
		break;
		case 4:
			win_hmes("�m���x@");//�_��[�i
		break;
		case 5:
			win_hmes("�_��[�i��/���ݐ�@");//�_��[�i
		break;
		case 6:
			win_hmes("�x����@��x�������[�e�[�V�����x����@");//��x��
		break;
		case 7:
			win_hmes("�Z�p���x��@�o�[�����^����LVUP@");//�J�����x��
		break;
		case 8:
			win_hmes("�������x��@");
		break;
		case 9:
			win_hmes("�B�S���x��@");
		break;
		case 10:
			win_hmes("�׍H���x��@");
		break;
		case 11:
			win_hmes("���ێ����Ɗ���@�ێ����ɂ��{�[�i�X�A50%���Ń{�[�i�X�Q�{@");
			break;
		case 12:
			win_hmes("���Њ�@����{�[�i�X:�l�o��+0.1/10%@");
			break;
		case 13:
			win_hmes("��l���@����{�[�i�X:�V�ăn���^�[�D���x+5/10%@");
			break;
		case 14:
			win_hmes("�z�R�J����@����{�[�i�X:�����R�X�g-1%/10%@");
			break;
		case 15:
			win_hmes("���b��������@����{�[�i�X:���ǌo��+1%/10%@");
			break;
		case 16:
			win_hmes("�V���Њ�@����{�[�i�X:��`����+1%/10%@");
			break;
		break;
		case 2000:
			win_hmes("�o�c����-���x@");
		break;
		case 2001:
			win_hmes("��������-���x@");
		break;
		case 2002:
			win_hmes("�H������-���x@");
		break;
		case 2003:
			win_hmes("�J������-���x@");
		break;
		case 2004:
			win_hmes("��`����-���x@");
		break;
	}

	if(wind.info_no >= 1000 && wind.info_no < 2000)
	{
		seido_info(wind.info_no - 1000);
	}

	return 1;
}
int DRA::win_8h(){

	if(wind.info_no<1000){//���O
		win_hmes("�l�X�ȏ�񂪃��O�ŕ\������܂�@");
		//�Ƃ肠��������
	}
	return 1;
}
int DRA::win_9h(){

	switch(wind.info_no){//���x�E�V�F�A
		case 0:
			win_hmes("�N�P�ʕ\��@");
		break;
		case 1:
			win_hmes("���P�ʕ\��@");
		break;
		case 2:
			win_hmes("���P�ʕ\��@");
		break;
		case 3:
			win_hmes("�ڍו\��@");
		break;
		case 4:
			win_hmes("���t�ύX@NOW�I���Ō��݂̓��t");
		break;
		case 5:
			win_hmes("����������̐�@");
		break;
		case 6:
			win_hmes("�g�[�^������@");
		break;
		case 7:
			win_hmes("���̔��さ�V�F�A@");
		break;
		case 8:
			win_hmes("���̔��さ�V�F�A@");
		break;
		case 9:
			win_hmes("���̔��さ�V�F�A@");
		break;
		case 10:
			win_hmes("�|�̔��さ�V�F�A@");
		break;
		case 11:
			win_hmes("���X�����q�̐�@");
		break;
		case 12:
			win_hmes("������������̐�@");
		break;
		case 13:
			win_hmes("����̐����J���Ɏg��������@");
		break;
		case 14:
			win_hmes("�X���ƐE�l�̋���@");
		break;
		case 15:
			win_hmes("�o�c��p�Ɏg���������{�݂��q�Ɏg�p����@");
		break;
		case 16:
			win_hmes("�ŋ��{���q�{�_��̔���@");
		break;
		case 17:
			win_hmes("�g�[�^���̗��v@");
		break;
		case 18:
			win_hmes("����@");
		break;
		case 20:
			win_hmes("���x�ڍו\���A���ڃN���b�N�ŃO���t�\��@");
		break;
		case 21:
			win_hmes("�O���t�\���A�N���b�N�Ŗ߂�@");
		break;
		case 22:
			win_hmes("������@");
		break;
		case 23:
			win_hmes("����@");
		break;
		case 24:
			win_hmes("�l��@");
		break;

	}

	return 1;
}
int DRA::win_10h(){
	//��p����
	std::ostringstream stream;

	if(wind.info_no<MANA_M){//
		mana_info(wind.info_no);
	}else{//MP
		switch(wind.info_no){
			case 1000:
				stream << "�o�c�n��p@EXP " << shop[P].bumon_exp[0]/10 << " / " << shop[P].bumon_lv[0]*shop[P].bumon_lv[0]*10 + 40 << "@";
				win_hmes(stream.str().c_str());
			break;
			case 1001:
				stream << "�����n��p@EXP " << shop[P].bumon_exp[1]/10 << " / " << shop[P].bumon_lv[1]*shop[P].bumon_lv[1]*10 + 40 << "@";
				win_hmes(stream.str().c_str());
			break;
			case 1002:
				stream << "�H���n��p@EXP " << shop[P].bumon_exp[2]/10 << " / " << shop[P].bumon_lv[2]*shop[P].bumon_lv[2]*10 + 40  << "@";
				win_hmes(stream.str().c_str());
			break;
			case 1003:
				stream << "�J���n��p@EXP " << shop[P].bumon_exp[3]/10 << " / " << shop[P].bumon_lv[3]*shop[P].bumon_lv[3]*10 + 40  << "@";
				win_hmes(stream.str().c_str());
			break;
			case 1004:
				stream << "��`�n��p@EXP " << shop[P].bumon_exp[4]/10 << " / " << shop[P].bumon_lv[4]*shop[P].bumon_lv[4]*10 + 40  << "@";
				win_hmes(stream.str().c_str());
			break;
			case 2000:
				win_hmes("����MP/�����̉񕜗�@");
			break;
			case 3000:
			case 3001:
			case 3002:
			case 3003:
			case 3004:
			case 3005:
				win_hmes("�\����p��ސ؂�ւ�@");
			break;
			case 3006:
			case 3007:
				win_hmes("�\����p��ސ؂�ւ�@");
			break;
		}
	}
	return 1;
}
int DRA::win_11h(){
	int X,Y;
	//�_���W����
	win_hmes("�_���W�����̏���\��",190,130);
	if(Inp.m_x<data.window_x-190) X = Inp.m_x;
	else						  X = Inp.m_x - 190;
	if(Inp.m_y<data.window_y-130) Y = Inp.m_y;
	else						  Y = Inp.m_y - 130;

	//LV�@�T���x�@�{�X�����@���������X�^�[
	int HP = (dun[wind.info_no].boss_hp * 101 - 1) /dun[wind.info_no].boss_max;

	waku(X+10,Y+26,165,20,6);
	waku(X+10,Y+51,60,20,6);
	waku(X+10,Y+76,60,20,6);
	waku(X+10,Y+101,60,20,6);

	waku_c(X+75,Y+51,wind.info_no*2,20,255,100,100);
	waku_c(X+75,Y+76,100-dun[wind.info_no].seek,20,255,100,100);
	waku_c(X+75,Y+101,HP,20,255,100,100);

	mes(X+18,30+Y,"���󂵂��������J�n",color.kuro,color.siro,2);

	mes(X+18,55+Y,"�k�u",color.kuro,color.siro,2);
	suu_bmf(X+165,61+Y,2,wind.info_no,0);

	mes(X+18,80+Y,"���J�x",color.kuro,color.siro,2);
	suu_bmf(X+165,86+Y,2,100-dun[wind.info_no].seek,0);

	mes(X+18,105+Y,"�{�X",color.kuro,color.siro,2);
	suu_bmf(X+165,111+Y,2,HP,0);

	return 1;
}
int DRA::win_12h(){
	//�E�B���h�E��,�㕔�^�u
	switch(wind.info_no){
		case 0:
			win_hmes("���q��@�e�X�̗��q�󋵁A���X�q�̏ڍׂ�\��@");//�q
		break;
		case 1:
			win_hmes("����ꗗ@���Y�\�ȕ���̈ꗗ@�h���b�O���h���b�v���t�H���_����@�E�l�Ƀh���b�v���V�t�g�ύX@");//����
		break;
		case 2:
			win_hmes("�X�ܕ��i@���X�̑O�̏�@");//�J��
		break;
		case 3:
			win_hmes("���l�ꗗ@�]�ƈ���W�ɉ��債�Ă����l�ނ̈ꗗ@�N���b�N������/�L�����Z��@");//���l
		break;
		case 4:
			win_hmes("�X���ꗗ@�h���b�O���h���b�v���V�t�g�ύX@");//�l���E�X
		break;
		case 5:
			win_hmes("�E�l�ꗗ@����or�J���ꗗ�Ƀh���b�v���V�t�g�ύX@");//�l���E�H
		break;
		case 6:
			win_hmes("��Џ��@���Ђ̃X�e�[�^�X@");//���
		break;
		case 7:
			win_hmes("���O�ꗗ@�ŋ߂̏o������\��@");//���O
		break;
		case 8:
			win_hmes("���x���@�N�������̎��x��@");//���x
		break;
		case 9:
			win_hmes("�o�c��p�ꗗ@�N���b�N���g�p�\��/�L�����Z��@");//�o�c��p
		break;
		case 10:
			win_hmes("�o�c�ڕW@�����������@");//�}�b�v�\��
		break;
		case 11:
			win_hmes("�}�b�v�\��@�S�ẴE�B���h�E��\��/��\����؂�ւ���@�}�b�v�����₷�����܂�@");//�}�b�v�\��
		break;
		case 12:
			win_hmes("�Q�[���I��@�N���b�N�Ō��݂̏�Ԃ��Z�[�u���A�I�����܂�@");//�^�C�g����
		break;
		case 13:
			win_hmes("�R���t�B�O@�E�B���h�E�T�C�Y��BGM���ʓ���ύX@");//�R���t�B�O
		break;
		case 14:
			win_hmes("�Q�[���X�s�[�h@�N���b�N�ŃQ�[���X�s�[�h��ύX@");//�Q�[���X�s�[�h
		break;
		case 15:
			win_hmes("�w���v@�w���v���j���[���J���܂�@");//�^�C�g����
		break;
		case 20:
			win_hmes("���݂̓��t@");//���t
		break;
		case 21:
			win_hmes("���݂̎���@");//����
		break;
		case 22:
			win_hmes("�����̓V�C�A�V�C�������Ƌq��������@");//�V�C
		break;
		case 23:
			win_hmes("�c�Ə��@");//�o��
		break;
		case 24:
			win_hmes("���݂̗��s@");//�o��
		break;
		case 25:
			win_hmes("�t�����e�B�A�ɂ���`���҂̐�@");//�`���Ґ�
		break;
		case 26:
			win_hmes("���Ђ̎���@");//����
		break;
		case 27:
			win_hmes("��Ђ̒m���x@");//�`���Ґ�
		break;
	}

	return 1;
}
int DRA::win_htai(){
	//�����ω��\��
	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 240 ) ;//�������Ńw���v�E�B���h�E
	draw.waku(Inp.m_x-35,Inp.m_y-30,70,30,3);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

	if(emp[wind.info_taiguu].chan_tai<0){//����
		suu_bmf(Inp.m_x+10,Inp.m_y-14,2,100,2,6);
		mes(Inp.m_x+18,Inp.m_y-25,"%",color.aka,color.kuro,0);
		mes(Inp.m_x-30,Inp.m_y-25,"-",color.aka,color.kuro,0);
	}else{
		suu_bmf(Inp.m_x+10,Inp.m_y-14,2,emp[wind.info_taiguu].chan_tai*5,2,6);
		mes(Inp.m_x+17,Inp.m_y-25,"%",color.ao,color.kuro,0);
		mes(Inp.m_x-28,Inp.m_y-25,"+",color.ao,color.kuro,0);
	}

	return 1;
}
int DRA::win_hmes(const char str[],int XS,int YS,int N){
	//���݂͂̂̃w���v//�f���s��
	//�E�B�h�E�͔�������
	int X,Y,G,C;

	std::string st[10];
	st[0] = str;

	for(G=0;G<10;G++){
		C = st[G].find("@");
		if(C==-1)break;//@��������ΏI��
		st[G+1] = st[G].substr(C+1);
		st[G]   = st[G].substr(0,C);
		YS += 20;
	}

	for(C=0;C<G;C++){
		XS = max(st[C].size()*9+13,unsigned int(XS));
	}

	//���_���W�I��
	if(Inp.m_x < data.window_x - XS) X = Inp.m_x;
	else							 X = Inp.m_x - XS;
	if(Inp.m_y < data.window_y - YS) Y = Inp.m_y;
	else							 Y = Inp.m_y - YS;	

	waku_help(X,Y,XS,YS,N);

	mes_bmf(X+16,Y+16,"HELP",2);

	for(C=0;C<G;C++){
		DrawStringToHandle(X+7,Y+27+C*20,st[C].c_str(),color.kuro,data.font[0]);
		DrawStringToHandle(X+6,Y+26+C*20,st[C].c_str(),color.siro,data.font[0]);
		//mes_info(X+7,Y+27+C*20,st[C].c_str());		
	}

	return 1;
}
int DRA::win_tmes(const char str[],int X,int Y,int N,int S){
	//���݂͂̂̃w���v//�f���s��
	//�E�B�h�E�͔�������
	int G,C;
	int XS = 0;
	int YS = 10;

	X += data.window_x/2-480;
	Y += data.window_y/2-360;

	std::string st[10];
	st[0] = str;

	for(G=0;G<10;G++){
		C = st[G].find("@");
		if(C==-1)break;//@��������ΏI��
		st[G+1] = st[G].substr(C+1);
		st[G]   = st[G].substr(0,C);
		YS += S * 10;
	}

	for(C=0;C<G;C++){
		XS = max(st[C].size()*9*S/2+13,unsigned int(XS));
	}

	//���_���W�I��
	draw.waku(X,Y,XS,YS,N);

	for(C=0;C<G;C++){
		DrawStringToHandle(X+6+S*2/3,Y+6+S*2/3+C*10*S,st[C].c_str(),color.kuro,data.font[S-2]);
		DrawStringToHandle(X+6,Y+6+C*10*S,st[C].c_str(),color.siro,data.font[S-2]);		
	}

	return 1;
}

int DRA::seido_info(int M){

	int X,Y;

	win_hmes("",450,140);
	if(Inp.m_x<data.window_x-450) X = Inp.m_x;
	else						  X = Inp.m_x - 450;
	if(Inp.m_y<data.window_y-140) Y = Inp.m_y;
	else						  Y = Inp.m_y - 140;

	//��{���
	waku(X+6,Y+30,230,32,6);
	waku(X+6,Y+66,430,66,6);
	draw.mana_icon(X+6,Y+26,M,1);
	mes(X+44,Y+37,mana[M].name.c_str(),color.kuro,color.siro,0);

	//������
	mes_stri(X+10,Y+ 70,mana[M].seido_h.c_str());
	return 1;
}
int DRA::mana_info(int M){

	int X,Y,T;

	T = mana[M].type;

	win_hmes("",450,140);
	if(Inp.m_x<data.window_x-450) X = Inp.m_x;
	else						  X = Inp.m_x - 450;
	if(Inp.m_y<data.window_y-140) Y = Inp.m_y;
	else						  Y = Inp.m_y - 140;

	//��{���
	waku(X+6,Y+30,240,32,6);

	waku(X+6,Y+66,430,66,6);
	if(shop[P].use_mana == M)waku_c(X+8,Y+32,236,28,255,200,200);

	draw.mana_icon(X+6,Y+26,M,2);

	mes(X+44,Y+37,mana[M].name.c_str(),color.kuro,color.siro,0);

	waku(X+338,Y+26, 98,17,6);
	mes_bmf(X+415,35+Y,"MP",1);
	suu_bmf(X+399,35+Y,2,shop[P].syou_mp[M]* shop[P].mana_b[T] / 100,0);
	waku(X+248,Y+45,188,17,6);
	mes_bmf(X+419,54+Y,"G",1);
	int SYOU_M = int(shop[P].syou_money[M]*shop[P].mana_gb[T]/100);
	if(M < 61 || M > 65){//���������n
		SYOU_M = SYOU_M * (1000 + data.day) / 10;
	}
	suu_bmf(X+399,54+Y,2,SYOU_M,0);
	waku(X+248,Y+26,88,17,6);
	std::string str;
	if(mana[M].b_w_c > 0 ){
		mes_bmf(X+260,35+Y,"Black",1);
		syou_bmf(X+329,35+Y,int(abs(mana[M].b_w_c) * 10),0);
	}else if(mana[M].b_w_c < 0 ){
		mes_bmf(X+260,35+Y,"White",1);
		syou_bmf(X+329,35+Y,int(abs(mana[M].b_w_c) * 10),0);
	}else{
		str = "No Color";
		mes_bmf(X+260,35+Y,str.c_str(),1);
	}

	//������
	mes_stri(X+10,Y+ 70,mana[M].help.c_str());
	return 1;
}
int DRA::emp_info(int E){

	int X,Y,Z;
	if(emp[E].now_job == 1) Z = 0;
	else			  		Z = 1;

	win_hmes("",400,246-Z*60);
	if(Inp.m_x < data.window_x - 400)	X = Inp.m_x;
	else								X = Inp.m_x - 400;
	if(Inp.m_y < data.window_y - 246 +Z*60) Y = Inp.m_y;
	else									Y = Inp.m_y - 246 + Z*60;

	//�摜���E�큕���`�x�[�V����
	waku(8+X,40+Y,148,24,7);
	waku(8+X,26+Y,98,38,7);
	mes(49+X,47+Y,emp[E].name.c_str(),color.kuro,color.siro,2);//���O
	DrawRotaGraph(30+X,46+Y,2,0,gra.unit[emp[E].gra][1],TRUE,0);
	//�̒��\��
	if(Z==0){
		int IC;
		if(emp[E].rest > 1		) IC = 5;
		else if(emp[E].rest > 0 ) IC = 6;
		else if(emp[E].tension >= 140) IC = 0;
		else if(emp[E].tension >= 120) IC = 1;
		else if(emp[E].tension >= 100) IC = 2;
		else if(emp[E].tension >= 80)  IC = 3;
		else						   IC = 4;

		if(emp[E].pb_rest > 0) SetDrawBright(255,255,0);
		if(emp[E].pb_rest < 0) SetDrawBright(122,122,122);
		DrawRotaGraph(36+X,37+Y,1,0,gra.emo[IC],TRUE,0);//���o��
		SetDrawBright(255,255,255);		
		switch(IC){
			case 0:mes(49+X,29+Y,"��D��!",color.kuro,color.siro,2);break;
			case 1:mes(49+X,29+Y," �D����",color.kuro,color.siro,2);break;
			case 2:mes(49+X,29+Y," ����",color.kuro,color.siro,2);break;
			case 3:mes(49+X,29+Y," �s��",color.kuro,color.siro,2);break;
			case 4:mes(49+X,29+Y,"�����",color.kuro,color.siro,2);break;
			case 5:mes(49+X,29+Y,"�×{���c",color.kuro,color.siro,2);break;
			case 6:mes(49+X,29+Y,"���x��",color.kuro,color.siro,2);break;
		}
	}else{
		mes(49+X,29+Y,"���E��",color.kuro,color.siro,2);
	}

	//�X�L��
	waku(158+X,40+Y,222,24,7);
	waku(158+X,26+Y,142,38,7);
	DrawRotaGraph(170+X,36+Y,1,0,gra.ico[91],TRUE,0);
	if(emp[E].mensetu[4][P] == 1){
		mes(180+X,29+Y,data.skill_job[emp[E].skill],color.kuro,color.siro,2);
		mes(162+X,48+Y,data.skill_info[emp[E].skill],color.kuro,color.siro,2);
	}else{
		mes(180+X,29+Y,"�H�H�H",color.kuro,color.siro,2);
		mes(162+X,48+Y,"�ǂ�ȓ��������邩������Ȃ�",color.kuro,color.siro,2);
	}
	//���x��
	//�C�x���g�l�ރt���O
	if(emp[E].eve_flag == 1){
		SetDrawBright(255,255,0);
		mes_bmf(14+X,58+Y,"EVE",1);
		SetDrawBright(255,255,255);
	}else{
		mes_bmf(18+X,58+Y,"L",1);
	}

	suu_bmf(40+X,56+Y,2,emp[E].lv,2);
	//��{�X�e�[�^�X�\��
	int ICO,N,C,RANK;
	int MAN = emp[E].pay_money * 100 / max(emp[E].req_money,1);

	MAN = emp[E].manzoku_cul();
	if(MAN > 1000) MAN = 1000;

	std::string NAME,COME;
	for(int i=0;i<8 - Z*3;i++){
		waku(X+10,66+Y+i*22,65,20,6);
		waku(X+80,66+Y+i*22,65,20,6);

		if(i%2==0)	C = 255;
		else		C = 150;

		int GL;//�Q�[�W����

		switch(i){
			case 0:NAME = "�̗�";ICO = 44;
				N  = (int)sqrt((double)emp[E].st[0] * 100);
				GL = N /4;
				break;
			case 1:
				N  = emp[E].st[1];
				GL = N / 4;
				if(emp[E].job == 1){
					NAME = "����";ICO = 45;
				}else{
					NAME = "�q�J";ICO = 93;
				}
				break;
			case 2:
				N = emp[E].st[2];
				GL = N / 4;
				if(emp[E].job == 1){
					NAME = "�J��";ICO = 7;
				}else{
					NAME = "�ڋq";ICO = 46;
				}
				break;
			case 3:
				N  = int(emp[E].konjyou_k);
				GL = N;
				NAME = "����";ICO = 73;break;
			case 4:
				N = emp[E].pay_money;
				GL = N / 6;
				NAME = "����";ICO = 53;break;
			case 5:
				NAME = "�Љ�";ICO = 48;break;
			case 6:
				NAME = "����";ICO = 50;break;
			case 7:
				NAME = "����";ICO = 93;break;
		}
		DrawRotaGraph(20+X,76+Y+i*22,1,0,gra.ico[ICO],TRUE,0);
		mes(36+X,69+Y+i*22,NAME.c_str(),color.kuro,color.siro,2);

		if(i<=4){
			if(i<4){//�����\���͕�
				if(emp[E].mensetu[i][P])suu_bmf(134+X,76+Y+i*22,2,N,0);
				else					mes_bmf(100+X,76+Y+i*22,"???",2);
			}else{
				syou_bmf(138+X,76+Y+i*22,N,0);
			}

			if(emp[E].mensetu[i][P] || i==4){
				if(i == 0 && Z == 0){//�̗͕\��
					waku_c(X+150,66+Y+i*22,GL,20,255,100,100);
					waku_c(X+150,66+Y+i*22,int(GL*emp[E].hp/100),20,255,C,0);
				}else if(i == 3 && Z == 0){//�X�g���X�\��
					waku_c(X+150,66+Y+i*22,GL,20,255,C,0);
					waku_c(X+150,66+Y+i*22,int(emp[E].sun),20,0,0,0);
				}else{//���X�e�[�^�X
					waku_c(X+150,66+Y+i*22,GL,20,255,C,0);
				}
			}
		}else if(i>=5 && i<7){
			waku(X+150,66+Y+i*22,230,20,6);
			switch(i){
				case 5:
					if(emp[E].b_w <= 0){
						COME = "����������Ђɉ����Ă�";RANK = 0;
					}else if(emp[E].b_w <= 20) {
						COME = "��Ђ���D��";RANK = 1;
					}else if(emp[E].b_w <= 40) {
						COME = "��Ђ̎��C�ɓ����Ă�";RANK = 2;
					}else if(emp[E].b_w <= 60) {
						COME = "���������Ȃ��Ă���";RANK = 3;
					}else if(emp[E].b_w <= 80) {
						COME = "�Ƃ��Ƃ񓭂�����";RANK = 4;
					}else{
						COME = "�В{�̖ڂ����Ă���";RANK = 5;
					}
				break;
				case 6:
					if(MAN<-20){
						COME = "�����͒������݂���";RANK = 0;
					}else if(MAN<0){
						COME = "�����͖����݂���";RANK = 1;
					}else if(MAN<50){
						COME = "�����ɂ��s��������";RANK = 2;
					}else if(MAN<100){
						COME = "�����ɕs��������";RANK = 3;
					}else if(MAN<200){
						COME = "���������Ȃ�����";RANK = 4;
					}else{
						COME = "�����̕������Ɍ����Ă���";RANK = 5;
					}
				break;
			}
			mes(152+X,69+Y+i*22,COME.c_str(),color.kuro,color.siro,2);
			if(i == 5){
				int Br = int(255 - emp[E].b_w*1.28);
				SetDrawBright( Br , Br , Br );

				if(emp[E].b_w > 50){
					mes_bmf(X+90,Y+76+i*22,"B",2);
					syou_bmf(138+X,76+Y+i*22,int((emp[E].b_w-50)*20),0);
				}else{
					mes_bmf(X+90,Y+76+i*22,"W",2);
					syou_bmf(138+X,76+Y+i*22,int((50-emp[E].b_w)*20),0);
				}
			}else{
				switch(RANK){
					case 0:SetDrawBright( 100 , 100 , 255 );mes_bmf(X+90,Y+76+i*22,"S",2);break;
					case 1:SetDrawBright( 150 , 150 , 255 );mes_bmf(X+90,Y+76+i*22,"A",2);break;
					case 2:SetDrawBright( 200 , 200 , 255 );mes_bmf(X+90,Y+76+i*22,"B",2);break;
					case 3:SetDrawBright( 255 , 200 , 200 );mes_bmf(X+90,Y+76+i*22,"C",2);break;
					case 4:SetDrawBright( 255 , 150 , 150 );mes_bmf(X+90,Y+76+i*22,"D",2);break;
					case 5:SetDrawBright( 255 , 100 , 100 );mes_bmf(X+90,Y+76+i*22,"F",2);break;
				}
				if(MAN < 0) MAN = 0;
				syou_bmf(138+X,76+Y+i*22,int(MAN),0);
			}
			SetDrawBright( 255 , 255 , 255 );
		}else{//����
			//���さ�M���񐔁��J������
			suu_bmf(134+X,76+Y+i*22,2,emp[E].work_cnt,0);
			
			waku(X+150,66+Y+i*22,65,20,6);
			waku(X+220,66+Y+i*22,65,20,6);

			if(emp[E].job == 0){
				DrawRotaGraph(160+X,76+Y+i*22,1,0,gra.ico[53],TRUE,0);
				mes(176+X,69+Y+i*22,"�̔�",color.kuro,color.siro,2);
				suu_bmf(264+X,76+Y+i*22,2,emp[E].sell_now/10000,0);
				suu_bmf(276+X,78+Y+i*22,1,emp[E].sell_now/1000%10,0);
			}else{
				DrawRotaGraph(160+X,76+Y+i*22,1,0,gra.ico[7],TRUE,0);
				mes(176+X,69+Y+i*22,"�M��",color.kuro,color.siro,2);
				suu_bmf(264+X,76+Y+i*22,2,emp[E].sell_now/10,0);
				suu_bmf(276+X,78+Y+i*22,1,emp[E].sell_now%10,0);
			}
		}
	}

	return 1;
}
int DRA::wep_info(int W){

	int i;
	std::string str;
	int ICO;
	int X,Y,Z;

	win_hmes("",400,246);
	if(Inp.m_x<data.window_x-400) X = Inp.m_x;
	else						  X = Inp.m_x - 400;
	if(Inp.m_y<data.window_y-246) Y = Inp.m_y +20;
	else						  Y = Inp.m_y -246+20;

	if(shop[P].wep_cre[W] == 1 || wind.info_t == 3) Z = 1;
	else											Z = 0;

	int C = 0;

	//���햼�O�A�l�i�A��
	waku(6+X,6+Y,380,30,6);
	mes(64+X,12+Y,wep[W].name.c_str(),color.kuro,color.siro,0);
	if(shop[P].wep_cre[W] != 2) SetDrawBright(70,70,70);
	wep_icon(24+X,22+Y,1,W);
	if(shop[P].wep_cre[W] != 2) SetDrawBright(255,255,255);


	if(W == NOU_NO)	{
		mes_bmf(X+44,Y+30,"ETC",1);
	}else{
		DrawRotaGraph(X+50,Y+16,1,0,gra.ico[wep[W].type],0);
		if(wep[W].type == 0) mes_bmf(X+44,Y+28,"SWD",1);
		else if(wep[W].type == 1) mes_bmf(X+44,Y+28,"LNC",1);
		else if(wep[W].type == 2) mes_bmf(X+44,Y+28,"AXE",1);
		else if(wep[W].type == 3) mes_bmf(X+44,Y+28,"ARW",1);
	}

	if(Z==0){//�J���ς�
	mes_bmf(X+305,22+Y,"X",1);
	suu_bmf(X+370,22+Y,2,shop[P].wep_rest[W],0);
	}else{//�J���O�A���ǒ�
		if(shop[P].wep_make_now[W]>0)	C=100;
		else							C=150;
		suu_bmf(350+X,24+Y,2,wep[W].create_time/54,0);
		mes_bmf(X+370,24+Y,"G",2);
	}

	int N,N2,N3;//N �� N3���\�����鐔���AN2�̓Q�[�W�p
	double G;
	for(i=0;i<7;i++){
		switch(i){
			case 0:str = "���i"	;ICO = 53;
				N  = int(wep[W].price * shop[P].price_rate);
				N2 = wep[W].price*100;
				N3 = int(shop[P].price_rate*10 - 1000);

				if(shop[P].medama_check(W) == 1){
					N  = N * 8 / 10;
					N3 = N3 * 8 / 10;
				}
				G  = 300;
			break;
			case 1:str = "��p"	;ICO = 52;
				N  = int(wep[W].seizou_cost*wep[W].price*shop[P].cost_j[W]);
				N2 = wep[W].seizou_cost*wep[W].price;
				N3 = int(shop[P].cost_j[W] * 1000 - 1000);
				G  = 300;
			break;
			case 2:str = "����"	;ICO = 54;
				N  = int(wep[W].make_time * 10 * shop[P].time_j[W] / 100 );
				N2 = int(wep[W].make_time * 10 / 100);
				N3 = int(shop[P].time_j[W] * 1000 - 1000);
				G  = 3;
				break;
			case 3:str = "�U����"	;ICO = 38;
				N  = int(wep[W].atk*shop[P].atk_j[W]*10);
				N2 = wep[W].atk* 10;
				N3 = int(shop[P].atk_j[W] * 1000 - 1000);
				G  = 20;
				break;
			case 4:str = "�ϋv��"	;ICO = 39;
				N  = int(wep[W].dur*shop[P].dur_j[W]);
				N2 = wep[W].dur;
				N3 = int(shop[P].dur_j[W] * 1000 - 1000);
				G  = 1;
				break;
			case 5:
				if(W == NOU_NO){
					str = "�[�i��"	;ICO = 62;
					N  = shop[P].nougu_req;
					N2 = shop[P].wep_rest[NOU_NO];
					if(shop[P].nougu_req <= 0)  N3 = 1000;
					else						N3 = shop[P].wep_rest[NOU_NO]*1000/shop[P].nougu_req;
					G = 5;
				}else{
					ICO = 40+wep[W].zoku;
					str = "�W�q��";				
					//N  = int((wep[W].ninki[0]+wep[W].ninki[1]+wep[W].ninki[2])*shop[P].ninki_j[W]*shop[P]);
                    N  = wep[W].ninki[0] * shop[P].ninki_b[0];
                    N += wep[W].ninki[1] * shop[P].ninki_b[1];
                    N += wep[W].ninki[2] * shop[P].ninki_b[2];
                    N  = (int)(N *shop[P].ninki_j[W] / 10);

					N2 = (wep[W].ninki[0]+wep[W].ninki[1]+wep[W].ninki[2])*10;
					N3 = int(shop[P].ninki_j[W] * 1000 - 1000);
					G = 20;
				}
				waku_c(X+185,40+Y+i*22 ,int(N  / G) ,20,0,255,255);
				waku_c(X+185,40+Y+i*22 ,int(N2 / G) ,20,255,255,0);
				break;
			case 6:
				if(shop[P].wep_cre[W] == 2){
					str = "����LV"	;ICO = 7;
					N  = shop[P].wep_kaicnt[W];
					N2 = 100;
					N3 = int( double(shop[P].wep_kaiexp[W]) / (500+shop[P].wep_kaicnt[W]*50) / 5400 / 30 * 1000);
				}else{
					str = "�J����"	;ICO = 7;
					N  = int(double(shop[P].wep_make[W])/wep[W].create_time*100);
					N2 = 100;
					N3 = N*10;
				}
				waku_c(X+185,40+Y+i*22 ,N2 * 19 /10,20,255,150,150);
				waku_c(X+185,40+Y+i*22 ,N3 * 19 /100,20,255,100,100);
				break;
		}

		//�X�e�[�^�X���ω�
		if(i < 5){
			int C = 150 + i%2 * 105;
			if(N > N2){
				waku_c(X+185,40+Y+i*22 ,min(int(N  / G),190),20,255,100,100);
				waku_c(X+185,40+Y+i*22 ,min(int(N2 / G),190),20,255,C,0);
			}else{
				waku_c(X+185,40+Y+i*22 ,min(int(N2 / G),190),20,100,100,255);
				waku_c(X+185,40+Y+i*22 ,min(int(N  / G),190),20,255,C,0);
			}
		}

		//���O�̂Ƃ��̘g
		waku(X+10,40+Y+i*22  ,75,20,6);
		waku(X+90,40+Y+i*22  ,90,20,6);
		mes(35+X,43+Y+i*22,str.c_str(),color.kuro,color.siro,2);
		DrawRotaGraph(20+X,50+Y+i*22,1,0,gra.ico[ICO],TRUE,0);

		//�X�e�[�^�X�\��
		if(i==5 && W!=NOU_NO){
				if(wep[W].ninki[0] > 0)			SetDrawBright(150,150,255);
				else if(wep[W].ninki[1] > 0)	SetDrawBright(255,150,150);
				else if(wep[W].ninki[2] > 0)	SetDrawBright(150,255,150);
				syou_bmf(172+X,50+Y+i*22,N,0);
				SetDrawBright(255,255,255);
		}else if(i==2 || i==3){
			syou_bmf(172+X,50+Y+i*22,N,0);
		}else{
			suu_bmf(170+X,50+Y+i*22,2,N,0);
		}

		//if(i == 0 && N3 == 100) continue;//�l�i�̓f�t�H���g�\������
		mes(X+370,40+Y+i*22,"%",color.kuro,color.siro,0);
		//
		if(N3 < 0 && i < 6) mes_bmf(X+314,50+Y+i*22,"-",2);
		if(N3 > 0 && i < 6) mes_bmf(X+314,50+Y+i*22,"+",2);
		syou_bmf(X+360,50+Y+i*22 ,abs(N3),0);
	}

	//�ڋʏ��i���ʕ\��
	waku(X+10,40+Y+7*22  ,90,20,6);
	waku(X+105,40+Y+7*22  ,270,20,6);
	mes(35+X,43+Y+7*22,"�ڋʏ��i",color.kuro,color.siro,2);
	DrawRotaGraph(20+X,50+Y+7*22,1,0,gra.ico[100],TRUE,0);

	if(W == NOU_NO) return 1;

	int XB = 0;
	if(wep[W].mtype > 0){
		int H = 10;
		if(data.wep_ganso[W] == P) H = 12;
		DrawRotaGraph(120+X,50+Y+7*22,1,0,gra.ico[wep[W].type],TRUE,0);
		mes_bmf(X+140,50+Y+i*22,"+",2);
		syou_bmf(X+175,50+Y+i*22,wep[W].mtype*H/10,0);
		mes(185+X,43+Y+7*22,"%",color.kuro,color.siro,2);
		XB= 120;
	}
	if(wep[W].mzoku > 0){
		int H = 10;
		if(data.wep_ganso[W] == P) H = 12;
		DrawRotaGraph(120+X+XB,50+Y+7*22,1,0,gra.ico[40+wep[W].zoku],TRUE,0);
		mes_bmf(X+140+XB,50+Y+i*22,"+",2);
		syou_bmf(X+175+XB,50+Y+i*22,wep[W].mzoku*H/10,0);
		mes(185+X+XB,43+Y+7*22,"%",color.kuro,color.siro,2);
	}

	return 1;
}
int DRA::mana_icon(int X,int Y,int M,int T){
	//T = 0 ��p�E�B���h�E
	//T = 1 ��Џ��E�B���h�E
	//T = 2 ����
	//T = 3 �}��
	int Z = mana[M].type;

	if(mana[M].b_w_d != -99999)		waku_c(X,Y,36,36, 50, 50, 50);//�u���b�N
	else if(mana[M].b_w_u != 99999) waku_c(X,Y,36,36,255,255,255);//�z���C�g
	else							waku_c(X,Y,36,36,200,200,200);
	
	waku(X+2,Y+2,32,32,6);

	if(T == 0 || T == 2){
		if(shop[P].use_mana == M)			waku_c(X,Y,36,36,255,150,150);//�g�p��
	}

	int IC = mana[M].icon;
	//���C���\��
	if(shop[P].mana_ok[M] != 1 && shop[P].mana_rest[M] > 0 && T < 3) IC = 49;

	//���xor�P��
	DrawRotaGraph(X+18,Y+18,2,0,gra.ico[IC],TRUE,0);
	if(mana[M].seido > 0){//���x
		DrawRotaGraph(X+8,Y+28,2,0,gra.ico[87],TRUE,0);
	}

	if(T < 2 || T == 3){
		std::string str;
		str = mana[M].name;
		if(str.length() > 4) str[4] = NULL;
		mes(X+4,Y+4,str.c_str(),color.kuro,color.siro,2);
	}

	if(shop[P].mana_day[M] == data.day && (T == 0 || T==2))	DrawRotaGraph(X+18,Y+28,2,0,gra.ico[22],TRUE,0);//�o������

	if(IC == 49){
		mes_bmf(X+8,Y+28,"RK",1);
		suu_bmf(X+28,Y+28,2,mana[M].rank,0);
	}else if(T == 0){
		suu_bmf(X+28,Y+28,1,shop[P].syou_mp[M]*shop[P].mana_b[Z]/100,0);//����MP
	}else if(T == 1){
		if(shop[P].mana_cnt[M] > 1){
			mes_bmf(X+8,Y+28,"LV",1);
			suu_bmf(X+28,Y+28,2,shop[P].mana_cnt[M],0);
		}
	}


	return 1;
}
int DRA::wep_icon(int X,int Y,double R,int N){

	if(shop[P].wep_cre[N] !=2) SetDrawBright(70,70,70); 
	DrawRotaGraph(X,Y,R,0,gra.wep[N],TRUE,0);//����A�C�R��
	if(data.wep_ganso[N] == P || data.wep_ganso[N] == -1) DrawRotaGraph(X-8,Y+6,2,0,gra.ico[101],TRUE,0);//���c�\��
	if(shop[P].wep_cre[N] != 2)SetDrawBright(255,255,255);

	return 1;
}
int DRA::drama(){
	int i;
	//�C�x���g�V�[�����C�����
	draw.work();
	//�w�i�Â�����
	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 100) ;
	DrawBox(0,0,data.window_x,data.window_y,GetColor(0,0,0),1);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
	//�g+��ʉ摜
	waku(data.window_x/2-212,data.window_y/2-162,456,324,3);
	SetDrawArea(data.window_x/2-208,data.window_y/2-158,data.window_x/2+238,data.window_y/2+156);

	if(EVE_FUN::Sin().eve_black>0 && EVE_FUN::Sin().eve_black<=510){
		SetDrawBright(abs(255-EVE_FUN::Sin().eve_black),abs(255-EVE_FUN::Sin().eve_black),abs(255-EVE_FUN::Sin().eve_black));
		if(EVE_FUN::Sin().eve_black <=255) data.back = EVE_FUN::Sin().eve_bback;
		EVE_FUN::Sin().eve_black -= 4+Inp.m_RO*8;
	}



	if(data.back == 0)		DrawRotaGraph(data.window_x/2+14,data.window_y/2+16,2,0,gra.shop[shop[P].size],0,0);
	else if(data.back == 1)	DrawRotaGraph(data.window_x/2+14,data.window_y/2,2,0,gra.back[shop[P].size],0,0);
	else				   	DrawRotaGraph(data.window_x/2+14,data.window_y/2,2,0,gra.back[data.back-1],0,0);
	waku(data.window_x/2-202,data.window_y/2-152,EVE_FUN::Sin().eve_namew,30,3);
	mes(data.window_x/2-196,data.window_y/2-146,EVE_FUN::Sin().eve_name.c_str(),color.kuro,color.siro,0);

	//�l�\��
	for(i=0;i<36;i++){

		if (act[i]->no<0)continue;
		act[i]->p = act[i]->m *3 + 1;
		for(int cnt =0; cnt<1+Inp.m_RO*2;cnt++){
			if(act[i]->mx < 0){//�ړ�����
				act[i]->mx += act[i]->sp;
				act[i]->x -= act[i]->sp;
				act[i]->p = act[i]->m *3 + (act[i]->x/10%4+1)%3;
			}
			if(act[i]->mx > 0){
				act[i]->mx -= act[i]->sp;
				act[i]->x += act[i]->sp;
				act[i]->p = act[i]->m *3 + (act[i]->x/10%4+1)%3;
			}
			if(act[i]->my < 0){
				act[i]->my += act[i]->sp;
				act[i]->y -= act[i]->sp;
				act[i]->p = act[i]->m *3 + (act[i]->y/10%4+1)%3;
			}
			if(act[i]->my > 0){
				act[i]->my -= act[i]->sp;
				act[i]->y += act[i]->sp;
				act[i]->p = act[i]->m *3 + (act[i]->y/10%4+1)%3;
			}
		}
		if(act[i]->emo == 13		 && EVE_FUN::Sin().eve_wait <= 20)act[i]->emo = 12;//�E�E�E
		else if(act[i]->emo == 12 && EVE_FUN::Sin().eve_wait <= 10)act[i]->emo = 11;
		//�����̌v�Z

		DrawRotaGraph(act[i]->x,act[i]->y,2,0,gra.unit[act[i]->no][act[i]->p],1,0);//SD
	}
	SetDrawArea(0,0,data.window_x,data.window_y);
	//����
	for(i=0;i<36;i++)
	{
		if(act[i]->emo>=0)DrawRotaGraph(act[i]->x,act[i]->y-30,2,0,gra.emo[act[i]->emo],1,0);//����
	}
	//���o��
	for(i=0;i<36;i++){
		if(act[i]->huki_w <=0 ) continue;
		draw.waku_h(i);
	}

	SetDrawBright(255,255,255);

	return 1;
}
int DRA::waku(int XU,int YU,int XS,int YS,int NO){

	//���g
	DrawExtendGraph(XU+10,YU+10,XU+XS-10,YU+YS-10,gra.win[NO*9+4],1);
	//�l��
	DrawGraph(XU	  ,YU	   ,gra.win[NO*9+0],1);
	DrawGraph(XU+XS-10,YU	   ,gra.win[NO*9+2],1);
	DrawGraph(XU	  ,YU+YS-10,gra.win[NO*9+6],1);
	DrawGraph(XU+XS-10,YU+YS-10,gra.win[NO*9+8],1);
	//�㉺���E
	DrawExtendGraph(XU+10	,YU		 ,XU+XS-10,YU+10,gra.win[NO*9+1],1);
	DrawExtendGraph(XU+10	,YU+YS-10,XU+XS-10,YU+YS,gra.win[NO*9+7],1);
	DrawExtendGraph(XU		,YU+10	 ,XU+10	  ,YU+YS-10,gra.win[NO*9+3],1);
	DrawExtendGraph(XU+XS-10,YU+10	 ,XU+XS	  ,YU+YS-10,gra.win[NO*9+5],1);

	return 1;
}
int DRA::waku_c(int XU,int YU,int XS,int YS,int C1,int C2,int C3){

	if(XS <=2 || YS<=2 )return -1;
	if(XS == 3){
		DrawLine(XU+1,YU+2,XU+1,YU+YS-2,GetColor(C1,C2,C3),1);
		DrawLine(XU+2,YU+1,XU+2,YU+YS-1,GetColor(C1,C2,C3),1);
		DrawLine(XU+3,YU+2,XU+3,YU+YS-2,GetColor(C1,C2,C3),1);
	}else{
		DrawBox(XU+2,YU+1,XU+XS-2,YU+YS-1,GetColor(C1,C2,C3),1);
		DrawLine(XU+1	,YU+2	,XU+1		,YU+YS-2,GetColor(C1,C2,C3),1);
		DrawLine(XU+XS-2,YU+2	,XU+XS-2	,YU+YS-2,GetColor(C1,C2,C3),1);
	}
	return 1;
}
int DRA::waku_h(int N){
	
	int SY,Y;
	SY = 20;

	//�g�����o���\��
	if(act[N]->huki_ud == 1){//��
		waku_c(act[N]->x-act[N]->huki_w/2-1,act[N]->y+24,act[N]->huki_w+2,act[N]->huki_h+2,0,0,0);
		waku(act[N]->x-act[N]->huki_w/2,act[N]->y+25,act[N]->huki_w,act[N]->huki_h,6);
		DrawRotaGraph(act[N]->x,act[N]->y+26,1,0,gra.huki[1],1,0);
		Y = -10;
	}else{//��
		waku_c(act[N]->x-act[N]->huki_w/2-1,act[N]->y-29-act[N]->huki_h,act[N]->huki_w+2,act[N]->huki_h+2,0,0,0);
		waku(act[N]->x-act[N]->huki_w/2,act[N]->y-28-act[N]->huki_h,act[N]->huki_w,act[N]->huki_h,6);
		DrawRotaGraph(act[N]->x,act[N]->y-24,1,0,gra.huki[0],1,0);
		Y = - act[N]->huki_h - 64;
	}
	//���O�p�E�B���h�E
	waku_c(act[N]->x-act[N]->huki_w/2+6,act[N]->y+38+Y,act[N]->name_w,20,0,0,0);
	waku_c(act[N]->x-act[N]->huki_w/2+7,act[N]->y+39+Y,act[N]->name_w-2,18,255,255,255);

	//����
	mes(act[N]->x-act[N]->huki_w/2+10,act[N]->y+42+Y     ,act[N]->name,color.kuro,color.siro,2);

	mes(act[N]->x-act[N]->huki_w/2+8,act[N]->y+59+Y     ,act[N]->huki_mes[0],color.kuro,color.siro,0);
	mes(act[N]->x-act[N]->huki_w/2+8,act[N]->y+59+Y+SY  ,act[N]->huki_mes[1],color.kuro,color.siro,0);
	mes(act[N]->x-act[N]->huki_w/2+8,act[N]->y+59+Y+SY*2,act[N]->huki_mes[2],color.kuro,color.siro,0);

	return 1;
}
int DRA::waku_help(int X,int Y,int XS,int YS,int N){
	//SetDrawBlendMode( DX_BLENDMODE_ALPHA , 240 ) ;//�������Ńw���v�E�B���h�E
	draw.waku(X,Y,XS,YS,N);
	//SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
	return 1;
}
int DRA::mes(int X,int Y,const char *M,int C,int C2,int FONT){

	DrawStringToHandle(X+1,Y+1,M,C2,data.font[FONT]);
	DrawStringToHandle(X,Y,M,C,data.font[FONT]);

	return 1;
}
int DRA::mes_i(int X,int Y,const char *M){
	//�����p

	std::string str = M;

	//�����͒u������
	for(int I=0, XA = X;I<(int)str.length();I++){
		if(str[I] == NULL) break;
		if(str[I] >= '0' && str[I] <= '9'){
			//XA+=5;
			DrawRotaGraph( XA+6 , Y+7 , 2 , 0 , gra.moji[str[I] - '0' +30] , TRUE ) ;
			str[I] = ' ';
			str.insert(I," ");
		}
		XA += 7;
	}
	DrawStringToHandle(X,Y,str.c_str(),color.kuro,data.font[2]);

	return 1;
}
int DRA::mes_bmf(int X,int Y,const char M[30],double S){

	int I;
	for(I=0;I<30;I++){
		if(M[I]==NULL) break;
		if(M[I] == '?')	DrawRotaGraph( X+int(I*7*S) , Y , S , 0 , gra.moji[28] , TRUE ) ;		
		else if(M[I]-55>0 && M[I]-55<40)	  DrawRotaGraph( X+int(I*7*S) , Y , S , 0 , gra.moji[M[I]-65] , TRUE ) ;
		else if(M[I]>=97 && M[I]<=122)DrawRotaGraph( X+int(I*7*S) , Y , S , 0 , gra.moji[M[I]-97] , TRUE ) ;
		else if(M[I] == '+')	DrawRotaGraph( X+int(I*7*S) , Y , S , 0 , gra.moji[26] , TRUE ) ;
		else if(M[I] == '-')	DrawRotaGraph( X+int(I*7*S) , Y , S , 0 , gra.moji[27] , TRUE ) ;
		else if(M[I] == '*')	DrawRotaGraph( X+int(I*7*S) , Y , S , 0 , gra.moji[29] , TRUE ) ;
	}
	return 1;
}
int DRA::mes_bmf2(int X,int Y,const char* M,double S,int LEN){

	int I;
	for(I=0;I<LEN;I++){
		if(M[I]==NULL) break;
		if(M[I] >= 'A' && M[I] <= 'A'+26){
			DrawRotaGraph( X+int(I*6*S) , Y , S*1.5 , 0 , gra.moji_b[M[I]-'A'+10] , TRUE ) ;
		}
		else if(M[I] >= 'a' && M[I] <= 'a'+26) DrawRotaGraph( X+int(I*6*S) , Y , S , 0 , gra.moji_b[M[I]-'a'+40] , TRUE ) ;
		else if(M[I] >= '0' && M[I] <= '0'+26) DrawRotaGraph( X+int(I*6*S) , Y , S , 0 , gra.moji_b[M[I]-'0'] , TRUE ) ;
		else if(M[I] == '(')
		{//(�L�E���E)
			DrawRotaGraph( X+int(I*6*S) , Y , S , 0 , gra.moji_b[76] , TRUE ) ;
			DrawRotaGraph( X+int(I*6*S+5*S) , Y , S , 0 , gra.moji_b[66] , TRUE ) ;
			DrawRotaGraph( X+int(I*6*S+10*S) , Y , S , 0 , gra.moji_b[68] , TRUE ) ;
			DrawRotaGraph( X+int(I*6*S+15*S) , Y , S , 0 , gra.moji_b[37] , TRUE ) ;
			DrawRotaGraph( X+int(I*6*S+22*S) , Y , S , 0 , gra.moji_b[68] , TRUE ) ;
			DrawRotaGraph( X+int(I*6*S+28*S) , Y , S , 0 , gra.moji_b[77] , TRUE ) ;
			break;
		}
	}

	return 1;
}
int DRA::suu_bmf(int X,int Y,double S,int V,int T,int K){

	int I=0;
	int M=V;
	int XA = 0;

	V = abs(V);

	do{
		if(I % 3==0 && I > 0){
			//�J���}�\��
			XA-=2;
			DrawRotaGraph( X-int(XA*S) , Y , S , 0 , gra.moji[29] , TRUE ) ;
			XA+=5;
		}
		DrawRotaGraph( X-int(XA*S) , Y , S , 0 , gra.moji[V%10+30+T*10] , TRUE ) ;
		V/=10;
		I++;
		XA += K;
	}while(V>0);

	if(M < 0){
		DrawRotaGraph( X-int((XA-2)*S) , Y , S , 0 , gra.moji[27] , TRUE ) ;
	}

	return 1;
}
int DRA::syou_bmf(int X,int Y,int V,int T,int K){

	int I=0;
	int M = V;
	V = abs(V);

	DrawRotaGraph( X-int(K*I) , Y+3 , 1 , 0 , gra.moji[V%10+30+T*10] , TRUE ) ;
	V/=10;
	do{
		DrawRotaGraph( X-int(K*I*2)-K-5 , Y , 2 , 0 , gra.moji[V%10+30+T*10] , TRUE ) ;
		V/=10;
		I++;
	}while(V>0);

	if(M < 0){//�}�C�i�X��
		DrawRotaGraph( X-int(K*I*2)-16 , Y , 2 , 0 , gra.moji[27] , TRUE ) ;
	}

	return 1;
}
int DRA::title(/*�^�C�g�����*/){

	static int time = 0;
	static int b_w = 0;
	unsigned int str_cnt;
	int	N=0;
	std::string str;
	double S = double(data.window_y)/1000;

	DrawBox(0,0,data.window_x,data.window_y,GetColor(0,0,0),true);
	// ��ʃf�[�^�̎�肱��
	if( time< 360){//��
		b_w = 0;
		mes_bmf2(data.window_x/2-318,data.window_y/2,"Presented By",6,time/20);
		if(time>280){
			mes_bmf2(data.window_x/2-318+6*13*6,data.window_y/2,"(????)",8);
		}

		if(Inp.m_LC == 1 ){
			time = 360;
			Inp.m_LC = 0;
		}

	}else{
		b_w= min(b_w+3,255);
		SetDrawBright(b_w,b_w,b_w);
		DrawExtendGraph(0,0,data.window_x,data.window_y,gra.title[2],true);
		SetDrawBright(255,255,255);

		str_cnt = (time-360);

		double X = double(Inp.m_x) / data.window_y * 1000;
		double Y = double(Inp.m_y) / data.window_y * 1000;

		if(X>40 && X<400)
		{
			N = int(Y+10)/50;
		}
	
		SetDrawArea(0,0,int(40*S+str_cnt*10),data.window_y);

		DrawGraph( 5 ,int(40*S),gra.title_txt,true);
		SetDrawArea(0,0,int(120*S+str_cnt*2),data.window_y);
		
		for(int i=6,NP = -1;i<=17;i++){
			if(i== 8 || i == 13) continue;
			NP++;
			if(i == 9 || i == 10 || i == 11 || i == 12 || i == 16 ){
				if( !sys.play_flag[1] ) continue;
			}
			if( i == 16 && sys.pass_on == 1 ) continue;

			if(N == i) SetDrawBright(255,0,0);
			else	   SetDrawBright(0,0,0);

			DrawGraph(int(120*S),int(i*50*S),gra.title_sub[NP],true);
		}
	}

	SetDrawArea(0,0,data.window_x,data.window_y);
	SetDrawBright(255,255,255);

	time++;

	if(time < 420) return 0;

	return N;
}

int DRA::credit_db()
{
	int XA=(data.window_x - 420) / 2;
	int YA=(data.window_y - 708) / 2;

	SetDrawBright( 128 , 128 , 128 );
	DrawExtendGraph(0,0,data.window_x,data.window_y,gra.title[2],true);
	SetDrawBright( 255 , 255 , 255 );

	int IC = 0;

	mes( 50 , 30 , "���E����E����" , color.siro , color.kuro , 1 );
	mes( 70 , 70 , "�i�L�E@�E�j" , color.siro , color.kuro , 0 );
	
	mes( 50 , 120 , "���p�f�ޓ��i�h�̗��j" , color.siro , color.kuro , 1 );
	mes( 60 , 160 , "�L�����A�}�b�v�`�b�v��" , color.siro , color.kuro , 0 );
	mes( 70 , 180 , "DotWorld" , color.siro , color.kuro , 0 );
	
	mes( 60 , 230 , "����A�C�R����" , color.siro , color.kuro , 0 );
	mes( 70 , 250 , "Whitecat" , color.siro , color.kuro , 0 );

	mes( 60 , 300 , "�V�X�e���A�C�R��" , color.siro , color.kuro , 0 );
	mes( 70 , 320 , "Mark James" , color.siro , color.kuro , 0 );
	
	mes( 60 , 370 , "���ʉ�" , color.siro , color.kuro , 0 );
	mes( 70 , 390 , "�U�E�}�b�`���C�J�@�Y" , color.siro , color.kuro , 0 );
	
	mes( 60 , 440 , "�a�f�l" , color.siro , color.kuro , 0 );
	mes( 70 , 460 , "�t���[���y�f�� H/MIX" , color.siro , color.kuro , 0 );
	
	mes( 60 , 510 , "�}���`���f�B�A���C�u����" , color.siro , color.kuro , 0 );
	mes( 70 , 530 , "�c�w���C�u�����u����" , color.siro , color.kuro , 0 );
	
	mes( 380 , 120 , "�e�X�g�v���C�i�h�̗��j" , color.siro , color.kuro , 1 );

	mes( 400 , 160 , "�A����" , color.siro , color.kuro , 0 );
	mes( 600 , 160 , "sinn" , color.siro , color.kuro , 0 );
	mes( 800 , 160 , "dai" , color.siro , color.kuro , 0 );

    mes( 400 , 190 , "nekoq" , color.siro , color.kuro , 0 );	
	mes( 600 , 190 , "krith" , color.siro , color.kuro , 0 );
	mes( 800 , 190 , "���������ׂ���" , color.siro , color.kuro , 0 );

	mes( 400 , 220 , "MonoM" , color.siro , color.kuro , 0 );
	mes( 600 , 220 , "veve" , color.siro , color.kuro , 0 );
	mes( 800 , 220 , "yan" , color.siro , color.kuro , 0 );

    mes( 400 , 250 , "Linebard" , color.siro , color.kuro , 0 );
	mes( 600 , 250 , "ENOMON" , color.siro , color.kuro , 0 );
	mes( 800 , 250 , "AX" , color.siro , color.kuro , 0 );
		
	mes( 400 , 280 , "�ނ���" , color.siro , color.kuro , 0 );
	mes( 600 , 280 , "�_�C" , color.siro , color.kuro , 0 );	
	mes( 800 , 280 , "�܂��B" , color.siro , color.kuro , 0 );

    mes( 400 , 310 , "��ׂ邠��" , color.siro , color.kuro , 0 );	
	mes( 600 , 310 , "GIA" , color.siro , color.kuro , 0 );
	mes( 800 , 310 , "����" , color.siro , color.kuro , 0 );
	
	mes( 400 , 340 , "milk" , color.siro , color.kuro , 0 );
	mes( 600 , 340 , "eriny" , color.siro , color.kuro , 0 );	
	mes( 800 , 340 , "Crosis the Purger" , color.siro , color.kuro , 0 );

    mes( 400 , 370 , "���[�N" , color.siro , color.kuro , 0 );
	mes( 600 , 370 , "�ނ�" , color.siro , color.kuro , 0 );
	mes( 800 , 370 , "SSS" , color.siro , color.kuro , 0 );
	
	mes( 400 , 400 , "Ariel" , color.siro , color.kuro , 0 );
	mes( 600 , 400 , "Taccon" , color.siro , color.kuro , 0 );
	mes( 800 , 400, "���U�O����/XA./SAN", color.siro, color.kuro, 0);

	mes( 400 , 430, "���I��", color.siro, color.kuro, 0);
    mes( 600 , 430, "�Ă���ς�", color.siro, color.kuro, 0);
    mes( 800 , 430, "eriny", color.siro, color.kuro, 0);

    mes( 400 , 460, "�㌎�J", color.siro, color.kuro, 0);
    mes( 600 , 460, "�]��", color.siro, color.kuro, 0);
    mes( 800 , 460, "��R�j��", color.siro, color.kuro, 0);

    mes( 400 , 490, "�Ƃ��ɂ�", color.siro, color.kuro, 0);
    mes( 600 , 490, "Jupiter", color.siro, color.kuro, 0);
    mes( 800 , 490, "��", color.siro, color.kuro, 0);
    
    mes( 400 , 520, "�҂҂�", color.siro, color.kuro, 0);
    mes( 600 , 520, "�V�`���[�₦��", color.siro, color.kuro, 0);
    mes( 800 , 520, "sipmen", color.siro, color.kuro, 0);

    mes( 400 , 550, "�Ȃ�", color.siro, color.kuro, 0);
    mes( 600 , 550, "�B", color.siro, color.kuro, 0);
    mes( 800 , 550, "Crostel", color.siro, color.kuro, 0);

    mes( 400 , 580, "���C�m�X", color.siro, color.kuro, 0);
    mes( 600 , 580, "���Ƃ��܂��傤", color.siro, color.kuro, 0);
    mes( 800 , 580, "�Չ���", color.siro, color.kuro, 0);
    
    mes( 400 , 610, "�\�Z�錎", color.siro, color.kuro, 0);
    mes( 600 , 610, "�i�h�m", color.siro, color.kuro, 0);
    mes( 800 , 610, "L-Valuation", color.siro, color.kuro, 0);

	return 1;
}
int DRA::wep_db(){

	int XA=(data.window_x - 800) / 2;
	int YA=(data.window_y - 670) / 2;

	static int T = 0;
	static int Tab = 0;
	static int Tsc[5] = {0,0,0,0,0};

	//��ރ{�^��
	if( Inp.m_x > XA + 8 && 
		Inp.m_x < XA + 168 && 
		Inp.m_y > YA + 8 && 
		Inp.m_y < YA + 48){
		T = 1000 + (Inp.m_x-XA-8)/40;
		if(Inp.m_LC == 1) Tab = T - 1000;
	}
	//���X�g
	if( Inp.m_x > XA + 8 && 
		Inp.m_x < XA + 260 && 
		Inp.m_y > YA + 56 && 
		Inp.m_y < YA + 656){
		T = (Inp.m_y-YA-56)/30;
	}
	//�X�N���[���o�[
	if( Inp.m_x > XA + 270 && 
		Inp.m_x < XA + 286 && 
		Inp.m_y > YA + 4 && 
		Inp.m_y < YA + 664){
		T = 2000;
		if(Inp.m_LO == 1){
			Tsc[Tab] = int((Inp.m_y - 4) *5 / 660) *20;
		}
	}

	Tsc[Tab] -= Inp.m_H*20;
	Tsc[Tab] = max(0,Tsc[Tab]);
	Tsc[Tab] = min(80,Tsc[Tab]);

	DrawExtendGraph(0,0,data.window_x,data.window_y,gra.title[2],true);

	waku(XA    ,YA,286,670,5);
	waku(XA+270,YA,16,670,5);
	int GL = Tsc[Tab] * 66 / 10;
	DrawBox(XA+274,YA+4+GL,XA+280,YA+4+132+GL,color.aka,1);
	waku(XA+286,YA,514,670,5);

	for(int i=0;i<4;i++){
		if(i == T-1000){
			waku_c(XA+6+i*40,YA+6,42,42,255,0,0);
		}
		if(i ==Tab){
			waku_c(XA+8+i*40,YA+8,38,38,255,120,120);
			DrawRotaGraph(XA+27+i*40,YA+22,2,0,gra.ico[i],0);
		}else{
			waku(XA+8+i*40,YA+8,38,38,6);
			DrawRotaGraph(XA+27+i*40,YA+22,1,0,gra.ico[i],0);
		}

		DrawRotaGraph(XA+27+i*40,YA+22,2,0,gra.ico[i],0);
		if(i==0)mes_bmf(XA+20+i*40,YA+38,"SWD",1);
		if(i==1)mes_bmf(XA+20+i*40,YA+38,"LNC",1);
		if(i==2)mes_bmf(XA+20+i*40,YA+38,"AXE",1);
		if(i==3)mes_bmf(XA+20+i*40,YA+38,"ARW",1);
	}

	for(int i=0,W=Tab*100+Tsc[Tab];i<20;i++,W++){
		if(i == T) waku_c(XA+6,YA+54+i*30,254,32,255,0,0);
		waku(XA+8,YA+56+i*30,250,28,6);
		if(sys.wep_maket[W] > 0){

			mes(XA+44,YA+60+i*30,wep[W].name.c_str(),color.kuro,color.siro,0);
			DrawRotaGraph(XA+24,YA+70+i*30,1,0,gra.wep[W],TRUE,0);//����A�C�R��
		}else{
			mes(XA+44,YA+60+i*30,"�H�H�H�H",color.kuro,color.siro,0);
			DrawRotaGraph(XA+24,YA+70+i*30,2,0,gra.ico[57],TRUE,0);//����A�C�R��
		}
	}

	//���\����
	wep_db_s(XA,YA,Tab*100+Tsc[Tab]+T);

	return 1;
}
int DRA::mana_db(){

	int XA=(data.window_x - 800) / 2;
	int YA=(data.window_y - 700) / 2;

	static int T = 0;
	static int Tab = 0;
	static int Tsc[5] = {0,0,0,0,0};

	//��ރ{�^��
	if( Inp.m_x > XA + 8 && 
		Inp.m_x < XA + 208 && 
		Inp.m_y > YA + 8 && 
		Inp.m_y < YA + 48){
		//T = 1000 + (Inp.m_x-XA-8)/40;
		if(Inp.m_LC == 1) Tab = 1000 + (Inp.m_x-XA-8)/40-1000;
	}
	//���X�g
	if( Inp.m_x > XA + 8 && 
		Inp.m_x < XA + 260 && 
		Inp.m_y > YA + 56 && 
		Inp.m_y < YA + 656){
		if(Tsc[Tab] + (Inp.m_y-YA-56)/30 < data.mana_max[Tab]){
			T = (Inp.m_y-YA-56)/30;
		}
	}
	//�X�N���[���o�[
	if( Inp.m_x > XA + 270 && 
		Inp.m_x < XA + 286 && 
		Inp.m_y > YA + 4 && 
		Inp.m_y < YA + 664){
		if(Inp.m_LO == 1){
			Tsc[Tab] = (Inp.m_y - 4) / (660 / ((data.mana_max[Tab]+19)/20)) *20;
		}
	}
	
	Tsc[Tab] -= Inp.m_H * 20;
	Tsc[Tab] = max(0,Tsc[Tab]);
	Tsc[Tab] = min((data.mana_max[Tab])/20*20,Tsc[Tab]);

	DrawExtendGraph(0,0,data.window_x,data.window_y,gra.title[2],true);

	waku(XA    ,YA,286,670,5);
	waku(XA+270,YA,16,670,5);
	int GP = Tsc[Tab]*33 / ((data.mana_max[Tab]+19)/20);
	int GL = 660/ ((data.mana_max[Tab]+19)/20);

	DrawBox(XA+274,YA+4+GP,XA+280,YA+4+GL+GP,color.aka,1);
	waku(XA+286,YA,514,670,5);

	for(int i=0;i<5;i++){
		if(i == T-1000){
			waku_c(XA+6+i*40,YA+6,42,42,255,0,0);
		}
		if(i ==Tab){
			waku_c(XA+8+i*40,YA+8,38,38,255,120,120);
			DrawRotaGraph(XA+27+i*40,YA+24,2,0,gra.ico[mana[i*60+1].icon],0);
		}else{
			waku(XA+8+i*40,YA+8,38,38,6);
			DrawRotaGraph(XA+27+i*40,YA+24,1,0,gra.ico[mana[i*60+1].icon],0);
		}	
		if(i==0)mes_bmf(XA+18+i*40,YA+36,"MANA",1);
		if(i==1)mes_bmf(XA+18+i*40,YA+36,"FINA",1);
		if(i==2)mes_bmf(XA+18+i*40,YA+36,"CONS",1);
		if(i==3)mes_bmf(XA+18+i*40,YA+36,"DEVE",1);
		if(i==4)mes_bmf(XA+18+i*40,YA+36,"PROP",1);
	}

	//���X�g
	int N = 0;

	for(int i=0,W=Tab*60+Tsc[Tab]+1;i<20;i++,W++){
		N = data.mana_index[W];
		if(i == T) waku_c(XA+6,YA+54+i*30,254,32,255,0,0);
		if(W > data.mana_max[Tab] + Tab*60) break;
		waku(XA+8,YA+56+i*30,250,28,6);
		if(sys.mana_total[N] > 0){
			mes(XA+44,YA+60+i*30,mana[N].name.c_str(),color.kuro,color.siro,0);
			DrawRotaGraph(XA+24,YA+70+i*30,2,0,gra.ico[mana[N].icon],TRUE,0);//��p
			if(mana[N].seido > 0)DrawRotaGraph(XA+32,YA+78+i*30,2,0,gra.ico[87],TRUE,0);
		}else{
			mes(XA+44,YA+60+i*30,"�H�H�H�H",color.kuro,color.siro,0);
			DrawRotaGraph(XA+24,YA+70+i*30,2,0,gra.ico[57],TRUE,0);//��p
		}

	}

	mana_db_s(XA,YA,data.mana_index[Tab*60+Tsc[Tab]+T+1]);

	return 1;
}
int DRA::record_db(){

	int XA=(data.window_x - 800) / 2;
	int YA=(data.window_y - 648) / 2;

	static int T = 0;

	if( Inp.m_x > XA + 10 && 
		Inp.m_x < XA + 260 && 
		Inp.m_y > YA + 10 && 
		Inp.m_y < YA + 610){
		T = (Inp.m_y-YA-10)/30;
	}

	sys.score_record[19][0]  = sys.total_sell;
	sys.score_record[19][1]  = sys.total_cust;
	sys.score_record[19][2]  = sys.total_sellc[0]+sys.total_sellc[1]+sys.total_sellc[2]+sys.total_sellc[3];
	sys.score_record[19][3]  = sys.total_sellc[0];
	sys.score_record[19][4]  = sys.total_sellc[1];
	sys.score_record[19][5]  = sys.total_sellc[2];
	sys.score_record[19][6]  = sys.total_sellc[3];
	sys.score_record[19][7]  = sys.total_make;
	sys.score_record[19][8]  = sys.total_makec;
	sys.score_record[19][9]  = sys.total_kyuuryou;
	sys.score_record[19][10] = sys.total_matokku;
	sys.score_record[19][11] = sys.total_kaihatu;
	sys.score_record[19][12] = sys.total_senden;
	sys.score_record[19][13] = sys.total_day;
	sys.score_record[19][14] = sys.total_koyou;
	sys.score_record[19][15] = sys.total_kaiko;
	sys.score_record[19][16] = sys.total_jisyoku;
	sys.score_record[19][17] = sys.total_haijin;

	DrawExtendGraph(0,0,data.window_x,data.window_y,gra.title[2],true);

	std::string label_r[36];
	std::string tanni[36];

	label_r[0] = "�̔���";tanni[0] = "��";
	label_r[1] = "���q��";tanni[1] = "�l";
	label_r[2] = "����グ-���v";tanni[2] = "�f";
	label_r[3] = "����グ-��";tanni[3] = "�f";
	label_r[4] = "����グ-��";tanni[4] = "�f";
	label_r[5] = "����グ-��";tanni[5] = "�f";
	label_r[6] = "����グ-�|";tanni[6] = "�f";
	label_r[7] = "������";tanni[7] = "��";
	label_r[8] = "������";tanni[8] = "�f";
	label_r[9] = "�l����";tanni[9] = "�f";
	label_r[10] = "��͂�����";tanni[10] = "��";
	
	label_r[11] = "�J����";tanni[11] = "��";
	label_r[12] = "��`��";tanni[12] = "��";
	label_r[13] = "�o�c����";tanni[13] = "��";
	label_r[14] = "�ٗp�l��";tanni[14] = "�l";
	label_r[15] = "���ِl��";tanni[15] = "�l";
	label_r[16] = "���E�l��";tanni[16] = "�l";
	label_r[17] = "�p�l����";tanni[17] = "�l";

	label_r[18] = "����";	tanni[18] = "�f";
	label_r[19] = "�J����";	tanni[19] = "��";
	label_r[20] = "�N���A����";	tanni[20] = "��";
	label_r[21] = "�l��";	tanni[21] = "�l";
	label_r[22] = "����";	tanni[22] = "�f";
	label_r[23] = "�N���A��";	tanni[23] = "��";
	label_r[24] = "��Փx";	tanni[24] = "";

	DrawExtendGraph(0,0,data.window_x,data.window_y,gra.title[2],true);

	waku(XA,YA,270,620,5);
	waku(XA+270,YA,530,620,5);

	//���[�h�ꗗ
	for(int i=0,W=1;i<19;i++,W++){
		int IC = data.mode_icon[i];
		if( i!= 0 && !sys.play_flag[i-1]) IC = 57;//

		if(T == i) waku_c(XA+6,YA+8+i*30,254,32,255,0,0);
		waku(XA+8,YA+10+i*30,250,28,6);
		if(IC != 57) mes(XA+46,YA+14+i*30,data.mode_n[i].c_str(),color.kuro,color.siro,0);
		else		 mes(XA+46,YA+14+i*30,"�H�H�H�H",color.kuro,color.siro,0);
		DrawRotaGraph(XA+26,YA+24+i*30,1,0,gra.ico[IC],TRUE,0);
	}

	//�L�^�ꗗ
	for(int i=0;i<18;i++){
		int IC = 15;
		waku(XA+10+270,YA+40+i*30,510,28,6);
		if(T == 0 || i <= 10){//����
			mes(XA+46+270,YA+44+i*30,label_r[i].c_str(),color.kuro,color.siro,0);
			mes(XA+46+720,YA+44+i*30,tanni[i].c_str(),color.kuro,color.siro,0);
		}else{//����ȊO
			mes(XA+46+270,YA+44+i*30,label_r[i+7].c_str(),color.kuro,color.siro,0);
			mes(XA+46+720,YA+44+i*30,tanni[i+7].c_str(),color.kuro,color.siro,0);
		}
		//���_��
		//DrawRotaGraph(XA+26+270,YA+54+i*30,1,0,gra.ico[IC],TRUE,0);

		if(T != 0 && i == 17){//�ō���Փx
			mes_bmf(XA+750 - data.nanndo_n[sys.score_record[(T+19)%20][17]].length()*10,YA+54+i*30,data.nanndo_n[sys.score_record[(T+19)%20][17]].c_str(),2);
		}else{//����ȊO
			suu_bmf(XA+750,YA+54+i*30,2,sys.score_record[(T+19)%20][i],0);
		}

	}

	return 1;
}
int DRA::medal_db(){

	int T = -1;
	int XA=(data.window_x - 420) / 2;
	int YA=(data.window_y - 708) / 2;

	std::string label[100];


	if( Inp.m_x > XA + 8 && 
		Inp.m_x < XA + 408 && 
		Inp.m_y > YA + 8 && 
		Inp.m_y < YA + 408){
		T = (Inp.m_x-XA-8)/40 + (Inp.m_y-YA-8)/40* 10;
	}

	DrawExtendGraph(0,0,data.window_x,data.window_y,gra.title[2],true);

	waku(XA,YA,420,420,5);

	waku(XA-100,YA+450,620,208,5);

	waku(XA-100,YA+660,620,50,5);

	int IC = 0;

	for(int i=0,W=1;i<100;i++,W++){
		if(i == T){
			waku_c(XA+6+(i%10)*40,YA+6+(i/10)*40,40,40,255,0,0);//�g
		}
		waku(XA+8+(i%10)*40,YA+8+(i/10)*40,36,36,6);//�g

		IC = 17 - sys.medal_gold[i];

		if(sys.medal_cnt[i]==0){
			SetDrawBright(64,64,64);
		}

		DrawRotaGraph(XA+25+(i%10)*40,YA+25+(i/10)*40,2,0,gra.ico[IC],TRUE,0);//�A�C�R��
		SetDrawBright(255,255,255);
	}

	//�M�͖�
	if(T >= 0){
		waku(		  XA-90,YA+460,600,30,6);//�g
		mes(		  XA-72,YA+463,sys.medal_name[T].c_str(),color.kuro,color.siro,1);
		//����
		waku(		  XA-90,YA+494,600,150,6);//�g
		mes_str(	  XA-82,YA+502,sys.medal_info[T].c_str(),color.kuro,color.siro,0);
		/*
		waku(		  XA-90,YA+618,600,30,6);//�g
		if(sys.medal_cnt[T] == 0) SetDrawBright(96,96,96);
		DrawRotaGraph(XA-72,YA+632,2,0,gra.ico[17],TRUE,0);
		SetDrawBright(255,255,255);
		mes_bmf(XA-58,YA+638,"Bonus Point",2);
		suu_bmf(XA+556,YA+634,2,sys.medal_gold[T],0);

		//�{�[�i�X�_
		//waku(XA+10,YA+618,500,30,6);//�g
		*/
	}

	sys.medal_type[0] = 0;
	sys.medal_type[1] = 0;
	sys.medal_type[2] = 0;

	fun.medal_check();

	for(int i=0;i<100;i++)
	{
		if( sys.medal_cnt[i] > 0 )
		{
			sys.medal_type[sys.medal_gold[i]]++;
		}
	}

	//���v���_����
	for(int i=0 ; i< 3;i++){
		waku(		  XA-90 + 200 * i ,YA+670, 190,30,6);//�g
		DrawRotaGraph(XA-72 + 200 * i ,YA+684,1,0,gra.ico[17-i],TRUE,0);
		if( i == 0	    ) mes_bmf(	  XA-58 + 10  + 200 * i ,YA+686,"gold",1);
		else if( i == 1 ) mes_bmf(	  XA-58 + 10  + 200 * i ,YA+686,"silver",1);
		else if( i == 2 ) mes_bmf(	  XA-58 + 10  + 200 * i ,YA+686,"bronze",1);

		mes_bmf(	  XA-58 + 100  + 200 * i ,YA+690,"x",1);
		suu_bmf(	  XA-58 + 130 + 200 * i ,YA+686,2,sys.medal_type[i],0);
	}

	//DrawRotaGraph(XA-72+120,YA+684,1,0,gra.ico[16],TRUE,0);
	//DrawRotaGraph(XA-72+240,YA+684,1,0,gra.ico[15],TRUE,0);


	return T;
}
int DRA::wep_db_s(int X,int Y,int W){

	if(sys.wep_maket[W] <= 0)
	{
		wep_db_no(X,Y,W);
		return 1;
	}

	int i;
	std::string str;
	int ICO;
	X += 300;
	Y += 34;

	int C = 0;

	//���햼�O�A�l�i�A��
	waku(6+X,6+Y,476,30,6);
	mes(64+X,12+Y,wep[W].name.c_str(),color.kuro,color.siro,0);
	DrawRotaGraph(24+X,20+Y,1,0,gra.wep[W],TRUE,0);//����A�C�R��

	if(W == NOU_NO)	{
		mes_bmf(X+44,Y+30,"ETC",1);
	}else{
		DrawRotaGraph(X+50,Y+16,1,0,gra.ico[wep[W].type],0);
		if(wep[W].type == 0) mes_bmf(X+44,Y+28,"SWD",1);
		else if(wep[W].type == 1) mes_bmf(X+44,Y+28,"LNC",1);
		else if(wep[W].type == 2) mes_bmf(X+44,Y+28,"AXE",1);
		else if(wep[W].type == 3) mes_bmf(X+44,Y+28,"ARW",1);
	}

	int N,L;//N �� N3���\�����鐔���AN2�̓Q�[�W�p
	double G;
	int YP = 0;
	for(i=0;i<16;i++,YP+=26){
		switch(i){
			case 0:
				str = "���i"	;ICO = 53;
				N  = wep[W].price * 100;
				G  = 100000.0/285;
			break;
			case 1:
				str = "��p"	;ICO = 52;
				N  = wep[W].seizou_cost*wep[W].price;
				G  = 100000.0/285;
			break;
			case 2:
				str = "����"	;ICO = 54;
				N  = wep[W].make_time/10;
				G  = 400.0/285;
				break;
			case 3:
				str = "�U����"	;ICO = 38;
				N  = wep[W].atk;
				G  = 320.0/285;
				break;
			case 4:
				str = "�ϋv��"	;ICO = 39;
				N  = wep[W].dur;
				G  = 100.0/285;
				break;
			case 5:
				str = "�W�q��"	;ICO = 86;
				N  = wep[W].ninki[0]+wep[W].ninki[1]+wep[W].ninki[2];
				G = 270.0/285;
			break;
			case 6://�ڋʕ␳				
				str = "���"	;ICO = 100;
				N  = wep[W].mtype;
				G = 270.0/285;
			break;
			case 7://�ڋʕ␳				
				str = "����"	;ICO = 100;
				N  = wep[W].mzoku;
				G = 270.0/285;
			break;
			case 8:
				YP += 5;
				str = "�J����"	;ICO = 53;
				N  = wep[W].create_time/54;
				G  = 500000.0/285;
			break;
			case 9:
				str = "�M��x"	;ICO = 7;
				N  = wep[W].rank;
				G  = 200.0/285;
			break;
			case 10:
				str = "����LV"	;ICO = 1;
				N  = wep[W].req_clv[0];
				G  = 50.0/285;
			break;
			case 11:
				str = "�B�SLV"	;ICO = 2;
				N  = wep[W].req_clv[1];
				G  = 50.0/285;
			break;
			case 12:
				str = "�׍HLV"	;ICO = 3;
				N  = wep[W].req_clv[2];
				G  = 50.0/285;
			break;
			case 13:
				YP += 5;
				str = "����MAX"	;ICO = 15;//�ō����x���ɂ��
				N  = sys.wep_maxlv[W];
				G  = 100.0/285;
			break;
			case 14:
				str = "�J����";ICO = 15;//
				N  = sys.wep_cret[W];
				G  = 100.0/285;
			break;
			case 15:
				str = "������"	;ICO = 15;
				N  = sys.wep_maket[W];
				G  = 10000.0/285;
			break;

		}
		//���O�̂Ƃ��̘g
		waku(X+10,38+Y+YP  ,75,24,6);
		waku(X+90,38+Y+YP  ,90,24,6);
		mes(35+X,44+Y+YP,str.c_str(),color.kuro,color.siro,2);
		DrawRotaGraph(21+X,51+Y+YP,1,0,gra.ico[ICO],TRUE,0);
		waku(X+183,38+Y+YP ,289,24,6);

		L = min(285,int(N  / G));

		//�X�e�[�^�X�\��
		if(i==5){
			if(wep[W].ninki[0] > 0)			SetDrawBright(150,150,255);
			else if(wep[W].ninki[1] > 0)	SetDrawBright(255,150,150);
			else if(wep[W].ninki[2] > 0)	SetDrawBright(150,255,150);
			waku_c(X+185,40+Y+YP ,L,20,255,255,255);
		}else{
			waku_c(X+185,40+Y+YP ,L,20,255,100+i%2*50,0);
		}

		if(i == 6 || i== 7)	syou_bmf(170+X,52+Y+YP,N,0);
		else	if(i == 2)	suu_bmf(170+X,52+Y+YP,2,N,0);
		else				suu_bmf(170+X,52+Y+YP,2,N,0);
		SetDrawBright(255,255,255);
	}
	//�J���R�X�g
	//�M����x
	//�Z�p��ABC

	//�ő����
	//�J����
	//������

	//������(�J����������)

	waku(6+X,38+Y+26*17,476,130,6);

	int no = wep[W].req_mana;
	std::string mess = "";

	if (no <= 0 || no == 60)
	{
		mess = "�����������";
	}
	else
	{
		mess += "�u" + mana[no].name + "�v" + "���g�p����ƊJ���\��";
	}

	mes_str(16+X,48+Y+26*17,mess.c_str(),color.kuro,color.siro,0);

	return 1;
}
int DRA::mana_db_s(int X,int Y,int M){

	int T = mana[M].type;

	if(sys.mana_total[M] <= 0){
		mana_db_no(X,Y,M);
		return 1;
	}

	X +=300;
	Y += 34;

	shop[P].mana_day[M] = -100;//New����


	//��{���
	waku(X+6,Y+6,476,30,6);

	draw.mana_icon(X+6,Y+2,M,3);

	mes(X+64,Y+12,mana[M].name.c_str(),color.kuro,color.siro,0);

	int N,N2,L;
	double G;
	int ICO;
	std::string str;
	for(int i=0;i<6;i++){
		switch(i){
			case 0:
				str = "�l�o"	;ICO = 14;
				N  = shop[P].syou_mp[M];
				G  = 200.0/255;
			break;
			case 1:
				str = "��p"	;ICO = 53;
				N  = shop[P].syou_money[M]*100;
				if(M >= 61 && M <= 65) N = 0;
				G  = 5000000.0/255;
			break;
			case 2:
				str = "�a�v�ω�"	;ICO = 47;
				N  = (int)mana[M].b_w_c;
				G  = 10.0/255;
				break;
			case 3:
				str = "�a�v����"	;ICO = 47;
				N  = max(mana[M].b_w_d,-100);
				N2 = min(mana[M].b_w_u,100);
				G  = 100.0/255;
				break;
			case 4:
				str = "����k�u"	;ICO = mana[M].icon;
				N  = mana[M].rank;
				G  = 10.0/255;
				break;
			case 5:
				str = "�݌v��"	;ICO = 15;//�g�p�񐔂ɉ�����
				N  = sys.mana_total[M];
				G  = 100.0/255;
			break;
		}
		//���O�̂Ƃ��̘g
		waku(X+10,38+Y+i*26  ,85,24,6);
		if(i != 3){
			waku(X+100,38+Y+i*26 ,110,24,6);
			waku(X+213,38+Y+i*26 ,259,24,6);
		}else{
			waku(X+100,38+Y+i*26 ,54,24,6);
			waku(X+156,38+Y+i*26 ,259,24,6);
			waku(X+417,38+Y+i*26 ,55,24,6);
		}

		mes(35+X,44+Y+i*26,str.c_str(),color.kuro,color.siro,2);
		DrawRotaGraph(21+X,51+Y+i*26,1,0,gra.ico[ICO],TRUE,0);

		L = min(255,int(N  / G));

		//�X�e�[�^�X�\��
		if(i==2){//BW�ω�
			if(N > 0){
				mes_bmf(X+110,51+Y+i*26,"Black",1);
				waku_c(X+215,40+Y+i*26 ,abs(L),20,0,0,0);
			}else if(N<0){
				mes_bmf(X+110,51+Y+i*26,"White",1);
				waku_c(X+215,40+Y+i*26 ,abs(L),20,255,255,255);
			}else{
				mes_bmf(X+110,51+Y+i*26,"No color",1);
			}
			syou_bmf(200+X,52+Y+i*26,abs(N)*10,0);
		}else if(i==3){
			//BW����
			for(int G=128+N*128/100;G<128+N2*127/100;G++){
				DrawLine(X+158+G,40+Y+i*26,X+158+G,60+Y+i*26,GetColor(255-G,255-G,255-G));
			}
			suu_bmf(144+X,52+Y+i*26,2,N,0);
			suu_bmf(462+X,52+Y+i*26,2,N2,0);

		}else{
			waku_c(X+215,40+Y+i*26 ,L,20,255,100+i%2*50,0);
			suu_bmf(200+X,52+Y+i*26,2,N,0);
		}
	}
	//��{������
	waku(X+10,Y+38+7*26  ,476,90,6);
	mes_stri(X+18,Y+58+7*26,mana[M].zukan.c_str());

	return 1;
}

int DRA::wep_db_no(int X,int Y, int W){
	//�O���t�B�b�N
	//�U��
	//�ϋv
	//�W�q
	//���l
	//����
	//����
	int i;
	std::string str;
	int ICO;
	X += 300;
	Y += 34;

	int C = 0;

	//���햼�O�A�l�i�A��
	waku(6+X,6+Y,476,30,6);
	mes(64+X,12+Y,"????",color.kuro,color.siro,0);
	DrawRotaGraph(24+X,20+Y,1,0,gra.ico[57],TRUE,0);//����A�C�R��

	mes_bmf(X+44,Y+30,"???",1);

	int YP = 0;
	for(i=0;i<16;i++,YP+=26){
		switch(i){
			case 0:
				str = "���i"	;ICO = 53;
			break;
			case 1:
				str = "��p"	;ICO = 52;
			break;
			case 2:
				str = "����"	;ICO = 54;
				break;
			case 3:
				str = "�U����"	;ICO = 38;
				break;
			case 4:
				str = "�ϋv��"	;ICO = 39;
				break;
			case 5:
				str = "�W�q��"	;ICO = 86;
			break;
			case 6://�ڋʕ␳				
				str = "���"	;ICO = 100;
			break;
			case 7://�ڋʕ␳				
				str = "����"	;ICO = 100;
			break;
			case 8:
				YP += 5;
				str = "�J����"	;ICO = 53;
			break;
			case 9:
				str = "�M��x"	;ICO = 7;
			break;
			case 10:
				str = "����LV"	;ICO = 1;
			break;
			case 11:
				str = "�B�SLV"	;ICO = 2;
			break;
			case 12:
				str = "�׍HLV"	;ICO = 3;
			break;
			case 13:
				YP += 5;
				str = "����MAX"	;ICO = 15;
			break;
			case 14:
				str = "�J����";ICO = 15;
			break;
			case 15:
				str = "������"	;ICO = 15;
			break;

		}
		//���O�̂Ƃ��̘g
		waku(X+10,38+Y+YP  ,75,24,6);
		waku(X+90,38+Y+YP  ,90,24,6);
		mes(35+X,44+Y+YP,str.c_str(),color.kuro,color.siro,2);
		DrawRotaGraph(21+X,51+Y+YP,1,0,gra.ico[ICO],TRUE,0);
		waku(X+183,38+Y+YP ,289,24,6);

		mes_bmf(140+X,52+Y+YP,"???",2);

		SetDrawBright(255,255,255);
	}
	//�J���R�X�g
	//�M����x
	//�Z�p��ABC

	//�ő����
	//�J����
	//������

	//������(�J����������)
	waku(6+X,38+Y+26*17,476,130,6);
	mes_str(16+X,48+Y+26*17,"�H�H�H�H--",color.kuro,color.siro,0);

	//������(�J����������)

	waku(6 + X, 38 + Y + 26 * 17, 476, 130, 6);

	int no = wep[W].req_mana;
	std::string mess = "";

	int total = 10;
	for (int i = 0; i < 100; ++i)
	{
		total += sys.medal_cnt[i];
	}

	if (no <= 0 || no == 60)
	{
		mess = "�����������";
	}
	else if ( wep[W].rank <= total)
	{
		mess += "�u" + mana[no].name + "�v" + "���g�p����ƊJ���\��";
	}
	else
	{
		mess = "�H�H�H�H";
	}

	mes_str(16 + X, 48 + Y + 26 * 17, mess.c_str(), color.kuro, color.siro, 0);


	return 1;
}
int DRA::mana_db_no(int X,int Y,int M){

	X +=300;
	Y += 34;

	//��{���
	waku(X+6,Y+6,476,30,6);
	DrawRotaGraph(24+X,20+Y,2,0,gra.ico[57],TRUE,0);//����A�C�R��

	mes(X+64,Y+12,"�H�H�H�H",color.kuro,color.siro,0);

	int ICO;
	std::string str;
	for(int i=0;i<6;i++){
		switch(i){
			case 0:
				str = "�l�o"	;ICO = 14;
			break;
			case 1:
				str = "��p"	;ICO = 53;
			break;
			case 2:
				str = "�a�v�ω�"	;ICO = 47;
				break;
			case 3:
				str = "�a�v����"	;ICO = 47;
				break;
			case 4:
				str = "����k�u"	;ICO = mana[M].icon;
				break;
			case 5:
				str = "�݌v��"	;ICO = 15;
			break;
		}
		//���O�̂Ƃ��̘g
		waku(X+10,38+Y+i*26  ,85,24,6);
		if(i != 3){
			waku(X+100,38+Y+i*26 ,110,24,6);
			waku(X+213,38+Y+i*26 ,259,24,6);
		}else{
			waku(X+100,38+Y+i*26 ,54,24,6);
			waku(X+156,38+Y+i*26 ,259,24,6);
			waku(X+417,38+Y+i*26 ,55,24,6);
		}

		mes(35+X,44+Y+i*26,str.c_str(),color.kuro,color.siro,2);
		DrawRotaGraph(21+X,51+Y+i*26,1,0,gra.ico[ICO],TRUE,0);


		//�X�e�[�^�X�\��
		if(i==2){//BW�ω�
			mes_bmf(170+X,52+Y+i*26,"???",2);
		}else if(i==3){
			//BW����
			mes_bmf(114+X,52+Y+i*26,"???",2);
			mes_bmf(432+X,52+Y+i*26,"???",2);
		}else{
			mes_bmf(170+X,52+Y+i*26,"???",2);
		}
	}
	//��{������
	waku(X+10,38+Y+7*26  ,476,90,6);
	mes_i(X+18,Y-18+Y+7*26,"�H�H�H�H");

	return 1;
}

int DRA::select_mode(){

	int X,Y,SX,SY;

	X = data.window_x/2-200;
	Y = data.window_y/2-200;

	SX = data.window_x;

	if(data.window_y*4/data.window_x == 3)SY = SX*3/4;
	else								  SY = SX*9/16;

	waku(X,Y-40,400,40,5);
	waku(X,Y,400,360,5);

	waku(X+365,Y-35,30,30,6);
	DrawRotaGraph(X+380,Y-20,2,0,gra.ico[57],TRUE,0);//����

	mes_bmf(X+20,Y-20,"Select Mode",2);

	int N = -1;
	if( Inp.m_x >= X+16 && Inp.m_x < X+16+40*9 &&
		Inp.m_y >= Y+16 && Inp.m_y < Y+16+40*2 ){
		N = (Inp.m_x-X-16)/40 + (Inp.m_y-Y-16)/40*9;
		if(Inp.m_LC == 1 && sys.play_flag[N] ){
			data.mode = N;
		}
		if(N>18){
			N = 18;
		}
	}
	//���ɐ������A��ɃA�C�R��
	for(int i=0,W=1;i<18;i++,W++){
		int IC = data.mode_icon[i+1];

		if( !sys.play_flag[i] ) IC = 57;//

		if(i == N){
			waku_c(X+16+(i%9)*40,Y+16+(i/9)*40,40,40,255,0,0);//�g
		}
		waku(X+18+(i%9)*40,Y+18+(i/9)*40,36,36,6);//�g
		DrawRotaGraph(X+35+(i%9)*40,Y+35+(i/9)*40,2,0,gra.ico[IC],TRUE,0);//�A�C�R��
	}

	waku_c(X+16,Y+106,200,36,255,255,255);//�g

	if(N != -1){
		if( !sys.play_flag[N] ){
			mes(X+20,Y+111,"�H�H�H�H",color.kuro,color.siro,1);
		}else{
			mes(X+20,Y+111,data.mode_n[N+1].c_str(),color.kuro,color.siro,1);
		}
	}
	if(Inp.m_x >= X+365 && Inp.m_x <= X+400 && Inp.m_y >= Y-35 && Inp.m_y <= Y-5  && Inp.m_LC==1) data.mode = -2;//�L�����Z��
	if(Inp.m_RC == 1) data.mode = -2;


	waku_c(X+16,Y+16+130,370,200,255,255,255);


	if(N != -1 && !sys.play_flag[N] ){
		mes_str(X+30,Y+160,"�H�H�H�H",color.kuro,color.siro,0);
	}else{
		switch(N){
			case -1:
				mes_str(X+30,Y+160,"���[�h��I�����Ă�������--",color.kuro,color.siro,0);
			break;
			case 0:
				mes_str(X+30,Y+160,"�t�����e�B�A�J��ɂ�����--�d��Ȗ������ʂ��������퉮--���j�ɖ�����A�m��ꂴ�邻�̎p��--�ʂ����Ăǂ̂悤�Ȃ��̂ł��������E�E�E",color.kuro,color.siro,0);
			break;
			case 1://�t���[
				mes_str(X+30,Y+160,"�T�̕��퉮�ň�ԂɂȂ낤�I",color.kuro,color.siro,0);
			break;
			case 2://�{�[�i�X
				mes_str(X+30,Y+160,"�M�͂������ƗL���ɂȂ��I",color.kuro,color.siro,0);
			break;
			case 3://����
				mes_str(X+30,Y+160,"��������������W�߂悤�I",color.kuro,color.siro,0);
			break;
			case 4://���q
				mes_str(X+30,Y+160,"���q�������t�W�߂悤�I",color.kuro,color.siro,0);
			break;
			case 5://����
				mes_str(X+30,Y+160,"�������z���グ�悤",color.kuro,color.siro,0);
			break;
		}
	}

	return 1;
}
int DRA::select_nanndo(){
	//��Փx�I�����

	int X,Y,SX,SY;
	const int WS= 300;

	X = data.window_x/2-WS/2;
	Y = data.window_y/2-200;

	SX = data.window_x;

	if(data.window_y*4/data.window_x == 3)SY = SX*3/4;
	else								  SY = SX*9/16;

	waku(X,Y-40,WS,40,5);
	waku(X,Y   ,WS,300,5);

	waku(X+WS-35,Y-35,30,30,6);
	DrawRotaGraph(X+WS-20,Y-20,2,0,gra.ico[57],TRUE,0);//����

	mes_bmf(X+20,Y-20,"Select difficulty",2);
	int N=-1;
	if( Inp.m_x >= X+8  && Inp.m_x < X+8+WS-16 &&
		Inp.m_y >= Y+18 && Inp.m_y < Y+33+30*6 ){
		N = (Inp.m_y-Y-18)/30;
		if(N > sys.nanndo_flag ) N = -1;
		if(Inp.m_LC == 1)
		{
			data.nando = N;	
		}
	}

	//��Փx���X�g�\��
	for(int i=0,W=1;i<4;i++,W++){
		if(N == i) waku_c(X+6,Y+16+i*30,WS-12,32,255,0,0);
		waku(X+8,Y+18+i*30,WS-16,28,6);

		if(sys.nanndo_flag < i ) mes_bmf(X+40,Y+33+i*30,"???",2);
		else					 mes_bmf(X+40,Y+33+i*30,data.nanndo_n[i+1].c_str(),2);

	}

	waku(X+8,Y+16+150,WS-16,90,6);

	if(Inp.m_x >= X+WS-35 && Inp.m_x <= X+WS && Inp.m_y >= Y-35 && Inp.m_y <= Y-5 && Inp.m_LC==1) data.mode = -1;//�ЂƂ߂�
	if(Inp.m_RC == 1){
		data.mode = -1;
		Inp.m_RC = 0;
	}

	switch(N){
		case -1:
			mes_str(X+30,Y+175,"��Փx��I�����Ă�������",color.kuro,color.siro,0);
		break;
		case 0:
			mes_str(X+30,Y+175,"�m�[�}���I--�܂�����o�c���悤",color.kuro,color.siro,0);
		break;
		case 1:
			mes_str(X+30,Y+175,"�n�[�h�I--��������o�c���悤",color.kuro,color.siro,0);
		break;
		case 2:
			mes_str(X+30,Y+175,"�}�j�A�b�N�I--�V�r�A�Ɍo�c���悤",color.kuro,color.siro,0);
		break;
		case 3:
			mes_str(X+30,Y+175,"�f�X�}�[�`�I--�o�c���_��\",color.kuro,color.siro,0);
		break;
	}


	return 1;
}

int DRA::select_save(){


	int X,Y,SX,SY;
	static int SC = 0;
	static int LD_MODE = 0;


	X = data.window_x/2-300;
	Y = data.window_y/2-240;

	SX = data.window_x;

	if(data.window_y*4/data.window_x == 3)SY = SX*3/4;
	else								  SY = SX*9/16;

	waku(X,Y-40,600,40,5);
	waku(X,Y,600,440,5);

	waku(X+565,Y-35,30,30,6);
	DrawRotaGraph(X+580,Y-20,2,0,gra.ico[57],TRUE,0);//����

	mes_bmf(X+20,Y-20,"Select data",2);

	int N = -1;
	if( Inp.m_x >= X+6 && Inp.m_x < X+556 &&
		Inp.m_y >= Y+36 && Inp.m_y < Y+36+400 ){
		N = (Inp.m_y-Y-36)/40;
	}
	SC -= Inp.m_H;

	if(SC > rabel.cnt - 10) SC = rabel.cnt - 10;
	if(SC < 0 ) SC = 0;

	if(N >= 0) N+=SC;
	if(N >= rabel.cnt) N = -1;

	if(Inp.m_x >= X+565 && Inp.m_x <= X+595 && Inp.m_y >= Y-35 && Inp.m_y <= Y-5 && Inp.m_LC==1){
		LD_MODE = 0;
		return -2;//�ЂƂ߂�
	}

	if(Inp.m_RC == 1){
		LD_MODE = 0;
		return -2;
	}

	//�ǂݍ��݃��[�hor�폜���[�h
	if(LD_MODE == 0) waku_c(X+4,Y+4,104,30,0,0,255);
	else			 waku_c(X+114,Y+4,104,30,0,0,255);
	waku(X+6,Y+6,100,26,6);
	waku(X+116,Y+6,100,26,6);
	mes_bmf(X+30,Y+20,"Load",2);
	mes_bmf(X+130,Y+20,"Delete",2);

	if(Inp.m_y >= Y+6 && Inp.m_y <= Y+32 && Inp.m_LC==1){
		if(Inp.m_x >= X+6   && Inp.m_x <= X+106) LD_MODE = 0;
		if(Inp.m_x >= X+116 && Inp.m_x <= X+216) LD_MODE = 1;
	}

	char str[64];
	for(int i=0,W=SC,R=SC;i<10;i++,R++){
		if( R >= rabel.cnt) break;
		W = rabel.cnt - R - 1;

		if(R == N){//�I��
			waku_c(X+4,Y+34+i*40,560,40,255,0,0);//�g
		}
		waku(X+6,Y+36+i*40,556,36,6);//�g
		//�A�C�R��
		//���̓A�C�R��
		DrawRotaGraph(X+25,Y+53+i*40,2,0,gra.ico[shop[rabel.list[W].shop].icon],TRUE,0);
		//���[�h�A�C�R��
		DrawRotaGraph(X+65,Y+53+i*40,2,0,gra.ico[data.mode_icon[rabel.list[W].mode+1]],TRUE,0);
		//���[�h��
		mes(X+100,Y+40+i*40,data.mode_n[rabel.list[W].mode+1].c_str(),color.kuro,color.siro,0);
		//��Փx
		mes_bmf(X+100,Y+65+i*40,data.nanndo_n[rabel.list[W].dif+1].c_str(),1);
		if(rabel.list[W].game_over != -1){
			mes_bmf(X+55,Y+65+i*40,"end",1);
		}

		//����
		suu_bmf(X+330,Y+55+i*40,2,rabel.list[W].day+1,0);
		mes(X+350,Y+45+i*40,"����",color.kuro,color.siro,0);
		//�v���C����
		sprintf_s(str,"%d:%d:%d",rabel.list[W].time/3600%60,rabel.list[W].time/60%60,rabel.list[W].time%60);
		mes(X+450,Y+45+i*40,str,color.kuro,color.siro,0);
	}


	//�X�N���[���o�[
	if(rabel.cnt>10){
		waku(X+584,Y,16,440,5);
		int GP = SC*428/max(1,rabel.cnt);
		int GL = min(4280/max(1,rabel.cnt),428);
		DrawBox(X+588,Y+4+GP,X+594,Y+6+GL+GP,color.aka,1);
	}

	if(N != -1 && Inp.m_LC == 1){
		//�m�F
		if(LD_MODE == 0){
			if(draw.kakunin("--�L�^�̑�������n�߂܂����H",0) == 1){
				return rabel.cnt - 1 - N;
			}
		}else{
			if(draw.kakunin("--�L�^���폜���܂����H",0) == 1){
					if(draw.kakunin("--�{���ɍ폜���܂����H",0) == 1){
						SetCurrentDirectory(data.szDir);						
						std::string name;
						name = "File/save/" + rabel.list[rabel.cnt - 1 - N].name;
						if( DeleteFile( name.c_str() ) == 1){						
							fun.load_rabel();
						}
				}
			}
		}
	}

	return -1;
}

int DRA::option(/*�I�v�V�������*/int size,int wide,int full,int bgm,int wav,int vram){
	int X,Y,SX,SY,i;

	X = data.window_x/2-225;
	Y = data.window_y/2-160;

	switch(size){
		case 0:SX = 1024;break;
		case 1:SX = 1280;break;
		case 2:SX = 1440;break;
		case 3:SX = 1600;break;
		case 4:SX = 1920;break;
	}
	if(wide == 0)SY = SX*3/4;
	else		 SY = SX*9/16;

	waku(X,Y-40,450,40,5);
	waku(X,Y,450,340,3);

	DrawRotaGraph(X+24,Y-20,2,0,gra.ico[79],TRUE,0);//�R���t�B�O
	waku(X+413,Y-35,30,30,6);
	DrawRotaGraph(X+428,Y-20,2,0,gra.ico[57],TRUE,0);//����

	for(i=0;i<6;i++){
		waku(X+10,Y+10+i*40,200,36,7);
		waku(X+220,Y+10+i*40,200,36,7);
		DrawRotaGraph(X+30,Y+30+i*40,2,0,gra.ico[80+i],TRUE,0);
		DrawRotaGraph(X+240,Y+28+i*40,2,0,gra.ico[58],TRUE,0);
		DrawRotaGraph(X+400,Y+28+i*40,2,0,gra.ico[59],TRUE,0);
	}

	mes(X+50,Y-34,"�ݒ�ύX",color.siro,color.kuro,1);

	mes(X+60,Y+20,"�E�B���h�E�T�C�Y",color.kuro,color.siro,0);
	suu_bmf(X+302,Y+30,2,SX,0);
	suu_bmf(X+377,Y+30,2,SY,0);
	mes(X+315,Y+20,"X",color.kuro,color.siro,0);


	mes(X+60,Y+60,"�c����",color.kuro,color.siro,0);
	if(wide==0) mes(X+300,Y+60," 4:3",color.kuro,color.siro,0);
	else		mes(X+300,Y+60,"16:9",color.kuro,color.siro,0);

	mes(X+60,Y+100,"��ʃ��[�h",color.kuro,color.siro,0);
	if(full == 0)	mes(X+270,Y+100,"�E�B���h�E",color.kuro,color.siro,0);
	else			mes(X+285,Y+100,"�ٽ�ذ�",color.kuro,color.siro,0);

	mes(X+60,Y+140,"VIDEO RAM",color.kuro,color.siro,0);
	if(vram == 0)	mes(X+270,Y+140,"�g�p���Ȃ���",color.kuro,color.siro,0);
	else			mes(X+280,Y+140,"�g�p���遦",color.kuro,color.siro,0);

	mes(X+60,Y+180,"�a�f�l�@����",color.kuro,color.siro,0);
	suu_bmf(X+325,Y+190,2,bgm,0);
	mes(X+345,Y+180,"%",color.kuro,color.siro,0);

	mes(X+60,Y+220,"���ʉ��@����",color.kuro,color.siro,0);
	suu_bmf(X+325,Y+230,2,wav,0);
	mes(X+345,Y+220,"%",color.kuro,color.siro,0);

	mes(X+20,Y+260,"������N�����X�V",color.kuro,color.siro,0);
	if(Inp.m_x >= data.window_x/2-215 && Inp.m_x <= data.window_x/2-25  && (Inp.m_y - data.window_y/2 + 150)/40==7 ){
		  waku(X+10,Y+290,200,36,4);
	}else waku(X+10,Y+290,200,36,2);
	if(Inp.m_x >= data.window_x/2-5   && Inp.m_x <= data.window_x/2+185 && (Inp.m_y - data.window_y/2 + 150)/40==7 ){
		  waku(X+220,Y+290,200,36,4);
	}else waku(X+220,Y+290,200,36,2);
	
	
	mes(X+90,Y+300,"�n�j",color.kuro,color.siro,0);
	mes(X+280,Y+300,"�L�����Z��",color.kuro,color.siro,0);
	return 1;
}
int DRA::tutorial_menu(){

	int X,Y,N = 0;

	X = data.window_x/2-300;
	Y = data.window_y/2-240;

	waku(X,Y-40,600,40,5);
	waku(X,Y,600,500,3);

	DrawRotaGraph(X+24,Y-20,2,0,gra.ico[89],TRUE,0);//����
	waku(X+563,Y-35,30,30,6);
	DrawRotaGraph(X+578,Y-20,2,0,gra.ico[57],TRUE,0);//����

	mes(X+50,Y-34,"�w���v",color.siro,color.kuro,1);
	N = -1;
	if(Inp.m_y	<data.window_y/2-210 || Inp.m_y	>=data.window_y/2-210+36*10) N = -1;
	else if(Inp.m_x >= X+20  && Inp.m_x<= X+320) N = ( Inp.m_y-(data.window_y/2-210) ) / 36;
	else if(Inp.m_x >= X+330 && Inp.m_x<= X+630) N = ( Inp.m_y-(data.window_y/2-210) ) / 36 + 10;

	for(int i=0;i<20;i++){
		if(N==i) waku_c(X+20+i/10*300,Y+30+i%10*36,260,28,200,200,255);
		else	 waku_c(X+20+i/10*300,Y+30+i%10*36,260,28,255,255,255);
		///sys.help_flag[i] = 1;
		if(sys.help_flag[i] == 1){
			switch(i){
				case  0:mes(X+30+i/10*300,Y+30+i%10*36,"�͂��߂�",color.kuro,color.siro,1);break;
				case  1:mes(X+30+i/10*300,Y+30+i%10*36,"��͂�",color.kuro,color.siro,1);break;
				case  2:mes(X+30+i/10*300,Y+30+i%10*36,"�X���A�q�Ɛڋq",color.kuro,color.siro,1);break;
				case  3:mes(X+30+i/10*300,Y+30+i%10*36,"�E�l�A����J���E����",color.kuro,color.siro,1);break;
				case  4:mes(X+30+i/10*300,Y+30+i%10*36,"�]�ƈ��̌ٗp",color.kuro,color.siro,1);break;
				case  5:mes(X+30+i/10*300,Y+30+i%10*36,"�n���^�[�ɂ���",color.kuro,color.siro,1);break;
				case  6:mes(X+30+i/10*300,Y+30+i%10*36,"���O�ƃC�x���g",color.kuro,color.siro,1);break;
				case  7:mes(X+30+i/10*300,Y+30+i%10*36,"�����E�ŋ��E�[�i",color.kuro,color.siro,1);break;
				case  8:mes(X+30+i/10*300,Y+30+i%10*36,"�u���b�N�x",color.kuro,color.siro,1);break;
				case  9:mes(X+30+i/10*300,Y+30+i%10*36,"���C�o���X",color.kuro,color.siro,1);break;

				case 10:mes(X+30+i/10*300,Y+30+i%10*36,"�o�c��p",color.kuro,color.siro,1);break;
				case 11:mes(X+30+i/10*300,Y+30+i%10*36,"������",color.kuro,color.siro,1);break;
				case 12:mes(X+30+i/10*300,Y+30+i%10*36,"�H����",color.kuro,color.siro,1);break;
				case 13:mes(X+30+i/10*300,Y+30+i%10*36,"�J����",color.kuro,color.siro,1);break;
				case 14:mes(X+30+i/10*300,Y+30+i%10*36,"��`��",color.kuro,color.siro,1);break;
				case 15:mes(X+30+i/10*300,Y+30+i%10*36,"�Ղ�",color.kuro,color.siro,1);break;
				case 16:mes(X+30+i/10*300,Y+30+i%10*36,"�t���[���[�h",color.kuro,color.siro,1);break;
				case 17:mes(X+30+i/10*300,Y+30+i%10*36,"�Q�[���I�[�o�[",color.kuro,color.siro,1);break;
				case 18:mes(X+30+i/10*300,Y+30+i%10*36,"�^�C�g�����",color.kuro,color.siro,1);break;
				case 19:mes(X+30+i/10*300,Y+30+i%10*36,"��",color.kuro,color.siro,1);break;
			}

		}else mes(X+30+i/10*300,Y+30+i%10*36,"????",color.kuro,color.siro,1);
	}

	return N;
}
int DRA::kakunin(const char* M,int T){

	int X,Y,SX,SY;

	X = data.window_x/2-175;
	Y = data.window_y/2-60;
	
	SX = data.window_x;
	
	if(data.window_y*4/data.window_x == 3)SY = SX*3/4;
	else								  SY = SX*9/16;

	int YA = Y+85;

	while(1){
		fun.inp_check();
		//�`��
		waku(X,Y-40,350,180,1);

		mes_str(X+40,Y-10,M,color.siro,color.kuro,0);

		if(T == 0){
			waku(X+20,YA,150,30,10);
			waku(X+180,YA,150,30,10);

			if(Inp.m_y >= YA && Inp.m_y <= YA+30){
				if(Inp.m_x >= X+20 && Inp.m_x <= X+170){
					waku(X+20,YA,150,30,2);
					if(Inp.m_LC == 1) return 1;
				}
				if(Inp.m_x >= X+180 && Inp.m_x <= X+330){
					waku(X+180,YA,150,30,2);
					if(Inp.m_LC == 1) return 0;
				}
			}
			mes(X+80,YA+5,"�n�j",color.kuro,color.siro,0);
			mes(X+210,YA+5,"�L�����Z��",color.kuro,color.siro,0);
		}else{
			waku(X+100,YA,150,30,10);

			if(Inp.m_y >= YA && Inp.m_y <= YA+30 && Inp.m_x >= X+100 && Inp.m_x <= X+250){
					waku(X+100,YA,150,30,2);
					if(Inp.m_LC == 1) return 1;
			}
			mes(X+150,YA+5,"�n�j",color.kuro,color.siro,0);
		}

		ScreenFlip();

		if(fun.err_c()== -1) return -1;
	}

	return 0;
}

int DRA::winning_mode(){//���������E�B���h�E
	//�j�Y����������


	return 1;
}

int DRA::mes_str(int X,int Y,const char* M,int C,int C2,int FONT){

	std::string str = M;
	unsigned int loc;

	while(1){
		loc = str.find("--",0);
		if(	loc == std::string::npos){
			mes(X,Y,str.c_str(),C,C2,FONT);
			break;
		}else{
			//���������ꍇ
			mes(X,Y,str.substr(0,loc).c_str(),C,C2,FONT);
			Y+=25;
			str.erase(0,loc+2);
		}
	}

	return 1;
}
int DRA::mes_stri(int X,int Y,const char* M){

	std::string str = M;
	unsigned int loc;

	while(1){
		loc = str.find("--",0);
		if(	loc == std::string::npos){
			mes_i(X,Y,str.c_str());
			break;
		}else{
			//���������ꍇ
			mes_i(X,Y,str.substr(0,loc).c_str());
			Y+=20;
			str.erase(0,loc+2);
		}
	}

	return 1;
}
int DRA::game_over(){


	int X,Y;

	X = data.window_x/2-300;
	Y = data.window_y/2-230;

	waku(X,Y,600,460,3);

	//����

	if(data.game_over / 100 == P){//���X����
		DrawExtendGraph(X + 10, Y + 10, X + 590, Y + 340, gra.back[9], false);

		waku(X + 10, Y + 350, 576, 60, 2);
		
		mes_bmf(X + 100, Y + 160, "Congratulations!!!", 4);


		switch(data.game_over%100){
			case 0://�q��
				mes_str(X+20,Y+358,"�q���ɂ�鏟��--",color.kuro,color.siro,0);
			break;
			case 1://����
				mes_str(X+20,Y+358,"�����ɂ�鏟��--",color.kuro,color.siro,0);
			break;
			case 2://������グ
				mes_str(X+20,Y+358,"������ɂ�鏟��--",color.kuro,color.siro,0);
			break;
			case 3://������グ
				mes_str(X+20,Y+358,"������ɂ�鏟��--",color.kuro,color.siro,0);
			break;
			case 4://������グ
				mes_str(X+20,Y+358,"������ɂ�鏟��--",color.kuro,color.siro,0);
			break;
			case 5://������グ
				mes_str(X+20,Y+358,"������ɂ�鏟��--",color.kuro,color.siro,0);
			break;
			case 6://�|����グ
				mes_str(X+20,Y+358,"�|����ɂ�鏟��--",color.kuro,color.siro,0);
			break;
			case 7://��͂�
				mes_str(X+20,Y+358,"��͂������ɂ�鏟��--",color.kuro,color.siro,0);
			break;
			case 8://�J��
				mes_str(X+20,Y+358,"����J���ɂ�鏟��--",color.kuro,color.siro,0);
			break;
			case 9://����
				mes_str(X+20,Y+358,"�����ɂ�鏟��--",color.kuro,color.siro,0);
			break;
			case 10://���
				mes_str(X+20,Y+358,"�Ղ��тɂ�鏟��--",color.kuro,color.siro,0);
			break;
			case 11://�{�X
				mes_str(X+20,Y+358,"�_���W�������e�ɂ�鏟��--",color.kuro,color.siro,0);
			break;
			case 12://�j�Y
				mes_str(X+20,Y+358,"�|�Y�ɂ��s�k--",color.kuro,color.siro,0);
			break;
		}
	}else{//���X����
		DrawExtendGraph(X + 10, Y + 10, X + 590, Y + 340, gra.back[8], false);
		waku(X + 10, Y + 350, 576, 60, 2);
		mes_bmf(X + 100, Y + 160, "   you defeat    ", 4);

		switch (data.game_over % 100){
			case 0://�q��
				mes_str(X+20,Y+358,"�q���ɂ��s�k--",color.kuro,color.siro,0);
			break;
			case 1://����
				mes_str(X+20,Y+358,"�����ɂ��s�k--",color.kuro,color.siro,0);
			break;
			case 2://������グ
				mes_str(X+20,Y+358,"������ɂ��s�k--",color.kuro,color.siro,0);
			break;
			case 3://������グ
				mes_str(X+20,Y+358,"������ɂ��s�k--",color.kuro,color.siro,0);
			break;
			case 4://������グ
				mes_str(X+20,Y+358,"����ɂ��s�k--",color.kuro,color.siro,0);
			break;
			case 5://������グ
				mes_str(X+20,Y+358,"����ɂ��s�k--",color.kuro,color.siro,0);
			break;
			case 6://�|����グ
				mes_str(X+20,Y+358,"����ɂ��s�k--",color.kuro,color.siro,0);
			break;
			case 7://��͂�
				mes_str(X+20,Y+358,"��͂������ɂ��s�k--",color.kuro,color.siro,0);
			break;
			case 8://�J��
				mes_str(X+20,Y+358,"����J���ɂ��s�k--",color.kuro,color.siro,0);
			break;
			case 9://����
				mes_str(X+20,Y+358,"�����ɂ��s�k--",color.kuro,color.siro,0);
			break;
			case 10://���
				mes_str(X+20,Y+358,"�Ղ��тɂ��s�k--",color.kuro,color.siro,0);
			break;
			case 11://�{�X
				mes_str(X+20,Y+358,"�_���W�������e�ɂ��s�k--",color.kuro,color.siro,0);
			break;
		}
	}
	
	//�^�C�g��or�I��
	waku(X+90,Y+416,200,34,8);

	if(Inp.m_x > X+90 && Inp.m_x < X+290 && Inp.m_y > Y+416 && Inp.m_y < Y+460){
		mes(X+120,Y+422,"�^�C�g���֖߂�",GetColor(255,150,150),GetColor(255,0,0),0);
		if(Inp.m_LC == 1) return 1;
	}else{
		mes(X+120,Y+422,"�^�C�g���֖߂�",color.siro,color.kuro,0);
	}

	waku(X+310,Y+416,200,34,8);
	if(Inp.m_x > X+310 && Inp.m_x < X+510 && Inp.m_y > Y+416 && Inp.m_y < Y+460){
		mes(X+350,Y+422,"�܂��߂�Ȃ�",GetColor(255,150,150),GetColor(255,0,0),0);
		if(Inp.m_LC == 1) return 2;
	}else{
		mes(X+350,Y+422,"�܂��߂�Ȃ�",color.siro,color.kuro,0);
	}

	return 0;
}

int DRA::ending()
{
	int count = 0;
	int add_y = data.window_y + 300;
	int alpha = 0;
	int alpha_rate = 1;

	while(1)
	{
		count++;
		add_y--;

		if( alpha_rate != 0 )
		{
			alpha+= alpha_rate;
			if(alpha <= 0   )
			{
				alpha = 0;
				alpha_rate = 0;
			}
			if(alpha >= 255 )
			{
				alpha = 255;
				alpha_rate = 0;
			}
		}
		//�w�i�h��Ԃ�
		DrawBox(0,0,data.window_x  ,data.window_y,GetColor(0,0,0),1);

		mes_bmf2( 50 , 10 + add_y , "Flontier Black Smith" , 4 );
		//�o��l��
		mes_bmf2( 100 , 200 + add_y , "Character" , 4 );
		
		mes_bmf2( 130 , 250 + add_y , "ceo" , 4 );
		DrawRotaGraph( 100 , 250 + add_y , 2 , 0 , gra.unit[0][1] , true );

		//�I���
		mes_bmf2( 100 , 500 + add_y , "To be continued" , 4 );
		
		if(count == 1000 + data.window_y) break;

		//�E�ɏ��
		SetDrawBlendMode( DX_BLENDMODE_ALPHA , alpha ) ;
		DrawRotaGraph(data.window_x*3/4,data.window_y/2,1,0,gra.shop[0],0,0);
		SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
		if(fun.err_c()== -1) break;
		ScreenFlip();
	}

	return 1;
}


//�e��J���@�|�~�S
//���@�@�@�@��3���P
//������	��1
//��		��
//�p		��
//�H		�|
//��4��2��1�|7

//�M��184�@���@42�G�N�X�J���o�[
//�M��185�@�� 142�Q�C�{���O
//�M��186�@�� 246�~�����j��
//�M��187�@�| 346�������|
//����Ȃ�悳�@ 258	- ���O�����@58
//����Ȃ�I�V���� 259	- ���T�C�Y 130
//����Ȃ�R�X�p�@ 260	- ������ڂ� 286

//124�`132�͎̂g�p�񐔂��݂Ĕ���

//�~�[124	- �38�@�t���C�p��258
//���炭128 - �X�����O386 �s�R�n�� 270
//��q��130 - �V�g378 or�@����382
//����132�@ - �|��186
//��1��1��2�|3

//����125	- �I�V�����@��53
//�H�[123�@	- �R�X�p�@��74
//����126	- �悳�@��190
//���W127	- �R�X�p�@��174
//�Ŕ�129	- �I�V�����@��262
//����131	- �悳�@��250
//�В�133	- 396�����e

//��9��7��7�|11