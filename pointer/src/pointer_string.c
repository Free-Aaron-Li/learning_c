//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "pointer_string.h"

/* 定义足够长的字符数组长度 */
#define N 100

/* @brief 获取数组的长度 */
#define SIZE(a) (sizeof(a) / sizeof(a[0]))

/**
 * @brief 将数字转换为对应的十六进制字符
 * @details
 * 通过查找字符串索引的方式，将0-15的整数转换为对应的十六进制字符(0-9,A-F)
 * @ingroup pointer_string_group
 * @param digit 需要转换的整数(0-15)
 * @return 返回对应的十六进制字符
 */
char
digit_to_hex_char(const int digit) {
    if (digit >= 0 && digit < 16) {
        return "0123456789ABCDEF"[digit];
    }
    exit(EXIT_FAILURE);
}


void
string_usage(void) {
    /* 1. 书写方式 */
    printf("I love xixi"
            "  --From peanut\n");

    /* 2. 存储方式 */
    const char* p_str = "hello";
    printf("%c\n", p_str[1]);
    printf("%c\n", "Hello"[0]);
    printf("%c\n", digit_to_hex_char(15));

    /* 3. 字符串的表示 */
    const char arr[] = { 'H', 'E', 'L', '\0', 'L', 'O', '\n', 'w', 'o', '\0' };
    printf("arr length: %lu\n", SIZE(arr));      /* 10 */
    printf("string length: %lu\n", strlen(arr)); /* 3 */

    /* 4. 字符串的定义和初始化 */
    const char s1[] = { 'H', 'E', 'L', 'L', 'O', '\0' };
    const char s2[] = "HELLO"; /* 语法糖，它就是数组初始化s1的简写形式 */
    const char* s3 = "HELLO";  /* 字符串字面值，不允许修改 */
    const char s4[10] = "HELLO";
    const char s5[6] = "HELLO";
    const char s6[5] = "HELLO"; /* 不表示字符串，因为没有“\0”尾缀 */

    printf("s6: %s\n",
           s6); /* 由于%s表示拼接的是字符串，
                 * 需要一直遇到“\0”才结束。连续输出两次HELLO，是因为后续内容为s5字符串字面值内容。
                 */
}


/**
 * @brief 自定义计算字符串长度
 * @details 遍历字符串，统计字符数直到遇到'\0'为止，返回字符串长度
 * @ingroup pointer_string_group
 * @param s 指向以'\0'结尾的字符串的指针
 * @return 返回字符串的长度(size_t类型)
 */
size_t
my_strlen(const char* s) {
    /* 方式一 */
    /*size_t len = 0;
    while (*s != '\0') {
        ++len;
        ++s;
    }
    return len;*/

    /* 方式二 */
    const char* p = s; /* 遍历字符串 */
    while (*p) {       /* *p不指向空字符 */
        /* 如果采用*p++，会导致潜在的越界访问 */
        ++p; /* 相较于方式一，减少一个自增运算 */
    }
    return p - s;
}


/**
 * @brief 自定义复制字符串
 * @details
 * 将源字符串src复制到目标字符串dest中，包括末尾的'\0'，返回目标字符串起始地址
 * @ingroup pointer_string_group
 * @param dest 目标字符串指针
 * @param src 源字符串指针
 * @return 返回目标字符串的起始地址(char*类型)
 */
char*
my_strcpy(char* dest, const char* src) {
    char* start = dest; /* 保存起始地址 */

    /* 方式一 */
    //
    // while (*src) {
    //     *dest = *src;
    //     ++dest;
    //     ++src;
    // }
    // *dest = '\0'; /* 以空字符结尾 */
    //

    /* 方式二 */
    while (*dest++ = *src++);

    return start;
}


/**
 * @brief 自定义字符串拼接
 * @details 将源字符串src的内容追加到目标字符串dest的末尾，包括末尾的'\0'，返回目标字符串的起始地址。
 *          函数首先找到目标字符串dest的末尾，然后将源字符串src的内容复制到该位置。
 * @ingroup pointer_string_group
 * @param dest 目标字符串指针
 * @param src 源字符串指针
 * @return 返回目标字符串的起始地址(char*类型)
 */
char*
my_strcat(char* dest, const char* src) {
    char* start = dest;
    /* 1. 找到dest的末尾，遍历dest */
    while (*dest) {
        ++*dest;
    } /* dest指向空字符 */

    /* 2. 复制src */
    while (*dest++ = *src++);
    return start;
}


/**
 * @brief 自定义字符串比较
 * @details 按字典序（ASCII码值）比较两个字符串。
 *          如果字符不同，则返回两字符的差值；
 *          如果一个字符串提前结束，则返回剩余字符与'\0'的差值。
 * @ingroup pointer_string_group
 * @param s1 指向第一个以'\0'结尾的字符串的指针
 * @param s2 指向第二个以'\0'结尾的字符串的指针
 * @return 返回值规则如下：
 *         - 若s1 == s2，返回0
 *         - 若s1 > s2， 返回正数
 *         - 若s1 < s2， 返回负数
 */
int
my_strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2) {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        ++s1;
        ++s2;
    }
    /* 剩余情况：
     * *s1 == '\0'
     * *s2 == '\0'
     */
    return *s1 - *s2;
}


void
operating_string(void) {
    char s1[] = "hello world!";

    /* 1. 字符串长度 */
    /* size_t strlen(const char* s)
     * 计数不包含“\0"。
     */
    printf("strlen(\"abc\") = %lu\n", strlen("abc"));
    printf("strlen(\"abc\") = %lu\n", my_strlen("abc"));

    /* 2. 字符串拼接 */
    /* char* strcat(char* dest, const char* src){
     *    strcpy(dest+strlen(dest),src);
     *    return dest;
     * }
     * str: string; cat: concatenate
     */
    printf("%c\n", *("abc" + 1));       /* abc本质上是指针指向的可读不可写字符数组 */
    printf("%s\n", strcat(s1, "xixi")); /* 虽可以正常打印，但是存在数组越界！ */
    char s2[N] = "hello world!";
    /* n 表示s2中剩余空间字符数，意味将src中最多n个字符追加到s2字符串的末尾 */
    printf("%s\n", strncat(s2, "xixi", sizeof(s2) - strlen(s2) - 1));
    s2[sizeof(s2) - 1] = '\0';

    /* 3. 字符串拷贝 */
    /* char* strcpy(char* dest, const char* src);
     * 弊端：不会检查数组越界！
     */
    char s3[] = "Hello";
    const char* s4 = "World! Welcome! ";
    strcpy(s3, s4);
    printf("s3: %s\n", s3); /* 数组越界 */
    /* 解决思路：strncpy */
    strncpy(s3, s4, sizeof(s3) - 1);
    s3[sizeof(s3) - 1] = '\0';

    /* 4. 字符串比较 */
    /* int strcmp (const char* p1, const char* p2)
     * s1 == s2：返回0
     * s1 >  s2：返回正数
     * s1 <  s2：返回负数
     * 比较规则：字典序（ASCII）
     * a>A，b>a，相同字符序列比长度。
     */
    printf("strcmp(\"abc\",\"def\") = %d\n", strcmp("abc", "def")); /* <0 */
    printf("strcmp(\"ab\",\"abc\") = %d\n", strcmp("ab", "abc"));   /* <0 */
    printf("strcmp(\"abc\",\"ABC\") = %d\n", strcmp("abc", "ABC")); /* >0 */
}


void
string_io(void) {
    char s1[] = "Hello world!";
    /* 1. 输出 */
    /* a. printf + %s
     * b. puts(str) 等价于 printf("%s\n", str);
     */
    printf("%s\n", s1);
    puts(s1);

    /* 2. 输入 */
    /* a. scanf + %s，忽略前置空白字符，读取字符填入字符数组，
     *    遇到空白字符结束。
     *    局限性：不能读取空白字符；不能检查数组越界。
     *    应用场景：读取单词（以空白字符分隔）
     * b. fgets(str, sizeof(line)), stdin)，由于gets函数在C11标准中已经被移除。
     *    使用 gets 可能会导致缓冲区溢出，因为它不会检查输入的长度。
     */
    char str[N];
    scanf("%s", str);
    printf(str);

    char line[N];
    fgets(line, sizeof(line),stdin); /* 会自动加上'\0' */
    printf(line);
}


void
string_array(void) {
    /* 1. 使用二维数组存储字符串 */
    const char planets[][8] = { "Mercury", "Venus", "Earth", "Mars",
                                "Jupiter",
                                "Saturn", "Uranus", "Neptune" };
    printf("%s\n", planets[1]);
    /* 上述方式的缺点：
     * a. 如果字符串之间长度差异很大，就会浪费内存空间；
     * b. 不够灵活，如果需要对上述数组排序，就需要复制整个字符串中内容。
     */

    /* 2. 字符指针数组（推荐） */
    char* planets_ptr[] = { "Mercury", "Venus", "Earth", "Mars",
                            "Jupiter",
                            "Saturn", "Uranus", "Neptune" };
    printf("%s\n", planets_ptr[1]);
    /* 上述方式的优点：
     * a. 非常灵活。
     */
}
