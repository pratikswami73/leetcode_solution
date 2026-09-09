class Solution {
public:
 queue<pair<int,int>> q;
    queue<pair<int,int>> q2;
    int count=0;

    void call(vector<vector<int>>& board,
              vector<vector<bool>>& vis,
              int i, int j) {

        bool boundary = false;

        vis[i][j] = true;
        q.push({i, j});

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int x = it.first;
            int y = it.second;

            q2.push({x, y});

            if (x == 0 || y == 0 ||
                x == board.size() - 1 ||
                y == board[0].size() - 1) {

                boundary = true;
            }

            if (x - 1 >= 0 &&
                !vis[x - 1][y] &&
                board[x - 1][y] == 1) {

                vis[x - 1][y] = true;
                q.push({x - 1, y});
            }

            if (y - 1 >= 0 &&
                !vis[x][y - 1] &&
                board[x][y - 1] ==1) {

                vis[x][y - 1] = true;
                q.push({x, y - 1});
            }

            if (x + 1 < board.size() &&
                !vis[x + 1][y] &&
                board[x + 1][y] == 1) {

                vis[x + 1][y] = true;
                q.push({x + 1, y});
            }

            if (y + 1 < board[0].size() &&
                !vis[x][y + 1] &&
                board[x][y + 1] == 1) {

                vis[x][y + 1] = true;
                q.push({x, y + 1});
            }
        }

        if (!boundary) {

            while (!q2.empty()) {

                auto it = q2.front();
                q2.pop();

               count++;
            }
        }
        else {

            while (!q2.empty()) {
                q2.pop();
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis( n, vector<bool>(m, false) );

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1 && !vis[i][j]) {

                    call(grid, vis, i, j);
                }
            }
        }
        return count;
    }
};