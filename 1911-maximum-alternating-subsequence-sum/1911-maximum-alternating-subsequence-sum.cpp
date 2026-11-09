class Solution {
public:
    long long hlpr(int i,vector<int>&nums,bool t,vector<vector<long long>>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        long long tk=0;
        if(t){
            tk=hlpr(i+1,nums,!t,dp)+nums[i];
        }
        else tk=hlpr(i+1,nums,!t,dp)-nums[i];
        long long nt=hlpr(i+1,nums,t,dp);
        return dp[i][t]=max(tk,nt);
    }
    // long long hlpr(int i,vector<int>&nums,bool t){
    //     if(i>=nums.size()) return 0;

    //     long long tk=0;
    //     if(t){
    //         tk=hlpr(i+1,nums,!t)+nums[i];
    //     }
    //     else tk=hlpr(i+1,nums,!t)-nums[i];
    //     long long nt=hlpr(i+1,nums,t);
    //     return max(tk,nt);
    // }
    // long long maxAlternatingSum(vector<int>& nums) {
        
    //     return hlpr(0,nums,true);
    // }
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return hlpr(0,nums,true,dp);
    }
};