class Solution {
  public:
    int sz;

    bool canAllocate(vector<int>&v, int k, int lt) {
        int student = 0;
        int pageCnt = 0;

        for (int i=0; i<sz; ++i) {
            if ((pageCnt+v[i]) <= lt) {
                pageCnt += v[i];
            } else {
                ++student;
                pageCnt = v[i];
            }
        }

        return (student < k);
    }

    int findPages(vector<int> &arr, int k) {
        sz = arr.size();

        if (sz < k) return -1;

        int l = *max_element(begin(arr), end(arr));
        int r = accumulate(begin(arr), end(arr), 0);
        int ans = -1;

        while (l <= r) {
            int m = l + ((r-l) >> 1);
            int feasible = canAllocate(arr, k, m);

            if (feasible) {
                ans = m;
                r = m-1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};

