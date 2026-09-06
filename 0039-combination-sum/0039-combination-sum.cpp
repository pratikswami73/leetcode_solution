class Solution {
public:
vector<vector<int>>ans;
int check1=0;
     void sum(vector<int>&check,int idx,vector<int>&candidates ,int target){
        if(idx==candidates.size()){
            return;
        }
        if(check1>target)return;
        if(check1==target){
            ans.push_back(check);
            return;
        }

        check.push_back(candidates[idx]);
        check1+=candidates[idx];
        sum(check,idx,candidates,target);
        
            check.pop_back();
            check1-=candidates[idx];

        
        sum(check,idx+1,candidates,target);

        return;

        

        
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>check;
        sort(candidates.begin(),candidates.end());
        sum(check,0,candidates,target);
        return ans;
    }
};