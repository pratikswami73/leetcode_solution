class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1;
        int sum = 0;
        int ans = 0;
        int MOD = 1e9 + 7;

        for(int x : arr) {
            sum += x;

            if(sum % 2 != 0) {
                ans = (ans + even) % MOD;
                odd++;
            }
            else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }

        return ans;
    }
};

  