class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>freq(51,0);
        int mx=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            mx=max(mx,nums[i]);
        }
        if(k==n) return mx;
        int cnt=-1;
        if(k==1){
            for(int i=0;i<51;i++){
                if(freq[i]==1){
                    cnt=max(cnt,i);
                }
            }
            return cnt;
        }

        if(freq[nums[0]]>1 && freq[nums[n-1]]>1){
            return cnt;
        }
        else if(freq[nums[0]]==1 && freq[nums[n-1]]==1){
            return max(nums[0],nums[n-1]);
        }
        else{
            if(freq[nums[0]]!=1){
                return nums[n-1];
            }
            return nums[0];
        }

    }
};