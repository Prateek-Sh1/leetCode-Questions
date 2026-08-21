class Solution {
public:
    int climbStairs(int n) {
        int x=0;
        int y=1;
        for(int i=1;i<=n;i++){
            int curr=x+y;
            x=y;
            y=curr;
        }

        return y;
    }
};