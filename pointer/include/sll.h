//   Copyright (c) 2025. aaron.
//
//   This program is under the GPL-3.0 license.
//   if you have not received it or the program has several bugs, please let me
//   know: <communicate_aaron@outlook.com>.

#ifndef SLL_H
#define SLL_H

/**
 * @file sll.h
 * @defgroup sll_group single_linked_list
 * @brief 单链表模块。
 * @details 主要包含：
 * - @ref Vector 动态数组
 */

#include <stdio.h>
#include <stdlib.h>

/* 元素类型 */
typedef int E;


/**
 * @brief 定义单链表的节点结构。
 * @details 
 * 该结构体表示单链表中的一个节点，包含存储的数据和指向下一个节点的指针。
 * @ingroup sll_group
 * @param data: 存储在节点中的元素值。
 * @param next: 指向下一个节点的指针，若为NULL则表示链表结束。
 */
typedef struct node {
    E            data;
    struct node* next;
} Node;

/**
 * @brief 头插法插入链表节点。
 * @details 
 * 该函数接收单链表的头指针和要添加的元素值，创建一个新节点并将其插入到链表的末尾。
 * 如果链表为空，则新节点将成为链表的头节点。
 * @ingroup sll_group
 * @param head 指向单链表头指针的指针。
 * @param val 要添加到链表中的元素值。
 */
void add_node(Node** head, E val);

#endif //SLL_H
