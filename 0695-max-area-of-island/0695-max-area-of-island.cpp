class Solution {
public:
int ans=0;
queue<pair<int,int>>q;
queue<pair<int,int>>q2;
   void visit(vector<vector<int>>&grid, vector<vector<bool>>&vis,int i,int j){
            if(vis[i][j]==false){
                while(!q2.empty()){
                    q2.pop();
                }
            }
        q.push({i,j});
        vis[i][j]=true;
        while(!q.empty()){
            auto it=q.front();
            q2.push({it.first,it.second});
            int w=q2.size();
            ans = max(ans,w);
            q.pop();
            int x=it.first;
            int y=it.second;
            if(x-1>=0 && vis[x-1][y]==false && grid[x-1][y]==1 ){
                q.push({x-1,y});
                vis[x-1][y]=true;
            }
             if(y-1>=0 && vis[x][y-1]==false && grid[x][y-1]==1 ){
                q.push({x,y-1});
                vis[x][y-1]=true;
            }
             if(x+1<grid.size() && vis[x+1][y]==false && grid[x+1][y]==1 ){
                q.push({x+1,y});
                vis[x+1][y]=true;
            }
             if(y+1<grid[0].size() && vis[x][y+1]==false && grid[x][y+1]==1 ){
                q.push({x,y+1});
                vis[x][y+1]=true;
            }

        }

   }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false && grid[i][j]==1){
                    visit(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};