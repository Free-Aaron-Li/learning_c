//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "st_and_em_exercise.h"

/**
 * 交换 @ref Student 结构体对象
 * @ingroup exercise_se_group
 * @param arr 学生数组
 * @param i 待交换学生对象
 * @param j 待交换学生对象
 */
#define SWAP(arr,i,j) {         \
    struct Student t = arr[i];  \
    arr[i]=arr[j];              \
    arr[j] = t;                 \
}


/**
 * @brief 打印每门课程最高分的学生信息。
 * @details 遍历学生数组，分别找到语文、数学和英语最高分的学生，并打印其信息。
 * @ingroup exercise_se_group
 * @param students 学生数组，包含每个学生的成绩信息。
 * @param n 学生数组的长度，表示学生人数。
 */
void
print_highest_score(const struct Student students[], const int n) {
    int idx1 = 0, idx2 = 0, idx3 = 0;
    for (int i = 0; i < n; ++i) {
        if (students[i]._chinese > students[idx1]._chinese) {
            idx1 = i;
        }
        if (students[i]._math > students[idx1]._math) {
            idx2 = i;
        }
        if (students[i]._english > students[idx1]._english) {
            idx3 = i;
        }
    }
    printf("各项最高分得主：\n");
    print_stu_info(&students[idx1]);
    print_stu_info(&students[idx2]);
    print_stu_info(&students[idx3]);
}


/**
 * @brief 打印每门课程的平均分。
 * @details 遍历学生数组，计算语文、数学和英语的总分，并输出各科的平均分。
 * @ingroup exercise_se_group
 * @param students 学生数组，包含每个学生的成绩信息。
 * @param n 学生数组的长度，表示学生人数。
 */
void
print_average_score(const struct Student students[], const int n) {
    int total_chinese = 0, total_math = 0, total_english = 0;
    for (int i = 0; i < n; ++i) {
        total_chinese += students[i]._chinese;
        total_math += students[i]._math;
        total_english += students[i]._english;
    }
    printf("平均分分别为：语文：%d，数学：%d，英语：%d\n",
           total_chinese / n,
           total_math / n,
           total_english / n);
}


/**
 * @brief 计算学生的总分。
 * @details 根据学生的语文、数学和英语成绩，计算并返回总分。
 * @ingroup exercise_se_group
 * @param s 指向学生结构体的指针，包含学生的成绩信息。
 * @return 返回学生的总分（语文、数学和英语成绩之和）。
 */
int
total_student_score(const struct Student* s) {
    return s->_chinese + s->_math + s->_english;
}


/**
 * @brief 按总分对学生数组进行降序排序。
 * @details 使用选择排序算法，根据每个学生的总分（语文、数学和英语成绩之和）对学生数组进行降序排序，并打印排序后的学生信息。
 * @ingroup exercise_se_group
 * @param students 学生数组，包含每个学生的成绩信息。
 * @param n 学生数组的长度，表示学生人数。
 */
void
sort_students_score(struct Student students[], const int n) {
    /* 选择排序 */
    for (int i = 0; i < n - 1; ++i) {
        int idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (total_student_score(&students[j]) > total_student_score(
                    &students[idx])) {
                idx = j;
            }
        }
        SWAP(students, i, idx);
    }
    printf("总分排序后排名为：\n");
    for (int i = 0; i < n; ++i) {
        print_stu_info(&students[i]);
    }
}


void
struct_exercise(void) {
    struct Student students[5];

    /* 1. 读取数据 */
    for (int i = 0; i < 5; ++i) {
        scanf("%d%s %c%d%d%d",
              &students[i]._number,
              students[i]._name,
              &students[i]._gender,
              &students[i]._chinese,
              &students[i]._math,
              &students[i]._english);
    }

    /* 2. 输出每门课程最高分学生信息 */
    print_highest_score(students, 5);

    /* 3. 各科平均分 */
    print_average_score(students, 5);

    /* 4. 排序总分 */
    sort_students_score(students, 5);
}
