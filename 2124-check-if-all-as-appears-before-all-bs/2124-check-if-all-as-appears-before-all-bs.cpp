class Solution {
public:
    bool checkString(string s) {
        int a=0;
        int b=0;
        for(char c:s){
            if(c=='a' && b!=0) return false;
            else if(c=='a') a++;
            else if(c=='b') b++;
        }
        return true;
    }
};