class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Take the first string as reference
        for (int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            // Compare this character with all strings
            for (int j = 1; j < strs.size(); j++) {
                // If mismatch or end of a string reached
                if (i >= strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0]; // all strings matched completely
    }
};
