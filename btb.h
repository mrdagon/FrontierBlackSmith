#pragma once

#include "DxLib.h"
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <vector>

#define HUN_M 10000 //�`���ҍő吔
#define JOB_M 50	//�E��ő吔
#define SHOP_M 5	//�X�ő吔
#define WEP_M 400	//�����ލő吔
#define SHOP_SP 1000 //���X�\�ő吔
#define EMP_M 500	//�]�ƈ��ő吔+
#define ENE_M 50	//�G���
#define DUN_M 100	//�_���W������
#define EVE_M 400	//�C�x���g��
#define LOG_M 100	//���O�ő吔
#define WIN_M 12	//�E�B���h�E��
#define MANA_M 300	//�o�c�헪���
#define YEAR_M	 5	//�ő�N��
#define MANTH_M (12*YEAR_M)	//�ő匎��
#define WEEK_M  (48*YEAR_M) //�ő�T��
#define DAY_M  (336*YEAR_M)	//�ő����
#define EIGYOU_T 54
#define WEP_T	4//�����
#define MANA_T	5//��p�^�C�v
#define NIN_T	3
#define KEN_T	3

#define NOU_NO	 99 //�_��z��Y��
#define P		 data.play //�v���C���[����
#define EVE_SKIP 0	//�C�x���g�X�L�b�v�t���O

//�o�����X�����n�d�v���l
#define WEP_EXP_RATE 72000//����J�����x���t�o����,1�㏸�ɂ�10%�Âオ��
#define WEP_EXP_RATE2 3600
#define H_LV_UP		  1000

#define PI      3.14159265358979323846f//���K��

	class HUNTER{//�`����
		public:
		int no;//�z��Y����

		int life;//������
		int lv;//���x��
		int exp;//�o���l
		int job;//�E��
		int sta[4];//�X�e�[�^�X
		int hp;//����HP
		int skill;//���Z
		int wep_t;//������
		int rank;//�W���u�����N
		int dun_lv;//�_���W�������x��

		int money;//���ݎ���
		int wep_c;//���폊����
		double wep_a[8];//����U��
		int wep_d[8];//����ϋv
		int wep_s[8];//�w���X��
		int shop_wepn[SHOP_M];//�Ō�ɗ��X�i����
		int shop_koukan[SHOP_M];
		int senden_boost[SHOP_M];//��`�u�[�X�g
		
		int like_t[3];//�����A�������悳�A�����̉e���x

		//�s�����
		int act;//�s�����//0�ҋ@�A1�X���A2�ڋq���A3�N���[�}�[�A4�ޓX�A5�X�ڋߒ�
		int act_no;//�X�ԍ��A�_���W�����ԍ�
		int b_w;//�u���b�N�x//����,�������A�N���[�}�[���t�o
		int stress;//��������
		int wait;//�ҋ@����
		int talk_max;//�Q�[�W�ő�
		int talk_emp;//���ݑΉ����Ă���X��

		int x;//���q�\���px���W�Ay���W
		int vx;//�q�i�s����
		int y;

		//�f���^�Œǉ�
		int p_card[SHOP_M];//�|�C���g�J�[�h����

		int sinazoroe(int S);

		int select_byte();
		int select_rest();
		int select_dungeon();
		int select_shop();
		int select_item();
		int taiou_emp(int E,int A);
		int select_act();
		int sell_item();
		int time_up();
		int act_now();

		int shop_out();

		int lv_up();
		int vs_enemy(int D);
		int shop_enter();		
		int crame_hantei(int N);

        int cul_yosan();

	}hun[HUN_M];
	class JOB{//�E��
		public:
		char name[21];
		int gra;//�摜
		int st_up[4];//������
		int st_st[4];//��{�X�e�[�^�X
		int next_J[3];//�h���W���u
		int wep_t;//������
		int rank_up;//�����N�A�b�v���x��
		int rank;//�����N
	}jobs[JOB_M];
	class SHOP{//�X
		public:
		std::string name;
		int icon;//�X�A�C�R��
		int color;//�X�F

		int no;
		int emp_cnt;
		int emp_kou;//�H�[�l��
		int emp_list[EMP_M];//�X�����X�g

		double money;//����
		double b_w;//�u���b�N�x0�`100
		int koubou_t;//�H�[�c�Ǝ���
		int koubou_n;//���̓��H�[����

		int create_get[KEN_T];//�l���J���o���l
		int create_exp[KEN_T];//�J���o���l
		int create_lv[KEN_T];//�J����

		int nougu_req;//�_�k���v��

		int wep_rest[WEP_M];//�݌ɐ�
		int wep_cre[WEP_M];//�J���� -1�J���s�� 0�Ђ�߂��\�@1�J���� 2�����\
		int wep_hday[WEP_M];//�M��������
		int wep_make[WEP_M];//���Y�i�s�x
		int wep_kaicnt[WEP_M];//���ǉ�
		int wep_kaiexp[WEP_M];//���ǉ�
		int wep_make_t[WEP_M];//�����Y��
		int wep_make_now[WEP_M];//�������Y��
		int wep_kai_now[WEP_M];//���Ǔ������ݒn

		//���ǉ�
		int ninki_kai[WEP_M];//�l�C
		int atk_kai[WEP_M];//�U��
		int dur_kai[WEP_M];//�ϋv
		int cost_kai[WEP_M];//�R�X�g
		int time_kai[WEP_M];//����

		int wep_sb[4][3];//�����{�J���\��//�悳�E�₷���E�������悳

		int yasuuri;//��ي���
		int price_rate;//��ي��� %
		double yasuuri_efe;//�Z�[������

		int bumon_lv[MANA_T];//�o�c�A�����A�H���A�J���A��`

		int bumon_exp[MANA_T];//

		int total_saiyou;//�݌v�̗p��
		int total_yame;//���߂��l�̍��v�Α�����

		double lv_ave;//���σ��x��
		double pay_ave;//���ϋ��^
		double mon_ave;//���ϋΑ�����
		double bw_bonus;//�u���b�N�x�{�[�i�X�l

		//���ǌ�̎��␳-����Čv�Z����
		double ninki_j[WEP_M];//�l�C
		double atk_j[WEP_M];//�U��
		double dur_j[WEP_M];//�ϋv
		double cost_j[WEP_M];//�R�X�g
		double time_j[WEP_M];//����

		int yasumi_max;//�x����			�x�ݐ��A���[�e�[�V�����ŋx�܂��܂�
		int zangyou;//�ő�c�Ǝ���		1 = 10��

		int seizou_b;
		int kairyou_b;//���ǃ{�[�i�X
		int tukare_b;
		int sekkyaku_b;
		int kaihatu_b;
		int sabaki_b;
		int stress_b;
		int yaruki_b;//���C�㏸��

		int size;
		int kouji;//�H���c�����

		int souko_now;//�q�Ɍ���//���߂Ōo���
		int souko_max;//�q�ɍő吔

		int tana_now;//�I���ݐ�//�W�q�͂ɉe��
		int tana_now_t[4];//�e������

		int teikyuu;//��x��
		int cust_cnt;//���q��
		int cust_cnt_t[WEP_T];//�����ޖ��̌��ݗ��q��
		int cust_wep[WEP_T];//�����ޕʗ��q��
		int cust_list[SHOP_SP];//���X�q���X�g
		int cust_gold[SHOP_SP];//���X�q����S�[���h

		double p_mp;//�񕜃}�l�W�����g�|�C���g
		double n_mp;//���݃}�l�W�����g�|�C���g
		int use_mana;//�g�p��p
		int mana_ok[MANA_M];//�o�c�헪�g�p�� -1�Ђ�߂��s�� �Ђ�߂��\�@1�g�p�\
		int syou_mp[MANA_M];//����MP
		int syou_money[MANA_M];//�����
		int mana_rest[MANA_M];//�c��g�p��
		int mana_cnt[MANA_M];//�g������
		int mana_day[MANA_M];//�M���Ă���̓���

		int sellc_day[DAY_M];//�̔���
		int sell_day[DAY_M];//����グ
		int cust_day[DAY_M][WEP_T];//����ʋq��
		int seizc_day[DAY_M];//������
		int seiz_day[DAY_M];//������

		int sellc_mon[MANTH_M];//�̔���
		int sell_mon[MANTH_M];//����グ
		int cust_mon[MANTH_M];//�q��
		int seizc_mon[MANTH_M];//������
		int seiz_mon[MANTH_M];//������

		int emp_mon[MANTH_M];//�ٗp��//�����Ɍv�Z
		int manege_mon[MANTH_M];//�o�c��p��p
		int etc_mon[MANTH_M];//��,���q�����Ɍv�Z
		int incom_mon[MANTH_M];//���v�����Ɍv�Z
		int nougu_mon[MANTH_M];//�_��[����
		int total_mon[MANTH_M];//�����Y//�����Ɍv�Z
		int kabu_mon[MANTH_M];//����

		int shera_wepd[DAY_M][WEP_T];//�e����̔̔��V�F�A
		int shera_wepm[MANTH_M][WEP_T];//�e����̔̔��V�F�A

		int holiday;//�x���ݒ� 0�c��,����ȊO�͉c�Ƃ��Ȃ�
		double timeido;//0~100

		double kabu_price;//����
		int kabu_max;//���ő吔
		int kabu_cnt[5];//���ێ���,0���Њ�,1����,2�z�R,3������,4�V����
		int kabu_rank[5];//���̃����N
		double kabu_rate[5];//���ێ���
		//AI�p
		int ai_like[5];
		//�ǉ��d�l��
		int mana_b[MANA_T];//��p�g�p�l�o�␳
		int mana_gb[MANA_T];//��p�g�p�����␳

		int mensetu_lv;//�ʐڃ��x��

		int kaihuku_b;
		int kaihuku_bs;//�̗͏���␳�A�V����
		int exp_b;//�o���l�␳
		int exp_bs;//�o���l�␳�A�V����
		int monster_b;//�N���[�}�[�������␳
		int syakai_b;//�Љ�l�x�ω��{�[�i�X
		int hp_up_b;//HP������
		int sei_up_b;//����������
		int kai_up_b;//�J��������
		int kya_up_b;//�q�J������
		int sek_up_b;//�ڋq������
		int kega_b;//���䔭����

		int sinn_b;//�V����D���x�{�[�i�X

		int mp_ninnzuu;//�l���ɂ��l�o�񕜃{�[�i�X

		int sk_pup;//�X�L�������m��
		int sk_rup;//�X�L�����]�m��
		int sk_qup;//�H�X�L���ω��m��

		int kabu_buy;//�������
		int nougu_up;
		int kyuuryou_b;//�����x������
		int risoku_rate;//�؋�����
		int risi_rate;//�������q
		int cost_b;//������␳
		int atk_b;//�U���̓{�[�i�X�A%
		int dur_b;

		int kaicost_b;//�J���R�X�g�␳

		int bukimatu_b;//����Ղ�{�[�i�X
		int turumatu_b;//��͂��Ղ�{�[�i�X
		int tax_b;//�ŋ���

		int hirameki_dayb;//�M���Ȃ������{�[�i�X
		int hirameki_b[WEP_T];//�����ʑM���␳
		int senden_b;//��`�␳

		int kaizen_week;//���P�T��

		int wep_medama[7];//�ݒ蒆�̕���
		int medama_max;
		double medama_wept[4];
		double medama_zoku[3];


		int ken_b[KEN_T];//�����o���␳

		int otona_b;//��l�����␳

		int ninki_b[NIN_T];//�W�q�␳�A������

		int koukan_down;//�D���x����

		int saitei_koukan;//�D���x�Œ�l

		int jisyoku_b;//���E�m���␳

		int eve_efe;//�C�x���g�ɂ��������
		int eve_turn;//������ʎc�莞��

		int clear_cust;
		int clear_sell_total;
		int clear_sell[5];
		int clear_turuhasi;
		int clear_wepcre;
		int clear_taikai;
		int clear_boss;

		int kouji_end();
		int start_sell(int Wari,int D);

		int senden_syori(int HIT,int LV);
		int senden_day();

		int hirameki_wep();
		int hirameki_mana();

		int kairyou(int W);
		int make(int W);
		int kaihatu(int W);

		int day_mana();
		int day_start();
		int mon_start();

		int cul_seiz_kair();
		int cul_kenkyuu();

		int cul_ave();
		int cul_kaihosei();
		int cul_timeido();
		int cul_kaburate();
		int cul_medama();

		int medama_check(int W);

		int goal_check();//�S�[������

		int kyuubo;

		int reset();

		int g_cust;//�����q��
		int g_kabu;//����������
		int g_sell_t;//������グ��
		int g_sell[4];//�����ʔ���グ��
		int g_turu;//��͂������Y��
		int g_wepcre;//���푍�J����
		int g_money;//��������
		int g_taikai;//�����_��
		int g_boss;//���{�X������

		int eve_random();//�����_���C�x���g

        void getumatu();

	}shop[SHOP_M];
	class WEPON{//����
		public:
		std::string name;
		std::string info;//������
		//char name[31];//���햼�O
		int type;//������
		int zoku;//�W�q����
		int rank;//����J�������N
		int atk;//�U����
		int dur;//�ϋv
		int ninki[NIN_T];//�l�C�At,y,k
		int seizou_cost;//��������
		int price;//��{�̔��z
		int priceOri;//��Փx�␳�O�̔��z
		int create_time;//�J������
		int make_time;//�����H��
		int req_clv[KEN_T];//�K�v�J�����x��
		int color;//�F
		//���ǂ��₷��
		int kairyou_up;
		int gazou;
		int mtype;//�ڋʕ␳�l
		int mzoku;
		int req_mana;//�M���ɕK�v�Ȑ�p
	}wep[WEP_M];
	class EMPLOY{//�J����
		public:
		std::string name;
		int name_no;
		//char name[21];//���O
		int no;

		int gra;//�摜
		int shop_n;//�z���X�A���E�X
		int shop_like[SHOP_M];//�D���x
		int now_job;//���ݏ� 0���E 1�A�E 2���� 3�j�[�g
		int mensetu[5][SHOP_M];//�ʐڏ󋵁A�X�e�[�^�X�A�X�ԍ�
		int req_jinji[5];//�ʐڐ����ɕK�v�Ȗʐڗ�
		int job;//�E��
		int shift;//�V�t�g
		int shift_n;//�V�t�g�ύX
		double sun;//���C�x�A�X�g���X
		int lv;//���x��
		int req_turn;//�o���^�[��
		int exp;//�o���l
		double hp;//�c��HP 0�`100%
		int tension;//���C
		double b_w;//�u���b�N�x�A0�`100%
		int konjyou_k;//�v�Z��̍���
		int konjyou;//����

		int rest;//����A���׊���
		int pay_money;//���ݒ���
		int req_money;//�v������
		int req_money_h;//�v�������␳
		int req_rate;//�v�����[�g

		int chan_tai;//�ҋ��ύX 0���̂܂܁@1���� 2���� 3����
		int st[3];//���݃X�e�[�^�X
		int st_st[3];//�ω���AHP���
		int st_up[3];//�X�e�[�^�X������
		int skill;//�X�L��
		int grow_t;//�����^�C�v
		int wait;//�ҋ@����-�X��
		int kinzoku;//�Α�����

		int work_cnt;//���ԁA�J������
		int rote_type;//1�`24-�Čv�Z����
		int sell_now;//������A�J���݌v
		int eve_flag;//�C�x���g�l�ރt���O�A��Ή��ق��Ȃ�

		int pb_rest;//�}�C�i�X�A�Í����c������A�z���C�g�A�������c�����
		int pb_count;//�Í��A�����|�C���g

		int tension_change();
		int manzoku_cul();
		int select_shop();
		int status_cul();
		int skill_change();
		int skill_efe(int UD);
		int month_emp();

		int yame(int MES);
		int plus(int S);
		int lv_up();

		int cul_man();

		int day_start();
		int mon_start();

		int hp_lose(int R);
		int hp_gain(double R);

		int rest_check();

		int make();

		int intai;//���ފm��

	}emp[EMP_M];
	class ENEMY{//�G
		public:
		char name[21];//���O
		int st[4];//�X�e�[�^�X�l
		int exp;//�o���l
		int money;//����
		int skill;//�X�L��
	}ene[ENE_M];
	class DUNGEON{//�_���W����
		public:
		int type;//�_���W�����^�C�v//��A�R�A���A�X�A��A��
		int boss_t;//�{�X�^�C�v
		int boss_max;//�{�X�ő�̗�
		int boss_hp;//�{�X�c��̗�
		int clear_f;//������
		int ene_t[8];//�o���G��//���m���A�����푰���������X�g����
		int x,y;//�_���W�����ʒu
		int seek;//�T���x-1������,0�ڕW,1�����ς�
		int root[5];//�q����_���W����
		int root_k[5];//����
		int root_t[5];//�T���x1�ȏ�T����
		int root_p[5];//������Փx
	}dun[DUN_M];
	class MANA{//�o�c��p
		public:
		//char name[51];//���O
		std::string name;
		std::string help;//������
		std::string zukan;
		std::string seido_h;//������

		int rank;//�����N
		int icon;//�\���A�C�R��
		int b_w_u;//�u���b�N�nor�z���C�g�n//������
		int b_w_d;//�u���b�N�nor�z���C�g�n//������
		double b_w_c;//�u���b�N�x�ω�
		int type;//����
		int seido;//���x�n		const int M_ROUD = ;//�J���g���̌���

	}mana[MANA_M];
	class GRAPH{//�摜
		public:
		int unit[300][12];//�J���ҁA�q�摜
		int wep[400];//����
		int ico[117];//�V�X�e���摜
		static const int icon_m = 117;
		int move[18];//�_���W�����A�C�R��
		int emo[20];//�\��
		int win[99];//�E�B���h�E
		int back[100];//�w�i	
		int map;
		int moji[60];//�����ƕ���
		int moji_b[80];//�������̂Q
		int huki[2];//�C�x���g�p���o��
		int title[10];
		int shop[5];//�X�O��

		int title_txt;
		int title_sub[10];
	}gra;
	class COLOR{//�F
		public:
			int kuro;
			int siro;
			int aka;
			int ao;
			int midori;
			int hai;
	}color;
	class WINDOW{//�E�B���h�E�A�C���^�[�t�F�C�X�A���я�
		public:
	
		int ok[WIN_M];//�E�B���h�E�J���邩�ǂ���

		int x[WIN_M],y[WIN_M];//�E�B���h�E�ʒu
		int sx[WIN_M],sy[WIN_M];//�E�B���h�E�傫��
		int smax[WIN_M];//�ő�x
		int smini[WIN_M];//�Œ�x
		int sf[WIN_M];//�T�C�Y�t���O
		int scr_cy;//�X�N���[���͂񂾈ʒu
		int scr_ccy;//�͂񂾂Ƃ��̂r�b�q�ʒu
		int scr[WIN_M];//�X�N���[����
		int scr_on[WIN_M];
		int scrm[WIN_M];//�X�N���[���ő�l
		int hide[WIN_M];//�d�Ȃ���
		int on[WIN_M];//�\�����
		int drag;//�͂�ł���
		int dx,dy;//�͂񂾈ʒu
		int sc;//�T�C�Y�ύX���t���O

		//int map_hyouji;//�}�b�v�\�����[�h
		int syousai_hyouji;//�ڍו\�����[�h
		int graph_hyouuji;

		int wep_sort;//����\�[�g���

		int req_hyouji;//���E�҃X�e�\��
		int emp_hyouji;//�ٗp�\���^�C�v
		int ts_hyouji;//�ҋ����V�t�g�\��
		int mana_hyouji;//��p�\���ؑ�
		int mana_rock;//��K���\��

		int syu_set;//���ݕ\�����x
		int syu_now;//���ݕ\��
		int syu_year;
		int syu_mon;
		int syu_day;
		int syu_hyouji[12];
		int syu_pars[16];//�O�Nor�O���\���p

		int shear_s[5][4];//�X�V�F�A�A���z
		int shear_p[5][4];//�X�V�F�A�A�Ɛ藦
		int shear_t[4];

		int req_list[EMP_M];//���l���X�g
		int kai_list[WEP_M];//�J�����X�g
		int mana_list[MANA_M];//�}�l�W���X�g

		int req_m;
		int kai_m;
		int mana_m;

		int info_no;//�w���v���ʔԍ�
		int info_t;//�w���v���ʎ�ʔԍ�
		int info_taiguu;//�ҋ��p�w���v
		int info_on;//�w���v�\��ON/OFF
		//1~10�e�E�B���h�E
		//11�@�}�b�v
		//12�@�㕔�^�u
		int help_id;
		int help_time;
		//����E�B���h�E
		int wfold_h[7];//�t�H���_����
		int wfold_cnt[7];//�t�H���_����
		int wfold_list[7][WEP_M];//����t�H���_���g
		//�l���E�B���h�E
		//�X��,�E�l,�ҋ�
		int efold_h[WEP_M+4];//�t�H���_����
		int efold_cnt[WEP_M+4];//�t�H���_���l��
		int efold_mem[WEP_M+4][100];//�e�t�H���_�̒��g
		int efold_s[WEP_M];//�E�l�t�H���_����

		int tfold_h[10][2];//�ҋ��E�B���h�E
		int tfold_cnt[10][2];
		int tfold_mem[10][2][100];
	}wind;
	class LOG{//�s�����O
		public:

		class LOGG{
			public:
			int type;//0,���َ��E,1�ٗp,2�a�C,34567��p�g�p,8
			//��p�g�p 3~7�@��
			//���َ��E 0	��
			//�a�C 2		��

			//�Z�[���n�܂� 9�@��
			//�Z�[���I��� 10 ��
			//�H���n�܂� 11 ��
			//�H���I��� 12 ��
			//�u�[���ω� 13 ��
			//��� 14
			//�{�X���� 15
			//���̑��C�x���g 16

			//�J���\1000~
			//�J���I��2000~ ���,3000~�@��Ԉȍ~

			int shop;//�Ή��X��,0�`4�e�X��,5�S��
			int date;//���t
			//std::string str;//���e
			//int ssize;
			char str[64];

			LOGG(){

			}

			~LOGG(){

			}
		};

		int mode;//�\�����[�h
		//0 ���ׂ�
		//1 ���X�܂̂�
		//2 ���XA
		//3 ���XB
		//4 ���XC
		//5 ���XD
		//6 �S�̂̂�

		int cnt;//���O�̐�
		std::vector<LOGG> log;
		int loc;//�X�N���[���ʒu

		int add(const char* M,int T,int S);

	}logu;
	class DATA{//�S�̏��
		public:
		int play;//�v���C���[����
		int nando;//��Փx
		int mode;//�Q�[�����[�h
		int day;//���t//1�t���[��10�b
		int play_time;//���v���C����
		int ver;//�f�[�^�̃o�[�W����
		
		int game_over;//�I���t���O- 100�̈ʂ��������́A0~11�����������A-1�͏I���O

		int yer;//�N
		int mon;//��
		int time;//����
		int tenki;//�V�C

		int jinkou;//�l��
		int jinkou_start;
		int jinkou_max;//�l�����[�v�����ő吔
		int jinkou_up;
		int total_des;//���ҍ��v
		int des_mon[MANTH_M];//�����̎���
		int jinkou_mon[MANTH_M];//���ʂ̐l��

		int shop_cnt;//�V���b�v��

		int kami_ikari;//�_�̓{��
		int creame_rate;//�N���[�}�[������
		int kairyou_rate;//�S�̉��ǌo��
		int hirameki_rate;//�S�̑M���m��
		int exp_rate;//�o���l���[�g
		int st_rate;//�X�e�[�^�X���[�g

		int taiguu_ok;//�ҋ��ύX��

		int back;
		int eve_target;

		int senden;//�J��҂̕�W�Ɛ�`��

		int wep_ganso[WEP_M];//���c�{�[�i�X

		int eve_flag[EVE_M];//�C�x���g�p�t���O
		int font[5];//�t�H���g
		int holiday;//�x���t���O
		char week[8][4];//�j����
		char tainame[4][5];//�ҋ���
		char skill_job[36][21];//�X�L����
		char skill_info[36][41];//�X�L��������

		char skill_vs[19][5];//�X�L���퓬
		int window_x,window_y;//�𑜓x
		int wide;//���C�h�t���O

		int taikai[2];//�����Ǝ��

		std::string win_name[12];
		std::string win_name_s[12];

		int now_save;//�g�p���̃f�[�^�X���b�g

		int mana_icon[5];
		int kabu_cnt[5];//����
		double kabu_price[5];//����

		//���Œǉ�
		int boom;//���݂̃u�[��
		int boom_rest;//�u�[���c�莞��

		std::string nanndo_n[5];//��Փx�\���p
		std::string mode_n[19];//���[�h�\���p

		int mode_icon[19];

		DATA(){
			mana_icon[0] = 11;
			mana_icon[1] = 53;
			mana_icon[2] = 95;
			mana_icon[3] = 7;
			mana_icon[4] = 78;
			
			data.mode_icon[0]  = 23;
			data.mode_icon[1]  = 23;
			data.mode_icon[2]  = 23;
			data.mode_icon[3]  = 23;
			data.mode_icon[4]  = 23;
			data.mode_icon[5]  = 23;
			data.mode_icon[6]  = 23;
			data.mode_icon[7]  = 23;
			data.mode_icon[8]  = 23;
			data.mode_icon[9]  = 23;
			data.mode_icon[10] = 23;
			data.mode_icon[11] = 23;
			data.mode_icon[12] = 23;
			data.mode_icon[13] = 23;
			data.mode_icon[14] = 23;
			data.mode_icon[15] = 23;
			data.mode_icon[16] = 23;
			data.mode_icon[17] = 23;
			data.mode_icon[18] = 23;
		}
		//�ڕW�l

		int goal_cust;//�ڕW���q��
		int goal_kabu;
		int goal_sell_t;//�̔��z
		int goal_sell[4];//�̔��z
		int goal_turu;
		int goal_wepcre;
		int goal_money;
		int goal_taikai;
		int goal_boss;

		//���s�t�@�C���f�B���N�g��
		char szDir[_MAX_DIR];

		int new_load;//�V�Kor�ǂݍ��݃t���O

		int req_act[12];//�e���̏���s���� 600��1�`1.5����

		int mana_max[5];//�e�n�����̐�p��
		int mana_index[MANA_M];//��p�̐}�ӕ��я�

	}data;
	class INP{//���͏��
	public:
		char p_k[256];//�L�[����
		char d_k[256];
		int d_no;//�h���b�O���Ă���Ώ�
		int d_type;//�h���b�O���Ă���^�C�v
		int m_x,m_y;
		int m_RC,m_RD,m_RO,m_RG,m_LC,m_LD,m_LO,m_LG;//�N���b�N�A�h���b�O�A�����A������
		int m_H,m_HC;//�z�C�[���N���b�N�A�ω�
	}Inp;
	class OPTION{//�ݒ�
		public:
		int v_ram;//V����
		int full_scr;//�t���X�N���[���t���O//�r���ύX�s�\
		int win_skin;//�E�B���h�E�X�L��
		int speed;//�Q�[���X�s�[�h//ini�ɕۑ����Ȃ�
		int speed_max;//������
		int speed_def;//�ʏ푬�x
		int bgm_size;//BGM����//�ۑ�����//�r���ύX�\
		int wev_size;//���ʉ�����//�ۑ�����//�r���ύX�\
		int window_x;
		int window_y;
	}opt;
	class EVENT{
		public:
		//��������
		int flag_req[3];//�K�v�t���O
		int flag_nreq[3];//�s�v�t���O
		int type;//�V�i���I�A�����_��
		int turn_req;//���ԏ���
		int time_req;//��������
	}eve[EVE_M];
	class SOUND{
	public:
		int bgm[100];
		int se[100];
	}sou;
	class SAVE_RABEL{
		public:


		class DATA{
			public:
			int day;//����
			int mode;//�v���C���[�h
			int shop;//�X�ԍ�
			int dif;//��Փx
			int time;//���v���C����
			int game_over;//�N���A���
			int ver;//�o�[�W����
			std::string name;
			DATA(){

			}
		};

		int cnt;
		std::vector<DATA> list;

	}rabel;
	class SYSTEM{
	public:
		int help_flag[100];//�w���v�����t���O-�V�X�e��
		int pass_on;//
		int clear;//
		//���ьn
		int medal_cnt[100];//���_��������
		int medal_gold[100];//���_������
		int medal_nanndo[100];//���_����Փx
		std::string medal_name[100];
		std::string medal_info[100];

		int medal_type[3];//��ޕʏ�����

		//
		int total_sell;//�̔�����
		int total_cust;//�����q��

		int total_sellc[4];//������グ�A�����ʁ�
		int total_make;//����������
		int total_makec;//�������R�X�g��
		int total_kyuuryou;//���v������
		int total_matokku;//����͂���
		int total_kaihatu;//�J���񐔁�
		int total_senden;//��`��
		int total_day;//�o�c������
		int total_koyou;//�ٗp�񐔁�
		int total_kaiko;//���ى񐔁�
		int total_jisyoku;//���E�񐔁�
		int total_haijin;//�p�l���񐔁�

		int score_record[20][18];

		int nanndo_flag;//�����Փx�t���O,-1�`9
        bool play_flag[18];//���[�h��V�ׂ邩�ǂ����t���O

		int win_cnt[14];//�����ʏ�����+�G���f�B���O�Q��

		int mana_total[300];//��p�݌v�g�p
		int wep_maxlv[400];//�ō����x��
		int wep_maket[400];//������
		int wep_cret[400];//�J����

		SYSTEM(){
			play_flag[0] = true;
		}

		int date;//�������̓��t

	}sys;
//�֐�
	class FUN{//�֐��N���X
		public:
		//�^�C�g�����
		int main(void);
		int title(void);
		int select_mode(void);
		int load_mode(void);
		int option(void);
		int wep_db(void);
		int mana_db(void);
		int record_db(void);
		int medal_db(void);
		int credit_db(void);

		//�Z�[�u�����[�h��ʁ�����
		int data_save(int N);//�f�[�^�̕ۑ�
		int data_load(int N);//�f�[�^�̓ǂݍ���
		int load_rabel();//���x���̓ǂݍ���
		int sys_save();
		int sys_load();
		//�����ݒ�̍쐬
		int make_define();
		int make_dungeon();//�_���W�����̍쐬
		int make_map();
		int make_hunter(int L,int J = -1);//�n���^�[�̍쐬
		int make_tenin();
		int make_start(void);//�����X�e�[�^�X�̑��
		int mode00_set(void);//�e���[�h�̏����l�Z�b�g
		int mode01_set(void);//�e���[�h�̏����l�Z�b�g
		int mode02_set(void);//�e���[�h�̏����l�Z�b�g
		int mode03_set(void);//�e���[�h�̏����l�Z�b�g
		int mode04_set(void);//�e���[�h�̏����l�Z�b�g
		int mode05_set(void);//�e���[�h�̏����l�Z�b�g
		int mode06_set(void);//�e���[�h�̏����l�Z�b�g
		int mode07_set(void);//�e���[�h�̏����l�Z�b�g
		int mode08_set(void);//�e���[�h�̏����l�Z�b�g
		int mode09_set(void);//�e���[�h�̏����l�Z�b�g
		int mode10_set(void);//�e���[�h�̏����l�Z�b�g
		int mode11_set(void);//�e���[�h�̏����l�Z�b�g
		int mode12_set(void);//�e���[�h�̏����l�Z�b�g
		int mode13_set(void);//�e���[�h�̏����l�Z�b�g
		int mode14_set(void);//�e���[�h�̏����l�Z�b�g
		int mode15_set(void);//�e���[�h�̏����l�Z�b�g
		int mode16_set(void);//�e���[�h�̏����l�Z�b�g
		int mode17_set(void);//�e���[�h�̏����l�Z�b�g
		int mode18_set(void);//�e���[�h�̏����l�Z�b�g
		int mode19_set(void);//�e���[�h�̏����l�Z�b�g
		int make_map(int R);//�}�b�v�쐬���ʒu�Čv�Z
		int set_map(int N,int X,int Y);
		int set_root(int A,int B,int N );
		//�f�[�^�̓ǂݍ���
		int gaibu_load(void);//�O���t�@�C���̓ǂݍ���
		int wep_price(double rate);//����
		int name_set(int N);
		int gra_load(void);//�摜�̓ǂݍ���
		int sound_load(void);//�����f�[�^�̓ǂݍ���
		int sound_volset(void);//�����f�[�^�̓ǂݍ���
		int wep_st_cul(int N);
		//�c�ƃt�F�C�Y
		int work_main();//
		int work_month_s();//���͂��ߏ���
		int work_day_s();
		int work_rest_check(int E,int S);//
		int cul_mensetu();
		int tansaku_syori();
		//���쏈��
		int work_sousa();//�E�B���h�E���^�u�ėp����
		int work_sousa_n(int X,int Y,int N);//�E�B���h�E�ŗL����
		int window_sort(int W);//�E�B���h�E���я��ύX
		int window_s01(int X,int Y);//�q���
		int window_s02(int X,int Y);//������
		int window_s03(int X,int Y);//�J�����
		int window_s04(int X,int Y);//������
		int window_s05(int X,int Y);//�l�����X���ꗗ
		int window_s06(int X,int Y);//�l�����E�l�ꗗ
		int window_s07(int X,int Y);//�X�܏��
		int window_s08(int X,int Y);//�s�����O
		int window_s09(int X,int Y);//���x�A�V�F�A���
		int window_s10(int X,int Y);//�o�c�헪�E�B���h�E
		int window_s11(int X,int Y);//�ڍ׃E�B���h�E
		int list_sort(int R=0);
		int list_dw(int W);//�J��or���ǃR�}���h�폜
		int list_pw(int W);//���탊�X�g�ǉ�
		int list_mw(int W);
		int list_de(int E);//�l�����X�g����폜
		int list_pe(int E);
		int list_df(int F);//�t�H���_�����
		int sort_wep();
		int sort_emp(int J);
		int sort_emp_st(int E,int R);
		int sort_req(int R = -1);
		//�c�ƃt�F�C�Y��������
		int customer_act();//�q����
		int shop_act();//�X�܏���
		int emp_act(int S,int C);
		int make_create();
		//�����q����
		int zaiko_cnt();
		int sell_data_cul(int N=0);
		int emp_plus(int E,int S);
		int emp_yame(int E,int MES);
		int skill_efe(int C,int UD);//
		//
		int eve_check();//�C�x���g�������菈��
		int eve_syori(int E);//�C�x���g��������
		int eve_boom();
		int game_over();//�Q�[���I��
		int medal_check();//���_���擾����
		int game_rerecord();//�L�^�X�V����

		//�C�x���g�X�N���v�g�p
		int act_mes(int N,int MS,int UD,char M1[],char M2[] = "",char M3[]="");//�����i�[
		int act_set(int N,int X,int Y,int T,int M,char NAME[]);
		int act_mov(int N,int MX,int MY,int S);
		//
		int input_pass();
		//�V�X�e������
		int inp_check(void);//���̓`�F�b�N
		int err_c();//�G���[�`�F�b�N
		int se_ok(int S);//���ʉ�
		int bgm_ok(int M);
		//���������֐�
		int Rand(int R);//��������
		int set_rand(unsigned long S);

		int hun_shopout(int C);//�ޓX
		int hun_timeup(int C);//���Ԑ؂�

		int tutorial(int N,int OK = 0);//�`���[�g���A���֐�
		int tutorial_menu();

		int Max(int a=0,int b = 0,int c=0,int d = 0,int e = 0,int f = 0);
		int Min(int a=999999,int b = 999999,int c=999999,int d = 999999,int e = 999999,int f = 999999);
	}fun;
	class AI{
		public:
		int wep_sel(int S);//����I������
		int set_emp(int S);//�J���Ҕz�u����
		int mana_sel(int S);//��p�I������
		int taiguu_sel(int S);//�ҋ����菈��
		int koyou_sel(int S);//�ٗp����
		int emp_kai(int S);//�œK�Ȑl�����v�Z
		int emp_sei(int S);//�œK�Ȑl�����v�Z
		int jinji_cul(int S);
		int jinji_sel(int S,int J);

		int emp_hyou[EMP_M];
		int tai_heikin;//�X�܂̗͕̑���
		int tai_husoku;

		int wep_cnt[4];//�n���ʍ݌ɐ��A�\��
		int wep_tc[4];//�n���ʒI��

		int no[100][4];//�n���ʔԍ�
		int ninki[100][4];//�l�C
		int list[4];//�n���ʐ�

		int wep_n[400];//����ԍ�
		int wep_rf[400];//�݌ɐ��\��
		int wep_kai[400];//�J���\�胊�X�g
		int wep_kp[400];//�����J����
		int kai_cnt;
		int sei_cnt;
		int zero_cnt;//�݌ɒ����Ȃ����퐔
		int syou_cnt;//�݌ɗ]�T���������퐔
		int kaico_cnt;//���ِ�
		int custom_pre;//�挎�q��

		//int nougu;
	}ai;
	class DRA{//�`��N���X
		public:

		int work();
		int wmap();
		int win_1b(int X,int Y);
		int win_2b(int X,int Y);
		int win_3b(int X,int Y);
		int win_4b(int X,int Y);
		int win_5b(int X,int Y);
		int win_6b(int X,int Y);
		int win_7b(int X,int Y);
		int win_8b(int X,int Y);
		int win_9b(int X,int Y);
		int win_10b(int X,int Y);
		int win_11b(int X,int Y);

		int win_help();//�w���v�E�B���h�E
		int win_1h();
		int win_2h();
		int win_3h();
		int win_4h();
		int win_5h();
		int win_6h();
		int win_7h();
		int win_8h();
		int win_9h();
		int win_10h();
		int win_11h();
		int win_12h();
		int win_htai();//�ҋ��ύX�p
		int win_hmes(const char str[],int XS=80,int YS=32,int N = 0);//���݂͂̂̃w���v//�f���s��
		int win_tmes(const char str[],int X,int Y,int N,int S);//���݂͂̂̃w���v//�f���s��

		int win_2s(int N,int X,int Y);
		int win_5s(int N,int X,int Y);
		int win_7_seido(int X,int Y);

		int mana_info(int M);
		int emp_info(int E);
		int wep_info(int W);
		int seido_info(int M);

		int wep_icon(int X,int Y,double R,int N);
		int mana_icon(int X,int Y,int M,int T);

		int title();
		int select_mode();
		int option(int,int,int,int,int,int);
		int drama();
		int novel();

		int waku(int XU,int YU,int XS,int YS,int NO);
		int waku_c(int XU,int YU,int XS,int YS,int C,int C2,int C3);
		int waku_h(int N);//���o��
		int waku_help(int X,int Y,int XS,int YS,int N = 0);
		int waku_syuusi();
		int waku_graph();
		int mes(int X,int Y,const char* M,int C,int C2,int FONT);
		int mes_str(int X,int Y,const char* M,int C,int C2,int FONT);

		int mes_stri(int X,int Y,const char* M);
		int mes_i(int X,int Y,const char* M);

		int mes_bmf(int X,int Y,const char M[30],double S);
		int mes_bmf2(int X,int Y,const char* M,double S,int LEN=100);
		int suu_bmf(int X,int Y,double S,int V,int T,int K=7);
		int syou_bmf(int X,int Y,int V,int T,int K=7);

		int tutorial_menu();
		int tutorial_00(int PA,int N);

		int wep_db();
		int mana_db();
		int record_db();
		int medal_db();
		int credit_db();
		int mana_db_s(int X,int Y,int W);
		int wep_db_s(int X,int Y,int M);
		int mana_db_no(int X,int Y,int M);
		int wep_db_no(int X,int Y, int W);

		int kakunin(const char* M,int T);

		int select_nanndo();
		int select_save();
		int winning_mode();

		int kai_t[WEP_M];//�c��\������
		int kai_c[WEP_M];//�F

		int lv_t[EMP_M];//�c��\������

		int sell_t[WEP_M];//�̔��\��

		int game_over();//�Q�[���I��

		int ending();

	}draw;

	ACTER act[32];

class EVE_FUN{
	public:

	static EVE_FUN& Sin()
	{
		static EVE_FUN eve;
		return eve;
	}

	int eve_no;//���݂̃C�x���g
	int eve_wait;//���͑҂�����
	int eve_next;//����
	int eve_line;//���s�ڂ̃C�x���g
	int eve_end;//�C�x���g�I���t���O
	int eve_black;//�Ó]
	int eve_bback;//�Ó]��w�i
	std::string eve_name;//�m��
	int eve_namew;//�m������

	void eve_test();

	void reset()
	{
		eve_end = 0;
		eve_line = 0;
		eve_wait = 0;
		eve_next = 0;
		eve_black = 0;
		eve_bback = 0;

		for(int i=0;i<32;i++)
		{
			act[i].no = -1;
			act[i].mx = 0;
			act[i].my = 0;
			act[i].sp = 4;
			act[i].huki_w = 0;
		}
	}

	int eve_switch(int E);

	void eve_efe( int E );

	bool eve_ok( int E );

	//void �͂��܂�();

	//��p���ʏ���
	int mana_syori(int S,int M);
	int mana_lvup(int S,int T);
	int mana_ai(int S,int M);
	int mana_000(int S,int AI);
	int mana_001(int S,int AI);
	int mana_002(int S,int AI);
	int mana_003(int S,int AI);
	int mana_004(int S,int AI);
	int mana_005(int S,int AI);
	int mana_006(int S,int AI);
	int mana_007(int S,int AI);
	int mana_008(int S,int AI);
	int mana_009(int S,int AI);
	int mana_010(int S,int AI);
	int mana_011(int S,int AI);
	int mana_012(int S,int AI);
	int mana_013(int S,int AI);
	int mana_014(int S,int AI);
	int mana_015(int S,int AI);
	int mana_016(int S,int AI);
	int mana_017(int S,int AI);
	int mana_018(int S,int AI);
	int mana_019(int S,int AI);
	int mana_020(int S,int AI);
	int mana_021(int S,int AI);
	int mana_022(int S,int AI);
	int mana_023(int S,int AI);
	int mana_024(int S,int AI);
	int mana_025(int S,int AI);
	int mana_026(int S,int AI);
	int mana_027(int S,int AI);
	int mana_028(int S,int AI);
	int mana_029(int S,int AI);
	int mana_030(int S,int AI);
	int mana_031(int S,int AI);
	int mana_032(int S,int AI);
	int mana_033(int S,int AI);
	int mana_034(int S,int AI);
	int mana_035(int S,int AI);
	int mana_036(int S,int AI);
	int mana_037(int S,int AI);
	int mana_038(int S,int AI);
	int mana_039(int S,int AI);
	int mana_040(int S,int AI);
	int mana_041(int S,int AI);
	int mana_042(int S,int AI);
	int mana_043(int S,int AI);
	int mana_044(int S,int AI);
	int mana_045(int S,int AI);
	int mana_046(int S,int AI);
	int mana_047(int S,int AI);
	int mana_048(int S,int AI);
	int mana_049(int S,int AI);
	int mana_050(int S,int AI);
	int mana_051(int S,int AI);
	int mana_052(int S,int AI);
	int mana_053(int S,int AI);
	int mana_054(int S,int AI);
	int mana_055(int S,int AI);
	int mana_056(int S,int AI);
	int mana_057(int S,int AI);
	int mana_058(int S,int AI);
	int mana_059(int S,int AI);
	int mana_060(int S,int AI);
	int mana_061(int S,int AI);
	int mana_062(int S,int AI);
	int mana_063(int S,int AI);
	int mana_064(int S,int AI);
	int mana_065(int S,int AI);
	int mana_066(int S,int AI);
	int mana_067(int S,int AI);
	int mana_068(int S,int AI);
	int mana_069(int S,int AI);
	int mana_070(int S,int AI);
	int mana_071(int S,int AI);
	int mana_072(int S,int AI);
	int mana_073(int S,int AI);
	int mana_074(int S,int AI);
	int mana_075(int S,int AI);
	int mana_076(int S,int AI);
	int mana_077(int S,int AI);
	int mana_078(int S,int AI);
	int mana_079(int S,int AI);
	int mana_080(int S,int AI);
	int mana_081(int S,int AI);
	int mana_082(int S,int AI);
	int mana_083(int S,int AI);
	int mana_084(int S,int AI);
	int mana_085(int S,int AI);
	int mana_086(int S,int AI);
	int mana_087(int S,int AI);
	int mana_088(int S,int AI);
	int mana_089(int S,int AI);
	int mana_090(int S,int AI);
	int mana_091(int S,int AI);
	int mana_092(int S,int AI);
	int mana_093(int S,int AI);
	int mana_094(int S,int AI);
	int mana_095(int S,int AI);
	int mana_096(int S,int AI);
	int mana_097(int S,int AI);
	int mana_098(int S,int AI);
	int mana_099(int S,int AI);
	int mana_100(int S,int AI);
	int mana_101(int S,int AI);
	int mana_102(int S,int AI);
	int mana_103(int S,int AI);
	int mana_104(int S,int AI);
	int mana_105(int S,int AI);
	int mana_106(int S,int AI);
	int mana_107(int S,int AI);
	int mana_108(int S,int AI);
	int mana_109(int S,int AI);
	int mana_110(int S,int AI);
	int mana_111(int S,int AI);
	int mana_112(int S,int AI);
	int mana_113(int S,int AI);
	int mana_114(int S,int AI);
	int mana_115(int S,int AI);
	int mana_116(int S,int AI);
	int mana_117(int S,int AI);
	int mana_118(int S,int AI);
	int mana_119(int S,int AI);
	int mana_120(int S,int AI);
	int mana_121(int S,int AI);
	int mana_122(int S,int AI);
	int mana_123(int S,int AI);
	int mana_124(int S,int AI);
	int mana_125(int S,int AI);
	int mana_126(int S,int AI);
	int mana_127(int S,int AI);
	int mana_128(int S,int AI);
	int mana_129(int S,int AI);
	int mana_130(int S,int AI);
	int mana_131(int S,int AI);
	int mana_132(int S,int AI);
	int mana_133(int S,int AI);
	int mana_134(int S,int AI);
	int mana_135(int S,int AI);
	int mana_136(int S,int AI);
	int mana_137(int S,int AI);
	int mana_138(int S,int AI);
	int mana_139(int S,int AI);
	int mana_140(int S,int AI);
	int mana_141(int S,int AI);
	int mana_142(int S,int AI);
	int mana_143(int S,int AI);
	int mana_144(int S,int AI);
	int mana_145(int S,int AI);
	int mana_146(int S,int AI);
	int mana_147(int S,int AI);
	int mana_148(int S,int AI);
	int mana_149(int S,int AI);
	int mana_150(int S,int AI);
	int mana_151(int S,int AI);
	int mana_152(int S,int AI);
	int mana_153(int S,int AI);
	int mana_154(int S,int AI);
	int mana_155(int S,int AI);
	int mana_156(int S,int AI);
	int mana_157(int S,int AI);
	int mana_158(int S,int AI);
	int mana_159(int S,int AI);
	int mana_160(int S,int AI);
	int mana_161(int S,int AI);
	int mana_162(int S,int AI);
	int mana_163(int S,int AI);
	int mana_164(int S,int AI);
	int mana_165(int S,int AI);
	int mana_166(int S,int AI);
	int mana_167(int S,int AI);
	int mana_168(int S,int AI);
	int mana_169(int S,int AI);
	int mana_170(int S,int AI);
	int mana_171(int S,int AI);
	int mana_172(int S,int AI);
	int mana_173(int S,int AI);
	int mana_174(int S,int AI);
	int mana_175(int S,int AI);
	int mana_176(int S,int AI);
	int mana_177(int S,int AI);
	int mana_178(int S,int AI);
	int mana_179(int S,int AI);
	int mana_180(int S,int AI);
	int mana_181(int S,int AI);
	int mana_182(int S,int AI);
	int mana_183(int S,int AI);
	int mana_184(int S,int AI);
	int mana_185(int S,int AI);
	int mana_186(int S,int AI);
	int mana_187(int S,int AI);
	int mana_188(int S,int AI);
	int mana_189(int S,int AI);
	int mana_190(int S,int AI);
	int mana_191(int S,int AI);
	int mana_192(int S,int AI);
	int mana_193(int S,int AI);
	int mana_194(int S,int AI);
	int mana_195(int S,int AI);
	int mana_196(int S,int AI);
	int mana_197(int S,int AI);
	int mana_198(int S,int AI);
	int mana_199(int S,int AI);
	int mana_200(int S,int AI);
	int mana_201(int S,int AI);
	int mana_202(int S,int AI);
	int mana_203(int S,int AI);
	int mana_204(int S,int AI);
	int mana_205(int S,int AI);
	int mana_206(int S,int AI);
	int mana_207(int S,int AI);
	int mana_208(int S,int AI);
	int mana_209(int S,int AI);
	int mana_210(int S,int AI);
	int mana_211(int S,int AI);
	int mana_212(int S,int AI);
	int mana_213(int S,int AI);
	int mana_214(int S,int AI);
	int mana_215(int S,int AI);
	int mana_216(int S,int AI);
	int mana_217(int S,int AI);
	int mana_218(int S,int AI);
	int mana_219(int S,int AI);
	int mana_220(int S,int AI);
	int mana_221(int S,int AI);
	int mana_222(int S,int AI);
	int mana_223(int S,int AI);
	int mana_224(int S,int AI);
	int mana_225(int S,int AI);
	int mana_226(int S,int AI);
	int mana_227(int S,int AI);
	int mana_228(int S,int AI);
	int mana_229(int S,int AI);
	int mana_230(int S,int AI);
	int mana_231(int S,int AI);
	int mana_232(int S,int AI);
	int mana_233(int S,int AI);
	int mana_234(int S,int AI);
	int mana_235(int S,int AI);
	int mana_236(int S,int AI);
	int mana_237(int S,int AI);
	int mana_238(int S,int AI);
	int mana_239(int S,int AI);
	int mana_240(int S,int AI);
	int mana_241(int S,int AI);
	int mana_242(int S,int AI);
	int mana_243(int S,int AI);
	int mana_244(int S,int AI);
	int mana_245(int S,int AI);
	int mana_246(int S,int AI);
	int mana_247(int S,int AI);
	int mana_248(int S,int AI);
	int mana_249(int S,int AI);
	int mana_250(int S,int AI);
	int mana_251(int S,int AI);
	int mana_252(int S,int AI);
	int mana_253(int S,int AI);
	int mana_254(int S,int AI);
	int mana_255(int S,int AI);
	int mana_256(int S,int AI);
	int mana_257(int S,int AI);
	int mana_258(int S,int AI);
	int mana_259(int S,int AI);
	int mana_260(int S,int AI);
	int mana_261(int S,int AI);
	int mana_262(int S,int AI);
	int mana_263(int S,int AI);
	int mana_264(int S,int AI);
	int mana_265(int S,int AI);
	int mana_266(int S,int AI);
	int mana_267(int S,int AI);
	int mana_268(int S,int AI);
	int mana_269(int S,int AI);
	int mana_270(int S,int AI);
	int mana_271(int S,int AI);
	int mana_272(int S,int AI);
	int mana_273(int S,int AI);
	int mana_274(int S,int AI);
	int mana_275(int S,int AI);
	int mana_276(int S,int AI);
	int mana_277(int S,int AI);
	int mana_278(int S,int AI);
	int mana_279(int S,int AI);
	int mana_280(int S,int AI);
	int mana_281(int S,int AI);
	int mana_282(int S,int AI);
	int mana_283(int S,int AI);
	int mana_284(int S,int AI);
	int mana_285(int S,int AI);
	int mana_286(int S,int AI);
	int mana_287(int S,int AI);
	int mana_288(int S,int AI);
	int mana_289(int S,int AI);
	int mana_290(int S,int AI);
	int mana_291(int S,int AI);
	int mana_292(int S,int AI);
	int mana_293(int S,int AI);
	int mana_294(int S,int AI);
	int mana_295(int S,int AI);
	int mana_296(int S,int AI);
	int mana_297(int S,int AI);
	int mana_298(int S,int AI);
	int mana_299(int S,int AI);
	//����������
	int mana_setumei();
	int seido_setumei();

	int back_change(EStage estage , int T = 1);//�w�i�ύX

	int get_line();

	void set_end();

};

int GetLine()
{
	return EVE_FUN::Sin().get_line();
}

void SetEnd()
{
	EVE_FUN::Sin().set_end();
}

int BackChenge(EStage estage , int T = 1)
{
	return EVE_FUN::Sin().back_change( estage , T);
}

static const int M_KUSY = 14;//�g���̏���
static const int M_TEKI = 18;//�K�ޓK��
static const int M_SUKR = 19;//�X�N����
static const int M_SINK = 22;//�V���̗p����
static const int M_TYUK = 23;//���r�̗p����
static const int M_GLDS = 30;//�����̐��_
static const int M_GLDM = 31;//�����̈ӎv
static const int M_NOBI = 32;//�̂т̂�
static const int M_LOVP = 39;//���А��_��
static const int M_ELVE = 44;//���퉮�I�Θb
static const int M_WECO = 45;//���퉮�I�Θb
static const int M_KAKU = 49;//�o���̎����

static const int M_IDEB = 67;//�A�C�f�A�蓖
static const int M_BONU = 70;//�{�[�i�X���x
static const int M_KAIK = 72;//���َ蓖
static const int M_MOKA = 77;//���������x-�p�~
static const int M_TEST = 78;//���p����
static const int M_JITU = 82;//�����x��
static const int M_KUUK = 83;//��Ԋ��p
static const int M_SABI = 85;//�J���͖�������
static const int M_MATP = 86;//�}�g�b�N�v����
static const int M_AHUR = 89;//���ӂ��T���v��

static const int M_ONRF = 134;//��郊�t�H�[��
static const int M_TAKM = 135;//�����t�H�[��
static const int M_SYSA = 136;//�h��
static const int M_SAKU = 137;//��

static const int M_NILE = 188;//�l���_�b
static const int M_IDEC = 189;//�A�C�f�A�̌���
static const int M_ENAL = 197;//�����ւ̓��B
static const int M_LOST = 198;//����ꂵ�Z�p
static const int M_NTEC = 199;//�V�Z�p�̓���
static const int M_AJYA = 200;//�A�W���C���J��
static const int M_TOCG = 201;//�����擾
static const int M_KORO = 202;//����̓I�}�[�W��
static const int M_BARA = 203;//�o�����X
static const int M_HUMI = 204;//���ݑ�

static const int M_NSEL = 251;//�i�E�I���Z�[��
static const int M_KAKH = 252;//���S�̉��i�ۏ�
static const int M_PCAD = 253;//�o�J�[�h
static const int M_TENF = 254;//�\�l�Ɉ�l�����I

static const int M_KOUT = 261;//�L���������Ă悤
static const int M_YURU = 262;//��邫���a��
static const int M_BURA = 263;//�u�����h���S�}�[�N
static const int M_MATO = 264;//�܂Ƃ��Ĕ���

static const int M_NKAR = 265;//�V���Ȏ��Z�[��
static const int M_GAIS = 266;//�M��搂�
static const int M_HEIT = 267;//�X�Z�[��

static const int M_RIFO = 268;//���t�H�[���Z�[��
static const int M_METE = 269;//�����X��

static const int M_HOMO = 270;//�{�Ɩ{��
static const int M_NOSE = 271;//��`���Ȃ���`���g�p�s�ɂ����p���ύX

static const int M_UTES = 272;//�J�V�Z�[��
static const int M_SURI = 273;//���肱��

/*
	data.mode_n[1] = "�V�i���I";
	data.mode_n[2] = "���R�o��";//�t���[���[�h�A�ڕW���T��
	data.mode_n[3] = "���_���̉�";//���_�����ŋ���
	data.mode_n[4] = "������`";//�����ڕW
	data.mode_n[5] = "��q����";//�q���ڕW
	data.mode_n[6] = "�����͗x��";//�����ڕW
	data.mode_n[7] = "�V�F�A�m�n�P";//�̔��ڕW
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
	data.mode_n[18] = "�S�̂�Ƃ萢��";//�n���^�[�������Ȃ�
*/