// https://leetcode.com/problems/search-a-2d-matrix-ii/submissions/1912721505/

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &v, int tar) {
    int m = v.size();
    int n = v[0].size();

    for (int i = 0, j = n - 1; i < m && j > -1;) {
      if (v[i][j] == tar)
        return 1;

      if (v[i][j] < tar) {
        ++i;
      } else {
        --j;
      }
    }

    return 0;
  }
};
