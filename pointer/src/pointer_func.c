//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "pointer_func.h"


void
foo1(const int a, const int b) {
    printf("Foo: %d\n", a + b);
}


void
bar(const int a, const int b) {
    printf("Bar: %d\n", a * b);
}


void
demonstrate_func_ptr() {
    /* 1. 定义函数指针变量 */
    void (*func)(const int, const int);

    /* 2. 函数地址：&foo, foo均可 */
    func = &foo1;
    func = bar;

    /* 3. 通过函数指针调用函数
     * 下述两种调用方式均可
     */
    (*func)(1, 2);
    func(2, 3);
}
