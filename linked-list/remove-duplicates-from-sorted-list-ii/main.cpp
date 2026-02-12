// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next)
      return head;

    ListNode *ans = nullptr;
    ListNode *pre = nullptr;

    while (head) {
      bool hasDup = head->next && head->next->val == head->val;

      if (hasDup) {
        while (head->next && head->next->val == head->val) {
          head = head->next;
        }

        if (pre) {
          pre->next = head->next;
        }
      } else {
        if (!ans) {
          ans = head;
        }
        pre = head;
      }

      head = head->next;
    }

    return ans;
  }
};
