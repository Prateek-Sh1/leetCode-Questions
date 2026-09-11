class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        int cnt=0;
        vector<int>mp(10,0);
        for(int i:digits){
            mp[i]++;
        }

        for(int i=0;i<10;i++){
            if(mp[i]>0 && i%2==0){
                mp[i]--;
                for(int j=0;j<10;j++){
                    if(mp[j]>0 && j!=0){
                        mp[j]--;
                        for(int k=0;k<10;k++){
                            if(mp[k]>0) cnt++;
                        }
                        mp[j]++;
                    }
                }
                mp[i]++;
            }
        }
        return cnt;
    }
};