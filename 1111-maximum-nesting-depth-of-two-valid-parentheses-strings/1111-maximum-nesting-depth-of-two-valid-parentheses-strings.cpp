class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
       int n=seq.size();
       int count=-1;
       vector<int>ans(n,0);
       for(int i=0;i<n;i++){
        if(seq[i]=='('){
            count++;
            ans[i]=count%2;

        }
        if(seq[i]==')'){
            ans[i]=count%2;
            count--;
        }
       } 
       return ans;
    }
};