class Solution {
public:
    int countOverlap(vector<vector<int>>&img1,vector<vector<int>>& img2,int R,int C){
        int c=0;
        int n=img1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i+R<0 ||j+C<0 || i+R>=n ||j+C>=n  ){
                    continue;
                }
                else{
                    if(img1[i][j]==1 && img2[i+R][j+C]==1){
                        c++;
                    }
                }
            }
        }
        return c;
    }

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int m=0;
        for(int R=-n+1;R<=n-1;R++){
            for(int C=-n+1;C<=n-1;C++){
                int s=countOverlap(img1,img2,R,C);
                m=max(m,s);
                }
            }
        return m;
        }

};