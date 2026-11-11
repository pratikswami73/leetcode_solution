class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
         int n = grid.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

      
        for(int j = 0; j < n; j++) {
            dp[0][j] = grid[0][j];
        }

     
        for(int i = 1; i < n; i++) {

            for(int j = 0; j < n; j++) {

                int mini = INT_MAX;

                for(int k = 0; k < n; k++) {

                    if(k != j) {
                        mini = min(mini, dp[i-1][k]);
                    }
                }

                dp[i][j] = grid[i][j] + mini;
            }
        }

        return *min_element(dp[n-1].begin(),
                            dp[n-1].end());
        
    }
};