//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.

#ifndef EXERCISE_H
#define EXERCISE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * @file exercise.h
 * @defgroup function_exercise_group function exercise
 * @brief 基础练习功能模块。
 * @details 主要包含：
 * - @ref judgement_num_is_prime 判断素数；
 * - @ref roll_the_dices_game 掷骰子游戏；
 * - @ref texas_holdem_game 德州扑克游戏。
 * @ingroup function_group
 */

/**
 * @brief 判断一个整数是否为素数。
 * @details 用户输入整数，程序显示该数是否为素数。会话如下：
 * @code
 * Enter a number: 34
 * Not prime
 * @endcode
 *
 * @ingroup function_exercise_group
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
 *
 * @ingroup function_exercise_group
 */
void roll_the_dices_game(void);

/**
 * @brief 德州扑克游戏
 *
 * @details 写一个程序循环读取5张手牌（输入 0 结束程序）。
 *
 * @note 德州扑克规则：
 * 手牌分类：同花顺、四张、葫芦、同花、顺子、三张、两对、一对、高牌。\n
 * 1. 同花顺（Straight Flush）：
 * 五张同花色的连续数字牌，如：红桃10-J-Q-K-A。
 * 2. 四张（Four of a kind）：
 * 四张相同数字的牌，加上一张其他数字的牌，如：A-A-A-A-K
 * 3. 葫芦（Full house）：
 * 三张相同数字的牌，加上一对其他数字的牌，如：A-A-A-K-K
 * 4. 同花（Flush）：
 * 五张同花色的牌，但不是顺子，如：红桃2-5-7-8-K
 * 5. 顺子（Straight）：
 * 由五张连续数字的牌组成（简单起见，A-2-3-4-5不是顺子），但不是同花。
 * 如：2-3-4-5-6，但包含不同花色的牌。
 * 6. 三张（Three of a kind）：
 * 由三张相同数字的牌，加两张不同数字的牌组成，如：A-A-A-2-K
 * 7. 两对（Two pairs）：
 * 由两对加上一张杂牌组成。如：A-A-K-K-2
 * 8. 对子（Pair）：
 * 由一对加上三张不同的牌组成。如：A-A-5-6-K
 * 9. 高牌（High card）：
 * 无法组成上述任意牌型的杂牌。如：2-5-8-10-Q，且包含多种花色的牌。
 *
 * 程序对话如下：
 * @code
 * Enter a card: 2s
 * Enter a card: 5s
 * Enter a card: 4s
 * Enter a card: 3s
 * Enter a card: 6s
 * Straight flush
 *
 * Enter a card: 8c
 * Enter a card: as
 * Enter a card: 8c
 * Duplicate card; ignored.
 * Enter a card: 7c
 * Enter a card: ad
 * Enter a card: 3h
 * Pair
 *
 * Enter a card: 6s
 * Enter a card: d2
 * Bad card; ignored.
 * Enter a card: 2d
 * Enter a card: 9c
 * Enter a card: 4h
 * Enter a card: ts
 * High card
 *
 * Enter a card: 0
 * @endcode
 *
 * @ingroup function_exercise_group
 */
void texas_holdem_game(void);

/**
 * @brief 扑克牌花色数量
 *
 * @details 花色分别为：
 * 1. 💎 钻石（Diamond）
 * 2. ♣ 梅花（Club）
 * 3. ♥️ 红心（Heart）
 * 4. ♠️ 黑桃（Spade）
 *
 * @ingroup function_exercise_group
 */
extern char num_in_suits[4];

/**
 * @brief 数字牌数量
 * @details 其中用`T`表示数字10。
 * @ingroup function_exercise_group
 */
extern char num_in_ranks[13];

/**
 * @brief 同花
 *
 * @ingroup function_exercise_group
 */
extern bool flush;

/**
 * @brief 顺子
 *
 * @ingroup function_exercise_group
 */
extern bool straight;

/**
 * @brief 四张
 *
 * @ingroup function_exercise_group
 */
extern bool four;

/**
 * @brief 三张
 *
 * @ingroup function_exercise_group
 */
extern bool three;

/**
 * @brief 对子
 *
 * @details 对子可能存在0、1、2三种值。
 *
 * @ingroup function_exercise_group
 */
extern int pairs;
#endif // EXERCISE_H
