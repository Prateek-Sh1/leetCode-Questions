class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int nt=0;
        int x;
        for(int i=0;i<n;i++){
            unordered_set<int>st;
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                x=st.size();
                nt+=(x*x);
            }
        }
        return nt;
    }
};