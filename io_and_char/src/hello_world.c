//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me know:
//   <communicate_aaron@outlook.com>.
#include "../include/io_and_char.h" // 预处理指令

#define N 5 /* 宏定义 */
#define FOO(x) (1 + x*x) /* 带参数的宏函数 */

void hello_world(void) { /* void 表示无参数，这与C++中不同。C++中不加表示无参，但是在C中表示不确定 */
    printf("Hello World.\n");
    printf("N * N = %d\n", N * N);
    printf("FOO(N) = %d\n", FOO(1+2)); /* 1+1+2*1+2=6，而非10。本质上是文本替换，所以注意⚠️要加上括号！ */
}
