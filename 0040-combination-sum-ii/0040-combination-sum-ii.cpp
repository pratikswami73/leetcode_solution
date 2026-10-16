class Solution {
public:
vector<vector<int>>ans;

vector<int>store;
     void combi(int i,int sum,vector<int>&st,vector<int>&candidates,int target){
       
            if(sum==target){
               ans.push_back(st);
               return;
               
                
            }
             if(i==candidates.size() || sum>target){
            return;
        }
        st.push_back(candidates[i]);
        combi(i+1,sum+candidates[i],st,candidates,target);

        st.pop_back();
       
       
        int j = i + 1;
        while (j < candidates.size() &&
               candidates[j] == candidates[i]) {
            j++;
        }

        combi(j, sum, st, candidates, target);
     }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>st;
        sort(candidates.begin(),candidates.end());
        combi(0,0,st,candidates,target);
        return ans;
    }
};