class Solution {
public:
    string reverseWords(string s) {
        // Step 1: Remove extra spaces
        stringstream ss(s);
        string word;
        vector<string> words;

        // Step 2: Split into words
        while (ss >> word) {
            words.push_back(word);
        }

        // Step 3: Reverse the words
        reverse(words.begin(), words.end());

        // Step 4: Join with single space
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i != words.size() - 1) result += " ";
        }
        return result;
    }
};
