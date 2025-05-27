//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.
#include "sll.h"


void
add_node(Node** head, const E val) {
    /* 1. 创建节点 */
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) {
        printf("Error: malloc new node failure.\n");
        exit(EXIT_FAILURE);
    }

    /* 2. 初始化节点 */
    new_node->data = val;
    new_node->next = *head; /* 头插法 */

    /* 3. 添加到链表 */
    *head = new_node;
}
