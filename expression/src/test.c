//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "test.h"

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

/** @brief 选择右移1字节 */
void
rotation_shifted_right_one_bytes(const int n) {
    const int left_one_bytes = (n & 0xF) << 12;
    const int right_three_bytes = n >> 4 & 0xFFF;
    const int result_four_bytes = left_one_bytes | right_three_bytes;
    printf("The reversed byte order of %d is: ", n);
    print_binary(result_four_bytes);
    printf("\n");
}

void
bit_operation_extension(void) {
    const int n = 0xCAFE;
    least_three_bits_one(n);
    reversing_last_four_bytes_order(n);
    rotation_shifted_right_one_bytes(n);
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

/** @brief 计算当前星期 */
void
weekday(const int current_year, const int current_month,
        const int current_day) {
    const char* weekday_names[] = { "Sunday",    "Monday",   "Tuesday",
                                    "Wednesday", "Thursday", "Friday",
                                    "Saturday" };
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
