class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>tb(n,0);
        vector<int>lf(n,0);
        int mx1;
        int mx2;
        for(int i=0;i<n;i++){
            mx1=0;
            mx2=0;
            for(int j=0;j<n;j++){
                mx1=max(mx1,grid[i][j]);
                mx2=max(mx2,grid[j][i]);
            }
            tb[i]=mx1;
            lf[i]=mx2;
        }

        int cnt=0;
        int mn=0;
        for(int i=0;i<n;i++){
            mx1=tb[i];
            for(int j=0;j<n;j++){
             mn=min(mx1,lf[j]);
             cnt+=(mn-grid[i][j]);
            }
        }

        return cnt;
    }
};