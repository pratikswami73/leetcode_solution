class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];

        if(n==2)return max(nums[0],nums[1]);

        vector<int>dp(n-1);
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++){
            int take=nums[i]+dp[i-2];
            int skip=dp[i-1];
            dp[i]=max(skip,take);
        }
        int x=dp[n-2];
           vector<int>dp1(n-1);
            dp1[0]=nums[1];
        dp1[1]=max(nums[1],nums[2]);
        for(int i=2;i<n-1;i++){
            int take=nums[i+1]+dp1[i-2];
            int skip=dp1[i-1];
            dp1[i]=max(skip,take);
        }
        return max(dp1[n-2],x);
    }
};