class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        vector<pair<int,int>>idx(101,{-1,-1});
        vector<int>freq(101,0);
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            if(idx[nums[i]].first==-1){
                idx[nums[i]].first=i;
            }
            idx[nums[i]].second=i;
        }
        int cnt=0;
        for(int i:nums){
            if(st.find(i)==st.end() && freq[i]==(idx[i].second-idx[i].first+1)){
                cnt++;
                st.insert(i);
            }
        }
        return cnt;
    }
};