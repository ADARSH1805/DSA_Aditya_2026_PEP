// https://leetcode.com/problems/reverse-linked-list/submissions/1913714829/

class Solution {
public:
  typedef ListNode *ln;
  ListNode *reverseList(ListNode *head) {
    ln pre = nullptr;
    ln cur = head;

    while (cur != nullptr) {
      ln nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }

    return pre;
  }
};
