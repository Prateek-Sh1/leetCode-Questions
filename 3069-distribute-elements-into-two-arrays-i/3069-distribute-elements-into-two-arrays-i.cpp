class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>rs;
        vector<int>rgt;
        int i=nums[0];
        int j=nums[1];
        rs.push_back(i);
        rgt.push_back(j);
        for(int k=2;k<n;k++){    
            if(i<j){
                j=nums[k];
                rgt.push_back(j);
            }
            else{
                i=nums[k];
                rs.push_back(i);
            }
        }
        
        for(int s:rgt){
            rs.push_back(s);
        }
        return rs;
    }
};