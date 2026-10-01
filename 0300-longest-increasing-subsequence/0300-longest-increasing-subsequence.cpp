class Solution {
public:
    int helpr(vector<int>& nums,int i,int prv,vector<vector<int>>&dp){
        if(i>=nums.size()) return 0;
        if( dp[i][prv+1]!=-1) return dp[i][prv+1];
        int tk=0;
        if(prv==-1 || nums[i]>nums[prv]){
            tk=1+helpr(nums,i+1,i,dp);
        }
        int nt=helpr(nums,i+1,prv,dp);
        return dp[i][prv+1]=max(tk,nt);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return helpr(nums,0,-1,dp);
    }
}; 