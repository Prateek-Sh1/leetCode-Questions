class Solution {
public:
    bool digitCount(string num) {
        int n=num.length();
        unordered_map<int,int>mp;
        vector<int>fr(11,0);
        for(int i=0;i<n;i++){
            int z=(num[i]-'0');
            fr[z]++;
            mp[i]=z;
        }
        for(auto it:mp){
            if(fr[it.first]!=it.second){
                return false;
            }
        }
        return true;

    }
};