class Solution {
public:
  void call(vector<vector<int>>&rooms,vector<bool>&vis,int i){
    queue<int>q;
    for(int j=0;j<rooms[i].size();j++){
        if(vis[rooms[i][j]]==false){
        q.push(rooms[i][j]);
        }

    }
    while(!q.empty()){
        if(vis[q.front()]==false){
            vis[q.front()]=true;
            int x=q.front();
            for(int i=0;i<rooms[x].size();i++){
                if(vis[rooms[x][i]]==false){
                    q.push(rooms[x][i]);
                }
            }
        }
        q.pop();
        
    }
    
  }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       int n=rooms.size();
       vector<bool>vis(n,false);
       vis[0]=true;
       call(rooms,vis,0);
       for(int i=0;i<n;i++){
        if(vis[i]==true){
        call(rooms,vis,i);
        }
       } 

       for(int i=0;i<n;i++){
        if(vis[i]==false){
            return false;
        }
        
       }
       return true;
    }
};