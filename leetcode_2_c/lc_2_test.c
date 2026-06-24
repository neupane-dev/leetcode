#include <stdio.h>
#include <stdlib.h>
#include "lc_2.h"

ListNode* create_list(int* arr, int size) {
    if (size == 0) return NULL;
    ListNode* head = (ListNode*)malloc(sizeof(ListNode));
    head->val = arr[0];
    head->next = NULL;
    ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = (struct ListNode*)malloc(sizeof(ListNode));
        curr = (ListNode*)curr->next;
        curr->val = arr[i];
        curr->next = NULL;
    }
    return head;
}

void print_and_free_list(ListNode* head) {
    ListNode* curr = head;
    printf("[");
    while (curr != NULL) {
        printf("%d%s", curr->val, curr->next ? ", " : "");
        ListNode* temp = curr;
        curr = (ListNode*)curr->next;
        free(temp);
    }
    printf("]\n");
}

int main() {
    int a1[] = {2, 4, 3};
    int a2[] = {5, 6, 4};
    
    ListNode* l1 = create_list(a1, 3);
    ListNode* l2 = create_list(a2, 3);

    ListNode* result = add_two_numbers(l1, l2);
    
    printf("Result List: ");
    print_and_free_list(result); // Expected Output: [7, 0, 8]
    
    print_and_free_list(l1);
    print_and_free_list(l2);

    return 0;
}