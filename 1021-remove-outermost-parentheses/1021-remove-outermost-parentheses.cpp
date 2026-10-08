class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string s2="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                if(c>0) s2+=s[i];
                c++;
                

               
            }
            else if(s[i]==')'){
                c--;
                 if(c>0)s2+=s[i];
               
               
          
            }
        }
        
        return s2;
    }
};