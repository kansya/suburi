/*********************************************************
 * ファイル名 : SysCtrl.c [sc]
 * 責務       : システム全体に関する処理
 * 作成日     : 2020.03.02
 * 作成者     : System-san
 *********************************************************/
/*** 利用ファイルのヘッダ ***/
#include "../RoboApp/Trace.h"
#include "../DrvApi/Sensor.h"
#include "../DrvApi/Motor.h"
#include "../InputCtrl/Course.h"
#include "SysCtrl.h"

/*** 公開関数 ********************************************/
/**********************************************************
 * 関数名     : sc_init
 * 機能       : 初期化処理
 * 引数       : なし
 * 戻値       : なし
 * 備考       : 
 *********************************************************/
void sc_init(void){
  ss_init();
  mt_init();
  tr_init();
  return;
}

/**********************************************************
 * 関数名     : sc_term
 * 機能       : 終了処理
 * 引数       : なし
 * 戻値       : なし
 * 備考       : 
 *********************************************************/
void sc_term(void){
  ss_term();
  mt_term();
  tr_term();
  return;
}

/**********************************************************
 * 関数名     : sc_runningMain
 * 機能       : 直立走行タスクのメイン関数
 * 引数       : なし
 * 戻値       : なし
 * 備考       : 4 ミリ秒周期
 *********************************************************/
void sc_runningMain(void){
  mt_running();
  return;
}

/********************************************************** 
 * 関数名     : sc_traceMain
 * 機能       : コース走行タスクのメイン関数
 * 引数       : なし
 * 戻値       : なし
 * 備考       : 20ミリ秒周期
 *********************************************************/
void sc_traceMain(void){
  tr_run();
  return;
}

/**********************************************************
 * 関数名     : sc_endDiag
 * 機能       : 自己診断完了を通知
 * 引数       : なし
 * 戻値       : なし
 * 備考       : 倒立モジュールから通知を受けてTraceに送信する
 *********************************************************/ 
void sc_endDiag(void){
  tr_runnable();
  return;
}
