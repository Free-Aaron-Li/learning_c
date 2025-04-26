//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me know:
//   <communicate_aaron@outlook.com>.
#include "function.h"

/**
 * @brief 获取下一个斐波那契数值
 * @return 斐波那契数值
 */
long long
next_fibonacci(void) {
    static long long first = 0;
    static long long second = 1;

    const long long temp = first + second;
    first = second;
    second = temp;
    return temp;
}

void
fibonacci(void) {
    printf("%lld\n", next_fibonacci());
    printf("%lld\n", next_fibonacci());
    printf("%lld\n", next_fibonacci());
    printf("%lld\n", next_fibonacci());
    printf("%lld\n", next_fibonacci());
}
