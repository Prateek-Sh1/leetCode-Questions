class Solution {
public:
    int reverseDegree(string s) {
        int sm=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            int ct=26-(s[i]-'a');
            sm+=((i+1)*ct);
        }
        return sm;
    }
};