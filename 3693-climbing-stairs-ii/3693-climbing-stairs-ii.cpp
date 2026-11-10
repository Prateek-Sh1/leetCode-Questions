class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int a=dp[i-1]+(costs[i-1]+1);
            int b=INT_MAX;
            if(i>1){
                b=dp[i-2]+(costs[i-1]+4);
            }
            int c=INT_MAX;
            if(i>2){
                c=dp[i-3]+(costs[i-1]+9);
            }
            dp[i]=min(a,min(b,c));
        }
        
        return dp[n];
    }
};