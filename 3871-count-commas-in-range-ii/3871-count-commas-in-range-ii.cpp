class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000){
            return 0;
        }

        string s=to_string(n);
        int digit=s.size();

        if(n<=999999){
            return n-1000+1;
        }
        else if(n<=999999999){
            long long ans=n-1000+1;
            ans+=n-1000000+1;
            return ans;


        }
        else if(n<=999999999999){
             long long ans=n-1000+1;
            ans+=n-1000000+1;
            ans+=n-1000000000+1;
            return ans;
        }
        else if(n<=999999999999999){
             long long ans=n-1000+1;
            ans+=n-1000000+1;
             ans+=n-1000000000+1;
             ans+=n-1000000000000+1;
             return ans;
        }
        else{
            long long ans=n-1000+1;
            ans+=n-1000000+1;
             ans+=n-1000000000+1;
             ans+=n-1000000000000+1;
             return ans+1;

        }



        return n;
    }
};