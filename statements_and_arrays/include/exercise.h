//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me know:
//   <communicate_aaron@outlook.com>.
#ifndef TEST_H
#define TEST_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** @brief  利用 switch
 * 语句编写一个程序，把用数字表示的成绩转换为字母表示的等级。
 *
 * 评定规则为：A 为 90~100，B 为 80~89，C 为 70~79，D 为
 * 60~69，F 为 0~59。
 * 如果成绩高于 100 或者低于0，则显示出错消息。
 * @code
 * Enter numerical grade: 84
 * Letter grade: B
 * @endcode
 */
void output_letter_grade(void);

/** @brief 计算一个整数的位数。 */
void output_the_digits_of_integer(void);

/** @brief
 * 开发一个记账程序。程序将为用户提供选择菜单：清空账户余额，往账户上存钱，从账户上取钱，显示当前余额，退出程序。
 * 选择项分别用整数0、1、2、3 和 4 表示。*/
void bookkeeping_procedures(void);

/** @brief
 * 用户输入初始金额，利率和投资年数，程序将打印一张表格。
 * 表格将显示输入的利率以及紧随其后4个更高利率下的总金额。
 * 程序的会话如下：
 * @code
 * Enter initial balance: 100
 * Enter interest rate: 6
 * Enter number of years 5
 * Years    6%     7%     8%     9%    10%
 *   1    106.00 107.00 108.00 109.00 110.00
 *   2    112.36 114.49 116.64 118.81 121.00
 *   3    119.10 122.50 ...
 *   4    ...
 *   5    ...
 * @endcode
 */
void interest_rate_earnings(void);

/** @brief 随机发牌
 * @details 用户指定发几张牌，程序打印手牌。
 * @code
 * Enter number of cards in hand: 5
 * Your hand: 9c 7d 3c 5d kd
 * @endcode
 */
void cards_are_dealt_randomly(void);
#endif // TEST_H
