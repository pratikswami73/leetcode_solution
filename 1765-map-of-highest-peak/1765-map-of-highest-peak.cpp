class Solution {
public:
void cal(vector<vector<int>>&ans,vector<vector<bool>>&vis,queue<pair<pair<int,int>,int>>q,vector<vector<int>>&isWater){
while(!q.empty()){
  auto it=q.front();
  q.pop();
  int i=it.first.first;
  int j=it.first.second;
  int k=it.second;
  ans[i][j]=k;
  if(i-1>=0 && vis[i-1][j]==false && isWater[i-1][j]==0){
    q.push({{i-1,j},k+1});
    vis[i-1][j]=true;
  }
  if(j-1>=0 && vis[i][j-1]==false && isWater[i][j-1]==0){
    q.push({{i,j-1},k+1});
    vis[i][j-1]=true;
  }
  if(i+1<isWater.size() && vis[i+1][j]==false && isWater[i+1][j]==0){
    q.push({{i+1,j},k+1});
    vis[i+1][j]=true;
  }
  if(j+1<isWater[0].size() && vis[i][j+1]==false && isWater[i][j+1]==0){
    q.push({{i,j+1},k+1});
    vis[i][j+1]=true;
  }
}

}
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));


        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        cal(ans,vis,q,isWater);
        return ans;
    }
};