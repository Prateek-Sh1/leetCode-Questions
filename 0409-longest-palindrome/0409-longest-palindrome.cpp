class Solution {
public:
    int longestPalindrome(string s) {
        int z=0;
        bool t=false;
        vector<int>fh(26,0);
        vector<int>fh2(26,0);
        for(char x:s){
            if(x>='a' && x<='z') fh[x-'a']++;
            else fh2[x-'A']++;
        }
        for(int i=0;i<26;i++){
            if(fh[i]%2==0){
                z+=fh[i];
            }else{
                t=true;
                z+=(fh[i]-1);
            }

            if(fh2[i]%2==0){
                z+=fh2[i];
            }else{
                t=true;
                z+=(fh2[i]-1);
            }

        }
        if(t){
            return z+1; 
        }
        return z; 
    }
};