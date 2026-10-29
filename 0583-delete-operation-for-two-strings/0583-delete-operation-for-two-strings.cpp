class Solution {
public:
    int minDistance(string w1, string w2) {
        int m=w1.size();
        int n=w2.size();

        vector<vector<int>>sp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(w1[i-1]==w2[j-1]){
                    sp[i][j]=sp[i-1][j-1]+1;
                }
                else{
                    sp[i][j]=max(sp[i-1][j],sp[i][j-1]);
                }
            }
        }
        int x=sp[m][n];
        return (m+n)-(2*x);
    }
};