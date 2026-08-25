class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());
        int x=1;
        while(st.find(k*x)!=st.end()){
            x++;
        }
        return k*x;

    }
};