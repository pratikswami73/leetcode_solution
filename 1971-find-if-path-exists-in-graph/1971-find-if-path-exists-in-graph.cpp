class Solution {
public:
        bool dfs(int node,vector<vector<int>>&list,vector<bool>&visited,int destination){

            if(node==destination)return true;
            visited[node]=true;
            for(int neighbour:list[node]){
                if(!visited[neighbour]){
                    if( dfs(neighbour,list,visited,destination)){
                        return true;
                    }
                }

            }
            return  false;
        }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>list(n);
       
        for(auto edge:edges){
           int v=edge[0];
           int u=edge[1];
            
            list[v].push_back(u);
            list[u].push_back(v);

        }

       vector<bool>visited(n,false);
        bool ans=dfs(source,list,visited,destination);
        return ans;
    }
};