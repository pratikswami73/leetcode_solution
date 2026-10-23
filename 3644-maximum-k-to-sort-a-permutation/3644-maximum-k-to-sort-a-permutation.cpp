class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int>check=nums;

        sort(check.begin(),check.end());
         
         int ans=-1;
         bool find=true;
         for(int i=0;i<nums.size();i++){
            if(nums[i]!=check[i]){
                if(ans==-1){
                    ans=nums[i];
                }
                
                else{
                ans=ans & nums[i];
                }
                find=false;

            }
         }
         if(ans==-1 ){
            return 0;
         }
         return ans;
    }
};