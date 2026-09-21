class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3)return false;
        bool inc=false;
        bool dec=false;
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1])return false;
            if(arr[i]<arr[i+1]){
                if(dec==true)return false;
                    inc=true;
            }
            if(arr[i]>arr[i+1]){
                if(inc==false)return false;
                dec=true;
            }
            
        }
        return inc && dec;
    }
};