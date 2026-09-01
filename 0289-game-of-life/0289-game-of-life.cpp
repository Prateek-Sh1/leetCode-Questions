class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<pair<int,int>>dir={{0,-1},{0,1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1){
                    int cnt=0;
                    for(auto it:dir){
                        int nr=it.first+i;
                        int nc=it.second+j;
                        if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]>0){
                            cnt++;
                        }
                    }
                    if(cnt!=0) board[i][j]=cnt;
                }
                else{
                    int cnt=0;
                    for(auto it:dir){
                        int nr=it.first+i;
                        int nc=it.second+j;
                        if(nr>=0 && nc>=0 && nr<n && nc<m && board[nr][nc]>0){
                            cnt++;
                        }
                    }
                    if(cnt!=0) board[i][j]=-cnt;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==-3 || board[i][j]==2 || board[i][j]==3 ){
                    board[i][j]=1;
                }else{
                    board[i][j]=0;
                }
            }
        }
        return ;
    }
};