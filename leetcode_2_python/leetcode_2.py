from typing import Optional

class ListNode:
    def __init__(self,val=0,next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode(0)
        current = dummy_head
        carry = 0

        #Loop as long as there are digits to add or a remaining carry
        while l1 or l2 or carry:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0

            #calculate the sum and new carry
            total = val1 + val2 + carry
            carry = total // 10
            digit = total % 10

            #Create the next node in the result list
            current.next = ListNode(digit)
            current = current.next

            #Advance the input lists of elements exist
            if l1: l1 = l1.next
            if l2: l2 = l2.next
        
        return dummy_head.next