//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "pointer_array.h"
#include "pointer_basic.h"
#include "pointer_string.h"
#include "pointer_exercise.h"
#include "pointer_malloc.h"
#include "vector.h"


void
test(void) {
    /* basic */
    // const_pointer();
    // find_max_min_value();
    // get_formal_parameter_address();

    /* array */
    //array_pointer();

    /* string */
    //string_usage();
    //operating_string();
    //string_io();
    //string_array();

    /* malloc */
    demonstrate_memory_allocation();
}


void
exercise(void) {
    /* exercise */
    /* 1. 总秒数的时分秒转换 */
    // const long total_sec = 30196;
    // int        hour      = 0;
    // int        minute    = 0;
    // int        second    = 0;
    // split_time(total_sec, &hour, &minute, &second);
    // printf("total_sec = %ld, convert to: %.2d:%.2d:%.2d\n",
    //        total_sec,
    //        hour,
    //        minute,
    //        second);

    /* 2. 求数组中第一第二大元素 */
    // const int array_ints[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
    //                            15 };
    // int largest        = 0;
    // int second_largest = 0;
    // find_two_largest(array_ints,
    //                  SIZE(array_ints),
    //                  &largest,
    //                  &second_largest);
    // printf("largest = %d, second_largest = %d\n", largest, second_largest);

    /* 3. 逆转字符串 */
    //reverse_print();

    /* 4. 寻最大最小单词 */
    find_max_min_word();
}


void
vector() {
    /* Vector整体流程 */
    Vector* v = vector_create(); /* 创建空的动态数组 */
    for (int i = 1; i <= 100; ++i) {
        push_back(v, i * 10);
    }
    for (int i = 0; i < v->size; ++i) {
        printf("%d ", v->elements[i]);
    }
    vector_destroy(v);
    return;
}


int
main(const int argc, char* argv[]) {
    /* 命令行参数
     * 操作系统在调用main函数时，可以给程序传递一些参数（比如文件名、或是改变程序行为的选项...）
     * argc（argument count）表示命令行参数的个数，
     * argv（argument vector）表示参数数组（向量）。
     * 操作系统都是以“字符串”的形式传递参数的，且argv[0]执行程序名，argv[1]到argv[argc-1]指向
     * 剩余的命令行参数。
     */

    /* 1. 获取命令行参数 */
    puts(argv[0]); /* 可执行文件路径 */
    for (int i = 1; i < argc; ++i) {
        printf("%s\n", argv[i]);
    }

    /* 2. 参数转换 */
    int    i;
    double d;
    if (argc < 3) {
        printf("Error!\n");
        exit(EXIT_FAILURE);
    }

    /* 读取数字 */
    sscanf(argv[1], "%d", &i);
    sscanf(argv[2], "%lf", &d);
    printf("i: %d, d: %lf\n", i, d);

    //test();
    //exercise();
    vector();
    return 0;
}
