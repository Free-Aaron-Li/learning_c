//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.

#ifndef EXERCISE_POINTER_H
#define EXERCISE_POINTER_H

#include "pointer.h"

/**
 * @file pointer_exercise.h
 * @defgroup pointer_exercise_group exercise
 * @brief 指针与字符串的练习
 * @details 主要包含：
 * - @ref split_time 秒时间转换；
 * - @ref find_two_largest 查找数组前二最大元素；
 * - @ref reverse_print 逆序打印消息；
 * - @ref palindrome 检查回文；
 * - @ref find_max_min_word 找出最小和最大单词。
 */


/**
 * @brief 秒时间转换
 * @details
 * 从午夜12:00开始计算的秒数（ @a total_sec ），请将 @a total_sec
 * 转换以时（0~23）、分（0~59）、秒（0~59）表示的时间，并存放到函数
 * 外部由指针 @a hour、@a minute、@a second 指向的变量中。并在
 * 外部打印出当前时间。
 * 由于 @a total_sec 以值传递方式，无需添加 @b const ，但是在实现函数中
 * 添加 @b const 是为了更好地阅读，遵循编码规范。
 * @ingroup pointer_exercise_group
 * @param total_sec 总时间（秒数）
 * @param hour 转换得到的小时段表示
 * @param minute 转换得到的分钟段表示
 * @param second 转换得到的秒数段表示
 */
void split_time(long total_sec, int* hour, int* minute, int* second);

/**
 * @brief 查找整数数组前二最大元素。
 * @details
 * 查找数组中最大的元素和第二大的元素，并将它们分别放在由 @a largest 和
 * @a second_largest 指向的变量中。
 * @attention 为了简化程序，数组不存在重复元素。
 * @ingroup pointer_exercise_group
 * @param arr 传入整数元素数组
 * @param n 传入数组长度
 * @param largest 数组中最大元素
 * @param second_largest 数组中第二大元素
 */
void
find_two_largest(const int arr[], int n, int* largest,
                 int*      second_largest);


/**
 * @brief 逆序打印一条消息
 * @details 读取一条消息，然后逆序打印这条消息。示例如下：
 * @code
 * Enter a message: Don't get mad, get even.
 * Reversal is: .neve teg ,dam teg t'noD
 * @endcode
 * @ingroup pointer_exercise_group
 * @note
 * 一次读取消息中的一个字符（用getchar函数），并且把这些字母存储在数组中，
 * 当数组满了或者读到字符 @c \n 时停止读操作。
 * @param string 待逆序打印消息
 */
void
reverse_print(void);

/**
 * @brief 检查回文
 * @details
 * 编写程序读一条消息，然后检查这条消息是否是回文
 * （消息从左往右看和从右往左看一致）。示例如下：
 * @code
 * Enters a message: He lived as a devil, eh?
 * Palindrome
 *
 * Enters a message: Madam, I am Adam.
 * Not a palindrome
 * @endcode
 * @attention 忽略所有不是字母的字符。用索引（或指针）来跟踪数组中的位置。
 * @ingroup pointer_exercise_group
 */
void palindrome();

/**
 * @brief 找出最小和最大单词
 * @details
 * 找出一组单词中最小单词和最大单词。当用户输入4个字母的单词时，程序停止读入。
 * 假设所有单词都不超过20个字母，程序会话如下：
 * @code
 * Enter word: dog
 * Enter word: zebra
 * Enter word: rabbit
 * Enter word: cat
 *
 * Smallest word: cat
 * Largest word : zebra
 * @endcode
 * @note
 * 使用两个名为 @a smallest_word 和 @a largest_word 的字符串来分别记录
 * 最小单词和最大单词。用户每输入一个新单词，都要用 @a strcmp 把它与 @a smallest_word
 * 和 @a largest_word 进行比较。用 @a strlen 函数判断用户是是否输入了4个字母的单词。
 * @ingroup pointer_exercise_group
 */
void find_max_min_word(void);

#endif //EXERCISE_POINTER_H
