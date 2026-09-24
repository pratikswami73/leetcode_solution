class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            string s=to_string(nums[i]);
            int sum = accumulate(s.begin(), s.end(), 0,
                [](int total, char ch) {
                    return total + (ch - '0');
                });
            if(sum==i){
                return i;
            }
        }
        return -1;
    }
};