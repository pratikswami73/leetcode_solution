class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
       int min=INT_MAX;
        bool yes=false;
       while(l<=r){
       
        for(int j=0;j<nums.size()-l+1;j++){
            int sum=0;
        for(int i=j;i<j+l;i++){
            sum+=nums[i];

        }
         if(sum<min && sum>0){
            min=sum;
            yes=true;
        }
        }
       
        l++;
       }
       if(yes){
       return min;}
       return -1;
       
    }
};