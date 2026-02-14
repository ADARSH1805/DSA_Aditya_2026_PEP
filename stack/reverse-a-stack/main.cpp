// https://www.geeksforgeeks.org/problems/reverse-a-stack/1

class Solution {
public:
  void putAtBottom(stack<int> &st, int eleToPut) {
    if (st.empty()) {
      st.push(eleToPut);
      return;
    }

    int top = st.top();
    st.pop();

    putAtBottom(st, eleToPut);
    st.push(top);
  }
  void reverseStack(stack<int> &st) {
    if (st.size() < 2)
      return;

    int top = st.top();
    st.pop();

    reverseStack(st);
    putAtBottom(st, top);
  }
};
