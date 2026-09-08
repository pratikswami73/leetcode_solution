class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
       

        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }

         vector<vector<bool>>vis(n,vector<bool>(m,false));
         int ans=0;
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int i=x.first.first;
            int j=x.first.second;
            int t=x.second;

            if(i-1>=0 && !vis[i-1][j]  && grid[i-1][j]==1 ){
                q.push({{i-1,j},t+1});
                vis[i-1][j]=true;
            }
             if(j-1>=0 && !vis[i][j-1]  && grid[i][j-1]==1 ){
                q.push({{i,j-1},t+1});
                vis[i][j-1]=true;
            }
             if(i+1<n && !vis[i+1][j]  && grid[i+1][j]==1 ){
                q.push({{i+1,j},t+1});
                vis[i+1][j]=true;
            }
             if(j+1<m && !vis[i][j+1]  && grid[i][j+1]==1 ){
                q.push({{i,j+1},t+1});
                vis[i][j+1]=true;
            }
            ans=max(ans,t);
        }

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false && grid[i][j]==1){
                  return -1;
                }
            }
        }
        return ans;

    }
};