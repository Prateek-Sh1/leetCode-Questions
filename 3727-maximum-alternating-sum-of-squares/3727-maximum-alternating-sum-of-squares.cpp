class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int mx=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=(nums[i]*nums[i]);
            mx=max(nums[i],mx);
        }
        long long nt=mx;
        sort(nums.begin(),nums.end());
        int s=nums.size()/2;
        for(int i=0;i<nums.size()-1;i++){
            if(s>0){
                nt-=nums[i];
                s--;
            }
            else{
                nt+=nums[i];
            }
        }
        return nt;
    }
};