//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me know:
//   <communicate_aaron@outlook.com>.
#include "exercise.h"


void
output_letter_grade(void) {
    int grade;
    char letter_grade;
    printf("Enter numerical grade: ");
    scanf("%d", &grade);


    switch (grade / 10) {
        case 9:
        case 10:
            letter_grade = 'A';
            break;
        case 8:
            letter_grade = 'B';
            break;
        case 7:
            letter_grade = 'C';
            break;
        case 6:
            letter_grade = 'D';
            break;
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            letter_grade = 'F';
            break;
        default:
            printf("Error: invalid grade\n");
            return;
    }
    printf("Letter grade: %c\n", letter_grade);
}

void
output_the_digits_of_integer(void) {
    int integer;
    int bit_count = 0;
    printf("Enter an integer: ");
    scanf("%d", &integer);

    if (integer < 0) {
        printf("Error: invalid integer\n");
        printf("The absolute value of %d is %d\n", integer, -integer);
        integer = -integer;
    }
    do {
        integer /= 10;
        ++bit_count;
    } while (integer > 0);

    printf("The number has %d digit(s)", bit_count);
}

void
bookkeeping_procedures(void) {
    int command = 0;
    int input_num = 0.0;
    double balance = 0.0;
    printf("*** checkbook-balancing program ***\n");
    printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");
    while (1) {
        printf("Enter command: ");
        scanf("%d", &command);
        switch (command) {
            case 0:
                balance = 0;
                break;
            case 1:
                printf("Enter amount of credit: ");
                scanf("%lf", &input_num);
                balance += input_num;
                break;
            case 2:
                printf("Enter amount of debit: ");
                scanf("%lf", &input_num);
                balance -= input_num;
                break;
            case 3:
                printf("Current balance: $%.2lf\n", balance);
                break;
            case 4:
                return;
            default:
                printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, "
                       "4=exit\n\n");
        }
    }
}

void
interest_rate_earnings(void) {
    double initial_balance = 0.0;
    printf("Enter initial balance: ");
    scanf("%lf", &initial_balance);

    int interest_rate = 0;
    printf("Enter interest rate: ");
    scanf("%d", &interest_rate);

    int years = 0;
    printf("Enter number of years: ");
    scanf("%d", &years);

    double balance[5] = { 0.0 };
    /** 在一个表达式中多次对同一个变量进行递增递减，属于<b>未定义行为</b>
     * 参数的求值顺序由<b>编译器和系统实现</b>决定。
     * 在这里interest_rate输出为10 10 9 8 7
     */
    // printf("Years\t\t%d%\t\t%d%\t\t%d%\t\t%d%\t\t%d%\n", interest_rate,
    //        ++interest_rate, ++interest_rate, ++interest_rate,
    //        ++interest_rate);
    printf("\nYears    ");
    for (int i = 0; i < 5; ++i) {
        printf("%4d%%  ", interest_rate + i);
    }
    putchar('\n');


    for (int i = 0; i < 5; ++i) {
        balance[i] = initial_balance;
    }

    for (int year = 1; year <= years; ++year) {
        printf("%3d      ", year);
        for (int i = 0; i < 5; ++i) {
            balance[i] = balance[i] * (1 + (interest_rate + i) / 100.0);
            printf("%7.2lf", balance[i]);
        }
        printf("\n");
    }
}

#define SIZE(a) sizeof(a) / sizeof(a[0])
void
cards_are_dealt_randomly(void) {
    /* 1. 表示牌值 */
    /**
     *  diamond 钻石
     *  club    梅花
     *  heart   红心
     *  spade   黑桃
     */
    int a[1] = { 0 };
    printf("%s", SIZE(a));
    const char suits[4] = { 'd', 'c', 'h', 's' };

    const char ranks[13] = { '2', '3', '4', '5', '6', '7', '8',
                             '9', 'T', 'J', 'Q', 'K', 'A' };

    /* 2. 随机发牌 */
    /* seed --> num1 --> num2 --> num3 ...
     * 设置种子，一般随机种子只需要设置一次，
     * 多次设置生成的随机值一致。
     * 伪随机数种子通过时间来生成可靠度随机数。
     */
    srand(time(NULL));

    /* 3. 判重 */
    bool in_hand[4][13] = { false };

    const int cards;
    printf("Enter number of cards in hand: ");
    scanf("%d", &cards);

    if (!(cards >= 0 && cards <= 13)) {
        printf("Error: invalid number of cards\n");
        return;
    }

    printf("Your hands: ");
    for (int i = 0; i < cards; ++i) {
        const int suit = rand() / (RAND_MAX / 4 + 1);
        const int rank = rand() / (RAND_MAX / 13 + 1);

        if (!in_hand[suit][rank]) {
            printf("%c%c ", ranks[rank], suits[suit]);
        } else {
            --i; /* 重新发牌 */
        }

        in_hand[suit][rank] = true;
    }
}
