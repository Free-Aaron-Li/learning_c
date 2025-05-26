//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "pointer_malloc.h"


void
demonstrate_memory_allocation() {
    /* 利用栈上指针变量访问堆上数据 */
    /* malloc: memory + allocate */
    int* p = malloc(sizeof(int) * 100);
    printf("Address of p: %p\n", (void*) &p);

    /* calloc: clear + allocate */
    int* p1 = calloc(10000000000000, sizeof(int));
    printf("Address of p: %p\n", p1); /* 申请失败，返回空指针 */

    /* realloc:  */

    free(p);
    free(p1);
    return;
}
