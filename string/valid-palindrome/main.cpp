// https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:
    bool isPalindrome(string &s) {
        int sz = s.size();
        int l = 0;
        int r = sz - 1;

        while (l < r) {
            if (!isalnum(s[l])) {
                ++l;
            } else if (!isalnum(s[r])) {
                --r;
            } else if (isalpha(s[l]) && isalpha(s[r])) {
                if (tolower(s[l]) != tolower(s[r])) {
                    return false;
                }
                ++l, --r;
            } else if (isdigit(s[l]) && isdigit(s[r])) {
                if (s[l] != s[r]) {
                    return false;
                }
                ++l, --r;
            } else {
                return false;
            }
        }

        return true;
    }
};
