class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.length();
        vector<string>res;
        map<char,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]].first=i;
                mp[s[i]].second=i;
            }
            else{
                mp[s[i]].second=i;
            }
        }
        vector<char>temp;
        vector<int>chrlst(26,-1);
        for(auto &it:mp){
            int r=it.second.second;
            for(int i=it.second.first;i<=r;i++){
                char x=s[i];
                if(mp[x].first<it.second.first){
                   temp.push_back(it.first);
                   break;
                }
                if(mp[x].second>r){
                    chrlst[it.first-'a']=mp[x].second;
                    r=mp[x].second;
                }
            }
        }
        for(int i=0;i<26;i++){
            if(chrlst[i]!=-1){
                mp['a'+i].second=chrlst[i];
            }
        }
        for(char c:temp){
            mp.erase(c);
        }
        vector<pair<int,int>>itv;
        for(auto it:mp){
            itv.push_back({it.second.first,it.second.second});
        }
        sort(itv.begin(),itv.end(),[](pair<int,int>a,pair<int,int>b){
            return a.second<b.second;
        });
        res.push_back(s.substr(itv[0].first,(itv[0].second-itv[0].first+1)));
        int r=itv[0].second;
        for(int i=1;i<itv.size();i++){
            if(itv[i].first>r){
                res.push_back(s.substr(itv[i].first,(itv[i].second-itv[i].first+1)));
                r=itv[i].second;
            }
        }
        return res;
    }
};