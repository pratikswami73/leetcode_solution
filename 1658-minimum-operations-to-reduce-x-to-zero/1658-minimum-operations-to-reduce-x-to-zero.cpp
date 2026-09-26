class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        int ans=INT_MAX;
        int r=0;
        int l=0;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==x){
                r=i;
                ans=i+1;
                break;
            }
            if(sum>x){
                r=i;
                break;
            }
        }
            int sum2=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum2+=nums[i];
            if(sum2==x){
                int w=nums.size()-i;
                ans=min(ans,w);
                break;
            }
            if(sum2 > x){break;}
        }
            sum-=nums[r];
            r--;
            l=nums.size()-1;
            sum+=nums[l];
        while(r>=0 && l>=0){
            if(sum>x){
                sum-=nums[r];
                r--;
            }
            else if(sum<x){
               // if(l==0)l=l+nums.size()-1;
                l--;
                sum+=nums[l];

            }
            else if(sum==x){
                int siz=r+1+nums.size()-l;
                ans=min(ans,siz);
                l--;
                sum+=nums[l];
                sum-=nums[r];
                r--;
            }
        }
        if(ans==INT_MAX)return -1;

        return ans;
    }
};