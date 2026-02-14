// https://www.geeksforgeeks.org/problems/implement-stack-using-array/1

class myStack {
public:
  int cap;
  vector<int> arr;

  myStack(int n) { cap = n; }

  bool isEmpty() { return arr.empty(); }

  bool isFull() { return cap == arr.size(); }

  void push(int x) { arr.push_back(x); }

  void pop() {
    if (!isEmpty()) {
      arr.pop_back();
    }
  }

  int peek() {
    if (isEmpty())
      return -1;

    return arr.back();
  }
};
