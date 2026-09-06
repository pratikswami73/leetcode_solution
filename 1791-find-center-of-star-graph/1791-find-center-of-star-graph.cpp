class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
    int c1=edges[0][0];
    int c2=edges[0][1];
    int count1=0;
    int count2=0;
    if(edges[1][0]==c1)count1++;
    if(edges[1][1]==c1)count1++;
     if(edges[1][0]==c2)count2++;
    if(edges[1][1]==c2)count2++;

    if(count1==1)return c1;
    if(count2==1)return c2;
    return 0;

    }
};