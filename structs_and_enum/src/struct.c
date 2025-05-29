//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "struct.h"

#include <string.h>


/**
 * @brief 输入学生数据。
 * @details 根据用户输入填充学生结构体的数据，包括学号、姓名、性别及各科成绩。
 * @ingroup struct_group
 * @param s 指向学生结构体的指针，用于存储输入的学生信息。
 * @return 无返回值。
 */
void
input_stu_data(struct Student* s) {
    scanf("%d%s %c%d%d%d",
          &s->_number,
          s->_name,
          &s->_gender,
          &s->_chinese,
          &s->_math,
          &s->_english
        );
}


void
print_stu_info(const struct Student* s) {
    /* 书写方式一 */
    // printf("%d: %s, %c, %d, %d, %d\n",
    //        (*s).number,
    //        (*s).name,
    //        (*s).gender,
    //        (*s).chinese,
    //        (*s).math,
    //        (*s).english);

    /* 书写方式二
     * -> 左边指向结构体指针，右边指向结构体成员
     */
    printf("%d: %s, %c, %d, %d, %d\n",
           s->_number,
           s->_name,
           s->_gender,
           s->_chinese,
           s->_math,
           s->_english
        );
}


void
using_struct(void) {
    /* 1. 定义结构体变量 */
    struct Student s1 = { 1, "xixi", 'f', 100, 100, 100 };
    struct Student s2 = { 2, "jack", 'm', 100 };
    printf("size of s1: %lu\n", sizeof(s1));
    printf("address of gender\t: %p\n", &s1._gender);
    printf("address of chinese\t: %p\n", &s1._chinese);
    /* 二者地址值相差2个字节，说明进行填充操作 */

    /* 2. 结构体变量的操作 */
    /* 2.1 获取成员 */
    printf("%s: %d, %d, %d\n", s1._name, s1._chinese, s1._math, s1._english);
    /* 2.2 赋值（复制）
     * 好处：复制结构体。
     * 坏处：结构体作为参数或者返回值时，会导致整个结构体的复制。
     * 赋值往往传递是指向结构体的指针。
     */
    print_stu_info(&s2);
    s2 = s1;
    print_stu_info(&s1);
    print_stu_info(&s2);


    /* 2.3 输入输出 */
    struct Student s3;
    input_stu_data(&s3);
    print_stu_info(&s3);
}


/**
 * @brief 比较用户成绩及姓名。
 * @details
 * 对总分、语文、数学、外语分别进行由高到低比较；
 * 对姓名按照字典顺序排序。
 * @ingroup struct_group
 * @return 比较值，p1大于（小于）p2返回负值（正值），p1等于p2返回0。
 */
int
compare(const void* p1, const void* p2) {
    /* 通用指针可以转换为任何类型指针 */
    const struct Student* s1 = p1;
    const struct Student* s2 = p2;

    const int total1 = s1->_chinese + s1->_math + s1->_english;
    const int total2 = s2->_chinese + s2->_math + s2->_english;

    /* 总分越高，应该排在前面，逻辑上越小 */
    if (total1 != total2) {
        /* 逆向排序，调用qsort时要交换顺序 */
        return total2 - total1;
    }
    if (s1->_chinese != s2->_chinese) {
        return s2->_chinese - s1->_chinese;
    }
    if (s1->_math != s2->_math) {
        return s2->_math - s1->_math;
    }
    /* 冗余操作，可以忽略
     * 存在相关性：总分=语数外之和
     * 但是后续扩展，此相关性可能会被打破
     */
    if (s1->_english != s2->_english) {
        return s2->_english - s1->_english;
    }

    return strcmp(s1->_name, s2->_name);
}


void
sorting_score(void) {
    struct Student students[5];
    char           temp[25];

    /* 1. 输入 */
    for (int i = 0; i < 5; ++i) {
        scanf("%d%s%d%d%d",
              &students[i]._number,
              temp,
              &students[i]._chinese,
              &students[i]._math,
              &students[i]._english);
        strcpy(students[i]._name, temp);
    }

    /* 2. 比较 */
    qsort(students, 5, sizeof(struct Student), compare);

    /* 3. 输出 */
    for (int i = 0; i < 5; ++i) {
        const int total = students[i]._chinese + students[i]._math +
                          students[i]._english;
        printf("total: %d, chinese: %d, math: %d, english: %d, name: %s.\n",
               total,
               students[i]._chinese,
               students[i]._math,
               students[i]._english,
               students[i]._name
            );
    }
}
