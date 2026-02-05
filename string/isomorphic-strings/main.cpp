// https://leetcode.com/problems/isomorphic-strings/description/

class Solution {
public:
    bool isIsomorphic(string &s, string &t) {
        int sz = s.size();

        if (sz != t.size()) {
            return 0;
        }

        unordered_map<char, char> ump, revUmp;

        for (int i=0; i<sz; ++i) {
            if (ump.find(s[i]) != end(ump)) {
                if (ump[s[i]] != t[i]) {
                    return 0;
                }
            } else if (revUmp.find(t[i]) != end(revUmp)) {
                if (revUmp[t[i]] != s[i]) {
                    return 0;
                }
            } else {
                ump[s[i]] = t[i];
                revUmp[t[i]] = s[i];
            }
        }

        return true;
    }
};
