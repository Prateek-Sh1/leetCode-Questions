class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int x=nums.size();
        sort(nums.begin(),nums.end());
        int z=0;
        if(x%2!=0){
            x/=2;
            z=nums[x];
        }
        else{
            x/=2;
            z=(nums[x-1]+nums[x])/2;
        } 
        int nt=0;
        for(int i:nums){
            nt+=abs(z-i);
        }
        return nt;
    }
};