class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp(n,0);
        int mn=nums[n-1];
        for(int i=n-1;i>=0;i--){
            if(mn>=nums[i]){
                mn=nums[i];
            }
            temp[i]=mn;
        }
        int mx=nums[0];
        for(int i=0;i<n;i++){
            if(mx<=nums[i]){
                mx=nums[i];
            }
            if((mx-temp[i])<=k){
                return i;
            }
        }
        return -1;
    }
};