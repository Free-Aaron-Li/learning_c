//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.

#ifndef POINTER_BASIC_H
#define POINTER_BASIC_H
#include "pointer.h"

/**
 * @file pointer_basic.h
 * @defgroup pointer_basic_group basic
 * @brief 指针基础模块。
 * @details 主要包含：
 * - @ref const_pointer 常量指针对比
 * - @ref find_max_min_value 查找数组最大值和最小值
 */

/**
 * @brief 演示常量指针和指针常量的使用
 *
 * @details 展示了两种类型的指针：常量指针（pointer to
 *          constant）和指针常量（constant pointer）。
 *         常量指针不能通过指针修改指向的值，而指针常量不能修改指针指向的地址。
 * @ingroup pointer_basic_group
 */
void const_pointer(void);

/**
 * @brief 展示查找数组最大值和最小值的正确和错误方法
 *
 * @details 通过对比演示了两种查找数组最大值和最小值的方法：
 *         一种是错误的指针赋值方式，另一种是正确的值修改方式
 * @ingroup pointer_basic_group
 */
void find_max_min_value(void);


/**
 * @brief 演示如何获取函数形参的地址
 *
 * @details 展示了如何获取和打印函数形式参数的内存地址，
 *         用于理解函数参数在内存中的存储位置和传递机制
 * @ingroup pointer_basic_group
 */
void get_formal_parameter_address(void);

#endif // POINTER_BASIC_H
