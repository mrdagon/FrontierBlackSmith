#pragma once
#include "btb.h"

#define shou_mana(a)		mana.req_mp[S][MANA_B+1]+=a;mana.req_mp[S][MANA_B+2]-=a;mana.req_mp[S][MANA_B+3]-=a;mana.req_mp[S][MANA_B+4]-=a;mana.req_mp[S][MANA_B+5]-=a;mana.req_mp[S][MANA_B+6]-=a;mana.req_mp[S][MANA_B+7]-=a;
#define _MANA_CUL____________________________________________		if(AI==0){
#define _MANA_END____________________________________________			}

#define WhiteP int(100 - shop[S].b_w) 
#define BlackP int(shop[S].b_w)

//using namespace fbs;
#include <sstream>
int EVE_FUN::mana_ai(int S,int M){

	int AI = 1;
	int POINT = 0;

	switch(M){
		case 0:POINT =  mana_000(S,AI);break;
		case 1:POINT =  mana_001(S,AI);break;
		case 2:POINT =  mana_002(S,AI);break;
		case 3:POINT =  mana_003(S,AI);break;
		case 4:POINT =  mana_004(S,AI);break;
		case 5:POINT =  mana_005(S,AI);break;
		case 6:POINT =  mana_006(S,AI);break;
		case 7:POINT =  mana_007(S,AI);break;
		case 8:POINT =  mana_008(S,AI);break;
		case 9:POINT =  mana_009(S,AI);break;
		case 10:POINT =  mana_010(S,AI);break;
		case 11:POINT =  mana_011(S,AI);break;
		case 12:POINT =  mana_012(S,AI);break;
		case 13:POINT =  mana_013(S,AI);break;
		case 14:POINT =  mana_014(S,AI);break;
		case 15:POINT =  mana_015(S,AI);break;
		case 16:POINT =  mana_016(S,AI);break;
		case 17:POINT =  mana_017(S,AI);break;
		case 18:POINT =  mana_018(S,AI);break;
		case 19:POINT =  mana_019(S,AI);break;
		case 20:POINT =  mana_020(S,AI);break;
		case 21:POINT =  mana_021(S,AI);break;
		case 22:POINT =  mana_022(S,AI);break;
		case 23:POINT =  mana_023(S,AI);break;
		case 24:POINT =  mana_024(S,AI);break;
		case 25:POINT =  mana_025(S,AI);break;
		case 26:POINT =  mana_026(S,AI);break;
		case 27:POINT =  mana_027(S,AI);break;
		case 28:POINT =  mana_028(S,AI);break;
		case 29:POINT =  mana_029(S,AI);break;
		case 30:POINT =  mana_030(S,AI);break;
		case 31:POINT =  mana_031(S,AI);break;
		case 32:POINT =  mana_032(S,AI);break;
		case 33:POINT =  mana_033(S,AI);break;
		case 34:POINT =  mana_034(S,AI);break;
		case 35:POINT =  mana_035(S,AI);break;
		case 36:POINT =  mana_036(S,AI);break;
		case 37:POINT =  mana_037(S,AI);break;
		case 38:POINT =  mana_038(S,AI);break;
		case 39:POINT =  mana_039(S,AI);break;
		case 40:POINT =  mana_040(S,AI);break;
		case 41:POINT =  mana_041(S,AI);break;
		case 42:POINT =  mana_042(S,AI);break;
		case 43:POINT =  mana_043(S,AI);break;
		case 44:POINT =  mana_044(S,AI);break;
		case 45:POINT =  mana_045(S,AI);break;
		case 46:POINT =  mana_046(S,AI);break;
		case 47:POINT =  mana_047(S,AI);break;
		case 48:POINT =  mana_048(S,AI);break;
		case 49:POINT =  mana_049(S,AI);break;
		case 50:POINT =  mana_050(S,AI);break;
		case 51:POINT =  mana_051(S,AI);break;
		case 52:POINT =  mana_052(S,AI);break;
		case 53:POINT =  mana_053(S,AI);break;
		case 54:POINT =  mana_054(S,AI);break;
		case 55:POINT =  mana_055(S,AI);break;
		case 56:POINT =  mana_056(S,AI);break;
		case 57:POINT =  mana_057(S,AI);break;
		case 58:POINT =  mana_058(S,AI);break;
		case 59:POINT =  mana_059(S,AI);break;
		case 60:POINT =  mana_060(S,AI);break;
		case 61:POINT =  mana_061(S,AI);break;
		case 62:POINT =  mana_062(S,AI);break;
		case 63:POINT =  mana_063(S,AI);break;
		case 64:POINT =  mana_064(S,AI);break;
		case 65:POINT =  mana_065(S,AI);break;
		case 66:POINT =  mana_066(S,AI);break;
		case 67:POINT =  mana_067(S,AI);break;
		case 68:POINT =  mana_068(S,AI);break;
		case 69:POINT =  mana_069(S,AI);break;
		case 70:POINT =  mana_070(S,AI);break;
		case 71:POINT =  mana_071(S,AI);break;
		case 72:POINT =  mana_072(S,AI);break;
		case 73:POINT =  mana_073(S,AI);break;
		case 74:POINT =  mana_074(S,AI);break;
		case 75:POINT =  mana_075(S,AI);break;
		case 76:POINT =  mana_076(S,AI);break;
		case 77:POINT = mana_077(S,AI);break;
		case 78:POINT = mana_078(S,AI);break;
		case 79:POINT = mana_079(S,AI);break;
		case 80:POINT = mana_080(S,AI);break;
		case 81:POINT = mana_081(S,AI);break;
		case 82:POINT = mana_082(S,AI);break;
		case 83:POINT = mana_083(S,AI);break;
		case 84:POINT = mana_084(S,AI);break;
		case 85:POINT = mana_085(S,AI);break;
		case 86:POINT = mana_086(S,AI);break;
		case 87:POINT = mana_087(S,AI);break;
		case 88:POINT = mana_088(S,AI);break;
		case 89:POINT = mana_089(S,AI);break;
		case 90:POINT = mana_090(S,AI);break;
		case 91:POINT = mana_091(S,AI);break;
		case 92:POINT = mana_092(S,AI);break;
		case 93:POINT = mana_093(S,AI);break;
		case 94:POINT = mana_094(S,AI);break;
		case 95:POINT = mana_095(S,AI);break;
		case 96:POINT = mana_096(S,AI);break;
		case 97:POINT = mana_097(S,AI);break;
		case 98:POINT = mana_098(S,AI);break;
		case 99:POINT = mana_099(S,AI);break;
		case 100:POINT = mana_100(S,AI);break;
		case 101:POINT = mana_101(S,AI);break;
		case 102:POINT = mana_102(S,AI);break;
		case 103:POINT = mana_103(S,AI);break;
		case 104:POINT = mana_104(S,AI);break;
		case 105:POINT = mana_105(S,AI);break;
		case 106:POINT = mana_106(S,AI);break;
		case 107:POINT = mana_107(S,AI);break;
		case 108:POINT = mana_108(S,AI);break;
		case 109:POINT = mana_109(S,AI);break;
		case 110:POINT = mana_110(S,AI);break;
		case 111:POINT = mana_111(S,AI);break;
		case 112:POINT = mana_112(S,AI);break;
		case 113:POINT = mana_113(S,AI);break;
		case 114:POINT = mana_114(S,AI);break;
		case 115:POINT = mana_115(S,AI);break;
		case 116:POINT = mana_116(S,AI);break;
		case 117:POINT = mana_117(S,AI);break;
		case 118:POINT = mana_118(S,AI);break;
		case 119:POINT = mana_119(S,AI);break;
		case 120:POINT = mana_120(S,AI);break;
		case 121:POINT = mana_121(S,AI);break;
		case 122:POINT = mana_122(S,AI);break;
		case 123:POINT = mana_123(S,AI);break;
		case 124:POINT = mana_124(S,AI);break;
		case 125:POINT = mana_125(S,AI);break;
		case 126:POINT = mana_126(S,AI);break;
		case 127:POINT = mana_127(S,AI);break;
		case 128:POINT = mana_128(S,AI);break;
		case 129:POINT = mana_129(S,AI);break;
		case 130:POINT = mana_130(S,AI);break;
		case 131:POINT = mana_131(S,AI);break;
		case 132:POINT = mana_132(S,AI);break;
		case 133:POINT = mana_133(S,AI);break;
		case 134:POINT = mana_134(S,AI);break;
		case 135:POINT = mana_135(S,AI);break;
		case 136:POINT = mana_136(S,AI);break;
		case 137:POINT = mana_137(S,AI);break;
		case 138:POINT = mana_138(S,AI);break;
		case 139:POINT = mana_139(S,AI);break;
		case 140:POINT = mana_140(S,AI);break;
		case 141:POINT = mana_141(S,AI);break;
		case 142:POINT = mana_142(S,AI);break;
		case 143:POINT = mana_143(S,AI);break;
		case 144:POINT = mana_144(S,AI);break;
		case 145:POINT = mana_145(S,AI);break;
		case 146:POINT = mana_146(S,AI);break;
		case 147:POINT = mana_147(S,AI);break;
		case 148:POINT = mana_148(S,AI);break;
		case 149:POINT = mana_149(S,AI);break;
		case 150:POINT = mana_150(S,AI);break;
		case 151:POINT = mana_151(S,AI);break;
		case 152:POINT = mana_152(S,AI);break;
		case 153:POINT = mana_153(S,AI);break;
		case 154:POINT = mana_154(S,AI);break;
		case 155:POINT = mana_155(S,AI);break;
		case 156:POINT = mana_156(S,AI);break;
		case 157:POINT = mana_157(S,AI);break;
		case 158:POINT = mana_158(S,AI);break;
		case 159:POINT = mana_159(S,AI);break;
		case 160:POINT = mana_160(S,AI);break;
		case 161:POINT = mana_161(S,AI);break;
		case 162:POINT = mana_162(S,AI);break;
		case 163:POINT = mana_163(S,AI);break;
		case 164:POINT = mana_164(S,AI);break;
		case 165:POINT = mana_165(S,AI);break;
		case 166:POINT = mana_166(S,AI);break;
		case 167:POINT = mana_167(S,AI);break;
		case 168:POINT = mana_168(S,AI);break;
		case 169:POINT = mana_169(S,AI);break;
		case 170:POINT = mana_170(S,AI);break;
		case 171:POINT = mana_171(S,AI);break;
		case 172:POINT = mana_172(S,AI);break;
		case 173:POINT = mana_173(S,AI);break;
		case 174:POINT = mana_174(S,AI);break;
		case 175:POINT = mana_175(S,AI);break;
		case 176:POINT = mana_176(S,AI);break;
		case 177:POINT = mana_177(S,AI);break;
		case 178:POINT = mana_178(S,AI);break;
		case 179:POINT = mana_179(S,AI);break;
		case 180:POINT = mana_180(S,AI);break;
		case 181:POINT = mana_181(S,AI);break;
		case 182:POINT = mana_182(S,AI);break;
		case 183:POINT = mana_183(S,AI);break;
		case 184:POINT = mana_184(S,AI);break;
		case 185:POINT = mana_185(S,AI);break;
		case 186:POINT = mana_186(S,AI);break;
		case 187:POINT = mana_187(S,AI);break;
		case 188:POINT = mana_188(S,AI);break;
		case 189:POINT = mana_189(S,AI);break;
		case 190:POINT = mana_190(S,AI);break;
		case 191:POINT = mana_191(S,AI);break;
		case 192:POINT = mana_192(S,AI);break;
		case 193:POINT = mana_193(S,AI);break;
		case 194:POINT = mana_194(S,AI);break;
		case 195:POINT = mana_195(S,AI);break;
		case 196:POINT = mana_196(S,AI);break;
		case 197:POINT = mana_197(S,AI);break;
		case 198:POINT = mana_198(S,AI);break;
		case 199:POINT = mana_199(S,AI);break;
		case 200:POINT = mana_200(S,AI);break;
		case 201:POINT = mana_201(S,AI);break;
		case 202:POINT = mana_202(S,AI);break;
		case 203:POINT = mana_203(S,AI);break;
		case 204:POINT = mana_204(S,AI);break;
		case 205:POINT = mana_205(S,AI);break;
		case 206:POINT = mana_206(S,AI);break;
		case 207:POINT = mana_207(S,AI);break;
		case 208:POINT = mana_208(S,AI);break;
		case 209:POINT = mana_209(S,AI);break;
		case 210:POINT = mana_210(S,AI);break;
		case 211:POINT = mana_211(S,AI);break;
		case 212:POINT = mana_212(S,AI);break;
		case 213:POINT = mana_213(S,AI);break;
		case 214:POINT = mana_214(S,AI);break;
		case 215:POINT = mana_215(S,AI);break;
		case 216:POINT = mana_216(S,AI);break;
		case 217:POINT = mana_217(S,AI);break;
		case 218:POINT = mana_218(S,AI);break;
		case 219:POINT = mana_219(S,AI);break;
		case 220:POINT = mana_220(S,AI);break;
		case 221:POINT = mana_221(S,AI);break;
		case 222:POINT = mana_222(S,AI);break;
		case 223:POINT = mana_223(S,AI);break;
		case 224:POINT = mana_224(S,AI);break;
		case 225:POINT = mana_225(S,AI);break;
		case 226:POINT = mana_226(S,AI);break;
		case 227:POINT = mana_227(S,AI);break;
		case 228:POINT = mana_228(S,AI);break;
		case 229:POINT = mana_229(S,AI);break;
		case 230:POINT = mana_230(S,AI);break;
		case 231:POINT = mana_231(S,AI);break;
		case 232:POINT = mana_232(S,AI);break;
		case 233:POINT = mana_233(S,AI);break;
		case 234:POINT = mana_234(S,AI);break;
		case 235:POINT = mana_235(S,AI);break;
		case 236:POINT = mana_236(S,AI);break;
		case 237:POINT = mana_237(S,AI);break;
		case 238:POINT = mana_238(S,AI);break;
		case 239:POINT = mana_239(S,AI);break;
		case 240:POINT = mana_240(S,AI);break;
		case 241:POINT = mana_241(S,AI);break;
		case 242:POINT = mana_242(S,AI);break;
		case 243:POINT = mana_243(S,AI);break;
		case 244:POINT = mana_244(S,AI);break;
		case 245:POINT = mana_245(S,AI);break;
		case 246:POINT = mana_246(S,AI);break;
		case 247:POINT = mana_247(S,AI);break;
		case 248:POINT = mana_248(S,AI);break;
		case 249:POINT = mana_249(S,AI);break;
		case 250:POINT = mana_250(S,AI);break;
		case 251:POINT = mana_251(S,AI);break;
		case 252:POINT = mana_252(S,AI);break;
		case 253:POINT = mana_253(S,AI);break;
		case 254:POINT = mana_254(S,AI);break;
		case 255:POINT = mana_255(S,AI);break;
		case 256:POINT = mana_256(S,AI);break;
		case 257:POINT = mana_257(S,AI);break;
		case 258:POINT = mana_258(S,AI);break;
		case 259:POINT = mana_259(S,AI);break;
		case 260:POINT = mana_260(S,AI);break;
		case 261:POINT = mana_261(S,AI);break;
		case 262:POINT = mana_262(S,AI);break;
		case 263:POINT = mana_263(S,AI);break;
		case 264:POINT = mana_264(S,AI);break;
		case 265:POINT = mana_265(S,AI);break;
		case 266:POINT = mana_266(S,AI);break;
		case 267:POINT = mana_267(S,AI);break;
		case 268:POINT = mana_268(S,AI);break;
		case 269:POINT = mana_269(S,AI);break;
		case 270:POINT = mana_270(S,AI);break;
		case 271:POINT = mana_271(S,AI);break;
		case 272:POINT = mana_272(S,AI);break;
		case 273:POINT = mana_273(S,AI);break;
		case 274:POINT = mana_274(S,AI);break;
		case 275:POINT = mana_275(S,AI);break;
		case 276:POINT = mana_276(S,AI);break;
		case 277:POINT = mana_277(S,AI);break;
		case 278:POINT = mana_278(S,AI);break;
		case 279:POINT = mana_279(S,AI);break;
		case 280:POINT = mana_280(S,AI);break;
		case 281:POINT = mana_281(S,AI);break;
		case 282:POINT = mana_282(S,AI);break;
		case 283:POINT = mana_283(S,AI);break;
		case 284:POINT = mana_284(S,AI);break;
		case 285:POINT = mana_285(S,AI);break;
		case 286:POINT = mana_286(S,AI);break;
		case 287:POINT = mana_287(S,AI);break;
		case 288:POINT = mana_288(S,AI);break;
		case 289:POINT = mana_289(S,AI);break;
		case 290:POINT = mana_290(S,AI);break;
		case 291:POINT = mana_291(S,AI);break;
		case 292:POINT = mana_292(S,AI);break;
		case 293:POINT = mana_293(S,AI);break;
		case 294:POINT = mana_294(S,AI);break;
		case 295:POINT = mana_295(S,AI);break;
		case 296:POINT = mana_296(S,AI);break;
		case 297:POINT = mana_297(S,AI);break;
		case 298:POINT = mana_298(S,AI);break;
		case 299:POINT = mana_299(S,AI);break;
	}

	return POINT;
}
int EVE_FUN::mana_syori(int S,int M){
	
	if(shop[S].use_mana != M) return 0;//使用していない

	shop[S].mana_rest[M]--;				//残り使用回数-1
	shop[S].mana_cnt[M]++;				//累計使用回数
	int T = mana[M].type;
	double MP = shop[S].syou_mp[M] * shop[S].mana_b[T] / 100;
	shop[S].bumon_exp[T] += int(shop[S].syou_mp[M]*10);
	shop[S].bumon_exp[(T+1)%5] += int(shop[S].syou_mp[M]*2);//1/5
	shop[S].bumon_exp[(T+4)%5] += int(shop[S].syou_mp[M]*2);

	shop[S].n_mp -= MP;
	int SYOU_M = int(shop[S].syou_money[M]*shop[S].mana_gb[T]/100);
	if(M < 61 || M > 65){//株式買収系以外は日数で加算
		SYOU_M = SYOU_M * (1000 + data.day) / 10;
	}

	if(mana[M].b_w_d != -99999 ){//ブラック
		shop[S].bw_bonus += (double)mana[M].b_w_c/100;
	}else if(mana[M].b_w_u != 99999 ){//ホワイト
		shop[S].bw_bonus -= (double)mana[M].b_w_c/100;
	}

	shop[S].manege_mon[data.day/28] -= SYOU_M;//月経費に追加
	shop[S].money				    -= SYOU_M;//金消費
	shop[S].bw_bonus += mana[M].b_w_c;
	shop[S].use_mana = -1;

	EVE_FUN::Sin().mana_lvup(S,T);
	EVE_FUN::Sin().mana_lvup(S,(T+1)%5);
	EVE_FUN::Sin().mana_lvup(S,(T+4)%5);

	
	char str[64];
	sprintf_s(str,"「%s」を使用した",mana[M].name.c_str());
	logu.add(str,mana[M].type,S);
	if( S == P) sys.mana_total[M] ++;
	
	//開発条件解除
	for(int W=0;W<WEP_M;W++){
		if(wep[W].req_mana == M && shop[S].wep_cre[W] == -1){
			if(M >= 124 && M<=132 && shop[S].mana_cnt[M] < W%4) continue;
			shop[S].wep_cre[W] = 0;
			//開発リストに入るやつ
			switch(W){
				case 30:
				case 85:
				case 90:
				case 94:
				case 96:
				case 97:
				case 98:
				case 162:
				case 212:
				case 266:
				case 297:
				case 298:
				case 342:
				case 362:
				case 397:
				shop[S].wep_cre[W]=1;
				shop[S].wep_hday[W] = data.day;
				if(S==P){
					fun.list_pw(W);//リスト最後尾に追加
					char str[128];
					sprintf_s(str,"「%s」開発可!",wep[W].name.c_str());
					logu.add(str,1000+W,P);
				}
				break;	
			}		
		}
	}


	int AI = 0;

	switch(M){
		case 0:mana_000(S,AI);break;
		case 1:mana_001(S,AI);break;
		case 2:mana_002(S,AI);break;
		case 3:mana_003(S,AI);break;
		case 4:mana_004(S,AI);break;
		case 5:mana_005(S,AI);break;
		case 6:mana_006(S,AI);break;
		case 7:mana_007(S,AI);break;
		case 8:mana_008(S,AI);break;
		case 9:mana_009(S,AI);break;
		case 10:mana_010(S,AI);break;
		case 11:mana_011(S,AI);break;
		case 12:mana_012(S,AI);break;
		case 13:mana_013(S,AI);break;
		case 14:mana_014(S,AI);break;
		case 15:mana_015(S,AI);break;
		case 16:mana_016(S,AI);break;
		case 17:mana_017(S,AI);break;
		case 18:mana_018(S,AI);break;
		case 19:mana_019(S,AI);break;
		case 20:mana_020(S,AI);break;
		case 21:mana_021(S,AI);break;
		case 22:mana_022(S,AI);break;
		case 23:mana_023(S,AI);break;
		case 24:mana_024(S,AI);break;
		case 25:mana_025(S,AI);break;
		case 26:mana_026(S,AI);break;
		case 27:mana_027(S,AI);break;
		case 28:mana_028(S,AI);break;
		case 29:mana_029(S,AI);break;
		case 30:mana_030(S,AI);break;
		case 31:mana_031(S,AI);break;
		case 32:mana_032(S,AI);break;
		case 33:mana_033(S,AI);break;
		case 34:mana_034(S,AI);break;
		case 35:mana_035(S,AI);break;
		case 36:mana_036(S,AI);break;
		case 37:mana_037(S,AI);break;
		case 38:mana_038(S,AI);break;
		case 39:mana_039(S,AI);break;
		case 40:mana_040(S,AI);break;
		case 41:mana_041(S,AI);break;
		case 42:mana_042(S,AI);break;
		case 43:mana_043(S,AI);break;
		case 44:mana_044(S,AI);break;
		case 45:mana_045(S,AI);break;
		case 46:mana_046(S,AI);break;
		case 47:mana_047(S,AI);break;
		case 48:mana_048(S,AI);break;
		case 49:mana_049(S,AI);break;
		case 50:mana_050(S,AI);break;
		case 51:mana_051(S,AI);break;
		case 52:mana_052(S,AI);break;
		case 53:mana_053(S,AI);break;
		case 54:mana_054(S,AI);break;
		case 55:mana_055(S,AI);break;
		case 56:mana_056(S,AI);break;
		case 57:mana_057(S,AI);break;
		case 58:mana_058(S,AI);break;
		case 59:mana_059(S,AI);break;
		case 60:mana_060(S,AI);break;
		case 61:mana_061(S,AI);break;
		case 62:mana_062(S,AI);break;
		case 63:mana_063(S,AI);break;
		case 64:mana_064(S,AI);break;
		case 65:mana_065(S,AI);break;
		case 66:mana_066(S,AI);break;
		case 67:mana_067(S,AI);break;
		case 68:mana_068(S,AI);break;
		case 69:mana_069(S,AI);break;
		case 70:mana_070(S,AI);break;
		case 71:mana_071(S,AI);break;
		case 72:mana_072(S,AI);break;
		case 73:mana_073(S,AI);break;
		case 74:mana_074(S,AI);break;
		case 75:mana_075(S,AI);break;
		case 76:mana_076(S,AI);break;
		case 77:mana_077(S,AI);break;
		case 78:mana_078(S,AI);break;
		case 79:mana_079(S,AI);break;
		case 80:mana_080(S,AI);break;
		case 81:mana_081(S,AI);break;
		case 82:mana_082(S,AI);break;
		case 83:mana_083(S,AI);break;
		case 84:mana_084(S,AI);break;
		case 85:mana_085(S,AI);break;
		case 86:mana_086(S,AI);break;
		case 87:mana_087(S,AI);break;
		case 88:mana_088(S,AI);break;
		case 89:mana_089(S,AI);break;
		case 90:mana_090(S,AI);break;
		case 91:mana_091(S,AI);break;
		case 92:mana_092(S,AI);break;
		case 93:mana_093(S,AI);break;
		case 94:mana_094(S,AI);break;
		case 95:mana_095(S,AI);break;
		case 96:mana_096(S,AI);break;
		case 97:mana_097(S,AI);break;
		case 98:mana_098(S,AI);break;
		case 99:mana_099(S,AI);break;
		case 100:mana_100(S,AI);break;
		case 101:mana_101(S,AI);break;
		case 102:mana_102(S,AI);break;
		case 103:mana_103(S,AI);break;
		case 104:mana_104(S,AI);break;
		case 105:mana_105(S,AI);break;
		case 106:mana_106(S,AI);break;
		case 107:mana_107(S,AI);break;
		case 108:mana_108(S,AI);break;
		case 109:mana_109(S,AI);break;
		case 110:mana_110(S,AI);break;
		case 111:mana_111(S,AI);break;
		case 112:mana_112(S,AI);break;
		case 113:mana_113(S,AI);break;
		case 114:mana_114(S,AI);break;
		case 115:mana_115(S,AI);break;
		case 116:mana_116(S,AI);break;
		case 117:mana_117(S,AI);break;
		case 118:mana_118(S,AI);break;
		case 119:mana_119(S,AI);break;
		case 120:mana_120(S,AI);break;
		case 121:mana_121(S,AI);break;
		case 122:mana_122(S,AI);break;
		case 123:mana_123(S,AI);break;
		case 124:mana_124(S,AI);break;
		case 125:mana_125(S,AI);break;
		case 126:mana_126(S,AI);break;
		case 127:mana_127(S,AI);break;
		case 128:mana_128(S,AI);break;
		case 129:mana_129(S,AI);break;
		case 130:mana_130(S,AI);break;
		case 131:mana_131(S,AI);break;
		case 132:mana_132(S,AI);break;
		case 133:mana_133(S,AI);break;
		case 134:mana_134(S,AI);break;
		case 135:mana_135(S,AI);break;
		case 136:mana_136(S,AI);break;
		case 137:mana_137(S,AI);break;
		case 138:mana_138(S,AI);break;
		case 139:mana_139(S,AI);break;
		case 140:mana_140(S,AI);break;
		case 141:mana_141(S,AI);break;
		case 142:mana_142(S,AI);break;
		case 143:mana_143(S,AI);break;
		case 144:mana_144(S,AI);break;
		case 145:mana_145(S,AI);break;
		case 146:mana_146(S,AI);break;
		case 147:mana_147(S,AI);break;
		case 148:mana_148(S,AI);break;
		case 149:mana_149(S,AI);break;
		case 150:mana_150(S,AI);break;
		case 151:mana_151(S,AI);break;
		case 152:mana_152(S,AI);break;
		case 153:mana_153(S,AI);break;
		case 154:mana_154(S,AI);break;
		case 155:mana_155(S,AI);break;
		case 156:mana_156(S,AI);break;
		case 157:mana_157(S,AI);break;
		case 158:mana_158(S,AI);break;
		case 159:mana_159(S,AI);break;
		case 160:mana_160(S,AI);break;
		case 161:mana_161(S,AI);break;
		case 162:mana_162(S,AI);break;
		case 163:mana_163(S,AI);break;
		case 164:mana_164(S,AI);break;
		case 165:mana_165(S,AI);break;
		case 166:mana_166(S,AI);break;
		case 167:mana_167(S,AI);break;
		case 168:mana_168(S,AI);break;
		case 169:mana_169(S,AI);break;
		case 170:mana_170(S,AI);break;
		case 171:mana_171(S,AI);break;
		case 172:mana_172(S,AI);break;
		case 173:mana_173(S,AI);break;
		case 174:mana_174(S,AI);break;
		case 175:mana_175(S,AI);break;
		case 176:mana_176(S,AI);break;
		case 177:mana_177(S,AI);break;
		case 178:mana_178(S,AI);break;
		case 179:mana_179(S,AI);break;
		case 180:mana_180(S,AI);break;
		case 181:mana_181(S,AI);break;
		case 182:mana_182(S,AI);break;
		case 183:mana_183(S,AI);break;
		case 184:mana_184(S,AI);break;
		case 185:mana_185(S,AI);break;
		case 186:mana_186(S,AI);break;
		case 187:mana_187(S,AI);break;
		case 188:mana_188(S,AI);break;
		case 189:mana_189(S,AI);break;
		case 190:mana_190(S,AI);break;
		case 191:mana_191(S,AI);break;
		case 192:mana_192(S,AI);break;
		case 193:mana_193(S,AI);break;
		case 194:mana_194(S,AI);break;
		case 195:mana_195(S,AI);break;
		case 196:mana_196(S,AI);break;
		case 197:mana_197(S,AI);break;
		case 198:mana_198(S,AI);break;
		case 199:mana_199(S,AI);break;

		case 200:mana_200(S,AI);break;
		case 201:mana_201(S,AI);break;
		case 202:mana_202(S,AI);break;
		case 203:mana_203(S,AI);break;
		case 204:mana_204(S,AI);break;
		case 205:mana_205(S,AI);break;
		case 206:mana_206(S,AI);break;
		case 207:mana_207(S,AI);break;
		case 208:mana_208(S,AI);break;
		case 209:mana_209(S,AI);break;
		case 210:mana_210(S,AI);break;
		case 211:mana_211(S,AI);break;
		case 212:mana_212(S,AI);break;
		case 213:mana_213(S,AI);break;
		case 214:mana_214(S,AI);break;
		case 215:mana_215(S,AI);break;
		case 216:mana_216(S,AI);break;
		case 217:mana_217(S,AI);break;
		case 218:mana_218(S,AI);break;
		case 219:mana_219(S,AI);break;
		case 220:mana_220(S,AI);break;
		case 221:mana_221(S,AI);break;
		case 222:mana_222(S,AI);break;
		case 223:mana_223(S,AI);break;
		case 224:mana_224(S,AI);break;
		case 225:mana_225(S,AI);break;
		case 226:mana_226(S,AI);break;
		case 227:mana_227(S,AI);break;
		case 228:mana_228(S,AI);break;
		case 229:mana_229(S,AI);break;
		case 230:mana_230(S,AI);break;
		case 231:mana_231(S,AI);break;
		case 232:mana_232(S,AI);break;
		case 233:mana_233(S,AI);break;
		case 234:mana_234(S,AI);break;
		case 235:mana_235(S,AI);break;
		case 236:mana_236(S,AI);break;
		case 237:mana_237(S,AI);break;
		case 238:mana_238(S,AI);break;
		case 239:mana_239(S,AI);break;
		case 240:mana_240(S,AI);break;
		case 241:mana_241(S,AI);break;
		case 242:mana_242(S,AI);break;
		case 243:mana_243(S,AI);break;
		case 244:mana_244(S,AI);break;
		case 245:mana_245(S,AI);break;
		case 246:mana_246(S,AI);break;
		case 247:mana_247(S,AI);break;
		case 248:mana_248(S,AI);break;
		case 249:mana_249(S,AI);break;
		case 250:mana_250(S,AI);break;
		case 251:mana_251(S,AI);break;
		case 252:mana_252(S,AI);break;
		case 253:mana_253(S,AI);break;
		case 254:mana_254(S,AI);break;
		case 255:mana_255(S,AI);break;
		case 256:mana_256(S,AI);break;
		case 257:mana_257(S,AI);break;
		case 258:mana_258(S,AI);break;
		case 259:mana_259(S,AI);break;
		case 260:mana_260(S,AI);break;
		case 261:mana_261(S,AI);break;
		case 262:mana_262(S,AI);break;
		case 263:mana_263(S,AI);break;
		case 264:mana_264(S,AI);break;
		case 265:mana_265(S,AI);break;
		case 266:mana_266(S,AI);break;
		case 267:mana_267(S,AI);break;
		case 268:mana_268(S,AI);break;
		case 269:mana_269(S,AI);break;
		case 270:mana_270(S,AI);break;
		case 271:mana_271(S,AI);break;
		case 272:mana_272(S,AI);break;
		case 273:mana_273(S,AI);break;
		case 274:mana_274(S,AI);break;
		case 275:mana_275(S,AI);break;
		case 276:mana_276(S,AI);break;
		case 277:mana_277(S,AI);break;
		case 278:mana_278(S,AI);break;
		case 279:mana_279(S,AI);break;
		case 280:mana_280(S,AI);break;
		case 281:mana_281(S,AI);break;
		case 282:mana_282(S,AI);break;
		case 283:mana_283(S,AI);break;
		case 284:mana_284(S,AI);break;
		case 285:mana_285(S,AI);break;
		case 286:mana_286(S,AI);break;
		case 287:mana_287(S,AI);break;
		case 288:mana_288(S,AI);break;
		case 289:mana_289(S,AI);break;
		case 290:mana_290(S,AI);break;
		case 291:mana_291(S,AI);break;
		case 292:mana_292(S,AI);break;
		case 293:mana_293(S,AI);break;
		case 294:mana_294(S,AI);break;
		case 295:mana_295(S,AI);break;
		case 296:mana_296(S,AI);break;
		case 297:mana_297(S,AI);break;
		case 298:mana_298(S,AI);break;
		case 299:mana_299(S,AI);break;
	}

	return 1;
}
int EVE_FUN::mana_lvup(int S,int T){

	if(shop[S].bumon_lv[T] == 0) return 1;

	int REQ = shop[S].bumon_lv[T] * shop[S].bumon_lv[T] * 100 + 400;
	if (shop[S].bumon_lv[T] > 5)
	{
		REQ = 4000;
	}

	if(shop[S].bumon_exp[T] >= REQ){//部門レベルアップ
		shop[S].p_mp+=0.1;//回復量＋0.1
		shop[S].bumon_lv[T]++;
		shop[S].bumon_exp[T] -= REQ;
		switch(T){
			case 0://経営
				shop[S].mensetu_lv+=5;
				break;
			case 1://財務
				shop[S].kabu_buy+=20;
				break;
			case 2://工事
				if(shop[S].bumon_lv[T]%2 == 0)shop[S].mana_rest[121]++;
				shop[S].souko_max+=200;
				break;
			case 3://開発
				shop[S].hirameki_b[0]+=5;
				shop[S].hirameki_b[1]+=5;
				shop[S].hirameki_b[2]+=5;
				shop[S].hirameki_b[3]+=5;
			break;
			case 4://宣伝
				shop[S].senden_b+=5;
			break;
		}
	}

	return 1;
}
int EVE_FUN::mana_000(/*◆経営*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_001(/*休日増加*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].yasumi_max += 2;
		shop[S].mana_rest[2]++;
		shop[S].p_mp += 0.2;
	_MANA_END____________________________________________

	//基本的に使わない
	return 0;
}
int EVE_FUN::mana_002(/*休日減少*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].yasumi_max -= 2;
		shop[S].mana_rest[1]++;
		shop[S].p_mp -= 0.2;
	_MANA_END____________________________________________

	//基本的に使わない
	return 0;
}
int EVE_FUN::mana_003(/*残業制度*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].zangyou += 3;
	_MANA_END____________________________________________

	//基本的に使わない
	return 0;
}
int EVE_FUN::mana_004(/*ノー残業*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].zangyou = 54;
		shop[S].mana_rest[3] = 0;
		shop[S].mana_cnt[3]  = 0;
	_MANA_END____________________________________________

	return WhiteP * 100;
}
int EVE_FUN::mana_005(/*経営のコツ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].mana_b[0] -= 20;
		shop[S].mana_rest[6] = 0;
		shop[S].mana_rest[7] = 0;
		shop[S].mana_rest[8] = 0;
		shop[S].mana_rest[9] = 0;
	_MANA_END____________________________________________

	//優先的に使う
	return 10000 + GetRand(10000);
}
int EVE_FUN::mana_006(/*財務のコツ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].mana_b[1] -= 20;
		shop[S].mana_rest[5] = 0;
		shop[S].mana_rest[7] = 0;
		shop[S].mana_rest[8] = 0;
		shop[S].mana_rest[9] = 0;
	_MANA_END____________________________________________

	//優先的に使う
	return 10000 + GetRand(10000);
}
int EVE_FUN::mana_007(/*工事のコツ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].mana_b[2] -= 20;
		shop[S].mana_rest[5] = 0;
		shop[S].mana_rest[6] = 0;
		shop[S].mana_rest[8] = 0;
		shop[S].mana_rest[9] = 0;
	_MANA_END____________________________________________

	//優先的に使う
	return 10000 + GetRand(10000);
}
int EVE_FUN::mana_008(/*開発のコツ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].mana_b[3] -= 20;
		shop[S].mana_rest[5] = 0;
		shop[S].mana_rest[6] = 0;
		shop[S].mana_rest[7] = 0;
		shop[S].mana_rest[9] = 0;
	_MANA_END____________________________________________

	//優先的に使う
	return 10000 + GetRand(10000);
}
int EVE_FUN::mana_009(/*宣伝のコツ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].mana_b[4] -= 20;
		shop[S].mana_rest[5] = 0;
		shop[S].mana_rest[6] = 0;
		shop[S].mana_rest[7] = 0;
		shop[S].mana_rest[8] = 0;
	_MANA_END____________________________________________

	//優先的に使う
	return 10000 + GetRand(10000);
}
int EVE_FUN::mana_010(/*暗黒の儀式*/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int E=0;E<EMP_M;E++){
			if(emp[E].shop_n == S && emp[E].now_job == 1 && emp[E].pb_rest < 0) shop[S].n_mp += 10;
		}
	_MANA_END____________________________________________

	//使わない
	return 0;
}
int EVE_FUN::mana_011(/*白金の儀式*/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int E=0;E<EMP_M;E++){
			if(emp[E].shop_n == S && emp[E].now_job == 1 && emp[E].pb_rest > 0) shop[S].n_mp += 10;
		}
	_MANA_END____________________________________________

	//使わない
	return 0;
}
int EVE_FUN::mana_012(/*定休日廃止*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].teikyuu = -1;
	_MANA_END____________________________________________

	//いつか使う
	return int(data.day * 25 + shop[S].b_w * 100);
}
int EVE_FUN::mana_013(/*労働者の結束*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].mp_ninnzuu += 5;
		shop[S].mana_rest[14] =1;
	_MANA_END____________________________________________

	return WhiteP * 100;
}
int EVE_FUN::mana_014(/*組合の掌握*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return BlackP * 100;
}
int EVE_FUN::mana_015(/*研修の確立*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].exp_bs += 100;
	_MANA_END____________________________________________

	return GetRand(5000);
}
int EVE_FUN::mana_016(/*五十六メソッド*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].exp_b += 50;
	_MANA_END____________________________________________

	//使わない
	return 0;
}
int EVE_FUN::mana_017(/*新卒の保護*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kaihuku_bs -= 20;
	_MANA_END____________________________________________

	//使わない
	return 0;
}
int EVE_FUN::mana_018(/*適材適所*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return data.nando * 4000;
}
int EVE_FUN::mana_019(/*スクラム*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	//使わない
	return 0;
}
int EVE_FUN::mana_020(/*職人急募*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kyuubo = 2;
	_MANA_END____________________________________________

	//たまに使う
	return GetRand(2000);
}
int EVE_FUN::mana_021(/*店員急募*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kyuubo = 1;
	_MANA_END____________________________________________

	//たまに使う
	return GetRand(2000);
}
int EVE_FUN::mana_022(/*新卒採用強化*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].mana_rest[23]= 0;
	_MANA_END____________________________________________

	//使わない
	return 0;
}
int EVE_FUN::mana_023(/*中途採用強化*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].mana_rest[22]= 0;
	_MANA_END____________________________________________

	//使わない
	return 0;
}
int EVE_FUN::mana_024(/*入念な面接*/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job == 0 && emp[E].shop_n == S){
				emp[E].mensetu[0][S] = 1;
				emp[E].mensetu[1][S] = 1;
				emp[E].mensetu[2][S] = 1;
				emp[E].mensetu[3][S] = 1;
				emp[E].mensetu[4][S] = 1;
			}
		}	
	_MANA_END____________________________________________

	//使わない
	return 0;
}
int EVE_FUN::mana_025(/*実技試験*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].mensetu_lv+=5;
		if(shop[S].mana_cnt[25]<=0) shop[S].mana_cnt[26] = 3;
	_MANA_END____________________________________________

	return 1000 + GetRand(1000);
}
int EVE_FUN::mana_026(/*筆記試験*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].mensetu_lv+=7;
	_MANA_END____________________________________________

	return 1000 + GetRand(1000);
}
int EVE_FUN::mana_027(/*一芸採用*/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int E=0;E<EMP_M;E++){
			emp[E].mensetu[4][S] = 1;
		}			
	_MANA_END____________________________________________

	return 3000 + GetRand(1000);
}
int EVE_FUN::mana_028(/*魔獣の排除*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].monster_b -= 75;
	_MANA_END____________________________________________

	return 3000 + GetRand(1000);
}
int EVE_FUN::mana_029(/*マイクロマネジ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].syakai_b += 20;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_030(/*黄金の精神*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 6000 + GetRand(1000);
}
int EVE_FUN::mana_031(/*黄金の意志*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 6000 + GetRand(1000);
}
int EVE_FUN::mana_032(/*のびのび*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 6000 + GetRand(1000);
}
int EVE_FUN::mana_033(/*安全第一*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kega_b -= 50;
	_MANA_END____________________________________________

	return 7000 + GetRand(1000);
}
int EVE_FUN::mana_034(/*高まる体力*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].hp_up_b += 20;
		shop[S].mana_rest[35] = 0;
		shop[S].mana_rest[36] = 0;
	_MANA_END____________________________________________

	return 7000 + GetRand(1000);
}
int EVE_FUN::mana_035(/*高まる技力*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kai_up_b += 20;
		shop[S].sek_up_b += 20;
		shop[S].mana_rest[34] = 0;
		shop[S].mana_rest[36] = 0;
	_MANA_END____________________________________________

	return 7700 + GetRand(1000);
}
int EVE_FUN::mana_036(/*高まる心力*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].sei_up_b += 30;
		shop[S].kya_up_b += 30;
		shop[S].mana_rest[34] = 0;
		shop[S].mana_rest[35] = 0;
	_MANA_END____________________________________________

	return 7700 + GetRand(1000);
}
int EVE_FUN::mana_037(/*リエンジニアリング*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].p_mp += 2;
	_MANA_END____________________________________________

	return 8000;
}
int EVE_FUN::mana_038(/*経営理念*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].p_mp += 1;
	_MANA_END____________________________________________

	return 6000;
}
int EVE_FUN::mana_039(/*愛社精神力*/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job == 1 && emp[E].shop_n == S){
				emp[E].hp       += 25;
				emp[E].sun	    -= 25;
				emp[E].tension  += 25;
			}
		}
		shop[S].holiday += 1;
	_MANA_END____________________________________________

	return BlackP * 100;
}
int EVE_FUN::mana_040(/*お花見*/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job == 1 && emp[E].shop_n == S){
				emp[E].hp_gain(25);
				emp[E].sun	    -= 10;
				emp[E].tension  += 10;
			}
		}
		shop[S].holiday += 1;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_041(/*夏休み*/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job == 1 && emp[E].shop_n == S){
				emp[E].hp_gain(25);
				emp[E].sun	    -= 25;
				emp[E].tension  += 25;
			}
		}
		shop[S].holiday += 5;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_042(/*お月見*/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job == 1 && emp[E].shop_n == S){
				emp[E].hp_gain(25);
				emp[E].sun	    -= 10;
				emp[E].tension  += 10;
			}
		}
		shop[S].holiday += 1;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_043(/*新年会*/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int E=0;E<EMP_M;E++){
			if(emp[E].now_job == 1 && emp[E].shop_n == S){
				emp[E].hp_gain(25);
				emp[E].sun	    -= 10;
				emp[E].tension  += 10;
			}
		}
		shop[S].holiday += 1;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_044(/*イベント大好き*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_045(/*武器にケーション*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 3000 + GetRand(1000);
}
int EVE_FUN::mana_046(/*Ex能力開発*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].sk_pup += 5+shop[S].mana_cnt[M_KAKU]*5;
	_MANA_END____________________________________________

	return 3000 + GetRand(1000);
}
int EVE_FUN::mana_047(/*短所を長所に*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].sk_rup += 5+shop[S].mana_cnt[M_KAKU]*5;
	_MANA_END____________________________________________

	return 3000 + GetRand(1000);
}
int EVE_FUN::mana_048(/*凡人の才覚*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].sk_qup += 5+shop[S].mana_cnt[M_KAKU]*5;
	_MANA_END____________________________________________

	return 3000 + GetRand(1000);
}
int EVE_FUN::mana_049(/*覚醒への手順書*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].sk_qup *= 2;
		shop[S].sk_rup *= 2;
		shop[S].sk_pup *= 2;
	_MANA_END____________________________________________

	return 3000 + GetRand(1000);
}
int EVE_FUN::mana_050(/*漆黒の眼差し*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].jisyoku_b /= 4;
	_MANA_END____________________________________________

	return (BlackP - 50) * 300;
}
int EVE_FUN::mana_051(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_052(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_053(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_054(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_055(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_056(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_057(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_058(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_059(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_060(/*◆財務・経理*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_061(/*株式買収・自社*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kabu_max -= shop[S].kabu_buy;
		shop[S].kabu_price  += shop[S].kabu_price * shop[S].kabu_buy / shop[S].kabu_max;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_062(/*株式買収・商会*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kabu_cnt[1] += shop[S].kabu_buy;
		data.kabu_price[1] += data.kabu_price[1] * shop[S].kabu_buy / data.kabu_cnt[1];

        int count = 0;
        for(int i=0;i<5;++i)
        {
            count += shop[i].kabu_cnt[1];
        }

        data.kabu_cnt[1] = max(data.kabu_cnt[1],count);


	_MANA_END____________________________________________

	return GetRand(1000) - (int)data.kabu_price[1] + shop[S].kabu_cnt[1] * 100;
}
int EVE_FUN::mana_063(/*株式買収・鉱山*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kabu_cnt[2] += shop[S].kabu_buy;
		data.kabu_price[2] += data.kabu_price[2] * shop[S].kabu_buy / data.kabu_cnt[2];

        int count = 0;
        for(int i=0;i<5;++i)
        {
            count += shop[i].kabu_cnt[2];
        }

        data.kabu_cnt[2] = max(data.kabu_cnt[2],count);


	_MANA_END____________________________________________

	return GetRand(1000) - (int)data.kabu_price[2] + shop[S].kabu_cnt[2] * 100;
}
int EVE_FUN::mana_064(/*株式買収・発明*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kabu_cnt[3] += shop[S].kabu_buy;
		data.kabu_price[3] += data.kabu_price[3] * shop[S].kabu_buy / data.kabu_cnt[3];

        int count = 0;
        for(int i=0;i<5;++i)
        {
            count += shop[i].kabu_cnt[3];
        }

        data.kabu_cnt[3] = max(data.kabu_cnt[3],count);


	_MANA_END____________________________________________

	return GetRand(1000) - (int)data.kabu_price[3] + shop[S].kabu_cnt[3] * 100;
}
int EVE_FUN::mana_065(/*株式買収・新聞*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kabu_cnt[4] += shop[S].kabu_buy;
		data.kabu_price[4] += data.kabu_price[4] * shop[S].kabu_buy / data.kabu_cnt[4];

        int count = 0;
        for(int i=0;i<5;++i)
        {
            count += shop[i].kabu_cnt[4];
        }

        data.kabu_cnt[4] = max(data.kabu_cnt[4],count);

	_MANA_END____________________________________________

	return GetRand(1000) - (int)data.kabu_price[4] + shop[S].kabu_cnt[4] * 100;
}
int EVE_FUN::mana_066(/*デイトレ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kabu_buy += 10;
	_MANA_END____________________________________________

	return GetRand(1000);
}
int EVE_FUN::mana_067(/*カイゼン手当*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].hirameki_b[0] += 20;
		shop[S].hirameki_b[1] += 20;
		shop[S].hirameki_b[2] += 20;
		shop[S].hirameki_b[3] += 20;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_068(/*増えまくる鉱山*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[0].nougu_up = 5;
		shop[1].nougu_up = 5;
		shop[2].nougu_up = 5;
		shop[3].nougu_up = 5;
		shop[4].nougu_up = 5;
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_069(/*マインせんべい*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].nougu_req += 15;
	_MANA_END____________________________________________

	if (data.mode == 7) return 20000;
	return 1;
}
int EVE_FUN::mana_070(/*ボーナス制*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return (WhiteP - 50) * 200;
}
int EVE_FUN::mana_071(/*増資*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kabu_max	+= shop[S].kabu_buy;
		shop[S].kabu_price  -= shop[S].kabu_price * shop[S].kabu_buy / shop[S].kabu_max;
        shop[S].money       += shop[S].kabu_price * shop[S].kabu_buy;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_072(/*解雇手当*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return (WhiteP - 50) * 160;
}
int EVE_FUN::mana_073(/*退職金積み立て*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kyuuryou_b -= 5;
	_MANA_END____________________________________________

	return (WhiteP - 50) * 150;
}
int EVE_FUN::mana_074(/*財テク*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].risoku_rate /= 2;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_075(/*銀行まんじゅう*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].risoku_rate /= 2;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_076(/*ハイパー積み立て*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].risi_rate *= 2;
	_MANA_END____________________________________________

	return int(shop[S].money / 10000);
}
int EVE_FUN::mana_077(/*持ち株制度*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return (BlackP - 50 )* 200;
}
int EVE_FUN::mana_078(/*非正規雇用*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return (BlackP - 50) * 220;
}
int EVE_FUN::mana_079(/*てんびき!*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kyuuryou_b -= 10;
		shop[S].mana_rest[80]++;
	_MANA_END____________________________________________

	return (BlackP - 50) * 450;
}
int EVE_FUN::mana_080(/*てんびき!!*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kyuuryou_b -= 10;
		shop[S].mana_rest[81]++;
	_MANA_END____________________________________________

	return (BlackP - 50) * 400;
}
int EVE_FUN::mana_081(/*てんびき!!!*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kyuuryou_b -= 10;
	_MANA_END____________________________________________

	return (BlackP - 50) * 350;
}
int EVE_FUN::mana_082(/*現物支給*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].nougu_req += shop[S].emp_cnt * 2;
	_MANA_END____________________________________________

	if (data.mode == 7) return 20000;
	return 1;
}
int EVE_FUN::mana_083(/*空間活用*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_084(/*コスト削減*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].cost_b -= 20;
		shop[S].atk_b  -= 10;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_085(/*サビザン*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return (BlackP - 50) * 150;
}
int EVE_FUN::mana_086(/*マトックプリン*/int S,int AI){
	
	_MANA_CUL____________________________________________
		wep[NOU_NO].price += 100;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_087(/*工夫*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].mana_gb[2] -= 20;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_088(/*経費削減*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].mana_gb[4] -= 20;
	_MANA_END____________________________________________

	return 10000;
}
int EVE_FUN::mana_089(/*あふれるサンプル*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_090(/*武器屋祭り飴*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].bukimatu_b +=100;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_091(/*つるはしケーキ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].turumatu_b +=100;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_092(/*タックスドーナツ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].tax_b -= 10;
	_MANA_END____________________________________________

	return (BlackP - 50) * 250;
}
int EVE_FUN::mana_093(/*株売却・商会*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kabu_cnt[1] -= shop[S].kabu_buy;
		shop[S].money += data.kabu_price[1] * shop[S].kabu_buy;
		data.kabu_price[1] -= data.kabu_price[1] * shop[S].kabu_buy / data.kabu_cnt[1];
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_094(/*株売却・鉱山*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kabu_cnt[2] -= shop[S].kabu_buy;
		shop[S].money += data.kabu_price[2] * shop[S].kabu_buy;
		data.kabu_price[2] -= data.kabu_price[2] * shop[S].kabu_buy / data.kabu_cnt[2];
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_095(/*株売却・発明*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kabu_cnt[3] -= shop[S].kabu_buy;
		shop[S].money += data.kabu_price[3] * shop[S].kabu_buy;
		data.kabu_price[3] -= data.kabu_price[3] * shop[S].kabu_buy / data.kabu_cnt[3];
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_096(/*株売却・新聞*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kabu_cnt[4] -= shop[S].kabu_buy;
		shop[S].money += data.kabu_price[4] * shop[S].kabu_buy;
		data.kabu_price[4] -= data.kabu_price[4] * shop[S].kabu_buy / data.kabu_cnt[4];
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_097(/*資金繰り*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].money+= 100000;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_098(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_099(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_100(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_101(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_102(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_103(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_104(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_105(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_106(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_107(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_108(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_109(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_110(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_111(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_112(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_113(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_114(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_115(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_116(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_117(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_118(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_119(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_120(/*◆工事*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_121(/*店舗拡大*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[121]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 5;//投資額の２倍
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].size++;
		shop[S].seizou_b   += 5;
		shop[S].kaihatu_b  += 5;
		shop[S].sekkyaku_b += 5;
		shop[S].sabaki_b   += 5;
		shop[S].kouji = 108;
        
		for(int i=0;i<12;i++)
        {
			shop[S].wep_sb[i%4][i/4]+=2;
		}
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return GetRand(1000);
}
int EVE_FUN::mana_122(/*倉庫拡大*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].souko_max  += 200;
	_MANA_END____________________________________________

	return 1000 - data.day - shop[S].souko_max;
}
int EVE_FUN::mana_123(/*工房リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[123]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 10;
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].seizou_b += 5;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF] * 2;
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return GetRand(1000);
}
int EVE_FUN::mana_124(/*厨房リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[124]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 10;
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].kaihuku_b += 5;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF] * 2;
		shop[S].syou_money[124]+=25;
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return  GetRand(1000);
}
int EVE_FUN::mana_125(/*内装リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[125]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 10;
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].sekkyaku_b += 5;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF] * 2;
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return  GetRand(1000);
}
int EVE_FUN::mana_126(/*研究室リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[126]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 10;
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].kaihatu_b += 5;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF] * 2;
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return  GetRand(1000);
}
int EVE_FUN::mana_127(/*レジリフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[127]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 10;
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].sabaki_b += 5;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF] * 2;
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return  GetRand(1000);
}
int EVE_FUN::mana_128(/*ごらく室リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[128]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 10;
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].stress_b += 5;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF] * 2;
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return  GetRand(1000);
}
int EVE_FUN::mana_129(/*看板リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[129]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 10;
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].senden_b += 5;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF] * 2;
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return  GetRand(1000);
}
int EVE_FUN::mana_130(/*礼拝堂リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[130]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 10;
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].syakai_b += 10;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF] * 2;
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return  GetRand(500);
}
int EVE_FUN::mana_131(/*資料室リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[131]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 10;
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].exp_b += 5;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF] * 2;
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return GetRand(1000);
}
int EVE_FUN::mana_132(/*温泉リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[132]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 10;
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].yaruki_b += 10;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF] * 2;
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return GetRand(1000);
}
int EVE_FUN::mana_133(/*社長室リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[133]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 10;
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].p_mp += 0.1;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF] * 2;
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return GetRand(1000);
}
int EVE_FUN::mana_134(/*一夜リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1000 + GetRand(1000);
}
int EVE_FUN::mana_135(/*匠リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1000 + GetRand(1000);
}
int EVE_FUN::mana_136(/*宿舎*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF];
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return (BlackP-50) * 50;
}
int EVE_FUN::mana_137(/*柵*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF];
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return (BlackP - 50) * 30;
}
int EVE_FUN::mana_138(/*金色の社長像*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].seizou_b   += 10;
		shop[S].kaihatu_b  += 10;
		shop[S].sekkyaku_b += 10;
		shop[S].sabaki_b   += 10;
	_MANA_END____________________________________________

	return 1000;
}
int EVE_FUN::mana_139(/*ショーウィンドー*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].medama_max++;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF];
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return 2000;
}
int EVE_FUN::mana_140(/*品質管理室リフォーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
		int M = (shop[S].syou_money[140]*shop[S].mana_gb[3]/100)* (1000 + data.day) / 10;
		shop[S].kabu_price += M / shop[S].kabu_cnt[0];
		shop[S].kairyou_b += 5;
		shop[S].kouji = 3 - shop[S].mana_cnt[M_ONRF];
		shop[S].syou_mp[140]   +=10;
		shop[S].syou_money[140]+=25;
		logu.add("工事開始！",11,S);
	_MANA_END____________________________________________

	return GetRand(1000);
}
int EVE_FUN::mana_141(/*爆発物取扱設備*/int S,int AI){
	
	_MANA_CUL____________________________________________
		//ビッグバンソード
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_142(/*永久冷凍設備*/int S,int AI){
	
	_MANA_CUL____________________________________________
		//アイスソード系
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_143(/*精密組立設備*/int S,int AI){
	
	_MANA_CUL____________________________________________
		//神殺し
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_144(/*玉鋼錬鉄釜*/int S,int AI){
	
	_MANA_CUL____________________________________________
		//刀系
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_145(/*精霊練銀釜*/int S,int AI){
	
	_MANA_CUL____________________________________________
		//ミスリル系
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_146(/*火廣練金釜*/int S,int AI){
	
	_MANA_CUL____________________________________________
		//神系
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_147(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_148(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_149(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_150(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_151(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_152(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_153(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_154(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_155(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_156(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_157(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_158(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_159(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_160(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_161(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_162(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_163(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_164(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_165(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_166(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_167(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_168(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_169(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_170(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_171(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_172(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_173(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_174(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_175(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_176(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_177(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_178(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_179(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_180(/*◆開発*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_181(/*研磨ブースト*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].create_lv[0]++;
		shop[S].syou_mp[181] += 1;
		shop[S].syou_money[181] += 100;
	_MANA_END____________________________________________

	return GetRand(2000);
}
int EVE_FUN::mana_182(/*錬鉄ブースト*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].create_lv[1]++;
		shop[S].syou_mp[182] += 1;
		shop[S].syou_money[182] += 100;
	_MANA_END____________________________________________

	return GetRand(2000);
}
int EVE_FUN::mana_183(/*細工ブースト*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].create_lv[2]++;
		shop[S].syou_mp[183] += 1;
		shop[S].syou_money[183] += 100;
	_MANA_END____________________________________________

	return GetRand(2000);
}
int EVE_FUN::mana_184(/*剣の閃光*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].hirameki_b[0] += 100;
		shop[S].mana_rest[184] = 0;
		shop[S].mana_rest[185] = 0;
		shop[S].mana_rest[186] = 0;
		shop[S].mana_rest[187] = 0;
		//基本の開発		
		for(int i=0;i<3;i++){
			shop[S].wep_sb[0][i]+=3;
		}
	_MANA_END____________________________________________

	return 10000 + GetRand(5000);
}
int EVE_FUN::mana_185(/*槍の閃光*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].hirameki_b[1] += 100;
		shop[S].mana_rest[184] = 0;
		shop[S].mana_rest[185] = 0;
		shop[S].mana_rest[186] = 0;
		shop[S].mana_rest[187] = 0;
		//基本の開発		
		for(int i=0;i<3;i++){
			shop[S].wep_sb[1][i]+=3;
		}
	_MANA_END____________________________________________

	return 10000 + GetRand(5000);
}
int EVE_FUN::mana_186(/*斧の閃光*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].hirameki_b[2] += 100;
		shop[S].mana_rest[184] = 0;
		shop[S].mana_rest[185] = 0;
		shop[S].mana_rest[186] = 0;
		shop[S].mana_rest[187] = 0;
		//基本の開発		
		for(int i=0;i<3;i++){
			shop[S].wep_sb[2][i]+=3;
		}
	_MANA_END____________________________________________

	return 10000 + GetRand(5000);
}
int EVE_FUN::mana_187(/*弓の閃光*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].hirameki_b[3] += 100;
		shop[S].mana_rest[184] = 0;
		shop[S].mana_rest[185] = 0;
		shop[S].mana_rest[186] = 0;
		shop[S].mana_rest[187] = 0;
		//基本の開発		
		for(int i=0;i<3;i++){
			shop[S].wep_sb[3][i]+=3;
		}
	_MANA_END____________________________________________

	return 10000 + GetRand(5000);
}
int EVE_FUN::mana_188(/*人月神話*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_189(/*アイデアの結晶*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return GetRand(5000);
}
int EVE_FUN::mana_190(/*カイゼン強化週間*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].kaizen_week = 7;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_191(/*研磨マスター*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].ken_b[0] += 30;
		shop[S].mana_rest[191] = 0;
		shop[S].mana_rest[192] = 0;
		shop[S].mana_rest[193] = 0;
	_MANA_END____________________________________________

	return 10000 + GetRand(5000);
}
int EVE_FUN::mana_192(/*錬鉄マスター*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].ken_b[1] += 30;
		shop[S].mana_rest[191] = 0;
		shop[S].mana_rest[192] = 0;
		shop[S].mana_rest[193] = 0;
	_MANA_END____________________________________________

	return 10000 + GetRand(5000);
}
int EVE_FUN::mana_193(/*細工マスター*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].ken_b[2] += 30;
		shop[S].mana_rest[191] = 0;
		shop[S].mana_rest[192] = 0;
		shop[S].mana_rest[193] = 0;
	_MANA_END____________________________________________

	return 10000 + GetRand(5000);
}
int EVE_FUN::mana_194(/*ブレインストーム*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return GetRand(5000);
}
int EVE_FUN::mana_195(/*使い捨ての剣*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].dur_b -= 20;
		shop[S].atk_b += 20;
		shop[S].mana_rest[195] = 0;
		shop[S].mana_rest[196] = 0;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_196(/*頑丈な武器*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].dur_b += 20;
		shop[S].mana_rest[195] = 0;
		shop[S].mana_rest[196] = 0;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_197(/*至高への到達*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_198(/*失われし技術*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_199(/*新技術の導入*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 4000;
}
int EVE_FUN::mana_200(/*アジャイル開発*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_201(/*特許取得*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_202(/*似通った武器*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_203(/*バランス志向*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_204(/*踏み台*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_205(/*アポカリプスの魔剣*/int S,int AI){
	
	_MANA_CUL____________________________________________
		//トルネルージュ
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_206(/*うぃっちの箒*/int S,int AI){
	
	_MANA_CUL____________________________________________
		//カランコエ
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_207(/*銀の弾丸などない*/int S,int AI){
	
	_MANA_CUL____________________________________________
		//クレメンス
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_208(/*愛の撲殺天使*/int S,int AI){
	
	_MANA_CUL____________________________________________
		//プリティワンド
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_209(/*ボーン装備*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_210(/*ホーン装備*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_211(/*ウィング装備*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_212(/*ファング装備*/int S,int AI){
	
	_MANA_CUL____________________________________________
		//竜の雷
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_213(/*小型大砲*/int S,int AI){
	
	_MANA_CUL____________________________________________

	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_214(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________
	return 1;
}
int EVE_FUN::mana_215(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int i=0;i<4;i++){
			if(shop[S].wep_cre[186+i] < 0) shop[S].wep_cre[186+i] = 0;//包丁
			if(shop[S].wep_cre[270+i] < 0) shop[S].wep_cre[270+i] = 0;//フライパン
			if(shop[S].wep_cre[386+i] < 0) shop[S].wep_cre[386+i] = 0;//フライパン
		}
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_216(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_217(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_218(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_219(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_220(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_221(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_222(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_223(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_224(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_225(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_226(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_227(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_228(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_229(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_230(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_231(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_232(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_233(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_234(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_235(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_236(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_237(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_238(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_239(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_240(/*◆宣伝*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_241(/*チラシ配り*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].senden_syori(25,100);
		if(shop[S].mana_rest[241] <= 0){
			shop[S].mana_rest[242] = 10;
		}
	_MANA_END____________________________________________

	return int(1400 - shop[S].timeido) * 5;
}
int EVE_FUN::mana_242(/*ティッシュ配り*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].senden_syori(27,110);
		if(shop[S].mana_rest[242] <= 0){
			shop[S].mana_rest[243] = 255;
		}
	_MANA_END____________________________________________

	return int(1500 - shop[S].timeido) * 5;
}
int EVE_FUN::mana_243(/*ティッシュ配り・改*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].senden_syori(30,120);
	_MANA_END____________________________________________

	return int(1600 - shop[S].timeido) * 5;
}
int EVE_FUN::mana_244(/*雑誌広告・Ａ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].senden_syori(20,200);
	_MANA_END____________________________________________

	return int(1200 - shop[S].timeido) * 6;
}
int EVE_FUN::mana_245(/*雑誌広告・Ｂ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].senden_syori(10,400);
	_MANA_END____________________________________________

	return int(1300 - shop[S].timeido) * 6;
}
int EVE_FUN::mana_246(/*雑誌広告・Ｃ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].senden_syori(1,1000);
	_MANA_END____________________________________________

	return int(1400 - shop[S].timeido) * 6;
}
int EVE_FUN::mana_247(/*割引セール*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].price_rate = 80;
		shop[S].yasuuri    =  7;
		for(int i=0;i<data.shop_cnt;i++){
			if(shop[i].mana_cnt[M_KAKH] > 0 && S != i){
				shop[i].start_sell(80,7);
			}
		}
	_MANA_END____________________________________________

	return int(1000 - shop[S].timeido) * 7;
}
int EVE_FUN::mana_248(/*半額セール*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].price_rate = 50;
		shop[S].yasuuri    =  7;
		for(int i=0;i<data.shop_cnt;i++){
			if(shop[i].mana_cnt[M_KAKH] > 0 && S != i){
				shop[S].start_sell(50,7);
			}
		}
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_249(/*もってけセール*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].price_rate =  0;
		shop[S].yasuuri    =  7;
		for(int i=0;i<data.shop_cnt;i++){
			if(shop[i].mana_cnt[M_KAKH] > 0 && S != i){
				shop[S].start_sell(0,7);
			}
		}
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_250(/*逆ザヤセール*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].price_rate = 50;
		shop[S].yasuuri    = 28*3;
		for(int i=0;i<data.shop_cnt;i++){
			if(shop[i].mana_cnt[M_KAKH] > 0 && S != i){
				shop[S].start_sell(50,28*3);
			}
		}
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_251(/*ナウオンセール*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_252(/*安心の価格保障*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 3000;
}
int EVE_FUN::mana_253(/*Ｐカード*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 3000;
}
int EVE_FUN::mana_254(/*十人に一人*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 2000;
}
int EVE_FUN::mana_255(/*品薄情報を流す*/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int H=0;H<data.jinkou_max;H++){
			if(hun[H].life <= 0) continue;
            if(hun[H].wep_c <= 1 && fun.Rand(1) == 0)
            {
                if(hun[H].shop_koukan[S] < shop[S].senden_b * 2)
                {
                    hun[H].shop_koukan[S] = shop[S].senden_b * 2;
                }
            }
		}
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_256(/*口コミを流す*/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int H=0;H<data.jinkou_max;H++){
			if(hun[H].life <= 0) continue;
            if(hun[H].wep_c >= 6 && fun.Rand(1) == 0 )
            {
                if(hun[H].shop_koukan[S] < shop[S].senden_b * 2)
                {
                    hun[H].shop_koukan[S] = shop[S].senden_b * 2;
                }
            }
		}
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_257(/*神の怒り*/int S,int AI){
	
	_MANA_CUL____________________________________________
		data.boom = 2;
		data.boom_rest = 7;
		logu.add("クレームがブーム！",13,5);
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_258(/*さらなるつよさ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].ninki_b[0] = 130;
		shop[S].ninki_b[1] = 70;
		shop[S].ninki_b[2] = 70;
		shop[S].mana_rest[258] = 0;
		shop[S].mana_rest[259] = 0;
		shop[S].mana_rest[260] = 0;
		//基本の開発		
		for(int i=0;i<4;i++){
			shop[S].wep_sb[i][0]+=3;
		}
	_MANA_END____________________________________________

	return 10000 + GetRand(5000);
}
int EVE_FUN::mana_259(/*さらなるおしゃれ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].ninki_b[0] = 70;
		shop[S].ninki_b[1] = 130;
		shop[S].ninki_b[2] = 70;
		shop[S].mana_rest[258] = 0;
		shop[S].mana_rest[259] = 0;
		shop[S].mana_rest[260] = 0;
		//基本の開発		
		for(int i=0;i<4;i++){
			shop[S].wep_sb[i][2]+=3;//T C K
		}
	_MANA_END____________________________________________

	return 10000 + GetRand(5000);
}
int EVE_FUN::mana_260(/*さらなるやすさ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].ninki_b[0] = 70;
		shop[S].ninki_b[1] = 70;
		shop[S].ninki_b[2] = 130;
		shop[S].mana_rest[258] = 0;
		shop[S].mana_rest[259] = 0;
		shop[S].mana_rest[260] = 0;
		//基本の開発		
		for(int i=0;i<4;i++){
			shop[S].wep_sb[i][1]+=3;
		}
	_MANA_END____________________________________________

	return 10000 + GetRand(5000);
}
int EVE_FUN::mana_261(/*広告塔の設置*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_262(/*ゆるきゃら誕生*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[0].mana_rest[262] = 0;
		shop[1].mana_rest[262] = 0;
		shop[2].mana_rest[262] = 0;
		shop[3].mana_rest[262] = 0;
		shop[4].mana_rest[262] = 0;
	_MANA_END____________________________________________

	return 10000;
}
int EVE_FUN::mana_263(/*ブランドロゴマーク*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[0].mana_rest[263] = 0;
		shop[1].mana_rest[263] = 0;
		shop[2].mana_rest[263] = 0;
		shop[3].mana_rest[263] = 0;
		shop[4].mana_rest[263] = 0;
	_MANA_END____________________________________________

	return 10000;
}
int EVE_FUN::mana_264(/*まとめて買え*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 2500;
}
int EVE_FUN::mana_265(/*新たな狩場セール*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_266(/*凱旋セール*/int S,int AI){
	
	_MANA_CUL____________________________________________

	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_267(/*閉店セール*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].price_rate = 90;
	_MANA_END____________________________________________

	return (BlackP - 50) * 50;
}
int EVE_FUN::mana_268(/*リフォームセール*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_269(/*名物店員*/int S,int AI){
	
	_MANA_CUL____________________________________________
		for(int E=0;E<EMP_M;E++){
			if(emp[E].shop_n != S || emp[E].now_job != 1) continue;
			if(emp[E].skill == 14 || emp[E].skill == 25){
				shop[S].senden_b += 5;
			}
		}
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_270(/*本家本元*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_271(/*宣伝をしないのが宣伝*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].sekkyaku_b += 50;
		shop[S].mana_rest[241] = 0;
		shop[S].mana_rest[242] = 0;
		shop[S].mana_rest[243] = 0;
		shop[S].mana_rest[244] = 0;
		shop[S].mana_rest[245] = 0;
		shop[S].mana_rest[246] = 0;
		shop[S].mana_rest[247] = 0;
		shop[S].mana_rest[248] = 0;
		shop[S].mana_rest[249] = 0;
		shop[S].mana_rest[250] = 0;
		shop[S].mana_rest[251] = 0;shop[S].mana_cnt[M_NSEL] = 0;
		shop[S].mana_rest[265] = 0;shop[S].mana_cnt[M_NKAR] = 0;
		shop[S].mana_rest[266] = 0;shop[S].mana_cnt[M_GAIS] = 0;
		shop[S].mana_rest[267] = 0;shop[S].mana_cnt[M_HEIT] = 0;
		shop[S].mana_rest[268] = 0;shop[S].mana_cnt[M_RIFO] = 0;
		shop[S].mana_rest[272] = 0;shop[S].mana_cnt[M_UTES] = 0;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_272(/*雨天セール*/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_273(/*すりこみ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].koukan_down += 50;
	_MANA_END____________________________________________

	return 0;
}
int EVE_FUN::mana_274(/*客寄せナンダ*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].medama_max++;
	_MANA_END____________________________________________

	return 5000;
}
int EVE_FUN::mana_275(/*市場調査*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].senden_b += 5;
		shop[S].syou_mp[275]+= 5;
		shop[S].syou_money[275]+= 5;
	_MANA_END____________________________________________

	return (data.day / 10 - shop[S].seizou_b) * 50;
}
int EVE_FUN::mana_276(/*競合分析*/int S,int AI){
	
	_MANA_CUL____________________________________________
		shop[S].senden_b += 5;
		shop[S].syou_mp[276]+= 5;
		shop[S].syou_money[276]+= 5;
	_MANA_END____________________________________________

	return (data.day / 10 - shop[S].seizou_b) * 50;
}
int EVE_FUN::mana_277(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_278(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_279(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_280(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_281(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_282(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_283(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_284(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_285(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_286(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_287(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_288(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_289(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_290(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_291(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_292(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_293(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_294(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_295(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_296(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_297(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_298(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}
int EVE_FUN::mana_299(/**/int S,int AI){
	
	_MANA_CUL____________________________________________
	_MANA_END____________________________________________

	return 1;
}

int EVE_FUN::mana_setumei(){
	//全ての説明文の更新処理
	std::ostringstream stream;
	//1休日増加
	stream << "社員の休日を増やす--休日　" << shop[P].yasumi_max << "日 → "<< shop[P].yasumi_max+2 << "日--MP回復量＋0.2" ;
	mana[1].help = stream.str();stream.str("");

	//2休日減少
	stream << "社員の休日を減らす--休日　" << shop[P].yasumi_max << "日 → "<< shop[P].yasumi_max-2 << "日--MP回復量－0.2";
	mana[2].help = stream.str();stream.str("");

	//3残業制度
	stream << "労働時間上限　" << shop[P].zangyou/6 << "時間 → "<< shop[P].zangyou/6+0.5 << "時間";
	mana[3].help = stream.str();stream.str("");

	//暗黒＆白金儀式 10-11
	int w = 0,b = 0;
	for(int E=0;E<EMP_M;E++){
		if(emp[E].shop_n == P && emp[E].now_job == 1 && emp[E].pb_rest < 0	   ) b++;
		else if(emp[E].shop_n == P && emp[E].now_job == 1 && emp[E].pb_rest > 0) w++;
	}
	stream << "暗黒期の社員の数×10のＭＰが回復する。--この戦術は一度しか使えない。--ＭＰ回復量 → " << b*10 ;
	mana[10].help = stream.str();stream.str("");
	stream << "黄金期の社員の数×10のＭＰが回復する。--この戦術は一度しか使えない。--ＭＰ回復量 → " << w*10 ;
	mana[11].help = stream.str();stream.str("");

	//25-26面接確率
	stream << "求職者の能力判別率＋5％--判別率　" << shop[P].mensetu_lv << "％ → "<< shop[P].mensetu_lv+5 << "％";
	mana[25].help = stream.str();stream.str("");
	stream << "求職者の能力判別率＋7％--判別率　" << shop[P].mensetu_lv << "％ → "<< shop[P].mensetu_lv+7 << "％";
	mana[26].help = stream.str();stream.str("");


	//61～65株式買収
	stream << "自社株を償却します。--";
	stream << "株価　" << shop[P].kabu_price << " Ｇ × "<< shop[P].kabu_buy << "株償却--";
	stream << "株数　" << shop[P].kabu_cnt[0] << "／"<< shop[P].kabu_max;
	mana[61].help = stream.str();stream.str("");

	for(int i=1;i<5;i++){
		switch(i){
			case 1:stream << "狩人協会の株を購入する。--";break;
			case 2:stream << "採掘場の株を購入する。--";break;
			case 3:stream << "発明所の株を購入する。--";break;
			case 4:stream << "新聞社の株を購入する。--";break;
		}
		stream << "株価　" << data.kabu_price[i] << " Ｇ × "<< shop[P].kabu_buy << "株購入--";
		stream << "株数　" << shop[P].kabu_cnt[i] << "／"<< data.kabu_cnt[i];
		mana[61+i].help = stream.str();stream.str("");
	}

	//71　　増資
	stream << "新規に株を発行します。--";
	stream << "株価　" << shop[P].kabu_price << " Ｇ × "<< shop[P].kabu_buy << "株増資--";
	stream << "株数　" << shop[P].kabu_cnt[0] << "／"<< shop[P].kabu_max;
	mana[71].help = stream.str();stream.str("");

	for(int i=1;i<5;i++){
		switch(i){
			case 1:stream << "狩人協会の株を売却する。--";break;
			case 2:stream << "採掘場の株を売却する。--";break;
			case 3:stream << "発明所の株を売却する。--";break;
			case 4:stream << "新聞社の株を売却する。--";break;
		}
		stream << "株価　" << data.kabu_price[i] << " Ｇ × "<< shop[P].kabu_buy << "株売却--";
		stream << "株数　" << shop[P].kabu_cnt[i] << "／"<< data.kabu_cnt[i];
		mana[92+i].help = stream.str();stream.str("");
	}

	//66デイトレ
	stream << "株式買収と増資の取引数が増える。--";
	stream << "発行＆買収　" << shop[P].kabu_buy << "株 → "<< shop[P].kabu_buy + 10 << "株";
	mana[66].help = stream.str();stream.str("");
	
	//74財テク&銀行まんじゅう
	stream << "借り入れ金の利息が1／2。--";
	stream << "利息　" << shop[P].risoku_rate << "％ → "<< shop[P].risoku_rate/2 << "％";
	mana[74].help = stream.str();
	mana[75].help = stream.str();stream.str("");

	//76ハイパー積み立て
	stream << "預金の利息が2倍になる。--";
	stream << "利子　" << shop[P].risi_rate << "％ → "<< shop[P].risi_rate*2 << "％";
	mana[76].help = stream.str();stream.str("");

	//121～138各種工事
	stream << "工事をして店舗を拡大し、様々なメリットを得る。--工事には一週間かかる。--";
	stream << "店舗の大きさ Lv" << shop[P].size << " → "<< shop[P].size + 1 << "";
    stream << "閃ける武器が増える";
	mana[121].help = stream.str();stream.str("");

	stream << "倉庫容量を200増やす。--";
	stream << "在庫が溢れると、毎日超過数×10Gの資金を消費する。--";
	stream << "倉庫容量 " << shop[P].souko_max << " 個 → "<< shop[P].souko_max+200 << "個";
	mana[122].help = stream.str();stream.str("");

	stream << "工房を強化し製造力を高める。--";
	stream << "製造力 ＋" << shop[P].seizou_b - 100 << "％ → ＋"<< shop[P].seizou_b - 95 << "％";
	mana[123].help = stream.str();stream.str("");

	stream << "厨房を強化し再生力を高める。--";
	stream << "回復力 ＋" << shop[P].kaihuku_b - 100 << "％ → ＋"<< shop[P].kaihuku_b - 95 << "％";
	mana[124].help = stream.str();stream.str("");

	stream << "内装を強化し接客力を高める。--";
	stream << "接客力 ＋" << shop[P].sekkyaku_b - 100 << "％ → ＋"<< shop[P].sekkyaku_b - 95 << "％";
    mana[125].help = stream.str();stream.str("");

	stream << "研究室を強化し開発力を高める。--";
	stream << "開発力 ＋" << shop[P].kaihatu_b - 100 << "％ → ＋"<< shop[P].kaihatu_b - 95 << "％";
    mana[126].help = stream.str();stream.str("");

	stream << "レジを強化し客捌力を高める。--";
	stream << "客捌力 ＋" << shop[P].sabaki_b - 100 << "％ → ＋"<< shop[P].sabaki_b - 95 << "％";
	mana[127].help = stream.str();stream.str("");

	stream << "ごらく室を強化しストレス回復力を高める。--";
	stream << "ストレス回復 ＋" << shop[P].stress_b - 100 << "％ → ＋"<< shop[P].stress_b - 95 << "％";
	mana[128].help = stream.str();stream.str("");

	stream << "看板を強化し宣伝命中率と効果を高める。--";
	stream << "宣伝効果 ＋" << shop[P].senden_b - 100 << "％ → ＋"<< shop[P].senden_b - 95 << "％";
    mana[129].help = stream.str();stream.str("");

	stream << "礼拝堂リフォーム--";
	stream << "社会人度変化 ＋" << shop[P].syakai_b - 100 << "％ → ＋"<< shop[P].syakai_b - 90 << "％";
	mana[130].help = stream.str();stream.str("");

	stream << "資料室を強化し、教育体制を整えます。--";
	stream << "経験値 ＋" << shop[P].exp_b - 100 << "％ → ＋"<< shop[P].exp_b - 95 << "％";
    mana[131].help = stream.str();stream.str("");

	stream << "温泉を強化しやる気を高める。--";
	stream << "やる気上昇 ＋" << shop[P].yaruki_b - 100 << "％ → ＋"<< shop[P].yaruki_b - 95 << "％";
	mana[132].help = stream.str();stream.str("");

	stream << "社長室を強化し経営力を高める。--";
	stream << "ＭＰ回復 ＋" << shop[P].p_mp << " → ＋"<< shop[P].p_mp+0.1 << "";
	mana[133].help = stream.str();stream.str("");

	stream << "検査室を強化し改良力を高める。--";
	stream << "改良経験 ＋" << shop[P].kairyou_b << " → ＋"<< shop[P].kairyou_b+10 << "";
	mana[140].help = stream.str();stream.str("");
	//241～246各種宣伝
	stream << "チラシを配って宣伝する。";
	stream << "--命中率" <<  25 * shop[P].senden_b /100;
	stream << "--好感度" << 100 * shop[P].senden_b /100;
	mana[241].help = stream.str();stream.str("");
	stream << "ティッシュを配ります。";
	stream << "--命中率" <<  27 * shop[P].senden_b /100;
	stream << "--好感度" << 110 * shop[P].senden_b /100;
	mana[242].help = stream.str();stream.str("");
	stream << "きぐるみを着て、ティッシュを配ります。";
	stream << "--命中率" <<  30 * shop[P].senden_b /100;
	stream << "--好感度" << 120 * shop[P].senden_b /100;
	mana[243].help = stream.str();stream.str("");

	stream << "月刊・ハンターライフに広告を載せる。";
	stream << "--命中率" <<  20 * shop[P].senden_b /100;
	stream << "--好感度" << 200 * shop[P].senden_b /100;
	mana[244].help = stream.str();stream.str("");
	stream << "季刊・俺の武器に広告を載せる。";
	stream << "--命中率" <<  10 * shop[P].senden_b /100;
	stream << "--好感度" << 400 * shop[P].senden_b /100;
	mana[245].help = stream.str();stream.str("");
	stream << "不定期・武器防具論に広告を載せる。";
	stream << "--命中率" <<   1 * shop[P].senden_b /100;
	stream << "--好感度" << 1000 * shop[P].senden_b /100;
	mana[246].help = stream.str();stream.str("");
	//255-256
	stream << "武器をあまり持っていないハンターに宣伝効果。";
	stream << "--命中率" <<  50;
	stream << "--好感度" << shop[P].senden_b * 2;
	mana[255].help = stream.str();stream.str("");
	stream << "武器をたくさん持っているハンターに宣伝効果。";
	stream << "--命中率" <<  50;
	stream << "--好感度" << shop[P].senden_b * 2;
	mana[256].help = stream.str();stream.str("");
	return 1;
}
int EVE_FUN::seido_setumei(){
	//全ての説明文の更新処理
	std::ostringstream stream;
	//5～8注釈削除
	mana[5].seido_h = "";
	mana[6].seido_h = "";
	mana[7].seido_h = "";
	mana[8].seido_h = "";
	mana[9].seido_h = "";
	//19スクラム
	if(shop[P].emp_cnt - shop[P].emp_kou <= 10){
		mana[19].seido_h = "職人のやる気上昇ボーナス";
	}else{
		mana[19].seido_h = "職人のやる気上昇ノーボーナス";
	}
	if(shop[P].emp_kou <= 10){
		mana[19].seido_h = "職人のやる気上昇ボーナス";
	}else{
		mana[19].seido_h = "職人のやる気上昇ノーボーナス";
	}
	//22～23注釈削除
	mana[22].seido_h = "";
	mana[23].seido_h = "";
	//33　安全第一
	stream << "判別率　" << shop[P].mensetu_lv << "％";
	mana[25].seido_h = stream.str();stream.str("");
	mana[26].seido_h = stream.str();stream.str("");
	//34～38注釈削除
	mana[34].seido_h = "";
	mana[35].seido_h = "";
	mana[36].seido_h = "";
	mana[37].seido_h = "";
	mana[38].seido_h = "";
	//
	mana[74].seido_h = "";
	mana[75].seido_h = "";
	mana[76].seido_h = "";

	stream << "店舗の大きさ Lv" << shop[P].size;
	mana[121].seido_h = stream.str();stream.str("");

	stream << "倉庫容量 " << shop[P].souko_max << " 個";
	mana[122].seido_h = stream.str();stream.str("");

	stream << "製造力 ＋" << shop[P].seizou_b - 100 << "％";
	mana[123].seido_h = stream.str();stream.str("");

	stream << "回復力 ＋" << shop[P].kaihuku_b - 100 << "％";
	mana[124].seido_h = stream.str();stream.str("");

	stream << "接客力 ＋" << shop[P].sekkyaku_b - 100 << "％";
	mana[125].seido_h = stream.str();stream.str("");

	stream << "開発力 ＋" << shop[P].hirameki_b - 100 << "％";
	mana[126].seido_h = stream.str();stream.str("");

	stream << "客捌力 ＋" << shop[P].sabaki_b - 100 << "％";
	mana[127].seido_h = stream.str();stream.str("");

	stream << "ストレス回復 ＋" << shop[P].stress_b - 100 << "％";
	mana[128].seido_h = stream.str();stream.str("");

	stream << "宣伝効果 ＋" << shop[P].senden_b - 100 << "％";
	mana[129].seido_h = stream.str();stream.str("");

	stream << "社会人度変化 ＋" << shop[P].syakai_b - 100 << "％";
	mana[130].seido_h = stream.str();stream.str("");

	stream << "経験値 ＋" << shop[P].exp_b - 100 << "％";
	mana[131].seido_h = stream.str();stream.str("");

	stream << "やる気上昇 ＋" << shop[P].yaruki_b - 100 << "％";
	mana[132].seido_h = stream.str();stream.str("");

	mana[184].seido_h = "";
	mana[185].seido_h = "";
	mana[186].seido_h = "";
	mana[187].seido_h = "";

	mana[191].seido_h = "";
	mana[192].seido_h = "";
	mana[193].seido_h = "";

	mana[195].seido_h = "";
	mana[196].seido_h = "";

	return 1;
}