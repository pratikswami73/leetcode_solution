class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int r=0;
        int n=s.size();
        unordered_map<string,string>dict;
        for(auto it:knowledge){
            dict[it[0]]=it[1];
        }
        string ans="";
        while(r<n){
            if(s[r]=='('){
                string key="";
                r++;
                while(s[r]!=')'){
                    key+=s[r];
                    r++;
                    
                }
                r++;
                if(dict[key]==""){
                    ans+='?';
                }
                else{

                ans+=dict[key];
                }

            }
            else{
                ans+=s[r];
                r++;
            }
        }
        return ans;
    }
};