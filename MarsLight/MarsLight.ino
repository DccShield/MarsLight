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
