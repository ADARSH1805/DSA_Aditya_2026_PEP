// https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *pre = nullptr;
    ListNode *cur = head;
    ListNode *ansHead = head->next;

    while (cur && cur->next) {
      if (pre) {
        pre->next = cur->next;
      }
      ListNode *nxtBlockBeg = cur->next->next;
      cur->next->next = cur;
      cur->next = nxtBlockBeg;
      pre = cur;
      cur = nxtBlockBeg;
    }

    return ansHead;
  }
};
