class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>rs;
        int cnt=0;
        int is=0;
        for(int i=0;i<n;i++){
            if(target>nums[i]){
                is++;
            }
            else if(target==nums[i]){
                cnt++;
            }
        }
        while(cnt>0){
            rs.push_back(is);
            is++;
            cnt--;
        }
        return rs; 

    }

};