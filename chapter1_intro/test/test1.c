// This file is part of 'learning' project.
// This program is called: 'test1'.
// If there are no special instructions, this file is used as an exercise and test file.
#include  "test1.h"

// 完整的gcc编译流程：
// 编译：gcc -S main.c
// 汇编：gcc -c main.s
// 链接：gcc -o main main.o
// 运行：./main
void test1_1() {               // 定义名为main的函数，不接受参数值
    printf("Hello, World!\n"); // main函数调用库函数printf以显示字符序列；\n表示换行符
}

void test1_2() {
    printf("Hello, World!\c\n");
}

void test1_3() {
    float fahr,  celsius;
    int   lower, upper, step;

    lower = 0;
    upper = 300;
    step  = 20;

    fahr = lower;
    printf("0-300 华氏温度与摄氏温度对照表\n");
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

void test1_4() {
    float fahr,  celsius;
    int   lower, upper, step;

    lower = 0;
    upper = 300;
    step  = 20;

    celsius = lower;
    printf("0-300 摄氏温度与华氏温度对照表\n");
    while (celsius <= upper) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}

void test1_5() {
    printf("0-300 华氏温度与摄氏温度对照表\n");
    for (int fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}

void test1_6() {
    int c;
    printf("%d", (c = getchar()) != EOF); // 1
}

void test1_7() {
    // #define EOF (-1)
    printf("%d",EOF);
}
