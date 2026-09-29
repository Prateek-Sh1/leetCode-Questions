class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        int cnt=INT_MAX;
        for(auto it:tasks){
            int i=it[0];
            int j=it[1];
            cnt=min(cnt,i+j);
        }
        return cnt;
    }
};