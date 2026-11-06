class Solution {
public:
    string toLowerCase(string s) {
        string ans="";
        for(char c:s){
            if(c>='A' && c<='Z'){
                int x=c-'A';
                ans+=('a'+x);
            }
            else ans+=c;
        }
        return ans;
    }
};