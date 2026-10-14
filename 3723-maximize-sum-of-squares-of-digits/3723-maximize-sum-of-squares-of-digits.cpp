class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
       if(sum>num*9)return "";
        string ans="";
       if(num==1){
        ans+=to_string(sum);
        
       }
       else{
        for(int i=0;i<num;i++){
            if(sum>9){
                ans+="9";
                sum-=9;
            }
            else{
                ans+=to_string(sum);
                sum=0;
            }
        }
       } 
       return ans;
    }
};