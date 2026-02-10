// https://leetcode.com/problems/middle-of-the-linked-list/submissions/1913718925/

class Solution {
public:
  typedef ListNode *ln;

  ListNode *middleNode(ListNode *head) {
    ln slow = head;
    ln fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};
