//--------------------------------------------------------------------------------
// レイアウト用のパトライト（マーズライト）点灯用スケッチ
// [MarsLight.ino]
// Copyright (c) 2020 Ayanosuke(Maison de DCC)
//
// http://maison-dcc.sblo.jp/ http://dcc.client.jp/ http://ayabu.blog.shinobi.jp/
// https://twitter.com/masashi_214
//
// DCC電子工作連合のメンバーです
// https://desktopstation.net/tmi/ https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//--------------------------------------------------------------------------------

#include "MarsLight.h"

// ArduinoNANOのデジタル出力 3,4,5,6,9,10,11 用のオブジェクトを生成
// それぞれ発光パターンをトリプルフラッシュ・ランダムフォーを設定
MarsLight MarsLightA = MarsLight(3, TripleFlash); 
MarsLight MarsLightB = MarsLight(4, TripleFlash);
MarsLight MarsLightC = MarsLight(5, TripleFlash);
MarsLight MarsLightD = MarsLight(6, RandomFour);
MarsLight MarsLightE = MarsLight(9, RandomFour);
MarsLight MarsLightF = MarsLight(10, RandomFour);
MarsLight MarsLightG = MarsLight(11, RandomFour);

void setup() {
}

void loop() {
  MarsLightA.stateCheck();
  MarsLightB.stateCheck();
  MarsLightC.stateCheck();
  MarsLightD.stateCheck();
  MarsLightE.stateCheck();
  MarsLightF.stateCheck();
  MarsLightG.stateCheck();
}
