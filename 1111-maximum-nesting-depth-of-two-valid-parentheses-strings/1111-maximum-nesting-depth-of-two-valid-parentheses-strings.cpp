class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.length();
        vector<int>rs;
        int dp=-1;
        for(char it:seq){
            if(it=='('){
                dp++;
                rs.push_back(dp%2);
            }
            else if(it==')'){
                rs.push_back(dp%2);
                dp--;
            }
        }
        return rs;
    }
};