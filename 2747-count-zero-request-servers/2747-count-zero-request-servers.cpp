class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int m=logs.size();
        int q=queries.size();
        sort(logs.begin(),logs.end(),[](auto &a ,auto &b){
            return a[1]<b[1];
        });
        vector<pair<int,int>>v;
        for(int i=0;i<q;i++){
           v.push_back({queries[i],i});
        }
           sort(v.begin(),v.end());
           vector<int>ans(q);
           unordered_map<int,int>mp;
           int left=0;int right=0;
           int active =0;
           for(auto[t,idx]:v){
            int start =t-x;
            while(right<m && logs[right][1]<=t){
                int server=logs[right][0];
                if(mp[server]==0){
                    active++;
                }
                mp[server]++;
                right++;
            }
            while(left<right && logs[left][1]<start){
                int server=logs[left][0];
                mp[server]--;
                if(mp[server]==0){
                    active--;
                }
                left++;
            }
            ans[idx]=n-active;
           
        }
        return ans;
    }
    
};