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
        // return hlpr(obst,m-1,n-1,dp);
        if(obst[0][0]==1) dp[0][0]=0;
        else dp[0][0]=1;
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0){
        //             if(j>0 && (dp[i][j-1]==0 || obst[i][j]==1)) dp[i][j]=0;
        //             else dp[i][j]=1;
        //         }
        //         if(j==0){
        //             if(i>0 && (dp[i-1][j]==0 || obst[i][j]==1)) dp[i][j]=0;
        //             else dp[i][j]=1;
        //         }
        //     }
        // }
        for(int i=1;i<m;i++){
            if(dp[i-1][0]==0 || obst[i][0]==1) dp[i][0]=0;
            else dp[i][0]=1;
        }
        for(int i=1;i<n;i++){
           if(dp[0][i-1]==0 || obst[0][i]==1) dp[0][i]=0;
            else dp[0][i]=1;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obst[i][j]==1) dp[i][j]=0;
                else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};