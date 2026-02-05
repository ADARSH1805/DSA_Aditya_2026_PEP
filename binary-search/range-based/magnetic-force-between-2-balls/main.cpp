// https://leetcode.com/problems/magnetic-force-between-two-balls/

class Solution {
public:
    int sz;

    bool feasible (vector<int>&v, int k, int m) {
        int preBall = 1;
        int preInd = 0;
        for (int i=1; i<sz; ++i) {
            if ((v[i]-v[preInd]) >= m) {
                ++preBall;
                preInd = i;
            }
        }

        return preBall >= k;
    }

    int maxDistance(vector<int>& v, int k) {
        sort(begin(v), end(v));

        sz = v.size();
        int l = 1;
        int r = 1e9;
        int ans = -1;

        while (l <= r) {
            int m = l + ((r-l) >> 1);

            if (feasible(v, k, m)) {
                ans = m;
                l = m+1;
            } else {
                r = m-1;
            }
        }

        return ans;
    }
};
