// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

class Solution {
public:
  typedef ListNode *ln;

  void reverse(ln l, ln r) {
    ln pre = nullptr;
    ln cur = l;

    while (pre != r) {
      ln nxt = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nxt;
    }
  }

  ListNode *reverseKGroup(ListNode *head, int k) {
    ln finalHead = nullptr;
    ln preSegEnd = nullptr;
    ln cur = head;
    ln curSegBeg = head;
    int cnt = 0;

    while (cur) {
      ++cnt;

      if (!(cnt % k)) {
        finalHead = finalHead ? finalHead : cur;
        ln nxtSegBeg = cur->next;
        reverse(curSegBeg, cur);

        if (preSegEnd) {
          preSegEnd->next = cur;
        }
        curSegBeg->next = nxtSegBeg;
        preSegEnd = curSegBeg;
        cur = nxtSegBeg;
        curSegBeg = nxtSegBeg;
      } else {
        cur = cur->next;
      }
    }

    return finalHead;
  }
};
