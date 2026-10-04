class Solution {
public:
    int minRotations(string s) {
        int ans=0;
        int l=(int)s[0]-'0';
         l=min(l,10-l);
        ans+=l;


        for(int i=0;i<s.size()-1;i++){
            int x=(int)s[i];
            int y=(int)s[i+1];
            int c=abs(x-y);
            int m=min(x,y);
            int n=max(x,y);
            int o=m+10-n;
            ans+=min(o,c);
        }

        return ans;
        
    }
};