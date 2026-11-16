class Solution {
public:
    long long maxDifference(vector<int>& nums) {
           int n = nums.size();

        long long next1 = 0;
        long long next2 = 0;

        for(int i = n - 1; i >= 0; i--) {

            long long s1 = nums[i];

            long long op1;
            if(s1 % 3 == 0)
                op1 = s1 - next1;
            else
                op1 = s1 + next1;

            long long op2 = LLONG_MIN;

            if(i + 1 < n) {
                long long s2 = nums[i] + (long long)nums[i + 1];

                if(s2 % 3 == 0)
                    op2 = s2 - next2;
                else
                    op2 = s2 + next2;
            }

            long long curr = max(op1, op2);

            next2 = next1;
            next1 = curr;
        }

        return next1;
    }
};