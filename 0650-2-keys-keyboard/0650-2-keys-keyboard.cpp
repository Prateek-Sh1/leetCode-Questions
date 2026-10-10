class Solution {
public:
    int helper(int n,int lip,int opy,bool b){
        if(lip==n) return 0;
        if(lip>n) return 1e8;
        int c=1e8;
        if(b){
            c=helper(n,lip,lip,false);
        }
        int p=helper(n,lip+opy,opy,true);
        
        return min(c,p)+1;
        
    }
    int minSteps(int n) {
        if(n==1) return 0;
        return helper(n,1,1,true)+1;
    }
};