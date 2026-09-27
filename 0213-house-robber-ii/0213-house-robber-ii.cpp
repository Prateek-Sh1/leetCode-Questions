class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int pre1=0;
        int pre2=nums[n-1];
        for(int i=n-2;i>=1;i--){
            int incl=pre1+nums[i];
            int excl=pre2;
            int crr=max(incl,excl);
            pre1=pre2;
            pre2=crr;
        }

        int res=pre2;

        pre1=0;
        pre2=nums[n-2];
        for(int i=n-3;i>=0;i--){
            int incl=pre1+nums[i];
            int excl=pre2;
            int crr=max(incl,excl);
            pre1=pre2;
            pre2=crr;
        }

        res=max(res,pre2);
        return res;
    }
};