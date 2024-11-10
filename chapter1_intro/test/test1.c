// Copyright (c) 2024. aaron.
//
// This program is under the GPL-3.0 license.
// if you have not received it or the program has a bug, please let me know:
// <communicate_aaron@outlook.com>.

// This file is part of 'learning' project.
// This program is called: 'test1'.
// Implementation of "test1.h".
#include  "test1.h"

// 完整的gcc编译流程：
// 编译：gcc -S main.c
// 汇编：gcc -c main.s
// 链接：gcc -o main main.o
// 运行：./main
void
test1_1() {                    // 定义名为main的函数，不接受参数值
    printf("Hello, World!\n"); // main函数调用库函数printf以显示字符序列；\n表示换行符
}

void
test1_2() {
    printf("Hello, World!\c\n");
}

void
test1_3() {
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

void
test1_4() {
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

void
test1_5() {
    printf("0-300 华氏温度与摄氏温度对照表\n");
    for (int fahr = 300; fahr >= 0; fahr = fahr - 20) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}

void
test1_6() {
    int c;
    printf("%d", (c = getchar()) != EOF); // 1
}

void
test1_7() {
    // #define EOF (-1)
    printf("%d",EOF);
}

void
test1_8() {
    int  c;
    long num_chars = 1;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            ++num_chars;
        }
    }

    printf("%ld\n", num_chars);
}

#define NOTASPACE 'a'

void
test1_9() {
    int c; // 读取字符

    /* 读取到字符的上一个字符 */
    int last_c = NOTASPACE;
    while ((c = getchar()) != EOF) {
        /* 上一个字符不是空格 */
        if (c != ' ' || last_c != ' ') {
            putchar(c);
        }
        last_c = c;
    }
}

void
test1_10() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\"); // 需要进行\进行两个转义
        } else {
            putchar(c);
        }
    }
}

#define IN 1 /* 在单词内 */
#define OUT 0 /* 在单词外 */

void
test1_11() {
    int c     = 0;
    int nl    = 0;
    int nw    = 0;
    int nc    = 0;
    int state = OUT;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') { /* 行计数 */
            ++nl;
        }
        if (c == ' ' || c == '\n' || c == '\t') { /* 在单词外 */
            state = OUT;
        } else if (state == OUT) { /* 单词内，单词计数 */
            state = IN;
            ++nw;
        }
    }
    printf("%d %d %d\n", nl, nw, nc);
}

void
test1_12() {
    int c     = 0;
    int state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t' || c == ',' || c == '.' || c == '!' || c == '?') {
            if (state == IN) {
                putchar('\n'); /* 单词输出完毕 */
                state = OUT;
            }
        } else if (state == OUT) { /* 输出单词首字符 */
            state = IN;
            putchar(c);
        } else {
            putchar(c); /* 输出单词中间字符 */
        }
    }
}

#define MAXWORDWIDTH 45 /* 最长字母宽度 */
/*
 * 参考牛津字典中，最长单词：“pneumonoultramicroscopicsilicovolcanoconiosis”，
 * 译为：由于吸入非常细的硅酸盐或石英尘而引起的肺部疾病，超微粒硅酸盐尘埃沉着症。
 */

void
test1_13() {
    int c;
    int state      = OUT;
    int word_width = 0;
    int words_table[MAXWORDWIDTH];

    /* 初始化字母长度表 */
    for (int i = 0; i < MAXWORDWIDTH; ++i) {
        words_table[i] = 0;
    }

    /* 判断单词并给出单词长度存入长度表中 */
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t' || c == ',' || c == '.' || c == '!' || c == '?') {
            if (state == IN) {
                ++words_table[word_width - 1]; /* 结束单词长度计数，存入长度表中 */
                word_width = 0;
                state      = OUT;
            }
        } else if (state == OUT) { /* 开始单词长度计数 */
            state = IN;
            ++word_width;
        } else {
            ++word_width;
        }
    }

    /* 单词长度频度水平方向直方图打印 */
    printf("水平方向单词长度频度直方图：\n");
    for (int i = 0; i < MAXWORDWIDTH; ++i) {
        printf("%d: ", i);                         /* 输入单词长度标头 */
        for (int j = 0; j < words_table[i]; ++j) { /* 打印频度 */
            printf("*");
        }
        printf("\n");
    }

    /* 单词长度频度垂直方向直方图打印 */
    printf("\n垂直方向单词长度频度直方图：\n");
    /* 1.输出行首标头 */
    for (int i = 0; i < MAXWORDWIDTH; ++i) {
        printf("%d ", i + 1);
    }
    printf("\n");

    /* 2.行输出 */
    for (int line = 0; line < MAXWORDWIDTH; ++line) {
        /* 单行输出 */
        for (int i = 0; i < MAXWORDWIDTH; ++i) {
            if (words_table[i] != 0) {
                printf("* ");
                --words_table[i];
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

#define LETTERS 26

void
test1_14() {
    int c;
    int letters_table[LETTERS];

    /* 初始化字母次数表 */
    for (int i = 0; i < LETTERS; ++i) {
        letters_table[i] = i;
    }

    /* 填入字母次数表 */
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            ++letters_table[c - 'a'];
        }
    }

    /* 水平方向直方图打印 */
    printf("水平方向字母频度直方图：\n");
    for (int i = 0; i < LETTERS; ++i) {
        printf("%c: ", i + 'a');
        for (int j = 0; j < letters_table[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }

    /* 垂直方向直方图打印 */
    printf("\n垂直方向字母频度直方图：\n");
    /* 1.输出行首标题 */
    for (int i = 0; i < LETTERS; ++i) {
        printf("%c ", i + 'a');
    }
    printf("\n");

    /* 2.计算直方图高度 */
    int table_high = 0; /* 字母次数表中最大次数，确定直方图高度 */
    for (int i = 0; i < LETTERS; ++i) {
        if (letters_table[i] > table_high) {
            table_high = letters_table[i];
        }
    }

    /* 3.行输出 */
    for (int line = 0; line < table_high; ++line) {
        /* 每行输出 */
        for (int i = 0; i < LETTERS; ++i) {
            if (letters_table[i] != 0) {
                printf("* ");
                --letters_table[i];
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

}
