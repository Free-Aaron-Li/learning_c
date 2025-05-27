//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "enum.h"
#include "st_and_em_exercise.h"
#include "struct.h"
#include "vector.h"

/** 求数组长度 */
#define SIZE(a)(sizeof(a)/sizeof(a[0]))


void
test(void) {
    /* using struct */
    //using_struct();

    /* using enum */
    //using_enum();
}


void
exercise(void) {
    struct_exercise();
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
main(void) {
    //test();
    //exercise();
    vector();
    exit(EXIT_SUCCESS);
}
