/*
 * メモリサイズ
 */

#include <stdio.h>

int g_num1;             //(.bss)
int g_num2 = 0;         // .bss
int g_num3 = 5;         // .data
const int g_num4 = 7;   // .rodata

int main(void){
  static int num5 = 9;  // .data
  int num6;             // スタック領域かレジスタ
  char *s = "1234567";  // .rodata

  return 0;
}
