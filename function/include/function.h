
//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me know:
//   <communicate_aaron@outlook.com>.

#ifndef FUNCTION_H
#define FUNCTION_H


/**
 * @file function.h
 * @brief 数学问题与经典算法模块
 *
 * @page Function 函数子模块文档
 *
 * @section intro_sec 概述
 *
 * 本小节实现了一些数学算法和经典问题的解决方案，旨在演示递归、回溯等算法思想。
 *
 * ### 包含的主要功能：
 * - 递归解决斐波那契数列；
 * - 分治法解决汉诺塔问题；
 * - 回溯解决 N 皇后问题；
 * - 练习函数模块（如素数判断或掷骰子游戏）。
 *
 * @section dependencies_sec 依赖
 *
 * - @see [<stdbool.h>](https://en.cppreference.com/w/c/header/stdbool)
 * 调用标准Bool类型
 * - @see [<stdio.h>](https://en.cppreference.com/w/c/header/stdio)
 * 调用标准输入输出函数
 * - @see [<stdlib.h>](https://en.cppreference.com/w/c/header/stdlib)
 * 调用标准退出函数
 *
 * @section usage_sec 使用方法
 * - 调用需要的功能函数。
 *
 * @section group_sec 模块划分
 * - @ref function_group 数学与经典算法模块
 * - @ref function_exercise_group 基础练习功能模块
 *
 * @copyright Copyright (c) 2025. aaron.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @defgroup function_group function
 * @brief 数学与经典算法模块。
 * @details 主要包含：
 * - @ref fibonacci 求斐波那契数组；
 * - @ref hanoi 求解汉诺塔问题；
 * - @ref queens 求解 N 皇后问题。
 */


/**
 * @brief 斐波那契数组
 * @details 调用 @ref next_fibonacci 获取斐波那契数。
 *
 * @see next_fibonacci
 *
 * @ingroup function_group
 */
void fibonacci(void);

/**
 * @brief 汉诺塔问题
 * @details 调用 @ref run_hanoi 实现汉诺塔具体实现过程。
 *
 * @see run_hanoi
 *
 * @ingroup function_group
 */
void hanoi(void);

/**
 * @brief 解决 N 皇后问题
 *
 * 初始化棋盘并调用递归算法来解决问题。
 *
 * @ingroup function_group
 */
void queens(void);
#endif // FUNCTION_H
