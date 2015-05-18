#include "eve_sub.h"
#include "btb.h"
#include "btb_ai.h"
#include "btb_draw.h"
#include "btb_emp.h"
#include "btb_func.h"
#include "btb_eve.h"
#include "btb_hun.h"
#include "btb_mana.h"
#include "btb_shop.h"
#include "btb_tutolial.h"
//todo
//イベントの再編
//祭り削除済み、チュートリアルの一覧からも消す、ファイル名の変更
//○各モード開始時のイベントを削除
//
//
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	// 実行ファイルのフルパス取得
	char szPath[_MAX_PATH];
	GetModuleFileName( NULL, szPath, MAX_PATH);
	// フルパスを分解
	char szDrive[_MAX_DRIVE];
	char szFName[_MAX_FNAME];
	char szExt[_MAX_EXT];
	_splitpath_s(szPath,szDrive,data.szDir,szFName,szExt);

	SetCurrentDirectory(data.szDir);

	DxLib::SetUseDirectInputFlag( false );

	fun.sys_load();

	SetMainWindowText( "Frontier Black Smith Preview 1.04" ) ;
	SetDoubleStartValidFlag( TRUE );//多重起動禁止
	SetAlwaysRunFlag(TRUE);//常にアクティブ
	
	int mx = GetSystemMetrics(SM_CXSCREEN);
	int my = GetSystemMetrics(SM_CYSCREEN);

	if(opt.full_scr == 1){//フルスクリーン
		data.window_x = mx;
		data.window_y = my;
	}else{
		data.window_x = min(opt.window_x , mx);
		data.window_y = min(opt.window_y , my);
	}
	
	if(data.window_x / 4 == data.window_y /3) data.wide = 0;
	else									  data.wide = 1;

	SetGraphMode( data.window_x , data.window_y , 16 ) ;//グラフィックモード&解像度決定
	ChangeWindowMode( TRUE ) ;//ウィンドウモードに変更

	SetScreenMemToVramFlag( opt.v_ram ) ;//Ｖラムを使用しない
	SetOutApplicationLogValidFlag( FALSE ) ;//ログ出力しない
	if( DxLib_Init() == -1 )return -1 ;//ＤＸライブラリ初期化処理 エラーが起きたら直ちに終了
	SetDrawScreen( DX_SCREEN_BACK ) ;//描写先を裏画面に設定
	SetMouseDispFlag( 1 ) ;//マウスカーソル表示する

	SetTransColor( 190 , 179 , 145 ) ;// 透過色を変更

	fun.main();//メイン関数

	fun.sys_save();

	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0;
}