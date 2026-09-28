class Solution {
public:
    int maxDepth(string s) {
        int n=s.length();
        stack<char>st;
        int rs=INT_MIN;
        for(char c:s){
            if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                st.pop();
                rs=max<int>(rs,st.size()+1);
            }
        }
        if(rs==INT_MIN) return 0;
        return rs;
    }
};