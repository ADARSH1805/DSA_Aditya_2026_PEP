// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

class Solution {
public:
  Node *segregate(Node *head) {
    Node *z = new Node(-1), *o = new Node(-1), *t = new Node(-1), *zs = z,
         *os = o, *ts = t;

    while (head) {
      if (head->data == 0) {
        z->next = new Node(0);
        z = z->next;
      } else if (head->data == 1) {
        o->next = new Node(1);
        o = o->next;
      } else {
        t->next = new Node(2);
        t = t->next;
      }

      head = head->next;
    }

    if (zs->next) {
      if (os->next) {
        z->next = os->next;
        o->next = ts->next;
      } else {
        z->next = ts->next;
      }

      return zs->next;
    }

    if (os->next) {
      o->next = ts->next;
      return os->next;
    }

    return ts->next;
  }
};
