class Solution {
public:
    bool isPalin(string &s,int i,int j){
        while(i<j){
            if(s[i]==s[j]){
                i++,j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    // int solve(string &s,int k,int i,int j,int n,vector<vector<int>>&dp){
    //     if(i>=n || j>=n) return 0;

    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(isPalin(s,i,j)){
    //         int take=1+solve(s,k,j+1,j+k,n,dp);
    //         int grow=solve(s,k,i,j+1,n,dp);
    //         int slide=solve(s,k,i+1,j+1,n,dp);
    //         return dp[i][j]=max(take,max(grow,slide));
    //     }
    //     else{
    //         int grow=solve(s,k,i,j+1,n,dp);
    //         int slide=solve(s,k,i+1,j+1,n,dp);
    //         return dp[i][j]=max(grow,slide);
    //     }
    // }
    int maxPalindromes(string s, int k) {
        int n=s.length();
        if(k==1) return n;
        vector<vector<int>>dp(n+1,vector<int>(n+1));
        // return solve(s,k,0,k-1,n,dp);

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(isPalin(s,i,j)){
                    int take=1+(j+k<=n?dp[j+1][j+k]:0);
                    int grow=dp[i][j+1];
                    int slide=dp[i+1][j+1];
                    dp[i][j]=max(take,max(grow,slide));
                }
                int grow=dp[i][j+1];
                int slide=dp[i+1][j+1];
                dp[i][j]=max(dp[i][j],max(grow,slide));
            }
        }
        return dp[0][k-1];
    }
};