class Solution {
public:
    int scoreOfParentheses(string s) {
        int cnt=0;
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                cnt++;
            }
            else if(i-1>=0 && s[i]==')' && s[i-1]=='('){
                ans+=pow(2,cnt-1);
                cnt--;
            }
            else{
                cnt--;
            }
            
        }
        return ans;
    }
};