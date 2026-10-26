class Solution {
public:
queue<pair<int,int>>q;
int c=0;
  void call(vector<vector<int>>&grid,vector<vector<bool>>&vis,int i,int j,int k){
    vis[i][j]=true;
    long long sum=0;

    q.push({i,j});
    while(!q.empty()){
        auto it=q.front();
        int x=it.first;
        int y=it.second;
        vis[x][y]=true;
        sum+=grid[x][y];
        q.pop();
        if(x-1>=0 && vis[x-1][y]==false && grid[x-1][y]>0){
            q.push({x-1,y});
            vis[x-1][y]=true;
        }
         if(y-1>=0 && vis[x][y-1]==false && grid[x][y-1]>0){
            q.push({x,y-1});
            vis[x][y-1]=true;
        }
         if(x+1<grid.size() && vis[x+1][y]==false && grid[x+1][y]>0){
            q.push({x+1,y});
            vis[x+1][y]=true;
        }
         if(y+1<grid[0].size() && vis[x][y+1]==false && grid[x][y+1]>0){
            q.push({x,y+1});
            vis[x][y+1]=true;
        }

    }
    if(sum%k==0){
        c++;
    }
  }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<bool>>vis(n,vector<bool>(m,false));
        c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0 && vis[i][j]==false){
                    call(grid,vis,i,j,k);
                }
            }
        }

        return c;

    }
};