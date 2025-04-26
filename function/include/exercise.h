//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me know:
//   <communicate_aaron@outlook.com>.

#ifndef EXERCISE_H
#define EXERCISE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/** @brief 判断一个整数是否为素数。
 * @details 用户输入整数，程序显示该数是否为素数。会话如下：
 * @code
 * Enter a number: 34
 * Not prime
 * @endcode
 */
void judgement_num_is_prime(void);

/** @brief 编写程序模拟掷骰子的游戏（两个骰子）。
 * @details  每局游戏的规则如下：\n
 * 第一次掷的时候，如果点数之和 7 或 11 则获胜；
 * 如果点数之和为 2、3 或 12 则落败；其他情况下的点数之和称为“目标”，游戏继续。
 * 在后续的投掷中，如果玩家再次掷出“目标”点数则获胜，掷出 7
 * 则落败，其他情况都忽略，游戏继续进行。\n\n
 * 每局游戏结束时，程序询问玩家是否再玩一次，如果用户输入的回答不是 y 或
 * Y，程序会显示胜败次数然后终止。
 * @code
 * You rolled: 8
 * Your point is: 8
 * You rolled: 10
 * You rolled: 8
 * You win!
 *
 * Play agin? y
 * You rolled: 6
 * @endcode
 */
void roll_the_dices_game(void);

#endif // EXERCISE_H
