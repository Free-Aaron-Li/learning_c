//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "../include/vector.h"


Vector*
vector_create(void) {
    Vector* vector = malloc(sizeof(Vector));
    if (vector == NULL) {
        printf("Error: Could not allocate memory for vector.\n");
        exit(EXIT_FAILURE);
    }
    vector->elements = malloc(DEFAULT_CAPACITY * sizeof(E));
    if (!vector->elements) {
        free(vector);
        printf("Error: Could not allocate memory for vector elements.\n");
        exit(EXIT_FAILURE);
    }
    vector->size     = 0;
    vector->capacity = DEFAULT_CAPACITY;
    return vector;
}


void
vector_destroy(Vector* v) {
    free(v->elements);
    free(v);
}


/**
 * @brief 扩展向量容量。
 * @details
 * 当向量的当前容量不足以容纳更多元素时，调用此函数扩展容量。\n
 * 扩容策略通常是将当前容量翻倍或其他预定义规则。
 * @ingroup vector_group
 * @param v 指向需要扩容的向量结构体指针。
 */
void
grow_capacity(Vector* v) {
    const size_t new_capacity = (v->capacity < MAX_PREALLOC
                                     ? (v->capacity << 1)
                                     : (v->capacity + MAX_PREALLOC));
    /* 错误：realloc失败返回空指针，且旧内存块不会被释放。造成内存泄露 */
    // vector->elements = realloc(vector->elements, new_capacity * sizeof(E));
    E* p = realloc(v->elements, new_capacity * sizeof(E));
    if (!p) {
        printf("Error: expansion failure.\n");
        exit(EXIT_FAILURE);
    }
    v->elements = p;
    v->capacity = new_capacity;
}


void
push_back(Vector* v, const E val) {
    if (v->size == v->capacity) { /* 扩容 */
        grow_capacity(v);
    }

    /* 添加元素 */
    v->elements[v->size] = val;
    ++v->size;
}
