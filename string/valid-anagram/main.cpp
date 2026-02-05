// https://leetcode.com/problems/valid-anagram/description/

class Solution {
public:
    bool isAnagram(string &s, string& t) {
        int szs = s.size();
        int szt = t.size();

        if (szs != szt) {
            return false;
        }

        vector<int>mp(26);

        for (char&ch : s) {
            ++mp[ch-'a'];
        }

        for (auto&ch : t) {
            --mp[ch-'a'];
        }

        for (int&it : mp) {
            if (it != 0) return false;
        }

        return 1;
    }
};




















