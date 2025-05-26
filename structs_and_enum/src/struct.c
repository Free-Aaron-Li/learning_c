//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "struct.h"


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
