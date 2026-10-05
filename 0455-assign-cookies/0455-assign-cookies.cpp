class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int l=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if( l<g.size() && s[i]>=g[l]){
                l++;
                count++;
                
            }
        }
        return count;
    }
};