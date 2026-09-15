class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]].push_back(i);
        }
        int count=0;
        for(auto it:freq){
            if(it.second.size()>=3){
                bool check=true;
                int x=it.second[1]-it.second[0];
                for(int i=0;i<it.second.size()-1;i++){
                    if(it.second[i+1]-it.second[i]!=x){
                        check=false;
                    }
                }
                if(check==true){
                    count++;
                }
            }
        }
        return count;
    }
};