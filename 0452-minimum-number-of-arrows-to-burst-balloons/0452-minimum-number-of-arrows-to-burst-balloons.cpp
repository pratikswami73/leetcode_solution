class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
      stack<pair<int,int>>st;
      st.push({points[0][0],points[0][1]});
        for(int i=1;i<points.size();i++){
          if(points[i][0]<=st.top().second){
            auto x=st.top();
            st.pop();
            x.first=max(x.first,points[i][0]);
            x.second=min(x.second,points[i][1]);
            st.push(x);
          }
          else{
            st.push({points[i][0],points[i][1]});
          }
        }
        return st.size();
    }
};