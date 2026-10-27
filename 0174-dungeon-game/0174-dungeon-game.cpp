class Solution {
public:
    int hlpr(int i,int j,vector<vector<int>>& dgn,vector<vector<int>>&dp){
        if(i>=dgn.size() || j>=dgn[0].size()) return INT_MAX;
        // if(i==0 && j==0) return 1;
        if(i==dgn.size()-1 && j==dgn[0].size()-1){
            return max(1,1-dgn[i][j]);
        }
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        int rgt=hlpr(i,j+1,dgn,dp);
        int btm=hlpr(i+1,j,dgn,dp);
        return dp[i][j]=max(min(rgt,btm)-dgn[i][j],1);
    }
    int calculateMinimumHP(vector<vector<int>>& dgn) {
        int m=dgn.size();
        int n=dgn[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MAX));
        return hlpr(0,0,dgn,dp);
    }
};