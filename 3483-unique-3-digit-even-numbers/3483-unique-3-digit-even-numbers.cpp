class Solution {
public:
    int totalNumbers(vector<int>& digits) {
          int cnt[10] = {};

        for (int d : digits) {
            cnt[d]++;
        }
          int ans = 0;
           for (int num = 100; num <= 999; num++) {
            if (num % 2 != 0)
                continue;

            int x = num;
            int a = x % 10;      
            x /= 10;
            int b = x % 10;       
            x /= 10;
            int c = x % 10;     

            int need[10] = {};
            need[a]++;
            need[b]++;
            need[c]++;

            bool possible = true;

            for (int d = 0; d <= 9; d++) {
                if (need[d] > cnt[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans++;
        }

        return ans;
    }        


};