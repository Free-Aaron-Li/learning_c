//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "pointer_string.h"

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
char digit_to_hex_char(const int digit) {
  if (digit >= 0 && digit < 16) {
    return "0123456789ABCDEF"[digit];
  }
  exit(EXIT_FAILURE);
}

void string_usage(void) {
  /* 1. 书写方式 */
  printf("I love xixi"
         "  --From peanut\n");

  /* 2. 存储方式 */
  const char *p_str = "hello";
  printf("%c\n", p_str[1]);
  printf("%c\n", "Hello"[0]);
  printf("%c\n", digit_to_hex_char(15));

  /* 3. 字符串的表示 */
  const char arr[] = {'H', 'E', 'L', '\0', 'L', 'O', '\n', 'w', 'o', '\0'};
  printf("arr length: %lu\n", SIZE(arr));      /* 10 */
  printf("string length: %lu\n", strlen(arr)); /* 3 */

  /* 4. 字符串的定义和初始化 */
  const char s1[] = {'H', 'E', 'L', 'L', 'O', '\0'};
  const char s2[] = "HELLO"; /* 语法糖，它就是数组初始化s1的简写形式 */
  const char *s3 = "HELLO";  /* 字符串字面值，不允许修改 */
  const char s4[10] = "HELLO";
  const char s5[6] = "HELLO";
  const char s6[5] = "HELLO"; /* 不表示字符串，因为没有“\0”尾缀 */

  printf(
      "s6: %s\n",
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
size_t my_strlen(const char *s) {
  /* 方式一 */
  /*size_t len = 0;
  while (*s != '\0') {
      ++len;
      ++s;
  }
  return len;*/

  /* 方式二 */
  const char *p = s; /* 遍历字符串 */
  while (*p) {       /* *p不指向空字符 */
                     /* 如果采用*p++，会导致潜在的越界访问 */
    ++p;             /* 相较于方式一，减少一个自增运算 */
  }
  return p - s;
}

void operating_string(void) {
  char s1[] = "hello world!";

  /* 1. 字符串长度 */
  /* size_t strlen(const char* s) */
  printf("strlen(\"abc\") = %lu\n", strlen("abc"));
  printf("strlen(\"abc\") = %lu\n", my_strlen("abc"));
}
