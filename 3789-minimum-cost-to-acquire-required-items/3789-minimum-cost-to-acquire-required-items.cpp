class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    long long x= 1LL*need1*cost1+1LL*need2*cost2;
    long long y=1LL*costBoth*max(need1,need2);
    long long w;
    if(need1>need2){
          w=1LL*costBoth*min(need1,need2)+1LL*(need1-need2)*cost1;

    }
    else{
          w=1LL*costBoth*min(need1,need2)+1LL*(need2-need1)*cost2;
    }
    return min(x,min(y,w));
    }
};