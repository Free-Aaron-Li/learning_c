//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "pointer_basic.h"

#define SIZE(a) (sizeof(a) / sizeof(a[0]))

void
const_pointer(void) {
    int a = 3, b = 4;
    const int* p = &a;

    /* p：const int *，*p：const int */
    printf("常量指针：");
    printf("*p = %d\n", *p);

    int* const p1 = &b;
    printf("指针常量：");
    b = 5;

    /* p1：int *const，*p1：int */
    printf("*p1 = %d\n", *p1);
    return;
}


/**
 * @brief 在数组中查找最大值和最小值
 * @details 通过遍历数组，将最大值和最小值分别存储在指定的内存位置中。
 *         该函数会修改指针指向的内存位置的值，而不是修改指针本身。
 * @ingroup pointer_basic_group
 *
 * @param arr 待查找的整型数组
 * @param length 数组长度
 * @param p_min 用于存储最小值的指针
 * @param p_max 用于存储最大值的指针
 */
void
min_max(const int arr[], const int length, int* p_min, int* p_max) {
    for (int i = 1; i < length; ++i) {
        if (arr[i] < *p_min) {
            *p_min = arr[i];
        } else if (arr[i] > *p_max) {
            *p_max = arr[i];
        }
    }
    printf("max local value in function: %d\n", p_max);
}


/**
 * @brief 在数组中查找最大值和最小值的错误示例
 * @details 通过修改指针本身而不是指针指向的值来尝试查找最大值和最小值，
 * 这种方法会导致函数外部无法获得正确的结果。因为采用值传递指针方式，函数体内部使用的是拷贝指针，而非原指针。
 * @ingroup pointer_basic_group
 *
 * @param arr 待查找的整型数组
 * @param length 数组长度
 * @param p_min 用于存储最小值的指针
 * @param p_max 用于存储最大值的指针
 */
void
min_max_fault(int arr[], const int length, int* p_min, int* p_max) {
    for (int i = 1; i < length; ++i) {
        if (arr[i] < *p_min) {
            p_min = &arr[i];
        } else if (arr[i] > *p_max) {
            p_max = &arr[i];
        }
    }
    printf("p_max local value in function: %d\n",
           p_max); /* 形参指针值发生改变。 */
}


void
find_max_min_value(void) {
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int min = 0, max = 0;
    int* p_max = &arr[0];
    int* p_min = &arr[0];

    /* 1. 指针赋值方式 */
    printf("p_max local: %d\n", p_max);
    min_max_fault(arr, SIZE(arr), p_min, p_max); /* max:0, min:0 */
    printf("max:%d, min:%d\n", *p_max, *p_min);
    printf("p_max local: %d\n", p_max); /* 值传递指针，指针值并没有改变。 */

    /* 2. 指针值修改方式 */
    printf("max local: %d\n", &max);
    min_max(arr, SIZE(arr), &min, &max); /* max:9, min:0 */
    printf("max:%d, min:%d\n", max, min);
    printf("max local: %d\n", &max);
}


/**
 * @brief 演示返回局部变量地址的危险行为
 * @details 该函数演示了一个常见的编程错误：返回局部变量的地址。
 *         局部变量在函数返回时会被销毁，因此返回其地址将导致悬空指针。
 *         当试图访问该地址时，会导致未定义行为，通常会引发段错误(SIGSEGV)。
 * @return 返回一个指向已销毁局部变量的指针，这是一个危险的行为
 */
int*
foo(void) {
    int i = 3;
    //...
    return &i;
}

void
get_formal_parameter_address(void) {
    int* p = foo(); /* 获取形参地址值 */

    printf("p = %d\n", p);   /* p = 0 */
    printf("*p = %d\n", *p); /* 139 (interrupted by signal 11: SIGSEGV) */
    printf("p = %d\n", p);
    printf("*p = %d\n", *p);
}
