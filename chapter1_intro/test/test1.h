// This file is part of 'learning' project.
// This program is called: 'test1'.
// If there are no special instructions, this file is used as an exercise and test file.
#ifndef TEST1_H
#define TEST1_H

#include <stdio.h>

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
 * @details 做个实验，当printf函数的参数字符串中包含\c（其中c是上面的转移字符序列中未曾列出的某个字符）时，观察一下会出现什么情况。
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
#endif //TEST1_H
