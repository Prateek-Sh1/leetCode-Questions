class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s="";
        int mx=num*9;
        int n=num;
        if(sum>mx) return s;
        if(sum==mx){
            while(n>0){
                s+="9";
                n--;
            }
            return s;
        } 
        int x=9;
        while(num>0){
            if(sum-x>=0){
                s+=to_string(x);
                sum-=x;
                num--;
            }else{
                x--;
            }
        }

        return s;
    }
};