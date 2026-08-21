class Solution {
public:
   
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        int prev=cost[0];
        int prev1=cost[1];

        for(int i=2;i<n;i++){
            int curr=cost[i]+min(prev1,prev);
            prev=prev1;
            prev1=curr;
        }
        prev1=min(prev1,prev);
        return prev1;
    }
};