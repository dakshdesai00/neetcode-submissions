class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        queue<pair<int,int>> q;

        // Top and bottom rows
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                q.push({0,j});
                board[0][j] = '#';
            }
            if(board[m-1][j] == 'O'){
                q.push({m-1,j});
                board[m-1][j] = '#';
            }
        }

        // Left and right columns
        for(int i = 1; i < m-1; i++){
            if(board[i][0] == 'O'){
                q.push({i,0});
                board[i][0] = '#';
            }
            if(board[i][n-1] == 'O'){
                q.push({i,n-1});
                board[i][n-1] = '#';
            }
        }

        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            for(auto &d : dir){
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx >= 0 && nx < m && ny >= 0 && ny < n &&
                   board[nx][ny] == 'O'){
                    board[nx][ny] = '#';
                    q.push({nx,ny});
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '#')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};