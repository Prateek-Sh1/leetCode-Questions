class Solution {
public:
    int findNumberOfLIS(vector<int>& arr){
        int n=arr.size();
        vector<int>dp(n,1);
        vector<int>nt(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j]){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        nt[i]=nt[j];
                    }
                    else if(dp[j]+1==dp[i]) nt[i]+=nt[j];
                }
            }
        }
              
        int mx=0;
        for(int i=0;i<n;i++){
            if(mx<dp[i]){
                mx=dp[i];
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(mx==dp[i]){
                cnt+=nt[i];
            }
        }
        return cnt;
    }
};