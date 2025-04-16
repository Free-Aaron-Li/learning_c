//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me know:
//   <communicate_aaron@outlook.com>.
#include "test.h"

#define SCALE_FACTOR (5.0f / 9.0f) /* 伸缩因子 */
#define FREEZING_PT 32.0f /* 冰点 */

void temperature_conversion(void) {
    double fahrenheit = 0.0;
    printf("Enter temperature in F: ");
    scanf("%lf", &fahrenheit);
    const double celsius = SCALE_FACTOR * (fahrenheit - FREEZING_PT);
    printf("Celsius is: %.1lf", celsius);
}

/** @fn 替换函数 */
#define SWAP(a, b) { \
    int t = a;       \
    a = b;           \
    b = t;           \
}

/**< Greatest Common Divisor */
int gcd(int a, int b) {
    if (a < b) {
        SWAP(a, b);
    }
    while (b != 0) {
        const int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void summed_fraction(void) {
    const int numerator1, denominator1;
    printf("Enter numerator and denominator, for example: 3/4\n ");
    printf("Enter first fraction: ");
    scanf("%d/%d", &numerator1, &denominator1);

    const int numerator2, denominator2;
    printf("Enter second fraction: ");
    scanf("%d/%d", &numerator2, &denominator2);

    const int result_numerator = numerator1 * denominator2 + numerator2 * denominator1;
    const int result_denominator = denominator1 * denominator2;
    const int divisor = gcd(result_numerator, result_denominator);

    if (divisor == result_denominator) { /* 整除 */
        printf("the sum is %d\n", result_numerator / divisor);
    } else {
        printf("the sum is %d/%d\n", result_numerator / divisor, result_denominator / divisor);
    }
}

void message_length(void) {
    int length = 0;
    char c;
    printf("Enter a message:");
    while (getchar() != '\n') {
        ++length;
    }
    printf("Your massage was %d character(s) long.\n", length);
}
