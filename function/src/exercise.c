//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me know:
//   <communicate_aaron@outlook.com>.
#include "exercise.h"

#include <stdlib.h>
#include <time.h>

/** @brief 判断是否为素数 */
bool
is_prime(const int num) {
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void
judgement_num_is_prime(void) {
    const int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (is_prime(num)) {
        printf("Prime\n");
    } else {
        printf("Not prime\n");
    }
}

/**
 * @brief 掷骰子
 * @return 骰子值
 */
int
roll_dices(void) {
    return (rand() / (RAND_MAX / 6 + 1) + 1) +
           (rand() / (RAND_MAX / 6 + 1) + 1);
}

/**
 * @brief 二次及后游戏
 * @param point 目标值
 * @param depth 递归调用最大深度
 * @return 游戏结果
 */
bool
play_game_second(const int point, int depth) {
    const int dices = roll_dices();
    printf("You rolled: %d\n", dices);
    if (dices == point) {
        printf("You win!\n");
        return true;
    }
    if (dices == 7) {
        printf("You lose!\n");
        return false;
    }
    if (depth <= 0) {
        printf("Game over: Reached maximum attempts.\n");
    }
    return play_game_second(point, --depth);
}

/** @brief 是否继续游戏 */
bool
play_game(void) {
    const int dices = roll_dices();
    printf("You rolled: %d\n", dices);
    if (dices == 7 || dices == 11) {
        printf("You win!\n");
        return true;
    }
    if (dices == 2 || dices == 3 || dices == 12) {
        printf("You lose!\n");
        return false;
    }

    printf("Your point is %d\n", dices);
    const int depth = 100; /**< 最大尝试次数 */
    return play_game_second(dices, depth);
}

void
roll_the_dices_game(void) {
    srand((unsigned int) time(NULL));
    int wins = 0, loses = 0;
    char again = 'n';

    do {
        play_game() ? ++wins : ++loses;
        printf("\nPlay agin? ");
        scanf(" %c", &again);
        printf("\n");
    } while (again == 'y' || again == 'Y');

    printf("Wins: %d Loses: %d", wins, loses);
}
