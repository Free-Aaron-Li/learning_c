//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me know:
//   <communicate_aaron@outlook.com>.

/**
 * @file function.c
 */
#include "function.h"

#define N 8 /**< 皇后数量 */

/**
 * @brief 获取下一个斐波那契数值
 * @details 被 @ref fibonacci 调用。
 * @return 斐波那契数值
 * @ingroup function_group
 */
long long
next_fibonacci(void) {
    static long long first = 0;
    static long long second = 1;

    const long long temp = first + second;
    first = second;
    second = temp;
    return temp;
}

/**
 * @brief 通过动态规划实现的斐波那契数计算
 * @return 斐波那契数
 * @ingroup function_group
 */
long long
fibonacci_plus(const int num) {
    if (num == 0 || num == 1) {
        return num;
    }

    long long a = 0, b = 1;
    for (int i = 2; i <= num; ++i) {
        const long long t = a + b;
        a = b;
        b = t;
    }
    return b;
}

void
fibonacci(void) {
    printf("%lld\n", next_fibonacci());
    printf("%lld\n", next_fibonacci());
    printf("%lld\n", next_fibonacci());
    printf("%lld\n", next_fibonacci());
    printf("%lld\n", next_fibonacci());
}

/**
 * @brief 运行汉诺塔
 * @details 被 @ref hanoi 调用。
 * @return 汉诺塔具体运行过程
 *
 * @ingroup function_group
 */
void
run_hanoi(const int n, const char start, const char middle, const char target) {
    /* 1. 边界条件 */
    if (n == 1) {
        printf("%c --> %c\n", start, target);
        return;
    }

    // middle（辅助杆）提供缓冲空间，可以存储部分盘子，让大的盘子能够按顺序移动到目标杆上。
    // 无法start --> middle的原因在于：大盘子无法在小盘子之上。
    // 汉诺塔解决的核心目标：将最大的盘子移动到目标杆上。

    // 2. 递归关系
    // 将n-1个盘子，将start经过target移动到middle上
    run_hanoi(n - 1, start, target, middle);
    // 将最下面的盘子，从start移动到target上
    printf("%c --> %c\n", start, target);
    // 将n-1个盘子，从middle经过start移动到target上
    run_hanoi(n - 1, middle, start, target);
}

void
hanoi(void) {
    int n = 0;
    scanf("%d", &n);
    run_hanoi(n, 'A', 'B', 'C');
}

int numbering = 1; /**< 正确放置皇后的棋盘编号  @ingroup Function */

/**
 * @brief 打印棋盘
 * @details 被 @ref solve_queues 调用。
 * @param board 棋盘
 *
 * @ingroup function_group
 */
void
print_board(const int board[]) {
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            if (board[row] == col) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
    printf("第%d个棋盘\n", numbering++);
    printf("------------------------------------------");
    printf("\n");
}

/**
 * @brief 皇后间是否冲突
 * @details 判断当前放置的皇后位置是否与其他皇后冲突。被 @ref solve_queues 调用
 * @param board 棋盘
 * @param row 放置皇后行
 * @param col 放置皇后列
 *
 * @return 如果可以放置，返回true；否则返回 false
 * @ingroup function_group
 */
bool
is_safe(const int board[], const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        /* 1. 同一列上冲突 */
        if (board[i] == col) {
            return false;
        }

        /* 2. 在主对角线上冲突 */
        if (board[i] - i == col - row) {
            return false;
        }

        /* 3. 在副对角线上冲突 */
        if (board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

/**
 * @brief 解决皇后放置问题
 * @details 通过递归调用，尝试将皇后放置在不冲突的位置。
 * 调用 @ref is_safe 判断皇后位置是否合法，调用 @ref print_board 打印棋盘。
 *
 * @param board 棋盘数组，记录每行皇后所在位置 board[row]=col
 * @param row 皇后开始放置起始行
 *
 * @see is_safe
 * @see print_board
 *
 * @ingroup function_group
 */
void
solve_queues(int board[], const int row) {
    /* 1. 边界条件 */
    if (row == N) {
        print_board(board);
        return;
    }

    /* 依次放置皇后 */
    for (int col = 0; col < N; ++col) { /* 从第1列开始放置皇后 */
        if (is_safe(board, row, col)) {
            board[row] = col; /* 在（row, col）位置放置一个皇后 */
            solve_queues(board, row + 1);
            board[row] = -1; /* 清除当前行状态，回溯核心思想 */
        }
    }
}

void
queens(void) {
    /* n 皇后 */
    int board[N];

    /* 初始化 */
    for (int i = 0; i < N; ++i) {
        board[i] = -1;
    }
    solve_queues(board, 0);
}
