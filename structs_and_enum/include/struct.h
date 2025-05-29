//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.

#ifndef STRUCT_H
#define STRUCT_H

#include "structs_and_enum.h"

/**
 * @file struct.h
 * @defgroup struct_group struct
 * @brief 结构体模块。
 * @details 主要包含：
 * - @ref using_struct 结构体的演示
 * - @ref Student 学生信息
 * - @ref sorting_score 学生成绩排序
 */

/**
 * @ingroup struct_group
 * @brief 学生信息结构体。
 * @details 用于存储学生的基本信息及成绩数据，包括学号、姓名、性别及各科成绩。
 */
typedef struct Student { /* typedef 类型 别名 */
    /** 学生编号 */
    int _number;
    /** 学生姓名 */
    char _name[25];
    /**
     * @brief 学生性别。
     * @details 该字段用于表示学生的性别，仅允许以下两种取值：
     * - 'f': 表示女性 (female)。
     * - 'm': 表示男性 (male)。
     */
    char _gender;
    /** 语文成绩 */
    int _chinese;
    /** 数学成绩 */
    int _math;
    /** 英语成绩 */
    int _english;
} student; /* student 是结构体别名 */


/**
 * @brief 打印学生信息。
 * @details 根据传入的学生结构体指针，打印学生的学号、姓名、性别及各科成绩。
 * @ingroup struct_group
 * @param s 指向学生结构体的常量指针，包含学生的基本信息及成绩数据。
 * @return 无返回值。
 */
void
print_stu_info(const struct Student* s);


/**
 * @brief 演示结构体的使用。
 * @details 该函数展示了如何定义、初始化和操作结构体变量，特别是 @ref Student 结构体。
 * - 定义多个 @ref Student 类型的实例演示。
 * - 初始化学生的详细信息（如学号、姓名、性别及各科成绩）。
 * - 打印或处理这些学生数据以展示结构体的操作方法。
 * @ingroup struct_group
 */
void using_struct(void);


/**
 * @brief 成绩排序。
 * @details
 * 从键盘中录入5个学生的信息，然后对学生进行排序。排序规则如下：
 * 先按总分从高到低排序，如果总分一样，依次按语文、数学、英语的分数从
 * 高到低进行排序；如果各科成绩都一样，则按照名字的字典顺序从小到大进行排序。
 * @ingroup struct_group
 */
void sorting_score(void);
#endif // STRUCT_H
