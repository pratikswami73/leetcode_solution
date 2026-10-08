class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       bool inserted = false;
        vector<vector<int>> temp;

        for (int i = 0; i < intervals.size(); i++) {

            if (!inserted && newInterval[0] < intervals[i][0]) {
                temp.push_back(newInterval);
                inserted = true;
            }

            temp.push_back(intervals[i]);
        }

        if (!inserted) {
            temp.push_back(newInterval);
        }

        stack<pair<int,int>>st;
        st.push({temp[0][0],temp[0][1]});
        for(int i=1;i<temp.size();i++){
            auto x=st.top();
            if(temp[i][0]<=x.second){
                x.second=max(x.second,temp[i][1]);
                st.pop();
                st.push(x);
            }
            else{
                
                st.push({temp[i][0],temp[i][1]});
            }
            
        }
            vector<vector<int>>ans;
        while(!st.empty()){
            auto x=st.top();
            st.pop();
            ans.push_back({x.first,x.second});
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};