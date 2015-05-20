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
	/*
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
	*/

	/*1.1*/
	/*プロローグ*/
	/*語り部による導入。*/
	static void _1_1_1();

	/*開店*/
	/*主人公とファクトの二人が店舗を開設した所からスタート。*/
	static void _1_1_2();

	/*製造開始*/
	/*武器の製造開始！と思いきや、鉱山開発用のつるはしを製造する事に。*/
	/*ここで竜が生息している伏線が貼られる。*/
	static void _1_1_3();

	/*総督の視察と営業許可A*/
	/*総督が部下を連れて武器屋の視察に来る。*/
	/*賄賂を要求されたが、ムカついたのでお菓子を渡す。*/
	static void _1_1_4();

	/*総督の視察と営業許可B*/
	/*賄賂の要求でお菓子を渡された事に起こって総督が反乱軍の容疑でやってくる、*/
	/*都合良く副総督がやってきてその場を収める。*/
	static void _1_1_5();

	/*初めての客*/
	/*いつもの様につるはしの生産計画の確認をしていた所、人が訪ねてきた。*/
	/*何の用か ? と聞くと武器を買いに来た･･･だと？*/
	/*来客者は調査のために狩猟をしているハンターだと言うので、初めて武器が売れる。*/
	/*以後ちょくちょく客が来るようになる。*/
	static void _1_1_6();

	/*ドラゴンハンター*/
	/*またもや来客、竜を狩るための武器を探しているという。*/
	/*竜なんて本当にいるのか？と聞くと、色々話をしてくれた。*/
	static void _1_1_7();

	/*募集開始*/
	/*思ったより武器の売れ行きが良く。*/
	/*追加で職人を雇う事に。*/
	static void _1_1_8();

	/*刀継採用*/
	/*募集を開始した翌日、武器製造の経験者だと言う若者がやってくる。*/
	/*結局採用する事に。*/
	static void _1_1_9();

	/*ルルファ採用*/
	/*可愛らしい女の子が職人志望？に来たのでセオは喜ぶが、接客志望だと分かる、*/
	/*とりあえず接客も募集していた事にして採用するのであった。*/
	static void _1_1_10();

	/*つるはし納品*/
	/*納品日になったので、つるはしを持ち役場に出向く。*/
	/*副総督から圧力があったのか、来月は受注を無くなる事に。*/
	static void _1_1_11();

	/*1.2*/
	/*	新入り入社*/
	/*月初めの挨拶と、新入りの自己紹介*/
	static void _1_2_1();

	/*経営体制をつくる*/
	/*社員が増えてきそうだし、社内制度を見直す動きをする*/
	static void _1_2_2();

	/*教授と調査狩猟団*/
	/*以前に買い物に来た調査団の団長が来訪、*/
	/*団員募集を手伝って欲しい、代わりに宣伝を手伝おうとの事。*/
	static void _1_2_3();

	/*工房取材*/
	/*フロンティア新聞の記者が来訪。*/
	/*開店理由等の取材を受ける、他店の動向についても聞く。*/
	static void _1_2_4();

	/*副総督の視察*/
	/*店の状況を見に副総督が来訪、つるはし納品数が増える。*/
	static void _1_2_5();

	/*1.3*/
	/*工事のススメ*/
	/*月初めの朝礼で、設備投資について語る。*/
	static void _1_3_1();

	/*ルルファの兄*/
	/*調査狩猟団員になったので武器を買いに来た、ルルファの兄二人が来店。*/
	/*調度品として魔物の毛皮等が売れるとかで団員を増やしているらしい。*/
	static void _1_3_2();

	/*カノン工房*/
	/*つるはし等を製造していたカノン工房が武器の販売を開始。*/
	/*なぜか乗り込んでくる。*/
	static void _1_3_3();

	/*財務について*/
	/*利益も出てきたので、余剰資金の使い道について。*/
	static void _1_3_4();

	/*1.4*/
	/*月初めの挨拶*/
	/*ライバル店への言及。*/
	static void _1_4_1();

	/*がらの悪い二人組*/
	/*狩猟団から紹介されたとかで来店した、すごく感じの悪いハンターが来店。*/
	static void _1_4_2();

	/*極月鍛冶*/
	/*新しく武器屋がまた出来たらしく、何故かカノンが来店。*/
	/*刀次はなにか知っている様子。*/
	static void _1_4_3();

	/*宣伝作戦*/
	/*他の武器屋も増えたので宣伝を強化しようといった話。*/
	static void _1_4_4();

	/*待遇改善要求
	/*ファクトより店員が昇給を要求していると聞く。*/
	/*儲かっているし利益を還元しようかと言った流れに。*/
	static void _1_4_5();

	/*1.5*/
	/*月初め*/
	/*業績が好調で給料も上げるぞ、みたいな話。*/
	static void _1_5_1();

	/*ドラゴンハンター再び*/
	/*竜の情報についてあれこれ。*/
	static void _1_5_2();

	/*魔獣の資源*/
	/*新聞のスクープ記事で、ゼラルーを燃料として使う方法が実用化したとの事。*/
	/*今後のハンター増加が見込まれる。*/
	static void _1_5_3();

	/*開拓祭り布告*/
	/*久しぶりに総督が来店、魔獣の資源化と入植開始5週年を記念して祭りをする事になったとか。*/
	static void _1_5_4();

	/*1.6*/
	/*月初め*/
	/*開拓祭りが来月にある事と、魔獣の資源化についてあれこれ*/
	static void _1_6_1();

	/*ハンター協会拡大*/
	/*プロフェッサーが来訪、資源化で調査狩猟団を拡大する説明等。*/
	static void _1_6_2();

	/*開拓祭りに誘う*/
	/*祭りの日は休みなので、ルルファを誘う事に*/
	/*ルルファ兄がたまたま訪問*/
	static void _1_6_3();

	/*新ハンター来訪*/
	/*狩猟団の新しい人が来る。*/
	/*ガラの悪いハンターも何か言う。*/
	static void _1_6_4();

	/*1.7*/
	/*月初め*/
	/*開拓祭りと、ハンター増について言及*/
	static void _1_7_1();

	/*新武器の開発*/
	/*ファクトが展示会用の武器を持ってくる。*/
	/*セオは装飾が微妙と返す、刀次は変な性癖を発揮。*/
	static void _1_7_2();

	/*開拓祭り開催*/
	/*演説やら展示会やら、久々に総督登場*/
	static void _1_7_3();

	/*ヘルメス採用*/
	/*祭りの時に露天であった人が、募集に来る。*/
	static void _1_7_4();

	/*1.8*/
	/*月初め* /
	/*ヘルメスの登用と、新商品開発について。*/
	static void _1_8_1();

	/*竜の遺産*/
	/*中央のオークションで竜の瞳が競売にかけられ凄まじい金額で売れる。*/
	/*ドラゴンハンターと会話、他の店の言及等。*/
	static void _1_8_2();

	/*極月刀鍛冶来訪*/
	/*祭り会場で見かけたとかで極月が刀次を連れ戻しに来る。*/
	/*喧嘩して終了。事情は聞けなかった。*/
	static void _1_8_3();

	/*ルルファ兄来訪*/
	/*ドラゴンの噂と、ドラゴン倒すぞー的な。*/
	static void _1_8_4();

	/*1.9*/
	/*月初め*/
	/*開拓が進んでいる事、ハンターが急増している事について*/
	static void _1_9_1();

	/*新人向けに安い武器*/
	/*ファクトがヘルメスの方針に文句を付ける、安い武器が必要だと言う。*/
	/*ファクトが老害っぽい感じで。*/
	static void _1_9_2();

	/*総督来店*/
	/*いやがらせにくる。*/
	static void _1_9_3();

	/*ハンター同士のトラブル*/
	/*ガラの悪い二人組みと、新入りハンターが店内でトラブルを起こす。*/
	static void _1_9_4();

	/*1.10*/
	/*月初め*/
	/*客とのトラブルについて。*/
	static void _1_10_1();

	/*プロフェッサー再び*/
	/*開拓の進み具合についてと、先日のトラブルについて等。*/
	static void _1_10_2();

	/*ルルファ兄との会話*/
	/*協会の実態について話したり、ハンター同士のトラブルについて。*/
	static void _1_10_3();

	/*・極月から*/
	/*刃一が説得にくる。*/
	static void _1_10_4();

	/*1.11*/
	/*・月初め*/
	/*経営は順調です。特に何も無し。*/
	static void _1_11_1();

	/*・ゴランノス出店の噂*/
	/*ルルファ兄からホワイトナイトの買収とゴランノス出展の噂を聞く。*/
	static void _1_11_2();

	/*・トウジの様子*/
	/*彼女が出来たらしい？(妹だったとか)*/
	static void _1_11_3();

	/*・ドラゴン目撃情報*/
	/*がらの悪いハンターが来店、ドラゴンがどうのこうの。*/
	static void _1_11_4();

	/*1.12*/
	/*・月初め*/
	/*ドラゴンの目撃情報について、対ドラゴン武器の開発が必要。*/
	static void _1_12_1();

	/*・ゴランノス出店*/
	/*ゴランノスが新規出店、支店長が宣戦布告に来る。*/
	static void _1_12_2();

	/*・対ドラゴン武器の開発*/
	/*対ドラゴン武器の開発状況について。*/
	static void _1_12_3();

	/*・副総督来店*/
	/*ゴランノスの情報等を何故か流してくれる。*/
	static void _1_12_4();

	/*2.1*/
	/*・月礼*/
	/*ルルファが珍しく遅刻。*/
	/*ドラゴンの襲撃を受け、ルルファ兄を含むハンター数名が死亡 / 行方不明。*/
	/*言論規制が敷かれるが、噂は直ぐに広まった。*/
	/*ルルファは休暇に入る。*/
	static void _2_1_1();

	/*・ゴランノスの投げ売り*/
	/*事前の情報通り、ゴランノスがセールを開始する。*/
	static void _2_1_2();

	/*・ドラゴン噂*/
	/*ドラゴン襲撃についてドラゴンハンターが来店。*/
	/*ドラゴンの懸賞金の話等、色々喋る。退治してくれていたらとかなんとか。*/
	static void _2_1_3();

	/*・カノン工房*/
	/*売上減少を危機に感じたカノンが来店。*/
	/*協力を打診してくる。部分的に協力する事に、極月とは協力出来ない。*/
	static void _2_1_4();

	/*2.2*/
	/*・月初め*/
	/*ゴランノスのセールの影響等について*/
	/*ルルファ復帰*/
	static void _2_2_1();

	/*・ルルファと会話*/
	/*何があったのか等*/
	static void _2_2_2();

	/*・来店*/
	/*がらの悪いハンターが来店、ゴランノス製品はゴミだ。*/
	/*協会もゴランノス製品をネガキャンしているとか。*/
	static void _2_2_3();

	/*・セール終了*/
	/*ゴランノスが安売りを止めて、リニューアルを始めるとの噂。*/
	static void _2_2_4();

	/*2.3*/
	/*・月初め*/
	/*ゴランノスのセール終了について。*/
	static void _2_3_1();

	/*・総督来店*/
	/*ゴランノスの出店失敗とその背景について。*/
	/*中央がどうとか。*/
	static void _2_3_2();

	/*・協力を続けるか？*/
	/*カノンがゴランノス失敗に喜び勇んでやってくる。*/
	/*今後も技術協力は続ける事に。ファクトは反対。*/
	static void _2_3_3();

	/*・ドラゴンの被害状況*/
	/*また、竜に襲われハンターが死亡したらしい。*/
	/*町の結構近くだとか。*/
	static void _2_3_4();

	/*2.4*/
	/*・月初め*/
	/*ドラゴンの脅威について。*/
	static void _2_4_1();

	/*・団長来店*/
	/*ゴランノスの失敗について、喜ぶ団長。*/
	static void _2_4_2();

	/*・ゴランノス、リニューアル*/
	/*ゴランノス社が店長を交代してリニューアルオープン。*/
	/*なぜかフロンティアスミスと殆ど同じ武器が並び、セールが開始。*/
	/*評判は多少回復したそうです。*/
	static void _2_4_3();

	/*・カノン来店*/
	/*技術流出について誰が流したか等で議論が紛糾。*/
	/*協力体制が決裂する。*/
	static void _2_4_4();

	/*2.5*/
	/*・月初め*/
	/*情報流出問題についてなど*/
	static void _2_5_1();

	/*・新武器の開発*/
	/*そもそも剣で竜と戦うのは無理では？*/
	/*という事でヘルメスが銃の製造を提案する。*/
	/*ゼラルー火薬の発明がどうのこうの。*/
	/*(銃は既に存在しているが、普及はしていない)*/
	static void _2_5_2();

	/*・ドラゴンハンター来店*/
	/*今ある武器で倒しに行く事にするらしい。*/
	/*ルルファは複雑な感じ。*/
	static void _2_5_3();

	/*・ルルファ兄来店*/
	/*酔っ払ったルルファ兄が来店。*/
	static void _2_5_4();

	/*2.6*/
	/*・月初め*/
	/*好調だけど、ゴランノスに苦戦気味。*/
	static void _2_6_1();

	/*・総督来店*/
	/*ゴランノス躍進の自慢と開拓祭の告知。*/
	static void _2_6_2();

	/*・ハンター来店*/
	/*ドラゴンにびびってる奴や倒そうとしている奴がいる事など雑談。*/
	static void _2_6_3();

	/*・銃器サンプル*/
	/*銃の試作が完成。祭りで展示する事に。*/
	static void _2_6_4();

	/*2.7*/
	/*・月初め*/
	/*1年ぶりに開拓祭があります。*/
	static void _2_7_1();

	/*・祭りに誘う*/
	/*ルルファを祭りに誘う。*/
	static void _2_7_2();

	/*・開拓祭り*/
	/*一年ぶりの開催。*/
	static void _2_7_3();

	/*・カノン工房が武器事業を終了*/
	/*つるはし事業に専念するとか。*/
	static void _2_7_4();

	/*2.8*/
	/*・月初め*/
	/*銃の展示が成功だった事。*/
	static void _2_8_1();

	/*・ハンター会長来店*/
	/*銃の開発に協力しようとやってくる。*/
	static void _2_8_2();

	/*・開発体制*/
	/*今後は銃の開発を強化し、情報流出に備えようと言う事に。*/
	/*ファクトが反発する。*/
	static void _2_8_3();

	/*・竜が討伐された？*/
	/*竜の目撃情報が減っているらしい。*/
	/*竜の鱗を入手した人が現れる。*/
	static void _2_8_4();

	/*2.9*/
	/*・月初め*/
	/*竜討伐の噂について。*/
	static void _2_9_1();

	/*・総督来店*/
	/*ゴランノスが銃の発表会を行うと情報をくれる。*/
	/*ファクトが疑われる。*/
	static void _2_9_2();

	/*・ゴランノスが銃の発表会*/
	/*事故を起こす。*/
	static void _2_9_3();

	/*・フロンティアスミスが銃の発表会*/
	/*成功する。*/
	static void _2_9_4();

	/*2.10*/
	/*・月初め*/
	/*銃の製造拡大に*/
	static void _2_10_1();

	/*・ファクト退職*/
	/*ついていけなくなったとか。*/
	static void _2_10_2();

	/*・シロ来店*/
	/*ドラゴンの討伐について。*/
	/*ファクトがいなくてがっかりみたいな感じ。*/
	static void _2_10_3();

	/*・銃の販売開始*/
	/*ドラゴンが討伐された件は隠される。*/
	static void _2_10_4();

	/*2.11*/
	/*・月初め*/
	/*銃の販売は好調。*/
	static void _2_11_1();

	/*・銃の量産計画*/
	/*売れまくってるのでどんどん増産する。*/
	static void _2_11_2();

	/*・ゴランノス撤退*/
	/*ゴランノスが西部での武器販売から撤退する事に。*/
	static void _2_11_3();

	/*・トウツグ退職*/
	/*実家に帰るらしい。*/
	static void _2_11_4();

	/*2.12*/
	/*・月初め*/
	/*ゴランノスの撤退について。*/
	static void _2_12_1();

	/*・副総督の演説とクーデター*/
	static void _2_12_2();

	/*・中央で反乱軍の蜂起*/
	static void _2_12_3();

	/*・エンディング*/
	static void _2_12_4();
	};

	/*
	void EVE_SUB::新聞取材2()
	{
	//魔獣資源化に関して取材。

	START
	act[0].Set(EChara::セオ,6,4,DI::下);
	act[1].Set(EChara::マスコン,6,8,DI::上);
	BackChenge(EStage::会議室);
	TO
	act[1].Mes("お忙しい所、すいません");
	TO
	act[0].Mes("いえいえ、こちらも店の宣伝になりますからね");
	TO
	act[1].Mes("それでは早速取材を始めますよ！");
	TO
	act[1].Mes("セオさんはなぜフロンティアで武器屋を始めようと？");
	TO
	act[0].Mes("フロンティアには武器屋が無いと言う話を聞いて＠魔獣が多く生息しているなら武器の需要もあると踏んで");
	TO
	act[0].Mes("以前は中央の武器工場で管理の仕事をしていたんですが＠自分の会社を作りたいと思っていましたし");
	TO
	act[1].Mes("そうですか、今回の発見を事前に知っていたわけではないと？");
	TO
	act[0].Mes("例の件は全く知りませんでした＠思ったよりも武器は売れなかったので＠伝えた時は社員も喜んでいましたよ");
	TO
	act[0].Mes("今後はより強い武器も販売していきたいですね");
	TO
	act[1].Mes("カノン工房さんは、やはり気になさってますか");
	TO
	act[0].E疑問();
	TO
	act[0].Mes("カノン工房？");
	TO
	act[1].Mes("ご存知なかったんですか？＠つるはし製造の経験を活かして、武器屋を始めるらしいですよ");
	TO
	act[0].E驚き();
	TO
	act[0].Mes("それは初耳ですね・・・");
	TO
	act[0].Mes("まぁ、他店は気にせず＠うちはいい武器を作るだけですね");
	TO
	act[1].Mes("なるほど");
	TO
	act[1].E思考();
	TO
	act[0].Mes("次は工場を案内しますよ");
	TO
	act[1].Mes("是非ともお願いします");
	END
	}


	void EVE_SUB::教授投資家()
	{
	//投資家募集に対して登場
	//なぜかデザインにケチをつけられる
	START
	act[0].Set(EChara::セオ, 7, 4, DI::下);
	act[1].Set(EChara::教授, 7, 12, DI::左,false);
	act[2].Set(EChara::メイコ, 6, 11, DI::左,false);
	act[3].Set(EChara::ジョッシュ, 8, 11, DI::左,false);
	BackChenge(EStage::店内);
	TO
	act[1].Move(0, -5);
	act[2].Move(0, -5);
	act[3].Move(0, -5);
	TO
	act[0].Mes("いらっしゃいませ");
	TO
	act[0].Mes("いつもご贔屓にして下さってありがとうございます＠本日はどのような武器を？");
	TO
	act[3].Mes("いえ、今日は武器を買いに来たのではないんですよ");
	TO
	act[0].E疑問();
	TO
	act[2].Down();
	act[2].Mes("博士");
	TO
	act[1].Move(0,-1);
	TO
	act[2].Up();
	act[1].Mes("君が社長さんかね？");
	TO
	act[0].Mes("はい、そうですが");
	TO
	act[0].Mes("えっと、あなたは？");
	TO
	act[1].E驚き();
	TO
	act[1].Mes("まさか、私を知らない人間がいるとは");
	TO
	act[2].E呆れ();
	act[3].E呆れ();
	TO
	act[0].Mes("そういえばどこかで・・・");
	TO
	act[1].E思考();
	TO
	act[1].Mes("我が名はトージョー");
	TO
	act[0].Mes("トージョー・・・ゼラルー油の！？");
	TO
	act[1].Mes("そのとおり！");
	TO
	act[1].Mes("フロンティア・・・いや世界一の天才である＠私を知らない人間はやはりいないか");
	TO
	act[0].E呆れ();
	act[1].E音符();
	TO
	act[0].Mes("えっと、本日はどのようなご用件で？");
	TO
	act[1].Mes("もちろん買い物だよ");
	TO
	act[1].Mes("この店の株を買いたい");
	TO
	act[0].Mes("株ですか？");
	TO
	act[1].Mes("武器屋に投資すれば、より強い武器が作れるようになり＠フロンティアの探索が進むと思ってね");
	TO
	act[0].E思考();
	TO
	act[0].Mes("いきなりそう言われましても・・・＠そう単純な話でもありませんし");
	TO
	act[1].Mes("まぁそれもそうだな＠投資して欲しくなったら連絡してくれ");
	TO
	act[1].Mes("では！また会おう！");
	TO
	act[1].Move(0,6);
	TO
	act[3].Mes("すいません・・・");
	TO
	act[0].Mes("いえいえ");
	END
	}

	//メインシナリオ 4
	void EVE_SUB::ヘルメス採用()
	{
	//デザイン力不足で悩んでいた所
	//露天商をしていたヘルメスをスカウトする

	START
	act[0].Set(EChara::セオ, -1, 7, DI::左);
	act[1].Set(EChara::ルルファ, -1, 8, DI::左,false);
	act[2].Set(EChara::ヘルメス,7,5,DI::下);
	BackChenge(EStage::広場);
	TO
	act[0].Move(7, 0);
	act[1].Move(7, 0);
	TO
	act[0].Down();
	act[1].Up();
	act[0].Mes("悪いね、休みの日に買い物に付き合って貰って");
	TO
	act[1].Mes("全然そんなことないですよ、気にしないでください");
	TO
	act[0].E音符();
	TO
	act[0].Mes("本当！？＠じゃあ、またお願いしようかな！");
	TO
	act[2].Mes("そこのおにーさん");
	TO
	act[0].Up();
	act[0].E疑問();
	TO
	act[0].Mes("俺？");
	TO
	act[2].Mes("そっちは彼女さん？");
	TO
	act[0].E驚き();
	TO
	act[0].Mes("いやぁ、そんなんじゃないですよ");
	TO
	act[1].E疑問();
	TO
	act[2].Mes("そうなん？");
	TO
	act[2].Mes("まぁええか、アクセサリー売ってるんやけど、見てかへん？");
	TO
	act[0].Mes("どれどれ・・・");
	TO
	act[0].E思考();
	TO
	act[1].Mes("格好良いデザインですね");
	TO
	act[0].Mes("どちらで仕入れられているんですか？");
	TO
	act[2].Mes("全部、私が作ったんや");
	TO
	act[0].E思考();
	TO
	act[2].Mes("どれにします？");
	TO
	act[0].Mes("うちで働きませんか？");
	TO
	act[2].E疑問();
	TO
	act[2].Mes("はい？");
	TO
	act[0].Mes("実はかくかくしかじかで＠デザインの得意な職人が必要なんです");
	TO
	act[2].Mes("なるほど～");
	TO
	act[2].E思考();
	TO
	act[2].Mes("悪い話じゃないんやけど");
	TO
	act[1].Mes("私からもお願いします");
	TO
	act[2].E思考();
	TO
	act[2].Mes("分かった、私の名前はヘルメス＠よろしゅう社長さん");
	END
	}
	void EVE_SUB::開発のススメ()
	{
	//ヘルメスの意見により開発部を作る事に
	START
	act[0].Set(EChara::セオ,7,4,DI::左);
	act[1].Set(EChara::ファクト,6,4,DI::右);
	act[2].Set(EChara::トウツグ,6,3,DI::右);
	BackChenge(EStage::店内);
	TO
	act[0].E思考();
	TO
	act[1].Mes("どうだい、新作の武器は？");
	TO
	act[2].Mes("今までの武器に比べて、かなり性能が上がってるはずです");
	TO
	act[0].E思考();
	TO
	act[0].Mes("たしかに性能は上がってるが・・・");
	TO
	act[0].Mes("見た目がイケてないのがなぁ＠お前らセンスないよな");
	TO
	act[2].Mes("武器は性能が第一ですよ、見た目なんてどうでもいいでしょう");
	TO
	act[1].Mes("僕もそう思うけど");
	TO
	act[0].Mes("まぁ、俺もそう思う");
	TO
	act[0].Mes("実際、ハンター同士の見栄の張り合いみたいなのがあって＠格好良さは売上に影響があるんだよ");
	TO
	act[0].Mes("とにかく、デザインを練りなおしてくれ");
	TO
	act[1].E思考();
	TO
	act[1].Mes("分かった、もうちょっと考えるよ");
	END
	}
	void EVE_SUB::ハンター協会()
	{
	//ハンター協会とかいう組織が出来たらしく
	//その宣伝に会長が登場
	//没
	START
	act[0].Set(EChara::セオ,7,4,DI::左);
	act[1].Set(EChara::ルルファ, 6, 4, DI::右);
	act[2].Set(EChara::オキテロ,7,11,DI::左);
	BackChenge(EStage::店内);
	TO
	act[1].Mes("お疲れ様です");
	TO
	act[0].Mes("お疲れ、明日もよろしくね");
	END
	}
	void EVE_SUB::宣伝のススメ()
	{
	//宣伝についての会議
	START
	act[0].Set(EChara::セオ,7,4,DI::下);
	act[1].Set(EChara::ニット,6.5,6,DI::上,false);
	act[2].Set(EChara::レイブル,7.5,6,DI::上,false);
	BackChenge(EStage::店内);
	TO
	act[0].Mes("お兄さん、うちの武器はどうですか？");
	TO
	act[1].Mes("良い武器だと思いますよ＠町の周辺の魔物相手なら上等すぎるぐらいです");
	TO
	act[2].Mes("確かにゼラルー相手ならなんでもいいよな");
	TO
	act[0].E呆れ();
	TO
	act[0].Mes("そうですか・・・");
	TO
	act[1].Mes("ルルファは仕事ちゃんとやってますか？");
	TO
	act[0].Mes("とてもまじめに働いて貰って、助かってますよ");
	TO
	act[1].Mes("そそっかしいから、何かやらかしてないか不安で");
	TO
	act[1].Mes("ルルファの事、お願いしますね");
	TO
	act[0].Mes("お任せ下さい！");
	TO
	act[2].Left();
	act[2].Mes("そろそろ行こうぜ");
	TO
	act[1].Mes("それじゃ社長さん、また");
	TO
	act[1].Move(0, 5);
	act[2].Move(0, 5);
	TO
	act[1].Set(EChara::ファイ, 6, 11, DI::左,false);
	act[2].Set(EChara::レンジ, 7, 11, DI::左, false);
	act[3].Set(EChara::パラコ, 8, 11, DI::左, false);
	act[4].Set(EChara::メディ, 9, 11, DI::左, false);
	act[1].Move(0, -5);
	act[2].Move(0, -5);
	act[3].Move(0, -5);
	act[4].Move(0, -5);
	TO
	act[0].Mes("いらっしゃいませ");
	TO
	act[3].Mes("こんな所にも武器屋があったのね");
	TO
	act[4].Mes("こんな店よく見つけたな");
	TO
	act[2].Mes("・・・");
	TO
	act[1].Mes("店員さん！一番いい武器を見せてくれ");
	TO
	act[0].Mes("これなんてどうでしょう？");
	TO
	act[1].E思考();
	TO
	act[1].Mes("いい武器だ、売ってくれ！");
	TO
	act[3].Mes("物はなかなか良さそうね");
	TO
	act[4].Mes("今度武器が壊れたら、買い物にこようかな");
	TO
	act[2].Mes("・・・");
	TO
	act[1].Move(0, 5);
	act[2].Move(0, 5);
	act[3].Move(0, 5);
	act[4].Move(0, 5);
	TO
	act[0].Mes("うちの店って知名度低いのか？");
	END
	}
	void EVE_SUB::がらの悪い三人衆()
	{
	//がらの悪い三人組のハンターが来店
	//没イベント
	START
	act[0].Set(EChara::セオ,6,10,DI::左);
	act[1].Set(EChara::ルルファ,6,10,DI::左);
	act[2].Set(EChara::ファイア,6,10,DI::左);
	act[3].Set(EChara::アイス,6,10,DI::左);
	act[4].Set(EChara::カーン,6,10,DI::左);
	BackChenge(EStage::店内);
	END
	}
	void EVE_SUB::ホワイトナイト()
	{
	//ホワイトナイトが開店＆来訪
	START
	act[0].Set(EChara::セオ,7,4,DI::左);
	act[1].Set(EChara::ファクト, 6, 4, DI::右);
	act[2].Set(EChara::ヘルメス, 2, 2, DI::下);
	BackChenge(EStage::店内);
	TO
	act[2].Move(0, 1);
	TO
	act[2].Move(4, 0);
	TO
	act[2].Down();
	act[2].Mes("おはようさん！");
	TO
	act[0].Up();
	act[1].Up();
	act[0].Mes("ああ、おはよう");
	TO
	act[1].Mes("おはよう");
	TO
	act[2].Mes("何の話ですか？");
	TO
	act[1].Up();
	act[1].Mes("新しい武器屋が出来る話だよ");
	TO
	act[2].Mes("へぇ");
	TO
	act[0].Mes("前に武器屋が出来たときは挨拶に来たから＠一応待ち構えておこうかと");
	TO
	act[2].E疑問();
	TO
	act[2].Mes("そんなやつおらんでしょ？");
	TO
	act[0].Down();
	act[1].Down();
	act[2].Down();
	act[3].Set(EChara::カノン,7,11,DI::上,false);
	TO
	act[3].Move(0, -5);
	TO
	act[3].Mes("久しぶりです！");
	TO
	act[3].Mes("何でも新しい武器屋が出来るらしいです");
	TO
	act[3].E音符();
	TO
	act[3].Mes("知ってました？");
	TO
	act[0].E呆れ();
	act[1].E呆れ();
	TO
	act[0].Mes("帰れ");
	END
	}
	void EVE_SUB::四人組のハンター()
	{
	//四人組のハンターが来店
	//没イベント
	START
	act[0].Set(EChara::セオ,6,10,DI::左);
	act[1].Set(EChara::ファイ,6,10,DI::左);
	act[2].Set(EChara::レンジ,6,10,DI::左);
	act[3].Set(EChara::パラコ,6,10,DI::左);
	act[4].Set(EChara::メディ,6,10,DI::左);
	BackChenge(EStage::店内);
	END
	}
	//メインシナリオ 5
	void EVE_SUB::武器屋祭り布告()
	{
	//武器屋祭り開催について
	//副府長が来訪
	START
	act[0].Set(EChara::セオ,7,4,DI::下);
	act[1].Set(EChara::ハルファド, 7, 11, DI::左,false);
	act[2].Set(EChara::兵士, 6, 12, DI::左);
	act[3].Set(EChara::兵士, 8, 12, DI::左);
	BackChenge(EStage::店内);
	TO
	act[1].Move(0, -5);
	act[2].Move(0, -5);
	act[3].Move(0, -5);
	TO
	act[0].Mes("いらっしゃいま・・・");
	TO
	act[0].E驚き();
	TO
	act[1].Mes("久しぶりだな");
	TO
	act[0].Mes("何の用ですか？");
	TO
	act[1].Mes("今日は菓子を貰いに来たわけではないぞ");
	TO
	act[1].Mes("来月のフロンティア祭で開催される武器屋コンテスト");
	TO
	act[1].Mes("そこに出展して貰おうと思ってな");
	TO
	act[0].Mes("コンテスト？");
	TO
	act[1].Mes("勝てば宣伝になる上、賞金も出る");
	TO
	act[1].Mes("まぁ結果によっては、評判を落とすこともあるだろうが");
	TO
	act[0].E思考();
	TO
	act[0].Mes("そうですね・・・");
	TO
	act[1].Mes("まぁ参加しない店は、武器の質に自信がないと思われるだろう＠きっと、そういう噂が立つぞ");
	TO
	act[0].Mes("分かりました、参加しましょう");
	TO
	act[1].Mes("よくぞ、そういってくれた！");
	TO
	act[1].Mes("審査委員長としても、盛り上がって欲しいからな！");
	TO
	act[1].Mes("それでは次は大会で会おう");
	TO
	act[1].Down();
	act[1].Mes("帰るぞ！");
	TO
	act[1].Move(0, 2);
	TO
	act[1].Move(0, 3);
	act[2].Move(0, 5);
	act[3].Move(0, 5);
	TO
	act[0].Mes("暇なやつだな");
	TO
	act[0].E思考();
	TO
	act[0].Mes("まぁなんとでもなるか");
	END
	}
	void EVE_SUB::調査続行()
	{
	//教授の部下が来訪、雑談
	//ドラゴンの噂
	START
	act[0].Set(EChara::セオ,7,4,DI::下);
	act[1].Set(EChara::ファクト, 6, 4, DI::下);
	act[2].Set(EChara::シロ,7,6,DI::上,false);
	BackChenge(EStage::店内);
	TO
	act[2].E思考();
	TO
	act[2].Mes("駄目だな");
	TO
	act[1].Mes("これでも駄目ですか？");
	TO
	act[2].Mes("これじゃあ、傷すらつけられない");
	TO
	act[0].Mes("しかしドラゴンの鱗って＠一体どれぐらい硬いんですか？");
	TO
	act[2].E思考();
	TO
	act[2].Mes("これがドラゴンの鱗だよ");
	TO
	act[0].E驚き();
	act[1].E驚き();
	TO
	act[1].Mes("これが・・・");
	TO
	act[0].E思考();
	TO
	act[0].Mes("これはどうやって？");
	TO
	act[2].Mes("ドラゴンと戦ってだよ、まぁ逃げられたわけだけど＠その時使っていた剣は失くしてしまってね");
	TO
	act[2].E思考();
	TO
	act[2].Mes("開発に役立つなら、貸そうか？");
	TO
	act[1].Mes("お願いします");
	TO
	act[2].Mes("じゃあまた");
	TO
	act[2].Move(0, 1);
	TO
	act[2].Up();
	act[2].Mes("ああ、それと");
	TO
	act[2].Mes("一応、この話は内密に");
	TO
	act[2].Move(0, 4);
	TO
	act[3].Set(EChara::ジョッシュ, 6.5, 11, DI::左,false);
	act[4].Set(EChara::メイコ, 7.5, 11, DI::左,false);
	act[3].Move(0, -5);
	act[4].Move(0, -5);
	TO
	act[0].Mes("いらっしゃいませ");
	TO
	act[3].Mes("今日は武器を買いに来たのではないんですよ");
	TO
	act[3].Mes("最近広まってる噂について＠セオさんなら何か知っているかと思いまして");
	TO
	act[4].Mes("全く、博士が変な研究を始めちゃって・・・");
	TO
	act[4].Mes("ドラゴンなんていると思う？");
	TO
	act[0].Mes("そういう噂はあるみたいですね＠私もよくわかりません");
	TO
	act[4].Mes("まぁ、お伽話に出てくるような化け物だとしたら＠調査なんてしたくないし、いない方がいいけどね");
	TO
	act[3].Mes("変な事を聞いてすいませんでした＠今度は買い物に来ますね");
	TO
	act[4].Mes("じゃあまたね");
	TO
	act[3].Move(0, 5);
	act[4].Move(0, 5);
	END
	}
	//メインシナリオ 6
	void EVE_SUB::極月鍛冶()
	{
	//極月鍛冶がオープン
	//トウツグを連れ戻しに来たが
	START
	act[0].Set(EChara::セオ, 8, 4, DI::左);
	act[1].Set(EChara::ファクト, 7, 4, DI::右);
	act[2].Set(EChara::トウツグ, 2, 2, DI::下);
	BackChenge(EStage::店内);
	TO
	act[2].Move(0, 2);
	TO
	act[2].Move(4, 0);
	TO
	act[2].Mes("おはようございます");
	TO
	act[0].Left();
	act[1].Left();
	act[0].Mes("ああ、おはよう");
	TO
	act[1].Mes("おはよう");
	TO
	act[2].Mes("何してるんですか？");
	TO
	act[1].Mes("新しい武器屋が出来るらしくてね");
	TO
	act[2].E疑問();
	TO
	act[0].Mes("一応待ち構えておこうかと");
	TO
	act[2].Mes("意味が分からないです");
	TO
	act[0].Mes("そろそろかな？");
	TO
	act[0].Down();
	act[1].Down();
	act[2].Down();
	act[3].Set(EChara::ヒトフリサイ, 7, 11, DI::左);
	act[4].Set(EChara::ジンイチ, 6, 12, DI::左);
	act[5].Set(EChara::ケンヒメ, 8, 12, DI::左);
	TO
	act[3].Move(0, -5);
	act[4].Move(0, -5);
	act[5].Move(0, -5);
	TO
	act[2].E思考();
	TO
	act[0].Mes("いらっしゃいませ");
	TO
	act[3].Mes("初にお目にかかる、極月一振斎と申します");
	TO
	act[0].E疑問();
	TO
	act[0].Mes("極月って、新しく出来る武器屋の？");
	TO
	act[3].Mes("いかにも");
	TO
	act[0].Mes("何の御用でしょうか？");
	TO
	act[3].Mes("当家の技を盗んだ不届き物がいると言う噂を聞きまして");
	TO
	act[3].Mes("のう、剣継");
	TO
	act[0].E疑問();
	TO
	act[0].Left();
	act[0].Mes("知り合いか？");
	TO
	act[2].E思考();
	TO
	act[0].Down();
	act[3].Mes("しかし、噂でしかなかったようですな");
	TO
	act[2].Mes("どういう意味だ？");
	TO
	act[3].Mes("お前の武器は、私が作る武器には遠く及ばん");
	TO
	act[3].Mes("そういう事だ");
	TO
	act[2].E思考();
	TO
	act[3].Mes("お邪魔しましたな");
	TO
	act[3].Move(0, 2);
	TO
	act[3].Move(0, 3);
	act[4].Move(0, 2);
	TO
	act[5].Mes("兄さん・・・");
	TO
	act[4].Up();
	act[4].Mes("帰るぞ");
	TO
	act[5].E思考();
	TO
	act[5].Mes("・・・はい");
	TO
	act[3].Move(0, 1);
	act[4].Move(0, 3);
	act[5].Move(0, 5);
	TO
	act[0].Left();
	act[1].Left();
	act[0].Mes("説明してくれるか");
	TO
	act[2].E思考();
	TO
	act[2].Mes("・・・知りません");
	TO
	act[2].Move(-6, 0);
	TO
	act[0].Mes("おい！");
	TO
	act[1].Right();
	act[1].Mes("ただならぬ感じだったし＠今はそっとしておいた方がいいんじゃないかな？");
	TO
	act[1].Mes("僕が後で話をしておくよ");
	TO
	act[0].Mes("しかしだな");
	TO
	act[3].Set(EChara::カノン, 7, 11, DI::上, false);
	TO
	act[3].Move(0, -5);
	TO
	act[0].Down();
	act[1].Down();
	act[3].Mes("久しぶりです！");
	TO
	act[3].Mes("何でも新しい武器屋が出来るら・・・");
	TO
	act[0].Mes("帰れ");
	END
	}
	void EVE_SUB::トウツグと極月()
	{
	//極月家とトウツグと話
	//没
	START
	act[0].Set(EChara::セオ,6,10,DI::左);
	act[1].Set(EChara::トウツグ,6,10,DI::左);
	act[2].Set(EChara::シエホ,6,10,DI::左);
	act[3].Set(EChara::ファクト,6,10,DI::左);
	act[4].Set(EChara::ヘルメス,6,10,DI::左);
	BackChenge(EStage::会議室);
	END
	}
	//メインシナリオ 7
	void EVE_SUB::武器屋祭り開催()
	{
	//ハンター協会主催の武器屋祭りが開催
	START
	act[0].Set(EChara::スタイト,7.5,5,DI::下);
	act[1].Set(EChara::ハルファド,9,5,DI::下);

	act[2].Set(EChara::セオ,5,7,DI::上);
	act[3].Set(EChara::ルルファ,6,7, DI::上);
	act[4].Set(EChara::兵士,7,7, DI::上);
	act[5].Set(EChara::カノン,8,7, DI::上);
	act[6].Set(EChara::兵士,9,7, DI::上);
	act[7].Set(EChara::タクミ,11,7, DI::上);

	act[8].Set(EChara::トウツグ, 4, 8, DI::上);
	act[9].Set(EChara::兵士, 5, 8, DI::上);
	act[10].Set(EChara::ファイ, 7,8, DI::上);
	act[11].Set(EChara::メディ, 8, 8, DI::上);
	act[12].Set(EChara::パラコ, 9, 8, DI::上);
	act[13].Set(EChara::レンジ, 10, 8, DI::上);

	act[14].Set(EChara::兵士, 5, 9, DI::上);
	act[15].Set(EChara::語り部, 6, 9, DI::上);
	act[16].Set(EChara::ヘルメス, 7, 9, DI::上);
	act[17].Set(EChara::兵士, 9, 9, DI::上);
	act[18].Set(EChara::ファクト, 10, 9, DI::上);
	act[19].Set(EChara::兵士, 11, 9, DI::上);

	act[20].Set(EChara::兵士, 4, 10, DI::上);
	act[21].Set(EChara::ジンイチ, 5, 10, DI::上);
	act[22].Set(EChara::ケンヒメ, 6, 10, DI::上);
	act[23].Set(EChara::兵士, 8, 10, DI::上);
	act[24].Set(EChara::兵士, 9, 10, DI::上);
	act[25].Set(EChara::ブロン, 10, 10, DI::上);

	BackChenge(EStage::広場);
	TO
	act[0].Mes("我々が入植を開始した頃、フロンティアには何も無かった");
	TO
	act[0].Mes("物資も無かった、魔獣に対する備えも無かった・・・");
	TO
	act[0].E思考();
	TO
	act[0].Mes("それから町は少しずつ大きくなり、２年目に鉱山開拓が始まり・・・");
	TO
	act[0].E思考();
	TO
	act[0].Mes("そして、今年＠魔獣を狩るため多くのハンターがやってきた・・・");
	TO
	act[0].E思考();
	TO
	act[0].Mes("それでは、第５回フロンティア開拓祭りの開催を宣言する！");
	TO
	for (int i = 2; i < 25; i++)
	{
	act[i].E驚き();
	}
	END
	}
	void EVE_SUB::つるはし祭り布告()
	{
	//武器屋祭りの盛況を受けて、政府もつるはし祭りをする事に
	//没
	START
	act[0].Set(EChara::セオ,6,10,DI::左);
	act[1].Set(EChara::スタイト,6,10,DI::左);
	BackChenge(EStage::店内);
	END
	}
	//メインシナリオ 8
	void EVE_SUB::ドラゴンの瞳()
	{
	//中央のオークションでドラゴンの瞳が凄い値段で売れる。
	//ハンターの増加が見込まれる
	START
	act[0].Set(EChara::セオ,8,4,DI::左);
	act[1].Set(EChara::ファクト, 7, 4, DI::右,false);
	BackChenge(EStage::店内);
	TO
	act[0].Mes("例のニュース聞いたか？");
	TO
	act[1].Mes("例のニュースって？");
	TO
	act[0].Mes("なんでも金持ちがオークションで竜の瞳を落札したそうだ");
	TO
	act[0].Mes("１０億で");
	TO
	act[1].E驚き();
	TO
	act[1].Mes("１０億！？");
	TO
	act[1].E疑問();
	TO
	act[1].Mes("でも、セオが言ってたのって竜鱗じゃなかったっけ？");
	TO
	act[0].E思考();
	TO
	act[0].Mes("多分、シロさんから預かってるのがそれだろう");
	TO
	act[0].Mes("俺にもよく分からんが＠オークションに出たのは偽物かもな");
	TO
	act[0].Mes("ドラゴンの目撃情報も増えているし＠これからハンターが増えるはず");
	TO
	act[0].Mes("客が増えて、求められる武器の質も上がるのは確かだろうな");
	TO
	act[1].Mes("そうだね、武器の開発頑張るよ");
	TO
	act[0].Mes("ああ");
	END
	}
	//メインシナリオ 9
	void EVE_SUB::つるはし祭り開催()
	{
	//つるはし祭りが開催
	//没
	START
	act[0].Set(EChara::スタイト,6,10,DI::左);
	act[1].Set(EChara::セオ,6,10,DI::左);
	act[2].Set(EChara::タクミ,6,10,DI::左);
	act[3].Set(EChara::ブロン,6,10,DI::左);
	act[4].Set(EChara::ヒトフリサイ,6,10,DI::左);
	BackChenge(EStage::広場);
	END
	}
	//メインシナリオ 10
	void EVE_SUB::開拓状況()
	{
	//開拓状況についての雑談
	START
	act[0].Set(EChara::セオ, 7, 4, DI::下);
	act[1].Set(EChara::ルルファ, 10, 7, DI::右);
	act[2].Set(EChara::スタイト, 7, 11, DI::左, false);
	act[3].Set(EChara::兵士, 7, 6, DI::上);
	act[4].Set(EChara::兵士, 11, 7, DI::左);
	BackChenge(EStage::店内);
	TO
	act[3].E音符();
	TO
	act[0].Mes("ありがとうございました");
	act[3].Move(0, 6, 4);
	TO
	act[2].Move(0, -5, 4);
	TO
	act[0].Mes("いらっしゃいませ");
	TO
	act[2].Mes("久しぶりだな");
	TO
	act[2].Mes("やはりドラゴンの件でハンターが増えてな");
	TO
	act[0].Mes("はい、大忙しですよ");
	TO
	act[2].Mes("開拓の方も大分進んだし、移民者が増えるのもありがたい");
	TO
	act[2].Mes("しかしこれだけ開拓が進んでも、ドラゴンに遭遇したハンターはいないらしい");
	TO
	act[2].Mes("本当にドラゴンはいるのかと思うんだが・・・");
	TO
	act[0].Mes("いると思いますよ");
	TO
	act[2].Mes("なぜそう思う？");
	TO
	act[0].Mes("目撃例は結構ありますし、いるんじゃないかと");
	TO
	act[2].Mes("へぇ");
	TO
	act[2].E思考();
	TO
	act[2].Mes("邪魔したね、忙しいのでそれじゃまた");
	TO
	act[2].Move(0, 5, 4);
	TO
	act[0].E疑問();
	TO
	act[0].Mes("何の用だったんだ？");
	END
	}
	//メインシナリオ 11
	void EVE_SUB::ゴランノスの噂()
	{
	//ゴランノスが出店するとの噂
	START
	act[0].Set(EChara::セオ, 7, 4, DI::下);
	act[1].Set(EChara::ルルファ, 2, 2, DI::右);
	BackChenge(EStage::店内);
	TO
	act[1].Move(0, 2);
	TO
	act[1].Move(4, 0);
	TO
	act[1].Mes("おはようございます");
	TO
	act[0].Mes("おはよう");
	TO
	act[1].Mes("そういえば聞きました？＠また武器屋が出来るらしいですね");
	TO
	act[1].Mes("結構大きな会社らしいですね、確か・・・");
	TO
	act[0].Mes("ゴランノス・ウェポンズ");
	TO
	act[1].Mes("そうです、それです！");
	TO
	act[1].Mes("やっぱりご存知でしたか");
	TO
	act[0].Mes("前の勤務先だしな");
	TO
	act[1].E驚き();
	TO
	act[1].Mes("えっ、そうなんですか！");
	TO
	act[0].Mes("あぁ");
	TO
	act[1].Mes("どんな所でした？");
	TO
	act[0].Mes("最低の武器屋だったな");
	TO
	act[1].Mes("そ、そうですか・・・");
	TO
	act[0].Left();
	act[0].Mes("大きい会社だが魔獣狩り向けの武器を作ってるわけじゃないし＠ノウハウがあるとも思えない");
	TO
	act[0].Mes("気にする必要もないね");
	TO
	act[0].E思考();
	TO
	act[0].E音符();
	TO
	act[0].Mes("そういう事だ、今日も１日よろしく");
	TO
	act[1].Mes("はい！");
	END
	}
	//メインシナリオ 12
	void EVE_SUB::ゴランノス出店()
	{
	//ゴランノス・ウェポンズが出店
	//やはり来訪

	//ホワイトナイトが開店＆来訪
	START
	act[0].Set(EChara::セオ, 7, 4, DI::下);
	act[1].Set(EChara::ファクト, 2, 2, DI::下);
	BackChenge(EStage::店内);
	TO
	act[1].Move(0, 2);
	TO
	act[1].Move(4, 0);
	TO
	act[1].Right();
	act[1].Mes("おはようセオ");
	TO
	act[0].Left();
	act[0].Mes("ああ、おはよう");
	TO
	act[1].Mes("いよいよ明日らしいけど");
	TO
	act[0].Mes("ああ");
	TO
	act[1].Mes("来るかな？");
	TO
	act[0].Mes("どうだろうな");
	TO
	act[0].Down();
	act[1].Down();
	act[2].Set(EChara::カクシャ, 6.5, 11, DI::下,false);
	TO
	act[2].Move(0, -5);
	TO
	act[2].Mes("元ゴランノスの従業員が作った武器屋と聞いて、誰かと思えば");
	TO
	act[0].E思考();
	TO
	act[0].Mes("久しぶりだな");
	TO
	act[2].Mes("ああ、１年ぶりくらいかな");
	TO
	act[0].Mes("何の用だ？");
	TO
	act[2].E音符();
	TO
	act[2].Mes("潰す前に、どんな店か見ておこうかと思ってね");
	TO
	act[0].Mes("潰れるのはあんたらの店だよ");
	TO
	act[2].Mes("強がっていられるのも今のうちだ");
	TO
	act[0].E思考();
	act[1].E思考();
	act[2].E思考();
	act[3].Set(EChara::カノン, 6.5, 11, DI::下);
	TO
	act[3].Move(0,-3);
	TO
	act[3].E思考();
	TO
	act[3].Move(0, 3);
	TO
	act[2].Mes("じゃあな、せいぜい頑張れよ");
	TO
	act[2].Move(0,5);
	END
	}
	void EVE_SUB::ルルファ兄失踪()
	{
	//ルルファの兄が失踪、ドラゴンとの遭遇
	//一年目、前篇が終了
	START
	act[0].Set(EChara::セオ, 7, 6, DI::下);
	act[1].Set(EChara::ファクト,6,8,DI::上);
	act[2].Set(EChara::ヘルメス,7,8,DI::上);
	act[3].Set(EChara::トウツグ,8,8,DI::上);
	act[4].Set(EChara::ルルファ,7,11,DI::上);
	BackChenge(EStage::店内);
	TO
	act[0].Mes("おはようございます");
	TO
	act[1].Mes("おはようございます");
	act[2].Mes("おはようございます");
	act[3].Mes("おはようございます");
	TO
	act[0].Mes("今日は大ニュースがあります");
	TO
	act[0].Mes("昨日、竜が発見されたらしい");
	TO
	act[1].E驚き();
	act[2].E驚き();
	act[3].E驚き();
	TO
	act[0].Mes("とは言っても、竜が狩られたわけではない");
	TO
	act[0].Mes("竜の鱗が硬くて、殆どダメージも与えられなかったとか");
	TO
	act[0].Mes("遭遇したハンターのパーティーは結構被害が出たらしい");
	TO
	act[0].Mes("竜を恐れてハンターが減るか、存在が確認されて増えるかは分からない");
	TO
	act[0].Mes("だが、より強力な武器が求められるのは確実だろう");
	TO
	act[0].Mes("開発の方はより一層頑張って欲しい");
	TO
	act[0].Mes("それでは今日も１日よろしくおねがいします");
	TO
	act[1].Mes("よろしくおねがいします");
	act[2].Mes("よろしくおねがいします");
	act[3].Mes("よろしくおねがいします");
	TO
	act[0].E思考();
	TO
	act[0].E疑問();
	TO
	act[0].Mes("そういえばルルファさんは？");
	TO
	act[1].Mes("今日は休みじゃないから、遅刻かな");
	TO
	act[3].Mes("珍しいですね");
	TO
	act[4].Move(0,-2,2);
	TO
	act[0].Mes("おはよう");
	act[1].Down();
	act[2].Down();
	act[3].Down();
	TO
	act[0].E疑問();
	TO
	act[0].Mes("どうした");
	TO
	act[0].E驚き();
	act[1].E驚き();
	act[2].E驚き();
	act[3].E驚き();
	TO
	act[4].Mes("兄さんが・・・");
	TO
	act[4].E思考();
	TO
	act[4].Mes("ドラゴンに襲われて・・・");
	TO
	act[0].Mes("まさか・・・");
	END
	}
	*/