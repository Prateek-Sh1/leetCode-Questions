class Solution {
public:
    int sumCounts(vector<int>& nums) {
        unordered_set<int>st;
        int n=nums.size();
        int nt=0;
        int x=1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                st.insert(nums[j]);
                x=st.size();
                nt+=(x*x);
            }
            st.clear();
        }
        return nt;
    }
};