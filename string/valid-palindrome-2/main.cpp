// https://leetcode.com/problems/valid-palindrome-ii/description/

class Solution {
public:
    bool validPalindrome(string &s) {
     int sz = s.size();
     int l = 0;
     int r = sz-1;

     auto is_palin = [&sz](string& str, int i, int j) -> bool {
        while (i < j) {
            if (str[i] != str[j]) {
                return 0;
            }
            ++i, --j;
        }

        return 1;
     };

     while (l < r) {
        if (s[l] == s[r]) {
            ++l, --r;
            continue;
        }
        if (is_palin(s, l+1, r)) {
            return 1;
        }

        if (is_palin(s, l, r-1)) {
            return 1;
        }

        return 0;
     }

     return 1;
    }
};
