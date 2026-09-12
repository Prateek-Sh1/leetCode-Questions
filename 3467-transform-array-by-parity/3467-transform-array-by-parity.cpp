class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n=nums.size();
        int ec=0;
        for(int i:nums){
            if(i%2==0) ec++;
        }
        for(int i=0;i<n;i++){
            if(i<ec)nums[i]=0;
            else{
                nums[i]=1;
            }
        }
        return nums;
    }
};