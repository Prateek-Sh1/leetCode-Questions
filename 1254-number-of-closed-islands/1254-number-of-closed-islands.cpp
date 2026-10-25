   
class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis,int n,int m){
        vis[i][j]=true;
        grid[i][j]=2;
        for(auto it:dir){
            int nr=i+it.first;
            int nc=j+it.second;
            if(nr>=0 && nc>=0 && nr<n && nc<m){
                if(!vis[nr][nc] && grid[nr][nc]==0){
                    dfs(nr,nc,grid,vis,n,m);
                }
            }
        }
        return;
    }
    void dfsC(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis,int n,int m){
        vis[i][j]=true;
        for(auto it:dir){
            int nr=i+it.first;
            int nc=j+it.second;
            if(nr>=0 && nc>=0 && nr<n && nc<m){
                if(!vis[nr][nc] && grid[nr][nc]==0){
                    dfsC(nr,nc,grid,vis,n,m);
                }
            }
        }
        return;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        // DisjointSet ds(n*m);
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                vis[i][0]=true;
            }
            if(grid[i][m-1]==1) vis[i][m-1]=true;

            if(grid[i][0]==0 && vis[i][0]!=true){
                dfs(i,0,grid,vis,n,m);
            }
            if(grid[i][m-1]==0 && vis[i][m-1]!=true){
                dfs(i,m-1,grid,vis,n,m);
            }
        }   
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                vis[0][i]=true;
            }
            else if(grid[0][i]==0 && vis[0][i]!=true){
                dfs(0,i,grid,vis,n,m);
            }
            if(grid[n-1][i]==1) vis[n-1][i]=true;
            else if(grid[n-1][i]==0 && vis[n-1][i]!=true){
                dfs(n-1,i,grid,vis,n,m);
            }
        }   
        
        int cnt=0;
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    dfsC(i,j,grid,vis,n,m);
                    cnt++;
                }

            }
        }

        return cnt;
    }
};