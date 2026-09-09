class Solution {
public:
   void cal(queue <pair<pair<int,int>,int>>q,vector<vector<int>>&ans,vector<vector<bool>>&vis,vector<vector<int>>&mat){
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int i=it.first.first;
            int j=it.first.second;
            int k=it.second;
            ans[i][j]=k;
            if(i-1>=0 && mat[i-1][j]==1 && vis[i-1][j]==false){
                q.push({{i-1,j},k+1});
                vis[i-1][j]=true;
            }
            if(j-1>=0 && mat[i][j-1]==1 && vis[i][j-1]==false){
                q.push({{i,j-1},k+1});
                   vis[i][j-1]=true;
            }
            if(i+1<mat.size() && mat[i+1][j]==1 && vis[i+1][j]==false){
                q.push({{i+1,j},k+1});
                   vis[i+1][j]=true;
            }
            if(j+1<mat[0].size() && mat[i][j+1]==1 && vis[i][j+1]==false){
                q.push({{i,j+1},k+1});
                   vis[i][j+1]=true;
            }
        }


   }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       queue<pair<pair<int,int>,int>>q;

       int n=mat.size();
       int m=mat[0].size();
       vector<vector<int>>ans(n,vector<int>(m,0));
       vector<vector<bool>>vis(n,vector<bool>(m,false));

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0){
                q.push({{i,j},0});
                vis[i][j]=true;



            }
        }
       }
       cal(q,ans,vis,mat);
       return ans;
    }
};