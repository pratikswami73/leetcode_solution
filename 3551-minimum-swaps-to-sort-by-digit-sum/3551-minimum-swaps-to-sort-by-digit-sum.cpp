class Solution {
public:
    int minSwaps(vector<int>& nums) {
       vector<pair<int,int>>order;
       int n=nums.size();
       unordered_map<int,int>mp;
       for(int i=0;i<nums.size();i++){
        mp[nums[i]]=i;
       }
       for(int i=0;i<nums.size();i++){
        int x=nums[i];
        int sum=0;
        while(x>0){
            sum+=x%10;
            x=x/10;
        }
        order.push_back({sum,nums[i]});
       }
       sort(order.begin(),order.end());
      vector<bool>visit(n,false);
        int swaps=0;
        for(int i=0;i<n;i++){
            if(visit[i] || i==mp[order[i].second]){
                continue;
            }
            int cyclesize=0;
            int j=i;
            while(!visit[j]){
                visit[j]=true;
                j=mp[order[j].second];
                cyclesize++;
            }
            swaps+=cyclesize-1;
        }
        return swaps;
    }
};