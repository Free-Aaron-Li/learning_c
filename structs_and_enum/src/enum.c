//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "enum.h"


void
using_enum(void) {
    // ReSharper disable once CppVariableCanBeMadeConstexpr
    const enum SUIT s1 = DIAMOND;
    printf("%s\n", s1); /* (null) */
    printf("%d\n", s1); /* 0 */

    /* 枚举默认从0开始，当然也可以通过“=”指定值。  */

    /* 使用别名方式 */
    INTEGER i = ONE;
}
