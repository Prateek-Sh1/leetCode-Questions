class Solution {
public:
    // int hlpr(int i,int j,vector<vector<int>>& dgn,vector<vector<int>>&dp){
    //     if(i>=dgn.size() || j>=dgn[0].size()) return INT_MAX;
    //     // dp[i][j] represents the minimum health required to save princes from i,j to m-1,n-1; 
    //     if(i==dgn.size()-1 && j==dgn[0].size()-1){
    //         return max(1,1-dgn[i][j]);
    //     }
    //     if(dp[i][j]!=INT_MAX) return dp[i][j];
    //     int rgt=hlpr(i,j+1,dgn,dp);
    //     int btm=hlpr(i+1,j,dgn,dp);
    //     return dp[i][j]=max(min(rgt,btm)-dgn[i][j],1);
    // }
    // int calculateMinimumHP(vector<vector<int>>& dgn) {
    //     int m=dgn.size();
    //     int n=dgn[0].size();
    //     vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
    //     return hlpr(0,0,dgn,dp);
    // }


    int calculateMinimumHP(vector<vector<int>>& dgn) {
        int m=dgn.size();
        int n=dgn[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){
                    dp[m-1][n-1]=max(1,1-dgn[m-1][n-1]);
                    continue;
                } 
                int rgt=dp[i][j+1];
                int bt=dp[i+1][j];
                dp[i][j]=max(1,min(rgt,bt)-dgn[i][j]);
            }
        }
        return dp[0][0];
    }
};