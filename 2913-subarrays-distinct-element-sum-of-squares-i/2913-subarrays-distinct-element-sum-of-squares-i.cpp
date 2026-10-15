class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
       
        int ans=0;
        for(int i=0;i<n;i++){
           
            for(int j=i;j<n;j++){
                 unordered_map<int,int>mp;

                for(int k=i;k<=j;k++){
                     mp[nums[k]]++;
                }
                ans+=mp.size()*mp.size();
            }
           
        }
        return ans;
        
    }
};