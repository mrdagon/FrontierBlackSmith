#include "eve_sub.h"

#define NEXT break;case
#define START int L=0;if(GetLine() == 0){
#define TO	  }L++;if(GetLine()==L){
#define END   TO SetEnd();}

extern ACTER act[32];

extern int GetLine();
extern void SetEnd();
extern int BackChenge(EStage esta , int T=1);

void EVE_SUB::Switch(int E)
{
	switch(E)
	{
		//0~19 �e���[�h�C���g��
		case  0:����_�V�i���I();break;
		case  1:����_���R�o��();break;
		case  2:����_���_���̉�();;break;
		case  3:����_�q����`();;break;
		case  4:����_��q����();;break;
		case  5:����_������Ă�();;break;
		case  6:����_�V�F�ANo1();;break;
		case  7:����_��͂���D��();break;
		case  8:����_�J��őO��();break;
		case  9:����_���o�̕�();break;
		case 10:����_���ɂ̑�();break;
		case 11:����_�����̌�();break;
		case 12:����_�����̋|();break;
		case 13:����_�E�F�|���}�C�X�^�[();break;
		case 14:����_�A�C�X�G�C�W();break;
		case 15:����_�M������();break;
		case 16:����_��n���^�[����();break;
		case 17:����_����̏I���();break;
		case 18:;break;
		case 19:;break;
		case 20:;break;
		//�Ղ�C�x���g
		case 21:���퉮�Ղ�();break;//�v
		case 22:���퉮�Ղ�();break;//���퉮�Ղ�
		//�V�i���I���[�h�C�x���g
	
		//1�N��1��
		case 23:�J�X();break;//1��
		case 24:��͂������J�n();break;//4��
		case 25:�c�Ƌ���A();break;//8��
		case 26:�c�Ƌ���B();break;//9��
		//case 27:�V�����();break;//�v�C�x���g
		case 28:�������();break;//13��
		case 29:�ŋ��̃n���^�[(); break;//20��
		case 30:�l�ޕ�W�J�n();break;//26��
		case 31:�g�E�c�O�̗p();break;//27��
		case 32:�����t�@�̗p();break;//28��

		//1�N��2��
		case 34:�o�c�񃖌���(); break;//1��
		case 33:��͂��[�i(); break;//3��
		case 35:�o�c�̃X�X��();break;//10��
		case 37:�H���̃X�X��();break;//22��
		case 38:���b�̎���();break;//17��
		//case 39:�V�����2();break;//�v

		//1�N��3��
		case 40:�o�c�O������();break;//1��
		case 36:�X�^�C�g���@(); break;//2��
		case 41:�����t�@�̌Z(); break;//7��
		//case 42:�V�G�z�̗p(); break;//�v
		//case 43:�����̃X�X��();break;//�v
		case 44:����������();break;//12��
		case 45:�w�����X�̗p();break;//17��
		case 46:�J���̃X�X��();break;//19��
		case 47:�J�m���H�[();break;//23��
		case 48:�����v��();break;//28��

		//1�N��4��
		//case 49:�n���^�[����();break;//�v
		case 50:��`�̃X�X��();break;//12��
		//case 51:����̈����O�l�O();break;//�v

		//1�N��5��
		case 52:�z���C�g�i�C�g(); break;//1��
		//case 53:�l�l�g�̃n���^�[();break;//�v

		//1�N��6��
		case 54:���퉮�Ղ�z��();break;//1��
		case 55:�������s();break;//12��

		//1�N��7��
		case 56:�Ɍ��b��();break;//1��
		//case 57:�g�E�c�O�ƋɌ�();break;//�v
		case 58:���퉮�Ղ�J��();break;//14��
		//case 59:��͂��Ղ�z��();break;//�v

		//1�N��8��
		case 60:�h���S���̓�();break;//3��

		//���C���V�i���I 9
		//case 61:��͂��Ղ�J��();break;//�v
		case 62:�J���();break;//8��
		case 63:�S�����m�X�̉\(); break;//14��
		//1�N��9��
		case 64:�S�����m�X�o�X();break;//1��
		case 65:�����t�@�Z���H();break;//28��
		default:
			SetEnd();
		break;
	}
}

void EVE_SUB::����_�V�i���I()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			BackChenge(EStage::����);
			act[0].Move(0,-6,2);
	TO
			act[0].Move(0.5,0,2);
	TO
			act[0].Mes("Hello world!");
			act[0].Direct(DI::��);
	TO
			act[0].Emo(EM::�v�l);
	TO
			act[0].Emo(EM::�^��);
	TO
			act[0].Mes("�悤�����A���E��!");
	TO
			act[0].Emo(EM::����);
	TO
			act[0].Mes("�����Ɛ����̎��ɂ��A���Ō��������헐�̎���͖������");
	TO
			act[0].Mes("���̎���A���̒����Ăщ��������");
	TO
			act[0].Mes("���͐�̖@�͒m��Ȃ��������A���𑀂�p�ɒ�����");
	TO
			act[0].Mes("�@�͕ω����A�����͂ł���������͏I�����a���K���");
	TO
			act[0].Mes("���āA�키�͖������͓z��ł�����");
	TO
			act[0].Mes("�����āA�x�ݖ������͂��̎���ɂ����Ă��z��ƂȂ�");
	TO
			act[0].Emo(EM::�v�l);
	TO
			act[0].Mes("����̕���͑嗤�����t�����e�B�A");
	TO
			act[0].Mes("�암�y�ѐ������x�z���Ɏ��߂����{�͓����J��ɒ��肷��");
	TO
			act[0].Mes("�������J��͈�N�ڂɂ��ēڍ�����");
	TO
			act[0].Mes("��t�����ł����������n���͓Ǝ��̐��Ԍn��L���Ă��聗���̒n��ɂ͌����Ȃ����b�����݂��Ă���");
	TO
			act[0].Mes("���b�͎���̃e���g���[��Ƃ��l�Ԃ���炢�A�����P����");
	TO
			act[0].Mes("�����̊J��҂��]���ɂȂ�Ȃ�����A�J��͒x�X�Ƃ��Đi�܂������Ԃ������߂��Ă���");
	TO
			act[0].Mes("�������A����҂ɂ�薂�b�������Ƃ��Ċ��p������@�𔭌������");
	TO
			act[0].Mes("����ɁA�����n���ł͖��b�̖є��p�A��A�������̎��W�����s�肾��");
	TO
			act[0].Mes("���낵�����b�̉�͋��Ɠ����A�������̓��͕�Έȏ�̉��l������");			
	TO
			act[0].Mes("�l�X�͑���𓾂邽�߁A�������ɓ����t�����e�B�A�֗�����");
	TO
			act[0].Mes("�l�͖��m�炸�̔ނ���n���^�[�ƌĂ�");
	TO
			act[0].Mes("����͖��b��̗��s���n�܂鏭���O����n�܂�");
	TO
			act[0].Mes("��l���͈ꝺ����𖲂ɓ����n���ւ���Ă�����l�̐l��");
	TO
			act[0].Mes("�n���^�[�ł͖���");
	TO
			act[0].Mes("���퉮�ł�����");
	END
}
void EVE_SUB::����_���R�o��()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_���_���̉�()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_�q����`()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_��q����()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_������Ă�()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_�V�F�ANo1()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_��͂���D��()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_�J��őO��()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_���o�̕�()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_���ɂ̑�()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_�����̌�()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_�����̋|()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_�E�F�|���}�C�X�^�[()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_�A�C�X�G�C�W()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_�M������()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_��n���^�[����()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::����_����̏I���()
{
	START
			act[0].Set(EChara::��蕔,6,10,DI::��);
			act[0].Move(0,-6,2);
			BackChenge(EStage::����);
	END
}
void EVE_SUB::��͂��Ղ�()
{
	static int point[5];//�e�X�̓��_
	//�N�P��
	//�v
	START
		act[0].Set(EChara::�i��,6,10,DI::��);
		BackChenge(EStage::�L��);
	END
}
void EVE_SUB::���퉮�Ղ�()
{
	//�N�P��
	START
		act[0].Set(EChara::�i��,8,5,DI::��);

		act[3].Set(EChara::�����t�@, 6, 7, DI::��);
		act[4].Set(EChara::���m, 7, 7, DI::��);

		act[6].Set(EChara::���m, 9, 7, DI::��);
		act[7].Set(EChara::�^�N�~, 11, 7, DI::��);

		act[8].Set(EChara::�g�E�c�O, 4, 8, DI::��);
		act[9].Set(EChara::���m, 5, 8, DI::��);
		act[10].Set(EChara::�t�@�C, 7, 8, DI::��);
		act[11].Set(EChara::���f�B, 8, 8, DI::��);
		act[12].Set(EChara::�p���R, 9, 8, DI::��);
		act[13].Set(EChara::�����W, 10, 8, DI::��);

		act[14].Set(EChara::���m, 5, 9, DI::��);
		act[15].Set(EChara::��蕔, 6, 9, DI::��);
		act[16].Set(EChara::�w�����X, 7, 9, DI::��);
		act[17].Set(EChara::���m, 9, 9, DI::��);
		act[18].Set(EChara::�t�@�N�g, 10, 9, DI::��);
		act[19].Set(EChara::���m, 11, 9, DI::��);

		act[20].Set(EChara::���m, 4, 10, DI::��);
		act[21].Set(EChara::�W���C�`, 5, 10, DI::��);
		act[22].Set(EChara::�P���q��, 6, 10, DI::��);
		act[23].Set(EChara::���m, 8, 10, DI::��);
		act[24].Set(EChara::���m, 9, 10, DI::��);

		BackChenge(EStage::�L��);
	TO
		act[0].Mes("����ł͕��퉮�R���e�X�g���ʔ��\�ł��I");
	TO
		act[0].Mes("�R�����ƈ�ʓ��[�ɂ��W�v�̌��ʁ������镐�퉮�̒�����h���ɋP���͈̂�́I");
	TO
		act[0].Mes("�h������D���X�́E�E�E");
	TO
		act[0].E�v�l();
	TO
		switch (EVE_SUB::Contest())
		{
		case 0:
			act[0].Mes("�t�����e�B�A�X�~�X�ł��I");
			act[1].Set(EChara::�Z�I, -1, 5, DI::�E);
			break;
		case 1:
			act[0].Mes("�J�m���H�[�ł��I");
			act[1].Set(EChara::�J�m��, -1, 5, DI::�E);
			break;
		case 2:
			act[0].Mes("�z���C�g�i�C�g�ł��I");
			act[1].Set(EChara::�u����, -1, 5, DI::�E);
			break;
		case 3:
			act[0].Mes("�Ɍ����b��ł��I");
			act[1].Set(EChara::�q�g�t���T�C, -1, 5, DI::�E);
			break;
		case 4:
			act[0].Mes("�S�����m�X�E�E�F�|���Y�ł��I");
			act[1].Set(EChara::�J�N�V��, -1, 5, DI::�E);
			break;
		}
		act[0].Left();
		act[1].Move(8,0);
	TO
		act[0].Down();
		act[1].Down();
		act[0].Mes("�D�����߂łƂ��I");
	TO
		act[1].E����();
	TO
		act[1].Mes("���肪�Ƃ��I");
	TO
		act[0].Mes("�ł͂܂�����̃R���e�X�g�ŉ���I");
	END
}
//���C���V�i���I 1
void EVE_SUB::�J�X()
{
	//��������t�����e�B�A�Ɉږ����Ă����A�Z�I�ƃt�@�N�g�B
	//�J�m���H�[�̐l�ɍH�����ĖႢ�܂���
	//������Ƃ����|��������A�Q�[���J�n

	START
		act[0].Set(EChara::�Z�I,-1,8,DI::�� , false);		
		act[1].Set(EChara::�t�@�N�g,7,7,DI::�� , true);
		act[2].Set(EChara::�^�N�~,8,7,DI::�� , true);			
		BackChenge(EStage::�X�O);
	TO
		act[0].Move(9,0,3);
	TO
		act[2].Mes("���͂悤�A�В�����");
		act[0].Direct(DI::��);
	TO
		act[0].Mes("���ꂪ���̓X��");
	TO
		act[2].Mes("�ǂ������C�ɓ����������H");
	TO
		act[0].Emo(EM::�v�l);
	TO
		act[1].Emo(EM::�{��);
	TO
		act[1].Mes("�\�Z�������񂾁A�V���{�C�͎̂d���Ȃ�����I");
	TO
		act[1].Mes("����ł�����Ȃ����͖l���H������`�����񂾂�I");
	TO
		act[0].Emo(EM::����);
	TO
		act[0].Mes("���������ĂȂ��񂾂��E�E�E");
	TO
		act[1].Mes("");
		act[0].Emo(EM::�v�l);
	TO
		act[0].Mes("�܂��A�m���ɃV���{�C��������񂪁����ꂩ��҂��Ō��đւ���Ⴂ��");
	TO
		act[0].Mes("���̎��͂܂����ނ�A�e��");
	TO
		act[2].Emo(EM::����);
	TO
		act[2].Mes("���x�͌��������ŗ��ނ�");
	TO
		act[0].Emo(EM::����);
		act[1].Emo(EM::����);
	END
}
void EVE_SUB::��͂������J�n()
{
	//�X�����Ă����A���������c�Ƌ����o�Ă��Ȃ�
	//�����ɋ������ɍs�����ۂɁA���łɂ�͂������̎d�����󒍂��鎖��
	START
		act[0].Set(EChara::�Z�I,2,2,DI::��);
		act[1].Set(EChara::�t�@�N�g,7,4,DI::��,false);
		BackChenge(EStage::�X��);
	TO
		act[0].Move(0, 2, 4);
	TO
		act[0].Move(4, 0, 4);
	TO
		act[0].Mes("�߂������A�X�Ԃ���J");
	TO
		act[0].Mes("");
		act[1].E����();
	TO
		act[1].E�v�l();
	TO
		act[1].Mes("�ӂ��`���E�E�E");
	TO
		act[1].Direct(DI::��);
		act[1].Mes("��������");
	TO
		act[1].Mes("�Ƃ���ŉ��̗p���������́H");
	TO
		act[0].Mes("�����ɉc�Ƌ���\�����Ă���");
	TO
		act[0].Mes("����𔄂�ƂȂ�ƁA�R�����o�^��炪���邩���");
	TO
		act[1].Mes("�ƌ������͂܂��c�Ƃ��ĂȂ������̂�");
	TO
		act[1].Mes("�X�Ԃ���K�v�������́H");
	TO
		act[0].E�v�l();
		act[1].E�v�l();
	TO
		act[0].Mes("����͂���Ƃ��Ė�����A�S���҂����@�ɗ��邻����");
	TO
		act[0].Mes("���ƁA���������͂�������Ă���");
	TO
		act[1].Mes("��͂��H");
	TO
		act[0].Mes("�z�R���@��̂Ɏg���A����");
	TO
		act[1].Mes("����͒m���Ă�恗����𔄂�񂶂�H");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("���킾���������͂��������������ׂ��邩���");
	TO
		act[0].Mes("���̌��Ńn���^�[��������̂��A���������悾������܂łɓX���ׂꂿ�።��");
	TO
		act[1].Mes("�����������̉\���Ė{���Ȃ́H");
	TO
		act[1].Mes("");
		act[0].E����();
	TO
		act[0].Mes("�����������ƂɊԈႢ�͖����I");
	TO
		act[1].Direct(DI::��);
		act[1].Mes("�܂��A���X�����Ă��d���������E�E�E");
	TO
		act[0].Mes("���Ⴀ�A��͂������܂�������");
	END
}
void EVE_SUB::�c�Ƌ���A()
{
	//��������̎��@�ɗ����n���t�@�h
	//���َq��n������
	START
		act[0].Set(EChara::�Z�I,8, 6, DI::��);
		act[1].Set(EChara::�n���t�@�h, 7.5, 11, DI::�� );
		act[1].HukiUp(false);
		act[2].Set(EChara::���m,6.5, 12, DI::��);
		act[3].Set(EChara::���m, 8.5, 12, DI::��);
		act[4].Set(EChara::�t�@�N�g, 7, 6, DI::��);
		BackChenge(EStage::�X��);
	TO
		act[1].Move(0, -4, 2);
		act[2].Move(0, -4, 2);
		act[3].Move(0, -4, 2);
	TO
		act[1].Mes("���͂悤");
	TO
		act[0].Mes("���͂悤�������܂��I");
	TO
		act[1].Mes("���̎��̃n���t�@�h���A��낵���B");
	TO
		act[1].Left();
		act[1].Mes("�N�����퉮���n�߂������Đl�H");
		act[0].Mes("");
		act[4].Mes("");
	TO
		act[0].Mes("�����В��̃Z�I�ł��I");
	TO
		act[1].Up();
		act[1].E�v�l();
	TO
		act[0].Mes("�ǂ������܂������H");
	TO
		act[1].Mes("�ւ��N���E�E�E�H");
	TO
		act[1].Mes("�܂��������������R�����n�߂悤���ˁA�H�[�͂ǂ����ˁH");
	TO
		act[0].Mes("������ł�");
	TO
		act[0].Move(-1, 0, 4);
		act[4].Move(-1, 0, 4);
	TO
		act[0].Move(-1, 0, 4);
		act[1].Move(-1, 0, 4);
		act[4].Move(-1, 0, 4);
	TO
		act[0].Set(EChara::�Z�I, 8, 6, DI::��);
		act[1].Set(EChara::�n���t�@�h, 7.5, 7, DI::��);
		act[1].HukiUp(false);
		act[2].Set(EChara::���m, 6.5, 8, DI::��);
		act[3].Set(EChara::���m, 8.5, 8, DI::��);
		act[4].Set(EChara::�t�@�N�g, 7, 6, DI::��);
		BackChenge(EStage::�X��);
	TO
		act[1].Mes("����Ŏ��@�͏I��肩��");
	TO
		act[0].Mes("���肪�Ƃ��������܂����B");
	TO
		act[1].Mes("��̖�薳�������ł͂���");
	TO
		act[1].Mes("�������A���퉮�̔F�͐T�d�ɂ���K�v�����邩�炵��");
	TO
		act[1].Right();
		act[1].Mes("���[���E�E�E");
	TO
		act[1].Mes("�Ȃ񂾂��A���َq�ł��H�ׂ����Ȃ��Ă����Ȃ��E�E�E");
	TO
		act[0].Mes("���َq�ł����H");
	TO
		act[1].Mes("����`�A���������ĊÂ����ɂ͖ڂ������Ă˂��E�E�E�H");
	TO
		act[0].E�v�l();
		act[1].E�v�l();
	TO
		act[0].Mes("���X���҂���");
	TO
		act[0].Move(10, 0, 4);
	TO
		act[0].Move(-10, 0, 4);
	TO
		act[0].Down();
		act[0].Mes("�S�΂���ł����A�悩�����炱���");
	TO
		act[1].Up();
		act[1].Mes("��A����͉����ȁH");
	TO
		act[0].Mes("�����َq�ł��A�悩������F�����");
	TO
		act[1].Mes("���������̂�Ⴄ�̂͂�����Ƃ܂����񂾂��ȁE�E�E");
	TO
		act[0].Mes("�������킸");
	TO
		act[1].Mes("�������ȁA�L����Ղ��悤");
	TO
		act[1].Mes("���@�̌��ʂ͖��Ȃ�����������c�Ƃ������悤");
	TO
		act[0].E����();
	TO
		act[0].Mes("���肪�Ƃ��������܂��I");
	TO
		act[1].Direct(DI::��);;
		act[1].Mes("�悵�A�����͋A�邼");
	TO
		act[1].Move(0, 2, 2);
	TO
		act[1].Move(0, 5, 2);
		act[2].Move(0, 5, 2);
		act[3].Move(0, 5, 2);
	END
}
void EVE_SUB::�c�Ƌ���B()
{
	//�d�G��Ⴆ���A�{��S���ȃn���t�@�h����荞��ł���
	//�ߕ߂��ꂻ���ɂȂ邪�A�����g�b�v�̐l�ɏ����Ė����

	START
		act[0].Set(EChara::�Z�I,7,3,DI::��);
		act[1].Set(EChara::�n���t�@�h,7,11,DI::��);
		act[2].Set(EChara::���m,6,12,DI::��);
		act[3].Set(EChara::���m,8,12,DI::��);
		BackChenge(EStage::�X��);
	TO
		act[1].Move(0, -5, 2);
		act[2].Move(0, -5, 2);
		act[3].Move(0, -5, 2);
	TO
		act[1].Mes("�����I");
		act[1].HukiUp(false);
	TO
		act[0].Down();
		act[0].Move(0, 1, 2);
	TO
		act[0].Mes("��������Ⴂ�܂��􁗂��q�l�{���͂ǂ̂悤�ȕ�������T���ŁH");
	TO
		act[0].Mes("�����I�n���t�@�h�l�����A�l�Ŗ{�����c�Ƃ��J�n���Ă���܂�");
	TO
		act[4].Set(EChara::���m,2, 2, DI::��);
		act[4].Move(0, 1, 2);
	TO
		act[5].Set(EChara::���m, 2, 2, DI::��);
		act[5].Move(0, 1, 2);
		act[4].Move(0, 1, 2);
	TO
		act[4].Right();
		act[5].Right();
	TO
		act[0].Left();
	TO
		act[0].Down();
		act[0].Mes("�Ȃ�ł����A��́H");
	TO
		act[1].Mes("�M�l�ɑߕߏ󂪏o�Ă���");
	TO
		act[1].Mes("�����ł̕��퉮�c�Ɓ�����͏d��Ȕƍߍs�ׂ�");
	TO
		act[0].Mes("�����������Č���������Ȃ��ł����I�H");
	TO
		act[1].Mes("�R��t���ȁI���ǂ����e�����X�g�ɂł�����𔄂��Ă���񂾂낤�I");
	TO
		act[1].Mes("�������Ƃ�����A�s����I");
	TO
		act[0].Left();
		act[0].Mes("���E�E�E");
	TO
		act[0].Down();
		act[6].Set(EChara::�X�^�C�g,7, 11, DI::��);
		act[6].Move(0, -3, 2);
		act[6].Mes("�Ȃ񂾁A����������");
		act[6].huki_ud = 1;
	TO
		act[1].Down();
		act[1].Mes("�̎��I");
		act[1].huki_ud = 0;
		act[2].Down();
		act[3].Down();
	TO
		act[0].Mes("�̎��H");
		act[0].huki_ud = 0;
	TO
		act[6].Mes("���m�������A��Ăǂ����ɍs�����Ǝv�����灗�������Ă���񂾁H");
	TO
		act[0].huki_w = 0;
		act[1].Mes("�����ŕ���𔄂��Ă���ƍߎ҂�ߕ߂��ɗ�����ł���B");
	TO
		act[6].Mes("�����Ȃ́H");
	TO
		act[1].huki_w = 0;
		act[0].Mes("����A���̕��ɑ��v�ƌ���ꂽ��ł����E�E�E");
	TO
		act[1].Up();
		act[1].Mes("�M�l�I�R��t����");
		act[0].huki_w = 0;
		act[1].huki_w = 0;
	TO
		act[1].Down();
		act[6].Mes("�v���o���������������Ή����\�����󗝂����񂾁I");
		act[6].huki_ud = 1;
	TO
		act[6].Mes("��������H");
		act[6].huki_ud = 1;
	TO
		act[0].Mes("������������ł����H");
	TO
		act[6].Mes("����Ŗ��Ȃ�����H");
	TO
		act[0].huki_w = 0;
		act[1].Mes("��薳���킯�����ł��傤�I");
	TO
		act[6].Mes("�E�E�E");
	TO
		act[1].Up();
		act[1].Mes("�����A�d���������o���Ă����");
	TO
		act[0].Down();
		act[1].Mes("�s����");
	TO
		act[1].Move(1, 0, 2);
		act[2].Move(0, 1, 2);
		act[3].Move(0, 1, 2);
		act[4].Move(0, -1, 2);
		act[5].Move(0, -1, 2);
	TO
		act[1].Move(0, 1, 2);
		act[2].Move(0, 1, 2);
		act[3].Move(0, 1, 2);
		act[4].Move(0, -1, 2);
		act[5].y = -1000;
	TO
		act[1].Move(0, 5, 2);
		act[2].Move(0, 5, 2);
		act[3].Move(0, 5, 2);
		act[4].y = -1000;
	TO
		act[6].Move(0, -2, 2);
		act[6].Mes("�Г������");
		act[6].huki_ud = 1;
	TO
		act[6].Down();
		act[6].Mes("�ǂ����A���񂽂̃N�b�L�[���C�ɓ���񂩂����炵��");
	TO
		act[6].Mes("�������A�d�G�ɉَq��n���z������Ƃ́����ʂ͎D�����l�߂����Ȃ񂾂�");
	TO
		act[0].E�v�l();
	TO
		act[6].Up();
		act[6].Mes("�킴�Ƃ��H");
	TO
		act[6].E����();
	TO
		act[6].Mes("�܂����ʎd�Ԃ��ɂ����܂ł��Ƃ͎v���");
	TO
		act[0].Mes("���肪�Ƃ��������܂��A������܂���");
	TO
		act[6].Up();
		act[6].Mes("�͂��́A��ɂ͋y�΂�恗�ēӔC���ēz�����邩���");
	TO
		act[6].Mes("�����͉c�Ƌ��؂�n���ɗ������ق��A���ꂪ�c�Ƌ���");
	TO
		act[6].Mes("�ƌ��������������A���ނɕs���������Ăȁ������o�����Ƃ͏o���Ȃ�");
	TO
		act[6].Left();
		act[6].Mes("���`�A�Ȃ񂾂��}�ɉَq�ł��H�ׂȂ��Ȃ��Ă����E�E�E");
	TO
		act[0].Mes("�E�E�E");
	TO
		act[6].Up();
		act[6].Mes("��k����A��k");
	TO
		act[6].Mes("�͂��R�����c�Ƌ��؂�");
	TO
		act[0].Mes("���肪�Ƃ��������܂�");
	TO
		act[6].Mes("�������A���̃^�C�~���O�ŕ��퉮���n�߂�Ƃ́E�E�E��");
	TO
		act[6].E�v�l();
	TO
		act[6].Mes("�܂�������");
	TO
		act[6].Mes("���Ⴀ��");
	TO
		act[6].Move(0, 6, 2);
	TO
		act[0].Mes("��������");
	END
}
void EVE_SUB::�V�����()
{
	//�ɂ����ȐV���L�҂���ނɗ����̂Ŏ󂯂邱�Ƃ�
	//�Ȃ����m���m���̃Z�I�����A�L���͏����������炵��
	//�v
	START
		act[0].Set(EChara::�Z�I,6,4,DI::��);
		act[1].Set(EChara::�}�X�R��,6,8,DI::��);
		BackChenge(EStage::��c��);
	END
}
void EVE_SUB::�������()
{
	//�������œ����Ă����l�g���������ɁA���߂Ă̋q�ł���
	//�V���L���̌��ʂ��������炵��

	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�W���b�V��,6.5,11,DI::��);
		act[2].Set(EChara::���C�R,7.5,11,DI::��);
		act[1].HukiUp(false);
		act[2].HukiUp(false);
		BackChenge(EStage::�X��);
	TO
		act[0].Mes("�c�ƊJ�n�����͗ǂ����A���܂�q�����Ȃ��ȁE�E�E");
	TO
		act[0].Mes("��`���s�����Ă���̂��E�E�E�P���Ɏ��v���Ȃ��̂�");
	TO
		act[0].E�v�l();
	TO
		act[0].E����();
	TO
		act[1].Move(0, -5,4);
		act[2].Move(0, -5,4);
	TO
		act[0].Mes("��������Ⴂ�܂�");
	TO
		act[1].Mes("����ȏ��ɕ��퉮���o���Ă�����ł���");
	TO
		act[2].Right();
		act[2].Mes("�ՌÒ������Ă�݂��������ǁ����ɂ͊��ҏo����̂�����H");
	TO
		act[2].Up();
		act[0].Mes("���X�̕���͂ǂ���ꋉ�i�ł����i���͕ۏ؂��܂���I");
	TO
		act[1].Mes("���������Ē����܂����H");
	TO
		act[0].Mes("�ǂ���");
	TO
		act[1].E�v�l();
	TO
		act[1].Mes("�ǂ������ł���");
	TO
		act[2].Mes("�Ȃ񂩃_�T���Ȃ��H���܂����m�������������͂܂���");
	TO
		act[0].Mes("���m�H");
	TO
		act[1].Mes("��X�̌ق���ł���������̐��Ԍn�𒲍����Ă����ł���");
	TO
		act[0].Mes("�ւ��`�A���������l�������ł���");
	TO
		act[1].Mes("�������������o���܂����A����ł�");
	TO
		act[0].Mes("���肪�Ƃ��������܂���");
	TO
		act[1].Move(0, 5, 4);
		act[2].Move(0, 5, 4);
	END
}
void EVE_SUB::�ŋ��̃n���^�[()
{
	//��l���̃V�������X�B
	//������ƒ����āA�A��B

	START
		act[0].Set(EChara::�Z�I, 7, 4, DI::��);
		act[1].Set(EChara::�t�@�N�g, -1, 4, DI::��);
		act[2].Set(EChara::�V��,7,11,DI::��);
		act[2].HukiUp(false);
		BackChenge(EStage::�X��);
	TO
		act[1].Move(7, 0, 4);
	TO
		act[1].Mes("�l�����������̕]���͂ǂ������H");
	TO
		act[0].Left();
		act[0].Mes("�܂��܂����ď�����");
	TO
		act[1].Mes("�N�������������Ď��́A�]���ǂ��񂾂�");
	TO
		act[0].Mes("���͑��̕��퉮�͖������A�]���Ђǂ��Ȃ����蔄��邵��");
	TO
		act[0].Mes("�v������肩����̎��v�͂��邵�����ʂ̌o�c�����Ȃ�������");
	TO
		act[1].Mes("�Ȃ���S����");
	TO
		act[1].E����();
	TO
		act[0].Down();
		act[1].Down();
		act[2].Move(0, -5, 4);
	TO
		act[0].Mes("��������Ⴂ�܂�");
	TO
		act[2].Mes("�������\�̕��퉮��");
	TO
		act[0].E����();
	TO
		act[1].Mes("�\�ɂȂ��Ă��ł����H");
	TO
		act[2].Mes("�Ȃ�ł����m�Ɏ��͂܂�Ă��Ƃ�");
	TO
		act[1].E����();
	TO
		act[1].Right();
		act[1].Mes("�����I�H");
	TO
		act[0].Left();
		act[0].Mes("���������ΌN�ɂ͌����ĂȂ�������");
	TO
		act[2].Mes("�ւ��{���������񂾁A�悭���v��������");
	TO
		act[1].Down();
		act[0].Down();
		act[0].Mes("�����܂��A�Ȃ�Ƃ��E�E�E");
	TO
		act[0].Mes("����Ŗ{���͂ǂ̂悤�ȕ�������T���ł���");
	TO
		act[2].Mes("�����~�����񂾁A�ō��̂�");
	TO
		act[0].Mes("����ł�����A������͂������ł��傤���H");
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("����͑ʖڂ��������Ɛ؂ꖡ������̂��~����");
	TO
		act[0].Mes("�����܂���A���X�ň����Ă��錕�͂��ꂾ���ł���");
	TO
		act[1].Mes("�l�̍��������͑ʖڂł����H");
	TO
		act[2].Mes("�����A�����ɂ͎g���Ȃ�");
	TO
		act[0].E����();
		act[1].E����();
	TO
		act[0].Mes("�h���S���I���݂����ł����I�H");
	TO
		act[2].Mes("�N���M�p���Ă���Ȃ��������ǂˁ��N�͐M���邩���H");
	TO
		act[0].E�v�l();
	TO
		act[2].Mes("�ז������ˁA���ꂶ��");
	TO
		act[2].Move(0, 1, 4);
	TO
		act[1].Mes("�҂��ĉ������I");
	TO
		act[2].Up();
		act[2].Mes("�����ȁH");
	TO
		act[1].Mes("�܂��X�ɗ��Ă������I");
	TO
		act[1].Mes("�l�����܂��A���E���̌�");
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("���҂��Ă���������");
	TO
		act[2].Move( 0 , 4 , 4);
	TO
		act[1].Mes("");
		act[0].E�v�l();
	END
}
void EVE_SUB::�l�ޕ�W�J�n()
{
	//�����������킪����n�߂��̂ŁA�l���W���鎖��
	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�t�@�N�g,6,4,DI::�E);
		BackChenge(EStage::�X��);
	TO
		act[0].Mes("�q�������Ă������A�d���̕��͂ǂ����H");
	TO
		act[1].Mes("���q���񂪑����Ă����̂͂������ǁ���͂��܂Ŗl��l�ō��̂́E�E�E");
	TO
		act[1].Mes("������l���ق��ė~����������Ɏ��Ԃ��~�����E�E�E");
	TO
		act[0].Mes("���E���̌����H����́A���Ԃ��������Ƃ��Ă��O�ɍ���̂�");
	TO
		act[1].Mes("����ɂ��̐l�h���S����������Č����Ă�����Ȃ������{���Ȃ炨�q����͑�����񂾂�");
	TO
		act[0].Mes("�h���S����������Ęb�A�M�����̂��H");
	TO
		act[1].Mes("�l�͐M����");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�܂��A�����M���Ă���킯����");
	TO
		act[0].Mes("�ڋq�̕��͉���l�ł��񂹂遗�Ƃ肠�������莆�ł����āA�E�l���W���邩");
	TO
		act[1].Mes("�ǂ��l�����Ă����Ƃ�����");
	TO
		act[0].Mes("��������");
	TO
		act[1].Move(-7,0,4);
	TO
		act[0].E�v�l();
	END
}
void EVE_SUB::�g�E�c�O�̗p()
{
	//���莆�����āA����Ă����g�E�c�O���̗p

	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�t�@�N�g,-1,4,DI::��);
		act[2].Set(EChara::�g�E�c�O,7,11,DI::��);
		act[2].HukiUp(false);
		BackChenge(EStage::�X��);
	TO
		act[2].Move(0,-5,4);
	TO
		act[0].Mes("��������Ⴂ�܂����ǂ̂悤�ȕ�������T���ŁH");
	TO
		act[2].Mes("����𔃂��ɗ����񂶂�Ȃ��ł�");
	TO
		act[0].E�^��();
	TO
		act[2].Mes("���́A�\�̒��莆��");
	TO
		act[0].Mes("�E�l��W�́H");
	TO
		act[2].Mes("�͂��I");
	TO
		act[0].E�v�l();
	TO
		act[0].Left();
		act[0].Mes("�����A�t�@�N�g�I");
	TO
		act[1].Move(7,0,4);
	TO
		act[1].Mes("���x�͐E�l��]�̐l����ˁH");
	TO
		act[0].Mes("�����A�\�̒��莆�������񂾂Ɓ��ǂ����H");
	TO
		act[1].Down();
		act[1].Mes("�ǂ������āA�����Ă�");
	TO
		act[0].Down();
		act[1].Mes("�����ƁA���O�́H");
	TO
		act[2].Mes("�g�E�c�O�ł�");
	TO
		act[1].Mes("�g�E�c�O�N�͂Ȃ�ł����œ������ƁH");
	TO
		act[2].Mes("���킪��肽������ł�");
	TO
		act[0].Mes("�ւ��A�Ⴆ�΂ǂ�ȁH");
	TO
		act[2].Mes("�����E���邮�炢��������ł�");
	TO
		act[1].E����();
		act[0].E����();
	TO
		act[0].Mes("�ʔ�������Ȃ���");
	TO
		act[1].Mes("�����{���ɂ���Ǝv���Ă�́H");
	TO
		act[2].Mes("�����A���������킯�ł͂Ȃ��ł�");
	TO
		act[1].E�v�l();
	TO
		act[1].Mes("���퐻���̌o���͂���H");
	TO
		act[2].Mes("�͂��I���ꉴ����������ł�");
	TO
		act[1].E�v�l();
	TO
		act[0].Left();
		act[0].Mes("���O��������z���o���������񂶂�Ȃ���");
	TO
		act[1].Mes("�E�E�E");
	TO
		act[0].Mes("���܂肾��");
	TO
		act[0].Down();
		act[0].Mes("�悵�̗p�I���������痈��邩�H");
	TO
		act[2].Mes("���v�ł��I����낵�����肢���܂��I");
	TO
		act[1].Mes("�����A��낵����");
	END
}
void EVE_SUB::�����t�@�̗p()
{
	//���莆��ǂ�ŁA����Ă��������t�@�𑦍̗p�B
	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�����t�@, 7, 11, DI::��);
		act[2].Set(EChara::�t�@�N�g, -1, 4, DI::��);
		act[1].HukiUp(false);
		BackChenge(EStage::�X��);
	TO
		act[1].Move(0, -5, 4);
	TO
		act[0].E�n�[�g();
	TO
		act[0].Mes("��������Ⴂ�܂��I����������T���ł������삳��");
	TO
		act[1].Mes("�����A�\�̋��l������");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�l��s���ō����Ă�����ł��A�̗p�I");
	TO
		act[1].E����();
	TO
		act[1].Mes("�����I������ȂɊȒP�Ɍ��߂ėǂ���ł����H");
	TO
		act[0].Mes("���Ȃ��̂悤�ȕ���҂��Ă�����ł���");
	TO
		act[1].Mes("�ł��E�E�E");
	TO
		act[1].E�v�l();
	TO
		act[1].Mes("���肪�Ƃ��������܂�");
	TO
		act[0].E�v�l();
	TO
		act[0].E����();
	TO
		act[0].Mes("����A���ȏЉ�x��܂����ˁ��В��̃Z�I�ł�");
	TO
		act[1].Mes("�����t�@�ł��A��낵�����肢���܂��B");
	TO
		act[0].Mes("�����t�@���񂩁����O�܂Ŕ�����");
	TO
		act[0].Left();
		act[0].Mes("�t�@�N�g�N�I");
	TO
		act[2].Move(7,0,4);
	TO
		act[2].Mes("������C���������ȁH");
	TO
		act[0].Down();
		act[0].Mes("�����A�l�����Ă��ꂽ���������t�@����");
	TO
		act[2].Down();
		act[2].E�v�l();
	TO
		act[2].Mes("���̎q����Ȃ����H�����v�Ȃ́H");
	TO
		act[0].Left();
		act[0].Mes("���ʂ͂�����ȁ����̎q���������������Ă�������Ȃ���");
	TO
		act[0].Down();
		act[0].Mes("�����܂���A�����Ă���ĉ�����");
	TO
		act[1].Mes("���������ł����H");
	TO
		act[0].E�v�l();
		act[1].E�v�l();
		act[2].E�v�l();
	TO
		act[0].E����();
		act[1].E�^��();
		act[2].E����();
	TO
		act[2].Mes("��W���Ă�̂́A��������E�l����");
	TO
		act[1].E����();
	TO
		act[1].Mes("�X�����񂶂�Ȃ���ł����H");
	TO
		act[2].Mes("���������Ă������͂�������");
	TO
		act[1].Mes("���߂�Ȃ���");
	TO
		act[0].E����();
	TO
		act[0].Mes("����A���x�X������W���悤�Ǝv���Ă�����ł���");
	TO
		act[2].Right();
		act[2].Mes("����");
	TO
		act[1].Mes("�����Ȃ�ł����H");
	TO
		act[0].Mes("���������낵����");
	END
}	
void EVE_SUB::��͂��[�i()
{
	//��͂���[�i�ɖ����
	//�������͖���ɂȂ�
	START
		act[0].Set(EChara::�Z�I,15,7,DI::��);
		act[1].Set(EChara::��t,2,7,DI::�E);
		act[2].Set(EChara::�S�N�g, -1, 7, DI::�E);
		act[3].Set(EChara::�^�N�X, -1, 7, DI::�E);
		BackChenge(EStage::����);
	TO
		act[0].Move(-10, 0, 4);
	TO
		act[1].Mes("����ɂ���");
	TO
		act[0].Mes("�t�����e�B�A�X�~�X�̃Z�I�ł����z�R�J���ۂ̃S�N�g��������肢���܂�");
	TO
		act[1].Mes("���X���҂���������");
	TO
		act[1].Move(-3,0,4);
	TO
		act[2].Move(3, 0, 4);
	TO
		act[2].Mes("���҂������܂���");
	TO
		act[0].Mes("��������������[�i�����A��͂��͂ǂ��ł����H");
	TO
		act[2].Mes("�Ȃ��Ȃ��ǂ���͂��ł������o�����痈�������݂�����ł����E�E�E");
	TO
		act[0].E�^��();
	TO
		act[2].Mes("��̕�����A���т̖����Ǝ҂͎̂g���ȂƂ����܂���");
	TO
		act[2].Mes("�����܂���A�Ƃ肠���������̎󒍂͂O�ƌ������ŁE�E�E");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("����͍���܂�");
	TO
		act[2].Mes("���������܂��Ă��E�E�E");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("������܂����E�E�E");
	TO
		act[2].Mes("�{���ɂ��߂�Ȃ����A���̗͕s����");
	TO
		act[0].Mes("����Ɛŋ��̌��ő��k�������̂ł���");
	TO
		act[2].Mes("������܂����A�S���̕������Ăт��܂�");
	TO
		act[2].Move(-3,0,4);
	TO
		act[3].Move(3, 0, 4);
	TO
		act[3].Mes("�͂��߂܂��Ă��A�Ŗ��ۂ̃^�N�X�ł�");
	TO
		act[0].Mes("�͂��߂܂��āA�t�����e�B�A�X�~�X�̃Z�I�ł�");
	TO
		act[3].Mes("�В��������ςł��˂��������̕��̎��݂����̂ɗ��܂��");
	TO
		act[3].Mes("�������Ƃ����΂�΂����̂ɂˁA����ȓz");
	TO
		act[0].E����();
		act[3].E�n�[�g();
	TO
		act[3].Mes("��k�ł��悧");
	TO
		act[3].Mes("�ŋ��̑��k�ł��������H");
	TO
		act[0].Mes("�͂��A������ƕ�����Ȃ��Ƃ��낪����܂���");
	TO
		act[0].Mes("");
		BackChenge(EStage::����);
	TO
		act[0].Mes("�������ŗ�����������Ǝv����ł����H");
	TO
		act[3].Mes("����ł����\�����ł�����d���Ȃ��ł���");
	TO
		act[0].Mes("�܂��ĖႦ�܂��񂩁H");
	TO
		act[3].E�v�l();
	TO
		act[3].Mes("����������ł��˂������O����ł�����");
	TO
		act[3].Mes("�o������z�R�ŋ����J���ł����ǁ��o���Ȃ��Ⴂ���킯��");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("����ς肢���ł�");
	TO
		act[3].Mes("�c�O�ł��˂�");
	END
}
//���C���V�i���I 2
void EVE_SUB::�o�c�񃖌���()
{
	//�o�c�񃕌��ڂ��J�n

	START
		act[0].Set(EChara::�Z�I,7.5,6,DI::��);
		act[1].Set(EChara::�t�@�N�g, 6.5, 8, DI::��,false);
		act[2].Set(EChara::�g�E�c�O, 7.5, 8, DI::��,false);
		act[3].Set(EChara::�����t�@, 8.5, 8,DI::��,false);
		BackChenge(EStage::�X��);
	TO
		act[0].Mes("���͂悤�������܂�");
	TO
		act[1].Mes("���͂悤�������܂�");
		act[2].Mes("���͂悤�������܂�");
		act[3].Mes("���͂悤�������܂�");
	TO
		act[0].Mes("��������Q��");
	TO
		act[0].Mes("�挎�͕���̔���s���͂܂��܂��ł���");
	TO
		act[0].Mes("�����͕���̔���������ƐL�΂������ł���");
	TO
		act[0].Mes("��l�͎n�߂͕�����Ȃ���������Ǝv���܂�����������Ȃ������������玄��A�t�@�N�g�ɕ����ĉ�����");
	TO
		act[0].Mes("����ł͍������P����낵�����˂������܂�");
	TO
		act[1].Mes("��낵�����˂������܂�");
		act[2].Mes("��낵�����˂������܂�");
		act[3].Mes("��낵�����˂������܂�");
	END
}
void EVE_SUB::�o�c�̃X�X��()
{
	//�A�ƋK���Ƃ������߂Ă��Ȃ��������ɋC�t��
	//���߂鎖��

	START
		act[0].Set(EChara::�Z�I,6,4,DI::��);
		act[1].Set(EChara::�t�@�N�g,6,8,DI::��);
		BackChenge(EStage::��c��);
	TO
		act[0].Mes("�V����͂ǂ����H");
	TO
		act[1].Mes("�������D�G���恗�o���҂��ق����͉̂^���ǂ�������");
	TO
		act[1].Mes("�����E�E�E");
	TO
		act[0].E�^��();
	TO
		act[1].Mes("����Ȃ�ł��Ȃ���A�����t�@�����͂ǂ�����");
	TO
		act[0].Mes("���̊o�����������A�f���ł܂��߂������q�̕]������X");
	TO
		act[0].Mes("������Ƃǂ��ȏ������킢���ā����喳������");
	TO
		act[1].E����();
	TO
		act[1].Mes("�b���Ă̂͂���H");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("��͂��̎󒍂��Ȃ��Ȃ���");
	TO
		act[1].Mes("�Ȃ�ŁH");
	TO
		act[0].Mes("�����͕�����񁗎d��������̂͂���������");
	TO
		act[0].Mes("�l�𑝂₵�����ɍ��������񂾁�����̔��������ƌ��\���т�������");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�����t�@���񂪓����āA�]�T���ł����������͌o�c������ɗ͂�����");
	TO
		act[0].Mes("���O�������l���Ƃ��Ă���");
	TO
		act[1].Mes("��������");
	END
}
void EVE_SUB::�X�^�C�g���@()
{
	//�����̂�͂��󒍂ɂ��ăX�^�C�g�����@
	//��͂��m���}����
	START
		act[0].Set(EChara::�Z�I, 7, 4, DI::��);
		act[1].Set(EChara::�����t�@,10,7,DI::�E);
		act[2].Set(EChara::�X�^�C�g,7,11,DI::��,false);
		act[3].Set(EChara::���m, 7, 6, DI::��);
		act[4].Set(EChara::���m, 11, 7, DI::��);
		BackChenge(EStage::�X��);
	TO
		act[3].E����();
	TO
		act[0].Mes("���肪�Ƃ��������܂���");
		act[3].Move(0, 6, 4);
	TO
		act[2].Move(0, -5, 4);
	TO
		act[0].Mes("��������Ⴂ�܂�");
	TO
		act[0].E����();
	TO
		act[0].Mes("����̓X�^�C�g�l");
	TO
		act[2].Mes("�₟�v���Ԃ�");
	TO
		act[2].Right();
		act[2].E�v�l();
	TO
		act[2].Up();
		act[2].Mes("�O���]�ƈ��������Ă邯�ǁ����퉮���Ėׂ���񂾂�");
	TO
		act[0].Mes("���₟�A�Ȃ��Ȃ��������ł���");
	TO
		act[0].Mes("�Ƃ���ŁA�{���͂ǂ̂悤�Ȃ��p���ŁH");
	TO
		act[2].Mes("�ǂ��j���[�X��m�点��");
	TO
		act[0].Mes("�ǂ��j���[�X�ł����H");
	TO
		act[2].Mes("���������[�i������͂��Ȃ񂾂����]�����ǂ��ĂˁA�܂��󒍂��鎖�ɂȂ���");
	TO
		act[2].Mes("�����󂯂Ă���邩�H");
	TO
		act[0].Mes("�������ł�");
	TO
		act[2].Mes("�ǂ������ǂ�����");
	TO
		act[2].Mes("���ꂩ��A������E�E�E");
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("���Ƃ���͔閧�ɂ��Ȃ��Ƃ����Ȃ�����");
	TO
		act[2].Mes("���ꂶ�Ⴀ�܂�����");
	TO
		act[2].Move(0,5,4);
	TO
		act[0].E�^��();
	END
}
void EVE_SUB::���b�̎���()
{
	//�^�����������b��R���Ƃ��Ĉ����Z�p�𔭖�
	//���㖂�b����t�����e�B�A�ŗ��s��͗l

	START
		act[0].Set(EChara::�Z�I, 7, 4, DI::��);
		act[1].Set(EChara::�����t�@, 2, 2, DI::��, false);
		BackChenge(EStage::�X��);
	TO
		act[1].Move(0,2);
	TO
		act[1].Move(4,0);
	TO
		act[1].Mes("�В��A���͂悤�������܂��I");
	TO
		act[0].Left();
		act[0].Mes("���͂悤�A�����t�@����");
	TO
		act[0].E����();
	TO
		act[0].Mes("�ӂӂ�");
	TO
		act[1].E�^��();
	TO
		act[1].Mes("�ǂ������܂������H");
	TO
		act[0].Mes("���̋L����ǂ�ł���邩��");
	TO
		act[1].Mes("�V���ł����H");
	TO
		act[1].E�v�l();
	TO
		act[1].Mes("�����ƁE�E�E���u�t�����e�B�A�ŐV�����I�H�v");
	TO
		act[1].Mes("�t�����e�B�A�ݏZ�̃g�[�W���[�������[�����[�ɐ������閂�b���灗����Ȗ��𐸐����鎖�ɐ�������");
	TO
		act[1].Mes("�[�����[�̓t�����e�B�A�ɐ������閂�b�Ł��[���`�����̑̂�����");
	TO
		act[1].Mes("�[�����[���͓�������A�����ɔ�ׁ������G�l���M�[������");
	TO
		act[1].Mes("�[�����[�͑�ʂɐ������Ă��邽�߁������ɖ������������悤�ɂȂ邾�낤");
	TO
		act[1].Mes("���̔��\�ŁA�R�����֘A���͑啝�ɒl�������Ă���");
	TO
		act[1].E�^��();
	TO
		act[1].Mes("���ꂪ�ǂ�������ł����H");
	TO
		act[1].E����();
	TO
		act[1].Mes("�����I�R�������܂���");
	TO
		act[0].E����();
	TO
		act[0].Mes("�܂��A����������Ȃ񂾂�");
	TO
		act[0].Mes("�[�����[�����n���^�[������������厖����");
	TO
		act[0].Mes("�q�������邾�낤���A�Z�����Ȃ遗����΂낤��");
	TO
		act[1].Mes("�͂��I");
	END
}
void EVE_SUB::�V�����2()
{
	//���b�������Ɋւ��Ď�ށB

	START
		act[0].Set(EChara::�Z�I,6,4,DI::��);
		act[1].Set(EChara::�}�X�R��,6,8,DI::��);
		BackChenge(EStage::��c��);
	TO
		act[1].Mes("���Z�������A�����܂���");
	TO
		act[0].Mes("���������A��������X�̐�`�ɂȂ�܂������");
	TO
		act[1].Mes("����ł͑�����ނ��n�߂܂���I");
	TO
		act[1].Mes("�Z�I����͂Ȃ��t�����e�B�A�ŕ��퉮���n�߂悤�ƁH");
	TO
		act[0].Mes("�t�����e�B�A�ɂ͕��퉮�������ƌ����b�𕷂��ā����b�������������Ă���Ȃ畐��̎��v������Ɠ����");
	TO
		act[0].Mes("�ȑO�͒����̕���H��ŊǗ��̎d�������Ă�����ł����������̉�Ђ���肽���Ǝv���Ă��܂�����");
	TO
		act[1].Mes("�����ł����A����̔��������O�ɒm���Ă����킯�ł͂Ȃ��ƁH");
	TO
		act[0].Mes("��̌��͑S���m��܂���ł������v������������͔���Ȃ������̂Ł��`�������͎Ј������ł��܂�����");
	TO
		act[0].Mes("����͂�苭��������̔����Ă��������ł���");
	TO
		act[1].Mes("�J�m���H�[����́A��͂�C�ɂȂ����Ă܂���");
	TO
		act[0].E�^��();
	TO
		act[0].Mes("�J�m���H�[�H");
	TO
		act[1].Mes("�����m�Ȃ�������ł����H����͂������̌o�����������āA���퉮���n�߂�炵���ł���");
	TO
		act[0].E����();
	TO
		act[0].Mes("����͏����ł��ˁE�E�E");
	TO
		act[0].Mes("�܂��A���X�͋C�ɂ����������͂����������邾���ł���");
	TO
		act[1].Mes("�Ȃ�ق�");
	TO
		act[1].E�v�l();
	TO
		act[0].Mes("���͍H����ē����܂���");
	TO
		act[1].Mes("����Ƃ����肢���܂�");
	END
}
void EVE_SUB::�H���̃X�X��()
{
	//�ݔ��̂���ڂ��ɂ��āA�g�E�c�O����s����
	//�Ȃ����o�ꂵ���J�m���H���X

	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
	act[1].Set(EChara::�t�@�N�g, -1, 4, DI::��, false);
		act[2].Set(EChara::�g�E�c�O,-1,3,DI::��);
		act[3].Set(EChara::�^�N�~, 7, 11, DI::��,false);
		BackChenge(EStage::�X��);
	TO
		act[1].Move(7,0);
		act[2].Move(7,0);
	TO
		act[1].Mes("�Z�I������Ƃ������H�[�̌��Řb������񂾂���");
	TO
		act[0].E�^��();
	TO
		act[0].Mes("�����H");
	TO
		act[1].Mes("���̍H�[�̐ݔ����ƁA���镐��Ɍ��E�������");
	TO
		act[1].Mes("���q������������������ݔ��𑝋����悤��");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�������Ȃ��A���ۂɋq��������̂͐悾��H���撣���ĂȂ�Ƃ����Ă���");
	TO
		act[2].E�{��();
	TO
		act[2].Mes("���̐ݔ�����ʖڂȂ�ł���");
	TO
		act[2].Mes("�F�͏������Ĉ�������������Ȃ��������������x������ĂȂ�");
	TO
		act[2].Mes("����Ȃ񂶂�i�}�N���������܂���恗����ł����퉮�̎В��ł����H");
	TO
		act[1].E����();
	TO
		act[1].Up();
		act[1].Mes("����������ƌ��t��I�΂Ȃ��ƁE�E�E");
	TO
		act[2].Down();
		act[2].Mes("���łł����H");
	TO
		act[0].Mes("�t�@�N�g�I���O�ǂ������w�����Ă��");
	TO
		act[1].E����();
	TO
		act[1].Mes("�����A�l�I�H");
	TO
		act[3].Move(0,-5);
	TO
		act[3].Mes("����ɂ��́A�В�");
	TO
		act[0].Down();
		act[1].Down();
		act[2].Down();
		act[0].E����();
	TO
		act[0].Mes("�����^�N�~����A���v���Ԃ�ł�");
	TO
		act[3].E�^��();
	TO
		act[3].Mes("����荞�ݒ����������ȁH");
	TO
		act[0].Mes("���₟�A����Ȏ��́E�E�E");
	TO
		act[3].Mes("�V��������A���q���񑝂���������Ȃ���");
	TO
		act[3].Mes("�Z�����Ȃ�O�ɁA�ݔ������z���Ƃ��Ȃ�����");
	TO
		act[0].Mes("�������Ȃ��E�E�E");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�E�l������A�ݔ��ɕs�����o�Ă邵");
	TO
		act[0].Mes("���肢���悤����");
	TO
		act[2].E����();
	TO
		act[3].Mes("���ꂶ�Ⴀ�����������ݔ������܂����灗�Ă�ł����");
	END
}
//���C���V�i���I 3
void EVE_SUB::�o�c�O������()
{
	//�o�c�O�����ځA�n���^�[�������邾�낤�b�B
	//����̗p�𑝂₷�b
	START
		act[0].Set(EChara::�Z�I, 7.5, 6, DI::��);
		act[1].Set(EChara::�t�@�N�g, 6.5, 8, DI::��, false);
		act[2].Set(EChara::�g�E�c�O, 7.5, 8, DI::��, false);
		act[3].Set(EChara::�����t�@, 8.5, 8, DI::��, false);
		BackChenge(EStage::�X��);
	TO
		act[0].Mes("���͂悤�������܂�");
	TO
		act[1].Mes("���͂悤�������܂�");
		act[2].Mes("���͂悤�������܂�");
		act[3].Mes("���͂悤�������܂�");
	TO
		act[0].Mes("�挎�͗�̔����������ăn���^�[����������������̔���s���ǂ�ǂ񑝂��Ă��܂�");
	TO
		act[0].Mes("���Y�𑝂₷���߂Ɂ��܂��l�𑝂₻���Ǝv���܂�");
	TO
		act[0].Mes("�������Ȃ���A���̓X���I�[�v������ƌ������������Ă��܂�");
	TO
		act[0].Mes("���i�̎���l�i�ő��X�ɕ����Ȃ��悤�Ɋ撣��Ȃ���΁����オ�����邱�Ƃ��l�����܂�");
	TO
		act[0].Mes("����ł͍������P����낵�����˂������܂�");
	TO
		act[1].Mes("��낵�����˂������܂�");
		act[2].Mes("��낵�����˂������܂�");
		act[3].Mes("��낵�����˂������܂�");
	END
}
void EVE_SUB::�����t�@�̌Z()
{
	//�����t�@�̌Z�o��A�z�R�J������߂ăn���^�[�ɂȂ�Ƃ��B

	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�����t�@,15,6,DI::�E);
		act[2].Set(EChara::�j�b�g,6.5,11,DI::��,false);
		act[3].Set(EChara::���C�u��,7.5,12,DI::��,false);
		BackChenge(EStage::�X��);
	TO
		act[2].Move(0,-5);
		act[3].Move(0, -6);
	TO
		act[0].Mes("��������Ⴂ�܂�");
	TO
		act[0].Mes("�{���͂ǂ̂悤�ȕ�����H");
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("��������n���^�[���n�߂�̂Ł����܂�ڂ����Ȃ���ł���");
	TO
		act[2].Mes("�������߂̌��Ƃ�����܂����H");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�����ł��ˁE�E�E�S�̌����������߂ł����؂ꖡ���ϋv���悭�āA�g���₷���ł���");
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("���Ⴀ����������ĖႦ�܂����H");
	TO
		act[2].Right();
		act[2].Mes("���O�͂ǂ�����H");
	TO
		act[3].Mes("���������̂����Ă݂邩��");
	TO
		act[2].Up();
		act[0].Mes("������܂����A���X���҂���");
	TO
		act[0].Right();
		act[0].Mes("�����t�@����I");
	TO
		act[0].Down();
		act[2].Right();
		act[3].Right();
		act[1].Move(-6,0);
	TO
		act[1].Mes("���Ăтł����H");
	TO
		act[1].Mes("���Z�����Ƀ��C�u���I");
	TO
		act[0].E�^��();
	TO
		act[1].Mes("�ǂ����Ă����ɁH");
	TO
		act[3].Mes("�o����񂪓����Ă���ĕ����āA����������������𔃂��ɂ�");
	TO
		act[1].Mes("�d���͂ǂ������́H");
	TO
		act[3].Mes("�O�̎d���͎��߂�����������͉��B�̎d���̓n���^�[��");
	TO
		act[3].E����();
	TO
		act[1].Mes("�댯����A�������Ă�́H");
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("��Ɍ����n�߂��͉̂��̕�����");
	TO
		act[2].Mes("�z�R�̎d�����Ȃ񂾂��񂾂Ŋ댯��������������������񂶂�Ȃ�");
	TO
		act[2].Mes("���b�����Č����Ă��ߏ�Ń[�����[����邾���Ȃ灗�΂��Ċ댯����Ȃ���");
	TO
		act[1].E�v�l();
	TO
		act[1].Mes("�Z���񂪂��������Ȃ�E�E�E");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("���ق�");
	TO
		act[1].Up();
		act[2].Up();
		act[3].Up();
		act[0].Mes("�S�z����̂�������܂����������̕�����g���΁A���b�Ȃ�Ă����������Ȃ��ł���");
	TO
		act[1].Mes("�����A�ł��ˁE�E�E");
	END
}
void EVE_SUB::�V�G�z�̗p()
{
	//�V�G�z��ʐځ��̗p
	//�v�C�x���g
	START
		act[0].Set(EChara::�Z�I,6,8,DI::��,false);
		BackChenge(EStage::��c��);
	TO
		act[0].Mes("�ǂ���");
	TO
		act[1].Set(EChara::�V�G�z, 3, 2, DI::��);
	TO
		act[1].Move(0, 2);
	TO
		act[1].Move(3, 0);
	TO
		act[1].Down();
		act[1].Mes("��낵�����肢���܂�");
	TO
		act[0].Mes("�����炱���A��낵��");
	TO
		act[0].Mes("���ꂶ�Ⴀ�ʐڂ��n�߂܂�");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("��v�̍��Ǝ��i���������̂悤�ł����ǁE�E�E");
	TO
		act[0].Mes("����{���ł����H");
	TO
		act[1].E�^��();
	TO
		act[1].Mes("�����ł����ǁA�����H");
	TO
		act[0].Mes("���肪������ł����A�Ȃ�ł����Ȃ񂩂ɂƎv���܂���");
	TO
		act[1].Mes("�͂�");
	TO
		act[1].Mes("�t�����e�B�A�Ŕ������ꂽ�V�G�l���M�[�̃j���[�X�𕷂��܂���");
	TO
		act[1].Mes("�����Ȃ�ƁA����t�����e�B�A�Ƀn���^�[�������邾�낤��");
	TO
		act[1].Mes("�����ɏ������������܂���");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�����ł����E�E�E");
	TO
		act[0].Mes("�ڋq�̌o���́H");
	TO
		act[1].Mes("�w������ɖ{���œ����Ă��܂���");
	TO
		act[0].Mes("�Ȃ�ق�");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�������瓭���Ē����܂����H");
	TO
		act[1].Mes("�͂��I");
	END
}
void EVE_SUB::�����̃X�X��()
{
	//�����J��ɑ΂��āA�����̒�āB
	//�v�C�x���g
	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�V�G�z,-1,4,DI::��);
		BackChenge(EStage::�X��);
	END
}
void EVE_SUB::����������()
{
	//�����ƕ�W�ɑ΂��ēo��
	//�Ȃ����f�U�C���ɃP�`��������
	START
		act[0].Set(EChara::�Z�I, 7, 4, DI::��);
		act[1].Set(EChara::����, 7, 12, DI::��,false);
		act[2].Set(EChara::���C�R, 6, 11, DI::��,false);
		act[3].Set(EChara::�W���b�V��, 8, 11, DI::��,false);
		BackChenge(EStage::�X��);
	TO
		act[1].Move(0, -5);
		act[2].Move(0, -5);
		act[3].Move(0, -5);
	TO
		act[0].Mes("��������Ⴂ�܂�");
	TO
		act[0].Mes("�������ۛ��ɂ��ĉ������Ă��肪�Ƃ��������܂����{���͂ǂ̂悤�ȕ�����H");
	TO
		act[3].Mes("�����A�����͕���𔃂��ɗ����̂ł͂Ȃ���ł���");
	TO
		act[0].E�^��();
	TO
		act[2].Down();
		act[2].Mes("���m");
	TO
		act[1].Move(0,-1);
	TO
		act[2].Up();
		act[1].Mes("�N���В����񂩂ˁH");
	TO
		act[0].Mes("�͂��A�����ł���");
	TO
		act[0].Mes("�����ƁA���Ȃ��́H");
	TO
		act[1].E����();
	TO
		act[1].Mes("�܂����A����m��Ȃ��l�Ԃ�����Ƃ�");
	TO
		act[2].E����();
		act[3].E����();
	TO
		act[0].Mes("���������΂ǂ����ŁE�E�E");
	TO
		act[1].E�v�l();
	TO
		act[1].Mes("�䂪���̓g�[�W���[");
	TO
		act[0].Mes("�g�[�W���[�E�E�E�[�����[���́I�H");
	TO
		act[1].Mes("���̂Ƃ���I");
	TO
		act[1].Mes("�t�����e�B�A�E�E�E���␢�E��̓V�˂ł��遗����m��Ȃ��l�Ԃ͂�͂肢�Ȃ���");
	TO
		act[0].E����();
		act[1].E����();
	TO
		act[0].Mes("�����ƁA�{���͂ǂ̂悤�Ȃ��p���ŁH");
	TO
		act[1].Mes("������񔃂�������");
	TO
		act[1].Mes("���̓X�̊��𔃂�����");
	TO
		act[0].Mes("���ł����H");
	TO
		act[1].Mes("���퉮�ɓ�������΁A��苭�����킪����悤�ɂȂ聗�t�����e�B�A�̒T�����i�ނƎv���Ă�");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�����Ȃ肻�������܂��Ă��E�E�E�������P���Șb�ł�����܂���");
	TO
		act[1].Mes("�܂�������������ȁ��������ė~�����Ȃ�����A�����Ă���");
	TO
		act[1].Mes("�ł́I�܂�����I");
	TO
		act[1].Move(0,6);
	TO
		act[3].Mes("�����܂���E�E�E");
	TO
		act[0].Mes("��������");
	END
}
void EVE_SUB::�J�m���H�[()
{
	//�J�m���H�[�����ɖ����J�X
	//�Ȃ񂩈��A�ɗ���
	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�t�@�N�g, 6, 4, DI::�E);
		BackChenge(EStage::�X��);
	TO
		act[1].Mes("���悢��A��������");
	TO
		act[0].E�^��();
	TO
		act[0].Mes("���̘b���H");
	TO
		act[1].Mes("�V�����o���镐�퉮�̊J�X������");
	TO
		act[0].Mes("���O�����������̋C�ɂ���񂾂�");
	TO
		act[0].Mes("�ǂ����債�����ƂȂ�����");
	TO
		act[2].Set(EChara::�J�m��, 7, 11, DI::��, false);
		act[2].Mes("����͕����̂ĂȂ�Ȃ��ł�");
	TO
		act[2].Move(0,-5);
	TO
		act[0].Down();
		act[1].Down();
		act[0].Mes("��������Ⴂ�܂�");
	TO
		act[2].Mes("�q����Ȃ��ł�");
	TO
		act[0].Left();
		act[1].Right();
		act[0].Mes("�m�荇���H");
	TO
		act[1].Mes("�����Ⴄ�Ǝv��");
	TO
		act[0].Down();
		act[1].Down();
		act[2].Mes("�J�m���H�[�A�В��̃J�m���ł����J�X�O�̈��A�ɗ��܂���");
	TO
		act[0].Mes("����͂ǂ���");
	TO
		act[2].Mes("���퉮���m�A���X���X�Ə����ł���");
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("�܂��A���������債���Ȃ������ł����������̑���ɂ͂Ȃ�Ȃ��Ǝv���܂���");
	TO
		act[2].Mes("����ł́A�J�X�����ŖZ�����̂�");
	TO
		act[2].Move(0,6);
	TO
		act[0].Left();
		act[1].Right();
		act[0].Mes("�������Ƃ��肾��H");
	TO
		act[1].Mes("��������");
	END
}
void EVE_SUB::�����v��()
{
	//�]�ƈ��̊Ǘ������悤�I�Ȓ��
	START
		act[0].Set(EChara::�Z�I,6,4,DI::��);
		act[1].Set(EChara::�t�@�N�g,6,8,DI::��);
		BackChenge(EStage::��c��);
	TO
		act[1].Mes("�b���ĉ��H");
	TO
		act[0].Mes("�����̘b��");
	TO
		act[0].Mes("���v�������Ă��邵�A�グ�悤�Ǝv���Ă�");
	TO
		act[1].Mes("�������ˁA�F��ԂƎv���恗���C���オ��񂶂�Ȃ����ȁH");
	TO
		act[0].Mes("�E�l�̓����Ԃ�ɂ��Ă͂��O�̕����������Ă邾��H�����̕ӂ�𕷂������Ă�");
	TO
		act[0].Mes("�ǂ�Ȋ������H");
	TO
		act[1].Mes("�����ƁA�������ˁE�E�E");
	END
}
//���C���V�i���I 4
void EVE_SUB::�w�����X�̗p()
{
	//�f�U�C���͕s���ŔY��ł�����
	//�I�V�������Ă����w�����X���X�J�E�g����

	START
		act[0].Set(EChara::�Z�I, -1, 7, DI::��);
		act[1].Set(EChara::�����t�@, -1, 8, DI::��,false);
		act[2].Set(EChara::�w�����X,7,5,DI::��);
		BackChenge(EStage::�L��);
	TO
		act[0].Move(7, 0);
		act[1].Move(7, 0);
	TO
		act[0].Down();
		act[1].Up();
		act[0].Mes("�����ˁA�x�݂̓��ɔ������ɕt�������Ė����");
	TO
		act[1].Mes("�S�R����Ȃ��ƂȂ��ł���A�C�ɂ��Ȃ��ł�������");
	TO
		act[0].E����();
	TO
		act[0].Mes("�{���I�H�����Ⴀ�A�܂����肢���悤���ȁI");
	TO
		act[2].Mes("�����̂��Ɂ[����");
	TO
		act[0].Up();
		act[0].E�^��();
	TO
		act[0].Mes("���H");
	TO
		act[2].Mes("�������͔ޏ�����H");
	TO
		act[0].E����();
	TO
		act[0].Mes("���₟�A����Ȃ񂶂�Ȃ��ł���");
	TO
		act[1].E�^��();
	TO
		act[2].Mes("�����Ȃ�H");
	TO
		act[2].Mes("�܂��������A�A�N�Z�T���[�����Ă��₯�ǁA���Ă��ւ�H");
	TO
		act[0].Mes("�ǂ�ǂ�E�E�E");
	TO
		act[0].E�v�l();
	TO
		act[1].Mes("�i�D�ǂ��f�U�C���ł���");
	TO
		act[0].Mes("�ǂ���Ŏd������Ă����ł����H");
	TO
		act[2].Mes("�S���A������������");
	TO
		act[0].E�v�l();
	TO
		act[2].Mes("�ǂ�ɂ��܂��H");
	TO
		act[0].Mes("�����œ����܂��񂩁H");
	TO
		act[2].E�^��();
	TO
		act[2].Mes("�͂��H");
	TO
		act[0].Mes("���͂����������������Ł��f�U�C���̓��ӂȐE�l���K�v�Ȃ�ł�");
	TO
		act[2].Mes("�Ȃ�قǁ`");
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("�����b����Ȃ���₯��");
	TO
		act[1].Mes("����������肢���܂�");		
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("���������A���̖��O�̓w�����X����낵�イ�В�����");
	END
}
void EVE_SUB::�J���̃X�X��()
{
	//�w�����X�̈ӌ��ɂ��J��������鎖��
	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�t�@�N�g,6,4,DI::�E);
		act[2].Set(EChara::�g�E�c�O,6,3,DI::�E);
		BackChenge(EStage::�X��);
	TO
		act[0].E�v�l();
	TO
		act[1].Mes("�ǂ������A�V��̕���́H");
	TO
		act[2].Mes("���܂ł̕���ɔ�ׂāA���Ȃ萫�\���オ���Ă�͂��ł�");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�������ɐ��\�͏オ���Ă邪�E�E�E");
	TO
		act[0].Mes("�����ڂ��C�P�ĂȂ��̂��Ȃ������O��Z���X�Ȃ����");
	TO
		act[2].Mes("����͐��\�����ł���A�����ڂȂ�Ăǂ��ł������ł��傤");
	TO
		act[1].Mes("�l�������v������");
	TO
		act[0].Mes("�܂��A���������v��");
	TO
		act[0].Mes("���ہA�n���^�[���m�̌��h�̒��荇���݂����Ȃ̂������ā��i�D�ǂ��͔���ɉe��������񂾂�");
	TO
		act[0].Mes("�Ƃɂ����A�f�U�C�������Ȃ����Ă���");
	TO
		act[1].E�v�l();
	TO
		act[1].Mes("���������A����������ƍl�����");
	END
}
void EVE_SUB::�n���^�[����()
{
	//�n���^�[����Ƃ������g�D���o�����炵��
	//���̐�`�ɉ���o��
	//�v
	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�����t�@, 6, 4, DI::�E);
		act[2].Set(EChara::�I�L�e��,7,11,DI::��);
		BackChenge(EStage::�X��);
	TO
		act[1].Mes("�����l�ł�");
	TO
		act[0].Mes("�����A��������낵����");
	END
}
void EVE_SUB::��`�̃X�X��()
{
	//��`�ɂ��Ẳ�c
	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�j�b�g,6.5,6,DI::��,false);
		act[2].Set(EChara::���C�u��,7.5,6,DI::��,false);
		BackChenge(EStage::�X��);
	TO
		act[0].Mes("���Z����A�����̕���͂ǂ��ł����H");
	TO
		act[1].Mes("�ǂ����킾�Ǝv���܂��恗���̎��ӂ̖�������Ȃ�㓙�����邮�炢�ł�");
	TO
		act[2].Mes("�m���Ƀ[�����[����Ȃ�Ȃ�ł��������");
	TO
		act[0].E����();
	TO
		act[0].Mes("�����ł����E�E�E");
	TO
		act[1].Mes("�����t�@�͎d�������Ƃ���Ă܂����H");
	TO
		act[0].Mes("�ƂĂ��܂��߂ɓ����Ė���āA�������Ă܂���");
	TO
		act[1].Mes("����������������A������炩���ĂȂ����s����");
	TO
		act[1].Mes("�����t�@�̎��A���肢���܂���");
	TO
		act[0].Mes("���C���������I");
	TO
		act[2].Left();
		act[2].Mes("���낻��s������");
	TO
		act[1].Mes("���ꂶ��В�����A�܂�");
	TO
		act[1].Move(0, 5);
		act[2].Move(0, 5);
	TO
		act[1].Set(EChara::�t�@�C, 6, 11, DI::��,false);
		act[2].Set(EChara::�����W, 7, 11, DI::��, false);
		act[3].Set(EChara::�p���R, 8, 11, DI::��, false);
		act[4].Set(EChara::���f�B, 9, 11, DI::��, false);
		act[1].Move(0, -5);
		act[2].Move(0, -5);
		act[3].Move(0, -5);
		act[4].Move(0, -5);
	TO
		act[0].Mes("��������Ⴂ�܂�");
	TO
		act[3].Mes("����ȏ��ɂ����퉮���������̂�");
	TO
		act[4].Mes("����ȓX�悭��������");
	TO
		act[2].Mes("�E�E�E");
	TO
		act[1].Mes("�X������I��Ԃ�������������Ă���");
	TO
		act[0].Mes("����Ȃ�Ăǂ��ł��傤�H");
	TO
		act[1].E�v�l();
	TO
		act[1].Mes("�������킾�A�����Ă���I");
	TO
		act[3].Mes("���͂Ȃ��Ȃ��ǂ�������");
	TO
		act[4].Mes("���x���킪��ꂽ��A�������ɂ��悤����");
	TO
		act[2].Mes("�E�E�E");
	TO
		act[1].Move(0, 5);
		act[2].Move(0, 5);
		act[3].Move(0, 5);
		act[4].Move(0, 5);
	TO
		act[0].Mes("�����̓X���Ēm���x�Ⴂ�̂��H");
	END
}
void EVE_SUB::����̈����O�l�O()
{
	//����̈����O�l�g�̃n���^�[�����X
	//�v�C�x���g
	START
			act[0].Set(EChara::�Z�I,6,10,DI::��);
			act[1].Set(EChara::�����t�@,6,10,DI::��);
			act[2].Set(EChara::�t�@�C�A,6,10,DI::��);
			act[3].Set(EChara::�A�C�X,6,10,DI::��);
			act[4].Set(EChara::�T���_�[,6,10,DI::��);
			BackChenge(EStage::�X��);
	END
}
void EVE_SUB::�z���C�g�i�C�g()
{
	//�z���C�g�i�C�g���J�X�����K
	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�t�@�N�g, 6, 4, DI::�E);
		act[2].Set(EChara::�w�����X, 2, 2, DI::��);
		BackChenge(EStage::�X��);
	TO
		act[2].Move(0, 1);
	TO
		act[2].Move(4, 0);
	TO
		act[2].Down();
		act[2].Mes("���͂悤����I");
	TO
		act[0].Up();
		act[1].Up();
		act[0].Mes("�����A���͂悤");
	TO
		act[1].Mes("���͂悤");
	TO
		act[2].Mes("���̘b�ł����H");
	TO
		act[1].Up();
		act[1].Mes("�V�������퉮���o����b����");
	TO
		act[2].Mes("�ւ�");
	TO
		act[0].Mes("�O�ɕ��퉮���o�����Ƃ��͈��A�ɗ������灗�ꉞ�҂��\���Ă���������");
	TO
		act[2].E�^��();
	TO
		act[2].Mes("����Ȃ�����ł���H");
	TO
		act[0].Down();
		act[1].Down();
		act[2].Down();
		act[3].Set(EChara::�J�m��,7,11,DI::��,false);
	TO
		act[3].Move(0, -5);
	TO
		act[3].Mes("�v���Ԃ�ł��I");
	TO
		act[3].Mes("���ł��V�������퉮���o����炵���ł�");
	TO
		act[3].E����();
	TO
		act[3].Mes("�m���Ă܂����H");
	TO
		act[0].E����();
		act[1].E����();
	TO
		act[0].Mes("�A��");
	END
}
void EVE_SUB::�l�l�g�̃n���^�[()
{
	//�l�l�g�̃n���^�[�����X
	//�v�C�x���g
	START
			act[0].Set(EChara::�Z�I,6,10,DI::��);
			act[1].Set(EChara::�t�@�C,6,10,DI::��);
			act[2].Set(EChara::�����W,6,10,DI::��);
			act[3].Set(EChara::�p���R,6,10,DI::��);
			act[4].Set(EChara::���f�B,6,10,DI::��);
			BackChenge(EStage::�X��);
	END
}
//���C���V�i���I 5
void EVE_SUB::���퉮�Ղ�z��()
{
	//���퉮�Ղ�J�Âɂ���
	//���{�������K
	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�n���t�@�h, 7, 11, DI::��,false);
		act[2].Set(EChara::���m, 6, 12, DI::��);
		act[3].Set(EChara::���m, 8, 12, DI::��);
		BackChenge(EStage::�X��);
	TO
		act[1].Move(0, -5);
		act[2].Move(0, -5);
		act[3].Move(0, -5);
	TO
		act[0].Mes("��������Ⴂ�܁E�E�E");
	TO
		act[0].E����();
	TO
		act[1].Mes("�v���Ԃ肾��");
	TO
		act[0].Mes("���̗p�ł����H");
	TO
		act[1].Mes("�����َ͉q��Ⴂ�ɗ����킯�ł͂Ȃ���");
	TO
		act[1].Mes("�����̃t�����e�B�A�ՂŊJ�Â���镐�퉮�R���e�X�g");
	TO
		act[1].Mes("�����ɏo�W���ĖႨ���Ǝv���Ă�");
	TO
		act[0].Mes("�R���e�X�g�H");
	TO
		act[1].Mes("���Ăΐ�`�ɂȂ��A�܋����o��");
	TO
		act[1].Mes("�܂����ʂɂ���ẮA�]���𗎂Ƃ����Ƃ����邾�낤��");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�����ł��ˁE�E�E");
	TO
		act[1].Mes("�܂��Q�����Ȃ��X�́A����̎��Ɏ��M���Ȃ��Ǝv���邾�낤�������ƁA���������\������");
	TO
		act[0].Mes("������܂����A�Q�����܂��傤");
	TO
		act[1].Mes("�悭���A���������Ă��ꂽ�I");
	TO
		act[1].Mes("�R���ψ����Ƃ��Ă��A����オ���ė~��������ȁI");
	TO
		act[1].Mes("����ł͎��͑��ŉ��");
	TO
		act[1].Down();
		act[1].Mes("�A�邼�I");
	TO
		act[1].Move(0, 2);
	TO
		act[1].Move(0, 3);
		act[2].Move(0, 5);
		act[3].Move(0, 5);
	TO
		act[0].Mes("�ɂȂ����");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�܂��Ȃ�Ƃł��Ȃ邩");
	END
}
void EVE_SUB::�������s()
{
	//�����̕��������K�A�G�k
	//�h���S���̉\
	START
		act[0].Set(EChara::�Z�I,7,4,DI::��);
		act[1].Set(EChara::�t�@�N�g, 6, 4, DI::��);
		act[2].Set(EChara::�V��,7,6,DI::��,false);
		BackChenge(EStage::�X��);
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("�ʖڂ���");
	TO
		act[1].Mes("����ł��ʖڂł����H");
	TO
		act[2].Mes("���ꂶ�Ⴀ�A����������Ȃ�");
	TO
		act[0].Mes("�������h���S���̗؂��ā���̂ǂꂮ�炢�d����ł����H");
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("���ꂪ�h���S���̗؂���");
	TO
		act[0].E����();
		act[1].E����();
	TO
		act[1].Mes("���ꂪ�E�E�E");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("����͂ǂ�����āH");
	TO
		act[2].Mes("�h���S���Ɛ���Ă���A�܂�������ꂽ�킯�����ǁ����̎��g���Ă������͎������Ă��܂��Ă�");
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("�J���ɖ𗧂Ȃ�A�݂������H");
	TO
		act[1].Mes("���肢���܂�");
	TO
		act[2].Mes("���Ⴀ�܂�");
	TO
		act[2].Move(0, 1);
	TO
		act[2].Up();
		act[2].Mes("�����A�����");
	TO
		act[2].Mes("�ꉞ�A���̘b�͓�����");
	TO
		act[2].Move(0, 4);
	TO
		act[3].Set(EChara::�W���b�V��, 6.5, 11, DI::��,false);
		act[4].Set(EChara::���C�R, 7.5, 11, DI::��,false);
		act[3].Move(0, -5);
		act[4].Move(0, -5);
	TO
		act[0].Mes("��������Ⴂ�܂�");
	TO
		act[3].Mes("�����͕���𔃂��ɗ����̂ł͂Ȃ���ł���");
	TO
		act[3].Mes("�ŋߍL�܂��Ă�\�ɂ��ā��Z�I����Ȃ牽���m���Ă��邩�Ǝv���܂���");
	TO
		act[4].Mes("�S���A���m���ςȌ������n�߂�����āE�E�E");
	TO
		act[4].Mes("�h���S���Ȃ�Ă���Ǝv���H");
	TO
		act[0].Mes("���������\�͂���݂����ł��ˁ������悭�킩��܂���");
	TO
		act[4].Mes("�܂��A�����b�ɏo�Ă���悤�ȉ��������Ƃ����灗�����Ȃ�Ă������Ȃ����A���Ȃ������������ǂ�");
	TO
		act[3].Mes("�ςȎ��𕷂��Ă����܂���ł��������x�͔������ɗ��܂���");
	TO
		act[4].Mes("���Ⴀ�܂���");
	TO
		act[3].Move(0, 5);
		act[4].Move(0, 5);
	END
}	
//���C���V�i���I 6
void EVE_SUB::�Ɍ��b��()
{
	//�Ɍ��b�肪�I�[�v��
	//�g�E�c�O��A��߂��ɗ�����
	START
		act[0].Set(EChara::�Z�I, 8, 4, DI::��);
		act[1].Set(EChara::�t�@�N�g, 7, 4, DI::�E);
		act[2].Set(EChara::�g�E�c�O, 2, 2, DI::��);
		BackChenge(EStage::�X��);
	TO
		act[2].Move(0, 2);
	TO
		act[2].Move(4, 0);
	TO
		act[2].Mes("���͂悤�������܂�");
	TO
		act[0].Left();
		act[1].Left();
		act[0].Mes("�����A���͂悤");
	TO
		act[1].Mes("���͂悤");
	TO
		act[2].Mes("�����Ă��ł����H");
	TO
		act[1].Mes("�V�������퉮���o����炵���Ă�");
	TO
		act[2].E�^��();
	TO
		act[0].Mes("�ꉞ�҂��\���Ă���������");
	TO
		act[2].Mes("�Ӗ���������Ȃ��ł�");
	TO
		act[0].Mes("���낻�납�ȁH");
	TO
		act[0].Down();
		act[1].Down();
		act[2].Down();
		act[3].Set(EChara::�q�g�t���T�C, 7, 11, DI::��);
		act[4].Set(EChara::�W���C�`, 6, 12, DI::��);
		act[5].Set(EChara::�P���q��, 8, 12, DI::��);
	TO
		act[3].Move(0, -5);
		act[4].Move(0, -5);
		act[5].Move(0, -5);
	TO
		act[2].E�v�l();
	TO
		act[0].Mes("��������Ⴂ�܂�");
	TO
		act[3].Mes("���ɂ��ڂɂ�����A�Ɍ���U�ւƐ\���܂�");
	TO
		act[0].E�^��();
	TO
		act[0].Mes("�Ɍ����āA�V�����o���镐�퉮�́H");
	TO
		act[3].Mes("�����ɂ�");
	TO
		act[0].Mes("���̌�p�ł��傤���H");
	TO
		act[3].Mes("���Ƃ̋Z�𓐂񂾕s�͂���������ƌ����\�𕷂��܂���");
	TO
		act[3].Mes("�̂��A���p");
	TO
		act[0].E�^��();
	TO
		act[0].Left();
		act[0].Mes("�m�荇�����H");
	TO
		act[2].E�v�l();
	TO
		act[0].Down();
		act[3].Mes("�������A�\�ł����Ȃ������悤�ł���");
	TO
		act[2].Mes("�ǂ������Ӗ����H");
	TO
		act[3].Mes("���O�̕���́A������镐��ɂ͉����y�΂�");
	TO
		act[3].Mes("������������");
	TO
		act[2].E�v�l();
	TO
		act[3].Mes("���ז����܂�����");
	TO
		act[3].Move(0, 2);
	TO
		act[3].Move(0, 3);
		act[4].Move(0, 2);
	TO
		act[5].Mes("�Z����E�E�E");
	TO
		act[4].Up();
		act[4].Mes("�A�邼");
	TO
		act[5].E�v�l();
	TO
		act[5].Mes("�E�E�E�͂�");
	TO
		act[3].Move(0, 1);
		act[4].Move(0, 3);
		act[5].Move(0, 5);
	TO
		act[0].Left();
		act[1].Left();
		act[0].Mes("�������Ă���邩");
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("�E�E�E�m��܂���");
	TO
		act[2].Move(-6, 0);
	TO
		act[0].Mes("�����I");
	TO
		act[1].Right();
		act[1].Mes("�����Ȃ�ʊ����������������͂����Ƃ��Ă��������������񂶂�Ȃ����ȁH");
	TO
		act[1].Mes("�l����Řb�����Ă�����");
	TO
		act[0].Mes("����������");
	TO
		act[3].Set(EChara::�J�m��, 7, 11, DI::��, false);
	TO
		act[3].Move(0, -5);
	TO
		act[0].Down();
		act[1].Down();
		act[3].Mes("�v���Ԃ�ł��I");
	TO
		act[3].Mes("���ł��V�������퉮���o�����E�E�E");
	TO
		act[0].Mes("�A��");
	END
}
void EVE_SUB::�g�E�c�O�ƋɌ�()
{
	//�Ɍ��Ƃƃg�E�c�O�Ƙb
	//�v
	START
			act[0].Set(EChara::�Z�I,6,10,DI::��);
			act[1].Set(EChara::�g�E�c�O,6,10,DI::��);
			act[2].Set(EChara::�V�G�z,6,10,DI::��);
			act[3].Set(EChara::�t�@�N�g,6,10,DI::��);
			act[4].Set(EChara::�w�����X,6,10,DI::��);
			BackChenge(EStage::��c��);
	END
}
//���C���V�i���I 7
void EVE_SUB::���퉮�Ղ�J��()
{
	//�n���^�[�����Â̕��퉮�Ղ肪�J��
	START
		act[0].Set(EChara::�X�^�C�g,7.5,5,DI::��);
		act[1].Set(EChara::�n���t�@�h,9,5,DI::��);

		act[2].Set(EChara::�Z�I,5,7,DI::��);
		act[3].Set(EChara::�����t�@,6,7, DI::��);
		act[4].Set(EChara::���m,7,7, DI::��);
		act[5].Set(EChara::�J�m��,8,7, DI::��);
		act[6].Set(EChara::���m,9,7, DI::��);
		act[7].Set(EChara::�^�N�~,11,7, DI::��);

		act[8].Set(EChara::�g�E�c�O, 4, 8, DI::��);
		act[9].Set(EChara::���m, 5, 8, DI::��);
		act[10].Set(EChara::�t�@�C, 7,8, DI::��);
		act[11].Set(EChara::���f�B, 8, 8, DI::��);
		act[12].Set(EChara::�p���R, 9, 8, DI::��);
		act[13].Set(EChara::�����W, 10, 8, DI::��);

		act[14].Set(EChara::���m, 5, 9, DI::��);
		act[15].Set(EChara::��蕔, 6, 9, DI::��);
		act[16].Set(EChara::�w�����X, 7, 9, DI::��);
		act[17].Set(EChara::���m, 9, 9, DI::��);
		act[18].Set(EChara::�t�@�N�g, 10, 9, DI::��);
		act[19].Set(EChara::���m, 11, 9, DI::��);

		act[20].Set(EChara::���m, 4, 10, DI::��);
		act[21].Set(EChara::�W���C�`, 5, 10, DI::��);
		act[22].Set(EChara::�P���q��, 6, 10, DI::��);
		act[23].Set(EChara::���m, 8, 10, DI::��);
		act[24].Set(EChara::���m, 9, 10, DI::��);
		act[25].Set(EChara::�u����, 10, 10, DI::��);

		BackChenge(EStage::�L��);
	TO
		act[0].Mes("��X�����A���J�n�������A�t�����e�B�A�ɂ͉�����������");
	TO
		act[0].Mes("���������������A���b�ɑ΂�����������������E�E�E");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("���ꂩ�璬�͏������傫���Ȃ�A�Q�N�ڂɍz�R�J�񂪎n�܂�E�E�E");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�����āA���N�����b����邽�ߑ����̃n���^�[������Ă����E�E�E");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("����ł́A��T��t�����e�B�A�J��Ղ�̊J�Â�錾����I");
	TO
		for (int i = 2; i < 25; i++)
		{
			act[i].E����();
		}
	END
}
void EVE_SUB::��͂��Ղ�z��()
{
	//���퉮�Ղ�̐������󂯂āA���{����͂��Ղ�����鎖��
	//�v
	START
		act[0].Set(EChara::�Z�I,6,10,DI::��);
		act[1].Set(EChara::�X�^�C�g,6,10,DI::��);
		BackChenge(EStage::�X��);
	END
}
//���C���V�i���I 8
void EVE_SUB::�h���S���̓�()
{
	//�����̃I�[�N�V�����Ńh���S���̓��������l�i�Ŕ����B
	//�n���^�[�̑����������܂��
	START
		act[0].Set(EChara::�Z�I,8,4,DI::��);
		act[1].Set(EChara::�t�@�N�g, 7, 4, DI::�E,false);
		BackChenge(EStage::�X��);
	TO
		act[0].Mes("��̃j���[�X���������H");
	TO
		act[1].Mes("��̃j���[�X���āH");
	TO
		act[0].Mes("�Ȃ�ł����������I�[�N�V�����ŗ��̓��𗎎D����������");
	TO
		act[0].Mes("�P�O����");
	TO
		act[1].E����();
	TO
		act[1].Mes("�P�O���I�H");
	TO
		act[1].E�^��();
	TO
		act[1].Mes("�ł��A�Z�I�������Ă��̂��ė��؂���Ȃ����������H");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�����A�V�����񂩂�a�����Ă�̂����ꂾ�낤");
	TO
		act[0].Mes("���ɂ��悭������񂪁��I�[�N�V�����ɏo���̂͋U��������");
	TO
		act[0].Mes("�h���S���̖ڌ����������Ă��邵�����ꂩ��n���^�[��������͂�");
	TO
		act[0].Mes("�q�������āA���߂��镐��̎����オ��̂͊m�����낤��");
	TO
		act[1].Mes("�������ˁA����̊J���撣���");
	TO
		act[0].Mes("����");
	END
}
//���C���V�i���I 9
void EVE_SUB::��͂��Ղ�J��()
{
	//��͂��Ղ肪�J��
	//�v
	START
			act[0].Set(EChara::�X�^�C�g,6,10,DI::��);
			act[1].Set(EChara::�Z�I,6,10,DI::��);
			act[2].Set(EChara::�^�N�~,6,10,DI::��);
			act[3].Set(EChara::�u����,6,10,DI::��);
			act[4].Set(EChara::�q�g�t���T�C,6,10,DI::��);
			BackChenge(EStage::�L��);
	END
}
//���C���V�i���I 10
void EVE_SUB::�J���()
{
	//�J��󋵂ɂ��Ă̎G�k
	START
		act[0].Set(EChara::�Z�I, 7, 4, DI::��);
		act[1].Set(EChara::�����t�@, 10, 7, DI::�E);
		act[2].Set(EChara::�X�^�C�g, 7, 11, DI::��, false);
		act[3].Set(EChara::���m, 7, 6, DI::��);
		act[4].Set(EChara::���m, 11, 7, DI::��);
		BackChenge(EStage::�X��);
	TO
		act[3].E����();
	TO
		act[0].Mes("���肪�Ƃ��������܂���");
		act[3].Move(0, 6, 4);
	TO
		act[2].Move(0, -5, 4);
	TO
		act[0].Mes("��������Ⴂ�܂�");
	TO
		act[2].Mes("�v���Ԃ肾��");
	TO
		act[2].Mes("��͂�h���S���̌��Ńn���^�[�������Ă�");
	TO
		act[0].Mes("�͂��A��Z���ł���");
	TO
		act[2].Mes("�J��̕����啪�i�񂾂��A�ږ��҂�������̂����肪����");
	TO
		act[2].Mes("���������ꂾ���J�񂪐i��ł��A�h���S���ɑ��������n���^�[�͂��Ȃ��炵��");
	TO
		act[2].Mes("�{���Ƀh���S���͂���̂��Ǝv���񂾂��E�E�E");
	TO
		act[0].Mes("����Ǝv���܂���");
	TO
		act[2].Mes("�Ȃ������v���H");
	TO
		act[0].Mes("�ڌ���͌��\����܂����A����񂶂�Ȃ�����");
	TO
		act[2].Mes("�ւ�");
	TO
		act[2].E�v�l();
	TO
		act[2].Mes("�ז������ˁA�Z�����̂ł��ꂶ��܂�");
	TO
		act[2].Move(0, 5, 4);
	TO
		act[0].E�^��();
	TO
		act[0].Mes("���̗p�������񂾁H");
	END
}
//���C���V�i���I 11
void EVE_SUB::�S�����m�X�̉\()
{
	//�S�����m�X���o�X����Ƃ̉\
	START
		act[0].Set(EChara::�Z�I, 7, 4, DI::��);
		act[1].Set(EChara::�����t�@, 2, 2, DI::�E);
		BackChenge(EStage::�X��);
	TO
		act[1].Move(0, 2);
	TO
		act[1].Move(4, 0);
	TO
		act[1].Mes("���͂悤�������܂�");
	TO
		act[0].Mes("���͂悤");
	TO
		act[1].Mes("���������Ε����܂����H���܂����퉮���o����炵���ł���");
	TO
		act[1].Mes("���\�傫�ȉ�Ђ炵���ł��ˁA�m���E�E�E");
	TO
		act[0].Mes("�S�����m�X�E�E�F�|���Y");
	TO
		act[1].Mes("�����ł��A����ł��I");
	TO
		act[1].Mes("����ς育���m�ł�����");
	TO
		act[0].Mes("�O�̋Ζ��悾����");
	TO
		act[1].E����();
	TO
		act[1].Mes("�����A�����Ȃ�ł����I");
	TO
		act[0].Mes("����");
	TO
		act[1].Mes("�ǂ�ȏ��ł����H");
	TO
		act[0].Mes("�Œ�̕��퉮��������");
	TO
		act[1].Mes("���A�����ł����E�E�E");
	TO
		act[0].Left();
		act[0].Mes("�傫����Ђ������b�������̕��������Ă�킯����Ȃ������m�E�n�E������Ƃ��v���Ȃ�");
	TO
		act[0].Mes("�C�ɂ���K�v���Ȃ���");
	TO
		act[0].E�v�l();
	TO
		act[0].E����();
	TO
		act[0].Mes("�������������A�������P����낵��");
	TO
		act[1].Mes("�͂��I");
	END
}
//���C���V�i���I 12
void EVE_SUB::�S�����m�X�o�X()
{
	//�S�����m�X�E�E�F�|���Y���o�X
	//��͂藈�K

	//�z���C�g�i�C�g���J�X�����K
	START
		act[0].Set(EChara::�Z�I, 7, 4, DI::��);
		act[1].Set(EChara::�t�@�N�g, 2, 2, DI::��);
		BackChenge(EStage::�X��);
	TO
		act[1].Move(0, 2);
	TO
		act[1].Move(4, 0);
	TO
		act[1].Right();
		act[1].Mes("���͂悤�Z�I");
	TO
		act[0].Left();
		act[0].Mes("�����A���͂悤");
	TO
		act[1].Mes("���悢�斾���炵������");
	TO
		act[0].Mes("����");
	TO
		act[1].Mes("���邩�ȁH");
	TO
		act[0].Mes("�ǂ����낤��");
	TO
		act[0].Down();
		act[1].Down();
		act[2].Set(EChara::�J�N�V��, 6.5, 11, DI::��,false);
	TO
		act[2].Move(0, -5);
	TO
		act[2].Mes("���S�����m�X�̏]�ƈ�����������퉮�ƕ����āA�N���Ǝv����");
	TO
		act[0].E�v�l();
	TO
		act[0].Mes("�v���Ԃ肾��");
	TO
		act[2].Mes("�����A�P�N�Ԃ肭�炢����");
	TO
		act[0].Mes("���̗p���H");
	TO
		act[2].E����();
	TO
		act[2].Mes("�ׂ��O�ɁA�ǂ�ȓX�����Ă��������Ǝv���Ă�");
	TO
		act[0].Mes("�ׂ��̂͂��񂽂�̓X����");
	TO
		act[2].Mes("�������Ă�����̂����̂�����");
	TO
		act[0].E�v�l();
		act[1].E�v�l();
		act[2].E�v�l();
		act[3].Set(EChara::�J�m��, 6.5, 11, DI::��);
	TO
		act[3].Move(0,-3);
	TO
		act[3].E�v�l();
	TO
		act[3].Move(0, 3);
	TO
		act[2].Mes("���Ⴀ�ȁA���������撣���");
	TO
		act[2].Move(0,5);
	END
}
void EVE_SUB::�����t�@�Z���H()
{
	//�����t�@�̌Z�����H�A�h���S���Ƃ̑���
	//��N�ځA�O�т��I��
	START
		act[0].Set(EChara::�Z�I, 7, 6, DI::��);
		act[1].Set(EChara::�t�@�N�g,6,8,DI::��);
		act[2].Set(EChara::�w�����X,7,8,DI::��);
		act[3].Set(EChara::�g�E�c�O,8,8,DI::��);
		act[4].Set(EChara::�����t�@,7,11,DI::��);		
		BackChenge(EStage::�X��);
	TO
		act[0].Mes("���͂悤�������܂�");
	TO
		act[1].Mes("���͂悤�������܂�");
		act[2].Mes("���͂悤�������܂�");
		act[3].Mes("���͂悤�������܂�");
	TO
		act[0].Mes("�����͑�j���[�X������܂�");
	TO
		act[0].Mes("����A�����������ꂽ�炵��");
	TO
		act[1].E����();
		act[2].E����();
		act[3].E����();
	TO
		act[0].Mes("�Ƃ͌����Ă��A�������ꂽ�킯�ł͂Ȃ�");
	TO
		act[0].Mes("���̗؂��d���āA�w�ǃ_���[�W���^�����Ȃ������Ƃ�");
	TO
		act[0].Mes("���������n���^�[�̃p�[�e�B�[�͌��\��Q���o���炵��");
	TO
		act[0].Mes("��������ăn���^�[�����邩�A���݂��m�F����đ����邩�͕�����Ȃ�");
	TO
		act[0].Mes("�����A��苭�͂ȕ��킪���߂���̂͊m�����낤");
	TO
		act[0].Mes("�J���̕��͂���w�撣���ė~����");
	TO
		act[0].Mes("����ł͍������P����낵�����˂������܂�");
	TO
		act[1].Mes("��낵�����˂������܂�");
		act[2].Mes("��낵�����˂������܂�");
		act[3].Mes("��낵�����˂������܂�");
	TO
		act[0].E�v�l();
	TO
		act[0].E�^��();
	TO
		act[0].Mes("���������΃����t�@����́H");
	TO
		act[1].Mes("�����͋x�݂���Ȃ�����A�x������");
	TO
		act[3].Mes("�������ł���");
	TO
		act[4].Move(0,-2,2);
	TO
		act[0].Mes("���͂悤");
		act[1].Down();
		act[2].Down();
		act[3].Down();
	TO
		act[0].E�^��();
	TO
		act[0].Mes("�ǂ�����");
	TO
		act[0].E����();
		act[1].E����();
		act[2].E����();
		act[3].E����();
	TO
		act[4].Mes("�Z���񂪁E�E�E");
	TO
		act[4].E�v�l();
	TO
		act[4].Mes("�h���S���ɏP���āE�E�E");
	TO
		act[0].Mes("�܂����E�E�E");
	END
}