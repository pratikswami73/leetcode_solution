class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;
    int n=nums.size();
        for(int i=0;i<n-1;i++){
            int y=nums[n-1]-nums[i];
            ans+=y;
        }
        return ans;
    }
};