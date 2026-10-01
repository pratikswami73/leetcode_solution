class Solution {
public:
char reverse(char c){
    if(c=='[')return ']';
    else if(c=='{')return '}';
    else if(c=='(')return ')';
    return c;
}
    bool isValid(string s) {
        if(s.size()%2!=0)return false;

        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);

            }
            else{
                if(st.empty())return false;
                if(s[i]!=reverse(st.top())){
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
        
    }
};