class Solution {
public:
int c=0;
queue<pair<int,int>>q;
        void call(vector<vector<char>>&grid,vector<vector<bool>>&vis,int i,int j){
            
                c++;
                vis[i][j]=true;
            
            
            q.push({i,j});
            
            while(!q.empty()){
                auto it=q.front();
                int x=it.first;
                int y=it.second;
                vis[x][y]=true;
                q.pop();

                if(x-1>=0 && vis[x-1][y]==false && grid[x-1][y]=='1' ){
                    q.push({x-1,y});
                    vis[x-1][y]=true;
                    
                }
                if(y-1>=0 && vis[x][y-1]==false && grid[x][y-1]=='1'){
                    q.push({x,y-1});
                    vis[x][y-1]=true;
                }
                if(x+1<grid.size() && vis[x+1][y]==false && grid[x+1][y]=='1'){
                    q.push({x+1,y});
                    vis[x+1][y]=true;
                }
                if(y+1<grid[0].size() && vis[x][y+1]==false && grid[x][y+1]=='1'){
                    q.push({x,y+1});
                    vis[x][y+1]=true;
                }

            }
        }
    int numIslands(vector<vector<char>>& grid) {
      
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==false){

              call(grid,vis,i,j);
                }
            }
        }
     // int ans=count(grid,vis,q);
      return c;
        
    }
};