//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "pointer_array.h"
#include "pointer_basic.h"
#include "pointer_string.h"


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
    string_array();
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
    int i;
    double d;
    if (argc < 3) {
        printf("Error!\n");
        exit(EXIT_FAILURE);
    }

    /* 读取数字 */
    sscanf(argv[1], "%d", &i);
    sscanf(argv[2], "%lf", &d);
    printf("i: %d, d: %lf\n", i, d);

    test();
    return 0;
}
