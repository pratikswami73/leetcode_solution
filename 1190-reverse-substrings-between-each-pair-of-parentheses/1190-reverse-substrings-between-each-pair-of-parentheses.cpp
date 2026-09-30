class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st1;
        stack<char>st2;
        stack<char>st3;
        int r=0;
        int n=s.size();
        string ans="";
        while(r<n){
            if(s[r]==')'){
                while(st1.top()!='('){
                    st2.push(st1.top());
                    st1.pop();
                }
                st1.pop();
                while(!st2.empty()){
                    st3.push(st2.top());
                    st2.pop();
                }
                while(!st3.empty()){
                    st1.push(st3.top());
                    st3.pop();
                }
                r++;
            }
            else{
            st1.push(s[r]);
            r++;
        }

        }
        while(!st1.empty()){
            ans+=st1.top();
            st1.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;


        
    }
};