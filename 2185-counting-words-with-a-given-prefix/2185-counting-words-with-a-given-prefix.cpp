class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt=0;
        int n=pref.length();
        for(string it:words){
            string s=it.substr(0,n);
            if(s==pref) cnt++;
        }
        return cnt;
    }
};