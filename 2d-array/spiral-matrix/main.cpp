// https://leetcode.com/problems/spiral-matrix/submissions/1912749023/

// S O L U T I O N - 1:

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &v) {
    int m = v.size();
    int n = v[0].size();
    int i = 0;
    int lt = (min(m, n) + 1) / 2;
    vector<int> ans;

    while (i > -1 && i < m && i < n && i < lt) {
      int ur = i;
      int dr = m - i - 1;
      int lc = i;
      int rc = n - i - 1;

      for (int col = i; col <= n - i - 1; ++col) {
        ans.push_back(v[ur][col]);
      }

      for (int row = i + 1; row <= m - i - 1; ++row) {
        ans.push_back(v[row][rc]);
      }

      if (dr > ur) {
        for (int col = n - i - 2; col >= i; --col) {
          ans.push_back(v[dr][col]);
        }
      }

      if (lc < rc) {
        for (int row = m - i - 2; row > i; --row) {
          ans.push_back(v[row][lc]);
        }
      }

      ++i;
    }

    return ans;
  }
};

// S O L U T I O N - 2:

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &v) {
    int m = v.size();
    int n = v[0].size();
    int sz = m * n;
    int dir = 0;

    vector<int> ans(sz);

    for (int k = 0, i = 0, j = 0; k < sz; ++k) {
      ans[k] = v[i][j];
      v[i][j] = INT_MAX;

      if (dir == 0) {
        if (j + 1 < n && v[i][j + 1] < INT_MAX)
          ++j;
        else {
          dir = 1;
          ++i;
        }
      } else if (dir == 1) {
        if (i + 1 < m && v[i + 1][j] < INT_MAX) {
          ++i;
        } else {
          dir = 2;
          --j;
        }
      } else if (dir == 2) {
        if (j && v[i][j - 1] < INT_MAX) {
          --j;
        } else {
          dir = 3;
          --i;
        }
      } else {
        if (i && v[i - 1][j] < INT_MAX) {
          --i;
        } else {
          ++j;
          dir = 0;
        }
      }
    }

    return ans;
  }
};
