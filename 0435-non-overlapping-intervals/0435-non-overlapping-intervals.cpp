class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        stack<pair<int,int>>st;
        int count=0;
        st.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++){
            auto x=st.top();
            if(x.second>intervals[i][0]){
                count++;
                if(x.second>intervals[i][1]){
                    x.first=intervals[i][0];
                    x.second=intervals[i][1];
                    st.pop();
                    st.push(x);
                }

            }
            else{
                st.push({intervals[i][0],intervals[i][1]});
            }
        }
        return count;
    }
};