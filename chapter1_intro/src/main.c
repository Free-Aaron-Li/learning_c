#include  "test1.h"

// 完整的gcc编译流程：
// 编译：gcc -S main.c
// 汇编：gcc -c main.s
// 链接：gcc -o main main.o
// 运行：./main

// 测试程序
void test1() {
    // test1_1();
    // test1_2();
    // test1_3();
    // test1_4();
    // test1_5();
    // test1_6();
    test1_7();
}

/* 当fahr=0,20, ..., 300时，分别打印华氏温度与摄氏温度对照表 */
void FahrCelsius() {
    int fahr,  celsius;
    int lower, upper, step;

    lower = 0;   /* 温度表的下限 */
    upper = 300; /* 温度表的上限 */
    step  = 20;  /* 步长 */

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}

void FahrCelsiusFloat() {
    float fahr,  celsius; // 声明为float，转换公式的表述方式更为自然
    int   lower, upper, step;

    lower = 0;
    upper = 300;
    step  = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

void InputOutput1() {
    int c; // 为了能够存储任何可能的字符外还要存储EOF，存储值必须足够大。

    while ((c = getchar()) != EOF) { // !=优先级高于=，所以要加上括号
        putchar(c);
    }
}

void main() { // 定义名为main的函数，不接受参数值
    test1();
    //FahrCelsius();
    //FahrCelsiusFloat();
    // InputOutput1();
}