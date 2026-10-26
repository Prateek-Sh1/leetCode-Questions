class Solution {
public:
    // int hlpr(int i,int j){
    //     if(i==0 && j==0) return 1;
    //     if(i<0 || j<0) return 0;

    //     int tp=hlpr(i-1,j);
    //     int lf=hlpr(i,j-1);
    //     return tp+lf;
    // }

    int hlpr(int i,int j,vector<vector<int>>&dp){
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int tp=hlpr(i-1,j,dp);
        int lf=hlpr(i,j-1,dp);
        return dp[i][j]=tp+lf;
    }

    int uniquePaths(int m, int n) {
        // return hlpr(m-1,n-1);
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return hlpr(m-1,n-1,dp);

    }
};