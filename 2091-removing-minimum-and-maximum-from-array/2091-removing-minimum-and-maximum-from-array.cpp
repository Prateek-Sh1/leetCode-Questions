class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mn=INT_MAX;
        int mx=INT_MIN;
        int x=0;
        int y=0;
        for(int i=0;i<n;i++){
            if(mn>nums[i]){
                x=i;
                mn=nums[i];
            }
            if(mx<nums[i]){
                y=i;
                mx=nums[i];
            }
        }

        int nx=min(x+1,n-x);
        int ny=min(y+1,n-y);

        int r=min(max(x+1,y+1),max(n-x,n-y));
        r=min(r,nx+ny);

        return r;
    }
};