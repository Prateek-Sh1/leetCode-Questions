class Solution {
public:
    bool checkPowersOfThree(int n) {
        int x=0;
        int z=n;
        while(z>=pow(3,x)){
            x++;
        }    
        x--;
        while(x>=0){
            if(n>=pow(3,x)){
                n=n-pow(3,x);
                x--;
            }
            else{
                x--;
            }
        }
        if(n==0) return true;
        return false; 
    }
};