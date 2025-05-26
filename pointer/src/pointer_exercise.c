//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "pointer_exercise.h"

/** 字符数组最大长度 */
#define MAXLINE 128

/* 单个单词最大长度 */
#define MAXWORD 21


void
split_time(const long total_sec, int* hour, int* minute, int* second) {
    /* 1. 将总秒数转换为时分秒 */
    /* 1.1 方式一：过于复杂且不够简洁 */
    // *hour   = (int) (total_sec / 3600);
    // *minute = (int) ((total_sec - (*hour * 3600)) / 60);
    // *second = (int) (total_sec - (*hour * 3600 + *minute * 60));

    /* 1.2 方式二：取余处理 */
    *second = (int) total_sec % 60;
    *minute = (int) (total_sec / 60) % 60;
    *hour   = (int) (total_sec / 60 / 60) % 24;
}


void
find_two_largest(const int arr[], const int n, int* largest,
                 int*      second_largest) {
    /* 初始化 */
    *largest        = arr[0] >= arr[1] ? arr[0] : arr[1];
    *second_largest = arr[0] < arr[1] ? arr[0] : arr[1];

    for (int i = 2; i < n; ++i) {
        if (arr[i] > *largest) {
            *second_largest = *largest;
            *largest        = arr[i];
        } else if (arr[i] > *second_largest) { /* 存在后续数字大于第二最大值情况 */
            *second_largest = arr[i];
        }
    }
}


void
reverse_print() {
    printf("Enter a message: ");
    char message[MAXLINE];
    char c;

    /* 1. 使用数字定位方式 */
    // int  n = 0;
    // while (n < MAXLINE && (c = getchar()) != '\n') {
    //     message[n++] = c;
    // }
    //
    // printf("Reversal is: ");
    // for (int i = n - 1; i >= 0; --i) {
    //     putchar(message[i]);
    // }

    /* 2. 使用指针定位方式 */
    char* p = message;
    while (p < message + MAXLINE && (c = getchar()) != '\n') {
        *p++ = c;
    }

    printf("Reversal is: ");
    --p;
    while (p >= message) {
        putchar(*p--);
    }

    putchar('\n');
}


/**
 * @brief 判断字符串是否为回文字符串。
 * @details 忽略非字母字符并区分大小写，通过索引方式实现。
 * @ingroup pointer_exercise_group
 * @param str 待检查的字符串数组。
 * @param n 字符串的有效长度。
 * @return 如果字符串是回文返回true，否则返回false。
 */
bool
is_palindrome(char str[], int n) {
    int i = 0, j = n - 1;
    while (i < j) {
        while (i < j && !isalpha(str[i])) {
            ++i;
        }
        while (i < j && !isalpha(str[j])) {
            --j;
        }
        if (tolower(str[i]) != tolower(str[j])) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}


/**
 * @brief 判断字符串是否为回文字符串。
 * @details 通过双指针方法检查给定字符串是否为回文，忽略非字母字符并区分大小写。
 * @ingroup pointer_exercise_group
 * @param start 指向字符串起始位置的指针。
 * @param end 指向字符串结束位置的指针。
 * @return 如果字符串是回文返回true，否则返回false。
 */
bool
is_palindrome_ptr(char* start, char* end) {
    while (start < end) {
        while (start < end && !isalpha(*start)) {
            ++start;
        }
        while (start < end && !isalpha(*end)) {
            --end;
        }
        if (tolower(*start) != tolower(*end)) {
            return false;
        }
        ++start;
        --end;
    }
    return true;
}


void
palindrome() {
    printf("Enters a message: ");
    char message[MAXLINE];

    /* 1. 索引方式 */
    // int  n = 0;
    // char c;
    //
    // while (n < MAXLINE && (c = getchar()) != '\n') {
    //     message[n] = c;
    //     ++n;
    // }
    //
    // if (is_palindrome(message, n)) {
    //     printf("Palindrome\n");
    // } else {
    //     printf("Not a palindrome\n");
    // }

    /* 2. 指针方式 */
    char* p = message;
    char  c;
    while (p < message + MAXLINE && (c = getchar()) != '\n') {
        *p++ = c;
    }
    if (is_palindrome_ptr(message, p - 1)) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }
}


void
find_max_min_word(void) {
    char smallest_word[MAXWORD];
    char largest_word[MAXWORD];
    char word[MAXWORD];

    printf("Enter word: ");
    scanf("%s", word);
    strcpy(smallest_word, word);
    strcpy(largest_word, word);

    while (strlen(word) != 4) {
        printf("Enter word: ");
        scanf("%s", word);

        if (strcmp(word, smallest_word) < 0) {
            strcpy(smallest_word, word);
        } else if (strcmp(word, largest_word) > 0) {
            strcpy(largest_word, word);
        }
    }
    printf("\nSmallest word: %s\nLargest word : %s\n",
           smallest_word,
           largest_word);
}
