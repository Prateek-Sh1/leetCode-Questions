class Solution {
public:
    unordered_set<string>rs;
    void helper(string& s,string& t,int i,int b,int lft,int rgt){
        if(b<0) return;
        if(i>=s.length() && b==0 && lft==0 && rgt==0){
            rs.insert(t);
            return;
        }
        if(i>=s.length() && b!=0 ) return;
        if(s[i]=='('){
            t.push_back(s[i]);
            helper(s,t,i+1,b+1,lft,rgt);
            t.pop_back();
            if(lft>0) helper(s,t,i+1,b,lft-1,rgt);
        }
        else if(s[i]==')'){
            t.push_back(s[i]);
            if (b>0) helper(s,t,i+1,b-1,lft,rgt);
            t.pop_back();
            if(rgt>0) helper(s,t,i+1,b,lft,rgt-1);
        }
        else{
            t.push_back(s[i]);
            helper(s,t,i+1,b,lft,rgt);
            t.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n=s.length();
        vector<string>rf;
        int lft=0;
        int rgt=0;
        for(char c:s){
            if(c=='('){
                lft++;
            }
            else if(c==')'){
                if(lft>0){
                    lft--;
                }
                else{
                    rgt++;
                }
            }
        }
        string t="";
        helper(s,t,0,0,lft,rgt);
        
        for(auto r:rs){
            rf.push_back(r);
        }
        return rf;
    }
};