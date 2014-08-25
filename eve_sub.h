#pragma once

enum class DI
{
	下,
	上,
	左,
	右
};

enum class EM
{
	驚き = 0,
	音符 = 1,
	困惑 = 2,
	呆れ = 4,
	怒り = 5,
	ハート = 6,
	ドクロ = 7,
	眠り = 8,
	疑問 = 10,
	思考 = 13,
};

enum class EChara
{
	セオ = 1,
	ルルファ,
	ファクト,
	トウツグ,
	シエホ,
	ヘルメス,

	アックス = 10,
	カノン,
	タクミ,

	ブロン = 15,
	エリザ,

	ヒトフリサイ = 20,
	ジンイチ,
	ケンヒメ,

	リークオ = 25,
	ポンサー,
	カクシャ,
	
	シロ = 30,
	
	ニット,
	レイブル,
	
	サンダー,
	ファイア,
	アイス,

	ファイ,
	メディ,
	パラコ,
	レンジ,

	ガイア,
	シズ,

	オキテロ,

	教授,
	ジョッシュ,
	メイコ,

	語り部,

	スタイト,
	ハルファド,
	タクス,
	ゴクト,

	マスコン,

	兵士,
	受付,
	店員,

	司会
};

enum class EStage
{
	店外 = 0,
	酒場 = 7,
	店内 = 1,
	会議室 = 5,
	役所 = 8,
	広場 = 6,
};

class ACTER{
	public:
	int x;//演者位置
	int y;//
	int emo;//感情
	int mx;//残り移動量
	int my;
	int sp;//移動速度
	int p;//歩行アニメ
	int m;//向き
	int no;//画像
	int huki_w;//幅
	int huki_h;//高さ
	int huki_ud;//表示位置
	int name_w;//名前横幅
	char huki_mes[3][101];//文字
	char name[15];//名前

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

	void E驚き();
	void E音符();
	void E困惑();
	void E呆れ();
	void E怒り();
	void Eハート();
	void Eドクロ();
	void E眠り();
	void E疑問();
	void E思考();

	void DoMove();

};

class EVE_SUB
{
	public:
		static void Switch(int E);

		static void 導入_シナリオ();
		static void 導入_自由経済();
		static void 導入_メダルの王();
		static void 導入_拝金主義();
		static void 導入_千客万来();
		static void 導入_株を育てて();
		static void 導入_シェアNo1();
		static void 導入_つるはし大好き();
		static void 導入_開拓最前線();
		static void 導入_無双の斧();
		static void 導入_究極の槍();
		static void 導入_至高の剣();
		static void 導入_完璧の弓();
		static void 導入_ウェポンマイスター();
		static void 導入_アイスエイジ();
		static void 導入_閃き道場();
		static void 導入_大ハンター時代();
		static void 導入_時代の終わり();
		static void つるはし祭り();
		static void 武器屋祭り();

		//メインシナリオ 1
		static void 開店();
		static void つるはし製造開始();
		static void 営業許可A();
		static void 営業許可B();
		static void 新聞取材();		
		static void 調査狩猟();
		static void 最強のハンター();
		static void 人材募集開始();
		static void トウツグ採用();
		static void ルルファ採用();
		
		static void つるはし納品();
		//メインシナリオ 2
		static void 経営二ヶ月目();
		static void 経営のススメ();
		static void スタイト視察();//つるはし受注回復
		static void 魔獣の資源();
		static void 新聞取材2();
		static void 工事のススメ();

		//メインシナリオ 3
		static void 経営三ヶ月目();//人材募集と、新商品についての会議
		static void ルルファの兄();	
		static void シエホ採用();
		static void 財務のススメ();
		static void 教授投資家();
		static void カノン工房();
		static void 昇給要求();

		//メインシナリオ 4
		static void ヘルメス採用();
		static void 開発のススメ();
		static void ハンター協会();
		static void 宣伝のススメ();
		static void がらの悪い三人衆();
		static void ホワイトナイト();
		static void 四人組のハンター();

		//メインシナリオ 5
		static void 武器屋祭り布告();
		static void 調査続行();		

		//メインシナリオ 6
		static void 極月鍛冶();
		static void トウツグと極月();

		//メインシナリオ 7
		static void 武器屋祭り開催();
		static void つるはし祭り布告();

		//メインシナリオ 8
		static void ドラゴンの瞳();

		//メインシナリオ 9
		static void つるはし祭り開催();

		//メインシナリオ 10
		static void 開拓状況();

		//メインシナリオ 11
		static void ゴランノスの噂();

		//メインシナリオ 12
		static void ゴランノス出店();
		static void ルルファ兄失踪();

		//サブイベント
		//従業員会話
		//ルルファ、接客について
		//ファクト、製造について
		//ヘルメス、開発・改良について
		//シエホ、財務に関して
		//恋愛要素

		//他店との絡み
		//カノン工房-つるはし、工事関連
		//極月工房-トウツグ絡み
		//ホワイトナイト-シエホ
		//ゴランノスウェポンズ-メインストーリー

		//ハンター会話
		//シロ、ボス級との対決
		//四人組、
		//悪そうなの
		//ルルファ兄弟
		//助手達

		//その他会話
		//ハンター協会
		//研究所＿たまに遊びに来る
		//マスコミ＿大きなニュースがあると取材に来る
		//政府＿たまに納品時にイベント

		static int Contest();
};

