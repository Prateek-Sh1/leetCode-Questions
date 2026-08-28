class Solution {
public:
    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    void dfs(int i,int j,vector<vector<char>>& board,int n,int m){
        if(i>=n || j>=m) return;
        board[i][j]='a';
        for(auto it:dir){
            int nr=it.first+i;
            int nc=it.second+j;
            if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]=='X'){
                 dfs(nr,nc,board,n,m);
            }
        }
        return ;
    }
    int countBattleships(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='X'){
                    dfs(i,j,board,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};