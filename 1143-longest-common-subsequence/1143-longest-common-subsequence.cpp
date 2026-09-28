class Solution {
public:
    // int cnt=0;
    // int helper(string text1, string text2,int i,int j,vector<vector<int>>&dp){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int tke=0;
    //     if(text1[i]==text2[j]){
    //         tke=helper(text1,text2,i-1,j-1,dp)+1;
    //     }
    //     int not_tk=max(helper(text1,text2,i-1,j,dp),helper(text1,text2,i,j-1,dp));
    //     return dp[i][j]=max(tke,not_tk);
    // }

    int helper(string text1, string text2){
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        dp[0][0]=0;
        // if(i<0 || j<0) return 0;
        // if(dp[i][j]!=-1) return dp[i][j];
        // int tke=0;
        // if(text1[i]==text2[j]){
        //     tke=helper(text1,text2,i-1,j-1,dp)+1;
        // }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // int n1=text1.length();
        // int n2=text2.length();
        // vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        // return helper(text1,text2,n1-1,n2-1,dp);
        return helper(text1,text2);
    }
};