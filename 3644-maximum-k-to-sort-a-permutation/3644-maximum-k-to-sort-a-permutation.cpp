class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MAX;
        // int nt=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                // nt++;
                mx &=nums[i];
            }
        }
        if(mx==INT_MAX) return 0;
        return mx;
    }
};