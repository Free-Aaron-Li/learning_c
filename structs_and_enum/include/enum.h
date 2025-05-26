//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.

#ifndef ENUM_H
#define ENUM_H

#include "structs_and_enum.h"

/**
 * @file enum.h
 * @defgroup enum_group enum
 * @brief 枚举模块。
 * @details 主要包含：
 * - @ref using_enum 枚举的演示。
 */


/**
 * @brief 演示枚举的使用方法。
 * @details 该函数通过示例代码展示如何定义、初始化和操作枚举类型，帮助开发者理解
 * 枚举的基本用法及其在程序中的实际应用场景。
 * @ingroup enum_group
 */
void using_enum(void);


/**
 * @brief 定义扑克牌花色枚举类型。
 * @details 包含四种花色：方块 (DIAMOND)、梅花 (CLUB)、红心 (HEART)、黑桃 (SPADE)。
 * @ingroup enum_group
 */
enum SUIT {
    DIAMOND, CLUB, HEART, SPADE
};

/**
 * @brief 定义整数字符枚举。
 * @details 通过给枚举类型起别名，避免每次声明枚举类型都需要加上`enum`关键字。
 * @ingroup enum_group
 */
typedef enum {
    ZERO,
    ONE,
    TWO
} INTEGER;

#endif //ENUM_H
