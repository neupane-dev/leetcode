#include <stdlib.h>
#include "lc_2.h"

ListNode* add_two_numbers(ListNode* l1, ListNode* l2)
{
    ListNode dummy;
    dummy.next = NULL;
    ListNode* current = &dummy;
    int carry = 0;

    while(l1 || l2 || carry)
    {
        int sum = carry;
        if(l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        ListNode* newNode = (ListNode*)malloc(sizeof(ListNode*));
        newNode->val = sum % 10;
        newNode->next = NULL;

        current->next = newNode;
        current = current->next;
    }

    return (ListNode*)dummy.next;
}