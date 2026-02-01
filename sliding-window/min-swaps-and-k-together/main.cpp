https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

// Final function implementation
class Solution {
  public:

    int minSwap(vector<int>& arr, int k) {
        const auto getForm = [&k](int num) -> int {
            return (num<=k ? 1 : 0);
        };

        int tot = 0;
        int sz = arr.size();

        for (const auto& it: arr) {
            tot += getForm(it);
        }
        int cur = 0;

        for (int i=0; i<tot; ++i) {
            cur += getForm(arr[i]);
        }
        int mx = cur;

        for (int i=1; i<=sz-tot; ++i) {
            cur -= getForm(arr[i-1]);
            cur += getForm(arr[(i+tot-1) % sz]);
            mx = max(mx, cur);
        }

        return tot - mx;
    }
};
