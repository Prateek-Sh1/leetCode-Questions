class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int x=INT_MIN;
        for(int i:nums){
            x=max(x,i);
        }
        int nt=0;
        for(int i:nums){
            nt+=abs(x-i);
        }
        return nt;
    }
};