class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sm=0;
        for(int i:stones){
            sm+=i;
        }
        int ts=sm;
        sm/=2;
        vector<vector<bool>>sp(n+1,vector<bool>(sm+1,false));
        for(int i=0;i<=n;i++){
            sp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sm;j++){
                bool sk=sp[i-1][j];
                bool tk=false;
                if(stones[i-1]<=j){
                    tk=sp[i-1][j-stones[i-1]];
                }
                sp[i][j]=(tk || sk);
            }
        }

        for(int i=sm;i>=0;i--){
            if(sp[n][i]){
                return ts-(2*i);
            }
        }
        return 0;
    }
};