//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "exercise.h"

/** @brief 输出二进制格式 */
void
print_binary(const unsigned int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    /* 获取最高位 */
    unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1);
    /* 前导0，用于在输出的过程中跳过前导零 */
    bool leading_zero = true;

    while (mask > 0) {
        if (n & mask) {
            printf("1");
            leading_zero = false;
        } else if (!leading_zero) {
            printf("0");
        }
        mask >>= 1;
    }
}

/** @brief 最后4位中是不是最少有3位为1 */
void
least_three_bits_one(const int n) {
    const int x = n & 0xF;
    const int nums[] = {
        7,  /* 0111 */
        11, /* 1011 */
        13, /* 1101 */
        14, /* 1110 */
        15  /* 1111 */
    };
    for (int i = 0; i < 5; i++) {
        if (x == nums[i]) {
            printf("The last four bits of 0xCAFE contain at least three bits "
                   "of 1, the last four bits is: ");
            print_binary(x);
            printf("\n");
            return;
        }
    }
    printf("The last four bits of 0xCAFE contain at most two bits of 1\n");
}

/** @brief 逆转最后四字节序 */
void
reversing_last_four_bytes_order(const int n) {
    const int last_two_bytes = (n & 0xFF) << 8; /* left move 2 bytes */
    const int first_two_bytes = n >> 8 & 0xFF;  /* right move 2 bytes */
    const int result_four_bytes = last_two_bytes | first_two_bytes;
    printf("The reversed byte order of %d is: ", n);
    print_binary(result_four_bytes);
    printf("\n");
}

/** @brief 旋转右移1字节 */
void
rotation_shifted_right_one_bytes(const int n) {
    const int left_one_bytes = (n & 0xF) << 12;
    const int right_three_bytes = n >> 4 & 0xFFF;
    const int result_four_bytes = left_one_bytes | right_three_bytes;
    printf("The reversed byte order of %d is: ", n);
    print_binary(result_four_bytes);
    printf("\n");
}

/** @brief 给定一个值不为 0 的整数，请找出值为 1 的最低有效位（last set bit）。
 */
int
get_value_of_last_significant_bit(const int n) {
    /* 思路一 */
    // int last_one_bit = 0x1;
    // while ((n & last_one_bit) == 0) {
    //     last_one_bit <<= 1;
    // }
    // return last_one_bit;

    /* 思路二 */
    return n & -n;
}

/** @brief 交换两个变量值（不使用临时中间变量） */
void
swap_value(void) {
    int a = 3, b = 4;
    /* 利用一对逆运算，来交换两个数 a0，b0
     * 存在问题，可能导致溢出，且效率低于位运算
     */
    a = a + b; /* a1=a0+b0, b1=b0 */
    b = a - b; /* a2=a0+b0, b2=a1-b1=a0 */
    a = a - b; /* a3=a2-b2=b0, b2=a0 */
    printf("a=%d, b=%d\n", a, b);

    /* 利用位运算，^和^是一对逆运算，a ^ b ^ b = a */
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("a=%d, b=%d\n", a, b);
}

/** @brief 出现一次的元素 */
void
value_that_appears_once(void) {
    const int nums[] = { 1, 4, 2, 1, 2 };
    /* 异或运算符的特点：交换律与结合律
     * 0^1^4^2^1^2=0^4=4
     */
    int single_num = 0;
    for (int i = 0; i < 5; i++) {
        single_num ^= nums[i];
    }
    printf("The single number is: %d\n", single_num);
}

/** @brief 两个单独的元素 */
void
value_that_appears_once_plus(void) {
    const int nums[] = { 1, 2, 1, 3, 2, 5 };
    int xor = 0; /* exclusive-or 异或 */

    /* 消除重复数字 */
    for (int i = 0; i < 6; ++i) {
        xor ^= nums[i];
    }
    /* 找出最右侧的1位（两个数的区分点）
     */
    const int last_set_bit = xor & -xor;

    /* 根据 last_set_bit 将所有元素分类 */
    int a = 0, b = 0;
    for (int i = 0; i < 6; ++i) {
        /* 分组：一组在 lsp 位上为1，一组为0 */
        if (nums[i] & last_set_bit) {
            /* num[i]在 lsp 位为1 */
            a ^= nums[i];
        } else {
            b ^= nums[i];
        }
    }

    printf("The single number is: %d, %d\n", a, b);
}

void
bit_operation_extension(void) {
    const int n = 0xCAFE;
    least_three_bits_one(n);
    reversing_last_four_bytes_order(n);
    rotation_shifted_right_one_bytes(n);
    printf("The last significant bit of %d is: %d\n", n,
           get_value_of_last_significant_bit(n));
    swap_value();
    value_that_appears_once();
    value_that_appears_once_plus();
}

/** @brief 是否为闰年 */
bool
is_leap_year(const int year) {
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

/** @brief 每月天数 */
int days_of_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

/** @brief 设定闰年二月天数 */
void
set_days_of_february(const int year) {
    if (is_leap_year(year)) {
        days_of_month[2] = 29;
    } else {
        days_of_month[2] = 28;
    }
}

/** @brief 获取年月日 */
void
get_year_month_day(void) {
    int year;
    int month;
    int day;
    printf("Enter year, month, day: ");
    scanf("%d%d%d", &year, &month, &day);

    ++day;
    set_days_of_february(year);

    if (day > days_of_month[month]) {
        day = 1;
        ++month;
    }

    if (month > 12) {
        month = 1;
        ++year;
    }

    printf("\nthe day add one, result is: %4d-%.2d-%.2d\n", year, month, day);
}

/** @brief 计算两个时间相差多少天 */
int
two_time_distance(const int year1, const int month1, const int day1,
                  const int year2, const int month2, const int day2) {
    int days = 0;
    /* 1. 计算year1剩余天数 */
    set_days_of_february(year1);
    days += days_of_month[month1] - day1;
    for (int i = month1 + 1; i <= 12; ++i) {
        days += days_of_month[i];
    }

    /* 2. 计算中间年份天数 */
    for (int i = year1 + 1; i < year2; ++i) {
        days += 365;
        if (is_leap_year(i)) {
            ++days;
        }
    }

    /* 3. 计算year2过去多少天 */
    set_days_of_february(year2);
    for (int i = 1; i < month2; ++i) {
        days += days_of_month[i];
    }
    days += day2;

    /* 4. 如果同年，则需要减去多算的一整年 */
    if (year1 == year2) {
        days -= 365;
        if (is_leap_year(year1)) {
            --days;
        }
    }
    printf("%4d-%.2d-%.2d and %4d-%.2d-%.2d distance is: %d days\n", year1,
           month1, day1, year2, month2, day2, days);
    return days;
}

/** @brief 星期名 */
const char* weekday_names[] = { "Sunday",   "Monday", "Tuesday", "Wednesday",
                                "Thursday", "Friday", "Saturday" };
/** @brief 计算当前星期 */
void
weekday(const int current_year, const int current_month,
        const int current_day) {
    const int distance_days = two_time_distance(1970, 1, 1, current_year,
                                                current_month, current_day);
    printf("Current day is %s\n", weekday_names[(4 + distance_days) % 7]);
}

void
calendar_calculation(void) {
    const int year = 2025;
    printf("Is %d a leap year? ", year);
    if (is_leap_year(year)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    get_year_month_day();

    const int year1, month1, day1, year2, month2, day2;
    printf("Enter the date you want to calculate, like this:\n"
           "first time : 2024 1 1\n"
           "second time: 2025 1 1\n"
           "---------------------\n");
    printf("first time : ");
    scanf("%d%d%d", &year1, &month1, &day1);
    printf("second time: ");
    scanf("%d%d%d", &year2, &month2, &day2);
    two_time_distance(year1, month1, day1, year2, month2, day2);
    weekday(2025, 4, 16);
}
