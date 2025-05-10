//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me know:
//   <communicate_aaron@outlook.com>.
#include "pointer_array.h"

void
array_pointer(void) {
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
    int *p = &arr[2];
    int *q = &arr[8];
    printf("p = %p, q = %p\n", p, q);
    printf("*p: %d, *q: %d\n", *p, *q);

    /* 1. 加法 */
    q = p + 3; /* +3：向右偏移3个元素 */
    p += 6;    /* +6：向右偏移6个元素 */
    printf("p = %p, q = %p\n", p, q);
    printf("*p: %d, *q: %d\n", *p, *q);

    /* 2. 减法 */
    p -= 2;
    printf("p = %p, q = %p\n", p, q);
    printf("*p: %d, *q: %d\n", *p, *q);

    // p = p - q; /* 错误： 由int* 转变为 long int */
    const long int distance = p - q;
    /* 3. 两指针相减 */
    printf("p - q = %ld\n", distance);

    /* 4. 利用指针运算处理数组 */

    int sum = 0;
    for (int *p = &arr[0]; p < &arr[16]; ++p) {
        sum += *p;
    }
    printf("sum=%d\n", sum);
}
