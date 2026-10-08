class Solution {
public:
    string removeOuterParentheses(string s) {
        string rs="";
        int n=s.length();
        stack<char>st;
        int i=0;
        for(char x:s){
            if(x=='(' && i==0){
                i++;
                continue;
            }
            else if(x=='('){
                st.push(x);
                rs+=x;
            }
            else if(!st.empty() && x==')' && st.top()=='('){
                rs+=')';
                st.pop();
            }
            else if(st.empty() && x==')'){
                 i=0;
                 continue;
            }
        }
        return rs;
    }
};