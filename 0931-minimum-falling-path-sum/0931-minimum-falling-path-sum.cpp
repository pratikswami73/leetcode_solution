class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(m,0));
        dp[0][0]=matrix[0][0];

        for(int i=0;i<m;i++){

            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    continue;
                }
                else if(i==0){
                    dp[i][j]=matrix[i][j];
                }
                else if(j==0){
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                }
                 else if(j==n-1){
                    dp[i][j]=matrix[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                }
                else{
                    int x=min(dp[i-1][j],dp[i-1][j+1]);
                     dp[i][j]=matrix[i][j]+min(dp[i-1][j-1],x);
                }
            }
        }
        return *min_element(dp[m-1].begin(),dp[m-1].end());

    }
};