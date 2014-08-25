#pragma once

#include "DxLib.h"
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <vector>

#define HUN_M 10000 //冒険者最大数
#define JOB_M 50	//職種最大数
#define SHOP_M 5	//店最大数
#define WEP_M 400	//武器種類最大数
#define SHOP_SP 1000 //来店可能最大数
#define EMP_M 500	//従業員最大数+
#define ENE_M 50	//敵種類
#define DUN_M 100	//ダンジョン数
#define EVE_M 400	//イベント数
#define LOG_M 100	//ログ最大数
#define WIN_M 12	//ウィンドウ数
#define MANA_M 300	//経営戦略種類
#define YEAR_M	 5	//最大年数
#define MANTH_M (12*YEAR_M)	//最大月数
#define WEEK_M  (48*YEAR_M) //最大週数
#define DAY_M  (336*YEAR_M)	//最大日数
#define EIGYOU_T 54
#define WEP_T	4//武器種
#define MANA_T	5//戦術タイプ
#define NIN_T	3
#define KEN_T	3

#define NOU_NO	 99 //農具配列添字
#define P		 data.play //プレイヤー勢力
#define EVE_SKIP 0	//イベントスキップフラグ

//バランス調整系重要数値
#define WEP_EXP_RATE 72000//武器開発レベルＵＰ条件,1上昇につき10%づつ上がる
#define WEP_EXP_RATE2 3600
#define H_LV_UP		  1000

#define PI      3.14159265358979323846f//演習率

	class HUNTER{//冒険者
		public:
		int no;//配列添え字

		int life;//生命力
		int lv;//レベル
		int exp;//経験値
		int job;//職種
		int sta[4];//ステータス
		int hp;//現在HP
		int skill;//特技
		int wep_t;//武器種類
		int rank;//ジョブランク
		int dun_lv;//ダンジョンレベル

		int money;//現在資金
		int wep_c;//武器所持数
		double wep_a[8];//武器攻撃
		int wep_d[8];//武器耐久
		int wep_s[8];//購入店舗
		int shop_wepn[SHOP_M];//最後に来店品揃え
		int shop_koukan[SHOP_M];
		int senden_boost[SHOP_M];//宣伝ブースト
		
		int like_t[3];//強さ、かっこよさ、安さの影響度

		//行動状態
		int act;//行動種類//0待機、1店内、2接客中、3クレーマー、4退店、5店接近中
		int act_no;//店番号、ダンジョン番号
		int b_w;//ブラック度//高い,交渉早い、クレーマー率ＵＰ
		int stress;//初動時間
		int wait;//待機時間
		int talk_max;//ゲージ最大
		int talk_emp;//現在対応している店員

		int x;//来客表示用x座標、y座標
		int vx;//客進行方向
		int y;

		//デルタで追加
		int p_card[SHOP_M];//ポイントカード所持

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
	class JOB{//職種
		public:
		char name[21];
		int gra;//画像
		int st_up[4];//成長率
		int st_st[4];//基本ステータス
		int next_J[3];//派生ジョブ
		int wep_t;//武器種類
		int rank_up;//ランクアップレベル
		int rank;//ランク
	}jobs[JOB_M];
	class SHOP{//店
		public:
		std::string name;
		int icon;//店アイコン
		int color;//店色

		int no;
		int emp_cnt;
		int emp_kou;//工房人数
		int emp_list[EMP_M];//店員リスト

		double money;//資金
		double b_w;//ブラック度0～100
		int koubou_t;//工房営業時間
		int koubou_n;//次の日工房時間

		int create_get[KEN_T];//獲得開発経験値
		int create_exp[KEN_T];//開発経験値
		int create_lv[KEN_T];//開発力

		int nougu_req;//農耕器具要求

		int wep_rest[WEP_M];//在庫数
		int wep_cre[WEP_M];//開発状況 -1開発不可 0ひらめき可能　1開発中 2製造可能
		int wep_hday[WEP_M];//閃いた日数
		int wep_make[WEP_M];//生産進行度
		int wep_kaicnt[WEP_M];//改良回数
		int wep_kaiexp[WEP_M];//改良回数
		int wep_make_t[WEP_M];//総生産数
		int wep_make_now[WEP_M];//投入生産力
		int wep_kai_now[WEP_M];//改良投入現在地

		//改良回数
		int ninki_kai[WEP_M];//人気
		int atk_kai[WEP_M];//攻撃
		int dur_kai[WEP_M];//耐久
		int cost_kai[WEP_M];//コスト
		int time_kai[WEP_M];//時間

		int wep_sb[4][3];//武器基本開発可能力//つよさ・やすさ・かっこよさ

		int yasuuri;//ｾｰﾙ期間
		int price_rate;//ｾｰﾙ割引 %
		double yasuuri_efe;//セール効果

		int bumon_lv[MANA_T];//経営、財務、工事、開発、宣伝

		int bumon_exp[MANA_T];//

		int total_saiyou;//累計採用数
		int total_yame;//辞めた人の合計勤続日数

		double lv_ave;//平均レベル
		double pay_ave;//平均給与
		double mon_ave;//平均勤続月数
		double bw_bonus;//ブラック度ボーナス値

		//改良後の実補正-毎回再計算する
		double ninki_j[WEP_M];//人気
		double atk_j[WEP_M];//攻撃
		double dur_j[WEP_M];//耐久
		double cost_j[WEP_M];//コスト
		double time_j[WEP_M];//時間

		int yasumi_max;//休日数			休み数、ローテーションで休ませます
		int zangyou;//最大残業時間		1 = 10分

		int seizou_b;
		int kairyou_b;//改良ボーナス
		int tukare_b;
		int sekkyaku_b;
		int kaihatu_b;
		int sabaki_b;
		int stress_b;
		int yaruki_b;//やる気上昇率

		int size;
		int kouji;//工事残り日数

		int souko_now;//倉庫現数//超過で経費発生
		int souko_max;//倉庫最大数

		int tana_now;//棚現在数//集客力に影響
		int tana_now_t[4];//各武器種別

		int teikyuu;//定休日
		int cust_cnt;//来客数
		int cust_cnt_t[WEP_T];//武器種類毎の現在来客数
		int cust_wep[WEP_T];//武器種類別来客数
		int cust_list[SHOP_SP];//来店客リスト
		int cust_gold[SHOP_SP];//来店客消費ゴールド

		double p_mp;//回復マネジメントポイント
		double n_mp;//現在マネジメントポイント
		int use_mana;//使用戦術
		int mana_ok[MANA_M];//経営戦略使用状況 -1ひらめき不可 ひらめき可能　1使用可能
		int syou_mp[MANA_M];//消費MP
		int syou_money[MANA_M];//消費資金
		int mana_rest[MANA_M];//残り使用回数
		int mana_cnt[MANA_M];//使った回数
		int mana_day[MANA_M];//閃いてからの日数

		int sellc_day[DAY_M];//販売数
		int sell_day[DAY_M];//売り上げ
		int cust_day[DAY_M][WEP_T];//武器別客数
		int seizc_day[DAY_M];//製造数
		int seiz_day[DAY_M];//製造費

		int sellc_mon[MANTH_M];//販売数
		int sell_mon[MANTH_M];//売り上げ
		int cust_mon[MANTH_M];//客数
		int seizc_mon[MANTH_M];//製造数
		int seiz_mon[MANTH_M];//製造費

		int emp_mon[MANTH_M];//雇用費//月末に計算
		int manege_mon[MANTH_M];//経営戦術費用
		int etc_mon[MANTH_M];//税,利子月末に計算
		int incom_mon[MANTH_M];//利益月末に計算
		int nougu_mon[MANTH_M];//農具納入数
		int total_mon[MANTH_M];//総資産//月末に計算
		int kabu_mon[MANTH_M];//株価

		int shera_wepd[DAY_M][WEP_T];//各武器の販売シェア
		int shera_wepm[MANTH_M][WEP_T];//各武器の販売シェア

		int holiday;//休日設定 0営業,それ以外は営業しない
		double timeido;//0~100

		double kabu_price;//株価
		int kabu_max;//株最大数
		int kabu_cnt[5];//株保持数,0自社株,1商会,2鉱山,3発明所,4新聞社
		int kabu_rank[5];//株のランク
		double kabu_rate[5];//株保持率
		//AI用
		int ai_like[5];
		//追加仕様Δ
		int mana_b[MANA_T];//戦術使用ＭＰ補正
		int mana_gb[MANA_T];//戦術使用資金補正

		int mensetu_lv;//面接レベル

		int kaihuku_b;
		int kaihuku_bs;//体力消費補正、新入り
		int exp_b;//経験値補正
		int exp_bs;//経験値補正、新入り
		int monster_b;//クレーマー発生率補正
		int syakai_b;//社会人度変化ボーナス
		int hp_up_b;//HP成長率
		int sei_up_b;//製造成長率
		int kai_up_b;//開発成長率
		int kya_up_b;//客捌成長率
		int sek_up_b;//接客成長率
		int kega_b;//怪我発生率

		int sinn_b;//新入り好感度ボーナス

		int mp_ninnzuu;//人数によるＭＰ回復ボーナス

		int sk_pup;//スキル強化確率
		int sk_rup;//スキル反転確率
		int sk_qup;//？スキル変化確率

		int kabu_buy;//株取引量
		int nougu_up;
		int kyuuryou_b;//給料支払い率
		int risoku_rate;//借金利息
		int risi_rate;//貯金利子
		int cost_b;//製造費補正
		int atk_b;//攻撃力ボーナス、%
		int dur_b;

		int kaicost_b;//開発コスト補正

		int bukimatu_b;//武器祭りボーナス
		int turumatu_b;//つるはし祭りボーナス
		int tax_b;//税金率

		int hirameki_dayb;//閃かない日数ボーナス
		int hirameki_b[WEP_T];//武器種別閃き補正
		int senden_b;//宣伝補正

		int kaizen_week;//改善週間

		int wep_medama[7];//設定中の武器
		int medama_max;
		double medama_wept[4];
		double medama_zoku[3];


		int ken_b[KEN_T];//研究経験補正

		int otona_b;//大人買い補正

		int ninki_b[NIN_T];//集客補正、属性別

		int koukan_down;//好感度下限

		int saitei_koukan;//好感度最低値

		int jisyoku_b;//辞職確率補正

		int eve_efe;//イベントによる特殊効果
		int eve_turn;//特殊効果残り時間

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

		int goal_check();//ゴール判定

		int kyuubo;

		int reset();

		int g_cust;//総来客○
		int g_kabu;//株価時価○
		int g_sell_t;//総売り上げ○
		int g_sell[4];//武器種別売り上げ○
		int g_turu;//つるはし総生産○
		int g_wepcre;//武器総開発○
		int g_money;//総資金○
		int g_taikai;//総大会得点○
		int g_boss;//総ボス討伐○

		int eve_random();//ランダムイベント

        void getumatu();

	}shop[SHOP_M];
	class WEPON{//武器
		public:
		std::string name;
		std::string info;//説明文
		//char name[31];//武器名前
		int type;//武器種類
		int zoku;//集客属性
		int rank;//武器開発ランク
		int atk;//攻撃力
		int dur;//耐久
		int ninki[NIN_T];//人気、t,y,k
		int seizou_cost;//製造原価
		int price;//基本販売額
		int priceOri;//難易度補正前販売額
		int create_time;//開発期間
		int make_time;//製造工数
		int req_clv[KEN_T];//必要開発レベル
		int color;//色
		//改良しやすさ
		int kairyou_up;
		int gazou;
		int mtype;//目玉補正値
		int mzoku;
		int req_mana;//閃きに必要な戦術
	}wep[WEP_M];
	class EMPLOY{//労働者
		public:
		std::string name;
		int name_no;
		//char name[21];//名前
		int no;

		int gra;//画像
		int shop_n;//配属店、求職店
		int shop_like[SHOP_M];//好感度
		int now_job;//現在状況 0求職 1就職 2内定 3ニート
		int mensetu[5][SHOP_M];//面接状況、ステータス、店番号
		int req_jinji[5];//面接成功に必要な面接力
		int job;//職種
		int shift;//シフト
		int shift_n;//シフト変更
		double sun;//正気度、ストレス
		int lv;//レベル
		int req_turn;//出現ターン
		int exp;//経験値
		double hp;//残りHP 0～100%
		int tension;//やる気
		double b_w;//ブラック度、0～100%
		int konjyou_k;//計算後の根性
		int konjyou;//根性

		int rest;//怪我、風邪期間
		int pay_money;//現在賃金
		int req_money;//要求賃金
		int req_money_h;//要求賃金補正
		int req_rate;//要求レート

		int chan_tai;//待遇変更 0そのまま　1昇給 2減給 3解雇
		int st[3];//現在ステータス
		int st_st[3];//変化後、HP消費率
		int st_up[3];//ステータス成長率
		int skill;//スキル
		int grow_t;//成長タイプ
		int wait;//待機時間-店員
		int kinzoku;//勤続月数

		int work_cnt;//月間、労働日数
		int rote_type;//1～24-再計算する
		int sell_now;//今売上、開発累計
		int eve_flag;//イベント人材フラグ、絶対解雇しない

		int pb_rest;//マイナス、暗黒期残り日数、ホワイト、白金期残り日数
		int pb_count;//暗黒、白金ポイント

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

		int intai;//引退確率

	}emp[EMP_M];
	class ENEMY{//敵
		public:
		char name[21];//名前
		int st[4];//ステータス値
		int exp;//経験値
		int money;//お金
		int skill;//スキル
	}ene[ENE_M];
	class DUNGEON{//ダンジョン
		public:
		int type;//ダンジョンタイプ//城、山、塔、森、滝、洞
		int boss_t;//ボスタイプ
		int boss_max;//ボス最大体力
		int boss_hp;//ボス残り体力
		int clear_f;//討伐数
		int ene_t[8];//出現雑魚//同確率、同じ種族が同じリストあり
		int x,y;//ダンジョン位置
		int seek;//探索度-1未発見,0目標,1発見済み
		int root[5];//繋がるダンジョン
		int root_k[5];//距離
		int root_t[5];//探索度1以上探索中
		int root_p[5];//発見難易度
	}dun[DUN_M];
	class MANA{//経営戦術
		public:
		//char name[51];//名前
		std::string name;
		std::string help;//説明文
		std::string zukan;
		std::string seido_h;//説明文

		int rank;//ランク
		int icon;//表示アイコン
		int b_w_u;//ブラック系orホワイト系//条件上
		int b_w_d;//ブラック系orホワイト系//条件下
		double b_w_c;//ブラック度変化
		int type;//属性
		int seido;//制度系		const int M_ROUD = ;//労働組合の結束

	}mana[MANA_M];
	class GRAPH{//画像
		public:
		int unit[300][12];//労働者、客画像
		int wep[400];//武器
		int ico[117];//システム画像
		static const int icon_m = 117;
		int move[18];//ダンジョンアイコン
		int emo[20];//表情
		int win[99];//ウィンドウ
		int back[100];//背景	
		int map;
		int moji[60];//数字と文字
		int moji_b[80];//文字その２
		int huki[2];//イベント用噴出し
		int title[10];
		int shop[5];//店外観

		int title_txt;
		int title_sub[10];
	}gra;
	class COLOR{//色
		public:
			int kuro;
			int siro;
			int aka;
			int ao;
			int midori;
			int hai;
	}color;
	class WINDOW{//ウィンドウ、インターフェイス、並び順
		public:
	
		int ok[WIN_M];//ウィンドウ開けるかどうか

		int x[WIN_M],y[WIN_M];//ウィンドウ位置
		int sx[WIN_M],sy[WIN_M];//ウィンドウ大きさ
		int smax[WIN_M];//最大Ｙ
		int smini[WIN_M];//最低Ｙ
		int sf[WIN_M];//サイズフラグ
		int scr_cy;//スクロール掴んだ位置
		int scr_ccy;//掴んだときのＳＣＲ位置
		int scr[WIN_M];//スクロール量
		int scr_on[WIN_M];
		int scrm[WIN_M];//スクロール最大値
		int hide[WIN_M];//重なり状態
		int on[WIN_M];//表示状態
		int drag;//掴んでいる
		int dx,dy;//掴んだ位置
		int sc;//サイズ変更中フラグ

		//int map_hyouji;//マップ表示モード
		int syousai_hyouji;//詳細表示モード
		int graph_hyouuji;

		int wep_sort;//武器ソート種別

		int req_hyouji;//求職者ステ表示
		int emp_hyouji;//雇用表示タイプ
		int ts_hyouji;//待遇＆シフト表示
		int mana_hyouji;//戦術表示切替
		int mana_rock;//非習得表示

		int syu_set;//現在表示収支
		int syu_now;//現在表示
		int syu_year;
		int syu_mon;
		int syu_day;
		int syu_hyouji[12];
		int syu_pars[16];//前年or前月表示用

		int shear_s[5][4];//店シェア、金額
		int shear_p[5][4];//店シェア、独占率
		int shear_t[4];

		int req_list[EMP_M];//求人リスト
		int kai_list[WEP_M];//開発リスト
		int mana_list[MANA_M];//マネジリスト

		int req_m;
		int kai_m;
		int mana_m;

		int info_no;//ヘルプ識別番号
		int info_t;//ヘルプ識別種別番号
		int info_taiguu;//待遇用ヘルプ
		int info_on;//ヘルプ表示ON/OFF
		//1~10各ウィンドウ
		//11　マップ
		//12　上部タブ
		int help_id;
		int help_time;
		//武器ウィンドウ
		int wfold_h[7];//フォルダ高さ
		int wfold_cnt[7];//フォルダ内数
		int wfold_list[7][WEP_M];//武器フォルダ中身
		//人事ウィンドウ
		//店員,職人,待遇
		int efold_h[WEP_M+4];//フォルダ高さ
		int efold_cnt[WEP_M+4];//フォルダ内人数
		int efold_mem[WEP_M+4][100];//各フォルダの中身
		int efold_s[WEP_M];//職人フォルダ順番

		int tfold_h[10][2];//待遇ウィンドウ
		int tfold_cnt[10][2];
		int tfold_mem[10][2][100];
	}wind;
	class LOG{//行動ログ
		public:

		class LOGG{
			public:
			int type;//0,解雇辞職,1雇用,2病気,34567戦術使用,8
			//戦術使用 3~7　○
			//解雇辞職 0	○
			//病気 2		○

			//セール始まり 9　○
			//セール終わり 10 ○
			//工事始まり 11 ○
			//工事終わり 12 ○
			//ブーム変化 13 ○
			//大会 14
			//ボス討伐 15
			//その他イベント 16

			//開発可能1000~
			//開発終了2000~ 一番,3000~　二番以降

			int shop;//対応店舗,0～4各店舗,5全体
			int date;//日付
			//std::string str;//内容
			//int ssize;
			char str[64];

			LOGG(){

			}

			~LOGG(){

			}
		};

		int mode;//表示モード
		//0 すべて
		//1 自店舗のみ
		//2 他店A
		//3 他店B
		//4 他店C
		//5 他店D
		//6 全体のみ

		int cnt;//ログの数
		std::vector<LOGG> log;
		int loc;//スクロール位置

		int add(const char* M,int T,int S);

	}logu;
	class DATA{//全体情報
		public:
		int play;//プレイヤー勢力
		int nando;//難易度
		int mode;//ゲームモード
		int day;//日付//1フレーム10秒
		int play_time;//実プレイ時間
		int ver;//データのバージョン
		
		int game_over;//終了フラグ- 100の位が勝利勢力、0~11が勝利条件、-1は終了前

		int yer;//年
		int mon;//月
		int time;//時刻
		int tenki;//天気

		int jinkou;//人口
		int jinkou_start;
		int jinkou_max;//人口ループ処理最大数
		int jinkou_up;
		int total_des;//死者合計
		int des_mon[MANTH_M];//月毎の死者
		int jinkou_mon[MANTH_M];//月別の人口

		int shop_cnt;//ショップ数

		int kami_ikari;//神の怒り
		int creame_rate;//クレーマー発生率
		int kairyou_rate;//全体改良経験
		int hirameki_rate;//全体閃き確率
		int exp_rate;//経験値レート
		int st_rate;//ステータスレート

		int taiguu_ok;//待遇変更可

		int back;
		int eve_target;

		int senden;//開拓者の募集と宣伝力

		int wep_ganso[WEP_M];//元祖ボーナス

		int eve_flag[EVE_M];//イベント用フラグ
		int font[5];//フォント
		int holiday;//休日フラグ
		char week[8][4];//曜日名
		char tainame[4][5];//待遇名
		char skill_job[36][21];//スキル名
		char skill_info[36][41];//スキル説明文

		char skill_vs[19][5];//スキル戦闘
		int window_x,window_y;//解像度
		int wide;//ワイドフラグ

		int taikai[2];//大会武器種と種目

		std::string win_name[12];
		std::string win_name_s[12];

		int now_save;//使用中のデータスロット

		int mana_icon[5];
		int kabu_cnt[5];//株数
		double kabu_price[5];//株数

		//Δ版追加
		int boom;//現在のブーム
		int boom_rest;//ブーム残り時間

		std::string nanndo_n[5];//難易度表示用
		std::string mode_n[19];//モード表示用

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
		//目標値

		int goal_cust;//目標来客数
		int goal_kabu;
		int goal_sell_t;//販売額
		int goal_sell[4];//販売額
		int goal_turu;
		int goal_wepcre;
		int goal_money;
		int goal_taikai;
		int goal_boss;

		//実行ファイルディレクトリ
		char szDir[_MAX_DIR];

		int new_load;//新規or読み込みフラグ

		int req_act[12];//各月の消費行動力 600で1～1.5時間

		int mana_max[5];//各系統毎の戦術数
		int mana_index[MANA_M];//戦術の図鑑並び順

	}data;
	class INP{//入力状態
	public:
		char p_k[256];//キー入力
		char d_k[256];
		int d_no;//ドラッグしている対象
		int d_type;//ドラッグしているタイプ
		int m_x,m_y;
		int m_RC,m_RD,m_RO,m_RG,m_LC,m_LD,m_LO,m_LG;//クリック、ドラッグ、離す、長押し
		int m_H,m_HC;//ホイールクリック、変化
	}Inp;
	class OPTION{//設定
		public:
		int v_ram;//Vラム
		int full_scr;//フルスクリーンフラグ//途中変更不可能
		int win_skin;//ウィンドウスキン
		int speed;//ゲームスピード//iniに保存しない
		int speed_max;//高速時
		int speed_def;//通常速度
		int bgm_size;//BGM音量//保存する//途中変更可能
		int wev_size;//効果音音量//保存する//途中変更可能
		int window_x;
		int window_y;
	}opt;
	class EVENT{
		public:
		//発生条件
		int flag_req[3];//必要フラグ
		int flag_nreq[3];//不要フラグ
		int type;//シナリオ、ランダム
		int turn_req;//期間条件
		int time_req;//発生時刻
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
			int day;//日数
			int mode;//プレイモード
			int shop;//店番号
			int dif;//難易度
			int time;//実プレイ時間
			int game_over;//クリア状態
			int ver;//バージョン
			std::string name;
			DATA(){

			}
		};

		int cnt;
		std::vector<DATA> list;

	}rabel;
	class SYSTEM{
	public:
		int help_flag[100];//ヘルプ未見フラグ-システム
		int pass_on;//
		int clear;//
		//実績系
		int medal_cnt[100];//メダル所持数
		int medal_gold[100];//メダル効果
		int medal_nanndo[100];//メダル難易度
		std::string medal_name[100];
		std::string medal_info[100];

		int medal_type[3];//種類別所持数

		//
		int total_sell;//販売数●
		int total_cust;//総来客●

		int total_sellc[4];//総売り上げ、武器種別●
		int total_make;//総製造数●
		int total_makec;//総製造コスト●
		int total_kyuuryou;//合計給料●
		int total_matokku;//総つるはし●
		int total_kaihatu;//開発回数●
		int total_senden;//宣伝回数
		int total_day;//経営日数●
		int total_koyou;//雇用回数●
		int total_kaiko;//解雇回数●
		int total_jisyoku;//辞職回数●
		int total_haijin;//廃人化回数●

		int score_record[20][18];

		int nanndo_flag;//上限難易度フラグ,-1～9
        bool play_flag[18];//モードを遊べるかどうかフラグ

		int win_cnt[14];//条件別勝利回数+エンディング２種

		int mana_total[300];//戦術累計使用
		int wep_maxlv[400];//最高レベル
		int wep_maket[400];//製造数
		int wep_cret[400];//開発回数

		SYSTEM(){
			play_flag[0] = true;
		}

		int date;//さいごの日付

	}sys;
//関数
	class FUN{//関数クラス
		public:
		//タイトル画面
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

		//セーブ＆ロード画面＆処理
		int data_save(int N);//データの保存
		int data_load(int N);//データの読み込み
		int load_rabel();//ラベルの読み込み
		int sys_save();
		int sys_load();
		//初期設定の作成
		int make_define();
		int make_dungeon();//ダンジョンの作成
		int make_map();
		int make_hunter(int L,int J = -1);//ハンターの作成
		int make_tenin();
		int make_start(void);//初期ステータスの代入
		int mode00_set(void);//各モードの初期値セット
		int mode01_set(void);//各モードの初期値セット
		int mode02_set(void);//各モードの初期値セット
		int mode03_set(void);//各モードの初期値セット
		int mode04_set(void);//各モードの初期値セット
		int mode05_set(void);//各モードの初期値セット
		int mode06_set(void);//各モードの初期値セット
		int mode07_set(void);//各モードの初期値セット
		int mode08_set(void);//各モードの初期値セット
		int mode09_set(void);//各モードの初期値セット
		int mode10_set(void);//各モードの初期値セット
		int mode11_set(void);//各モードの初期値セット
		int mode12_set(void);//各モードの初期値セット
		int mode13_set(void);//各モードの初期値セット
		int mode14_set(void);//各モードの初期値セット
		int mode15_set(void);//各モードの初期値セット
		int mode16_set(void);//各モードの初期値セット
		int mode17_set(void);//各モードの初期値セット
		int mode18_set(void);//各モードの初期値セット
		int mode19_set(void);//各モードの初期値セット
		int make_map(int R);//マップ作成＆位置再計算
		int set_map(int N,int X,int Y);
		int set_root(int A,int B,int N );
		//データの読み込み
		int gaibu_load(void);//外部ファイルの読み込み
		int wep_price(double rate);//武器
		int name_set(int N);
		int gra_load(void);//画像の読み込み
		int sound_load(void);//音声データの読み込み
		int sound_volset(void);//音声データの読み込み
		int wep_st_cul(int N);
		//営業フェイズ
		int work_main();//
		int work_month_s();//月はじめ処理
		int work_day_s();
		int work_rest_check(int E,int S);//
		int cul_mensetu();
		int tansaku_syori();
		//操作処理
		int work_sousa();//ウィンドウ＆タブ汎用操作
		int work_sousa_n(int X,int Y,int N);//ウィンドウ固有処理
		int window_sort(int W);//ウィンドウ並び順変更
		int window_s01(int X,int Y);//客情報
		int window_s02(int X,int Y);//武器情報
		int window_s03(int X,int Y);//開発情報
		int window_s04(int X,int Y);//武器情報
		int window_s05(int X,int Y);//人事情報店員一覧
		int window_s06(int X,int Y);//人事情報職人一覧
		int window_s07(int X,int Y);//店舗情報
		int window_s08(int X,int Y);//行動ログ
		int window_s09(int X,int Y);//収支、シェア情報
		int window_s10(int X,int Y);//経営戦略ウィンドウ
		int window_s11(int X,int Y);//詳細ウィンドウ
		int list_sort(int R=0);
		int list_dw(int W);//開発or改良コマンド削除
		int list_pw(int W);//武器リスト追加
		int list_mw(int W);
		int list_de(int E);//人事リストから削除
		int list_pe(int E);
		int list_df(int F);//フォルダを閉じる
		int sort_wep();
		int sort_emp(int J);
		int sort_emp_st(int E,int R);
		int sort_req(int R = -1);
		//営業フェイズ内部処理
		int customer_act();//客処理
		int shop_act();//店舗処理
		int emp_act(int S,int C);
		int make_create();
		//内部子処理
		int zaiko_cnt();
		int sell_data_cul(int N=0);
		int emp_plus(int E,int S);
		int emp_yame(int E,int MES);
		int skill_efe(int C,int UD);//
		//
		int eve_check();//イベント条件判定処理
		int eve_syori(int E);//イベント発生処理
		int eve_boom();
		int game_over();//ゲーム終了
		int medal_check();//メダル取得判定
		int game_rerecord();//記録更新処理

		//イベントスクリプト用
		int act_mes(int N,int MS,int UD,char M1[],char M2[] = "",char M3[]="");//文字格納
		int act_set(int N,int X,int Y,int T,int M,char NAME[]);
		int act_mov(int N,int MX,int MY,int S);
		//
		int input_pass();
		//システム処理
		int inp_check(void);//入力チェック
		int err_c();//エラーチェック
		int se_ok(int S);//効果音
		int bgm_ok(int M);
		//乱数生成関数
		int Rand(int R);//乱数生成
		int set_rand(unsigned long S);

		int hun_shopout(int C);//退店
		int hun_timeup(int C);//時間切れ

		int tutorial(int N,int OK = 0);//チュートリアル関数
		int tutorial_menu();

		int Max(int a=0,int b = 0,int c=0,int d = 0,int e = 0,int f = 0);
		int Min(int a=999999,int b = 999999,int c=999999,int d = 999999,int e = 999999,int f = 999999);
	}fun;
	class AI{
		public:
		int wep_sel(int S);//武器選択処理
		int set_emp(int S);//労働者配置処理
		int mana_sel(int S);//戦術選択処理
		int taiguu_sel(int S);//待遇決定処理
		int koyou_sel(int S);//雇用処理
		int emp_kai(int S);//最適な人員を計算
		int emp_sei(int S);//最適な人員を計算
		int jinji_cul(int S);
		int jinji_sel(int S,int J);

		int emp_hyou[EMP_M];
		int tai_heikin;//店舗の体力平均
		int tai_husoku;

		int wep_cnt[4];//系統別在庫数、予測
		int wep_tc[4];//系統別棚数

		int no[100][4];//系統別番号
		int ninki[100][4];//人気
		int list[4];//系統別数

		int wep_n[400];//武器番号
		int wep_rf[400];//在庫数予測
		int wep_kai[400];//開発予定リスト
		int wep_kp[400];//投入開発力
		int kai_cnt;
		int sei_cnt;
		int zero_cnt;//在庫超少ない武器数
		int syou_cnt;//在庫余裕が無い武器数
		int kaico_cnt;//解雇数
		int custom_pre;//先月客数

		//int nougu;
	}ai;
	class DRA{//描画クラス
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

		int win_help();//ヘルプウィンドウ
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
		int win_htai();//待遇変更用
		int win_hmes(const char str[],int XS=80,int YS=32,int N = 0);//文章のみのヘルプ//Ｇ＝行数
		int win_tmes(const char str[],int X,int Y,int N,int S);//文章のみのヘルプ//Ｇ＝行数

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
		int waku_h(int N);//噴出し
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

		int kai_t[WEP_M];//残り表示時間
		int kai_c[WEP_M];//色

		int lv_t[EMP_M];//残り表示時間

		int sell_t[WEP_M];//販売表示

		int game_over();//ゲーム終了

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

	int eve_no;//現在のイベント
	int eve_wait;//入力待ち時間
	int eve_next;//次へ
	int eve_line;//何行目のイベント
	int eve_end;//イベント終了フラグ
	int eve_black;//暗転
	int eve_bback;//暗転後背景
	std::string eve_name;//知名
	int eve_namew;//知名長さ

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

	//void はじまり();

	//戦術効果処理
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
	//説明文処理
	int mana_setumei();
	int seido_setumei();

	int back_change(EStage estage , int T = 1);//背景変更

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

static const int M_KUSY = 14;//組合の掌握
static const int M_TEKI = 18;//適材適所
static const int M_SUKR = 19;//スクラム
static const int M_SINK = 22;//新卒採用強化
static const int M_TYUK = 23;//中途採用強化
static const int M_GLDS = 30;//黄金の精神
static const int M_GLDM = 31;//黄金の意思
static const int M_NOBI = 32;//のびのび
static const int M_LOVP = 39;//愛社精神力
static const int M_ELVE = 44;//武器屋的対話
static const int M_WECO = 45;//武器屋的対話
static const int M_KAKU = 49;//覚醒の手引き

static const int M_IDEB = 67;//アイデア手当
static const int M_BONU = 70;//ボーナス制度
static const int M_KAIK = 72;//解雇手当
static const int M_MOKA = 77;//持ち株制度-廃止
static const int M_TEST = 78;//試用期間
static const int M_JITU = 82;//現物支給
static const int M_KUUK = 83;//空間活用
static const int M_SABI = 85;//労働力無償供給
static const int M_MATP = 86;//マトックプリン
static const int M_AHUR = 89;//あふれるサンプル

static const int M_ONRF = 134;//一夜リフォーム
static const int M_TAKM = 135;//匠リフォーム
static const int M_SYSA = 136;//宿舎
static const int M_SAKU = 137;//柵

static const int M_NILE = 188;//人月神話
static const int M_IDEC = 189;//アイデアの結晶
static const int M_ENAL = 197;//至高への到達
static const int M_LOST = 198;//失われし技術
static const int M_NTEC = 199;//新技術の導入
static const int M_AJYA = 200;//アジャイル開発
static const int M_TOCG = 201;//特許取得
static const int M_KORO = 202;//これはオマージュ
static const int M_BARA = 203;//バランス
static const int M_HUMI = 204;//踏み台

static const int M_NSEL = 251;//ナウオンセール
static const int M_KAKH = 252;//安心の価格保障
static const int M_PCAD = 253;//Ｐカード
static const int M_TENF = 254;//十人に一人無料！

static const int M_KOUT = 261;//広告塔を建てよう
static const int M_YURU = 262;//ゆるきゃら誕生
static const int M_BURA = 263;//ブランドロゴマーク
static const int M_MATO = 264;//まとえて買え

static const int M_NKAR = 265;//新たな狩場セール
static const int M_GAIS = 266;//凱旋謳う
static const int M_HEIT = 267;//閉店セール

static const int M_RIFO = 268;//リフォームセール
static const int M_METE = 269;//名物店員

static const int M_HOMO = 270;//本家本元
static const int M_NOSE = 271;//宣伝しない宣伝＜使用不可にする戦術も変更

static const int M_UTES = 272;//雨天セール
static const int M_SURI = 273;//すりこみ

/*
	data.mode_n[1] = "シナリオ";
	data.mode_n[2] = "自由経済";//フリーモード、目標下５つ
	data.mode_n[3] = "メダルの王";//メダル数で強化
	data.mode_n[4] = "現生主義";//資金目標
	data.mode_n[5] = "千客万来";//客数目標
	data.mode_n[6] = "株価は踊る";//株価目標
	data.mode_n[7] = "シェアＮＯ１";//販売目標
	data.mode_n[8] = "つるはし大好き";//つるはし数目標
	data.mode_n[9] = "開拓最前線";//１店のみボス攻略数
	data.mode_n[10] = "無双の斧";//カノン編-つるはしor斧
	data.mode_n[11] = "究極の槍";//ホワイトナイト-大会優勝or槍
	data.mode_n[12] = "至高の剣";//月極-開発or剣
	data.mode_n[13] = "完璧の弓";//ゴランノス-株価or弓
	data.mode_n[14] = "ウェポンマイスター";//四種武器どれか
	data.mode_n[15] = "アイスエイジ";//求職者超多い
	data.mode_n[16] = "閃き道場";//閃き率がとても高い
	data.mode_n[17] = "大ハンター時代";//ハンターがとても多い
	data.mode_n[18] = "心のゆとり世代";//ハンターが増えない
*/