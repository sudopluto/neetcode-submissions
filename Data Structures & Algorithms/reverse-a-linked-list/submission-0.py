# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:
            return None
        # base case, 1 elements
        if head and head.next is None:
            return head
        # base case, 2 elements
        if head and head.next:
            # next element is end?
            if head.next.next is None:
                new_head = head.next
                head.next = None
                new_head.next = head
                return new_head
            # have rest of list
            else:
                tail = head.next
                head.next = None
                new_head = self.reverseList(tail)
                tail.next = head
                return new_head
 