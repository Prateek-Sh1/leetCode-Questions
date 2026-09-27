class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=0;
        int prev2=nums[n-1];
        for(int i=n-2;i>=0;i--){
            int incl=prev1+nums[i];
            int exl=prev2;
            int crr=max(incl,exl);
            prev1=prev2;
            prev2=crr;
        }
        return prev2;
    }
};