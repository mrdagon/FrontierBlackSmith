//Copyright © 2015 (´･@･)
//[License]GNU Affero General Public License, version 3
//[Contact]http://tacoika.blog87.fc2.com/
#include "eve_sub.h"

#define NEXT break;case
#define START int L=0;if(GetLine() == 0){
#define TO	  }L++;if(GetLine()==L){
#define END   TO SetEnd();}

extern ACTER* act[35];

extern ACTER セオ;//FBS関係
extern ACTER ルルファ;
extern ACTER ファクト;
extern ACTER トウツグ;
extern ACTER ヘルメス;

extern ACTER カノン;//カノン工房関係

extern ACTER ヒトフリサイ;//極月関係
extern ACTER ジンイチ;
extern ACTER ケンヒメ;

extern ACTER リークオ;//ゴランノス関連
extern ACTER ポンサー;
extern ACTER カクシャ;

extern ACTER シロ;//ハンター

extern ACTER ニット;//ルルファ兄
extern ACTER レイブル;

extern ACTER サンダー;//がらの悪いハンター二人組み
extern ACTER ファイア;

extern ACTER ファイタ;//新米ハンター達
extern ACTER メディ;
extern ACTER パラコ;
extern ACTER レンジ;

extern ACTER プロフェッサー;//協会会長
extern ACTER ジョッシュ;
extern ACTER メイコ;

extern ACTER 語り部;

extern ACTER スタイト;//副総督
extern ACTER ハルファド;//総督

extern ACTER 記者;

extern ACTER 兵士A;
extern ACTER 兵士B;
extern ACTER 兵士C;
extern ACTER 兵士D;

extern ACTER 受付;
extern ACTER 店員;
extern ACTER 司会;


extern int GetLine();
extern void SetEnd();
extern int BackChenge(EStage esta , int T=1);

void EVE_SUB::Switch(int E)
{
	switch(E)
	{
		//0~19 各モードイントロ
		case  0:導入_シナリオ();break;
		case  1:導入_自由経済();break;
		case  2:導入_メダルの王();;break;
		case  3:導入_拝金主義();;break;
		case  4:導入_千客万来();;break;
		case  5:導入_株を育てて();;break;
		case  6:導入_シェアNo1();;break;
		case  7:導入_つるはし大好き();break;
		case  8:導入_開拓最前線();break;
		case  9:導入_無双の斧();break;
		case 10:導入_究極の槍();break;
		case 11:導入_至高の剣();break;
		case 12:導入_完璧の弓();break;
		case 13:導入_ウェポンマイスター();break;
		case 14:導入_アイスエイジ();break;
		case 15:導入_閃き道場();break;
		case 16:導入_大ハンター時代();break;
		case 17:導入_時代の終わり();break;
		case 18:;break;
		case 19:;break;
		case 20:;break;
		//祭りイベント
		//case 21:武器屋祭り();break;//没
		//case 22:武器屋祭り();break;//武器屋祭り
		//シナリオモードイベント
	
		//1年目1月
		case 23:開店();break;//1日
		case 24:つるはし製造開始();break;//4日
		case 25:営業許可A();break;//8日
		case 26:営業許可B();break;//9日
		case 27:新聞取材();break;//没イベント
		case 28:調査狩猟();break;//13日
		case 29:最強のハンター(); break;//20日
		case 30:人材募集開始();break;//26日
		case 31:トウツグ採用();break;//27日
		case 32:ルルファ採用();break;//28日

		//1年目2月
		case 34:経営二ヶ月目(); break;//1日
		case 33:つるはし納品(); break;//3日
		case 35:経営のススメ();break;//10日
		case 37:工事のススメ();break;//22日
		case 38:魔獣の資源();break;//17日
		//case 39:新聞取材2();break;//没

		//1年目3月
		case 40:経営三ヶ月目();break;//1日
		case 36:スタイト視察(); break;//2日
		case 41:ルルファの兄(); break;//7日
		//case 42:シエホ採用(); break;//没
		//case 43:財務のススメ();break;//没
		case 44:教授投資家();break;//12日
		case 45:ヘルメス採用();break;//17日
		case 46:開発のススメ();break;//19日
		case 47:カノン工房();break;//23日
		case 48:昇給要求();break;//28日

		//1年目4月
		//case 49:ハンター協会();break;//没
		case 50:宣伝のススメ();break;//12日
		//case 51:がらの悪い三人衆();break;//没

		//1年目5月
		case 52:ホワイトナイト(); break;//1日
		//case 53:四人組のハンター();break;//没

		//1年目6月
		case 54:武器屋祭り布告();break;//1日
		case 55:調査続行();break;//12日

		//1年目7月
		case 56:極月鍛冶();break;//1日
		//case 57:トウツグと極月();break;//没
		case 58:武器屋祭り開催();break;//14日
		//case 59:つるはし祭り布告();break;//没

		//1年目8月
		case 60:ドラゴンの瞳();break;//3日

		//メインシナリオ 9
		//case 61:つるはし祭り開催();break;//没
		case 62:開拓状況();break;//8日
		case 63:ゴランノスの噂(); break;//14日
		//1年目9月
		case 64:ゴランノス出店();break;//1日
		case 65:ルルファ兄失踪();break;//28日
		default:
			SetEnd();
		break;

		case 21:1_1_1(); break;
		case 22:1_1_2(); break;
		case 23:1_1_3(); break;
		case 24:1_1_4(); break;
		case 25:1_1_5(); break;
		case 26:1_1_6(); break;
		case 27:1_1_7(); break;
		case 28:1_1_8(); break;
		case 29:1_1_9(); break;
		case 30:1_1_10(); break;
		case 31:1_1_11(); break;
		case 32:1_2_1(); break;
		case 33:1_2_2(); break;
		case 34:1_2_3(); break;
		case 35:1_2_4(); break;
		case 36:1_2_5(); break;
		case 37:1_3_1(); break;
		case 38:1_3_2(); break;
		case 39:1_3_3(); break;
		case 40:1_3_4(); break;
		case 41:1_4_1(); break;
		case 42:1_4_2(); break;
		case 43:1_4_3(); break;
		case 44:1_4_4(); break;
		case 45:1_4_5(); break;
		case 46:1_5_1(); break;
		case 47:1_5_2(); break;
		case 48:1_5_3(); break;
		case 49:1_5_4(); break;
		case 50:1_6_1(); break;
		case 51:1_6_2(); break;
		case 52:1_6_3(); break;
		case 53:1_6_4(); break;
		case 54:1_7_1(); break;
		case 55:1_7_2(); break;
		case 56:1_7_3(); break;
		case 57:1_7_4(); break;
		case 58:1_8_1(); break;
		case 59:1_8_2(); break;
		case 60:1_8_3(); break;
		case 61:1_8_4(); break;
		case 62:1_9_1(); break;
		case 63:1_9_2(); break;
		case 64:1_9_3(); break;
		case 65:1_9_4(); break;
		case 66:1_10_1(); break;
		case 67:1_10_2(); break;
		case 68:1_10_3(); break;
		case 69:1_10_4(); break;
		case 70:1_11_1(); break;
		case 71:1_11_2(); break;
		case 72:1_11_3(); break;
		case 73:1_11_4(); break;
		case 74:1_12_1(); break;
		case 75:1_12_2(); break;
		case 76:1_12_3(); break;
		case 77:1_12_4(); break;
		case 78:1_1_1(); break;
		case 79:1_1_2(); break;
		case 80:1_1_3(); break;
		case 81:1_1_4(); break;
		case 82:1_2_1(); break;
		case 83:1_2_2(); break;
		case 84:1_2_3(); break;
		case 85:1_2_4(); break;
		case 86:1_3_1(); break;
		case 87:1_3_2(); break;
		case 88:1_3_3(); break;
		case 89:1_3_4(); break;
		case 90:1_4_1(); break;
		case 91:1_4_2(); break;
		case 92:1_4_3(); break;
		case 93:1_4_4(); break;
		case 94:1_5_1(); break;
		case 95:1_5_2(); break;
		case 96:1_5_3(); break;
		case 97:1_5_4(); break;
		case 98:1_6_1(); break;
		case 99:1_6_2(); break;
		case 100:1_6_3(); break;
		case 101:1_6_4(); break;
		case 102:1_7_1(); break;
		case 103:1_7_2(); break;
		case 104:1_7_3(); break;
		case 105:1_7_4(); break;
		case 106:1_8_1(); break;
		case 107:1_8_2(); break;
		case 108:1_8_3(); break;
		case 109:1_8_4(); break;
		case 110:1_9_1(); break;
		case 111:1_9_2(); break;
		case 112:1_9_3(); break;
		case 113:1_9_4(); break;
		case 114:1_10_1(); break;
		case 115:1_10_2(); break;
		case 116:1_10_3(); break;
		case 117:1_10_4(); break;
		case 118:1_11_1(); break;
		case 119:1_11_2(); break;
		case 120:1_11_3(); break;
		case 121:1_11_4(); break;
		case 122:1_12_1(); break;
		case 123:1_12_2(); break;
		case 124:1_12_3(); break;
		case 125:1_12_4(); break;
	}
}

void EVE_SUB::導入_シナリオ()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			BackChenge(EStage::酒場);
			act[0].Move(0,-6,2);
	TO
			act[0].Move(0.5,0,2);
	TO
			act[0].Mes("Hello world!");
			act[0].Direct(DI::下);
	TO
			act[0].Emo(EM::思考);
	TO
			act[0].Emo(EM::疑問);
	TO
			act[0].Mes("ようこそ、世界へ!");
	TO
			act[0].Emo(EM::音符);
	TO
			act[0].Mes("冥王と聖王の死により、血で血を洗った戦乱の時代は幕を閉じる");
	TO
			act[0].Mes("王の死後、民の中より再び王が現れる");
	TO
			act[0].Mes("王は戦の法は知らなかったが、民を操る術に長ける");
	TO
			act[0].Mes("法は変化し、武が力であった時代は終え平和が訪れる");
	TO
			act[0].Mes("かつて、戦う力無き民は奴隷であった");
	TO
			act[0].Mes("そして、富み無き民はこの時代においても奴隷となる");
	TO
			act[0].Emo(EM::思考);
	TO
			act[0].Mes("物語の舞台は大陸東部フロンティア");
	TO
			act[0].Mes("南部及び西部を支配下に収めた政府は東部開拓に着手する");
	TO
			act[0].Mes("しかし開拓は一年目にして頓挫する");
	TO
			act[0].Mes("手付かずであった東部地方は独自の生態系を有しており＠他の地域には見られない魔獣が存在していた");
	TO
			act[0].Mes("魔獣は自らのテリトリーを犯す人間を喰らい、町を襲った");
	TO
			act[0].Mes("多くの開拓者が犠牲になりながらも、開拓は遅々として進まず＠時間だけが過ぎていく");
	TO
			act[0].Mes("しかし、ある者により魔獣を資源として活用する方法を発見される");
	TO
			act[0].Mes("さらに、中央地方では魔獣の毛皮や角、牙、剥製等の収集が流行りだす");
	TO
			act[0].Mes("恐ろしい魔獣の牙は金と同等、煌く竜の瞳は宝石以上の価値を持つ");			
	TO
			act[0].Mes("人々は大金を得るため、武器を手に東部フロンティアへ旅立つ");
	TO
			act[0].Mes("人は命知らずの彼らをハンターと呼んだ");
	TO
			act[0].Mes("物語は魔獣狩猟の流行が始まる少し前から始まる");
	TO
			act[0].Mes("主人公は一攫千金を夢に東部地方へやってきた一人の人物");
	TO
			act[0].Mes("ハンターでは無く");
	TO
			act[0].Mes("武器屋であった");
	END
}
void EVE_SUB::導入_自由経済()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_メダルの王()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_拝金主義()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_千客万来()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_株を育てて()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_シェアNo1()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_つるはし大好き()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_開拓最前線()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_無双の斧()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_究極の槍()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_至高の剣()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_完璧の弓()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_ウェポンマイスター()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_アイスエイジ()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_閃き道場()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_大ハンター時代()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::導入_時代の終わり()
{
	START
			act[0].Set(EChara::語り部,6,10,DI::左);
			act[0].Move(0,-6,2);
			BackChenge(EStage::酒場);
	END
}
void EVE_SUB::つるはし祭り()
{
	static int point[5];//各店の得点
	//年１回
	//没
	START
		act[0].Set(EChara::司会,6,10,DI::左);
		BackChenge(EStage::広場);
	END
}
void EVE_SUB::武器屋祭り()
{
	//年１回
	START
		act[0].Set(EChara::司会,8,5,DI::下);

		act[3].Set(EChara::ルルファ, 6, 7, DI::上);
		act[4].Set(EChara::兵士, 7, 7, DI::上);

		act[6].Set(EChara::兵士, 9, 7, DI::上);
		act[7].Set(EChara::タクミ, 11, 7, DI::上);

		act[8].Set(EChara::トウツグ, 4, 8, DI::上);
		act[9].Set(EChara::兵士, 5, 8, DI::上);
		act[10].Set(EChara::ファイ, 7, 8, DI::上);
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

		BackChenge(EStage::広場);
	TO
		act[0].Mes("それでは武器屋コンテスト結果発表です！");
	TO
		act[0].Mes("審査員と一般投票による集計の結果＠数ある武器屋の中から栄冠に輝くのは一体！");
	TO
		act[0].Mes("栄えある優勝店は・・・");
	TO
		act[0].E思考();
	TO
		switch (EVE_SUB::Contest())
		{
		case 0:
			act[0].Mes("フロンティアスミスです！");
			act[1].Set(EChara::セオ, -1, 5, DI::右);
			break;
		case 1:
			act[0].Mes("カノン工房です！");
			act[1].Set(EChara::カノン, -1, 5, DI::右);
			break;
		case 2:
			act[0].Mes("ホワイトナイトです！");
			act[1].Set(EChara::ブロン, -1, 5, DI::右);
			break;
		case 3:
			act[0].Mes("極月刀鍛冶です！");
			act[1].Set(EChara::ヒトフリサイ, -1, 5, DI::右);
			break;
		case 4:
			act[0].Mes("ゴランノス・ウェポンズです！");
			act[1].Set(EChara::カクシャ, -1, 5, DI::右);
			break;
		}
		act[0].Left();
		act[1].Move(8,0);
	TO
		act[0].Down();
		act[1].Down();
		act[0].Mes("優勝おめでとう！");
	TO
		act[1].E音符();
	TO
		act[1].Mes("ありがとう！");
	TO
		act[0].Mes("ではまた次回のコンテストで会おう！");
	END
}
//メインシナリオ 1
void EVE_SUB::開店()
{
	//中央からフロンティアに移民してきた、セオとファクト。
	//カノン工房の人に工事して貰いました
	//ちょっとした掛け合い後、ゲーム開始
	START
		act[0].Set(EChara::セオ,-1,8,DI::左 , false);		
		act[1].Set(EChara::ファクト,7,7,DI::下 , true);
		act[2].Set(EChara::タクミ,8,7,DI::下 , true);			
		BackChenge(EStage::店外);
	TO
		act[0].Move(9,0,3);
	TO
		act[2].Mes("おはよう、社長さん");
		act[0].Direct(DI::上);
	TO
		act[0].Mes("これが俺の店か");
	TO
		act[2].Mes("どうだい気に入ったかい？");
	TO
		act[0].Emo(EM::思考);
	TO
		act[1].Emo(EM::怒り);
	TO
		act[1].Mes("予算が無いんだ、ショボイのは仕方ないだろ！");
	TO
		act[1].Mes("それでも足りない分は僕が工事を手伝ったんだよ！");
	TO
		act[0].Emo(EM::呆れ);
	TO
		act[0].Mes("何も言ってないんだが・・・");
	TO
		act[1].Mes("");
		act[0].Emo(EM::思考);
	TO
		act[0].Mes("まぁ、確かにショボイかもしれんが＠これから稼いで建て替えりゃいい");
	TO
		act[0].Mes("その時はまた頼むよ、親方");
	TO
		act[2].Emo(EM::音符);
	TO
		act[2].Mes("今度は現金払いで頼むよ");
	TO
		act[0].Emo(EM::音符);
		act[1].Emo(EM::呆れ);
	END
}
void EVE_SUB::つるはし製造開始()
{
	//店を建てたが、そもそも営業許可が出ていない
	//役所に許可を取りに行った際に、ついでにつるはし製造の仕事も受注する事に
	START
		act[0].Set(EChara::セオ,2,2,DI::下);
		act[1].Set(EChara::ファクト,7,4,DI::下,false);
		BackChenge(EStage::店内);
	TO
		act[0].Move(0, 2, 4);
	TO
		act[0].Move(4, 0, 4);
	TO
		act[0].Mes("戻ったぞ、店番ご苦労");
	TO
		act[0].Mes("");
		act[1].E眠り();
	TO
		act[1].E思考();
	TO
		act[1].Mes("ふぁ～あ・・・");
	TO
		act[1].Direct(DI::左);
		act[1].Mes("おかえり");
	TO
		act[1].Mes("ところで何の用事だったの？");
	TO
		act[0].Mes("役所に営業許可を申請してきた");
	TO
		act[0].Mes("武器を売るとなると、審査やら登録やらがあるからな");
	TO
		act[1].Mes("と言う事はまだ営業してなかったのか");
	TO
		act[1].Mes("店番する必要あったの？");
	TO
		act[0].E思考();
		act[1].E思考();
	TO
		act[0].Mes("それはそれとして明後日、担当者が視察に来るそうだ");
	TO
		act[0].Mes("あと、明日からつるはしを作ってくれ");
	TO
		act[1].Mes("つるはし？");
	TO
		act[0].Mes("鉱山を掘るのに使うアレだ");
	TO
		act[1].Mes("それは知ってるよ＠武器を売るんじゃ？");
	TO
		act[0].E思考();
	TO
		act[0].Mes("武器だけ売るよりつるはしも売った方が儲かるからな");
	TO
		act[0].Mes("竜の件でハンターが増えるのも、もう少し先だ＠それまでに店が潰れちゃ困る");
	TO
		act[1].Mes("そもそもその噂って本当なの？");
	TO
		act[1].Mes("");
		act[0].E音符();
	TO
		act[0].Mes("俺が言うことに間違いは無い！");
	TO
		act[1].Direct(DI::下);
		act[1].Mes("まぁ、今更言っても仕方無いか・・・");
	TO
		act[0].Mes("じゃあ、つるはし製造まかせたぞ");
	END
}
void EVE_SUB::営業許可A()
{
	//役所からの視察に来たハルファド
	//お菓子を渡す事に
	START
		act[0].Set(EChara::セオ,8, 6, DI::下);
		act[1].Set(EChara::ハルファド, 7.5, 11, DI::下 );
		act[1].HukiUp(false);
		act[2].Set(EChara::兵士,6.5, 12, DI::下);
		act[3].Set(EChara::兵士, 8.5, 12, DI::下);
		act[4].Set(EChara::ファクト, 7, 6, DI::下);
		BackChenge(EStage::店内);
	TO
		act[1].Move(0, -4, 2);
		act[2].Move(0, -4, 2);
		act[3].Move(0, -4, 2);
	TO
		act[1].Mes("おはよう");
	TO
		act[0].Mes("おはようございます！");
	TO
		act[1].Mes("副領事のハルファドだ、よろしく。");
	TO
		act[1].Left();
		act[1].Mes("君が武器屋を始めたいって人？");
		act[0].Mes("");
		act[4].Mes("");
	TO
		act[0].Mes("私が社長のセオです！");
	TO
		act[1].Up();
		act[1].E思考();
	TO
		act[0].Mes("どうかしましたか？");
	TO
		act[1].Mes("へぇ君が・・・？");
	TO
		act[1].Mes("まぁいいか＠早速審査を始めようかね、工房はどこかね？");
	TO
		act[0].Mes("こちらです");
	TO
		act[0].Move(-1, 0, 4);
		act[4].Move(-1, 0, 4);
	TO
		act[0].Move(-1, 0, 4);
		act[1].Move(-1, 0, 4);
		act[4].Move(-1, 0, 4);
	TO
		act[0].Set(EChara::セオ, 8, 6, DI::下);
		act[1].Set(EChara::ハルファド, 7.5, 7, DI::上);
		act[1].HukiUp(false);
		act[2].Set(EChara::兵士, 6.5, 8, DI::上);
		act[3].Set(EChara::兵士, 8.5, 8, DI::上);
		act[4].Set(EChara::ファクト, 7, 6, DI::下);
		BackChenge(EStage::店内);
	TO
		act[1].Mes("これで視察は終わりかな");
	TO
		act[0].Mes("ありがとうございました。");
	TO
		act[1].Mes("大体問題無さそうではある");
	TO
		act[1].Mes("しかし、武器屋の認可は慎重にする必要があるからして");
	TO
		act[1].Right();
		act[1].Mes("あーっ・・・");
	TO
		act[1].Mes("なんだか、お菓子でも食べたくなってきたなぁ・・・");
	TO
		act[0].Mes("お菓子ですか？");
	TO
		act[1].Mes("いや～、こう見えて甘い物には目が無くてねぇ・・・？");
	TO
		act[0].E思考();
		act[1].E思考();
	TO
		act[0].Mes("少々お待ちを");
	TO
		act[0].Move(10, 0, 4);
	TO
		act[0].Move(-10, 0, 4);
	TO
		act[0].Down();
		act[0].Mes("心ばかりですが、よかったらこれを");
	TO
		act[1].Up();
		act[1].Mes("ん、これは何かな？");
	TO
		act[0].Mes("お茶菓子です、よかったら皆さんで");
	TO
		act[1].Mes("そういうのを貰うのはちょっとまずいんだがな・・・");
	TO
		act[0].Mes("そう言わず");
	TO
		act[1].Mes("そうだな、有難く頂戴しよう");
	TO
		act[1].Mes("視察の結果は問題なし＠明日から営業を許可しよう");
	TO
		act[0].E音符();
	TO
		act[0].Mes("ありがとうございます！");
	TO
		act[1].Direct(DI::下);;
		act[1].Mes("よし、今日は帰るぞ");
	TO
		act[1].Move(0, 2, 2);
	TO
		act[1].Move(0, 5, 2);
		act[2].Move(0, 5, 2);
		act[3].Move(0, 5, 2);
	END
}
void EVE_SUB::営業許可B()
{
	//賄賂を貰えず、怒り心頭なハルファドが乗り込んできた
	//逮捕されそうになるが、役所トップの人に助けて貰った

	START
		act[0].Set(EChara::セオ,7,3,DI::左);
		act[1].Set(EChara::ハルファド,7,11,DI::左);
		act[2].Set(EChara::兵士,6,12,DI::左);
		act[3].Set(EChara::兵士,8,12,DI::左);
		BackChenge(EStage::店内);
	TO
		act[1].Move(0, -5, 2);
		act[2].Move(0, -5, 2);
		act[3].Move(0, -5, 2);
	TO
		act[1].Mes("おい！");
		act[1].HukiUp(false);
	TO
		act[0].Down();
		act[0].Move(0, 1, 2);
	TO
		act[0].Mes("いらっしゃいませ♪＠お客様本日はどのような武器をお探しで？");
	TO
		act[0].Mes("ああ！ハルファド様＠お陰様で本日より営業を開始しております");
	TO
		act[4].Set(EChara::兵士,2, 2, DI::下);
		act[4].Move(0, 1, 2);
	TO
		act[5].Set(EChara::兵士, 2, 2, DI::下);
		act[5].Move(0, 1, 2);
		act[4].Move(0, 1, 2);
	TO
		act[4].Right();
		act[5].Right();
	TO
		act[0].Left();
	TO
		act[0].Down();
		act[0].Mes("なんですか、一体？");
	TO
		act[1].Mes("貴様に逮捕状が出ている");
	TO
		act[1].Mes("無許可での武器屋営業＠これは重大な犯罪行為だ");
	TO
		act[0].Mes("昨日許可するって言ったじゃないですか！？");
	TO
		act[1].Mes("嘘を付くな！＠どうせテロリストにでも武器を売っているんだろう！");
	TO
		act[1].Mes("さっさとこいつを連行しろ！");
	TO
		act[0].Left();
		act[0].Mes("っ・・・");
	TO
		act[0].Down();
		act[6].Set(EChara::スタイト,7, 11, DI::上);
		act[6].Move(0, -3, 2);
		act[6].Mes("なんだ、騒がしいな");
		act[6].huki_ud = 1;
	TO
		act[1].Down();
		act[1].Mes("領事！");
		act[1].huki_ud = 0;
		act[2].Down();
		act[3].Down();
	TO
		act[0].Mes("領事？");
		act[0].huki_ud = 0;
	TO
		act[6].Mes("兵士を引き連れてどこかに行ったと思ったら＠何をしているんだ？");
	TO
		act[0].huki_w = 0;
		act[1].Mes("無許可で武器を売っている犯罪者を逮捕しに来たんですよ。");
	TO
		act[6].Mes("そうなの？");
	TO
		act[1].huki_w = 0;
		act[0].Mes("昨日、この方に大丈夫と言われたんですが・・・");
	TO
		act[1].Up();
		act[1].Mes("貴様！嘘を付くな");
		act[0].huki_w = 0;
		act[1].huki_w = 0;
	TO
		act[1].Down();
		act[6].Mes("思い出した＠そういえば俺が申請を受理したんだ！");
		act[6].huki_ud = 1;
	TO
		act[6].Mes("そうだろ？");
		act[6].huki_ud = 1;
	TO
		act[0].Mes("そうだったんですか？");
	TO
		act[6].Mes("これで問題ないだろ？");
	TO
		act[0].huki_w = 0;
		act[1].Mes("問題無いわけ無いでしょう！");
	TO
		act[6].Mes("・・・");
	TO
		act[1].Up();
		act[1].Mes("ちっ、仕方無い＠覚えていろよ");
	TO
		act[0].Down();
		act[1].Mes("行くぞ");
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
		act[6].Mes("災難だったな");
		act[6].huki_ud = 1;
	TO
		act[6].Down();
		act[6].Mes("どうやら、あんたのクッキーが気に入らんかったらしい");
	TO
		act[6].Mes("しかし、賄賂に菓子を渡す奴がいるとは＠普通は札束を詰めるもんなんだが");
	TO
		act[0].E思考();
	TO
		act[6].Up();
		act[6].Mes("わざとか？");
	TO
		act[6].E音符();
	TO
		act[6].Mes("まぁ普通仕返しにここまでやるとは思わんか");
	TO
		act[0].Mes("ありがとうございます、助かりました");
	TO
		act[6].Up();
		act[6].Mes("はっは、例には及ばんよ＠監督責任って奴もあるからな");
	TO
		act[6].Mes("今日は営業許可証を渡しに来た＠ほい、これが営業許可証");
	TO
		act[6].Mes("と言いたい所だが、書類に不備があってな＠許可を出すことは出来ない");
	TO
		act[6].Left();
		act[6].Mes("あ～、なんだか急に菓子でも食べなくなってきた・・・");
	TO
		act[0].Mes("・・・");
	TO
		act[6].Up();
		act[6].Mes("冗談だよ、冗談");
	TO
		act[6].Mes("はいコレが営業許可証だ");
	TO
		act[0].Mes("ありがとうございます");
	TO
		act[6].Mes("しかし、このタイミングで武器屋を始めるとは・・・＠");
	TO
		act[6].E思考();
	TO
		act[6].Mes("まぁいいか");
	TO
		act[6].Mes("じゃあな");
	TO
		act[6].Move(0, 6, 2);
	TO
		act[0].Mes("助かった");
	END
}
void EVE_SUB::新聞取材()
{
	//暇そうな新聞記者が取材に来たので受けることに
	//なぜかノリノリのセオだが、記事は小さかったらしい
	//没
	START
		act[0].Set(EChara::セオ,6,4,DI::下);
		act[1].Set(EChara::マスコン,6,8,DI::上);
		BackChenge(EStage::会議室);
	END
}
void EVE_SUB::調査狩猟()
{
	//研究所で働いている二人組が買い物に、初めての客である
	//新聞記事の効果があったらしい

	START
		act[0].Set(EChara::セオ,7,4,DI::下);
		act[1].Set(EChara::ジョッシュ,6.5,11,DI::左);
		act[2].Set(EChara::メイコ,7.5,11,DI::左);
		act[1].HukiUp(false);
		act[2].HukiUp(false);
		BackChenge(EStage::店内);
	TO
		act[0].Mes("営業開始したは良いが、あまり客が来ないな・・・");
	TO
		act[0].Mes("宣伝が不足しているのか・・・単純に需要がないのか");
	TO
		act[0].E思考();
	TO
		act[0].E驚き();
	TO
		act[1].Move(0, -5,4);
		act[2].Move(0, -5,4);
	TO
		act[0].Mes("いらっしゃいませ");
	TO
		act[1].Mes("こんな所に武器屋が出来ていたんですね");
	TO
		act[2].Right();
		act[2].Mes("閑古鳥が鳴いてるみたいだけど＠物には期待出来るのかしら？");
	TO
		act[2].Up();
		act[0].Mes("当店の武器はどれも一級品です＠品質は保証しますよ！");
	TO
		act[1].Mes("剣を見せて頂けますか？");
	TO
		act[0].Mes("どうぞ");
	TO
		act[1].E思考();
	TO
		act[1].Mes("良さそうですね");
	TO
		act[2].Mes("なんかダサくない？＠まぁ博士が作った武器よりはましか");
	TO
		act[0].Mes("博士？");
	TO
		act[1].Mes("我々の雇い主です＠ここらの生態系を調査しているんですよ");
	TO
		act[0].Mes("へぇ～、そういう人がいるんですか");
	TO
		act[1].Mes("いい買い物が出来ました、それでは");
	TO
		act[0].Mes("ありがとうございました");
	TO
		act[1].Move(0, 5, 4);
		act[2].Move(0, 5, 4);
	END
}
void EVE_SUB::最強のハンター()
{
	//主人公のシロが来店。
	//ちょっと喋って、帰る。

	START
		act[0].Set(EChara::セオ, 7, 4, DI::下);
		act[1].Set(EChara::ファクト, -1, 4, DI::左);
		act[2].Set(EChara::シロ,7,11,DI::左);
		act[2].HukiUp(false);
		BackChenge(EStage::店内);
	TO
		act[1].Move(7, 0, 4);
	TO
		act[1].Mes("僕が作った武器の評判はどうだい？");
	TO
		act[0].Left();
		act[0].Mes("まずまずって所だな");
	TO
		act[1].Mes("君がそういうって事は、評判良いんだね");
	TO
		act[0].Mes("今は他の武器屋は無いし、余程ひどくない限り売れるしな");
	TO
		act[0].Mes("思ったよりか武器の需要はあるし＠当面の経営も問題なさそうだ");
	TO
		act[1].Mes("なら安心だね");
	TO
		act[1].E音符();
	TO
		act[0].Down();
		act[1].Down();
		act[2].Move(0, -5, 4);
	TO
		act[0].Mes("いらっしゃいませ");
	TO
		act[2].Mes("ここが噂の武器屋か");
	TO
		act[0].E音符();
	TO
		act[1].Mes("噂になってるんですか？");
	TO
		act[2].Mes("なんでも兵士に取り囲まれてたとか");
	TO
		act[1].E驚き();
	TO
		act[1].Right();
		act[1].Mes("えっ！？");
	TO
		act[0].Left();
		act[0].Mes("そういえば君には言ってなかったね");
	TO
		act[2].Mes("へぇ本当だったんだ、よく大丈夫だったね");
	TO
		act[1].Down();
		act[0].Down();
		act[0].Mes("ええまぁ、なんとか・・・");
	TO
		act[0].Mes("それで本日はどのような武器をお探しですか");
	TO
		act[2].Mes("剣が欲しいんだ、最高のね");
	TO
		act[0].Mes("それでしたら、こちらはいかがでしょうか？");
	TO
		act[2].E思考();
	TO
		act[2].Mes("これは駄目だ＠もっと切れ味があるのが欲しい");
	TO
		act[0].Mes("すいません、当店で扱っている剣はそれだけでして");
	TO
		act[1].Mes("僕の作った武器は駄目ですか？");
	TO
		act[2].Mes("ああ、竜狩りには使えない");
	TO
		act[0].E驚き();
		act[1].E驚き();
	TO
		act[0].Mes("ドラゴン！実在するんですか！？");
	TO
		act[2].Mes("誰も信用してくれなかったけどね＠君は信じるかい？");
	TO
		act[0].E思考();
	TO
		act[2].Mes("邪魔したね、それじゃ");
	TO
		act[2].Move(0, 1, 4);
	TO
		act[1].Mes("待って下さい！");
	TO
		act[2].Up();
		act[2].Mes("何かな？");
	TO
		act[1].Mes("また店に来てくだい！");
	TO
		act[1].Mes("僕が作ります、竜殺しの剣");
	TO
		act[2].E思考();
	TO
		act[2].Mes("期待しておこうかな");
	TO
		act[2].Move( 0 , 4 , 4);
	TO
		act[1].Mes("");
		act[0].E思考();
	END
}
void EVE_SUB::人材募集開始()
{
	//少しだけ武器が売れ始めたので、人を募集する事に
	START
		act[0].Set(EChara::セオ,7,4,DI::左);
		act[1].Set(EChara::ファクト,6,4,DI::右);
		BackChenge(EStage::店内);
	TO
		act[0].Mes("客が増えてきたが、仕事の方はどうだ？");
	TO
		act[1].Mes("お客さんが増えてきたのはいいけど＠つるはしまで僕一人で作るのは・・・");
	TO
		act[1].Mes("だから人を雇って欲しい＠それに時間が欲しい・・・");
	TO
		act[0].Mes("竜殺しの剣か？＠大体、時間があったとしてお前に作れるのか");
	TO
		act[1].Mes("それにあの人ドラゴンがいるって言ってたじゃないか＠本当ならお客さんは増えるんだろ");
	TO
		act[0].Mes("ドラゴンがいるって話、信じたのか？");
	TO
		act[1].Mes("僕は信じる");
	TO
		act[0].E思考();
	TO
		act[0].Mes("まぁ、俺も信じているわけだが");
	TO
		act[0].Mes("接客の方は俺一人でも回せる＠とりあえず張り紙でもして、職人を募集するか");
	TO
		act[1].Mes("良い人が来てくれるといいね");
	TO
		act[0].Mes("そうだな");
	TO
		act[1].Move(-7,0,4);
	TO
		act[0].E思考();
	END
}
void EVE_SUB::トウツグ採用()
{
	//張り紙を見て、やってきたトウツグを採用

	START
		act[0].Set(EChara::セオ,7,4,DI::下);
		act[1].Set(EChara::ファクト,-1,4,DI::左);
		act[2].Set(EChara::トウツグ,7,11,DI::左);
		act[2].HukiUp(false);
		BackChenge(EStage::店内);
	TO
		act[2].Move(0,-5,4);
	TO
		act[0].Mes("いらっしゃいませ＠どのような武器をお探しで？");
	TO
		act[2].Mes("武器を買いに来たんじゃないです");
	TO
		act[0].E疑問();
	TO
		act[2].Mes("その、表の張り紙の");
	TO
		act[0].Mes("職人募集の？");
	TO
		act[2].Mes("はい！");
	TO
		act[0].E思考();
	TO
		act[0].Left();
		act[0].Mes("おい、ファクト！");
	TO
		act[1].Move(7,0,4);
	TO
		act[1].Mes("今度は職人希望の人だよね？");
	TO
		act[0].Mes("ああ、表の張り紙を見たんだと＠どうだ？");
	TO
		act[1].Down();
		act[1].Mes("どうだって、言われても");
	TO
		act[0].Down();
		act[1].Mes("えっと、名前は？");
	TO
		act[2].Mes("トウツグです");
	TO
		act[1].Mes("トウツグ君はなんでうちで働こうと？");
	TO
		act[2].Mes("武器が作りたいからです");
	TO
		act[0].Mes("へぇ、例えばどんな？");
	TO
		act[2].Mes("竜を殺せるぐらい強い武器です");
	TO
		act[1].E驚き();
		act[0].E音符();
	TO
		act[0].Mes("面白いじゃないか");
	TO
		act[1].Mes("竜が本当にいると思ってるの？");
	TO
		act[2].Mes("いえ、そういうわけではないです");
	TO
		act[1].E思考();
	TO
		act[1].Mes("武器製造の経験はある？");
	TO
		act[2].Mes("はい！これ俺が作った斧です");
	TO
		act[1].E思考();
	TO
		act[0].Left();
		act[0].Mes("お前が作った奴より出来がいいんじゃないか");
	TO
		act[1].Mes("・・・");
	TO
		act[0].Mes("決まりだな");
	TO
		act[0].Down();
		act[0].Mes("よし採用！＠明日から来れるか？");
	TO
		act[2].Mes("大丈夫です！＠よろしくお願いします！");
	TO
		act[1].Mes("ああ、よろしくね");
	END
}
void EVE_SUB::ルルファ採用()
{
	//張り紙を読んで、やってきたルルファを即採用。
	START
		act[0].Set(EChara::セオ,7,4,DI::下);
		act[1].Set(EChara::ルルファ, 7, 11, DI::左);
		act[2].Set(EChara::ファクト, -1, 4, DI::左);
		act[1].HukiUp(false);
		BackChenge(EStage::店内);
	TO
		act[1].Move(0, -5, 4);
	TO
		act[0].Eハート();
	TO
		act[0].Mes("いらっしゃいませ！＠武器をお探しですかお嬢さん");
	TO
		act[1].Mes("いえ、表の求人を見て");
	TO
		act[0].E思考();
	TO
		act[0].Mes("人手不足で困っていたんです、採用！");
	TO
		act[1].E驚き();
	TO
		act[1].Mes("えっ！＠そんなに簡単に決めて良いんですか？");
	TO
		act[0].Mes("あなたのような方を待っていたんですよ");
	TO
		act[1].Mes("でも・・・");
	TO
		act[1].E思考();
	TO
		act[1].Mes("ありがとうございます");
	TO
		act[0].E思考();
	TO
		act[0].E驚き();
	TO
		act[0].Mes("失礼、自己紹介が遅れましたね＠社長のセオです");
	TO
		act[1].Mes("ルルファです、よろしくお願いします。");
	TO
		act[0].Mes("ルルファさんか＠名前まで美しい");
	TO
		act[0].Left();
		act[0].Mes("ファクト君！");
	TO
		act[2].Move(7,0,4);
	TO
		act[2].Mes("何だよ気持ち悪いな？");
	TO
		act[0].Down();
		act[0].Mes("早速、人が来てくれたぞ＠ルルファさんだ");
	TO
		act[2].Down();
		act[2].E思考();
	TO
		act[2].Mes("女の子じゃないか？＠大丈夫なの？");
	TO
		act[0].Left();
		act[0].Mes("差別はいかんな＠女の子が武器を作ったっていいじゃないか");
	TO
		act[0].Down();
		act[0].Mes("すいません、許してやって下さい");
	TO
		act[1].Mes("武器を作るんですか？");
	TO
		act[0].E思考();
		act[1].E思考();
		act[2].E思考();
	TO
		act[0].E驚き();
		act[1].E疑問();
		act[2].E呆れ();
	TO
		act[2].Mes("募集してるのは、武器を作る職人だよ");
	TO
		act[1].E呆れ();
	TO
		act[1].Mes("店員さんじゃないんですか？");
	TO
		act[2].Mes("そう書いてあったはずだけど");
	TO
		act[1].Mes("ごめんなさい");
	TO
		act[0].E音符();
	TO
		act[0].Mes("いや、丁度店員も募集しようと思っていたんですよ");
	TO
		act[2].Right();
		act[2].Mes("えっ");
	TO
		act[1].Mes("そうなんですか？");
	TO
		act[0].Mes("来月からよろしくね");
	END
}	
void EVE_SUB::つるはし納品()
{
	//つるはしを納品に役場へ
	//来月分は未定になる
	START
		act[0].Set(EChara::セオ,15,7,DI::左);
		act[1].Set(EChara::受付,2,7,DI::右);
		act[2].Set(EChara::ゴクト, -1, 7, DI::右);
		act[3].Set(EChara::タクス, -1, 7, DI::右);
		BackChenge(EStage::役所);
	TO
		act[0].Move(-10, 0, 4);
	TO
		act[1].Mes("こんにちは");
	TO
		act[0].Mes("フロンティアスミスのセオです＠鉱山開発課のゴクトさんをお願いします");
	TO
		act[1].Mes("少々お待ちください");
	TO
		act[1].Move(-3,0,4);
	TO
		act[2].Move(3, 0, 4);
	TO
		act[2].Mes("お待たせしました");
	TO
		act[0].Mes("いえいえ＠先日納品した、つるはしはどうですか？");
	TO
		act[2].Mes("なかなか良いつるはしでした＠出来たら来月も頼みたいんですが・・・");
	TO
		act[0].E疑問();
	TO
		act[2].Mes("上の方から、実績の無い業者のは使うなといわれまして");
	TO
		act[2].Mes("すいません、とりあえず今月の受注は０と言う事で・・・");
	TO
		act[0].E思考();
	TO
		act[0].Mes("それは困ります");
	TO
		act[2].Mes("そう言われましても・・・");
	TO
		act[0].E思考();
	TO
		act[0].Mes("分かりました・・・");
	TO
		act[2].Mes("本当にごめんなさい、私の力不足で");
	TO
		act[0].Mes("それと税金の件で相談したいのですが");
	TO
		act[2].Mes("分かりました、担当の物をお呼びします");
	TO
		act[2].Move(-3,0,4);
	TO
		act[3].Move(3, 0, 4);
	TO
		act[3].Mes("はじめましてぇ、税務課のタクスです");
	TO
		act[0].Mes("はじめまして、フロンティアスミスのセオです");
	TO
		act[3].Mes("社長さんも大変ですねぇ＠うちの副領事みたいのに絡まれて");
	TO
		act[3].Mes("さっさとくたばればいいのにね、あんな奴");
	TO
		act[0].E呆れ();
		act[3].Eハート();
	TO
		act[3].Mes("冗談ですよぉ");
	TO
		act[3].Mes("税金の相談でしたっけ？");
	TO
		act[0].Mes("はい、ちょっと分からないところがありまして");
	TO
		act[0].Mes("");
		BackChenge(EStage::役所);
	TO
		act[0].Mes("しかし税率が高すぎると思うんですが？");
	TO
		act[3].Mes("武器税が結構高いですから仕方ないですね");
	TO
		act[0].Mes("まけて貰えませんか？");
	TO
		act[3].E思考();
	TO
		act[3].Mes("それもいいですねぇ＠分前次第ですけど");
	TO
		act[3].Mes("バレたら鉱山で強制労働ですけど＠バレなきゃいいわけで");
	TO
		act[0].E思考();
	TO
		act[0].Mes("やっぱりいいです");
	TO
		act[3].Mes("残念ですねぇ");
	END
}
//メインシナリオ 2
void EVE_SUB::経営二ヶ月目()
{
	//経営二ヵ月目が開始

	START
		act[0].Set(EChara::セオ,7.5,6,DI::下);
		act[1].Set(EChara::ファクト, 6.5, 8, DI::上,false);
		act[2].Set(EChara::トウツグ, 7.5, 8, DI::上,false);
		act[3].Set(EChara::ルルファ, 8.5, 8,DI::上,false);
		BackChenge(EStage::店内);
	TO
		act[0].Mes("おはようございます");
	TO
		act[1].Mes("おはようございます");
		act[2].Mes("おはようございます");
		act[3].Mes("おはようございます");
	TO
		act[0].Mes("今日から２月");
	TO
		act[0].Mes("先月は武器の売れ行きはまずまずでした");
	TO
		act[0].Mes("今月は武器の売上をもっと伸ばしたいですね");
	TO
		act[0].Mes("二人は始めは分からない事もあると思いますが＠分からない事があったら私や、ファクトに聞いて下さい");
	TO
		act[0].Mes("それでは今日も１日よろしくおねがいします");
	TO
		act[1].Mes("よろしくおねがいします");
		act[2].Mes("よろしくおねがいします");
		act[3].Mes("よろしくおねがいします");
	END
}
void EVE_SUB::経営のススメ()
{
	//就業規則とかを決めていなかった事に気付く
	//決める事に

	START
		act[0].Set(EChara::セオ,6,4,DI::下);
		act[1].Set(EChara::ファクト,6,8,DI::上);
		BackChenge(EStage::会議室);
	TO
		act[0].Mes("新入りはどうだ？");
	TO
		act[1].Mes("すごく優秀だよ＠経験者が雇えたのは運が良かったね");
	TO
		act[1].Mes("ただ・・・");
	TO
		act[0].E疑問();
	TO
		act[1].Mes("いやなんでもないよ、ルルファちゃんはどうだい");
	TO
		act[0].Mes("もの覚えもいいし、素直でまじめだし＠客の評判も上々");
	TO
		act[0].Mes("ちょっとどじな所もかわいくて＠文句無しだな");
	TO
		act[1].E呆れ();
	TO
		act[1].Mes("話ってのはそれ？");
	TO
		act[0].E思考();
	TO
		act[0].Mes("つるはしの受注がなくなった");
	TO
		act[1].Mes("なんで？");
	TO
		act[0].Mes("原因は分からん＠仕事が減るのはたしかだな");
	TO
		act[0].Mes("人を増やした矢先に困ったもんだ＠武器販売だけだと結構きびしいしな");
	TO
		act[0].E思考();
	TO
		act[0].Mes("ルルファさんが入って、余裕もできたし＠俺は経営や財務に力を入れる");
	TO
		act[0].Mes("お前も何か考えといてくれ");
	TO
		act[1].Mes("分かった");
	END
}
void EVE_SUB::スタイト視察()
{
	//来月のつるはし受注についてスタイトが視察
	//つるはしノルマが回復
	START
		act[0].Set(EChara::セオ, 7, 4, DI::下);
		act[1].Set(EChara::ルルファ,10,7,DI::右);
		act[2].Set(EChara::スタイト,7,11,DI::左,false);
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
		act[0].E驚き();
	TO
		act[0].Mes("これはスタイト様");
	TO
		act[2].Mes("やぁ久しぶり");
	TO
		act[2].Right();
		act[2].E思考();
	TO
		act[2].Up();
		act[2].Mes("前より従業員が増えてるけど＠武器屋って儲かるんだな");
	TO
		act[0].Mes("いやぁ、なかなか厳しいですね");
	TO
		act[0].Mes("ところで、本日はどのようなご用件で？");
	TO
		act[2].Mes("良いニュースを知らせに");
	TO
		act[0].Mes("良いニュースですか？");
	TO
		act[2].Mes("おたくが納品したつるはしなんだが＠評判が良くてね、また受注する事になった");
	TO
		act[2].Mes("引き受けてくれるか？");
	TO
		act[0].Mes("もちろんです");
	TO
		act[2].Mes("良かった良かった");
	TO
		act[2].Mes("それから、もう一つ・・・");
	TO
		act[2].E思考();
	TO
		act[2].Mes("っとこれは秘密にしないといけなかった");
	TO
		act[2].Mes("それじゃあまた今後");
	TO
		act[2].Move(0,5,4);
	TO
		act[0].E疑問();
	END
}
void EVE_SUB::魔獣の資源()
{
	//某研究所が魔獣を燃料として扱う技術を発明
	//今後魔獣狩猟がフロンティアで流行る模様

	START
		act[0].Set(EChara::セオ, 7, 4, DI::下);
		act[1].Set(EChara::ルルファ, 2, 2, DI::下, false);
		BackChenge(EStage::店内);
	TO
		act[1].Move(0,2);
	TO
		act[1].Move(4,0);
	TO
		act[1].Mes("社長、おはようございます！");
	TO
		act[0].Left();
		act[0].Mes("おはよう、ルルファさん");
	TO
		act[0].E音符();
	TO
		act[0].Mes("ふふふ");
	TO
		act[1].E疑問();
	TO
		act[1].Mes("どうかしましたか？");
	TO
		act[0].Mes("この記事を読んでくれるかな");
	TO
		act[1].Mes("新聞ですか？");
	TO
		act[1].E思考();
	TO
		act[1].Mes("えっと・・・＠「フロンティアで新発見！？」");
	TO
		act[1].Mes("フロンティア在住のトージョー氏が＠ゼラルーに生息する魔獣から＠特殊な油を精製する事に成功した");
	TO
		act[1].Mes("ゼラルーはフロンティアに生息する魔獣で＠ゼラチン質の体を持つ");
	TO
		act[1].Mes("ゼラルー油は動物油や植物油に比べ＠高いエネルギーを持つ");
	TO
		act[1].Mes("ゼラルーは大量に生息しているため＠安価に油が精製されるようになるだろう");
	TO
		act[1].Mes("この発表で、燃料油関連株は大幅に値動きしている");
	TO
		act[1].E疑問();
	TO
		act[1].Mes("これがどうしたんですか？");
	TO
		act[1].E音符();
	TO
		act[1].Mes("あっ！燃料費が減りますね");
	TO
		act[0].E呆れ();
	TO
		act[0].Mes("まぁ、それもそうなんだが");
	TO
		act[0].Mes("ゼラルーを狩るハンターが増える方が大事かな");
	TO
		act[0].Mes("客も増えるだろうし、忙しくなる＠がんばろうな");
	TO
		act[1].Mes("はい！");
	END
}
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
void EVE_SUB::工事のススメ()
{
	//設備のしょぼさについて、トウツグから不満が
	//なぜか登場したカノン工務店

	START
		act[0].Set(EChara::セオ,7,4,DI::左);
	act[1].Set(EChara::ファクト, -1, 4, DI::左, false);
		act[2].Set(EChara::トウツグ,-1,3,DI::左);
		act[3].Set(EChara::タクミ, 7, 11, DI::上,false);
		BackChenge(EStage::店内);
	TO
		act[1].Move(7,0);
		act[2].Move(7,0);
	TO
		act[1].Mes("セオちょっといい＠工房の件で話があるんだけど");
	TO
		act[0].E疑問();
	TO
		act[0].Mes("何だ？");
	TO
		act[1].Mes("今の工房の設備だと、作れる武器に限界があるんだ");
	TO
		act[1].Mes("お客さんも増えそうだし設備を増強しようよ");
	TO
		act[0].E思考();
	TO
		act[0].Mes("しかしなぁ、実際に客が増えるのは先だろ？＠頑張ってなんとかしてくれ");
	TO
		act[2].E怒り();
	TO
		act[2].Mes("今の設備じゃ駄目なんですよ");
	TO
		act[2].Mes("炉は小さくて扱える金属が少ないし＠金床も強度が足りてない");
	TO
		act[2].Mes("あんなんじゃナマクラしか作れませんよ＠それでも武器屋の社長ですか？");
	TO
		act[1].E呆れ();
	TO
		act[1].Up();
		act[1].Mes("もうちょっと言葉を選ばないと・・・");
	TO
		act[2].Down();
		act[2].Mes("何でですか？");
	TO
		act[0].Mes("ファクト！お前どういう指導してるんだ");
	TO
		act[1].E呆れ();
	TO
		act[1].Mes("えっ、僕！？");
	TO
		act[3].Move(0,-5);
	TO
		act[3].Mes("こんにちは、社長");
	TO
		act[0].Down();
		act[1].Down();
		act[2].Down();
		act[0].E驚き();
	TO
		act[0].Mes("おっタクミさん、お久しぶりです");
	TO
		act[3].E疑問();
	TO
		act[3].Mes("お取り込み中だったかな？");
	TO
		act[0].Mes("いやぁ、そんな事は・・・");
	TO
		act[3].Mes("新聞見たよ、お客さん増えそうじゃないか");
	TO
		act[3].Mes("忙しくなる前に、設備を改築しとかないかい");
	TO
		act[0].Mes("そうだなぁ・・・");
	TO
		act[0].E思考();
	TO
		act[0].Mes("職人からも、設備に不満が出てるし");
	TO
		act[0].Mes("お願いしようかな");
	TO
		act[2].E音符();
	TO
		act[3].Mes("それじゃあ強化したい設備が決まったら＠呼んでくれよ");
	END
}
//メインシナリオ 3
void EVE_SUB::経営三ヶ月目()
{
	//経営三ヶ月目、ハンターが増えるだろう話。
	//今後採用を増やす話
	START
		act[0].Set(EChara::セオ, 7.5, 6, DI::下);
		act[1].Set(EChara::ファクト, 6.5, 8, DI::上, false);
		act[2].Set(EChara::トウツグ, 7.5, 8, DI::上, false);
		act[3].Set(EChara::ルルファ, 8.5, 8, DI::上, false);
		BackChenge(EStage::店内);
	TO
		act[0].Mes("おはようございます");
	TO
		act[1].Mes("おはようございます");
		act[2].Mes("おはようございます");
		act[3].Mes("おはようございます");
	TO
		act[0].Mes("先月は例の発見もあってハンターが増えだし＠武器の売れ行きどんどん増えています");
	TO
		act[0].Mes("生産を増やすために＠また人を増やそうと思います");
	TO
		act[0].Mes("しかしながら、他の店がオープンすると言う情報も入っています");
	TO
		act[0].Mes("商品の質や値段で他店に負けないように頑張らなければ＠売上が落ちることも考えられます");
	TO
		act[0].Mes("それでは今日も１日よろしくおねがいします");
	TO
		act[1].Mes("よろしくおねがいします");
		act[2].Mes("よろしくおねがいします");
		act[3].Mes("よろしくおねがいします");
	END
}
void EVE_SUB::ルルファの兄()
{
	//ルルファの兄登場、鉱山労働をやめてハンターになるとか。

	START
		act[0].Set(EChara::セオ,7,4,DI::下);
		act[1].Set(EChara::ルルファ,15,6,DI::右);
		act[2].Set(EChara::ニット,6.5,11,DI::左,false);
		act[3].Set(EChara::レイブル,7.5,12,DI::左,false);
		BackChenge(EStage::店内);
	TO
		act[2].Move(0,-5);
		act[3].Move(0, -6);
	TO
		act[0].Mes("いらっしゃいませ");
	TO
		act[0].Mes("本日はどのような武器を？");
	TO
		act[2].E思考();
	TO
		act[2].Mes("今日からハンターを始めるので＠あまり詳しくないんですよ");
	TO
		act[2].Mes("おすすめの剣とかありますか？");
	TO
		act[0].E思考();
	TO
		act[0].Mes("そうですね・・・鉄の剣がおすすめです＠切れ味も耐久もよくて、使いやすいですし");
	TO
		act[2].E思考();
	TO
		act[2].Mes("じゃあそれを見せて貰えますか？");
	TO
		act[2].Right();
		act[2].Mes("お前はどうする？");
	TO
		act[3].Mes("俺も同じのを見てみるかな");
	TO
		act[2].Up();
		act[0].Mes("分かりました、少々お待ちを");
	TO
		act[0].Right();
		act[0].Mes("ルルファさん！");
	TO
		act[0].Down();
		act[2].Right();
		act[3].Right();
		act[1].Move(-6,0);
	TO
		act[1].Mes("お呼びですか？");
	TO
		act[1].Mes("お兄ちゃんにレイブル！");
	TO
		act[0].E疑問();
	TO
		act[1].Mes("どうしてここに？");
	TO
		act[3].Mes("姉ちゃんが働いてるって聞いて、せっかくだし武器を買いにな");
	TO
		act[1].Mes("仕事はどうしたの？");
	TO
		act[3].Mes("前の仕事は辞めた＠今日からは俺達の仕事はハンターだ");
	TO
		act[3].E音符();
	TO
		act[1].Mes("危険だよ、分かってるの？");
	TO
		act[2].E思考();
	TO
		act[2].Mes("先に言い始めたのは俺の方だよ");
	TO
		act[2].Mes("鉱山の仕事もなんだかんだで危険だし＠長く続けられるもんじゃない");
	TO
		act[2].Mes("魔獣狩りって言っても近場でゼラルーを狩るだけなら＠対して危険じゃないよ");
	TO
		act[1].E思考();
	TO
		act[1].Mes("兄さんがそう言うなら・・・");
	TO
		act[0].E思考();
	TO
		act[0].Mes("ごほん");
	TO
		act[1].Up();
		act[2].Up();
		act[3].Up();
		act[0].Mes("心配するのも分かりますが＠うちの武器を使えば、魔獣なんてたいした事ないですよ");
	TO
		act[1].Mes("そう、ですね・・・");
	END
}
void EVE_SUB::シエホ採用()
{
	//シエホを面接＆採用
	//没イベント
	START
		act[0].Set(EChara::セオ,6,8,DI::上,false);
		BackChenge(EStage::会議室);
	TO
		act[0].Mes("どうぞ");
	TO
		act[1].Set(EChara::シエホ, 3, 2, DI::下);
	TO
		act[1].Move(0, 2);
	TO
		act[1].Move(3, 0);
	TO
		act[1].Down();
		act[1].Mes("よろしくお願いします");
	TO
		act[0].Mes("こちらこそ、よろしく");
	TO
		act[0].Mes("それじゃあ面接を始めます");
	TO
		act[0].E思考();
	TO
		act[0].Mes("会計の国家資格をお持ちのようですけど・・・");
	TO
		act[0].Mes("これ本当ですか？");
	TO
		act[1].E疑問();
	TO
		act[1].Mes("そうですけど、何か？");
	TO
		act[0].Mes("ありがたいんですが、なんでうちなんかにと思いまして");
	TO
		act[1].Mes("はい");
	TO
		act[1].Mes("フロンティアで発見された新エネルギーのニュースを聞きまして");
	TO
		act[1].Mes("そうなると、今後フロンティアにハンターが増えるだろうと");
	TO
		act[1].Mes("そこに将来性を感じました");
	TO
		act[0].E思考();
	TO
		act[0].Mes("そうですか・・・");
	TO
		act[0].Mes("接客の経験は？");
	TO
		act[1].Mes("学生時代に本屋で働いていました");
	TO
		act[0].Mes("なるほど");
	TO
		act[0].E思考();
	TO
		act[0].Mes("明日から働いて頂けますか？");
	TO
		act[1].Mes("はい！");
	END
}
void EVE_SUB::財務のススメ()
{
	//資金繰りに対して、増資の提案。
	//没イベント
	START
		act[0].Set(EChara::セオ,7,4,DI::左);
		act[1].Set(EChara::シエホ,-1,4,DI::左);
		BackChenge(EStage::店内);
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
void EVE_SUB::カノン工房()
{
	//カノン工房が遂に明日開店
	//なんか挨拶に来る
	START
		act[0].Set(EChara::セオ,7,4,DI::左);
		act[1].Set(EChara::ファクト, 6, 4, DI::右);
		BackChenge(EStage::店内);
	TO
		act[1].Mes("いよいよ、明日だね");
	TO
		act[0].E疑問();
	TO
		act[0].Mes("何の話だ？");
	TO
		act[1].Mes("新しく出来る武器屋の開店日だよ");
	TO
		act[0].Mes("お前もそういうの気にするんだな");
	TO
		act[0].Mes("どうせ大したことないだろ");
	TO
		act[2].Set(EChara::カノン, 7, 11, DI::左, false);
		act[2].Mes("それは聞き捨てならないです");
	TO
		act[2].Move(0,-5);
	TO
		act[0].Down();
		act[1].Down();
		act[0].Mes("いらっしゃいませ");
	TO
		act[2].Mes("客じゃないです");
	TO
		act[0].Left();
		act[1].Right();
		act[0].Mes("知り合い？");
	TO
		act[1].Mes("多分違うと思う");
	TO
		act[0].Down();
		act[1].Down();
		act[2].Mes("カノン工房、社長のカノンです＠開店前の挨拶に来ました");
	TO
		act[0].Mes("それはどうも");
	TO
		act[2].Mes("武器屋同士、正々堂々と商売ですよ");
	TO
		act[2].E思考();
	TO
		act[2].Mes("まぁ、見た感じ大したなさそうですし＠うちの相手にはならないと思いますが");
	TO
		act[2].Mes("それでは、開店準備で忙しいので");
	TO
		act[2].Move(0,6);
	TO
		act[0].Left();
		act[1].Right();
		act[0].Mes("言ったとおりだろ？");
	TO
		act[1].Mes("そうだね");
	END
}
void EVE_SUB::昇給要求()
{
	//従業員の管理をしよう的な提案
	START
		act[0].Set(EChara::セオ,6,4,DI::下);
		act[1].Set(EChara::ファクト,6,8,DI::上);
		BackChenge(EStage::会議室);
	TO
		act[1].Mes("話って何？");
	TO
		act[0].Mes("給料の話だ");
	TO
		act[0].Mes("利益も増えているし、上げようと思ってな");
	TO
		act[1].Mes("そうだね、皆喜ぶと思うよ＠やる気も上がるんじゃないかな？");
	TO
		act[0].Mes("職人の働きぶりについてはお前の方が分かってるだろ？＠その辺りを聞きたくてな");
	TO
		act[0].Mes("どんな感じだ？");
	TO
		act[1].Mes("えっと、そうだね・・・");
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
			act[4].Set(EChara::サンダー,6,10,DI::左);
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

/*1.1*/
/*プロローグ*/
/*語り部による導入。*/
void EVE_SUB::1_1_1();

/*開店*/
/*主人公とファクトの二人が店舗を開設した所からスタート。*/
void EVE_SUB::1_1_2();

/*製造開始*/
/*武器の製造開始！と思いきや、鉱山開発用のつるはしを製造する事に。*/
/*ここで竜が生息している伏線が貼られる。*/
void EVE_SUB::1_1_3();

/*総督の視察と営業許可A*/
/*総督が部下を連れて武器屋の視察に来る。*/
/*賄賂を要求されたが、ムカついたのでお菓子を渡す。*/
void EVE_SUB::1_1_4();

/*総督の視察と営業許可B*/
/*賄賂の要求でお菓子を渡された事に起こって総督が反乱軍の容疑でやってくる、*/
/*都合良く副総督がやってきてその場を収める。*/
void EVE_SUB::1_1_5();

/*初めての客*/
/*いつもの様につるはしの生産計画の確認をしていた所、人が訪ねてきた。*/
/*何の用か ? と聞くと武器を買いに来た･･･だと？*/
/*来客者は調査のために狩猟をしているハンターだと言うので、初めて武器が売れる。*/
/*以後ちょくちょく客が来るようになる。*/
void EVE_SUB::1_1_6();

/*ドラゴンハンター*/
/*またもや来客、竜を狩るための武器を探しているという。*/
/*竜なんて本当にいるのか？と聞くと、色々話をしてくれた。*/
void EVE_SUB::1_1_7();

/*募集開始*/
/*思ったより武器の売れ行きが良く。*/
/*追加で職人を雇う事に。*/
void EVE_SUB::1_1_8();

/*刀継採用*/
/*募集を開始した翌日、武器製造の経験者だと言う若者がやってくる。*/
/*結局採用する事に。*/
void EVE_SUB::1_1_9();

/*ルルファ採用*/
/*可愛らしい女の子が職人志望？に来たのでセオは喜ぶが、接客志望だと分かる、*/
/*とりあえず接客も募集していた事にして採用するのであった。*/
void EVE_SUB::1_1_10();

/*つるはし納品*/
/*納品日になったので、つるはしを持ち役場に出向く。*/
/*副総督から圧力があったのか、来月は受注を無くなる事に。*/
void EVE_SUB::1_1_11();

/*1.2*/
/*	新入り入社*/
/*月初めの挨拶と、新入りの自己紹介*/
void EVE_SUB::1_2_1();

/*経営体制をつくる*/
/*社員が増えてきそうだし、社内制度を見直す動きをする*/
void EVE_SUB::1_2_2();

/*教授と調査狩猟団*/
/*以前に買い物に来た調査団の団長が来訪、*/
/*団員募集を手伝って欲しい、代わりに宣伝を手伝おうとの事。*/
void EVE_SUB::1_2_3();

/*副総督の視察*/
/*店の状況を見に副総督が来訪、つるはし納品数が増える。*/
void EVE_SUB::1_2_4();

/*工房取材*/
/*フロンティア新聞の記者が来訪。*/
/*開店理由等の取材を受ける、他店の動向についても聞く。*/
void EVE_SUB::1_2_5();

/*1.3*/
/*工事のススメ*/
/*月初めの朝礼で、設備投資について語る。*/
void EVE_SUB::1_3_1();

/*ルルファの兄*/
/*調査狩猟団員になったので武器を買いに来た、ルルファの兄二人が来店。*/
/*調度品として魔物の毛皮等が売れるとかで団員を増やしているらしい。*/
void EVE_SUB::1_3_2();

/*カノン工房*/
/*つるはし等を製造していたカノン工房が武器の販売を開始。*/
/*なぜか乗り込んでくる。*/
void EVE_SUB::1_3_3();

/*財務について*/
/*利益も出てきたので、余剰資金の使い道について。*/
void EVE_SUB::1_3_4();

/*1.4*/
/*月初めの挨拶*/
/*ライバル店への言及。*/
void EVE_SUB::1_4_1();

/*がらの悪い二人組*/
/*狩猟団から紹介されたとかで来店した、すごく感じの悪いハンターが来店。*/
void EVE_SUB::1_4_2();

/*極月鍛冶*/
/*新しく武器屋がまた出来たらしく、何故かカノンが来店。*/
/*刀次はなにか知っている様子。*/
void EVE_SUB::1_4_3();

/*宣伝作戦*/
/*他の武器屋も増えたので宣伝を強化しようといった話。*/
void EVE_SUB::1_4_4();

/*待遇改善要求
/*ファクトより店員が昇給を要求していると聞く。*/
/*儲かっているし利益を還元しようかと言った流れに。*/
void EVE_SUB::1_4_5();

/*1.5*/
/*月初め*/
/*業績が好調で給料も上げるぞ、みたいな話。*/
void EVE_SUB::1_5_1();

/*ドラゴンハンター再び*/
/*竜の情報についてあれこれ。*/
void EVE_SUB::1_5_2();

/*魔獣の資源*/
/*新聞のスクープ記事で、ゼラルーを燃料として使う方法が実用化したとの事。*/
/*今後のハンター増加が見込まれる。*/
void EVE_SUB::1_5_3();

/*開拓祭り布告*/
/*久しぶりに総督が来店、魔獣の資源化と入植開始5週年を記念して祭りをする事になったとか。*/
void EVE_SUB::1_5_4();

/*1.6*/
/*月初め*/
/*開拓祭りが来月にある事と、魔獣の資源化についてあれこれ*/
void EVE_SUB::1_6_1();

/*ハンター協会拡大*/
/*プロフェッサーが来訪、資源化で調査狩猟団を拡大する説明等。*/
void EVE_SUB::1_6_2();

/*開拓祭りに誘う*/
/*祭りの日は休みなので、ルルファを誘う事に*/
/*ルルファ兄がたまたま訪問*/
void EVE_SUB::1_6_3();

/*新ハンター来訪*/
/*狩猟団の新しい人が来る。*/
/*ガラの悪いハンターも何か言う。*/
void EVE_SUB::1_6_4();

/*1.7*/
/*月初め*/
/*開拓祭りと、ハンター増について言及*/
void EVE_SUB::1_7_1();

/*開拓祭り開催*/
/*演説やら展示会やら、久々に総督登場*/
void EVE_SUB::1_7_2();

/*ヘルメス採用*/
/*祭りの時に露天であった人が、募集に来る。*/
void EVE_SUB::1_7_3();

/*新武器の開発*/
/*ヘルメスの提案、武器の装飾について。*/
/*ファクトはやや反対派、刀次は中立な感じ。*/
void EVE_SUB::1_7_4();

/*1.8*/
/*月初め* /
/*ヘルメスの登用と、新商品開発について。*/
void EVE_SUB::1_8_1();

/*竜の遺産*/
/*中央のオークションで竜の瞳が競売にかけられ凄まじい金額で売れる。*/
/*ドラゴンハンターと会話、他の店の言及等。*/
void EVE_SUB::1_8_2();

/*極月刀鍛冶来訪*/
/*祭り会場で見かけたとかで極月が刀次を連れ戻しに来る。*/
/*喧嘩して終了。事情は聞けなかった。*/
void EVE_SUB::1_8_3();

/*ルルファ兄来訪*/
/*ドラゴンの噂と、ドラゴン倒すぞー的な。*/
void EVE_SUB::1_8_4();

/*1.9*/
/*月初め*/
/*開拓が進んでいる事、ハンターが急増している事について*/
void EVE_SUB::1_9_1();

/*新人向けに安い武器*/
/*ファクトがヘルメスの方針に文句を付ける、安い武器が必要だと言う。*/
/*ファクトが老害っぽい感じで。*/
void EVE_SUB::1_9_2();

/*総督来店*/
/*いやがらせにくる。*/
void EVE_SUB::1_9_3();

/*ハンター同士のトラブル*/
/*ガラの悪い二人組みと、新入りハンターが店内でトラブルを起こす。*/
void EVE_SUB::1_9_4();

/*1.10*/
/*月初め*/
/*客とのトラブルについて。*/
void EVE_SUB::1_10_1();

/*プロフェッサー再び*/
/*開拓の進み具合についてと、先日のトラブルについて等。*/
void EVE_SUB::1_10_2();

/*ルルファ兄との会話*/
/*協会の実態について話したり、ハンター同士のトラブルについて。*/
void EVE_SUB::1_10_3();

/*・極月から*/
/*刃一が説得にくる。*/
void EVE_SUB::1_10_4();

/*1.11*/
/*・月初め*/
/*経営は順調です。特に何も無し。*/
void EVE_SUB::1_11_1();

/*・ゴランノス出店の噂*/
/*ルルファ兄からホワイトナイトの買収とゴランノス出展の噂を聞く。*/
void EVE_SUB::1_11_2();

/*・トウジの様子*/
/*彼女が出来たらしい？(妹だったとか)*/
void EVE_SUB::1_11_3();

/*・ドラゴン目撃情報*/
/*がらの悪いハンターが来店、ドラゴンがどうのこうの。*/
void EVE_SUB::1_11_4();

/*1.12*/
/*・月初め*/
/*ドラゴンの目撃情報について、対ドラゴン武器の開発が必要。*/
void EVE_SUB::1_12_1();

/*・ゴランノス出店*/
/*ゴランノスが新規出店、支店長が宣戦布告に来る。*/
void EVE_SUB::1_12_2();

/*・対ドラゴン武器の開発*/
/*対ドラゴン武器の開発状況について。*/
void EVE_SUB::1_12_3();

/*・副総督来店*/
/*ゴランノスの情報等を何故か流してくれる。*/
void EVE_SUB::1_12_4();

/*2.1*/
/*・月礼*/
/*ルルファが珍しく遅刻。*/
/*ドラゴンの襲撃を受け、ルルファ兄を含むハンター数名が死亡 / 行方不明。*/
/*言論規制が敷かれるが、噂は直ぐに広まった。*/
/*ルルファは休暇に入る。*/
void EVE_SUB::2_1_1();

/*・ゴランノスの投げ売り*/
/*事前の情報通り、ゴランノスがセールを開始する。*/
void EVE_SUB::2_1_2();

/*・ドラゴン噂*/
/*ドラゴン襲撃についてドラゴンハンターが来店。*/
/*ドラゴンの懸賞金の話等、色々喋る。退治してくれていたらとかなんとか。*/
void EVE_SUB::2_1_3();

/*・カノン工房*/
/*売上減少を危機に感じたカノンが来店。*/
/*協力を打診してくる。部分的に協力する事に、極月とは協力出来ない。*/
void EVE_SUB::2_1_4();

/*2.2*/
/*・月初め*/
/*ゴランノスのセールの影響等について*/
/*ルルファ復帰*/
void EVE_SUB::2_2_1();

/*・ルルファと会話*/
/*何があったのか等*/
void EVE_SUB::2_2_2();

/*・来店*/
/*がらの悪いハンターが来店、ゴランノス製品はゴミだ。*/
/*協会もゴランノス製品をネガキャンしているとか。*/
void EVE_SUB::2_2_3();

/*・セール終了*/
/*ゴランノスが安売りを止めて、リニューアルを始めるとの噂。*/
void EVE_SUB::2_2_4();

/*2.3*/
/*・月初め*/
/*ゴランノスのセール終了について。*/
void EVE_SUB::2_3_1();

/*・総督来店*/
/*ゴランノスの出店失敗とその背景について。*/
/*中央がどうとか。*/
void EVE_SUB::2_3_2();

/*・協力を続けるか？*/
/*カノンがゴランノス失敗に喜び勇んでやってくる。*/
/*今後も技術協力は続ける事に。ファクトは反対。*/
void EVE_SUB::2_3_3();

/*・ドラゴンの被害状況*/
/*また、竜に襲われハンターが死亡したらしい。*/
/*町の結構近くだとか。*/
void EVE_SUB::2_3_4();

/*2.4*/
/*・月初め*/
/*ドラゴンの脅威について。*/
void EVE_SUB::2_4_1();

/*・団長来店*/
/*ゴランノスの失敗について、喜ぶ団長。*/
void EVE_SUB::2_4_2();

/*・ゴランノス、リニューアル*/
/*ゴランノス社が店長を交代してリニューアルオープン。*/
/*なぜかフロンティアスミスと殆ど同じ武器が並び、セールが開始。*/
/*評判は多少回復したそうです。*/
void EVE_SUB::2_4_3();

/*・カノン来店*/
/*技術流出について誰が流したか等で議論が紛糾。*/
/*協力体制が決裂する。*/
void EVE_SUB::2_4_4();

/*2.5*/
/*・月初め*/
/*情報流出問題についてなど*/
void EVE_SUB::2_5_1();

/*・新武器の開発*/
/*そもそも剣で竜と戦うのは無理では？*/
/*という事でヘルメスが銃の製造を提案する。*/
/*ゼラルー火薬の発明がどうのこうの。*/
/*(銃は既に存在しているが、普及はしていない)*/
void EVE_SUB::2_5_2();

/*・ドラゴンハンター来店*/
/*今ある武器で倒しに行く事にするらしい。*/
/*ルルファは複雑な感じ。*/
void EVE_SUB::2_5_3();

/*・ルルファ兄来店*/
/*酔っ払ったルルファ兄が来店。*/
void EVE_SUB::2_5_4();

/*2.6*/
/*・月初め*/
/*好調だけど、ゴランノスに苦戦気味。*/
void EVE_SUB::2_6_1();

/*・総督来店*/
/*ゴランノス躍進の自慢と開拓祭の告知。*/
void EVE_SUB::2_6_2();

/*・ハンター来店*/
/*ドラゴンにびびってる奴や倒そうとしている奴がいる事など雑談。*/
void EVE_SUB::2_6_3();

/*・銃器サンプル*/
/*銃の試作が完成。祭りで展示する事に。*/
void EVE_SUB::2_6_4();

/*2.7*/
/*・月初め*/
/*1年ぶりに開拓祭があります。*/
void EVE_SUB::2_7_1();

/*・祭りに誘う*/
/*ルルファを祭りに誘う。*/
void EVE_SUB::2_7_2();

/*・開拓祭り*/
/*一年ぶりの開催。*/
void EVE_SUB::2_7_3();

/*・カノン工房が武器事業を終了*/
/*つるはし事業に専念するとか。*/
void EVE_SUB::2_7_4();

/*2.8*/
/*・月初め*/
/*銃の展示が成功だった事。*/
void EVE_SUB::2_8_1();

/*・ハンター会長来店*/
/*銃の開発に協力しようとやってくる。*/
void EVE_SUB::2_8_2();

/*・開発体制*/
/*今後は銃の開発を強化し、情報流出に備えようと言う事に。*/
/*ファクトが反発する。*/
void EVE_SUB::2_8_3();

/*・竜が討伐された？*/
/*竜の目撃情報が減っているらしい。*/
/*竜の鱗を入手した人が現れる。*/
void EVE_SUB::2_8_4();

/*2.9*/
/*・月初め*/
/*竜討伐の噂について。*/
void EVE_SUB::2_9_1();

/*・総督来店*/
/*ゴランノスが銃の発表会を行うと情報をくれる。*/
/*ファクトが疑われる。*/
void EVE_SUB::2_9_2();

/*・ゴランノスが銃の発表会*/
/*事故を起こす。*/
void EVE_SUB::2_9_3();

/*・フロンティアスミスが銃の発表会*/
/*成功する。*/
void EVE_SUB::2_9_4();

/*2.10*/
/*・月初め*/
/*銃の製造拡大に*/
void EVE_SUB::2_10_1();

/*・ファクト退職*/
/*ついていけなくなったとか。*/
void EVE_SUB::2_10_2();

/*・シロ来店*/
/*ドラゴンの討伐について。*/
/*ファクトがいなくてがっかりみたいな感じ。*/
void EVE_SUB::2_10_3();

/*・銃の販売開始*/
/*ドラゴンが討伐された件は隠される。*/
void EVE_SUB::2_10_4();

/*2.11*/
/*・月初め*/
/*銃の販売は好調。*/
void EVE_SUB::2_11_1();

/*・銃の量産計画*/
/*売れまくってるのでどんどん増産する。*/
void EVE_SUB::2_11_2();

/*・ゴランノス撤退*/
/*ゴランノスが西部での武器販売から撤退する事に。*/
void EVE_SUB::2_11_3();

/*・トウツグ退職*/
/*実家に帰るらしい。*/
void EVE_SUB::2_11_4();

/*2.12*/
/*・月初め*/
/*ゴランノスの撤退について。*/
void EVE_SUB::2_12_1();

/*・副総督の演説とクーデター*/
void EVE_SUB::2_12_2();

/*・中央で反乱軍の蜂起*/
void EVE_SUB::2_12_3();

/*・エンディング*/
void EVE_SUB::2_12_4();