#pragma once
int DRA::tutorial_00(int PA,int N/*�q���*/){
	 
	int X = data.window_x/2-480;
	int Y = data.window_y/2-350;
	char str[200];

	SetCurrentDirectory(data.szDir);
	sprintf_s(str,200,"File/tutorial/%d%d/�X���C�h%d.PNG",N/10,N%10,PA);
	
	SetDrawArea(X,Y,X+960,Y+700);
	DrawBox(X,Y,X+960,Y+680,color.kuro,true);
	LoadGraphScreen( X,Y , str , TRUE );
	SetDrawArea(0,0,data.window_x,data.window_y);

	switch(N){
		case   0:return 7;//�͂��߂�-��
		case   1:return 2;//��͂�-��
		case   2:return 6;//�X��-��
		case   3:return 5;//�E�l-��
		case   4:return 4;//�ٗp-��
		case   5:return 4;//�n���^�[-��
		case   6:return 2;//���O-��
		case   7:return 5;//����-��
		case   8:return 3;//�u���b�N�x-��
		case   9:return 5;//���C�o���X-��
		case  10:return 6;//�o�c��-��
		case  11:return 3;//������-��
		case  12:return 3;//�H����-��
		case  13:return 3;//�J����-��
		case  14:return 4;//��`��-��
		case  15:return 2;//�Ղ�-21��
		case  16:return 5;//�t���[���[�h-��
		case  17:return 5;//�^�C�g����ʁ�
		case  18:return 1;//�Q�[���I�[�o�[��
		case  19:return 1;//�񋟁�
	}


	return 1;//�y�[�W����Ԃ�
}