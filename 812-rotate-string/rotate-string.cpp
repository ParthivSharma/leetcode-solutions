class Solution {
public:
    vector<int> findLps(string &patt) {
        int n = patt.size();
        vector<int> lps(n, 0);
        int len = 0;
        int i = 1;

        while (i < n) {
            if (patt[i] == patt[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len > 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    bool KMP(string &text, string &patt, vector<int> &lps) {
        int m = text.size();
        int n = patt.size();
        int i = 0, j = 0;

        while (i < m) {
            if (text[i] == patt[j]) {
                i++;
                j++;
            }
            if (j == n) return true;

            if (i < m && text[i] != patt[j]) {
                if (j > 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return false;
    }

    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        string text = s + s;
        vector<int> lps = findLps(goal);
        return KMP(text, goal, lps);    
    }
};
