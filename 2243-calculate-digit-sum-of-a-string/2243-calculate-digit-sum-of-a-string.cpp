class Solution {
public:
    string hlpr(string s,int k){
        string st="";
        int cnt=0;
        int nt=0;
        for(char c:s){
            cnt+=(c-'0');
            nt++;
            if(nt==k){
                st+=to_string(cnt);
                cnt=0;
                nt=0;
            }
        }

        if(nt>0){
            st+=to_string(cnt);
        }

        return st;
    }
    string digitSum(string s, int k) {
        while(s.length()>k){
            s=hlpr(s,k);
        }
        return s;
    }
};