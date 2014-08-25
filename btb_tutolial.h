#pragma once
int DRA::tutorial_00(int PA,int N/*客情報*/){
	 
	int X = data.window_x/2-480;
	int Y = data.window_y/2-350;
	char str[200];

	SetCurrentDirectory(data.szDir);
	sprintf_s(str,200,"File/tutorial/%d%d/スライド%d.PNG",N/10,N%10,PA);
	
	SetDrawArea(X,Y,X+960,Y+700);
	DrawBox(X,Y,X+960,Y+680,color.kuro,true);
	LoadGraphScreen( X,Y , str , TRUE );
	SetDrawArea(0,0,data.window_x,data.window_y);

	switch(N){
		case   0:return 7;//はじめに-●
		case   1:return 2;//つるはし-●
		case   2:return 6;//店員-●
		case   3:return 5;//職人-●
		case   4:return 4;//雇用-●
		case   5:return 4;//ハンター-●
		case   6:return 2;//ログ-●
		case   7:return 5;//月末-●
		case   8:return 3;//ブラック度-●
		case   9:return 5;//ライバル店-●
		case  10:return 6;//経営部-●
		case  11:return 3;//財務部-●
		case  12:return 3;//工事部-●
		case  13:return 3;//開発部-●
		case  14:return 4;//宣伝部-●
		case  15:return 2;//祭り-21●
		case  16:return 5;//フリーモード-●
		case  17:return 5;//タイトル画面●
		case  18:return 1;//ゲームオーバー●
		case  19:return 1;//提供●
	}


	return 1;//ページ数を返す
}