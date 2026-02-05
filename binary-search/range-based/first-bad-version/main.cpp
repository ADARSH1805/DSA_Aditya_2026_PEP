// https://leetcode.com/problems/first-bad-version/description/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        int ans = -1;

        while (l <= r) {
            int m = l + ((r-l) >> 1);

            if (isBadVersion(m)) {
                r = m-1;
                ans = m;
            } else {
                l = m+1;
            }
        }

        return ans;
    }
};
