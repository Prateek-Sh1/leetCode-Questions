class Solution {
public:
    int minAddToMakeValid(string s) {
        int nt=0;
        // int tk=0;
        stack<char>st;
        for(char c:s){
            if(c=='('){
                st.push(c);
            }
            else if(!st.empty() && c==')' && st.top()=='('){
                st.pop();
            }
            else if(st.empty() && c==')'){
                nt++;
            }
        }
        while(!st.empty()){
            st.pop();
            nt++;
        }

        return nt;
    }
};