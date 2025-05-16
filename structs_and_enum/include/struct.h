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
 * - @ref using_struct 结构体的演示。
 */


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
 * @ingroup struct_group
 * @brief 学生信息结构体。
 * @details 用于存储学生的基本信息及成绩数据，包括学号、姓名、性别及各科成绩。
 */
struct Student {
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
};

#endif // STRUCT_H
