#pragma once

enum class DI
{
	��,
	��,
	��,
	�E
};

enum class EM
{
	���� = 0,
	���� = 1,
	���f = 2,
	���� = 4,
	�{�� = 5,
	�n�[�g = 6,
	�h�N�� = 7,
	���� = 8,
	�^�� = 10,
	�v�l = 13,
};

enum class EChara
{
	�Z�I = 1,
	�����t�@,
	�t�@�N�g,
	�g�E�c�O,
	�V�G�z,
	�w�����X,

	�A�b�N�X = 10,
	�J�m��,
	�^�N�~,

	�u���� = 15,
	�G���U,

	�q�g�t���T�C = 20,
	�W���C�`,
	�P���q��,

	���[�N�I = 25,
	�|���T�[,
	�J�N�V��,
	
	�V�� = 30,
	
	�j�b�g,
	���C�u��,
	
	�T���_�[,
	�t�@�C�A,
	�A�C�X,

	�t�@�C,
	���f�B,
	�p���R,
	�����W,

	�K�C�A,
	�V�Y,

	�I�L�e��,

	����,
	�W���b�V��,
	���C�R,

	��蕔,

	�X�^�C�g,
	�n���t�@�h,
	�^�N�X,
	�S�N�g,

	�}�X�R��,

	���m,
	��t,
	�X��,

	�i��
};

enum class EStage
{
	�X�O = 0,
	���� = 7,
	�X�� = 1,
	��c�� = 5,
	���� = 8,
	�L�� = 6,
};

class ACTER{
	public:
	int x;//���҈ʒu
	int y;//
	int emo;//����
	int mx;//�c��ړ���
	int my;
	int sp;//�ړ����x
	int p;//���s�A�j��
	int m;//����
	int no;//�摜
	int huki_w;//��
	int huki_h;//����
	int huki_ud;//�\���ʒu
	int name_w;//���O����
	char huki_mes[3][101];//����
	char name[15];//���O

	void Set(EChara chara , double X,double Y,DI M,bool isUp = true);
	void Mes(const char *M );
	void HukiUp(bool isUp);
	void Move(double MX,double MY,int S = 4);
	void Emo(EM E);
	void Direct(DI di);

	void Up();
	void Down();
	void Left();
	void Right();

	void E����();
	void E����();
	void E���f();
	void E����();
	void E�{��();
	void E�n�[�g();
	void E�h�N��();
	void E����();
	void E�^��();
	void E�v�l();

	void DoMove();

};

class EVE_SUB
{
	public:
		static void Switch(int E);

		static void ����_�V�i���I();
		static void ����_���R�o��();
		static void ����_���_���̉�();
		static void ����_�q����`();
		static void ����_��q����();
		static void ����_������Ă�();
		static void ����_�V�F�ANo1();
		static void ����_��͂���D��();
		static void ����_�J��őO��();
		static void ����_���o�̕�();
		static void ����_���ɂ̑�();
		static void ����_�����̌�();
		static void ����_�����̋|();
		static void ����_�E�F�|���}�C�X�^�[();
		static void ����_�A�C�X�G�C�W();
		static void ����_�M������();
		static void ����_��n���^�[����();
		static void ����_����̏I���();
		static void ��͂��Ղ�();
		static void ���퉮�Ղ�();

		//���C���V�i���I 1
		static void �J�X();
		static void ��͂������J�n();
		static void �c�Ƌ���A();
		static void �c�Ƌ���B();
		static void �V�����();		
		static void �������();
		static void �ŋ��̃n���^�[();
		static void �l�ޕ�W�J�n();
		static void �g�E�c�O�̗p();
		static void �����t�@�̗p();
		
		static void ��͂��[�i();
		//���C���V�i���I 2
		static void �o�c�񃖌���();
		static void �o�c�̃X�X��();
		static void �X�^�C�g���@();//��͂��󒍉�
		static void ���b�̎���();
		static void �V�����2();
		static void �H���̃X�X��();

		//���C���V�i���I 3
		static void �o�c�O������();//�l�ޕ�W�ƁA�V���i�ɂ��Ẳ�c
		static void �����t�@�̌Z();	
		static void �V�G�z�̗p();
		static void �����̃X�X��();
		static void ����������();
		static void �J�m���H�[();
		static void �����v��();

		//���C���V�i���I 4
		static void �w�����X�̗p();
		static void �J���̃X�X��();
		static void �n���^�[����();
		static void ��`�̃X�X��();
		static void ����̈����O�l�O();
		static void �z���C�g�i�C�g();
		static void �l�l�g�̃n���^�[();

		//���C���V�i���I 5
		static void ���퉮�Ղ�z��();
		static void �������s();		

		//���C���V�i���I 6
		static void �Ɍ��b��();
		static void �g�E�c�O�ƋɌ�();

		//���C���V�i���I 7
		static void ���퉮�Ղ�J��();
		static void ��͂��Ղ�z��();

		//���C���V�i���I 8
		static void �h���S���̓�();

		//���C���V�i���I 9
		static void ��͂��Ղ�J��();

		//���C���V�i���I 10
		static void �J���();

		//���C���V�i���I 11
		static void �S�����m�X�̉\();

		//���C���V�i���I 12
		static void �S�����m�X�o�X();
		static void �����t�@�Z���H();

		//�T�u�C�x���g
		//�]�ƈ���b
		//�����t�@�A�ڋq�ɂ���
		//�t�@�N�g�A�����ɂ���
		//�w�����X�A�J���E���ǂɂ���
		//�V�G�z�A�����Ɋւ���
		//�����v�f

		//���X�Ƃ̗���
		//�J�m���H�[-��͂��A�H���֘A
		//�Ɍ��H�[-�g�E�c�O����
		//�z���C�g�i�C�g-�V�G�z
		//�S�����m�X�E�F�|���Y-���C���X�g�[���[

		//�n���^�[��b
		//�V���A�{�X���Ƃ̑Ό�
		//�l�l�g�A
		//�������Ȃ�
		//�����t�@�Z��
		//����B

		//���̑���b
		//�n���^�[����
		//�������Q���܂ɗV�тɗ���
		//�}�X�R�~�Q�傫�ȃj���[�X������Ǝ�ނɗ���
		//���{�Q���܂ɔ[�i���ɃC�x���g

		static int Contest();
};

