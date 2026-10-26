class Solution {
public:
    vector<long long>res;
    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    long long cnt=0;
    void dfs(int i,int j,vector<vector<int>>& grid, int n,int m){
        cnt+=grid[i][j];
        grid[i][j]=0;
        for(auto it:dir){
            int nr=it.first+i;
            int nc=it.second+j;
            if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]!=0){
                dfs(nr,nc,grid,n,m);
            }
        }

        return;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0){
                    dfs(i,j,grid,n,m);
                    res.push_back(cnt);
                    cnt=0;
                }
            }
        }
        int ct=0;
        for(auto it:res){
            if(it%k==0) ct++;
        }
        return ct;
    }
};