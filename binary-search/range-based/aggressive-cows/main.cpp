class Solution {
  public:
    int sz;
    bool feasible (vector<int>&v, int cowCnt, int mnDist) {
        int stallCnt = 1;
        int preStallInd = 0;

        for (int i=1; i<sz; ++i) {
            int curDist = v[i] - v[preStallInd];

            if (curDist >= mnDist) {
                ++stallCnt;
                preStallInd = i;
            }
        }

        return (stallCnt >= cowCnt);
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        sort(begin(stalls), end(stalls));
        sz = stalls.size();
        int ans = -1;
        int l = 1;
        int r = 1e9;

        while (l <= r) {
            int m = l + ((r-l) >> 1);

            if (feasible(stalls, k, m)) {
                ans = m;
                l = m + 1;
            } else {
                r = m-1;
            }
        }

        return ans;
    }
};
