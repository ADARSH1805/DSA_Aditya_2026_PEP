// https://leetcode.com/problems/palindrome-linked-list/submissions/1913733988/

class Solution {
  typedef ListNode *ln;

public:
  ln reverseList(ln head) {
    ln pre = nullptr;
    ln cur = head;

    while (cur) {
      ln nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }

    return pre;
  }

  bool isPalindrome(ListNode *head) {
    ln s = head;
    ln f = head;

    while (f && f->next) {
      s = s->next;
      f = f->next->next;
    }

    ln r = reverseList(s);
    ln l = head;

    while (r) {
      if (l->val != r->val) {
        return 0;
      }
      l = l->next;
      r = r->next;
    }

    return 1;
  }
};
