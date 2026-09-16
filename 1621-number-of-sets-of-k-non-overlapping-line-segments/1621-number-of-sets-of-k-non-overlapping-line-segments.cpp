class Solution {
public:
    int mod=1e9+7;
    // int solve(int n,int k,int i,vector<vector<int>>&dp){
    //     if(k==0) return 1;
    //     if(i>=n) return 0;
    //     if(dp[i][k]!=-1) return dp[i][k];
    //     long long skip=solve(n,k,i+1,dp)%mod;
    //     long long take=0;
    //     for(int j=i+1;j<n;j++){
    //         take+=(solve(n,k-1,j,dp)%mod);
    //     }

    //     return dp[i][k]=(skip+take)%mod;
    // }
    int numberOfSets(int n, int k) {
        if(k==n-1) return 1;
        // vector<vector<int>>dp(1001,vector<int>(1001,-1));
        vector<vector<int>>dp(1001,vector<int>(1001,0));
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int K=1;K<=k;K++){
            vector<int>prevRowSum(n+1,0);
            for(int x=n-1;x>=0;x--){
                prevRowSum[x]=(prevRowSum[x+1]+dp[K-1][x])%mod;
            }
            for(int i=n-1;i>=0;i--){
                int skip=dp[K][i+1]%mod;
                int take=prevRowSum[i+1];
                // for(int j=i+1;j<n;j++){
                //     take=(take+dp[K-1][j])%mod;
                // }
                dp[K][i]=(take+skip)%mod;
            }
        }

        return dp[k][0];


        // return solve(n,k,0,dp)%mod;
    }
};