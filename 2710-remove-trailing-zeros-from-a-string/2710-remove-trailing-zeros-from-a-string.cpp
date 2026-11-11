class Solution {
public:
    string removeTrailingZeros(string num) {
        int nt=0;
        int n=num.length();
        for(int i=n-1;i>=0;i--){
            if(num[i]=='0') nt++;
            else break;
        }
        string st=num.substr(0,n-nt);
        return st;
    }
};