class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans="";
        for(char c:s){
            if(k==0) break;
            if(c==' '){
                if(k!=1){
                    ans+=c;
                }
                k--;
            }
            else{
                ans+=c;
            }
        }
        return ans;
    }
};