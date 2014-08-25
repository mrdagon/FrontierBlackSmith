#pragma once
#include "btb.h"
//using namespace fbs;

#define NEXT break;case
#define START int L=0;if(EVE_FUN::Sin().eve_line == 0){
#define TO	  }L++;if(EVE_FUN::Sin().eve_line==L){
#define END   TO EVE_FUN::Sin().eve_end = 1;}

void EVE_FUN::eve_test()
{
	while(1)
	{
		fun.eve_syori(1);
		//イベントチェック
		if(fun.err_c()== -1) break;
	}
}

int EVE_FUN::eve_switch(int E)
{
	EVE_SUB::Switch( E );
	
	return 1;
}

void EVE_FUN::eve_efe(int E)
{
	//終了後効果、チュートリアル導入等
	switch( E )
	{
		case 23://開店
			wind.ok[1] = 1;
			wind.ok[5] = 1;	
			fun.tutorial(0);
		break;
		case 24://つるはし製造開始
			shop[0].wep_cre[99] = 2;
			fun.list_pw(99);
			shop[0].nougu_req = 30;			
			wind.ok[6] = 1;
			fun.tutorial(1);
		break;
		case 25://営業許可Ａ
			data.jinkou_up = 5;
			for (int i = 0; i< 10; i++)	fun.make_hunter(1);
			wind.ok[0] = 1;
			wind.ok[2] = 1;
			wind.ok[4] = 1;
		break;
		case 28://調査狩猟
			fun.tutorial(5);//ハンターの生活
		break;
		case 31://トウツグ採用
			data.hirameki_rate = 100;
			shop[0].hirameki_dayb = 100;
			fun.tutorial(3);
		break;
		case 33://つるはし納品
			wind.ok[8] = 1;
			shop[P].nougu_req = 0;
			fun.tutorial(7);
		break;
		case 34://２か月目-ルルファ追加
			emp[2].plus(0);
			emp[4].plus(0);
			shop[0].nougu_req = 0;
			wind.ok[7] = 1;
			fun.tutorial(6);
		break;
		case 35://経営戦術
			wind.ok[9] = 1;
			shop[P].n_mp = 50;
			shop[P].bumon_lv[0] = 1;
			fun.tutorial(10);
		break;
		case 36://スタイトの視察
			shop[0].nougu_req = 60;
		break;
		case 37://工事部
			for(int S=0;S<5;S++){shop[S].bumon_lv[2] = 1;}
			fun.tutorial(12);
		break;
		case 38://魔獣の研究
			wind.ok[11] = 1;
			data.jinkou_up = 100;
			fun.tutorial(2);
		break;
		case 40://経営三ヶ月目
			data.jinkou_up = 40;
			wind.ok[3] = 1;
			fun.tutorial(4);
			fun.tutorial(8);
		break;
		case 44://財務部--増資
			for(int S=0;S<5;S++){shop[S].bumon_lv[1] = 1;}
			fun.tutorial(11);
		break;
		case 45://ヘルメス採用
			emp[6].plus(0);
		break;
		case 46://開発部
			for(int S=0;S<5;S++){shop[S].bumon_lv[3] = 1;}
			fun.tutorial(13);
		break;
		case 47://カノン工房
			data.shop_cnt = 2;
			shop[1].create_lv[0] = 5;
			shop[1].create_lv[1] = 6;
			shop[1].create_lv[2] = 5;
			shop[1].wep_cre[11]=2;
			shop[1].wep_cre[111]=2;
			shop[1].wep_cre[211]=2;
			shop[1].wep_cre[311]=2;	
			shop[1].wep_rest[11] = 100;
			shop[1].wep_rest[111] = 100;
			shop[1].wep_rest[211] = 100;
			shop[1].wep_rest[311] = 100;
			shop[1].senden_syori(50,100);
			fun.zaiko_cnt();
			fun.tutorial(9);
			data.taiguu_ok = 1;
		break;
		case 48://昇給要求
		break;
		case 50://宣伝部
			for(int S=0;S<5;S++){shop[S].bumon_lv[4] = 1;}
			fun.tutorial(14);
		break;
		case 52://ホワイトナイト			
			data.shop_cnt = 3;
			shop[2].create_lv[0] = 8;
			shop[2].create_lv[1] = 8;
			shop[2].create_lv[2] = 10;
			shop[2].wep_cre[11]=2;
			shop[2].wep_cre[111]=2;
			shop[2].wep_cre[211]=2;
			shop[2].wep_cre[311]=2;	
			shop[2].wep_rest[11] = 100;
			shop[2].wep_rest[111] = 100;
			shop[2].wep_rest[211] = 100;
			shop[2].wep_rest[311] = 100;
			shop[2].senden_syori(50,100);
			fun.zaiko_cnt();
		break;
		case 56://極月鍛冶
			data.shop_cnt = 4;
			shop[3].create_lv[0] = 16;
			shop[3].create_lv[1] = 10;
			shop[3].create_lv[2] = 10;
			shop[3].wep_cre[11]  = 3;
			shop[3].wep_cre[111] = 3;
			shop[3].wep_cre[211] = 3;
			shop[3].wep_cre[311] = 3;	
			shop[3].wep_rest[11]  = 100;
			shop[3].wep_rest[111] = 100;
			shop[3].wep_rest[211] = 100;
			shop[3].wep_rest[311] = 100;
			shop[3].senden_syori(50,100);
			fun.zaiko_cnt();
		break;
		case 54://祭り布告
			fun.tutorial(15);//つるはしんピック
		break;
		case 60://竜の瞳
			data.jinkou_up = 100;
		break;
		case 64://ゴランノス出店
			data.shop_cnt = 5;
			shop[4].create_lv[0] = 5;
			shop[4].create_lv[1] = 5;
			shop[4].create_lv[2] = 5;
			shop[4].wep_cre[11]  = 3;
			shop[4].wep_cre[111] = 3;
			shop[4].wep_cre[211] = 3;
			shop[4].wep_cre[311] = 3;	
			shop[4].wep_rest[11]  = 100;
			shop[4].wep_rest[111] = 100;
			shop[4].wep_rest[211] = 100;
			shop[4].wep_rest[311] = 100;
			shop[4].senden_syori(50,100);
			fun.zaiko_cnt();
		break;
		case 65://前編終了
			data.jinkou_up = 50;
			fun.tutorial(19);
			sys.clear = 1;
		break;
	}
}

bool EVE_FUN::eve_ok(int E)
{
	//特殊条件判定
	switch( E )
	{
		case 0:
		return true;
		default:
		return true;
	}

	return true;
}

/*背景切り替え*/
int EVE_FUN::back_change(EStage estage , int T )
{
	switch( estage )
	{
		case EStage::店外:
			EVE_FUN::Sin().eve_name = "店外";
		break;
		case EStage::店内:
			EVE_FUN::Sin().eve_name = "店内";
		break;
		case EStage::会議室:
			EVE_FUN::Sin().eve_name = "事務所";
		break;
		case EStage::役所:
			EVE_FUN::Sin().eve_name = "役場";
		break;
		case EStage::広場:
			EVE_FUN::Sin().eve_name = "広場";
		break;
		case EStage::酒場:
			EVE_FUN::Sin().eve_name = "Bar";
		break;
	}
	
	EVE_FUN::Sin().eve_bback = (int)estage;

	EVE_FUN::Sin().eve_black = 255 * T;
	EVE_FUN::Sin().eve_namew = strlen(eve_name.c_str())*9+14;

	return 1;
}

int EVE_FUN::get_line()
{
	return eve_line;
}

void EVE_FUN::set_end()
{
	this->eve_end = 1;
}
/*アクター操作*/

void ACTER::Mes(const char *str ){

	if( str[0] == NULL )//空の場合 
	{
		this->huki_w = 0;
		return;
	}

	int SY,SL,MS=0;
	int lines = 1;

	std::string strr = str;

	SY = 21;

	int N[3] = {0,0,0};

	huki_mes[0][0] = NULL;
	huki_mes[1][0] = NULL;
	huki_mes[2][0] = NULL;

	N[0] = strr.find( "＠" );
	sprintf_s(huki_mes[0], strr.substr(0,N[0]).c_str() );
	
	if( N[0] != std::string::npos )
	{
		lines = 2;
		N[1] = strr.find( "＠" , N[0]+2 );
		sprintf_s(huki_mes[1], strr.substr(N[0]+2,N[1]-N[0]-2).c_str() );

		if( N[1] != std::string::npos )
		{
			lines = 3;
			N[2] = strr.find( "＠" , N[1]+2 );
			sprintf_s(huki_mes[2], strr.substr(N[1]+2,N[2]-N[1]).c_str() );
		}
	}

	huki_h = 25;
	huki_w = 0;
	SL = 0;

	for( int i=0; i< lines ; i++ )
	{
		if( huki_mes[i] == NULL ) break;

		SL = max( SL , (int)strlen(huki_mes[i]) );
		huki_w = max(huki_w , GetDrawStringWidth( huki_mes[i] , SL ) * SY / 20 + 20);
		huki_h += SY;
	}
}
void ACTER::Set(EChara chara , double  X,double  Y,DI M,bool isUp)
{
	emo = -1;
	mx = 0;
	my = 0;
	m = (int)M;
	p = (int)M*3+1;
	x = data.window_x/2 - 212 + int(X * 32) - 14;
	y = data.window_y/2 - 162 + int(Y * 32) - 16;
	huki_ud = 1 - isUp;
	
	sprintf_s(name,emp[(int)chara].name.c_str());

	no = emp[(int)chara].gra;
	
	name_w = strlen( name )*9;
}
void ACTER::Move(double MX,double MY,int S )
{

	mx = int(MX * 32);
	my = int(MY * 32);
	huki_w = 0;
	sp = S;

	if(mx > 0 ) m = (int)DI::右;
	if(mx < 0 ) m = (int)DI::左;
	if(my > 0 ) m = (int)DI::下;
	if(my < 0 ) m = (int)DI::上;

	EVE_FUN::Sin().eve_wait = int(abs(MX+MY)*32/S);
	EVE_FUN::Sin().eve_next = 1;
}
void ACTER::Emo(EM em){
	for (int i = 0; i<32; i++)
	{
		act[i].huki_w = 0;
	}
	emo = (int)em;
	huki_w =0;
	EVE_FUN::Sin().eve_wait= 30;
	EVE_FUN::Sin().eve_next = 1;
}
void ACTER::Direct(DI di)
{
	this->m = (int)di;
}
void ACTER::HukiUp(bool isUp)
{
	this->huki_ud = 1 - isUp;
}

void ACTER::E驚き()
{
	Emo(EM::驚き);
}
void ACTER::E音符()
{
	Emo(EM::音符);
}
void ACTER::E困惑()
{
	Emo(EM::困惑);
}
void ACTER::E呆れ()
{
	Emo(EM::呆れ);
}
void ACTER::E怒り()
{
	Emo(EM::怒り);
}
void ACTER::Eハート()
{
	Emo(EM::ハート);
}
void ACTER::Eドクロ()
{
	Emo(EM::ドクロ);
}
void ACTER::E眠り()
{
	Emo(EM::眠り);
}
void ACTER::E疑問()
{
	Emo(EM::疑問);
}
void ACTER::E思考()
{
	Emo(EM::思考);
}

void ACTER::Up()
{
	Direct(DI::上);
}
void ACTER::Down()
{
	Direct(DI::下);
}
void ACTER::Left()
{
	Direct(DI::左);
}
void ACTER::Right()
{
	Direct(DI::右);
}

int EVE_SUB::Contest()
{
	int point[5] = {0,0,0,0,0};
	int max = 0;
	int top = 0;

	for (int h = 0; h < 100; h++)
	{
		int n = GetRand(data.jinkou_max);

		max = 0;
		top = 0;
		for (int s = 0; s < data.shop_cnt; s++)
		{
			//得点計算
			int buf = hun[h].sinazoroe(s);
			if (buf >= max)
			{
				max = buf;
				top = s;
			}
		}
		point[top]++;
	}
	
	//賄賂効果
	for (int s = 0; s < data.shop_cnt; s++)
	{
		point[s] += shop[s].bukimatu_b;
		shop[s].bukimatu_b = 0;
	}

	//イベントモード効果
	if (data.mode == 0)
	{
		point[2] += 10;
		point[4] += 9;
	}

	max = 0;
	top = 0;

	for (int s = 0; s < data.shop_cnt; s++)
	{
		if (point[s] >= max)
		{
			max = point[s];
			top = s;
		}
	}

	return top;
}