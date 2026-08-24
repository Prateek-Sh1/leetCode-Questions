class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st1(nums1.begin(),nums1.end());
        unordered_set<int>st2(nums2.begin(),nums2.end());
        vector<int>rs;
        int ans=0;
        for(int i:nums1){
            if(st2.find(i)!=st2.end()){
                ans++;
            }
        }
        rs.push_back(ans);
        ans=0;
        for(int i:nums2){
            if(st1.find(i)!=st1.end()){
                ans++;
            }
        }
        rs.push_back(ans);
        return rs;
    }
};