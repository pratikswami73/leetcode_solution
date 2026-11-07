class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int>points(10001,0);
        for(int x:nums){
            points[x]+=x;
        }
        vector<int>dp(10001,0);
        dp[0]=points[0];
        dp[1]=max(points[0],points[1]);
        for(int i=2;i<=10000;i++){
            dp[i]=max(dp[i-1],dp[i-2]+points[i]);
        }
        return dp[10000];
    }
};