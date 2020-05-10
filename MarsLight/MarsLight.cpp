//--------------------------------------------------------------------------------
// レイアウト用のパトライト（マーズライト）点灯用スケッチ
// [MarsLight.cpp]
// Copyright (c) 2020 Ayanosuke(Maison de DCC)
// https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//--------------------------------------------------------------------------------

//--------------------------------------------------------------------------------
// MarsLightクラス
//--------------------------------------------------------------------------------
#include <Arduino.h>
#include"MarsLight.h"

// コンストラクタ
MarsLight::MarsLight( unsigned char ch, unsigned char mode)
{
  port = ch;
  pinMode(port, OUTPUT);
  state = ST_INIT;

  switch(mode){
    case TripleFlash:
                strcpy(LuminousPattern,"1_1_1______*");          //トリプルフラッシュ
                break;
    case RandomFour:
                strcpy(LuminousPattern,"101010100001^__100_*");  //ランダムフォー
                break;
    default:
                break;            
  }
  
}  

// MarsLight ステートマシン（状態遷移）
void MarsLight::stateCheck()
{
  switch(state){
    case ST_INIT:
                  Previous = millis();
                  LuminousAddres = 0;
                  state = ST_RUN;
                  break;
    case ST_RUN:
                  if((millis() - Previous) >= 15) { //15msec 
                    switch(LuminousPattern[LuminousAddres]){
                      case  '0': // 1 off
                        cnt = 2;
                        digitalWrite(port, LOW);
                        Previous = millis();
                        state = ST_NEXT;
                        break;
                      case '_':  // 1.5 off
                        cnt = 3;
                        digitalWrite(port, LOW);
                        Previous = millis();
                        state = ST_NEXT;
                        break;
                      case '1':  // 1 on
                        cnt = 2;
                        digitalWrite(port, HIGH);
                        Previous = millis();
                        state = ST_NEXT;
                        break;
                      case '^': // 1.5 on
                        cnt = 3;
                        digitalWrite(port, HIGH);
                        Previous = millis();
                        state = ST_NEXT;
                        break;                        
                      case '*':
                        LuminousAddres = 0;
                        Previous = millis();
                        state = ST_RUN;
                        break;
                      default:
                        break;  
                    }
                  }
                  break;
    case ST_NEXT:
                  if((millis() - Previous) >= 15) { //15msec 
                    cnt --;
                    if(cnt == 0){
                      LuminousAddres ++;
                      state = ST_RUN;
                    }
                        Previous = millis();
                  }
                  break;
    default:
                  break;
  }
}
