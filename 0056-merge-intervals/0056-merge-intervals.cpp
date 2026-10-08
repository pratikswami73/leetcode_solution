class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<pair<int,int>>st;
        st.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++){
            auto x=st.top();
            if(x.second<=intervals[i][1] && x.second>=intervals[i][0]){
                x.second=max(x.second,intervals[i][1]);
                st.pop();
                st.push(x);
            }
            else{
                if(intervals[i][0]<=x.second && intervals[i][1]<=x.second){
                    continue;
                }
                st.push({intervals[i][0],intervals[i][1]});

            }
        }
           // vector<vector<int>>ans;
           intervals.clear();

        while(!st.empty()){
            auto x=st.top();
            intervals.push_back({x.first,x.second});
            st.pop();
        }
        sort(intervals.begin(),intervals.end());
        return intervals;
        
    }
};