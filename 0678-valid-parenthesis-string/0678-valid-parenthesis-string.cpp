class Solution {
public:
    bool helper(int m,int i,string s,int N,vector<vector<int>>&dp){
        if(m<0) return false;
        if(i==N && m==0) return true;
        if(i>=N && m>0) return false;
        if(dp[i][m]!=-1) return dp[i][m];
        bool tk=false;
        bool nt=false;
        bool nrt=false;
        if(s[i]=='('){
            tk=helper(m+1,i+1,s,N,dp);
        }
        else if(s[i]==')'){
            nt=helper(m-1,i+1,s,N,dp);
        }
        else if(s[i]=='*'){
            nrt=helper(m+1,i+1,s,N,dp) || helper(m-1,i+1,s,N,dp) || helper(m,i+1,s,N,dp);
        }
        return dp[i][m]= (tk || nt|| nrt);
    }
    bool checkValidString(string s) {
        int N=s.length();
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1));
        return helper(0,0,s,N,dp);
    }
};