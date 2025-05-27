//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.

#ifndef VECTOR_H
#define VECTOR_H

/**
 * @file vector.h
 * @defgroup vector_group vector
 * @brief 自定义向量模块。
 * @details 主要包含：
 * - @ref Vector 动态数组
 * - @ref vector_create 创建动态数组实例
 * - @ref vector_destroy 销毁动态数组实例
 * - @ref push_back 添加元素
 */

#include <stdlib.h>
#include <stdio.h>

/* 默认初始容量 */
#define DEFAULT_CAPACITY 8

/* 最大预分配容量 */
#define MAX_PREALLOC 1024

/* 元素类型 */
typedef int E;


/**
 * @brief 定义一个动态数组结构体。
 * @details 该结构体用于实现动态数组功能，支持存储元素、记录当前大小和容量。\n
 * 结构体成员包括：\n
 * - elements：指向堆空间的数组，用于存储数据。\n
 * - size：当前存储的元素个数。\n
 * - capacity：数组的最大容量。\n
 * @ingroup vector_group
 */
typedef struct {
    E*     elements; /* 指向堆空间的数组 */
    size_t size;     /* 元素个数 */
    size_t capacity; /* 数组容量 */
} Vector;

/**
 * @brief 创建一个动态数组实例。
 * @details
 * 该函数用于初始化并返回一个动态数组实例。\n
 * 动态数组初始状态为空，容量和大小均为0。\n
 * @ingroup vector_group
 * @return 返回指向新创建的动态数组实例的指针。
 */
Vector* vector_create(void);

/**
 * @brief 销毁动态数组实例。
 * @details
 * 该函数用于释放动态数组占用的内存资源。\n
 * 包括释放存储元素的堆空间以及动态数组结构体本身。\n
 * @ingroup vector_group
 * @param v 指向要销毁的动态数组实例的指针。
 */
void vector_destroy(Vector* v);

/**
 * @brief 向动态数组末尾添加一个元素。
 * @details
 * 该函数用于将指定值添加到动态数组的末尾。\n
 * 如果当前容量不足，会自动扩展容量以容纳新元素。\n
 * @ingroup vector_group
 * @param v 指向动态数组实例的指针。
 * @param val 要添加到动态数组末尾的元素值。
 */
void push_back(Vector* v, E val);

#endif //VECTOR_H
