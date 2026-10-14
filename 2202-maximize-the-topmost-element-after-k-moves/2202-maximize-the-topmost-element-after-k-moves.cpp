class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int maxi=INT_MIN;
        int n=nums.size();
        if(k%2!=0 && n==1)return -1;
        if(k<=nums.size()){
        for(int i=0;i<k-1;i++){
            maxi=max(nums[i],maxi);
        }
       // if()
        maxi=max(maxi,nums[k]);
        }
        else{
            return *max_element(nums.begin(),nums.end());
        }
        if(maxi==INT_MIN)return -1;
        return maxi;
    }
};