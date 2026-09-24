class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for (int i=0;i<n;i++){
            int x=nums[i];
            int r=0;
            while(x>0){
                int z=x%10;
                r+=z;
                x=x/10;
            }
            if(r==i){
                return i;
            }
        }
        return -1;
    }
};