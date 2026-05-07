class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<bool> hash(9, false);

        // Check rows
        for (int i = 0; i < 9; i++) {

            fill(hash.begin(), hash.end(), false);

            for (int j = 0; j < 9; j++) {

                if (board[i][j] == '.') continue;

                int num = board[i][j] - '1';

                if (hash[num])
                    return false;

                hash[num] = true;
            }
        }

        // Check columns
        for (int i = 0; i < 9; i++) {

            fill(hash.begin(), hash.end(), false);

            for (int j = 0; j < 9; j++) {

                if (board[j][i] == '.') continue;

                int num = board[j][i] - '1';

                if (hash[num])
                    return false;

                hash[num] = true;
            }
        }

        // Check 3x3 boxes
        for (int i = 0; i < 9; i += 3) {

            for (int j = 0; j < 9; j += 3) {

                fill(hash.begin(), hash.end(), false);

                // Traverse inside one box
                for (int r = i; r < i + 3; r++) {

                    for (int c = j; c < j + 3; c++) {

                        if (board[r][c] == '.') continue;

                        int num = board[r][c] - '1';

                        if (hash[num])
                            return false;

                        hash[num] = true;
                    }
                }
            }
        }

        return true;
    }
};