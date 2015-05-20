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

	void Set( double X, double Y, DI M, bool isUp = true);
	void Warp(double X, double Y, DI M, bool isUp = true);
	void Mes(const char *M);
	void HukiUp(bool isUp);
	void Move(double MX, double MY, int S = 4);
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
	/*
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
	*/

	/*1.1*/
	/*�v�����[�O*/
	/*��蕔�ɂ�铱���B*/
	static void _1_1_1();

	/*�J�X*/
	/*��l���ƃt�@�N�g�̓�l���X�܂��J�݂���������X�^�[�g�B*/
	static void _1_1_2();

	/*�����J�n*/
	/*����̐����J�n�I�Ǝv������A�z�R�J���p�̂�͂��𐻑����鎖�ɁB*/
	/*�����ŗ����������Ă��镚�����\����B*/
	static void _1_1_3();

	/*���̎��@�Ɖc�Ƌ���A*/
	/*����������A��ĕ��퉮�̎��@�ɗ���B*/
	/*�d�G��v�����ꂽ���A���J�����̂ł��َq��n���B*/
	static void _1_1_4();

	/*���̎��@�Ɖc�Ƌ���B*/
	/*�d�G�̗v���ł��َq��n���ꂽ���ɋN�����đ��������R�̗e�^�ł���Ă���A*/
	/*�s���ǂ�����������Ă��Ă��̏�����߂�B*/
	static void _1_1_5();

	/*���߂Ă̋q*/
	/*�����̗l�ɂ�͂��̐��Y�v��̊m�F�����Ă������A�l���K�˂Ă����B*/
	/*���̗p�� ? �ƕ����ƕ���𔃂��ɗ���������ƁH*/
	/*���q�҂͒����̂��߂Ɏ�����Ă���n���^�[���ƌ����̂ŁA���߂ĕ��킪�����B*/
	/*�Ȍタ�傭���傭�q������悤�ɂȂ�B*/
	static void _1_1_6();

	/*�h���S���n���^�[*/
	/*�܂����◈�q�A������邽�߂̕����T���Ă���Ƃ����B*/
	/*���Ȃ�Ė{���ɂ���̂��H�ƕ����ƁA�F�X�b�����Ă��ꂽ�B*/
	static void _1_1_7();

	/*��W�J�n*/
	/*�v������蕐��̔���s�����ǂ��B*/
	/*�ǉ��ŐE�l���ق����ɁB*/
	static void _1_1_8();

	/*���p�̗p*/
	/*��W���J�n���������A���퐻���̌o���҂��ƌ�����҂�����Ă���B*/
	/*���Ǎ̗p���鎖�ɁB*/
	static void _1_1_9();

	/*�����t�@�̗p*/
	/*���炵�����̎q���E�l�u�]�H�ɗ����̂ŃZ�I�͊�Ԃ��A�ڋq�u�]���ƕ�����A*/
	/*�Ƃ肠�����ڋq����W���Ă������ɂ��č̗p����̂ł������B*/
	static void _1_1_10();

	/*��͂��[�i*/
	/*�[�i���ɂȂ����̂ŁA��͂�����������ɏo�����B*/
	/*�������爳�͂��������̂��A�����͎󒍂𖳂��Ȃ鎖�ɁB*/
	static void _1_1_11();

	/*1.2*/
	/*	�V�������*/
	/*�����߂̈��A�ƁA�V����̎��ȏЉ�*/
	static void _1_2_1();

	/*�o�c�̐�������*/
	/*�Ј��������Ă����������A�Г����x������������������*/
	static void _1_2_2();

	/*�����ƒ�����c*/
	/*�ȑO�ɔ������ɗ��������c�̒c�������K�A*/
	/*�c����W����`���ė~�����A����ɐ�`����`�����Ƃ̎��B*/
	static void _1_2_3();

	/*�H�[���*/
	/*�t�����e�B�A�V���̋L�҂����K�B*/
	/*�J�X���R���̎�ނ��󂯂�A���X�̓����ɂ��Ă������B*/
	static void _1_2_4();

	/*�����̎��@*/
	/*�X�̏󋵂����ɕ��������K�A��͂��[�i����������B*/
	static void _1_2_5();

	/*1.3*/
	/*�H���̃X�X��*/
	/*�����߂̒���ŁA�ݔ������ɂ��Č��B*/
	static void _1_3_1();

	/*�����t�@�̌Z*/
	/*������c���ɂȂ����̂ŕ���𔃂��ɗ����A�����t�@�̌Z��l�����X�B*/
	/*���x�i�Ƃ��Ė����̖є瓙�������Ƃ��Œc���𑝂₵�Ă���炵���B*/
	static void _1_3_2();

	/*�J�m���H�[*/
	/*��͂����𐻑����Ă����J�m���H�[������̔̔����J�n�B*/
	/*�Ȃ�����荞��ł���B*/
	static void _1_3_3();

	/*�����ɂ���*/
	/*���v���o�Ă����̂ŁA�]�莑���̎g�����ɂ��āB*/
	static void _1_3_4();

	/*1.4*/
	/*�����߂̈��A*/
	/*���C�o���X�ւ̌��y�B*/
	static void _1_4_1();

	/*����̈�����l�g*/
	/*��c����Љ�ꂽ�Ƃ��ŗ��X�����A�����������̈����n���^�[�����X�B*/
	static void _1_4_2();

	/*�Ɍ��b��*/
	/*�V�������퉮���܂��o�����炵���A���̂��J�m�������X�B*/
	/*�����͂Ȃɂ��m���Ă���l�q�B*/
	static void _1_4_3();

	/*��`���*/
	/*���̕��퉮���������̂Ő�`���������悤�Ƃ������b�B*/
	static void _1_4_4();

	/*�ҋ����P�v��
	/*�t�@�N�g���X����������v�����Ă���ƕ����B*/
	/*�ׂ����Ă��邵���v���Ҍ����悤���ƌ���������ɁB*/
	static void _1_4_5();

	/*1.5*/
	/*������*/
	/*�Ɛт��D���ŋ������グ�邼�A�݂����Șb�B*/
	static void _1_5_1();

	/*�h���S���n���^�[�Ă�*/
	/*���̏��ɂ��Ă��ꂱ��B*/
	static void _1_5_2();

	/*���b�̎���*/
	/*�V���̃X�N�[�v�L���ŁA�[�����[��R���Ƃ��Ďg�����@�����p�������Ƃ̎��B*/
	/*����̃n���^�[�����������܂��B*/
	static void _1_5_3();

	/*�J��Ղ�z��*/
	/*�v���Ԃ�ɑ������X�A���b�̎������Ɠ��A�J�n5�T�N���L�O���čՂ�����鎖�ɂȂ����Ƃ��B*/
	static void _1_5_4();

	/*1.6*/
	/*������*/
	/*�J��Ղ肪�����ɂ��鎖�ƁA���b�̎������ɂ��Ă��ꂱ��*/
	static void _1_6_1();

	/*�n���^�[����g��*/
	/*�v���t�F�b�T�[�����K�A�������Œ�����c���g�傷��������B*/
	static void _1_6_2();

	/*�J��Ղ�ɗU��*/
	/*�Ղ�̓��͋x�݂Ȃ̂ŁA�����t�@��U������*/
	/*�����t�@�Z�����܂��ܖK��*/
	static void _1_6_3();

	/*�V�n���^�[���K*/
	/*��c�̐V�����l������B*/
	/*�K���̈����n���^�[�����������B*/
	static void _1_6_4();

	/*1.7*/
	/*������*/
	/*�J��Ղ�ƁA�n���^�[���ɂ��Č��y*/
	static void _1_7_1();

	/*�V����̊J��*/
	/*�t�@�N�g���W����p�̕���������Ă���B*/
	/*�Z�I�͑����������ƕԂ��A�����͕ςȐ��Ȃ𔭊��B*/
	static void _1_7_2();

	/*�J��Ղ�J��*/
	/*�������W������A�v�X�ɑ��o��*/
	static void _1_7_3();

	/*�w�����X�̗p*/
	/*�Ղ�̎��ɘI�V�ł������l���A��W�ɗ���B*/
	static void _1_7_4();

	/*1.8*/
	/*������* /
	/*�w�����X�̓o�p�ƁA�V���i�J���ɂ��āB*/
	static void _1_8_1();

	/*���̈�Y*/
	/*�����̃I�[�N�V�����ŗ��̓��������ɂ�����ꐦ�܂������z�Ŕ����B*/
	/*�h���S���n���^�[�Ɖ�b�A���̓X�̌��y���B*/
	static void _1_8_2();

	/*�Ɍ����b�藈�K*/
	/*�Ղ���Ō��������Ƃ��ŋɌ���������A��߂��ɗ���B*/
	/*���܂��ďI���B����͕����Ȃ������B*/
	static void _1_8_3();

	/*�����t�@�Z���K*/
	/*�h���S���̉\�ƁA�h���S���|�����[�I�ȁB*/
	static void _1_8_4();

	/*1.9*/
	/*������*/
	/*�J�񂪐i��ł��鎖�A�n���^�[���}�����Ă��鎖�ɂ���*/
	static void _1_9_1();

	/*�V�l�����Ɉ�������*/
	/*�t�@�N�g���w�����X�̕��j�ɕ����t����A�������킪�K�v���ƌ����B*/
	/*�t�@�N�g���V�Q���ۂ������ŁB*/
	static void _1_9_2();

	/*�����X*/
	/*���₪�点�ɂ���B*/
	static void _1_9_3();

	/*�n���^�[���m�̃g���u��*/
	/*�K���̈�����l�g�݂ƁA�V����n���^�[���X���Ńg���u�����N�����B*/
	static void _1_9_4();

	/*1.10*/
	/*������*/
	/*�q�Ƃ̃g���u���ɂ��āB*/
	static void _1_10_1();

	/*�v���t�F�b�T�[�Ă�*/
	/*�J��̐i�݋�ɂ��ĂƁA����̃g���u���ɂ��ē��B*/
	static void _1_10_2();

	/*�����t�@�Z�Ƃ̉�b*/
	/*����̎��Ԃɂ��Ęb������A�n���^�[���m�̃g���u���ɂ��āB*/
	static void _1_10_3();

	/*�E�Ɍ�����*/
	/*�n�ꂪ�����ɂ���B*/
	static void _1_10_4();

	/*1.11*/
	/*�E������*/
	/*�o�c�͏����ł��B���ɉ��������B*/
	static void _1_11_1();

	/*�E�S�����m�X�o�X�̉\*/
	/*�����t�@�Z����z���C�g�i�C�g�̔����ƃS�����m�X�o�W�̉\�𕷂��B*/
	static void _1_11_2();

	/*�E�g�E�W�̗l�q*/
	/*�ޏ����o�����炵���H(���������Ƃ�)*/
	static void _1_11_3();

	/*�E�h���S���ڌ����*/
	/*����̈����n���^�[�����X�A�h���S�����ǂ��̂����́B*/
	static void _1_11_4();

	/*1.12*/
	/*�E������*/
	/*�h���S���̖ڌ����ɂ��āA�΃h���S������̊J�����K�v�B*/
	static void _1_12_1();

	/*�E�S�����m�X�o�X*/
	/*�S�����m�X���V�K�o�X�A�x�X�������z���ɗ���B*/
	static void _1_12_2();

	/*�E�΃h���S������̊J��*/
	/*�΃h���S������̊J���󋵂ɂ��āB*/
	static void _1_12_3();

	/*�E�������X*/
	/*�S�����m�X�̏�񓙂����̂������Ă����B*/
	static void _1_12_4();

	/*2.1*/
	/*�E����*/
	/*�����t�@���������x���B*/
	/*�h���S���̏P�����󂯁A�����t�@�Z���܂ރn���^�[���������S / �s���s���B*/
	/*���_�K�����~����邪�A�\�͒����ɍL�܂����B*/
	/*�����t�@�͋x�ɂɓ���B*/
	static void _2_1_1();

	/*�E�S�����m�X�̓�������*/
	/*���O�̏��ʂ�A�S�����m�X���Z�[�����J�n����B*/
	static void _2_1_2();

	/*�E�h���S���\*/
	/*�h���S���P���ɂ��ăh���S���n���^�[�����X�B*/
	/*�h���S���̌��܋��̘b���A�F�X����B�ގ����Ă���Ă�����Ƃ��Ȃ�Ƃ��B*/
	static void _2_1_3();

	/*�E�J�m���H�[*/
	/*���㌸������@�Ɋ������J�m�������X�B*/
	/*���͂�Őf���Ă���B�����I�ɋ��͂��鎖�ɁA�Ɍ��Ƃ͋��͏o���Ȃ��B*/
	static void _2_1_4();

	/*2.2*/
	/*�E������*/
	/*�S�����m�X�̃Z�[���̉e�����ɂ���*/
	/*�����t�@���A*/
	static void _2_2_1();

	/*�E�����t�@�Ɖ�b*/
	/*�����������̂���*/
	static void _2_2_2();

	/*�E���X*/
	/*����̈����n���^�[�����X�A�S�����m�X���i�̓S�~���B*/
	/*������S�����m�X���i���l�K�L�������Ă���Ƃ��B*/
	static void _2_2_3();

	/*�E�Z�[���I��*/
	/*�S�����m�X����������~�߂āA���j���[�A�����n�߂�Ƃ̉\�B*/
	static void _2_2_4();

	/*2.3*/
	/*�E������*/
	/*�S�����m�X�̃Z�[���I���ɂ��āB*/
	static void _2_3_1();

	/*�E�����X*/
	/*�S�����m�X�̏o�X���s�Ƃ��̔w�i�ɂ��āB*/
	/*�������ǂ��Ƃ��B*/
	static void _2_3_2();

	/*�E���͂𑱂��邩�H*/
	/*�J�m�����S�����m�X���s�Ɋ�їE��ł���Ă���B*/
	/*������Z�p���͂͑����鎖�ɁB�t�@�N�g�͔��΁B*/
	static void _2_3_3();

	/*�E�h���S���̔�Q��*/
	/*�܂��A���ɏP���n���^�[�����S�����炵���B*/
	/*���̌��\�߂����Ƃ��B*/
	static void _2_3_4();

	/*2.4*/
	/*�E������*/
	/*�h���S���̋��Ђɂ��āB*/
	static void _2_4_1();

	/*�E�c�����X*/
	/*�S�����m�X�̎��s�ɂ��āA��Ԓc���B*/
	static void _2_4_2();

	/*�E�S�����m�X�A���j���[�A��*/
	/*�S�����m�X�Ђ��X������サ�ă��j���[�A���I�[�v���B*/
	/*�Ȃ����t�����e�B�A�X�~�X�Ɩw�Ǔ������킪���сA�Z�[�����J�n�B*/
	/*�]���͑����񕜂��������ł��B*/
	static void _2_4_3();

	/*�E�J�m�����X*/
	/*�Z�p���o�ɂ��ĒN�������������ŋc�_�������B*/
	/*���͑̐������􂷂�B*/
	static void _2_4_4();

	/*2.5*/
	/*�E������*/
	/*��񗬏o���ɂ��ĂȂ�*/
	static void _2_5_1();

	/*�E�V����̊J��*/
	/*�����������ŗ��Ɛ키�͖̂����ł́H*/
	/*�Ƃ������Ńw�����X���e�̐������Ă���B*/
	/*�[�����[�Ζ�̔������ǂ��̂����́B*/
	/*(�e�͊��ɑ��݂��Ă��邪�A���y�͂��Ă��Ȃ�)*/
	static void _2_5_2();

	/*�E�h���S���n���^�[���X*/
	/*�����镐��œ|���ɍs�����ɂ���炵���B*/
	/*�����t�@�͕��G�Ȋ����B*/
	static void _2_5_3();

	/*�E�����t�@�Z���X*/
	/*���������������t�@�Z�����X�B*/
	static void _2_5_4();

	/*2.6*/
	/*�E������*/
	/*�D�������ǁA�S�����m�X�ɋ��C���B*/
	static void _2_6_1();

	/*�E�����X*/
	/*�S�����m�X���i�̎����ƊJ��Ղ̍��m�B*/
	static void _2_6_2();

	/*�E�n���^�[���X*/
	/*�h���S���ɂтт��Ă�z��|�����Ƃ��Ă���z�����鎖�ȂǎG�k�B*/
	static void _2_6_3();

	/*�E�e��T���v��*/
	/*�e�̎��삪�����B�Ղ�œW�����鎖�ɁB*/
	static void _2_6_4();

	/*2.7*/
	/*�E������*/
	/*1�N�Ԃ�ɊJ��Ղ�����܂��B*/
	static void _2_7_1();

	/*�E�Ղ�ɗU��*/
	/*�����t�@���Ղ�ɗU���B*/
	static void _2_7_2();

	/*�E�J��Ղ�*/
	/*��N�Ԃ�̊J�ÁB*/
	static void _2_7_3();

	/*�E�J�m���H�[�����펖�Ƃ��I��*/
	/*��͂����Ƃɐ�O����Ƃ��B*/
	static void _2_7_4();

	/*2.8*/
	/*�E������*/
	/*�e�̓W�����������������B*/
	static void _2_8_1();

	/*�E�n���^�[����X*/
	/*�e�̊J���ɋ��͂��悤�Ƃ���Ă���B*/
	static void _2_8_2();

	/*�E�J���̐�*/
	/*����͏e�̊J�����������A��񗬏o�ɔ����悤�ƌ������ɁB*/
	/*�t�@�N�g����������B*/
	static void _2_8_3();

	/*�E�����������ꂽ�H*/
	/*���̖ڌ���񂪌����Ă���炵���B*/
	/*���̗؂���肵���l�������B*/
	static void _2_8_4();

	/*2.9*/
	/*�E������*/
	/*�������̉\�ɂ��āB*/
	static void _2_9_1();

	/*�E�����X*/
	/*�S�����m�X���e�̔��\����s���Ə��������B*/
	/*�t�@�N�g���^����B*/
	static void _2_9_2();

	/*�E�S�����m�X���e�̔��\��*/
	/*���̂��N�����B*/
	static void _2_9_3();

	/*�E�t�����e�B�A�X�~�X���e�̔��\��*/
	/*��������B*/
	static void _2_9_4();

	/*2.10*/
	/*�E������*/
	/*�e�̐����g���*/
	static void _2_10_1();

	/*�E�t�@�N�g�ސE*/
	/*���Ă����Ȃ��Ȃ����Ƃ��B*/
	static void _2_10_2();

	/*�E�V�����X*/
	/*�h���S���̓����ɂ��āB*/
	/*�t�@�N�g�����Ȃ��Ă�������݂����Ȋ����B*/
	static void _2_10_3();

	/*�E�e�̔̔��J�n*/
	/*�h���S�����������ꂽ���͉B�����B*/
	static void _2_10_4();

	/*2.11*/
	/*�E������*/
	/*�e�̔̔��͍D���B*/
	static void _2_11_1();

	/*�E�e�̗ʎY�v��*/
	/*����܂����Ă�̂łǂ�ǂ񑝎Y����B*/
	static void _2_11_2();

	/*�E�S�����m�X�P��*/
	/*�S�����m�X�������ł̕���̔�����P�ނ��鎖�ɁB*/
	static void _2_11_3();

	/*�E�g�E�c�O�ސE*/
	/*���ƂɋA��炵���B*/
	static void _2_11_4();

	/*2.12*/
	/*�E������*/
	/*�S�����m�X�̓P�ނɂ��āB*/
	static void _2_12_1();

	/*�E�����̉����ƃN�[�f�^�[*/
	static void _2_12_2();

	/*�E�����Ŕ����R�̖I�N*/
	static void _2_12_3();

	/*�E�G���f�B���O*/
	static void _2_12_4();
	};

	/*
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
	act[4].Set(EChara::�J�[��,6,10,DI::��);
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
	*/