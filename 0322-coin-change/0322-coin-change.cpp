class Solution {
public:

    int solveRec(vector<int>& coins, int x){
        vector<int>dp(x+1,INT_MAX);
        dp[0]=0;

        for(int i=1;i<=x;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        if(dp[x]==INT_MAX) return -1;
        return dp[x];
    }


    // int solveRec(vector<int>& coins, int x,vector<int>&dp){
    //     if(x==0) return 0;
    //     if(x<0)return INT_MAX;

    //     if(dp[x]!=-1) return dp[x];
        
    //     int mn=INT_MAX;
    //     for(int i=0;i<coins.size();i++){
    //         int ans=solveRec(coins,x-coins[i],dp);
    //         if(ans!=INT_MAX){
    //             mn=min(mn,ans+1);
    //         }
    //     }

    //     dp[x]=mn;

    //     return dp[x];
    // }
    int coinChange(vector<int>& coins, int amount) {
        // vector<int>dp(amount+1,-1);
        // int ans=solveRec(coins,amount,dp);
        int ans=solveRec(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};