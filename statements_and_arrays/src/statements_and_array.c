//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "statements_and_arrays.h"

/* a是一个数组 */
#define SIZE(a) (sizeof(a) / sizeof(a[0]))

int
array(void) {
    /* 1. 初始化 */
    int arr[5];                      /* 变量名：arr；类型：int[5]； */
    int arr1[5];                     /* 定义长度为5的int数组，没有初始化 */
    int arr2[5] = { 1, 2, 3, 4, 5 }; /* 初始化式 */
    int arr3[5] = { 1, 2, 3 };       /*  */

    /* 2. 操作 */
    /* 2.1 取下表[] */;
    const int arr4[] = { 1, 2, 3, 4, 5 };
    printf("arr4[2]=%d\n", arr4[2]);
    /* C语言不检查数组越界，数组越界是一个“未定义行为” */
    printf("arr4[7]=%d\n", arr4[7]);

    /* 2.2 让编译器计算数组长度 */;
    for (int i = 0; i < SIZE(arr4); ++i) {
        printf("%d\t", arr4[i]);
    }
    return 0;
}
