class Solution {
public:
    int sumBase(int n, int k) {
        int nt=0;
        while(k<=n){
            nt+=n%k;
            n=n/k;
        }
        nt+=n;
        return nt;
    }
};