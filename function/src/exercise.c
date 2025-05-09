//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me know:
//   <communicate_aaron@outlook.com>.
#include "exercise.h"

/**
 * @brief 判断是否为素数
 *
 * @ingroup function_exercise_group
 */
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
 *
 * @ingroup function_exercise_group
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
 *
 * @ingroup function_exercise_group
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

/**
 * @brief 是否继续游戏
 *
 * @ingroup function_exercise_group
 */
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
    const int depth = 100; /* 最大尝试次数 */
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

/**
 * @brief 读取牌值，提取需要的信息。
 *
 * @ingroup function_exercise_group
 */
void
read_cards(void) {
    /* 1. 清空所有牌 */
    for (int i = 0; i < 4; ++i) {
        num_in_suits[i] = 0;
    }
    for (int i = 0; i < 13; ++i) {
        num_in_ranks[i] = 0;
    }

    /* 2. 发牌 */
    bool in_hand[4][13] = { false };
    int cards = 0; /**< 发牌数量 */
    while (cards < 5) {
        printf("Enter a card: ");
        bool bad_card = false;
        char card = getchar();
        int rank;
        switch (card) {
            case '0': {
                exit(EXIT_SUCCESS);
            }
            case '2': {
                rank = 0;
                break;
            }
            case '3': {
                rank = 1;
                break;
            }
            case '4': {
                rank = 2;
                break;
            }
            case '5': {
                rank = 3;
                break;
            }
            case '6': {
                rank = 4;
                break;
            }
            case '7': {
                rank = 5;
                break;
            }
            case '8': {
                rank = 6;
                break;
            }
            case '9': {
                rank = 7;
                break;
            }
            case 't':
            case 'T': {
                rank = 8;
                break;
            }
            case 'j':
            case 'J': {
                rank = 9;
                break;
            }
            case 'q':
            case 'Q': {
                rank = 10;
                break;
            }
            case 'k':
            case 'K': {
                rank = 11;
                break;
            }
            case 'a':
            case 'A': {
                rank = 12;
                break;
            }
            default: {
                bad_card = true;
                break;
            }
        }

        card = getchar();
        int suit;
        switch (card) {
            case 'd':
            case 'D': {
                suit = 0;
                break;
            }
            case 'c':
            case 'C': {
                suit = 1;
                break;
            }
            case 'h':
            case 'H': {
                suit = 2;
                break;
            }
            case 's':
            case 'S': {
                suit = 3;
                break;
            }
            default: {
                bad_card = true;
                break;
            }
        }

        if (bad_card) {
            printf("Bad card; ignored.\n");
        } else if (in_hand[suit][rank]) {
            printf("Duplicate card; ignored.\n");
        } else {
            ++cards;
            in_hand[suit][rank] = true;
            ++num_in_suits[suit];
            ++num_in_ranks[rank];
        }
    }
}

void
analyze_hand(void) {}

void
print_result(void) {}

char num_in_suits[4] = { 0 };
char num_in_ranks[13] = { 0 };
bool flush = false;
bool straight = false;
bool four = false;
bool three = false;
int pairs = 0;

void
texas_holdem_game(void) {
    for (;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}
