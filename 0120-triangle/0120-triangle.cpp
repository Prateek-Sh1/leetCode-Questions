class Solution {
public:
    // int hlpr(vector<vector<int>>& tri,int n,int i,int j){
    //     if(i==n){
    //         return 0;
    //     }
    //     // if(sp[i][j]!=-1) return sp[i][j];
    //     int a=tri[i][j]+hlpr(tri,n,i+1,j);
    //     int b=tri[i][j]+hlpr(tri,n,i+1,j+1);
    //     return min(a,b);        
    // }
    int hlpr(vector<vector<int>>& tri,int &n,int i,int j,vector<vector<int>>&sp){
        if(i==n){
            return 0;
        }
        if(sp[i][j]!=INT_MAX) return sp[i][j];
        int a=tri[i][j]+hlpr(tri,n,i+1,j,sp);
        int b=tri[i][j]+hlpr(tri,n,i+1,j+1,sp);
        return sp[i][j]=min(a,b);        
    }
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        vector<vector<int>>sp(n+1,vector<int>(n+1,INT_MAX));
        return hlpr(tri,n,0,0,sp);

        // return hlpr(tri,n,0,0);
    }
};