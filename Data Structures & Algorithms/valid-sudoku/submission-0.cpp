class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use hash sets to track seen numbers
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char val = board[r][c];
                if (val == '.') continue; // skip empty cells

                // Check row
                if (rows[r].count(val)) return false;
                rows[r].insert(val);

                // Check column
                if (cols[c].count(val)) return false;
                cols[c].insert(val);

                // Check 3x3 box
                int boxIndex = (r / 3) * 3 + (c / 3);
                if (boxes[boxIndex].count(val)) return false;
                boxes[boxIndex].insert(val);
            }
        }
        return true;
    }
};
