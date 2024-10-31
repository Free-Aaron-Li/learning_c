// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'learning' project.
// This program is called: 'test1'.
// Chapter1 test programs.
#ifndef TEST1_H
#define TEST1_H

#include <stdio.h>
#include <string.h>

/**
 * @brief 练习1-1
 * @details 在你自己的系统中运行“hello, world”程序。再有意去掉程序中的部分内容，看看会得到什么出错结果。
 */
void test1_1();

// 1. 去掉头文件
// 得到错误：无法解析符号'printf'，但是程序正常运行。
// 2. 去掉main()函数
// 得到错误：未定义对'main'的引用，程序执行失败。
// 3. 去掉printf()函数
// 程序正常运行，没有输出结果。

/**
 * @brief 练习1-2
 * @details 做个实验，当printf函数的参数字符串中包含\\c（其中c是上面的转移字符序列中未曾列出的某个字符）时，观察一下会出现什么情况。
 */
void test1_2();

// 警告：参数在编译时未被使用。

/**
 * @brief 练习1-3
 * @details 修改温度转换程序，使之能在转换表的顶部打印一个标题。
 */
void test1_3();

/**
 * @brief 练习1-4
 * @details 编写一个程序打印摄氏温度转换为相应华氏温度的转换表。
 */
void test1_4();

/**
 * @brief 练习1-5
 * @details 修改温度转换程序，要求以逆序（即按照从300度到0度的顺序）打印温度转换表。
 */
void test1_5();

/**
 * @brief 练习1-6
 * @details 验证表达式getchar()!=EOF的值是0还是1。
 */
void test1_6();

/**
 * @brief 练习1-7
 * @details 编写一个打印EOF值的程序。
 */
void test1_7();

/**
 * @brief 练习1-8
 * @details 编写一个统计空格、制表符和换行符个数的程序。
 */
void test1_8();

/**
 * @brief 练习1-9
 * @details 编写一个ie将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替。
 */
void test1_9();

/**
 * @brief 练习1-10
 * @details 编写一个将输入复制到输出的程序，并将其中的制表符替换为\\t，将回退符替换为\\b，将反斜杠替换为\\\。这样可以将制表符和回退符以可见的方式打印出来。
 */
void test1_10();

/**
 * @brief  练习1-11
 * @details 你准备如何测试单词计数程序？如果程序中存在某种错误，那么什么样的输入最可能发现这类错误呢？
 */
void test1_11();

/*
 * 1. 没有输入
 * 2. 没有单词（仅有换行符）
 * 3. 没有单词（只有空格、制表符和换行符）
 * 4. 每个单词各占一行的情况（没有空格和制表符）
 * 5. 单词出现于文本行行首的情况
 * 6. 单词出现于一串空格之后的情况
 */

/**
 * @brief 练习1-12
 * @details 编写一个程序，以每行一个单词的形式打印其输入。
 */
void test1_12();

/**
 * @brief 练习1-13
 * @details 编写一个程序，打印输入中单词长度的直方图。水平方向的直方图比较容易绘制，垂直方向的直方图则要困难些。
 */
void test1_13();

/**
 * @brief 练习1-14
 * @details 编写一个程序，打印输入中各个字符出现频度的直方图。
 */
void test1_14();
#endif //TEST1_H
