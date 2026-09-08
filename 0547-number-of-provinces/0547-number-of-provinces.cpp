class Solution {
public:

    void dfs(int n,vector<bool>&visited,vector<vector<int>>&list){
        visited[n]=true;

        for(int i:list[n]){
            if(!visited[i]){
                dfs(i,visited,list);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       
        int n=isConnected.size();
         vector<vector<int>>list(n);
        int m=isConnected[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    list[i].push_back(j);
                    list[j].push_back(i);

                }
            }
        }
        vector<bool>visited(n,false);


      int count=0;
      for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i,visited,list);
            count++;
        }
      }
      return count;
        
            }
};