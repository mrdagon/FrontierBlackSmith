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
//�C�x���g�̍ĕ�
//�Ղ�폜�ς݁A�`���[�g���A���̈ꗗ����������A�t�@�C�����̕ύX
//���e���[�h�J�n���̃C�x���g���폜
//
//
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	// ���s�t�@�C���̃t���p�X�擾
	char szPath[_MAX_PATH];
	GetModuleFileName( NULL, szPath, MAX_PATH);
	// �t���p�X�𕪉�
	char szDrive[_MAX_DRIVE];
	char szFName[_MAX_FNAME];
	char szExt[_MAX_EXT];
	_splitpath_s(szPath,szDrive,data.szDir,szFName,szExt);

	SetCurrentDirectory(data.szDir);

	DxLib::SetUseDirectInputFlag( false );

	fun.sys_load();

	SetMainWindowText( "Frontier Black Smith Preview 1.04" ) ;
	SetDoubleStartValidFlag( TRUE );//���d�N���֎~
	SetAlwaysRunFlag(TRUE);//��ɃA�N�e�B�u
	
	int mx = GetSystemMetrics(SM_CXSCREEN);
	int my = GetSystemMetrics(SM_CYSCREEN);

	if(opt.full_scr == 1){//�t���X�N���[��
		data.window_x = mx;
		data.window_y = my;
	}else{
		data.window_x = min(opt.window_x , mx);
		data.window_y = min(opt.window_y , my);
	}
	
	if(data.window_x / 4 == data.window_y /3) data.wide = 0;
	else									  data.wide = 1;

	SetGraphMode( data.window_x , data.window_y , 16 ) ;//�O���t�B�b�N���[�h&�𑜓x����
	ChangeWindowMode( TRUE ) ;//�E�B���h�E���[�h�ɕύX

	SetScreenMemToVramFlag( opt.v_ram ) ;//�u�������g�p���Ȃ�
	SetOutApplicationLogValidFlag( FALSE ) ;//���O�o�͂��Ȃ�
	if( DxLib_Init() == -1 )return -1 ;//�c�w���C�u�������������� �G���[���N�����璼���ɏI��
	SetDrawScreen( DX_SCREEN_BACK ) ;//�`�ʐ�𗠉�ʂɐݒ�
	SetMouseDispFlag( 1 ) ;//�}�E�X�J�[�\���\������

	SetTransColor( 190 , 179 , 145 ) ;// ���ߐF��ύX

	fun.main();//���C���֐�

	fun.sys_save();

	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0;
}