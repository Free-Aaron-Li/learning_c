//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.

#ifndef POINTER_STRING_H
#define POINTER_STRING_H
#include "pointer.h"

/**
 * @file pointer_string.h
 * @defgroup pointer_string_group string
 * @brief 指针与字符串模块。
 * @details 主要包含：
 * - @ref string_usage 字符串的使用
 */

/**
 * @brief 展示字符串的不同用法和存储方式
 * @details
 * 演示了字符串的书写方式、存储方式、表示方法以及定义和初始化的区别；
 * 通过示例代码展示字符串在内存中的存储和访问方式
 * @ingroup pointer_string_group
 */
void string_usage(void);

/**
 * @brief 使用 <string.h> 常用字符串操作函数
 * @details
 * 演示 strlen， strcpy， strcat，strcmp 等函数。
 * @ingroup pointer_string_group
 */
void operating_string(void);


/**
 * @brief 展示字符串的输入与输出操作
 * @details
 * 演示如何通过标准输入输出函数处理字符串，
 * 包括使用 scanf、printf、fgets、puts 等。
 * @ingroup pointer_string_group
 */
void string_io(void);

void string_array(void);
#endif // POINTER_STRING_H
