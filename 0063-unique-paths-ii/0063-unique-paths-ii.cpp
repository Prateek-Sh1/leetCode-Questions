class Solution {
public:

    // int hlpr(vector<vector<int>>& obst,int i,int j){
    //     if(i==0 && j==0) return 1;
    //     if(i<0 || j<0 || obst[i][j]==1) return 0;
    //     int tp=hlpr(obst,i-1,j);
    //     int lf=hlpr(obst,i,j-1);
    //     return tp+lf;
    // }

    
    int hlpr(vector<vector<int>>& obst,int i,int j,vector<vector<int>>&dp){
        if(i<0 || j<0 || obst[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int tp=hlpr(obst,i-1,j,dp);
        int lf=hlpr(obst,i,j-1,dp);
        return dp[i][j]=tp+lf;
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obst) {
        int m=obst.size();
        int n=obst[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return hlpr(obst,m-1,n-1,dp);
    }
};