class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>>store;
        for(int i=0;i<costs.size();i++){
            store.push_back({costs[i][0]-costs[i][1],i});
        }
        int ans=0;
        sort(store.begin(),store.end());
        for(int j=0;j<store.size()/2;j++){
                ans+=costs[store[j].second][0];

        }
        for(int j=store.size()/2;j<store.size();j++){
            ans+=costs[store[j].second][1];
        }
        return ans;
    }
};