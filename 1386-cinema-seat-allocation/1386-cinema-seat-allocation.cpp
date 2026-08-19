class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rS) {
        sort(rS.begin(),rS.end());
        unordered_set<int>st;
        bool lft=false;
        bool mid=false;
        bool rgt=false;
        int cnt=0;
        st.insert(rS[0][0]);
        int m=rS.size();
        for(int i=0;i<m-1;i++){
            int ri=rS[i][0];
            int sti=rS[i][1];

            if(2<=sti && sti<=5){
                lft=true;
            }
            if(4<=sti && sti<=7){
                mid=true;
            }
            if(6<=sti && sti<=9){
                rgt=true;
            }

            if(ri!=rS[i+1][0]){
                st.insert(rS[i+1][0]);
                if(!lft && !rgt){
                    cnt+=2;
                }
                else if(!mid){
                    cnt++;
                }
                else if(!lft || !rgt){
                    cnt++;
                }
                lft=false;
                mid=false;
                rgt=false;
            }
        }
        if(m){
            if(m==1 || rS[m-1][0]!=rS[m-2][0]){
                lft=false;
                mid=false;
                rgt=false;
            }
            int sti=rS[m-1][1];
            if(2<=sti && sti<=5){
                lft=true;
            }
            if(4<=sti && sti<=7){
                mid=true;
            }
            if(6<=sti && sti<=9){
                rgt=true;
            }
        }

        if (!lft && !rgt) {
            cnt += 2;
        } else if (!mid) {
            cnt++;
        } else if (!lft || !rgt) {
            cnt++;
        }

        int s=st.size();
        int r=n-s;
        cnt+=(r*2);
        
        return cnt;
    }
};