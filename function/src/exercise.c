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
 * @brief 判断三角形三边是否可以构成三角形
 *
 * @param a @f$a@f$边长
 * @param b @f$b@f$边长
 * @param c @f$c@f$边长
 *
 * @return 如果可以构成三角形，返回true；否则返回false。
 *
 * @ingroup function_exercise_group
 */
bool
is_triangle(const double a, const double b, const double c) {
    return a + b > c && a + c > b && b + c > a;
}

/**
 * @brief 获取三角形面积
 * @details 利用海伦公式在使用 @ref is_triangle
 *          函数判断@f$a@f$，@f$b@f$和@f$c@f$三边可以构成三角形的前提下。
 *
 * @param a @f$a@f$边长
 * @param b @f$b@f$边长
 * @param c @f$c@f$边长
 *
 * @return 三角形面积。
 *
 * @ingroup function_exercise_group
 */
double
get_area(const double a, const double b, const double c) {
    const double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

void
get_triangular_area(void) {
    double a, b, c;
    printf("Please enter three sides length of a triangle: ");
    scanf("%lf%lf%lf", &a, &b, &c);
    if (is_triangle(a, b, c)) {
        const double area = get_area(a, b, c);
        printf("The area of the triangle is: %.2lf\n", area);
    } else {
        printf("The given three sides cannot form a triangle.\n");
    }
}

/**
 * @brief 读取牌值，提取需要的信息。
 *
 * @details 此函数从用户输入中读取卡片值，并更新相关状态信息。
 * 函数中主要的局部变量说明如下：
 * - `cards`: 记录已经发牌的数量。
 * - `bad_card`: 标示输入的卡片是否合法。
 * - `in_hand`: 用于跟踪卡片是否已经出现在手牌中。
 *
 * @ingroup function_exercise_group
 */
void
read_cards(void) {
    /* 1. 清空所有牌 */
    bool in_hand[4][13] = { false }; /* 记录是否已经出现在手牌中 */
    for (int i = 0; i < 4; ++i) {
        num_in_suits[i] = 0;
    }
    for (int i = 0; i < 13; ++i) {
        num_in_ranks[i] = 0;
    }

    /* 2. 发牌 */
    int cards = 0; /* 发牌数量 */
    while (cards < 5) {
        bool bad_card = false; /* 无效卡牌标志 */
        printf("Enter a card: ");
        char card = getchar();
        int rank = 0;
        switch (card) {
            case '0': exit(EXIT_SUCCESS);
            case '2': rank = 0; break;
            case '3': rank = 1; break;
            case '4': rank = 2; break;
            case '5': rank = 3; break;
            case '6': rank = 4; break;
            case '7': rank = 5; break;
            case '8': rank = 6; break;
            case '9': rank = 7; break;
            case 't':
            case 'T': rank = 8; break;
            case 'j':
            case 'J': rank = 9; break;
            case 'q':
            case 'Q': rank = 10; break;
            case 'k':
            case 'K': rank = 11; break;
            case 'a':
            case 'A': rank = 12; break;
            default: bad_card = true; break;
        }

        card = getchar();
        int suit = 0;
        switch (card) {
            case 'd':
            case 'D': suit = 0; break;
            case 'c':
            case 'C': suit = 1; break;
            case 'h':
            case 'H': suit = 2; break;
            case 's':
            case 'S': suit = 3; break;
            default: bad_card = true; break;
        }

        /* 处理当前行剩余字符 */
        while ((card = getchar()) != '\n') {
            if (card != ' ' && card != '\t') {
                bad_card = true;
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

/**
 * @brief 分析手牌
 *
 * @details 通过 @ref num_in_suits 和 @ref num_in_ranks 两个数组，
 *          判断手牌属于那种类型（同花、顺子等）。
 *
 * @ingroup function_exercise_group
 */
void
analyze_hand(void) {
    flush = false;
    straight = false;
    four = false;
    three = false;
    pairs = 0;
    /* 1. 检查是否为同花 */
    for (int i = 0; i < 4; ++i) {
        if (num_in_suits[i] == 5) {
            flush = true;
        }
    }

    /* 2. 检查是否为顺子 */
    int idx = 0;
    /* 2.1 找到最小牌 */
    while (num_in_ranks[idx] == 0) {
        ++idx;
    }

    /* 2.2 查找连续牌数量 */
    int consecutive_ranks = 0;
    while (idx < 13 && num_in_ranks[idx] != 0) {
        ++consecutive_ranks;
        ++idx;
    }
    if (consecutive_ranks == 5) {
        straight = true;
        return;
    }

    /* 3. 判断四张、三张、两张等情况 */
    for (int i = 0; i < 13; ++i) {
        if (num_in_ranks[i] == 4) {
            four = true;
        } else if (num_in_ranks[i] == 3) {
            three = true;
        } else if (num_in_ranks[i] == 2) {
            ++pairs;
        }
    }
}

/**
 * @brief 打印手牌结果
 *
 * @details 通过 @ref analyze_hand 函数对手牌进行分析，
 *          获取 @ref flush、@ref straight、@ref four、@ref three、@ref pairs
 *          等变量值，打印手牌结果。
 *
 * @ingroup function_exercise_group
 */
void
print_result(void) {
    if (straight && flush) {
        printf("Straight flush\n");
    } else if (four) {
        printf("Four\n");
    } else if (three && (pairs == 1)) {
        printf("Full house\n");
    } else if (flush) {
        printf("Flush\n");
    } else if (straight) {
        printf("Straight\n");
    } else if (three && (pairs == 0)) {
        printf("Three\n");
    } else if (pairs == 2) {
        printf("Two pairs\n");
    } else if (pairs == 1) {
        printf("One pair\n");
    } else {
        printf("High card\n");
    }
    printf("\n");
}

/* 初始化 */
/*char num_in_suits[4] = { 0 };
char num_in_ranks[13] = { 0 };
bool flush = false;
bool straight = false;
bool four = false;
bool three = false;
int pairs = 0;*/

void
texas_holdem_game(void) {
    for (;;) {
        read_cards();
        analyze_hand();
        print_result();
    }
}
