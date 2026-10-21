class Solution {
public:
    int minOperations(string s) {
        bool x=false;
        int n=s.length();
        int mn=s[0]-'a';
        int cmn=1;
        int cmx=1;
        int mx=s[0]-'a';
        for(int i=1;i<n;i++){
            if(s[i]<s[i-1]){
                x=true;
            }
            if(mn>(s[i]-'a')){
                cmn=1;
                mn=(s[i]-'a');
            }
            else if(mn==(s[i]-'a')) cmn++;
            if(mx<(s[i]-'a')){
                cmx=1;
                mx=(s[i]-'a');
            }
            else if(mx==(s[i]-'a')) cmx++;
            // mn=min(mn,s[i]-'a');
            // mx=max(mx,s[i]-'a');
        }
        if(x && n==2) return -1;
        if(!x) return 0;
        if(mx==(s[0]-'a') && mn==(s[n-1]-'a') && (cmn==1 && cmx==1)){
            return 3;
        }
        // if(((mn==(s[0]-'a') && mx!=(s[n-1]-'a')) || (mn!=(s[0]-'a') && mx==(s[n-1]-'a'))) && (cmn==1 && cmx==1)){
        //     return 1;
        // }
        if( mn==(s[0]-'a') || mx==(s[n-1]-'a')){
            return 1;
        }
        // if((mn==(s[0]-'a') && mx==(s[n-1]-'a')) && (cmn>1 || cmx>1)) return 1;
        // if((cmn>1 || cmx>1)) return 1;
        return 2;
    }
};