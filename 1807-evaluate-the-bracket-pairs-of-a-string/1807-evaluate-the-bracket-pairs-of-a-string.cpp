class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto itv:knowledge){
            string k=itv[0];
            string v=itv[1];
            mp[k]=v;
        }
        vector<string>val;
        char x=')';
        string ky="";
        for(char c:s){
            if(c==')'){
                x=')';
                if(mp.find(ky)==mp.end()){
                    val.push_back("?");
                }
                else{
                    val.push_back(mp[ky]);
                }
                ky="";
                continue;
            }
            if(c=='('){
                x='(';
                continue;
            }
            if(x=='('){
                ky+=c;
            }
        }

        x=')';
        int i=-1;
        string res="";
        for(char c:s){
            if(c=='('){
                i++;
                res+=(val[i]);
                x='(';
                continue;
            }
            if(c==')'){
                x=')';
                continue;
            }
            if(x=='(') continue;
            if(x==')'){
                res+=c;
            }
        }
        return res;
    }
};