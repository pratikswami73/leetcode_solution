class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int length=1;
        int ans=1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                length++;
                if(ans<length){
                 ans=length;
               }
            }
            else{length=1;}
        }
        length=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                length++;
               if(ans<length){
                 ans=length;
               }
            }
            else{length=1;}
        }
        return ans;
        
    }
};