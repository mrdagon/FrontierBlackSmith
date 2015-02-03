#pragma once

#include <string>
#include <list>
#include <sstream>
int DRA::work(/*経営メイン*/){

	//地図と上下タグの表示
	draw.wmap();
	//ウィンドウの表示
	int i,W;

	for(i=11;i>=0;i--){
		if(wind.on[11] == 1) break;//地図
		W=wind.hide[i];
		if(wind.on[W]==0)continue;
		//ウィンドウ表示
		if(opt.win_skin==0){
			waku(wind.x[W],wind.y[W],wind.sx[W],32,5);
			waku(wind.x[W],wind.y[W]+28,wind.sx[W],wind.sy[W]-28,3);
		}else{
			waku(wind.x[W],wind.y[W]+28,wind.sx[W],wind.sy[W]-28,1);
			waku(wind.x[W],wind.y[W],wind.sx[W],32,0);
		}
		//ウィンドウアイコン表示
		waku_c(wind.x[W]+6,wind.y[W]+5,20,20,255,255,255);
		waku_c(wind.x[W]+wind.sx[W]-26,wind.y[W]+5,20,20,255,255,255);
		waku_c(wind.x[W]+wind.sx[W]-52,wind.y[W]+5,20,20,255,255,255);
		int ICO[11] = {5,6,95,8,9,10,11,12,13,14,86};
		DrawRotaGraph(wind.x[W]+16,wind.y[W]+15,1,0,gra.ico[ICO[W]],TRUE,0);
		DrawRotaGraph(wind.x[W]+wind.sx[W]-16,wind.y[W]+15,1,0,gra.ico[57],TRUE,0);//閉じる
		DrawRotaGraph(wind.x[W]+wind.sx[W]-42,wind.y[W]+15,1,0,gra.ico[82],TRUE,0);//拡大縮小
		if( W == 4 ) mes_bmf(wind.x[W]+20,wind.y[W]+18,"T",1);
		if( W == 5 ) mes_bmf(wind.x[W]+20,wind.y[W]+18,"S",1);
		//最大＆縮小
		if(wind.scr_on[W]==1 && wind.sy[W]<wind.scrm[W]+38 && wind.sy[W] != wind.smini[W]){
			//スクロールバー表示//表示可能範囲、wind.sy[W]-45//-38
			waku(wind.x[W]+wind.sx[W]-20,wind.y[W]+32,16,wind.sy[W]-36,5);
			//スクロール位置計算
			int SY = wind.scr[W]*(wind.sy[W]-45)/wind.scrm[W];
			int SS = (wind.sy[W]-38)*(wind.sy[W]-45)/wind.scrm[W];
			if(SS<1)SS=1;
			DrawBox(wind.x[W]+wind.sx[W]-16,wind.y[W]+36+SY,wind.x[W]+wind.sx[W]-10 ,wind.y[W]+36+SY+SS,color.aka,1);
		}

		//内部表示
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
	
	//ドラッグ表示
	if(Inp.d_no>=0 && wind.syousai_hyouji == 0){
		if(Inp.d_type == 2 || Inp.d_type == 3){//武器ドラッグ
			draw.wep_icon(Inp.m_x,Inp.m_y,1.5,Inp.d_no);
		}else if(Inp.d_type == 5){//店員
			DrawRotaGraph(Inp.m_x,Inp.m_y,3,0, gra.unit[emp[Inp.d_no].gra][1] ,TRUE,0);
		}else if(Inp.d_type == 6){//職人
			if(Inp.d_no<1000)DrawRotaGraph(Inp.m_x,Inp.m_y,3,0, gra.unit[emp[Inp.d_no].gra][1] ,TRUE,0);
			else draw.wep_icon(Inp.m_x,Inp.m_y,1.5,wind.efold_s[Inp.d_no-1000]);
		}
	}

	if(wind.syousai_hyouji > 0){//詳細表示
		if(wind.graph_hyouuji >= 1)	draw.waku_graph();
		else						draw.waku_syuusi();
	}

	//ダイレクトヘルプ
	if(wind.info_on == 1)		win_help();//ダイレクトヘルプ
	if(wind.info_taiguu >=0)    win_htai();//待遇変化値



	return 1;
}
//wmap消えたので探す
int DRA::wmap(/*地図等*/){
	int XS=data.window_y/3*4;
	int YS=data.window_y;
	int R,G,B,i,D;
	int X[2],Y[2];

	//時間で暗さが変わる
	if(data.time < 4800){//開店前
		R = 55 + (data.time-4200)/3;
		G = 55 + (data.time-4200)/3;
		B = 55 + (data.time-4200)/3;
	}else if(data.time < 10200){//5時
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

	//経路表示
	for(D=0;D<100;D++){
		X[0] = dun[D].x;
		Y[0] = dun[D].y;
		for(i=0;i<5;i++){
			if(dun[D].root[i] == 0)break;//ルート無し
			if(dun[D].root_t[i] <= 0) continue;//探索前
			X[1] = X[0]-(X[0]-dun[dun[D].root[i]].x)*dun[D].root_t[i]/dun[D].root_k[i];//距離計算
			Y[1] = Y[0]-(Y[0]-dun[dun[D].root[i]].y)*dun[D].root_t[i]/dun[D].root_k[i];

			if(dun[dun[D].root[i]].seek>0){//目標発見済み
				DrawLine(X[0],Y[0],X[1],Y[1],color.siro,2);
			}else{
				DrawLine(X[0],Y[0],X[1],Y[1],color.aka,1);
			}
		}
	}

	//ダンジョン表示
	for(i=0;i<100;i++){

		if(dun[i].seek<0) continue;

		if(dun[i].seek==0){
			SetDrawBlendMode( DX_BLENDMODE_ALPHA , 64 );//目標状態
			DrawRotaGraph(dun[i].x,dun[i].y,1,0,gra.move[dun[i].type],TRUE);
			SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
			continue;
		}

		if(dun[i].boss_hp<=0 || dun[i].seek<100){
			DrawRotaGraph(dun[i].x,dun[i].y,1,0,gra.move[dun[i].type+9],TRUE);//廃墟化
		}

		if(dun[i].seek<100){
			DrawRectGraph(dun[i].x-12,dun[i].y-12,0,0,24,6*(101-dun[i].seek)/25,gra.move[dun[i].type],TRUE,0);
		}
			
		if(dun[i].boss_hp>0 && dun[i].seek>=100){//ボス発見状態
				DrawRotaGraph(dun[i].x	 ,dun[i].y	 ,1,0,gra.move[17],TRUE);
				DrawRectGraph(dun[i].x-12,dun[i].y-12,0,0,24,6*(dun[i].boss_hp*99/dun[i].boss_max+1)/25,gra.move[8],TRUE,0);
		}
		//ダンジョンLV
		if(i>0)	suu_bmf(dun[i].x+8,dun[i].y-8,1,i,0);

	}
	SetDrawBright( 255,255,255 );

	//各武器種別
	int ccc[4] = {0,0,0,0};
	for(int i=0;i<data.jinkou_max;i++){
		if(hun[i].life>0){
			ccc[hun[i].wep_t]++;
		}
	}

	//上タブ
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

	//ウィンドウアイコン
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
	//知名度＆資金


	//知名度ゲージ
	if( data.window_x != 1024){
		waku( 608,38,104,24,6);

		waku( 714,38,198,24,6);

		waku( 608,62,304,24,6);

		DrawRotaGraph(624,50,2,0,gra.ico[78],TRUE,0);

		mes(645,41,"知名度",color.kuro,color.siro,0);

		int TX = (int)(shop[P].timeido / 10);
		if( TX > 300 ) TX = 300;

		for(int i=0;i<TX;i++){
			int color;
			int pp = (i%50) * 5;

			if( i < 50 )		color = GetColor(255,0,0);//オレンジ
			else if(i < 100)	color = GetColor(255,pp,0);//黄色
			else if(i < 150)	color = GetColor(255 - pp,255,0);//緑
			else if(i < 200)	color = GetColor(0  ,255 , pp);//青緑
			else if(i < 250)	color = GetColor(0, 255 - pp ,255);//青
			else				color = GetColor(0, 0 ,255);

			if(i== 0 || i == TX -1) DrawLine(612+i,66,612+i,82,color);
			else					DrawLine(612+i,65,612+i,83,color);
		}

		syou_bmf(870,50,(int)shop[P].timeido,0);
		mes(885,41,"Ｐ",color.kuro,color.siro,0);
	}else{
		waku( 608,38,104,24,6);
		waku( 608,62,104,24,6);

		DrawRotaGraph(624,50,2,0,gra.ico[78],TRUE,0);

		//mes(645,41,"知名度",color.kuro,color.siro,0);
		syou_bmf(700,50,(int)shop[P].timeido,0);

		int TX = (int)(shop[P].timeido / 30);
		if( TX > 100 ) TX = 100;

		for(int i=0;i<TX;i++){
			int color;
			int pp = (i%17) * 15;
			if( i < 17 )		color = GetColor(255,0,0);//オレンジ
			else if(i < 34)		color = GetColor(255, pp ,0);//黄色
			else if(i < 51)		color = GetColor(255 - pp ,255,0);//緑
			else if(i < 68)		color = GetColor(0  ,255 , pp );//青緑
			else if(i < 85)		color = GetColor(0, 255 - pp ,255);//青
			else				color = GetColor(0, 0 ,255);

			if(i== 0 || i == TX -1) DrawLine(610+i,66,610+i,82,color);
			else					DrawLine(610+i,65,610+i,83,color);
		}
	}

	//ヘルプ
	waku(data.window_x-280,46,36,36,7);
	DrawRotaGraph(data.window_x - 262,64,2,0,gra.ico[89],TRUE,0);//ヘルプ
	mes_bmf(data.window_x - 272,48,"help",1);

	//ゲームスピード
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

	//オプション
	waku(data.window_x-110,46,36,36,7);
	DrawRotaGraph(data.window_x - 92,64,2,0,gra.ico[79],TRUE,0);
	mes_bmf(data.window_x - 110,48,"option",1);
	//タイトルへ
	waku(data.window_x-60,46,36,36,7);
	DrawRotaGraph(data.window_x - 42,64,2,0,gra.ico[65],TRUE,0);
	mes_bmf(data.window_x - 57,48,"title",1);

	char str[256];
	DrawRotaGraph(15,15,2,0,gra.ico[56],TRUE,0);
	sprintf_s(str,"%d年 %d月 %d日",200+data.day/336,1+data.mon%12,1+data.day%28);
	mes(30,6,str,color.siro,color.kuro,0);

	DrawRotaGraph(170,15,2,0,gra.ico[25+data.day%7],TRUE,0);
	//時計アイコン
	DrawRotaGraph(225,15,2,0,gra.ico[77],TRUE,0);
	if(data.time<6000)		sprintf_s(str," %d",data.time/600);
	else					sprintf_s(str,"%d",data.time/600);
	mes(250,6,str,color.siro,color.kuro,0);
	if(data.time%60<30)	mes(270,6,":",color.siro,color.kuro,0);

	if(data.time%600<100)	sprintf_s(str," %d",data.time/10%60);
	else					sprintf_s(str,"%d",data.time/10%60);
	mes(280,6,str,color.siro,color.kuro,0);

	//天気アイコン
	DrawRotaGraph(330,15,2,0,gra.ico[18+data.tenki],TRUE,0);
	switch(data.tenki){
		case 0:mes(350,6,"晴天",color.siro,color.kuro,0);break;
		case 1:mes(350,6,"曇天",color.siro,color.kuro,0);break;
		case 2:mes(350,6,"雨天",color.siro,color.kuro,0);break;
		case 3:mes(350,6,"豪雨",color.siro,color.kuro,0);break;
	}
	//営業状況
	DrawRotaGraph(415,15,2,0,gra.ico[11],TRUE,0);

	int NO = 0;
	if(shop[P].kouji > 0){
		sprintf_s(str,"工事中");
		NO = shop[P].kouji % 10;
	}else if(shop[P].holiday >0){
		if(shop[P].teikyuu == data.day % 7)	sprintf_s(str,"定休");
		else								sprintf_s(str,"臨休");
	}else{
		if(shop[P].price_rate != 100) sprintf_s(str,"割引");
		else						  sprintf_s(str,"営業");
		NO = 100-shop[P].price_rate;
	}
	mes(435,6,str,color.siro,color.kuro,0);
	if(NO!=0)suu_bmf(470,22,2,NO,2);
	//流行
	DrawRotaGraph(500,15,2,0,gra.ico[35],TRUE,0);

	switch(data.boom){
		case  0:sprintf_s(str,"なし");break;
		case  1:sprintf_s(str,"狩人");break;
		case  2:sprintf_s(str,"神怒");break;
		case  3:sprintf_s(str," 剣 ");break;
		case  4:sprintf_s(str," 槍 ");break;
		case  5:sprintf_s(str," 斧 ");break;
		case  6:sprintf_s(str," 弓");break;
		case  7:sprintf_s(str,"強さ");break;
		case  8:sprintf_s(str,"格好");break;
		case  9:sprintf_s(str,"買得");break;
	}
	mes(520,6,str,color.siro,color.kuro,0);

	//人口
	DrawRotaGraph(700,15,2,0,gra.ico[5],TRUE,0);
	suu_bmf(770,16,2,data.jinkou,0);
	mes(782,6,"人",color.siro,color.kuro,0);
	//資金
	DrawRotaGraph(830,15,2,0,gra.ico[53],TRUE,0);
	//sprintf_s(str,"%dＧ",shop[P].money);
	suu_bmf(978,16,2,int(shop[P].money),0);
	mes(990,6,"Ｇ",color.siro,color.kuro,0);

	return 1;
}
int DRA::win_1b(/*客情報*/int X,int Y){

	int H;
	static double ber=9;

	//スクロール最大値計算
	SetDrawArea(X+4,Y+4,X+wind.sx[0]-20,Y+112);

	for(H=999;H>=0;H--){
		if(shop[P].cust_list[H]>=0)break;
	}
	wind.scrm[0]=92+(H+1)*20;//最大スクロール

	//来客合計＆通過人数
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
		suu_bmf(X+65, Y+16+YH,1,shop[P].cust_cnt_t[i],0);//現在人数

		suu_bmf(X+120,Y+16+YH,1,shop[P].cust_day[data.day][i],0);//合計客数
		suu_bmf(X+165,Y+16+YH,1, shop[0].cust_day[data.day][i] + shop[1].cust_day[data.day][i]
								+shop[2].cust_day[data.day][i] + shop[3].cust_day[data.day][i]
								+shop[4].cust_day[data.day][i] , 0);
	}

	//客の状態
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
int DRA::win_2b(/*武器情報*/int X,int Y){

	//最上部にソート用タブ
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
			case 0: IC = 38;break;//攻撃力
			case 1: IC = 39;break;//耐久
			case 2: IC = 43;break;//集客力
			case 3: IC = 54;break;//工数
			case 4: IC = 53;break;//売値
			case 5: IC = 32;break;//儲け
		}
		DrawRotaGraph(X+31+54*i+SH,Y+22+SH,1+SH,0,gra.ico[IC],TRUE,0);
	}
	//武器取り扱い割合
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
	mes(X+294,Y+42,"種類",color.kuro,color.siro,2);
	suu_bmf(X+285,Y+50,2,shop[P].tana_now,0);

	//在庫割合
	for(i=0;i<4;i++)LON[i]=0;
	for(i=0;i<WEP_M;i++){
		LON[wep[i].type] += shop[P].wep_rest[i];
	}
	LON[0]-= shop[P].wep_rest[NOU_NO];//農具分剣から引く
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

	//武器フォルダ
	SetDrawArea(X+4,Y+76,X+wind.sx[1]-20,Y+wind.sy[1]-34);
	H=0;
	int WH = 290;
	for(i=0;i<7;i++){
		waku(6+X,78+Y-wind.scr[1]+H,40,30,6);
		if(i == 0) waku(36+X,78+Y-wind.scr[1]+H,5+40*shop[P].medama_max,wind.wfold_h[i],6);
		else	   waku(36+X,78+Y-wind.scr[1]+H,285,wind.wfold_h[i],6);
		

		switch(i){
			case 0:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[100],TRUE,0);break;//目玉商品
			case 1:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[22],TRUE,0);break;//新商品
			case 2:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[0],TRUE,0);break;//剣
			case 3:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[1],TRUE,0);break;//槍
			case 4:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[2],TRUE,0);break;//斧
			case 5:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[3],TRUE,0);break;//弓
			case 6:DrawRotaGraph(22+X,94+Y-wind.scr[1]+H,2,0,gra.ico[61],TRUE,0);break;//その他
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
int DRA::win_3b(/*店舗風景*/int X,int Y){

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

	//明るさ変更
	int R=255,G=255,B=255;

	if(data.time < 4800){//開店前
		R= 55 + (data.time-4200)/3;G = R; B = R;
	}else if(data.time < 10200){//5時
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
	//扉を表示
	if(shop[P].holiday == 1){
		if(SG == 0)					DrawExtendGraph(X+4+144*(WIDE),Y+4+96*(WIDE),X+4+176*(WIDE),Y+4+112*(WIDE),gra.ico[99],0);
		else if(SG == 1 || SG == 2)	DrawExtendGraph(X+4+144*(WIDE),Y+4+80*(WIDE),X+4+176*(WIDE),Y+4+112*(WIDE),gra.ico[99],0);
	}


	//雨表示
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

	for(int H=0;H<data.jinkou_max;H++){//冒険者表示
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
int DRA::win_4b(/*求人情報*/int X,int Y){
	SetDrawArea(X+4,Y+4,X+wind.sx[3]-20,Y+wind.sy[3]-34);

	wind.smini[3] = 75;
	wind.scr_on[3] = 1;

	int XP = 6 ,YP = -44 , E = -1 , i , T = -1 , SH , IC;
	std::string name;

	for(i=0;i<7;i++){//情報表示タブ
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
			case 4:IC = 91;break;//スキル
			case 5:IC = 73;break;//根性
			case 6:IC = 53;break;//給料
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
				case 0:name = "店員";IC = 46;break;
				case 1:name = "職人";IC = 45;break;
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
		if(emp[E].now_job == 2)	waku_c(2+X+XP,2+Y+YP,36,36,255,150,150);//R内定
		if(emp[E].mensetu[P] == 0){//面接前
			mes(10+X+XP,10+Y+YP,"？",color.kuro,color.siro,1);
		}else{
			//画像
			DrawRotaGraph(20+X+XP,20+Y+YP,2,0,gra.unit[emp[E].gra][1],TRUE,0);
			//レベル
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
					break;//スキル
				case 5:
					if(emp[E].mensetu[3][P] == 1)	suu_bmf(32+X+XP,30+Y+YP,2,emp[E].konjyou,2,5);
					else							mes_bmf(14+X+XP,30+Y+YP,"???",1);
					break;//根性
				case 6:
					suu_bmf(24+X+XP,28+Y+YP,2,emp[E].req_money/10,2,5);
					suu_bmf(34+X+XP,30+Y+YP,1,emp[E].req_money%10,2,5);
				break;//給料
			}
		}
		//職種
		DrawRotaGraph(10+X+XP,10+Y+YP,1,0,gra.ico[46-emp[E].job],TRUE,0);

		XP += 40;
	}
	wind.scrm[3] = YP + 80;
	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;
}
int DRA::win_5b(/*店員情報*/int X,int Y){
	int i,c,H,XC,YC,SH,IC;

	wind.smax[4] = 1000;

	SetDrawArea(X+4,Y+4,X+wind.sx[4]-20,Y+wind.sy[4]-34);

	for(i=0;i<7;i++){//情報表示タブ

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
			case 4:IC = 53;break;//給料
			case 5:IC = 48;break;//忠誠
			case 6:IC = 50;break;//満足
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
	//各コーナーの稼働率
	//店別客数//一番客が多い店を基準にする
	waku_c(X+255,Y+48,65,24,255,255,255);//最大
	suu_bmf(X+275,Y+60,2,(EIGYOU_T+48)/6,0);
	mes(X+280,Y+50,":",color.siro,color.kuro,0);
	suu_bmf(X+295,Y+60,2,(EIGYOU_T+48)%6,0);
	suu_bmf(X+310,Y+60,2,0,0);
	SetDrawBright(255,255,255);
	waku_c(X+34,Y+50,EIGYOU_T*3+4,20,255,255,255);//現在
	waku_c(X+36,Y+52,EIGYOU_T*3,16,50,50,255);//現在
	DrawRotaGraph(X+24,Y+56,2,0,gra.ico[77],TRUE,0);
	suu_bmf(X+55,Y+60,2,8,0);
	mes(X+60,Y+50,":",color.siro,color.kuro,0);
	suu_bmf(X+75,Y+60,2,0,0);
	suu_bmf(X+90,Y+60,2,0,0);
	SetDrawArea(X+4,Y+76,X+wind.sx[4]-20,Y+wind.sy[4]-34);
	//表示//武器は最大16種類まで
	H=0;
	if(wind.ts_hyouji == 0){//シフト変更
		for(i=WEP_M;i<WEP_M+4;i++){
			waku(6+X,78+Y-wind.scr[4]+H,40,30,6);
			waku(36+X,78+Y-wind.scr[4]+H,290,wind.efold_h[i],6);
			switch(i-WEP_M){
				case 0:DrawRotaGraph(22+X,94+Y-wind.scr[4]+H,2,0,gra.ico[0],TRUE,0);break;
				case 1:DrawRotaGraph(22+X,94+Y-wind.scr[4]+H,2,0,gra.ico[1],TRUE,0);break;
				case 2:DrawRotaGraph(22+X,94+Y-wind.scr[4]+H,2,0,gra.ico[2],TRUE,0);break;
				case 3:DrawRotaGraph(22+X,94+Y-wind.scr[4]+H,2,0,gra.ico[3],TRUE,0);break;
			}
			//人物描画
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
			//フォルダ位置補正
			H +=wind.efold_h[i]+4;
		}
	}else{//待遇変更
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
			//人物描画
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
			//フォルダ位置補正
			H +=wind.tfold_h[i][0]+4;
		}
	}


	wind.scrm[4] = H + 76;

	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;
}
int DRA::win_6b(/*職人情報*/int X,int Y){
	int i,c,H,XC,YC,SH,IC,WN;

	SetDrawArea(X+4,Y+4,X+wind.sx[5]-20,Y+wind.sy[5]-34);

	for(i=0;i<7;i++){//情報表示タブ

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
			case 4:IC = 53;break;//給料
			case 5:IC = 48;break;//忠誠
			case 6:IC = 50;break;//満足
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
	//稼動時間
	if(shop[P].koubou_n<shop[P].koubou_t)		SetDrawBright(255,150,150);
	else if(shop[P].koubou_n>shop[P].koubou_t)	SetDrawBright(150,150,255);
	waku_c(X+255,Y+48,65,24,255,255,255);//最大
	suu_bmf(X+275,Y+60,2,(shop[P].koubou_n+48)/6,0);
	mes(X+280,Y+50,":",color.siro,color.kuro,0);
	suu_bmf(X+295,Y+60,2,(shop[P].koubou_n+48)%6,0);
	suu_bmf(X+310,Y+60,2,0,0);
	SetDrawBright(255,255,255);
	waku_c(X+34,Y+48,4+shop[P].zangyou*3,24,255,255,255);//最大
	waku_c(X+36,Y+52,shop[P].koubou_t*3,16,50,255,50);//現在
	waku_c(X+36+shop[P].koubou_n*3-2,Y+50,5,20,255,50,50);//予定
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
	//表示//
	H=0;

	if(wind.ts_hyouji == 0){
		for(i=0;i<WEP_M;i++){
			WN = wind.efold_s[i];
			if(WN == -1)break;//工房はフォルダ表示スキップ有
			waku(6+X,78+Y-wind.scr[5]+H,40,30,6);
			waku(36+X,78+Y-wind.scr[5]+H,290,wind.efold_h[WN],6);
			//武器同じorフォルダつかみで緑表示
			if( (WN == Inp.d_no && Inp.d_type <=3) || (Inp.d_no-1000 == i && Inp.d_type == 6)){
				waku_c( 8+X,80+Y-wind.scr[5]+H,40,26,100,255,100);
				waku_c(38+X,80+Y-wind.scr[5]+H,286,wind.efold_h[WN]-4,100,255,100);
			}
			wep_icon(22+X,94+Y-wind.scr[5]+H,1,WN);//タブのアイコン
			if(draw.kai_t[WN] > 0){
				draw.kai_t[WN] --;
				SetDrawBright(255,100,100);	
				mes_bmf2(22+X,94+Y-wind.scr[5]+H + draw.kai_t[WN] / 5 ,"up",2);
				SetDrawBright(255,255,255);	
			}
			if(shop[P].wep_cre[WN] != 2){//開発率も表示
				waku_c(160+X,92+Y-wind.scr[5]+H,154,20,170,170,255);
				//開発率
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
			//担当0のフォルダ
			if(wind.efold_cnt[WN]<=0){//数が0なら閉じるボタンを付ける
				DrawRotaGraph(310+X,90+Y-wind.scr[5]+H,1,0,gra.ico[57],TRUE,0);
			}
			//人物描画
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
			//フォルダ位置補正
			H +=wind.efold_h[WN]+4;
		}
	}else{//待遇変更
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
			//人物描画
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
			//フォルダ位置補正
			H +=wind.tfold_h[i][1]+4;
		}
	}
	wind.scrm[5] = H + 76;

	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;
}
int DRA::win_7b(/*会社情報*/int X,int Y){

	SetDrawArea(X+4,Y+4,X+wind.sx[6]-20,Y+wind.sy[6]-34);


	int XP,YP=Y+6-wind.scr[6],i;
	int ICO,LV = 0;
	std::string NAME,TANI;

	//+shop.cnt *27

	//基本枠
	for(i=0;i<17;i++){
		if(i==0)XP=6;
		else if(i==8 || i==12) XP = 12; 
		else XP = 20;
		switch(i){
			case 0 :XP = 6;ICO=11;NAME = shop[P].name;break;
			case 1 :XP =20;ICO=53;NAME = "資金";TANI="Ｇ";break;
			case 2 :XP =20;ICO=9;NAME  = "平均LV";TANI="";break;
			case 3 :XP =20;ICO=47;NAME = "ブラック度";TANI="％";break;
			case 4 :XP =20;ICO=78;NAME = "知名度";TANI = "％";break;
			case 5 :XP =20;ICO=62;NAME = "農具納品";TANI="個";break;
			case 6 :XP =20;ICO=51;NAME = "休日";TANI="日";break;
			case 7 :XP =12;ICO=7;NAME  = "技術レベル";TANI = "";break;
			case 8 :XP =20;ICO=1;NAME  = "研磨";break;
			case 9 :XP =20;ICO=2;NAME  = "錬鉄";break;
			case 10:XP =20;ICO=3;NAME  = "細工";break;
			case 11:XP =12;ICO=42;NAME = "株式";break;
			case 12:XP =20;ICO=-1;NAME = "自社株" ;TANI="Ｇ";break;
			case 13:XP =20;ICO=-1;NAME = "協会株" ;TANI="Ｇ";break;
			case 14:XP =20;ICO=-1;NAME = "鉱山株" ;TANI="Ｇ";break;
			case 15:XP =20;ICO=-1;NAME = "発明株" ;TANI="Ｇ";break;
			case 16:XP =20;ICO=-1;NAME = "新聞株" ;TANI="Ｇ";break;
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
		if(ICO>=0)DrawRotaGraph(X+XP+14,YP+13,1,0,gra.ico[ICO],TRUE,0);//資金

		int GL = 0;
		if(i >= 8 && i<=10){//ゲージ表示
			GL = shop[P].create_exp[i-8]*7/(shop[P].create_lv[i-8]+7) / WEP_EXP_RATE2;
			waku_c( X+125,YP+2,144,21,255,150,150);
			GL = GL * 140/144;
			waku_c( X+127,YP+4,GL,17,255,50,50);
			mes_bmf(X+77 ,YP+12,"LV",1);
			suu_bmf(X+111,YP+12,2,shop[P].create_lv[i-8],0);
		}
		if(i >=12){//株数表示
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
	//ブラック度
	YP = Y-wind.scr[6]-6;
	if(shop[P].money<0)	SetDrawBright(255,150,150);//資金
	suu_bmf(X+240,YP+27*2,2,abs(int(shop[P].money)),0);
	SetDrawBright(255,255,255);

	syou_bmf(X+240,YP+27*3,int(shop[P].lv_ave*10),0);//レベル
	syou_bmf(X+240,YP+27*4,int(shop[P].b_w*10),0);//ブラック度
	syou_bmf(X+240,YP+27*5,int(shop[P].timeido),0);//知名度
	suu_bmf(X+180,YP+27*6,2,shop[P].wep_rest[NOU_NO],0);//農具在庫/要求数
	suu_bmf(X+240,YP+27*6,1,shop[P].nougu_req,0);
	mes(X+195,YP+27*6-8,"/",color.kuro,color.siro,2);
	
	int YB = 4;

	switch(shop[P].teikyuu){
		case -1:mes(X+130,YP+27*7-10,"定休無し",color.kuro,color.siro,2);YB=0;break;
		case 0:mes(X+140,YP+27*7-10,"月曜日",color.kuro,color.siro,2);break;
		case 1:mes(X+140,YP+27*7-10,"火曜日",color.kuro,color.siro,2);break;
		case 2:mes(X+140,YP+27*7-10,"水曜日",color.kuro,color.siro,2);break;
		case 3:mes(X+140,YP+27*7-10,"木曜日",color.kuro,color.siro,2);break;
		case 4:mes(X+140,YP+27*7-10,"金曜日",color.kuro,color.siro,2);break;
		case 5:mes(X+140,YP+27*7-10,"土曜日",color.kuro,color.siro,2);break;
		case 6:mes(X+140,YP+27*7-10,"日曜日",color.kuro,color.siro,2);break;
	}
	suu_bmf(X+240,YP+27*7,2,shop[P].yasumi_max-YB,0);//最大休み

	mes_bmf(X+200,YP+27*7-2,"+",1);

	//会社制度一覧
	win_7_seido(X,Y-wind.scr[6]+465);

	SetDrawArea(0,0,data.window_x,data.window_y);
	return 1;

}
int DRA::win_8b(/*ログ*/int X,int Y){

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

	//最上部にソート用タブ
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
			case 0: IC = 4;break;//全部
			case 1: IC = shop[SM[0]].icon;break;//自店のみ
			case 2: IC = shop[SM[1]].icon;break;//他店Ａ
			case 3: IC = shop[SM[2]].icon;break;//他店Ｂ
			case 4: IC = shop[SM[3]].icon;break;//他店Ｃ
			case 5: IC = shop[SM[4]].icon;break;//他店Ｄ
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

		//モードのよってスキップ決定
		if(logu.mode != 0 && logu.log[I].shop != SM[logu.mode-1]){
			continue;
		}

		//日付表示
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
int DRA::win_9b(/*収支情報*/int X,int Y){

	int i,HY,HX,HS,IC;
	char str[2][10];

	wind.smax[8] = 540;
	//表示選択ボタン
	SetDrawArea(X+4,Y+4,X+wind.sx[8]-20,Y+wind.sy[8]-34);
	for(i=0;i<3;i++){
		if(i != wind.syu_set)		waku(X+6+i*36,Y+6,32,32,8);
		else						waku(X+6+i*36,Y+6,32,32,9);
	}

	mes(X+10 +(wind.syu_set+3)%4/3,Y+8+(wind.syu_set+3)%4/3,"年",color.siro,color.kuro,1);
	mes(X+46 +(wind.syu_set+2)%4/3,Y+8+(wind.syu_set+2)%4/3,"月",color.siro,color.kuro,1);
	mes(X+82 +(wind.syu_set+1)%4/3,Y+8+(wind.syu_set+1)%4/3,"日",color.siro,color.kuro,1);

	if(wind.syu_set !=2){
		waku(X+212,Y+6,60,32,8+wind.syousai_hyouji);
		mes(X+215+wind.syousai_hyouji,Y+8+wind.syousai_hyouji,"詳細",color.siro,color.kuro,1);
	}

	//年月日選択
	waku(X+8,Y+45,270,40,6);
	mes(X+80,Y+55,"年",color.kuro,color.siro,0);
	suu_bmf(X+65,Y+65,2,wind.syu_year+200,0);
	DrawRotaGraph(X+50,79+Y,1,PI/2,gra.ico[59],TRUE,0);
	DrawRotaGraph(X+50,49+Y,1,-PI/2,gra.ico[59],TRUE,0);
	if(wind.syu_set>0){
		DrawRotaGraph(X+115,79+Y,1,PI/2,gra.ico[59],TRUE,0);
		DrawRotaGraph(X+115,49+Y,1,-PI/2,gra.ico[59],TRUE,0);
		mes(X+140,Y+55,"月",color.kuro,color.siro,0);
		suu_bmf(X+125,Y+65,2,wind.syu_mon+1,0);
	}
	if(wind.syu_set>1){
		DrawRotaGraph(X+175,79+Y,1,PI/2,gra.ico[59],TRUE,0);
		DrawRotaGraph(X+175,49+Y,1,-PI/2,gra.ico[59],TRUE,0);
		mes(X+190,Y+55,"日",color.kuro,color.siro,0);
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
	//今月状況
	for(i=0;i<4;i++){//シェア表示
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
			case  0:strcpy_s(str[0],"売数")		;strcpy_s(str[1],"個");IC = 5 ;N= wind.syu_hyouji[0];break;
			case  1:strcpy_s(str[0],"総売上")	;strcpy_s(str[1],"Ｇ");IC = 32;N= wind.syu_hyouji[1];break;
			case  2:							;strcpy_s(str[1],"Ｇ");IC = -1;N= wind.shear_s[P][0];break;
			case  3:							;strcpy_s(str[1],"Ｇ");IC = -1;N= wind.shear_s[P][1];break;
			case  4:							;strcpy_s(str[1],"Ｇ");IC = -1;N= wind.shear_s[P][2];break;
			case  5:							;strcpy_s(str[1],"Ｇ");IC = -1;N= wind.shear_s[P][3];break;
			case  6:strcpy_s(str[0],"客数")		;strcpy_s(str[1],"人");IC = 5 ;N= wind.syu_hyouji[2];break;
			case  7:strcpy_s(str[0],"製造数")	;strcpy_s(str[1],"個");IC = 45;N= wind.syu_hyouji[3];break;
			case  8:strcpy_s(str[0],"製造費")	;strcpy_s(str[1],"Ｇ");IC = 33;N= wind.syu_hyouji[4];break;
			case  9:strcpy_s(str[0],"人件費")	;strcpy_s(str[1],"Ｇ");IC = 33;N= wind.syu_hyouji[5];break;
			case 10:strcpy_s(str[0],"経営費")	;strcpy_s(str[1],"Ｇ");IC = 33;N= wind.syu_hyouji[6];break;
			case 11:strcpy_s(str[0],"税,利子等");strcpy_s(str[1],"Ｇ");IC = 53;N= wind.syu_hyouji[7];break;
			case 12:strcpy_s(str[0],"利益")		;strcpy_s(str[1],"Ｇ");IC = 53;N= wind.syu_hyouji[8];break;
			case 13:strcpy_s(str[0],"株価")		;strcpy_s(str[1],"Ｇ");IC = 53;N= wind.syu_hyouji[11];break;
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
int DRA::win_10b(/*経営戦略ウィンドウ*/int X,int Y){

	double N_MP = shop[P].n_mp;
	int U_MP = shop[P].use_mana;
	int S_MP = 0;		
	if( shop[P].use_mana > 0) S_MP = shop[P].syou_mp[U_MP] * shop[P].mana_b[mana[U_MP].type] / 100;
	N_MP -= S_MP;
	wind.smini[9]=76+38;

	SetDrawArea(X+4,Y+4,X+wind.sx[9]-20,Y+80);

	int SH = 0,IC = 0;

	for(int i=0;i<7;i++){//情報表示タブ

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
			case 6:IC = 49;break;//未修得表示
		}
		if(i<6)			DrawRotaGraph(X+22+36*i+SH,Y+24+SH,1+SH,0,gra.ico[IC],TRUE,0);
		else			DrawRotaGraph(X+38+36*i+SH,Y+24+SH,1+SH,0,gra.ico[IC],TRUE,0);
	}

	Y+=38;

	waku(X+6,Y+6,280,36,6);

	waku_c(X+57,Y+7,int(shop[P].n_mp),34,150,150,255);//消費前値
	waku_c(X+57,Y+7,int(S_MP)		 ,34,255,150,150);//消費後値

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
			//タグ表示
			XP=6;
			if(MRR==0){
				YP+=50;
				MRR = 1;
			}
			switch(MR){
				case 0:name = "経営";break;
				case 1:name = "財務";break;
				case 2:name = "工事";break;
				case 3:name = "開発";break;
				case 4:name = "宣伝";break;
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
	//全体枠表示
	SetDrawArea(X+4,Y+4,X+wind.sx[10]-20,Y+wind.sy[10]-34);

	Y -= wind.scr[10];

	mes_bmf(X+20,Y-20,"Mode Info",2);

	//モード名
	waku_c(X+16,Y+20,370,30,255,255,255);
	mes(X+30,Y+26,"モード:",color.kuro,color.siro,0);
	mes(X+110,Y+26,data.mode_n[data.mode+1].c_str(),color.kuro,color.siro,0);

	//難易度
	waku_c(X+16,Y+60,370,30,255,255,255);
	mes(X+30,Y+66,"難易度:",color.kuro,color.siro,0);
	mes(X+110,Y+66,data.nanndo_n[data.nando+1].c_str(),color.kuro,color.siro,0);
	//勝利条件
	waku_c(X+16,Y+100,370,60,255,255,255);

	switch(data.mode){
		case 0:
			mes_str(X+30,Y+110,"会社を大きくしよう！--",color.kuro,color.siro,0);
		break;
		case 1:
			mes_str(X+30,Y+110,"いずれかの勝利条件を目指そう！--",color.kuro,color.siro,0);
		break;
	}
	//●勝利条件ゲージ(最大３つ)

	//○総来客酢数

	std::string str;
	double NB;//目標値
	double NP;//割合
	int YP=30;

	waku_c(X+16,Y+170,90,30,255,255,255);
	mes(X+21,Y+178,"勝利条件",color.kuro,color.siro,0);


	double na[5] ={0,0,0,0,0};

	for(int i=0;i<12;i++){
		int yp = 0;

		switch(i){		
			case 0:
				str = "総来客数";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_cust;
				NB = data.goal_cust;
			break;
			case 1:
				str = "時価総額";//○時価総額
				for(int s= 0;s<5;s++) na[s] = shop[s].g_kabu;
				NB = data.goal_kabu;
			break;
			case 2:
				str = "総販売額";//○総販売数
				for(int s= 0;s<5;s++) na[s] = shop[s].g_sell_t;
				NB = data.goal_sell_t;
			break;
			case 3:
				str = "剣販売額";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_sell[0];
				NB = data.goal_sell[0];
			break;
			case 4:
				str = "槍販売額";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_sell[1];
				NB = data.goal_sell[1];
			break;
			case 5:
				str = "斧販売額";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_sell[2];
				NB = data.goal_sell[2];
			break;
			case 6:
				str = "弓販売額";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_sell[3];
				NB = data.goal_sell[3];
			break;
			case 7:
				str = "鶴嘴製造";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_turu;
				NB = data.goal_turu;
			break;
			case 8:
				str = "開発数";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_wepcre;
				NB = data.goal_wepcre;
			break;
			case 9:
				str = "資金";
				for(int s= 0;s<5;s++) na[s] = shop[s].money;
				NB = data.goal_money;
			break;
			case 10:
				str = "大会上位";
				for(int s= 0;s<5;s++) na[s] = shop[s].g_taikai;
				NB = data.goal_taikai;
			break;
			case 11:
				str = "ボス討伐";
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

			if(s == P){//時点数字
				suu_bmf(X+200 ,Y+230+YP,1,int(na[s]),0);
				mes(X+210	  ,Y+220+YP,"/",color.kuro,color.siro,2);
				suu_bmf(X+300 ,Y+230+YP,1,int(NB),0);

				syou_bmf(X+360,Y+227+YP,int(NP),0);
				mes(X+370,Y+220+YP,"%",color.kuro,color.siro,2);			
			}

			//ゲージ＆順位
			waku_c(X+90,Y+172+YP+yp,296*int(NP)/1000,8,
				col[0],
				col[1],
				col[2]);

			DrawRotaGraph(X+90+int(296*NP/1000),Y+172+YP+yp,1,0,gra.ico[shop[s].icon],false);

			yp+=9;
		}

		YP+=70;
	}

	//条件数、ゲージ、現在値
	
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

	//背景暗くする
	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 200) ;
	DrawBox(0,0,data.window_x,data.window_y,GetColor(0,0,0),1);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

	waku( X , Y-50 ,600,50,3);
	waku( X , Y ,600,530,3);

	waku(X+500,8+Y,75,25,6);
	waku(X+15,10+Y,480,25,6);
	mes(X+40 ,12+Y,"項目名",color.kuro,color.siro,0);

	waku(X+85,Y-40,30,30,6);
	waku(X+485,Y-40,30,30,6);

	DrawRotaGraph(X+100,Y-25,1, 0,gra.ico[58],TRUE,0);
	DrawRotaGraph(X+500,Y-25,1, 0,gra.ico[59],TRUE,0);
	waku(X+555,Y-40,30,30,6);
	DrawRotaGraph(X+570,Y-25,2,0,gra.ico[57],TRUE,0);//閉じる

	if(wind.syu_set == 1){//月表示
		mes(X+220,Y-35,"年　　月　収支報告",color.kuro,color.siro,0);
		suu_bmf(X+210,Y-24,2,wind.syu_year+200,0);
		suu_bmf(X+260,Y-24,2,wind.syu_mon%12+1,0);
		mes(X+510,10+Y,"前月比",color.kuro,color.siro,0);
		if(wind.syu_mon>0 || wind.syu_year>0){//最初の月は計算しない
			fun.sell_data_cul(1);//前月or前年計算
		}
		fun.sell_data_cul(2);
	}else{//年表示
		mes(X+220,Y-35,"年　　　　収支報告",color.kuro,color.siro,0);	
		suu_bmf(X+210,Y-24,2,wind.syu_year+200,0);
		mes(X+510,10+Y,"前年比",color.kuro,color.siro,0);
		if(wind.syu_year>0){//最初の年は計算しない
			fun.sell_data_cul(1);//前月or前年計算
		}
		fun.sell_data_cul(2);
	}

	for(i=0;i<4;i++){//シェア表示
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
			case  0:strcpy_s(str[0],"販売数")	;strcpy_s(str[1],"個");IC = 5 ;N= wind.syu_hyouji[0];NP = wind.syu_pars[0];break;
			case  1:strcpy_s(str[0],"総売上")	;strcpy_s(str[1],"Ｇ");IC = 32;N= wind.syu_hyouji[1];NP = wind.syu_pars[1];break;
			case  2:							;strcpy_s(str[1],"Ｇ");IC = -1;N= wind.shear_s[P][0];NP = wind.syu_pars[12];break;
			case  3:							;strcpy_s(str[1],"Ｇ");IC = -1;N= wind.shear_s[P][1];NP = wind.syu_pars[13];break;
			case  4:							;strcpy_s(str[1],"Ｇ");IC = -1;N= wind.shear_s[P][2];NP = wind.syu_pars[14];break;
			case  5:							;strcpy_s(str[1],"Ｇ");IC = -1;N= wind.shear_s[P][3];NP = wind.syu_pars[15];break;
			case  6:strcpy_s(str[0],"来客数")	;strcpy_s(str[1],"人");IC = 5 ;N= wind.syu_hyouji[2];NP = wind.syu_pars[2];break;
			case  7:strcpy_s(str[0],"製造数")	;strcpy_s(str[1],"個");IC = 45;N= wind.syu_hyouji[3];NP = wind.syu_pars[3];break;
			case  8:strcpy_s(str[0],"製造費")	;strcpy_s(str[1],"Ｇ");IC = 33;N= wind.syu_hyouji[4];NP = wind.syu_pars[4];break;
			case  9:strcpy_s(str[0],"人件費")	;strcpy_s(str[1],"Ｇ");IC = 33;N= wind.syu_hyouji[5];NP = wind.syu_pars[5];break;
			case 10:strcpy_s(str[0],"経営費")	;strcpy_s(str[1],"Ｇ");IC = 33;N= wind.syu_hyouji[6];NP = wind.syu_pars[6];break;
			case 11:strcpy_s(str[0],"税＆利子") ;strcpy_s(str[1],"Ｇ");IC = 53;N= wind.syu_hyouji[7];NP = wind.syu_pars[7];break;
			case 12:strcpy_s(str[0],"利益")		;strcpy_s(str[1],"Ｇ");IC = 53;N= wind.syu_hyouji[8];NP = wind.syu_pars[8];break;
			case 13:strcpy_s(str[0],"総資金")	;strcpy_s(str[1],"Ｇ");IC = 53;N= wind.syu_hyouji[9];NP = wind.syu_pars[9];break;
			case 14:strcpy_s(str[0],"株価")		;strcpy_s(str[1],"Ｇ");IC = 53;N= wind.syu_hyouji[11];NP = wind.syu_pars[11];break;
			case 15:strcpy_s(str[0],"人口")		;strcpy_s(str[1],"人");IC = 53;N= wind.syu_hyouji[10];NP = wind.syu_pars[10];break;
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
				if(N>0)	mes(X+510,HY,"黒字化",color.kuro,color.siro,0);
				else	mes(X+510,HY,"赤字化",color.aka,color.siro,0);
			}else{
				mes(X+510,HY,"―――",color.kuro,color.siro,0);
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

	//背景暗くする
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
	DrawRotaGraph(X+570,Y-25,2,0,gra.ico[57],TRUE,0);//閉じる

	if(wind.syu_set == 1){//月表示
		mes(X+220,Y-35,"年　　月",color.kuro,color.siro,0);
		suu_bmf(X+210,Y-24,2,wind.syu_year+200,0);
		suu_bmf(X+260,Y-24,2,wind.syu_mon%12+1,0);
	}else{//年表示
		mes(X+220,Y-35,"年",color.kuro,color.siro,0);	
		suu_bmf(X+210,Y-24,2,wind.syu_year+200,0);
	}

	switch(wind.graph_hyouuji){
		case  0+19:strcpy_s(str," 販売数")	;IC=5	;break;
		case  1+19:strcpy_s(str," 総売上")	;IC=32	;break;
		case  2+19:strcpy_s(str," 剣売上")	;IC=0	;break;
		case  3+19:strcpy_s(str," 槍売上")	;IC=1	;break;
		case  4+19:strcpy_s(str," 斧売上")	;IC=2	;break;
		case  5+19:strcpy_s(str," 弓売上")	;IC=3	;break;
		case  6+19:strcpy_s(str," 来客数")	;IC=5	;break;
		case  7+19:strcpy_s(str," 製造数")	;IC=45	;break;
		case  8+19:strcpy_s(str," 製造費")	;IC=33	;break;
		case  9+19:strcpy_s(str," 人件費")	;IC=33	;break;
		case 10+19:strcpy_s(str," 経営費")	;IC=33	;break;
		case 11+19:strcpy_s(str,"税＆利子");IC=53	;break;
		case 12+19:strcpy_s(str,"　利益")	;IC=53	;break;
		case 13+19:strcpy_s(str," 総資金");IC=53	;break;
		case 14+19:strcpy_s(str,"　株価")	;IC=53	;break;
		case 15+19:strcpy_s(str,"　人口")	;IC=53	;break;
	}

	DrawRotaGraph(X+320,Y-25,2,0,gra.ico[IC],TRUE,0);
	mes(X+340,Y-35,str,color.kuro,color.siro,0);

	//最大値を計算
	int MAX=10,MIN=0,MAX_M= min(data.day/28+1,120);//最大値と最大月
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
	L= MAX/10;//ラインは基本10本
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

	DrawBox(X+25,Y+25,X+575,Y+505,color.siro,1);//全体
	DrawLine(X+25,int(YP),X+575,int(YP),color.kuro,1);//0基準線
	DrawLine(X+100,Y+25,X+100,Y+505,color.kuro,1);
	suu_bmf(X+90,YP,1,0,0);
	//数値単位
	i = L;
	while(1){
		if(-MIN-i <= 0) break; 
		YP=Y+480-int(double(-MIN-i)*430/MAX);
		DrawLine(X+90,int(YP),X+575,int(YP),GetColor(150,150,255),1);//0基準線
		suu_bmf(X+75,YP,1,i,0);
		i += L;
	}
	i = L;
	while(1){
		if(-MIN+i >= MAX) break; 
		YP=Y+480-int(double(-MIN+i)*430/MAX);
		DrawLine(X+90,int(YP),X+575,int(YP),GetColor(150,150,255),1);//0基準線
		suu_bmf(X+75,YP,1,i,0);
		i += L;
	}

	//グラフ表示
	for(int S=0;S<SM;S++){
		XP = X+100;
		YP = Y+480-int(double(ST[0][S]-MIN)*430/MAX);
		for(i=1;i<MAX_M;i++){
			XP2 = X+100+int(double(i+1)*450/MAX_M);
			if(i%12 == 0){
				DrawLine(XP2,Y+481,XP2,Y+25,GetColor(100,100,200),1);//0基準線
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
		//人口
		mes(X+30,Y+530,"ハンター数",color.kuro,color.siro,0);
		DrawLine(X+130,Y+540,X+230,Y+540,shop[0].color,2);
		mes(X+250,Y+530,"死者数",color.kuro,color.siro,0);	
		DrawLine(X+325,Y+540,X+425,Y+540,shop[1].color,2);
		return 1;
	}
	//表示色対応
	for(int S=0;S<SM;S++){
		DrawRotaGraph(X+30+S*100,Y+540,2,0,gra.ico[shop[S].icon],TRUE,0);
		DrawLine(X+50+S*100,Y+540,X+100+S*100,Y+540,shop[S].color,2);
	}


	return 1;
}
int DRA::win_2s(int N,int X,int Y/*武器アイコン子*/){

	int MP;//製造,開発進行率
	int col;
	int PL,PS;
	int KAI = 0;//開発中or製造中
	if(shop[P].wep_cre[N] != 2) KAI = 1;

	//武器表示
	if(N == Inp.d_no && Inp.d_type < 4)							waku_c(X,Y,32,32,100,255,100);//武器つかみ中
	else if(Inp.d_type == 6 && emp[Inp.d_no].shift_n == N) 	waku_c(X,Y,32,32,150,255,150);//シフト同じ
	else 	waku_c(X,Y,32,32,255,255,255);

	//製造速度枠
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

	//製造進行率a１
	DrawLine(			X				,Y				,X+min(MP,32),Y,col,2);
	if(MP>32)DrawLine(	X+32			,Y				,X+32,Y+min(MP-32,32),col,2);
	if(MP>64)DrawLine(	X+max(96-MP,0)	,Y+32			,X+32,Y+32,col,2);
	if(MP>96)DrawLine(	X				,Y+128-MP,X,Y+32,col,2);

	draw.wep_icon(16+X,16+Y,1,N);

	if(KAI == 0){//製造中
		if(draw.sell_t[N] > 0){
			SetDrawBright(255,255-draw.sell_t[N]*20,255-draw.sell_t[N]*20);	
			draw.sell_t[N] -= opt.speed;
			if(draw.sell_t[N] < 0) draw.sell_t[N] = 0;
		}
		mes_bmf(X+4,Y+30,"X",1);
		suu_bmf(X+30,Y+30,1,shop[P].wep_rest[N],0);
		SetDrawBright(255,255,255);
	}else{//開発中
		DrawRotaGraph(X+24,Y+8,1,0,gra.ico[7],0);

	}

	//ステータス表示
	switch(wind.wep_sort){
		case 0://攻撃力
			PL = int(wep[N].atk*shop[P].atk_j[N]);
			PS = 2;
		break;
		case 1://耐久
			PL = int(wep[N].dur*shop[P].dur_j[N]);
			PS = 2;
		break;
		case 2://人気合計
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
		case 3://工数
			PS = 2;
			PL = int(wep[N].make_time *10 * shop[P].time_j[N] / 100);
		break;
		case 4://値段
			PS = 2;
			PL = int(wep[N].price * shop[P].price_rate / 100);
		break;
		case 5://儲け
			PS = 2;
			PL = int(wep[N].price * (shop[P].price_rate - wep[N].seizou_cost * shop[P].cost_j[N] ) / 100);
		break;
		default://非表示
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
int DRA::win_5s(int N,int X,int Y/*人事アイコン子*/){

	int HP,MAN;

	if(Inp.d_type >= 5 && Inp.d_type <= 6 && Inp.d_no == N)	waku_c( X,   Y,32,32,100,255,100);//選択中
	else if(emp[N].shift != emp[N].shift_n)				waku_c( X,   Y,32,32,100,100,255);//シフト変更
	else													waku_c( X,   Y,32,32,255,200,200);//選択中or武器同じ

	DrawRotaGraph(16+X,16+Y,2,0,gra.unit[emp[N].gra][1],TRUE,0);//キャラ画像

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

	DrawRotaGraph(22+X, 2+Y,1,0,gra.emo[IC],TRUE,0);//体調噴出し
	SetDrawBright(255,255,255);

	if(emp[N].rest>1){//長期療養
		suu_bmf(22+X,Y+4,1,emp[N].rest,2);//休み日数
	}

	//残り体力
	HP = int(emp[N].hp)*32/100;//0~100

	//体力表示
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
		case 4://給料
		suu_bmf(X+18,Y+26,2,emp[N].pay_money/10,2,5);
		suu_bmf(X+28,Y+28,1,emp[N].pay_money%10,2,5);
		break;
		case 5://忠誠
			
		if		(int(emp[N].b_w)>=100)	{SetDrawBright( 255 , 255 , 255 ) ;mes_bmf(X+24,Y+24,"W",2);}
		else  if(int(emp[N].b_w)>= 80)	{SetDrawBright( 220 , 220 , 220 ) ;mes_bmf(X+24,Y+24,"W",2);}
		else  if(int(emp[N].b_w)>= 60)	{SetDrawBright( 190 , 190 , 190 ) ;mes_bmf(X+24,Y+24,"G",2);}
		else  if(int(emp[N].b_w)>= 40)	{SetDrawBright( 160 , 160 , 160 ) ;mes_bmf(X+24,Y+24,"G",2);}
		else  if(int(emp[N].b_w)>= 20)	{SetDrawBright( 120 , 120 , 120 ) ;mes_bmf(X+24,Y+24,"B",2);}
		else								{SetDrawBright( 0 , 0 , 0 )	  ;mes_bmf(X+24,Y+24,"B",2);}
		SetDrawBright( 255 , 255 , 255 ) ;
		break;
		case 6://満足
		MAN = emp[N].manzoku_cul();
		//給料満足
		if(MAN<-20)			{SetDrawBright( 100 , 100 , 255 ) ;mes_bmf(X+24,Y+24,"S",2);}
		else  if(MAN<0)		{SetDrawBright( 200 , 200 , 255 ) ;mes_bmf(X+24,Y+24,"A",2);}
		else  if(MAN<50)									   mes_bmf(X+24,Y+24,"B",2);
		else  if(MAN<100)	{SetDrawBright( 255 , 200 , 200 ) ;mes_bmf(X+24,Y+24,"C",2);}
		else  if(MAN<200)	{SetDrawBright( 255 , 100 , 100 ) ;mes_bmf(X+24,Y+24,"D",2);}
		else				{SetDrawBright( 255 , 0 , 0 )	  ;mes_bmf(X+24,Y+24,"F",2);}
		SetDrawBright( 255 , 255 , 255 ) ;
		break;
	}


	if(draw.lv_t[N] > 0){//レベル上昇
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

		if(M%60 == 0){//ラベル表示
			if(CNT>0)YP+=40;
			CNT = 0;
			switch(M/60){
				case 0:name = "経営";break;
				case 1:name = "財務";break;
				case 2:name = "工事";break;
				case 3:name = "開発";break;
				case 4:name = "宣伝";break;
			}
			XP=0;
			waku_c(X+12,Y+YP,260,25,150,250,150);
			mes(X+38,Y+YP+6,name.c_str(),color.kuro,color.siro,2);
			DrawRotaGraph(X+26,Y+YP+13,1,0,gra.ico[data.mana_icon[M/60]],TRUE,0);//資金
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
	//ヘルプウィンドウメイン

	if( wind.info_t <=0 || wind.info_no<0){
		win_hmes("");
		return 1;
	}

	switch(wind.info_t){
		case  1: win_1h();break;//客一覧
		case  2: win_2h();break;//商品一覧
		case  3: win_3h();break;//開発
		case  4: win_4h();break;//求人
		case  5: win_5h();break;//人事/店員
		case  6: win_6h();break;//人事/職人
		case  7: win_7h();break;//会社
		case  8: win_8h();break;//ログ
		case  9: win_9h();break;//収支・シェア
		case 10:win_10h();break;//戦術
		case 11:win_11h();break;//マップ
		case 12:win_12h();break;//そのほか
	}

	return 1;
}
int DRA::win_1h(){

	int X,Y,H;
	int i,ICO,N,G;
	std::string str;

	if(wind.info_no == HUN_M){//店内状況
		win_hmes("現在の客数/本日の客数/他店を含めた本日の客数@");
	}

	if(wind.info_no >=0 && wind.info_no < HUN_M){//客情報

		H = wind.info_no;
		if(hun[H].act == 4) return 1;

		win_hmes("",360,194);
		if(Inp.m_x<data.window_x-360) X = Inp.m_x;
		else						  X = Inp.m_x - 360;
		if(Inp.m_y<data.window_y-183) Y = Inp.m_y;
		else						  Y = Inp.m_y - 183;
		//客アイコン、レベル、武器種、ステータス、資金、所持武器数

		DrawRotaGraph(X+20,Y+50,2,0,gra.unit[jobs[hun[H].job].gra][1],1,0);
		DrawRotaGraph(X+50,Y+50,2,0,gra.emo[16+hun[H].wep_t],1,0);
		suu_bmf(X+60,Y+60,2,hun[H].lv,2,6);
		//交渉バー
		waku(X+80,Y+38,265,28,6);
		int iro[3];
		char jyoutai[10];

		switch(hun[H].act){
			case 1://待機
				iro[0] = 0;iro[1] = 255;iro[2] = 0;
				sprintf_s(jyoutai,10,"waiting");
			break;
			case 2://接客中
				iro[0] = 0;iro[1] = 0;iro[2] = 255;
				sprintf_s(jyoutai,10,"shopping");
			break;
			case 3://クレーマー
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
				case 0:str = "体力"		;ICO = 44;N=hun[H].sta[0]	  ;G=N/4   ;break;
				case 1:str = "攻撃"		;ICO = 38;N=hun[H].sta[1]	  ;G=N*3	 ;break;
				case 2:str = "防御"		;ICO = 39;N=hun[H].sta[2]     ;G=N*3	 ;break;
				case 3:str = "敏捷"		;ICO = 54;N=hun[H].sta[3]	  ;G=N*3	 ;break;
				case 4:str = "予算"		;ICO = 53;N=hun[H].cul_yosan();G=N/1000;break;
			}
			if(G>160)   G = 160;
			if(N>99999) N = 99999;

			waku(X+10,70+Y+i*22  ,60,20,6);
			waku(X+75,70+Y+i*22  ,105,20,6);
			mes(35+X,73+Y+i*22,str.c_str(),color.kuro,color.siro,2);
			DrawRotaGraph(20+X,80+Y+i*22,1,0,gra.ico[ICO],TRUE,0);

			if( i == 0){//体力
				waku_c(X+185,70+Y+i*22 ,G,20,255,100,100);
				waku_c(X+185,70+Y+i*22 ,hun[H].hp/4,20,255,150,0);
			}else{//それ以外
				waku_c(X+185,71+Y+i*22 ,G,20,255,150+i%2*105,0);
			}
			suu_bmf(170+X,81+Y+i*22,2,N,0);
		}
	}

	return 1;
}
int DRA::win_2h(){
	if(wind.info_no<1000){//武器
		wep_info(wind.info_no);
	}else {//タブ,ソートボタン
		switch(wind.info_no){
			case 1000:
				win_hmes("目玉商品@ここに入れた武器は２割引で販売し集客＋２０％@さらに目玉商品効果を発揮します@");
			break;
			case 1001:
				win_hmes("新しく開発された武器はこのリストに入ります@");
			break;
			case 1002:
				win_hmes("剣系@");
			break;
			case 1003:
				win_hmes("槍系@");
			break;
			case 1004:
				win_hmes("斧系@");
			break;
			case 1005:
				win_hmes("弓系@");
			break;
			case 1006:
				win_hmes("もう作らない武器はここへ、削除はされません@");
			break;
			case 2000:
				win_hmes("攻撃力を表示@ダブルクリックでソート@");
			break;
			case 2001:
				win_hmes("耐久力を表示@ダブルクリックでソート@");
			break;
			case 2002:
				win_hmes("集客力を表示@ダブルクリックでソート@");
			break;
			case 2003:
				win_hmes("製造時間を表示@ダブルクリックでソート@");
			break;
			case 2004:
				win_hmes("売価を表示@ダブルクリックでソート@");
			break;
			case 2005:
				win_hmes("粗利を表示@ダブルクリックでソート@");
			break;
			case 2006:
				win_hmes("商品構成比率と、倉庫の状態@");
			break;
		}
	}

	return 1;
}
int DRA::win_3h(){

	return 1;
	if(wind.info_no<1000){//開発武器
		wep_info(wind.info_no);
	}
	return 1;
}
int DRA::win_4h(){

	if(wind.info_no<1000){//求人番号
		emp_info(wind.info_no);
	}else{
		switch(wind.info_no - 1000){
			case 0:
				win_hmes("店員の求職者一覧@");
			break;
			case 1:
				win_hmes("職人の求職者一覧@");
			break;
			case 2:
				win_hmes("レベルを表示@ダブルクリックでソート@");
			break;
			case 3:
				win_hmes("ＨＰを表示@ダブルクリックでソート@");
			break;
			case 4:
				win_hmes("客捌、製造力を表示@ダブルクリックでソート@");
			break;
			case 5:
				win_hmes("接客、開発力を表示@ダブルクリックでソート@");
			break;
			case 6:
				win_hmes("スキルを表示@ダブルクリックでソート@");
			break;
			case 7:
				win_hmes("根性を表示@ダブルクリックでソート@");
			break;
			case 8:
				win_hmes("要求賃金を表示@ダブルクリックでソート@");
			break;
		}
	}

	return 1;
}
int DRA::win_5h(){

	if(wind.info_no<1000){//店員
		emp_info(wind.info_no);
	}else{//タブ
		switch(wind.info_no){
			case 1400:
				win_hmes("シフト・剣売り場@");
			break;
			case 1401:
				win_hmes("シフト・槍売り場@");
			break;
			case 1402:
				win_hmes("シフト・斧売り場@");
			break;
			case 1403:
				win_hmes("シフト・弓売り場@");
			break;
			case 2000:
				win_hmes("現在ＨＰ表示@");
			break;
			case 2001:
				win_hmes("レベル表示@");
			break;
			case 2002:
				win_hmes("交渉力表示@");
			break;
			case 2003:
				win_hmes("接客力表示@");
			break;
			case 2004:
				win_hmes("月給表示@");
			break;
			case 2005:
				win_hmes("社会人度表示@");
			break;
			case 2006:
				win_hmes("満足度表示@");
			break;
			case 2007:
			case 2008:
				if(data.taiguu_ok == 1)win_hmes("昇給⇔シフト表示切り替え@");
			break;
			case 2009:
				win_hmes("営業時間は変更出来ません@");
			break;
			case 2010:
				win_hmes("給料そのまま@");
			break;
			case 2011:
				win_hmes("昇給したい従業員はこのフォルダへ@月給を１０％(月給３０万以下の場合３万)上げ、愛社に傾けます@");
			break;
			case 2012:
				win_hmes("減給したい従業員はこのフォルダへ@月給を１０％下げ、社畜に傾けます@");
			break;
			case 2013:
				win_hmes("解雇したい従業員はこのフォルダへ@解雇した月は給料を二倍払わないといけません@");
			break;
		}
	}
	return 1;
}
int DRA::win_6h(){

	if(wind.info_no<1000){//職人
		emp_info(wind.info_no);
	}else if(wind.info_no<2000){//タブ
		wep_info(wind.efold_s[wind.info_no-1000]);
	}else{//ソートボタン等
		switch(wind.info_no){
			case 2000:
				win_hmes("現在ＨＰ表示@");
			break;
			case 2001:
				win_hmes("レベル表示@");
			break;
			case 2002:
				win_hmes("製造力表示@");
			break;
			case 2003:
				win_hmes("開発力表示@");
			break;
			case 2004:
				win_hmes("月給表示@");
			break;
			case 2005:
				win_hmes("社会人度表示@");
			break;
			case 2006:
				win_hmes("満足度表示@");
			break;
			case 2007:
			case 2008:
				if(data.taiguu_ok == 1)win_hmes("昇給⇔シフト表示切り替え@");
			break;
			case 2009:
				if(wind.ok[9] == 0)	win_hmes("工房稼動時間@変更出来ません@");
				else				win_hmes("工房稼動時間@数値横の△をクリックで変更@週の初めに反映されます@");
			break;
			case 2010:
				win_hmes("給料そのまま@");
			break;
			case 2011:
				win_hmes("昇給したい従業員はこのフォルダへ@月給を１０％(月給２０万以下の場合２万)上げ、愛社に傾けます@");
			break;
			case 2012:
				win_hmes("減給したい従業員はこのフォルダへ@月給を１０％下げ、社畜に傾けます@");
			break;
			case 2013:
				win_hmes("解雇したい従業員はこのフォルダへ@解雇した月は給料を二倍払わないといけません@");
			break;
		}
	}

	return 1;
}
int DRA::win_7h(){

	switch(wind.info_no){//会社情報
		case 0:
			win_hmes("社名@");//社名
		break;
		case 1:
			win_hmes("総資金@");//資金
		break;
		case 2:
			win_hmes("平均LV@");//従業員
		break;
		case 3:
			win_hmes("ブラック度@");//ブラック度
		break;
		case 4:
			win_hmes("知名度@");//農具納品
		break;
		case 5:
			win_hmes("農具納品数/現在数@");//農具納品
		break;
		case 6:
			win_hmes("休日数@定休日＆ローテーション休日数@");//定休日
		break;
		case 7:
			win_hmes("技術レベル@バーが満タンでLVUP@");//開発レベル
		break;
		case 8:
			win_hmes("研磨レベル@");
		break;
		case 9:
			win_hmes("錬鉄レベル@");
		break;
		case 10:
			win_hmes("細工レベル@");
		break;
		case 11:
			win_hmes("株保持率と株価@保持率につきボーナス、50%超でボーナス２倍@");
			break;
		case 12:
			win_hmes("自社株@株主ボーナス:ＭＰ回復+0.1/10%@");
			break;
		case 13:
			win_hmes("狩人協会株@株主ボーナス:新米ハンター好感度+5/10%@");
			break;
		case 14:
			win_hmes("鉱山開発株@株主ボーナス:製造コスト-1%/10%@");
			break;
		case 15:
			win_hmes("魔獣研究所株@株主ボーナス:改良経験+1%/10%@");
			break;
		case 16:
			win_hmes("新聞社株@株主ボーナス:宣伝効果+1%/10%@");
			break;
		break;
		case 2000:
			win_hmes("経営部門-制度@");
		break;
		case 2001:
			win_hmes("財務部門-制度@");
		break;
		case 2002:
			win_hmes("工事部門-制度@");
		break;
		case 2003:
			win_hmes("開発部門-制度@");
		break;
		case 2004:
			win_hmes("宣伝部門-制度@");
		break;
	}

	if(wind.info_no >= 1000 && wind.info_no < 2000)
	{
		seido_info(wind.info_no - 1000);
	}

	return 1;
}
int DRA::win_8h(){

	if(wind.info_no<1000){//ログ
		win_hmes("様々な情報がログで表示されます@");
		//とりあえず未定
	}
	return 1;
}
int DRA::win_9h(){

	switch(wind.info_no){//収支・シェア
		case 0:
			win_hmes("年単位表示@");
		break;
		case 1:
			win_hmes("月単位表示@");
		break;
		case 2:
			win_hmes("日単位表示@");
		break;
		case 3:
			win_hmes("詳細表示@");
		break;
		case 4:
			win_hmes("日付変更@NOWオンで現在の日付");
		break;
		case 5:
			win_hmes("売った武器の数@");
		break;
		case 6:
			win_hmes("トータル売上@");
		break;
		case 7:
			win_hmes("剣の売上＆シェア@");
		break;
		case 8:
			win_hmes("槍の売上＆シェア@");
		break;
		case 9:
			win_hmes("斧の売上＆シェア@");
		break;
		case 10:
			win_hmes("弓の売上＆シェア@");
		break;
		case 11:
			win_hmes("来店した客の数@");
		break;
		case 12:
			win_hmes("製造した武器の数@");
		break;
		case 13:
			win_hmes("武器の製造開発に使った資金@");
		break;
		case 14:
			win_hmes("店員と職人の給料@");
		break;
		case 15:
			win_hmes("経営戦術に使った資金＋貸し倉庫使用料金@");
		break;
		case 16:
			win_hmes("税金＋利子＋農具の売上@");
		break;
		case 17:
			win_hmes("トータルの利益@");
		break;
		case 18:
			win_hmes("株価@");
		break;
		case 20:
			win_hmes("収支詳細表示、項目クリックでグラフ表示@");
		break;
		case 21:
			win_hmes("グラフ表示、クリックで戻る@");
		break;
		case 22:
			win_hmes("総資金@");
		break;
		case 23:
			win_hmes("株価@");
		break;
		case 24:
			win_hmes("人口@");
		break;

	}

	return 1;
}
int DRA::win_10h(){
	//戦術説明
	std::ostringstream stream;

	if(wind.info_no<MANA_M){//
		mana_info(wind.info_no);
	}else{//MP
		switch(wind.info_no){
			case 1000:
				stream << "経営系戦術@EXP " << shop[P].bumon_exp[0]/10 << " / " << shop[P].bumon_lv[0]*shop[P].bumon_lv[0]*10 + 40 << "@";
				win_hmes(stream.str().c_str());
			break;
			case 1001:
				stream << "財務系戦術@EXP " << shop[P].bumon_exp[1]/10 << " / " << shop[P].bumon_lv[1]*shop[P].bumon_lv[1]*10 + 40 << "@";
				win_hmes(stream.str().c_str());
			break;
			case 1002:
				stream << "工事系戦術@EXP " << shop[P].bumon_exp[2]/10 << " / " << shop[P].bumon_lv[2]*shop[P].bumon_lv[2]*10 + 40  << "@";
				win_hmes(stream.str().c_str());
			break;
			case 1003:
				stream << "開発系戦術@EXP " << shop[P].bumon_exp[3]/10 << " / " << shop[P].bumon_lv[3]*shop[P].bumon_lv[3]*10 + 40  << "@";
				win_hmes(stream.str().c_str());
			break;
			case 1004:
				stream << "宣伝系戦術@EXP " << shop[P].bumon_exp[4]/10 << " / " << shop[P].bumon_lv[4]*shop[P].bumon_lv[4]*10 + 40  << "@";
				win_hmes(stream.str().c_str());
			break;
			case 2000:
				win_hmes("現在MP/毎日の回復量@");
			break;
			case 3000:
			case 3001:
			case 3002:
			case 3003:
			case 3004:
			case 3005:
				win_hmes("表示戦術種類切り替え@");
			break;
			case 3006:
			case 3007:
				win_hmes("表示戦術種類切り替え@");
			break;
		}
	}
	return 1;
}
int DRA::win_11h(){
	int X,Y;
	//ダンジョン
	win_hmes("ダンジョンの情報を表示",190,130);
	if(Inp.m_x<data.window_x-190) X = Inp.m_x;
	else						  X = Inp.m_x - 190;
	if(Inp.m_y<data.window_y-130) Y = Inp.m_y;
	else						  Y = Inp.m_y - 130;

	//LV　探索度　ボス強さ　生息モンスター
	int HP = (dun[wind.info_no].boss_hp * 101 - 1) /dun[wind.info_no].boss_max;

	waku(X+10,Y+26,165,20,6);
	waku(X+10,Y+51,60,20,6);
	waku(X+10,Y+76,60,20,6);
	waku(X+10,Y+101,60,20,6);

	waku_c(X+75,Y+51,wind.info_no*2,20,255,100,100);
	waku_c(X+75,Y+76,100-dun[wind.info_no].seek,20,255,100,100);
	waku_c(X+75,Y+101,HP,20,255,100,100);

	mes(X+18,30+Y,"名状しがたい未開地",color.kuro,color.siro,2);

	mes(X+18,55+Y,"ＬＶ",color.kuro,color.siro,2);
	suu_bmf(X+165,61+Y,2,wind.info_no,0);

	mes(X+18,80+Y,"未開度",color.kuro,color.siro,2);
	suu_bmf(X+165,86+Y,2,100-dun[wind.info_no].seek,0);

	mes(X+18,105+Y,"ボス",color.kuro,color.siro,2);
	suu_bmf(X+165,111+Y,2,HP,0);

	return 1;
}
int DRA::win_12h(){
	//ウィンドウ名,上部タブ
	switch(wind.info_no){
		case 0:
			win_hmes("来客状況@各店の来客状況、自店客の詳細を表示@");//客
		break;
		case 1:
			win_hmes("武器一覧@生産可能な武器の一覧@ドラッグ＆ドロップ＞フォルダ整理@職人にドロップ＞シフト変更@");//武器
		break;
		case 2:
			win_hmes("店舗風景@お店の前の状況@");//開発
		break;
		case 3:
			win_hmes("求人一覧@従業員募集に応募してきた人材の一覧@クリック＞内定/キャンセル@");//求人
		break;
		case 4:
			win_hmes("店員一覧@ドラッグ＆ドロップ＞シフト変更@");//人事・店
		break;
		case 5:
			win_hmes("職人一覧@武器or開発一覧にドロップ＞シフト変更@");//人事・工
		break;
		case 6:
			win_hmes("会社情報@自社のステータス@");//会社
		break;
		case 7:
			win_hmes("ログ一覧@最近の出来事を表示@");//ログ
		break;
		case 8:
			win_hmes("収支情報@年月日毎の収支状況@");//収支
		break;
		case 9:
			win_hmes("経営戦術一覧@クリック＞使用予約/キャンセル@");//経営戦術
		break;
		case 10:
			win_hmes("経営目標@勝利条件や状況@");//マップ表示
		break;
		case 11:
			win_hmes("マップ表示@全てのウィンドウを表示/非表示を切り替えて@マップを見やすくします@");//マップ表示
		break;
		case 12:
			win_hmes("ゲーム終了@クリックで現在の状態をセーブし、終了します@");//タイトルへ
		break;
		case 13:
			win_hmes("コンフィグ@ウィンドウサイズやBGM音量等を変更@");//コンフィグ
		break;
		case 14:
			win_hmes("ゲームスピード@クリックでゲームスピードを変更@");//ゲームスピード
		break;
		case 15:
			win_hmes("ヘルプ@ヘルプメニューを開きます@");//タイトルへ
		break;
		case 20:
			win_hmes("現在の日付@");//日付
		break;
		case 21:
			win_hmes("現在の時刻@");//時刻
		break;
		case 22:
			win_hmes("今日の天気、天気が悪いと客が増える@");//天気
		break;
		case 23:
			win_hmes("営業状態@");//経済
		break;
		case 24:
			win_hmes("現在の流行@");//経済
		break;
		case 25:
			win_hmes("フロンティアにいる冒険者の数@");//冒険者数
		break;
		case 26:
			win_hmes("自社の資金@");//資金
		break;
		case 27:
			win_hmes("会社の知名度@");//冒険者数
		break;
	}

	return 1;
}
int DRA::win_htai(){
	//給料変化表示
	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 240 ) ;//半透明でヘルプウィンドウ
	draw.waku(Inp.m_x-35,Inp.m_y-30,70,30,3);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;

	if(emp[wind.info_taiguu].chan_tai<0){//解雇
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
	//文章のみのヘルプ//Ｇ＝行数
	//ウィドウは半透明で
	int X,Y,G,C;

	std::string st[10];
	st[0] = str;

	for(G=0;G<10;G++){
		C = st[G].find("@");
		if(C==-1)break;//@が無ければ終了
		st[G+1] = st[G].substr(C+1);
		st[G]   = st[G].substr(0,C);
		YS += 20;
	}

	for(C=0;C<G;C++){
		XS = max(st[C].size()*9+13,unsigned int(XS));
	}

	//頂点座標選択
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
	//文章のみのヘルプ//Ｇ＝行数
	//ウィドウは半透明で
	int G,C;
	int XS = 0;
	int YS = 10;

	X += data.window_x/2-480;
	Y += data.window_y/2-360;

	std::string st[10];
	st[0] = str;

	for(G=0;G<10;G++){
		C = st[G].find("@");
		if(C==-1)break;//@が無ければ終了
		st[G+1] = st[G].substr(C+1);
		st[G]   = st[G].substr(0,C);
		YS += S * 10;
	}

	for(C=0;C<G;C++){
		XS = max(st[C].size()*9*S/2+13,unsigned int(XS));
	}

	//頂点座標選択
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

	//基本情報
	waku(X+6,Y+30,230,32,6);
	waku(X+6,Y+66,430,66,6);
	draw.mana_icon(X+6,Y+26,M,1);
	mes(X+44,Y+37,mana[M].name.c_str(),color.kuro,color.siro,0);

	//説明文
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

	//基本情報
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
	if(M < 61 || M > 65){//株式買収系
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

	//説明文
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

	//画像＆職種＆モチベーション
	waku(8+X,40+Y,148,24,7);
	waku(8+X,26+Y,98,38,7);
	mes(49+X,47+Y,emp[E].name.c_str(),color.kuro,color.siro,2);//名前
	DrawRotaGraph(30+X,46+Y,2,0,gra.unit[emp[E].gra][1],TRUE,0);
	//体調表示
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
		DrawRotaGraph(36+X,37+Y,1,0,gra.emo[IC],TRUE,0);//噴出し
		SetDrawBright(255,255,255);		
		switch(IC){
			case 0:mes(49+X,29+Y,"絶好調!",color.kuro,color.siro,2);break;
			case 1:mes(49+X,29+Y," 好調♪",color.kuro,color.siro,2);break;
			case 2:mes(49+X,29+Y," 普通",color.kuro,color.siro,2);break;
			case 3:mes(49+X,29+Y," 不調",color.kuro,color.siro,2);break;
			case 4:mes(49+X,29+Y,"お疲れ",color.kuro,color.siro,2);break;
			case 5:mes(49+X,29+Y,"療養中…",color.kuro,color.siro,2);break;
			case 6:mes(49+X,29+Y,"お休み",color.kuro,color.siro,2);break;
		}
	}else{
		mes(49+X,29+Y,"求職中",color.kuro,color.siro,2);
	}

	//スキル
	waku(158+X,40+Y,222,24,7);
	waku(158+X,26+Y,142,38,7);
	DrawRotaGraph(170+X,36+Y,1,0,gra.ico[91],TRUE,0);
	if(emp[E].mensetu[4][P] == 1){
		mes(180+X,29+Y,data.skill_job[emp[E].skill],color.kuro,color.siro,2);
		mes(162+X,48+Y,data.skill_info[emp[E].skill],color.kuro,color.siro,2);
	}else{
		mes(180+X,29+Y,"？？？",color.kuro,color.siro,2);
		mes(162+X,48+Y,"どんな特徴があるか分からない",color.kuro,color.siro,2);
	}
	//レベル
	//イベント人材フラグ
	if(emp[E].eve_flag == 1){
		SetDrawBright(255,255,0);
		mes_bmf(14+X,58+Y,"EVE",1);
		SetDrawBright(255,255,255);
	}else{
		mes_bmf(18+X,58+Y,"L",1);
	}

	suu_bmf(40+X,56+Y,2,emp[E].lv,2);
	//基本ステータス表示
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

		int GL;//ゲージ長さ

		switch(i){
			case 0:NAME = "体力";ICO = 44;
				N  = (int)sqrt((double)emp[E].st[0] * 100);
				GL = N /4;
				break;
			case 1:
				N  = emp[E].st[1];
				GL = N / 4;
				if(emp[E].job == 1){
					NAME = "製造";ICO = 45;
				}else{
					NAME = "客捌";ICO = 93;
				}
				break;
			case 2:
				N = emp[E].st[2];
				GL = N / 4;
				if(emp[E].job == 1){
					NAME = "開発";ICO = 7;
				}else{
					NAME = "接客";ICO = 46;
				}
				break;
			case 3:
				N  = int(emp[E].konjyou_k);
				GL = N;
				NAME = "根性";ICO = 73;break;
			case 4:
				N = emp[E].pay_money;
				GL = N / 6;
				NAME = "給料";ICO = 53;break;
			case 5:
				NAME = "社会";ICO = 48;break;
			case 6:
				NAME = "満足";ICO = 50;break;
			case 7:
				NAME = "実働";ICO = 93;break;
		}
		DrawRotaGraph(20+X,76+Y+i*22,1,0,gra.ico[ICO],TRUE,0);
		mes(36+X,69+Y+i*22,NAME.c_str(),color.kuro,color.siro,2);

		if(i<=4){
			if(i<4){//給料表示は別
				if(emp[E].mensetu[i][P])suu_bmf(134+X,76+Y+i*22,2,N,0);
				else					mes_bmf(100+X,76+Y+i*22,"???",2);
			}else{
				syou_bmf(138+X,76+Y+i*22,N,0);
			}

			if(emp[E].mensetu[i][P] || i==4){
				if(i == 0 && Z == 0){//体力表示
					waku_c(X+150,66+Y+i*22,GL,20,255,100,100);
					waku_c(X+150,66+Y+i*22,int(GL*emp[E].hp/100),20,255,C,0);
				}else if(i == 3 && Z == 0){//ストレス表示
					waku_c(X+150,66+Y+i*22,GL,20,255,C,0);
					waku_c(X+150,66+Y+i*22,int(emp[E].sun),20,0,0,0);
				}else{//他ステータス
					waku_c(X+150,66+Y+i*22,GL,20,255,C,0);
				}
			}
		}else if(i>=5 && i<7){
			waku(X+150,66+Y+i*22,230,20,6);
			switch(i){
				case 5:
					if(emp[E].b_w <= 0){
						COME = "すっごく会社に懐いてる";RANK = 0;
					}else if(emp[E].b_w <= 20) {
						COME = "会社が大好き";RANK = 1;
					}else if(emp[E].b_w <= 40) {
						COME = "会社の事気に入ってる";RANK = 2;
					}else if(emp[E].b_w <= 60) {
						COME = "働きたくなってきた";RANK = 3;
					}else if(emp[E].b_w <= 80) {
						COME = "とことん働きたい";RANK = 4;
					}else{
						COME = "社畜の目をしている";RANK = 5;
					}
				break;
				case 6:
					if(MAN<-20){
						COME = "給料は超満足みたい";RANK = 0;
					}else if(MAN<0){
						COME = "給料は満足みたい";RANK = 1;
					}else if(MAN<50){
						COME = "給料にやや不満がある";RANK = 2;
					}else if(MAN<100){
						COME = "給料に不満がある";RANK = 3;
					}else if(MAN<200){
						COME = "給料が少なすぎる";RANK = 4;
					}else{
						COME = "給料の文句を常に言っている";RANK = 5;
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
		}else{//成績
			//売上＆閃き回数＆労働日数
			suu_bmf(134+X,76+Y+i*22,2,emp[E].work_cnt,0);
			
			waku(X+150,66+Y+i*22,65,20,6);
			waku(X+220,66+Y+i*22,65,20,6);

			if(emp[E].job == 0){
				DrawRotaGraph(160+X,76+Y+i*22,1,0,gra.ico[53],TRUE,0);
				mes(176+X,69+Y+i*22,"販売",color.kuro,color.siro,2);
				suu_bmf(264+X,76+Y+i*22,2,emp[E].sell_now/10000,0);
				suu_bmf(276+X,78+Y+i*22,1,emp[E].sell_now/1000%10,0);
			}else{
				DrawRotaGraph(160+X,76+Y+i*22,1,0,gra.ico[7],TRUE,0);
				mes(176+X,69+Y+i*22,"閃き",color.kuro,color.siro,2);
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

	//武器名前、値段、数
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

	if(Z==0){//開発済み
	mes_bmf(X+305,22+Y,"X",1);
	suu_bmf(X+370,22+Y,2,shop[P].wep_rest[W],0);
	}else{//開発前、改良中
		if(shop[P].wep_make_now[W]>0)	C=100;
		else							C=150;
		suu_bmf(350+X,24+Y,2,wep[W].create_time/54,0);
		mes_bmf(X+370,24+Y,"G",2);
	}

	int N,N2,N3;//N と N3が表示する数字、N2はゲージ用
	double G;
	for(i=0;i<7;i++){
		switch(i){
			case 0:str = "価格"	;ICO = 53;
				N  = int(wep[W].price * shop[P].price_rate);
				N2 = wep[W].price*100;
				N3 = int(shop[P].price_rate*10 - 1000);

				if(shop[P].medama_check(W) == 1){
					N  = N * 8 / 10;
					N3 = N3 * 8 / 10;
				}
				G  = 300;
			break;
			case 1:str = "費用"	;ICO = 52;
				N  = int(wep[W].seizou_cost*wep[W].price*shop[P].cost_j[W]);
				N2 = wep[W].seizou_cost*wep[W].price;
				N3 = int(shop[P].cost_j[W] * 1000 - 1000);
				G  = 300;
			break;
			case 2:str = "時間"	;ICO = 54;
				N  = int(wep[W].make_time * 10 * shop[P].time_j[W] / 100 );
				N2 = int(wep[W].make_time * 10 / 100);
				N3 = int(shop[P].time_j[W] * 1000 - 1000);
				G  = 3;
				break;
			case 3:str = "攻撃力"	;ICO = 38;
				N  = int(wep[W].atk*shop[P].atk_j[W]*10);
				N2 = wep[W].atk* 10;
				N3 = int(shop[P].atk_j[W] * 1000 - 1000);
				G  = 20;
				break;
			case 4:str = "耐久力"	;ICO = 39;
				N  = int(wep[W].dur*shop[P].dur_j[W]);
				N2 = wep[W].dur;
				N3 = int(shop[P].dur_j[W] * 1000 - 1000);
				G  = 1;
				break;
			case 5:
				if(W == NOU_NO){
					str = "納品数"	;ICO = 62;
					N  = shop[P].nougu_req;
					N2 = shop[P].wep_rest[NOU_NO];
					if(shop[P].nougu_req <= 0)  N3 = 1000;
					else						N3 = shop[P].wep_rest[NOU_NO]*1000/shop[P].nougu_req;
					G = 5;
				}else{
					ICO = 40+wep[W].zoku;
					str = "集客力";				
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
					str = "改良LV"	;ICO = 7;
					N  = shop[P].wep_kaicnt[W];
					N2 = 100;
					N3 = int( double(shop[P].wep_kaiexp[W]) / (500+shop[P].wep_kaicnt[W]*50) / 5400 / 30 * 1000);
				}else{
					str = "開発率"	;ICO = 7;
					N  = int(double(shop[P].wep_make[W])/wep[W].create_time*100);
					N2 = 100;
					N3 = N*10;
				}
				waku_c(X+185,40+Y+i*22 ,N2 * 19 /10,20,255,150,150);
				waku_c(X+185,40+Y+i*22 ,N3 * 19 /100,20,255,100,100);
				break;
		}

		//ステータス＆変化
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

		//名前のとこの枠
		waku(X+10,40+Y+i*22  ,75,20,6);
		waku(X+90,40+Y+i*22  ,90,20,6);
		mes(35+X,43+Y+i*22,str.c_str(),color.kuro,color.siro,2);
		DrawRotaGraph(20+X,50+Y+i*22,1,0,gra.ico[ICO],TRUE,0);

		//ステータス表示
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

		//if(i == 0 && N3 == 100) continue;//値段はデフォルト表示無し
		mes(X+370,40+Y+i*22,"%",color.kuro,color.siro,0);
		//
		if(N3 < 0 && i < 6) mes_bmf(X+314,50+Y+i*22,"-",2);
		if(N3 > 0 && i < 6) mes_bmf(X+314,50+Y+i*22,"+",2);
		syou_bmf(X+360,50+Y+i*22 ,abs(N3),0);
	}

	//目玉商品効果表示
	waku(X+10,40+Y+7*22  ,90,20,6);
	waku(X+105,40+Y+7*22  ,270,20,6);
	mes(35+X,43+Y+7*22,"目玉商品",color.kuro,color.siro,2);
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
	//T = 0 戦術ウィンドウ
	//T = 1 会社情報ウィンドウ
	//T = 2 説明
	//T = 3 図鑑
	int Z = mana[M].type;

	if(mana[M].b_w_d != -99999)		waku_c(X,Y,36,36, 50, 50, 50);//ブラック
	else if(mana[M].b_w_u != 99999) waku_c(X,Y,36,36,255,255,255);//ホワイト
	else							waku_c(X,Y,36,36,200,200,200);
	
	waku(X+2,Y+2,32,32,6);

	if(T == 0 || T == 2){
		if(shop[P].use_mana == M)			waku_c(X,Y,36,36,255,150,150);//使用中
	}

	int IC = mana[M].icon;
	//未修得表示
	if(shop[P].mana_ok[M] != 1 && shop[P].mana_rest[M] > 0 && T < 3) IC = 49;

	//制度or単発
	DrawRotaGraph(X+18,Y+18,2,0,gra.ico[IC],TRUE,0);
	if(mana[M].seido > 0){//制度
		DrawRotaGraph(X+8,Y+28,2,0,gra.ico[87],TRUE,0);
	}

	if(T < 2 || T == 3){
		std::string str;
		str = mana[M].name;
		if(str.length() > 4) str[4] = NULL;
		mes(X+4,Y+4,str.c_str(),color.kuro,color.siro,2);
	}

	if(shop[P].mana_day[M] == data.day && (T == 0 || T==2))	DrawRotaGraph(X+18,Y+28,2,0,gra.ico[22],TRUE,0);//覚えたて

	if(IC == 49){
		mes_bmf(X+8,Y+28,"RK",1);
		suu_bmf(X+28,Y+28,2,mana[M].rank,0);
	}else if(T == 0){
		suu_bmf(X+28,Y+28,1,shop[P].syou_mp[M]*shop[P].mana_b[Z]/100,0);//消費MP
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
	DrawRotaGraph(X,Y,R,0,gra.wep[N],TRUE,0);//武器アイコン
	if(data.wep_ganso[N] == P || data.wep_ganso[N] == -1) DrawRotaGraph(X-8,Y+6,2,0,gra.ico[101],TRUE,0);//元祖表示
	if(shop[P].wep_cre[N] != 2)SetDrawBright(255,255,255);

	return 1;
}
int DRA::drama(){
	int i;
	//イベントシーンメイン画面
	draw.work();
	//背景暗くする
	SetDrawBlendMode( DX_BLENDMODE_ALPHA , 100) ;
	DrawBox(0,0,data.window_x,data.window_y,GetColor(0,0,0),1);
	SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
	//枠+場面画像
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

	//人表示
	for(i=0;i<36;i++){

		if (act[i]->no<0)continue;
		act[i]->p = act[i]->m *3 + 1;
		for(int cnt =0; cnt<1+Inp.m_RO*2;cnt++){
			if(act[i]->mx < 0){//移動処理
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
		if(act[i]->emo == 13		 && EVE_FUN::Sin().eve_wait <= 20)act[i]->emo = 12;//・・・
		else if(act[i]->emo == 12 && EVE_FUN::Sin().eve_wait <= 10)act[i]->emo = 11;
		//向きの計算

		DrawRotaGraph(act[i]->x,act[i]->y,2,0,gra.unit[act[i]->no][act[i]->p],1,0);//SD
	}
	SetDrawArea(0,0,data.window_x,data.window_y);
	//感情
	for(i=0;i<36;i++)
	{
		if(act[i]->emo>=0)DrawRotaGraph(act[i]->x,act[i]->y-30,2,0,gra.emo[act[i]->emo],1,0);//感情
	}
	//噴出し
	for(i=0;i<36;i++){
		if(act[i]->huki_w <=0 ) continue;
		draw.waku_h(i);
	}

	SetDrawBright(255,255,255);

	return 1;
}
int DRA::waku(int XU,int YU,int XS,int YS,int NO){

	//中身
	DrawExtendGraph(XU+10,YU+10,XU+XS-10,YU+YS-10,gra.win[NO*9+4],1);
	//四隅
	DrawGraph(XU	  ,YU	   ,gra.win[NO*9+0],1);
	DrawGraph(XU+XS-10,YU	   ,gra.win[NO*9+2],1);
	DrawGraph(XU	  ,YU+YS-10,gra.win[NO*9+6],1);
	DrawGraph(XU+XS-10,YU+YS-10,gra.win[NO*9+8],1);
	//上下左右
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

	//枠＆噴出し表示
	if(act[N]->huki_ud == 1){//下
		waku_c(act[N]->x-act[N]->huki_w/2-1,act[N]->y+24,act[N]->huki_w+2,act[N]->huki_h+2,0,0,0);
		waku(act[N]->x-act[N]->huki_w/2,act[N]->y+25,act[N]->huki_w,act[N]->huki_h,6);
		DrawRotaGraph(act[N]->x,act[N]->y+26,1,0,gra.huki[1],1,0);
		Y = -10;
	}else{//上
		waku_c(act[N]->x-act[N]->huki_w/2-1,act[N]->y-29-act[N]->huki_h,act[N]->huki_w+2,act[N]->huki_h+2,0,0,0);
		waku(act[N]->x-act[N]->huki_w/2,act[N]->y-28-act[N]->huki_h,act[N]->huki_w,act[N]->huki_h,6);
		DrawRotaGraph(act[N]->x,act[N]->y-24,1,0,gra.huki[0],1,0);
		Y = - act[N]->huki_h - 64;
	}
	//名前用ウィンドウ
	waku_c(act[N]->x-act[N]->huki_w/2+6,act[N]->y+38+Y,act[N]->name_w,20,0,0,0);
	waku_c(act[N]->x-act[N]->huki_w/2+7,act[N]->y+39+Y,act[N]->name_w-2,18,255,255,255);

	//文章
	mes(act[N]->x-act[N]->huki_w/2+10,act[N]->y+42+Y     ,act[N]->name,color.kuro,color.siro,2);

	mes(act[N]->x-act[N]->huki_w/2+8,act[N]->y+59+Y     ,act[N]->huki_mes[0],color.kuro,color.siro,0);
	mes(act[N]->x-act[N]->huki_w/2+8,act[N]->y+59+Y+SY  ,act[N]->huki_mes[1],color.kuro,color.siro,0);
	mes(act[N]->x-act[N]->huki_w/2+8,act[N]->y+59+Y+SY*2,act[N]->huki_mes[2],color.kuro,color.siro,0);

	return 1;
}
int DRA::waku_help(int X,int Y,int XS,int YS,int N){
	//SetDrawBlendMode( DX_BLENDMODE_ALPHA , 240 ) ;//半透明でヘルプウィンドウ
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
	//説明用

	std::string str = M;

	//数字は置換する
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
		{//(´・＠・)
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
			//カンマ表示
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

	if(M < 0){//マイナス時
		DrawRotaGraph( X-int(K*I*2)-16 , Y , 2 , 0 , gra.moji[27] , TRUE ) ;
	}

	return 1;
}
int DRA::title(/*タイトル画面*/){

	static int time = 0;
	static int b_w = 0;
	unsigned int str_cnt;
	int	N=0;
	std::string str;
	double S = double(data.window_y)/1000;

	DrawBox(0,0,data.window_x,data.window_y,GetColor(0,0,0),true);
	// 画面データの取りこみ
	if( time< 360){//提供
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

	mes( 50 , 30 , "企画・制作・著作" , color.siro , color.kuro , 1 );
	mes( 70 , 70 , "（´・@・）" , color.siro , color.kuro , 0 );
	
	mes( 50 , 120 , "利用素材等（敬称略）" , color.siro , color.kuro , 1 );
	mes( 60 , 160 , "キャラ、マップチップ等" , color.siro , color.kuro , 0 );
	mes( 70 , 180 , "DotWorld" , color.siro , color.kuro , 0 );
	
	mes( 60 , 230 , "武器アイコン等" , color.siro , color.kuro , 0 );
	mes( 70 , 250 , "Whitecat" , color.siro , color.kuro , 0 );

	mes( 60 , 300 , "システムアイコン" , color.siro , color.kuro , 0 );
	mes( 70 , 320 , "Mark James" , color.siro , color.kuro , 0 );
	
	mes( 60 , 370 , "効果音" , color.siro , color.kuro , 0 );
	mes( 70 , 390 , "ザ・マッチメイカァズ" , color.siro , color.kuro , 0 );
	
	mes( 60 , 440 , "ＢＧＭ" , color.siro , color.kuro , 0 );
	mes( 70 , 460 , "フリー音楽素材 H/MIX" , color.siro , color.kuro , 0 );
	
	mes( 60 , 510 , "マルチメディアライブラリ" , color.siro , color.kuro , 0 );
	mes( 70 , 530 , "ＤＸライブラリ置き場" , color.siro , color.kuro , 0 );
	
	mes( 380 , 120 , "テストプレイ（敬称略）" , color.siro , color.kuro , 1 );

	mes( 400 , 160 , "アヲン" , color.siro , color.kuro , 0 );
	mes( 600 , 160 , "sinn" , color.siro , color.kuro , 0 );
	mes( 800 , 160 , "dai" , color.siro , color.kuro , 0 );

    mes( 400 , 190 , "nekoq" , color.siro , color.kuro , 0 );	
	mes( 600 , 190 , "krith" , color.siro , color.kuro , 0 );
	mes( 800 , 190 , "メロンたべたい" , color.siro , color.kuro , 0 );

	mes( 400 , 220 , "MonoM" , color.siro , color.kuro , 0 );
	mes( 600 , 220 , "veve" , color.siro , color.kuro , 0 );
	mes( 800 , 220 , "yan" , color.siro , color.kuro , 0 );

    mes( 400 , 250 , "Linebard" , color.siro , color.kuro , 0 );
	mes( 600 , 250 , "ENOMON" , color.siro , color.kuro , 0 );
	mes( 800 , 250 , "AX" , color.siro , color.kuro , 0 );
		
	mes( 400 , 280 , "むっぴ" , color.siro , color.kuro , 0 );
	mes( 600 , 280 , "ダイ" , color.siro , color.kuro , 0 );	
	mes( 800 , 280 , "まあ。" , color.siro , color.kuro , 0 );

    mes( 400 , 310 , "れべるあげ" , color.siro , color.kuro , 0 );	
	mes( 600 , 310 , "GIA" , color.siro , color.kuro , 0 );
	mes( 800 , 310 , "武将" , color.siro , color.kuro , 0 );
	
	mes( 400 , 340 , "milk" , color.siro , color.kuro , 0 );
	mes( 600 , 340 , "eriny" , color.siro , color.kuro , 0 );	
	mes( 800 , 340 , "Crosis the Purger" , color.siro , color.kuro , 0 );

    mes( 400 , 370 , "ルーク" , color.siro , color.kuro , 0 );
	mes( 600 , 370 , "むむ" , color.siro , color.kuro , 0 );
	mes( 800 , 370 , "SSS" , color.siro , color.kuro , 0 );
	
	mes( 400 , 400 , "Ariel" , color.siro , color.kuro , 0 );
	mes( 600 , 400 , "Taccon" , color.siro , color.kuro , 0 );
	mes( 800 , 400, "特攻三等兵/XA./SAN", color.siro, color.kuro, 0);

	mes( 400 , 430, "ワオン", color.siro, color.kuro, 0);
    mes( 600 , 430, "てつしんぱん", color.siro, color.kuro, 0);
    mes( 800 , 430, "eriny", color.siro, color.kuro, 0);

    mes( 400 , 460, "九月雨", color.siro, color.kuro, 0);
    mes( 600 , 460, "望崎", color.siro, color.kuro, 0);
    mes( 800 , 460, "二コニ胡", color.siro, color.kuro, 0);

    mes( 400 , 490, "とくにな", color.siro, color.kuro, 0);
    mes( 600 , 490, "Jupiter", color.siro, color.kuro, 0);
    mes( 800 , 490, "て", color.siro, color.kuro, 0);
    
    mes( 400 , 520, "ぴぴぴ", color.siro, color.kuro, 0);
    mes( 600 , 520, "シチュー冷えた", color.siro, color.kuro, 0);
    mes( 800 , 520, "sipmen", color.siro, color.kuro, 0);

    mes( 400 , 550, "なし", color.siro, color.kuro, 0);
    mes( 600 , 550, "唯", color.siro, color.kuro, 0);
    mes( 800 , 550, "Crostel", color.siro, color.kuro, 0);

    mes( 400 , 580, "ライノス", color.siro, color.kuro, 0);
    mes( 600 , 580, "ことだましょう", color.siro, color.kuro, 0);
    mes( 800 , 580, "虎王丸", color.siro, color.kuro, 0);
    
    mes( 400 , 610, "十六夜月", color.siro, color.kuro, 0);
    mes( 600 , 610, "ＪＩＮ", color.siro, color.kuro, 0);
    mes( 800 , 610, "L-Valuation", color.siro, color.kuro, 0);

	return 1;
}
int DRA::wep_db(){

	int XA=(data.window_x - 800) / 2;
	int YA=(data.window_y - 670) / 2;

	static int T = 0;
	static int Tab = 0;
	static int Tsc[5] = {0,0,0,0,0};

	//種類ボタン
	if( Inp.m_x > XA + 8 && 
		Inp.m_x < XA + 168 && 
		Inp.m_y > YA + 8 && 
		Inp.m_y < YA + 48){
		T = 1000 + (Inp.m_x-XA-8)/40;
		if(Inp.m_LC == 1) Tab = T - 1000;
	}
	//リスト
	if( Inp.m_x > XA + 8 && 
		Inp.m_x < XA + 260 && 
		Inp.m_y > YA + 56 && 
		Inp.m_y < YA + 656){
		T = (Inp.m_y-YA-56)/30;
	}
	//スクロールバー
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
			DrawRotaGraph(XA+24,YA+70+i*30,1,0,gra.wep[W],TRUE,0);//武器アイコン
		}else{
			mes(XA+44,YA+60+i*30,"？？？？",color.kuro,color.siro,0);
			DrawRotaGraph(XA+24,YA+70+i*30,2,0,gra.ico[57],TRUE,0);//武器アイコン
		}
	}

	//性能説明
	wep_db_s(XA,YA,Tab*100+Tsc[Tab]+T);

	return 1;
}
int DRA::mana_db(){

	int XA=(data.window_x - 800) / 2;
	int YA=(data.window_y - 700) / 2;

	static int T = 0;
	static int Tab = 0;
	static int Tsc[5] = {0,0,0,0,0};

	//種類ボタン
	if( Inp.m_x > XA + 8 && 
		Inp.m_x < XA + 208 && 
		Inp.m_y > YA + 8 && 
		Inp.m_y < YA + 48){
		//T = 1000 + (Inp.m_x-XA-8)/40;
		if(Inp.m_LC == 1) Tab = 1000 + (Inp.m_x-XA-8)/40-1000;
	}
	//リスト
	if( Inp.m_x > XA + 8 && 
		Inp.m_x < XA + 260 && 
		Inp.m_y > YA + 56 && 
		Inp.m_y < YA + 656){
		if(Tsc[Tab] + (Inp.m_y-YA-56)/30 < data.mana_max[Tab]){
			T = (Inp.m_y-YA-56)/30;
		}
	}
	//スクロールバー
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

	//リスト
	int N = 0;

	for(int i=0,W=Tab*60+Tsc[Tab]+1;i<20;i++,W++){
		N = data.mana_index[W];
		if(i == T) waku_c(XA+6,YA+54+i*30,254,32,255,0,0);
		if(W > data.mana_max[Tab] + Tab*60) break;
		waku(XA+8,YA+56+i*30,250,28,6);
		if(sys.mana_total[N] > 0){
			mes(XA+44,YA+60+i*30,mana[N].name.c_str(),color.kuro,color.siro,0);
			DrawRotaGraph(XA+24,YA+70+i*30,2,0,gra.ico[mana[N].icon],TRUE,0);//戦術
			if(mana[N].seido > 0)DrawRotaGraph(XA+32,YA+78+i*30,2,0,gra.ico[87],TRUE,0);
		}else{
			mes(XA+44,YA+60+i*30,"？？？？",color.kuro,color.siro,0);
			DrawRotaGraph(XA+24,YA+70+i*30,2,0,gra.ico[57],TRUE,0);//戦術
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

	label_r[0] = "販売数";tanni[0] = "個";
	label_r[1] = "来客数";tanni[1] = "人";
	label_r[2] = "売り上げ-合計";tanni[2] = "Ｇ";
	label_r[3] = "売り上げ-剣";tanni[3] = "Ｇ";
	label_r[4] = "売り上げ-槍";tanni[4] = "Ｇ";
	label_r[5] = "売り上げ-斧";tanni[5] = "Ｇ";
	label_r[6] = "売り上げ-弓";tanni[6] = "Ｇ";
	label_r[7] = "製造数";tanni[7] = "個";
	label_r[8] = "製造費";tanni[8] = "Ｇ";
	label_r[9] = "人件費";tanni[9] = "Ｇ";
	label_r[10] = "つるはし製造";tanni[10] = "個";
	
	label_r[11] = "開発回数";tanni[11] = "回";
	label_r[12] = "宣伝回数";tanni[12] = "回";
	label_r[13] = "経営日数";tanni[13] = "日";
	label_r[14] = "雇用人数";tanni[14] = "人";
	label_r[15] = "解雇人数";tanni[15] = "人";
	label_r[16] = "辞職人数";tanni[16] = "人";
	label_r[17] = "廃人化数";tanni[17] = "人";

	label_r[18] = "株価";	tanni[18] = "Ｇ";
	label_r[19] = "開発数";	tanni[19] = "個";
	label_r[20] = "クリア日数";	tanni[20] = "日";
	label_r[21] = "人口";	tanni[21] = "人";
	label_r[22] = "資金";	tanni[22] = "Ｇ";
	label_r[23] = "クリア回数";	tanni[23] = "回";
	label_r[24] = "難易度";	tanni[24] = "";

	DrawExtendGraph(0,0,data.window_x,data.window_y,gra.title[2],true);

	waku(XA,YA,270,620,5);
	waku(XA+270,YA,530,620,5);

	//モード一覧
	for(int i=0,W=1;i<19;i++,W++){
		int IC = data.mode_icon[i];
		if( i!= 0 && !sys.play_flag[i-1]) IC = 57;//

		if(T == i) waku_c(XA+6,YA+8+i*30,254,32,255,0,0);
		waku(XA+8,YA+10+i*30,250,28,6);
		if(IC != 57) mes(XA+46,YA+14+i*30,data.mode_n[i].c_str(),color.kuro,color.siro,0);
		else		 mes(XA+46,YA+14+i*30,"？？？？",color.kuro,color.siro,0);
		DrawRotaGraph(XA+26,YA+24+i*30,1,0,gra.ico[IC],TRUE,0);
	}

	//記録一覧
	for(int i=0;i<18;i++){
		int IC = 15;
		waku(XA+10+270,YA+40+i*30,510,28,6);
		if(T == 0 || i <= 10){//総合
			mes(XA+46+270,YA+44+i*30,label_r[i].c_str(),color.kuro,color.siro,0);
			mes(XA+46+720,YA+44+i*30,tanni[i].c_str(),color.kuro,color.siro,0);
		}else{//それ以外
			mes(XA+46+270,YA+44+i*30,label_r[i+7].c_str(),color.kuro,color.siro,0);
			mes(XA+46+720,YA+44+i*30,tanni[i+7].c_str(),color.kuro,color.siro,0);
		}
		//メダル
		//DrawRotaGraph(XA+26+270,YA+54+i*30,1,0,gra.ico[IC],TRUE,0);

		if(T != 0 && i == 17){//最高難易度
			mes_bmf(XA+750 - data.nanndo_n[sys.score_record[(T+19)%20][17]].length()*10,YA+54+i*30,data.nanndo_n[sys.score_record[(T+19)%20][17]].c_str(),2);
		}else{//それ以外
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
			waku_c(XA+6+(i%10)*40,YA+6+(i/10)*40,40,40,255,0,0);//枠
		}
		waku(XA+8+(i%10)*40,YA+8+(i/10)*40,36,36,6);//枠

		IC = 17 - sys.medal_gold[i];

		if(sys.medal_cnt[i]==0){
			SetDrawBright(64,64,64);
		}

		DrawRotaGraph(XA+25+(i%10)*40,YA+25+(i/10)*40,2,0,gra.ico[IC],TRUE,0);//アイコン
		SetDrawBright(255,255,255);
	}

	//勲章名
	if(T >= 0){
		waku(		  XA-90,YA+460,600,30,6);//枠
		mes(		  XA-72,YA+463,sys.medal_name[T].c_str(),color.kuro,color.siro,1);
		//説明
		waku(		  XA-90,YA+494,600,150,6);//枠
		mes_str(	  XA-82,YA+502,sys.medal_info[T].c_str(),color.kuro,color.siro,0);
		/*
		waku(		  XA-90,YA+618,600,30,6);//枠
		if(sys.medal_cnt[T] == 0) SetDrawBright(96,96,96);
		DrawRotaGraph(XA-72,YA+632,2,0,gra.ico[17],TRUE,0);
		SetDrawBright(255,255,255);
		mes_bmf(XA-58,YA+638,"Bonus Point",2);
		suu_bmf(XA+556,YA+634,2,sys.medal_gold[T],0);

		//ボーナス点
		//waku(XA+10,YA+618,500,30,6);//枠
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

	//合計メダル数
	for(int i=0 ; i< 3;i++){
		waku(		  XA-90 + 200 * i ,YA+670, 190,30,6);//枠
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

	//武器名前、値段、数
	waku(6+X,6+Y,476,30,6);
	mes(64+X,12+Y,wep[W].name.c_str(),color.kuro,color.siro,0);
	DrawRotaGraph(24+X,20+Y,1,0,gra.wep[W],TRUE,0);//武器アイコン

	if(W == NOU_NO)	{
		mes_bmf(X+44,Y+30,"ETC",1);
	}else{
		DrawRotaGraph(X+50,Y+16,1,0,gra.ico[wep[W].type],0);
		if(wep[W].type == 0) mes_bmf(X+44,Y+28,"SWD",1);
		else if(wep[W].type == 1) mes_bmf(X+44,Y+28,"LNC",1);
		else if(wep[W].type == 2) mes_bmf(X+44,Y+28,"AXE",1);
		else if(wep[W].type == 3) mes_bmf(X+44,Y+28,"ARW",1);
	}

	int N,L;//N と N3が表示する数字、N2はゲージ用
	double G;
	int YP = 0;
	for(i=0;i<16;i++,YP+=26){
		switch(i){
			case 0:
				str = "価格"	;ICO = 53;
				N  = wep[W].price * 100;
				G  = 100000.0/285;
			break;
			case 1:
				str = "費用"	;ICO = 52;
				N  = wep[W].seizou_cost*wep[W].price;
				G  = 100000.0/285;
			break;
			case 2:
				str = "時間"	;ICO = 54;
				N  = wep[W].make_time/10;
				G  = 400.0/285;
				break;
			case 3:
				str = "攻撃力"	;ICO = 38;
				N  = wep[W].atk;
				G  = 320.0/285;
				break;
			case 4:
				str = "耐久力"	;ICO = 39;
				N  = wep[W].dur;
				G  = 100.0/285;
				break;
			case 5:
				str = "集客力"	;ICO = 86;
				N  = wep[W].ninki[0]+wep[W].ninki[1]+wep[W].ninki[2];
				G = 270.0/285;
			break;
			case 6://目玉補正				
				str = "種類"	;ICO = 100;
				N  = wep[W].mtype;
				G = 270.0/285;
			break;
			case 7://目玉補正				
				str = "属性"	;ICO = 100;
				N  = wep[W].mzoku;
				G = 270.0/285;
			break;
			case 8:
				YP += 5;
				str = "開発費"	;ICO = 53;
				N  = wep[W].create_time/54;
				G  = 500000.0/285;
			break;
			case 9:
				str = "閃難度"	;ICO = 7;
				N  = wep[W].rank;
				G  = 200.0/285;
			break;
			case 10:
				str = "研磨LV"	;ICO = 1;
				N  = wep[W].req_clv[0];
				G  = 50.0/285;
			break;
			case 11:
				str = "錬鉄LV"	;ICO = 2;
				N  = wep[W].req_clv[1];
				G  = 50.0/285;
			break;
			case 12:
				str = "細工LV"	;ICO = 3;
				N  = wep[W].req_clv[2];
				G  = 50.0/285;
			break;
			case 13:
				YP += 5;
				str = "改良MAX"	;ICO = 15;//最高レベルによる
				N  = sys.wep_maxlv[W];
				G  = 100.0/285;
			break;
			case 14:
				str = "開発数";ICO = 15;//
				N  = sys.wep_cret[W];
				G  = 100.0/285;
			break;
			case 15:
				str = "製造数"	;ICO = 15;
				N  = sys.wep_maket[W];
				G  = 10000.0/285;
			break;

		}
		//名前のとこの枠
		waku(X+10,38+Y+YP  ,75,24,6);
		waku(X+90,38+Y+YP  ,90,24,6);
		mes(35+X,44+Y+YP,str.c_str(),color.kuro,color.siro,2);
		DrawRotaGraph(21+X,51+Y+YP,1,0,gra.ico[ICO],TRUE,0);
		waku(X+183,38+Y+YP ,289,24,6);

		L = min(285,int(N  / G));

		//ステータス表示
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
	//開発コスト
	//閃き難度
	//技術力ABC

	//最大改良
	//開発回数
	//製造数

	//説明文(開発条件込み)

	waku(6+X,38+Y+26*17,476,130,6);

	int no = wep[W].req_mana;
	std::string mess = "";

	if (no <= 0 || no == 60)
	{
		mess = "特殊条件無し";
	}
	else
	{
		mess += "「" + mana[no].name + "」" + "を使用すると開発可能に";
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

	shop[P].mana_day[M] = -100;//New消去


	//基本情報
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
				str = "ＭＰ"	;ICO = 14;
				N  = shop[P].syou_mp[M];
				G  = 200.0/255;
			break;
			case 1:
				str = "費用"	;ICO = 53;
				N  = shop[P].syou_money[M]*100;
				if(M >= 61 && M <= 65) N = 0;
				G  = 5000000.0/255;
			break;
			case 2:
				str = "ＢＷ変化"	;ICO = 47;
				N  = (int)mana[M].b_w_c;
				G  = 10.0/255;
				break;
			case 3:
				str = "ＢＷ条件"	;ICO = 47;
				N  = max(mana[M].b_w_d,-100);
				N2 = min(mana[M].b_w_u,100);
				G  = 100.0/255;
				break;
			case 4:
				str = "部門ＬＶ"	;ICO = mana[M].icon;
				N  = mana[M].rank;
				G  = 10.0/255;
				break;
			case 5:
				str = "累計回数"	;ICO = 15;//使用回数に応じて
				N  = sys.mana_total[M];
				G  = 100.0/255;
			break;
		}
		//名前のとこの枠
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

		//ステータス表示
		if(i==2){//BW変化
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
			//BW条件
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
	//基本説明文
	waku(X+10,Y+38+7*26  ,476,90,6);
	mes_stri(X+18,Y+58+7*26,mana[M].zukan.c_str());

	return 1;
}

int DRA::wep_db_no(int X,int Y, int W){
	//グラフィック
	//攻撃
	//耐久
	//集客
	//売値
	//原価
	//製造
	int i;
	std::string str;
	int ICO;
	X += 300;
	Y += 34;

	int C = 0;

	//武器名前、値段、数
	waku(6+X,6+Y,476,30,6);
	mes(64+X,12+Y,"????",color.kuro,color.siro,0);
	DrawRotaGraph(24+X,20+Y,1,0,gra.ico[57],TRUE,0);//武器アイコン

	mes_bmf(X+44,Y+30,"???",1);

	int YP = 0;
	for(i=0;i<16;i++,YP+=26){
		switch(i){
			case 0:
				str = "価格"	;ICO = 53;
			break;
			case 1:
				str = "費用"	;ICO = 52;
			break;
			case 2:
				str = "時間"	;ICO = 54;
				break;
			case 3:
				str = "攻撃力"	;ICO = 38;
				break;
			case 4:
				str = "耐久力"	;ICO = 39;
				break;
			case 5:
				str = "集客力"	;ICO = 86;
			break;
			case 6://目玉補正				
				str = "種類"	;ICO = 100;
			break;
			case 7://目玉補正				
				str = "属性"	;ICO = 100;
			break;
			case 8:
				YP += 5;
				str = "開発費"	;ICO = 53;
			break;
			case 9:
				str = "閃難度"	;ICO = 7;
			break;
			case 10:
				str = "研磨LV"	;ICO = 1;
			break;
			case 11:
				str = "錬鉄LV"	;ICO = 2;
			break;
			case 12:
				str = "細工LV"	;ICO = 3;
			break;
			case 13:
				YP += 5;
				str = "改良MAX"	;ICO = 15;
			break;
			case 14:
				str = "開発数";ICO = 15;
			break;
			case 15:
				str = "製造数"	;ICO = 15;
			break;

		}
		//名前のとこの枠
		waku(X+10,38+Y+YP  ,75,24,6);
		waku(X+90,38+Y+YP  ,90,24,6);
		mes(35+X,44+Y+YP,str.c_str(),color.kuro,color.siro,2);
		DrawRotaGraph(21+X,51+Y+YP,1,0,gra.ico[ICO],TRUE,0);
		waku(X+183,38+Y+YP ,289,24,6);

		mes_bmf(140+X,52+Y+YP,"???",2);

		SetDrawBright(255,255,255);
	}
	//開発コスト
	//閃き難度
	//技術力ABC

	//最大改良
	//開発回数
	//製造数

	//説明文(開発条件込み)
	waku(6+X,38+Y+26*17,476,130,6);
	mes_str(16+X,48+Y+26*17,"？？？？--",color.kuro,color.siro,0);

	//説明文(開発条件込み)

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
		mess = "特殊条件無し";
	}
	else if ( wep[W].rank <= total)
	{
		mess += "「" + mana[no].name + "」" + "を使用すると開発可能に";
	}
	else
	{
		mess = "？？？？";
	}

	mes_str(16 + X, 48 + Y + 26 * 17, mess.c_str(), color.kuro, color.siro, 0);


	return 1;
}
int DRA::mana_db_no(int X,int Y,int M){

	X +=300;
	Y += 34;

	//基本情報
	waku(X+6,Y+6,476,30,6);
	DrawRotaGraph(24+X,20+Y,2,0,gra.ico[57],TRUE,0);//武器アイコン

	mes(X+64,Y+12,"？？？？",color.kuro,color.siro,0);

	int ICO;
	std::string str;
	for(int i=0;i<6;i++){
		switch(i){
			case 0:
				str = "ＭＰ"	;ICO = 14;
			break;
			case 1:
				str = "費用"	;ICO = 53;
			break;
			case 2:
				str = "ＢＷ変化"	;ICO = 47;
				break;
			case 3:
				str = "ＢＷ条件"	;ICO = 47;
				break;
			case 4:
				str = "部門ＬＶ"	;ICO = mana[M].icon;
				break;
			case 5:
				str = "累計回数"	;ICO = 15;
			break;
		}
		//名前のとこの枠
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


		//ステータス表示
		if(i==2){//BW変化
			mes_bmf(170+X,52+Y+i*26,"???",2);
		}else if(i==3){
			//BW条件
			mes_bmf(114+X,52+Y+i*26,"???",2);
			mes_bmf(432+X,52+Y+i*26,"???",2);
		}else{
			mes_bmf(170+X,52+Y+i*26,"???",2);
		}
	}
	//基本説明文
	waku(X+10,38+Y+7*26  ,476,90,6);
	mes_i(X+18,Y-18+Y+7*26,"？？？？");

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
	DrawRotaGraph(X+380,Y-20,2,0,gra.ico[57],TRUE,0);//閉じる

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
	//下に説明文、上にアイコン
	for(int i=0,W=1;i<18;i++,W++){
		int IC = data.mode_icon[i+1];

		if( !sys.play_flag[i] ) IC = 57;//

		if(i == N){
			waku_c(X+16+(i%9)*40,Y+16+(i/9)*40,40,40,255,0,0);//枠
		}
		waku(X+18+(i%9)*40,Y+18+(i/9)*40,36,36,6);//枠
		DrawRotaGraph(X+35+(i%9)*40,Y+35+(i/9)*40,2,0,gra.ico[IC],TRUE,0);//アイコン
	}

	waku_c(X+16,Y+106,200,36,255,255,255);//枠

	if(N != -1){
		if( !sys.play_flag[N] ){
			mes(X+20,Y+111,"？？？？",color.kuro,color.siro,1);
		}else{
			mes(X+20,Y+111,data.mode_n[N+1].c_str(),color.kuro,color.siro,1);
		}
	}
	if(Inp.m_x >= X+365 && Inp.m_x <= X+400 && Inp.m_y >= Y-35 && Inp.m_y <= Y-5  && Inp.m_LC==1) data.mode = -2;//キャンセル
	if(Inp.m_RC == 1) data.mode = -2;


	waku_c(X+16,Y+16+130,370,200,255,255,255);


	if(N != -1 && !sys.play_flag[N] ){
		mes_str(X+30,Y+160,"？？？？",color.kuro,color.siro,0);
	}else{
		switch(N){
			case -1:
				mes_str(X+30,Y+160,"モードを選択してください--",color.kuro,color.siro,0);
			break;
			case 0:
				mes_str(X+30,Y+160,"フロンティア開拓において--重大な役割を果たした武器屋--歴史に埋もれ、知られざるその姿は--果たしてどのようなものであったか・・・",color.kuro,color.siro,0);
			break;
			case 1://フリー
				mes_str(X+30,Y+160,"５つの武器屋で一番になろう！",color.kuro,color.siro,0);
			break;
			case 2://ボーナス
				mes_str(X+30,Y+160,"勲章が多いと有利になるよ！",color.kuro,color.siro,0);
			break;
			case 3://資金
				mes_str(X+30,Y+160,"お金をたくさん集めよう！",color.kuro,color.siro,0);
			break;
			case 4://来客
				mes_str(X+30,Y+160,"お客さんを一杯集めよう！",color.kuro,color.siro,0);
			break;
			case 5://株価
				mes_str(X+30,Y+160,"時価総額を上げよう",color.kuro,color.siro,0);
			break;
		}
	}

	return 1;
}
int DRA::select_nanndo(){
	//難易度選択画面

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
	DrawRotaGraph(X+WS-20,Y-20,2,0,gra.ico[57],TRUE,0);//閉じる

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

	//難易度リスト表示
	for(int i=0,W=1;i<4;i++,W++){
		if(N == i) waku_c(X+6,Y+16+i*30,WS-12,32,255,0,0);
		waku(X+8,Y+18+i*30,WS-16,28,6);

		if(sys.nanndo_flag < i ) mes_bmf(X+40,Y+33+i*30,"???",2);
		else					 mes_bmf(X+40,Y+33+i*30,data.nanndo_n[i+1].c_str(),2);

	}

	waku(X+8,Y+16+150,WS-16,90,6);

	if(Inp.m_x >= X+WS-35 && Inp.m_x <= X+WS && Inp.m_y >= Y-35 && Inp.m_y <= Y-5 && Inp.m_LC==1) data.mode = -1;//ひとつ戻る
	if(Inp.m_RC == 1){
		data.mode = -1;
		Inp.m_RC = 0;
	}

	switch(N){
		case -1:
			mes_str(X+30,Y+175,"難易度を選択してください",color.kuro,color.siro,0);
		break;
		case 0:
			mes_str(X+30,Y+175,"ノーマル！--まったり経営しよう",color.kuro,color.siro,0);
		break;
		case 1:
			mes_str(X+30,Y+175,"ハード！--しっかり経営しよう",color.kuro,color.siro,0);
		break;
		case 2:
			mes_str(X+30,Y+175,"マニアック！--シビアに経営しよう",color.kuro,color.siro,0);
		break;
		case 3:
			mes_str(X+30,Y+175,"デスマーチ！--経営理論上可能",color.kuro,color.siro,0);
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
	DrawRotaGraph(X+580,Y-20,2,0,gra.ico[57],TRUE,0);//閉じる

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
		return -2;//ひとつ戻る
	}

	if(Inp.m_RC == 1){
		LD_MODE = 0;
		return -2;
	}

	//読み込みモードor削除モード
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

		if(R == N){//選択中
			waku_c(X+4,Y+34+i*40,560,40,255,0,0);//枠
		}
		waku(X+6,Y+36+i*40,556,36,6);//枠
		//アイコン
		//勢力アイコン
		DrawRotaGraph(X+25,Y+53+i*40,2,0,gra.ico[shop[rabel.list[W].shop].icon],TRUE,0);
		//モードアイコン
		DrawRotaGraph(X+65,Y+53+i*40,2,0,gra.ico[data.mode_icon[rabel.list[W].mode+1]],TRUE,0);
		//モード名
		mes(X+100,Y+40+i*40,data.mode_n[rabel.list[W].mode+1].c_str(),color.kuro,color.siro,0);
		//難易度
		mes_bmf(X+100,Y+65+i*40,data.nanndo_n[rabel.list[W].dif+1].c_str(),1);
		if(rabel.list[W].game_over != -1){
			mes_bmf(X+55,Y+65+i*40,"end",1);
		}

		//日数
		suu_bmf(X+330,Y+55+i*40,2,rabel.list[W].day+1,0);
		mes(X+350,Y+45+i*40,"日目",color.kuro,color.siro,0);
		//プレイ時間
		sprintf_s(str,"%d:%d:%d",rabel.list[W].time/3600%60,rabel.list[W].time/60%60,rabel.list[W].time%60);
		mes(X+450,Y+45+i*40,str,color.kuro,color.siro,0);
	}


	//スクロールバー
	if(rabel.cnt>10){
		waku(X+584,Y,16,440,5);
		int GP = SC*428/max(1,rabel.cnt);
		int GL = min(4280/max(1,rabel.cnt),428);
		DrawBox(X+588,Y+4+GP,X+594,Y+6+GL+GP,color.aka,1);
	}

	if(N != -1 && Inp.m_LC == 1){
		//確認
		if(LD_MODE == 0){
			if(draw.kakunin("--記録の続きから始めますか？",0) == 1){
				return rabel.cnt - 1 - N;
			}
		}else{
			if(draw.kakunin("--記録を削除しますか？",0) == 1){
					if(draw.kakunin("--本当に削除しますか？",0) == 1){
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

int DRA::option(/*オプション画面*/int size,int wide,int full,int bgm,int wav,int vram){
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

	DrawRotaGraph(X+24,Y-20,2,0,gra.ico[79],TRUE,0);//コンフィグ
	waku(X+413,Y-35,30,30,6);
	DrawRotaGraph(X+428,Y-20,2,0,gra.ico[57],TRUE,0);//閉じる

	for(i=0;i<6;i++){
		waku(X+10,Y+10+i*40,200,36,7);
		waku(X+220,Y+10+i*40,200,36,7);
		DrawRotaGraph(X+30,Y+30+i*40,2,0,gra.ico[80+i],TRUE,0);
		DrawRotaGraph(X+240,Y+28+i*40,2,0,gra.ico[58],TRUE,0);
		DrawRotaGraph(X+400,Y+28+i*40,2,0,gra.ico[59],TRUE,0);
	}

	mes(X+50,Y-34,"設定変更",color.siro,color.kuro,1);

	mes(X+60,Y+20,"ウィンドウサイズ",color.kuro,color.siro,0);
	suu_bmf(X+302,Y+30,2,SX,0);
	suu_bmf(X+377,Y+30,2,SY,0);
	mes(X+315,Y+20,"X",color.kuro,color.siro,0);


	mes(X+60,Y+60,"縦横比",color.kuro,color.siro,0);
	if(wide==0) mes(X+300,Y+60," 4:3",color.kuro,color.siro,0);
	else		mes(X+300,Y+60,"16:9",color.kuro,color.siro,0);

	mes(X+60,Y+100,"画面モード",color.kuro,color.siro,0);
	if(full == 0)	mes(X+270,Y+100,"ウィンドウ",color.kuro,color.siro,0);
	else			mes(X+285,Y+100,"ﾌﾙｽｸﾘｰﾝ",color.kuro,color.siro,0);

	mes(X+60,Y+140,"VIDEO RAM",color.kuro,color.siro,0);
	if(vram == 0)	mes(X+270,Y+140,"使用しない※",color.kuro,color.siro,0);
	else			mes(X+280,Y+140,"使用する※",color.kuro,color.siro,0);

	mes(X+60,Y+180,"ＢＧＭ　音量",color.kuro,color.siro,0);
	suu_bmf(X+325,Y+190,2,bgm,0);
	mes(X+345,Y+180,"%",color.kuro,color.siro,0);

	mes(X+60,Y+220,"効果音　音量",color.kuro,color.siro,0);
	suu_bmf(X+325,Y+230,2,wav,0);
	mes(X+345,Y+220,"%",color.kuro,color.siro,0);

	mes(X+20,Y+260,"※次回起動時更新",color.kuro,color.siro,0);
	if(Inp.m_x >= data.window_x/2-215 && Inp.m_x <= data.window_x/2-25  && (Inp.m_y - data.window_y/2 + 150)/40==7 ){
		  waku(X+10,Y+290,200,36,4);
	}else waku(X+10,Y+290,200,36,2);
	if(Inp.m_x >= data.window_x/2-5   && Inp.m_x <= data.window_x/2+185 && (Inp.m_y - data.window_y/2 + 150)/40==7 ){
		  waku(X+220,Y+290,200,36,4);
	}else waku(X+220,Y+290,200,36,2);
	
	
	mes(X+90,Y+300,"ＯＫ",color.kuro,color.siro,0);
	mes(X+280,Y+300,"キャンセル",color.kuro,color.siro,0);
	return 1;
}
int DRA::tutorial_menu(){

	int X,Y,N = 0;

	X = data.window_x/2-300;
	Y = data.window_y/2-240;

	waku(X,Y-40,600,40,5);
	waku(X,Y,600,500,3);

	DrawRotaGraph(X+24,Y-20,2,0,gra.ico[89],TRUE,0);//説明
	waku(X+563,Y-35,30,30,6);
	DrawRotaGraph(X+578,Y-20,2,0,gra.ico[57],TRUE,0);//閉じる

	mes(X+50,Y-34,"ヘルプ",color.siro,color.kuro,1);
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
				case  0:mes(X+30+i/10*300,Y+30+i%10*36,"はじめに",color.kuro,color.siro,1);break;
				case  1:mes(X+30+i/10*300,Y+30+i%10*36,"つるはし",color.kuro,color.siro,1);break;
				case  2:mes(X+30+i/10*300,Y+30+i%10*36,"店員、客と接客",color.kuro,color.siro,1);break;
				case  3:mes(X+30+i/10*300,Y+30+i%10*36,"職人、武器開発・改良",color.kuro,color.siro,1);break;
				case  4:mes(X+30+i/10*300,Y+30+i%10*36,"従業員の雇用",color.kuro,color.siro,1);break;
				case  5:mes(X+30+i/10*300,Y+30+i%10*36,"ハンターについて",color.kuro,color.siro,1);break;
				case  6:mes(X+30+i/10*300,Y+30+i%10*36,"ログとイベント",color.kuro,color.siro,1);break;
				case  7:mes(X+30+i/10*300,Y+30+i%10*36,"月末・税金・納品",color.kuro,color.siro,1);break;
				case  8:mes(X+30+i/10*300,Y+30+i%10*36,"ブラック度",color.kuro,color.siro,1);break;
				case  9:mes(X+30+i/10*300,Y+30+i%10*36,"ライバル店",color.kuro,color.siro,1);break;

				case 10:mes(X+30+i/10*300,Y+30+i%10*36,"経営戦術",color.kuro,color.siro,1);break;
				case 11:mes(X+30+i/10*300,Y+30+i%10*36,"財務部",color.kuro,color.siro,1);break;
				case 12:mes(X+30+i/10*300,Y+30+i%10*36,"工事部",color.kuro,color.siro,1);break;
				case 13:mes(X+30+i/10*300,Y+30+i%10*36,"開発部",color.kuro,color.siro,1);break;
				case 14:mes(X+30+i/10*300,Y+30+i%10*36,"宣伝部",color.kuro,color.siro,1);break;
				case 15:mes(X+30+i/10*300,Y+30+i%10*36,"祭り",color.kuro,color.siro,1);break;
				case 16:mes(X+30+i/10*300,Y+30+i%10*36,"フリーモード",color.kuro,color.siro,1);break;
				case 17:mes(X+30+i/10*300,Y+30+i%10*36,"ゲームオーバー",color.kuro,color.siro,1);break;
				case 18:mes(X+30+i/10*300,Y+30+i%10*36,"タイトル画面",color.kuro,color.siro,1);break;
				case 19:mes(X+30+i/10*300,Y+30+i%10*36,"提供",color.kuro,color.siro,1);break;
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
		//描画
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
			mes(X+80,YA+5,"ＯＫ",color.kuro,color.siro,0);
			mes(X+210,YA+5,"キャンセル",color.kuro,color.siro,0);
		}else{
			waku(X+100,YA,150,30,10);

			if(Inp.m_y >= YA && Inp.m_y <= YA+30 && Inp.m_x >= X+100 && Inp.m_x <= X+250){
					waku(X+100,YA,150,30,2);
					if(Inp.m_LC == 1) return 1;
			}
			mes(X+150,YA+5,"ＯＫ",color.kuro,color.siro,0);
		}

		ScreenFlip();

		if(fun.err_c()== -1) return -1;
	}

	return 0;
}

int DRA::winning_mode(){//勝利条件ウィンドウ
	//破産もここから


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
			//見つかった場合
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
			//見つかった場合
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

	//説明

	if(data.game_over / 100 == P){//自店勝利
		DrawExtendGraph(X + 10, Y + 10, X + 590, Y + 340, gra.back[9], false);

		waku(X + 10, Y + 350, 576, 60, 2);
		
		mes_bmf(X + 100, Y + 160, "Congratulations!!!", 4);


		switch(data.game_over%100){
			case 0://客数
				mes_str(X+20,Y+358,"客数による勝利--",color.kuro,color.siro,0);
			break;
			case 1://株価
				mes_str(X+20,Y+358,"株価による勝利--",color.kuro,color.siro,0);
			break;
			case 2://総売り上げ
				mes_str(X+20,Y+358,"総売上による勝利--",color.kuro,color.siro,0);
			break;
			case 3://剣売り上げ
				mes_str(X+20,Y+358,"剣売上による勝利--",color.kuro,color.siro,0);
			break;
			case 4://槍売り上げ
				mes_str(X+20,Y+358,"槍売上による勝利--",color.kuro,color.siro,0);
			break;
			case 5://斧売り上げ
				mes_str(X+20,Y+358,"斧売上による勝利--",color.kuro,color.siro,0);
			break;
			case 6://弓売り上げ
				mes_str(X+20,Y+358,"弓売上による勝利--",color.kuro,color.siro,0);
			break;
			case 7://つるはし
				mes_str(X+20,Y+358,"つるはし製造による勝利--",color.kuro,color.siro,0);
			break;
			case 8://開発
				mes_str(X+20,Y+358,"武器開発による勝利--",color.kuro,color.siro,0);
			break;
			case 9://資金
				mes_str(X+20,Y+358,"資金による勝利--",color.kuro,color.siro,0);
			break;
			case 10://大会
				mes_str(X+20,Y+358,"祭り戦績による勝利--",color.kuro,color.siro,0);
			break;
			case 11://ボス
				mes_str(X+20,Y+358,"ダンジョン制覇による勝利--",color.kuro,color.siro,0);
			break;
			case 12://破産
				mes_str(X+20,Y+358,"倒産による敗北--",color.kuro,color.siro,0);
			break;
		}
	}else{//他店勝利
		DrawExtendGraph(X + 10, Y + 10, X + 590, Y + 340, gra.back[8], false);
		waku(X + 10, Y + 350, 576, 60, 2);
		mes_bmf(X + 100, Y + 160, "   you defeat    ", 4);

		switch (data.game_over % 100){
			case 0://客数
				mes_str(X+20,Y+358,"客数による敗北--",color.kuro,color.siro,0);
			break;
			case 1://株価
				mes_str(X+20,Y+358,"株価による敗北--",color.kuro,color.siro,0);
			break;
			case 2://総売り上げ
				mes_str(X+20,Y+358,"総売上による敗北--",color.kuro,color.siro,0);
			break;
			case 3://剣売り上げ
				mes_str(X+20,Y+358,"剣売上による敗北--",color.kuro,color.siro,0);
			break;
			case 4://槍売り上げ
				mes_str(X+20,Y+358,"売上による敗北--",color.kuro,color.siro,0);
			break;
			case 5://斧売り上げ
				mes_str(X+20,Y+358,"売上による敗北--",color.kuro,color.siro,0);
			break;
			case 6://弓売り上げ
				mes_str(X+20,Y+358,"売上による敗北--",color.kuro,color.siro,0);
			break;
			case 7://つるはし
				mes_str(X+20,Y+358,"つるはし製造による敗北--",color.kuro,color.siro,0);
			break;
			case 8://開発
				mes_str(X+20,Y+358,"武器開発による敗北--",color.kuro,color.siro,0);
			break;
			case 9://資金
				mes_str(X+20,Y+358,"資金による敗北--",color.kuro,color.siro,0);
			break;
			case 10://大会
				mes_str(X+20,Y+358,"祭り戦績による敗北--",color.kuro,color.siro,0);
			break;
			case 11://ボス
				mes_str(X+20,Y+358,"ダンジョン制覇による敗北--",color.kuro,color.siro,0);
			break;
		}
	}
	
	//タイトルor終了
	waku(X+90,Y+416,200,34,8);

	if(Inp.m_x > X+90 && Inp.m_x < X+290 && Inp.m_y > Y+416 && Inp.m_y < Y+460){
		mes(X+120,Y+422,"タイトルへ戻る",GetColor(255,150,150),GetColor(255,0,0),0);
		if(Inp.m_LC == 1) return 1;
	}else{
		mes(X+120,Y+422,"タイトルへ戻る",color.siro,color.kuro,0);
	}

	waku(X+310,Y+416,200,34,8);
	if(Inp.m_x > X+310 && Inp.m_x < X+510 && Inp.m_y > Y+416 && Inp.m_y < Y+460){
		mes(X+350,Y+422,"まだ戻らない",GetColor(255,150,150),GetColor(255,0,0),0);
		if(Inp.m_LC == 1) return 2;
	}else{
		mes(X+350,Y+422,"まだ戻らない",color.siro,color.kuro,0);
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
		//背景塗りつぶし
		DrawBox(0,0,data.window_x  ,data.window_y,GetColor(0,0,0),1);

		mes_bmf2( 50 , 10 + add_y , "Flontier Black Smith" , 4 );
		//登場人物
		mes_bmf2( 100 , 200 + add_y , "Character" , 4 );
		
		mes_bmf2( 130 , 250 + add_y , "ceo" , 4 );
		DrawRotaGraph( 100 , 250 + add_y , 2 , 0 , gra.unit[0][1] , true );

		//終わり
		mes_bmf2( 100 , 500 + add_y , "To be continued" , 4 );
		
		if(count == 1000 + data.window_y) break;

		//右に場面
		SetDrawBlendMode( DX_BLENDMODE_ALPHA , alpha ) ;
		DrawRotaGraph(data.window_x*3/4,data.window_y/2,1,0,gra.shop[0],0,0);
		SetDrawBlendMode( DX_BLENDMODE_NOBLEND , 0 ) ;
		if(fun.err_c()== -1) break;
		ScreenFlip();
	}

	return 1;
}


//銃器開発　弓×４
//刀　　　　剣3槍１
//爆発物	剣1
//骨		斧
//角		槍
//羽		弓
//剣4槍2斧1弓7

//閃光184　剣　42つエクスカリバー
//閃光185　槍 142つゲイボルグ
//閃光186　斧 246つミョルニル
//閃光187　弓 346つあずさ弓
//さらなるつよさ　 258	- 剣グラム　58
//さらなるオシャレ 259	- 槍サイズ 130
//さらなるコスパ　 260	- 斧こんぼう 286

//124～132のは使用回数もみて判定

//厨房124	- 包丁38　フライパン258
//ごらく128 - スリング386 ピコハン 270
//礼拝堂130 - 天使378 or　悪魔382
//温泉132　 - 竹槍186
//剣1槍1斧2弓3

//内装125	- オシャレ　剣53
//工房123　	- コスパ　剣74
//研究126	- つよさ　槍190
//レジ127	- コスパ　槍174
//看板129	- オシャレ　斧262
//資料131	- つよさ　斧250
//社長133	- 396黄金銃

//剣9槍7斧7弓11