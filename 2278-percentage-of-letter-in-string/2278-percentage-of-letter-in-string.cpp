class Solution {
public:
    int percentageLetter(string s, char letter) {
        unordered_map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
       float ans= mp[letter]*100/s.size();
       return (int)ans;

    }
};