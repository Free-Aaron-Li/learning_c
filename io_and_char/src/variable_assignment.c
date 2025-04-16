//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me know:
//   <communicate_aaron@outlook.com>.
#include "io_and_char.h"

void print_format(void) {
    const int i = 40;
    const float x = 512.1314f;
    printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i); /* d: decimal; f: float */
    printf("|%f|%10f|%10.2f|%-10.2f|\n", x, x, x, x);
}

void scan_format(void) {
    const int i, j;
    const float x, y;
    /* 返回匹配成功转换说明的个数 */
    const int n = scanf("%d %d %f %f", &i, &j, &x, &y); /* 12 12.3 12.3abc 25.4 */
    printf("i:%d, j:%d, x:%f, y:%f \n", i, j, x, y); /* 12, 12, 0.3, 12.3 */
    printf("match success number is:%d\n", n); /* 4 */

    const int m = scanf("%d/%d", &i, &j); /* 5/ 96 */
    printf("i:%d, j:%d\n", i, j); /* 5 96 */
    printf("match success number is:%d\n", m); /* 2 */
}

#include <ctype.h>

void escape_sequence_of_characters(void) {
    printf("test\ntest");
    printf("\n----------\n");
    printf("test\ntest\r");
    printf("\n----------\n");
    printf("test\ttest");
    printf("\n----------\n");
    printf("test\\test");
    printf("\n----------\n");
    printf("test\'test\"");
    printf("\n----------\n");
    printf("test\atest");
    printf("\n----------\n");
    printf("test\btest");
    printf("\n----------\n");
    printf("test\ftest");
    printf("\n----------\n");
    printf("test\vtest");
    printf("\n----------\n");
    printf("test\?test");
    char c = 'a';
    c = toupper(c);
    printf("%c", c);
}

int character_conversion(void) {
    /* 1. 隐式转换*/
    /* 1.1 整数提升 */
    // char c = '1';
    // short s = 10;
    // int i = 100;

    /* 1.2 低向高提升 */
    // long l = 1000L;
    // long long ll = 10000LL;
    // float f = 3.14f;
    // double d = 512.1314;

    /* 1.3 有符号转换 */
    // const int i = -1;
    // const unsigned u = 100;
    // if (i > u) {
    //     printf("i>u\n");
    // }

    /* 2. 显式转换 */
    /* 2.1 计算浮点数的小数部分 */
    // const double d = 3.14;
    // const double fraction = d - (int) d;

    /* 2.2 注释作用 */
    // const int i = (int) d; /* d一定会转换为int类型 */
    // printf("%lf", fraction);

    /* 2.3 精确控制类型转换 */
    // const int dividend = 7;
    // const int divisor = 4;
    // const double quotient = (double) dividend / divisor;

    /* 2.4 避免溢出*/
    // const long long millis_per_day = 24 * 60 * 60 * 1000;
    // const long long nanos_per_day = 24 * 60 * 60 * 1000 * 1000 * 1000; /* 整数相乘导致溢出 */
    // const long long nanos_per_day1 = (long long) 24 * 60 * 60 * 1000 * 1000 * 1000; /* 整数相乘导致溢出 */
    // printf("nanos_per_day / millis_per_day = %lld\n", nanos_per_day / millis_per_day);
    // printf("nanos_per_day / millis_per_day = %lld\n", nanos_per_day1 / millis_per_day);

    return 0;
}
