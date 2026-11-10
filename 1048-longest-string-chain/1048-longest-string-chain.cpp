class Solution {
public:
    bool chk(string s1,string s2){
        int i=0,j=0;
        int cnt=0;
        while(i<s1.length() && j<s2.length()){
            if(s1[i]==s2[j]){
                cnt++;
                i++,j++;
            }
            else j++;
        }
        if(cnt==s1.length()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),[](string&a ,string&b){
            return a.length()<b.length();
        });
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(((words[i].length()-1)==words[j].length()) && chk(words[j],words[i])){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};