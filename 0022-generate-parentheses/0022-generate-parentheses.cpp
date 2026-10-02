class Solution {
public:
    // 
    void helper(int n,int m,vector<string>&rs,string s){
        if(n>m || n<0 || m<0) return;
        if(m==0 && n==0){
            rs.push_back(s);
            return;
        }
        helper(n-1,m,rs,s+"(");
        helper(n,m-1,rs,s+")");
    }
    vector<string> generateParenthesis(int n) {
        vector<string>rs;
        helper(n,n,rs,"");
        return rs;
    }
};