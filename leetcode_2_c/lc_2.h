#ifndef LC_2_H
#define LC_2_H

typedef struct ListNode{
    int val;
    struct ListNode* next;
} ListNode;

ListNode* add_two_numbers(ListNode* l1, ListNode* l2);


#endif