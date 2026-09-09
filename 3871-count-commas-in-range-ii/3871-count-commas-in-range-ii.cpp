class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        int dgt=0;
        long long x=n;
        while(x>0){
            int r=x%10;
            dgt++;
            x=x/10;
        }
        long long cnt=0;
        if(dgt<=16 && dgt>15){
            cnt+=(n-999999999999999)*5;
            return cnt+999000+(999000000*2)+(999000000000*3)+(999000000000000*4);
        }
        else if(dgt<=15 && dgt>12){
            cnt+=(n-999999999999)*4;
            return cnt+999000+(999000000*2)+(999000000000*3);
        }
        else if(dgt<=12 && dgt>9){
            cnt+=(n-999999999)*3;
            return cnt+999000+(999000000*2);
        }
        else if(dgt<=9 && dgt>6){
            cnt+=(n-999999)*2;
            return cnt+999000;
        }
        else return n-1000+1;
    }
};