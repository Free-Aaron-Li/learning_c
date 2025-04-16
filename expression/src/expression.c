//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "expression.h"

void
operator_precedence(void) {
    int i;

    /* expr1 = expr2，整体的值为赋值后，左边表达式expr1的值
     *                副作用：改变左边表达式的值
     */
    const double d = i = 3.14l;
    printf("i = %d, d = %.2lf\n", i, d); /* 3 3.00 */

    i = 1;
    /* ++i，值：原来的i加1
     *      副作用：i自增
     */
    printf("++i = %d\n", ++i);

    i = 1;
    /* i++，值：原来的i
     *      副作用：i自增
     */
    printf("i++ = %d\n", i++);
    printf("i = %d\n", i);
}

void
byte_operation(void) {
    /* 移位运算 */
    /* 左移没有溢出，左移n位，相当于乘以2^n次方
     * 右移n位，相当于除以2^n次方（向下取整）
     * 左移和右移没有副作用
     */
    // const unsigned short i = 13; /* 0000 1101 */
    // unsigned short j = i << 2;   /* 0011 0100 52 */
    // printf("i = %d, j = %d\n", i, j);
    // j = i >> 2; /* 0000 0011 3 */
    // printf("i = %d, j = %d\n", i, j);

    /* 按位运算 */
    // const unsigned short i = 21; /* 0000 0000 0001 0101 */
    // const unsigned short j = 56; /* 0000 0000 0011 1000*/
    // unsigned short k = ~i;       /* 1111 1111 1110 1010 */
    // printf("i = %d, j = %d, k = %d\n", i, j, k);
    // k = i & j; /* 0000 0000 0001 0000 */
    // k = i | j; /* 0000 0000 0011 1101 */
    // k = i ^ j; /* 0000 0000 0010 1101 */
    // printf("i = %d, j = %d, k = %d\n", i, j, k);
}
bool
is_odd(const int i) {
    /* WRONG: 采用数学方式无法进行判断
     * 数学中取余值一定是非负数，但是在C语言中取余值可以为负数，
     * 余数的符号和被除数的符号一致。
     */
    // return i % 2 == 1;

    /* 正确的写法 */
    return i % 2 != 0;
}
bool
is_odd_plus(const int i) {
    /* 补码：奇数的最低位一定为1，
     * mask 掩码操作：&
     * 0x1表示关注该数的二进制表示，1更多的表示该数的值，
     * 采用0x1更能表示该语句的具体作用。
     */
    return (i & 0x1) == 1;
}
bool
is_power_of_two(int i) {
    /* 做法1 */
    // while ((i & 0x1) == 0) {
    //     i >>= 1;
    // }
    // return i == 1;

    /* 做法2 */
    /* 2的幂的二进制有什么特点：只有一位为1
     * n:   0100 0000
     * n-1: 0011 1111
     */
    return (i & (i - 1)) == 0;
}
void
byte_operation_interview_question(void) {
    /* 1. 请判断一个整数是否为奇数？ */
    int i = -1; /* -1 是奇数 */
    /* -1 % 2 = -1 != 1 */
    printf("is_odd(%d) = %s\n", i, is_odd_plus(i) ? "true" : "false");

    /* 2. 如何判断一个非0的整数是否为2的幂（1, 2, 4, 8,...） */
    i = 4;
    printf("is_power_of_two(%d) = %s\n", i,
           is_power_of_two(i) ? "true" : "false");
}
