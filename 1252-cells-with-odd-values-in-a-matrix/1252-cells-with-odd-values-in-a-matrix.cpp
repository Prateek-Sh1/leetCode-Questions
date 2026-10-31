class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>>vt(m,vector<int>(n,0));
        for(auto it:indices){
            int x=it[0];
            int y=it[1];
            for(int i=0;i<n;i++){
                vt[x][i]++;
            }
            for(int i=0;i<m;i++){
                vt[i][y]++;
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vt[i][j]%2!=0){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};