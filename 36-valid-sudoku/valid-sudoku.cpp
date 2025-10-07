class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use hash sets for each row, column, and sub-box
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c == '.') continue; // skip empty cells

                // Check row
                if (rows[i].count(c)) return false;
                rows[i].insert(c);

                // Check column
                if (cols[j].count(c)) return false;
                cols[j].insert(c);

                // Check 3x3 box
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxes[boxIndex].count(c)) return false;
                boxes[boxIndex].insert(c);
            }
        }
        return true;
    }
};