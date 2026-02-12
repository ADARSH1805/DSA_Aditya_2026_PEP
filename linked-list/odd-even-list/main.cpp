// https://leetcode.com/problems/odd-even-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *oddEvenList(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenBeg = head->next;
    ListNode *ans = head;

    head = head->next->next;

    while (head) {
      odd->next = head;
      even->next = head->next;
      odd = odd->next;
      even = even->next;
      head = head->next ? head->next->next : nullptr;
    }

    odd->next = evenBeg;

    return ans;
  }
};
