class Solution {
public:
    int minInsertions(string s) {
        int n= s.length();
        int b=0;
        stack<char>st;
        for(int j=0;j<n;j++){
            if(s[j]=='('){
                st.push(s[j]);
            }
            else if(!st.empty() && s[j]==')'){
                if(j+1<n && s[j+1]==')'){
                    st.pop();
                    j=j+1;
                }
                else{
                    st.pop();
                    b++;
                }
            }
            else if(!st.empty() && s[j]==')'){
                if(j+1<n && s[j+1]=='('){
                    st.pop();
                    b++;
                }
            }
            else if(st.empty() && s[j]==')'){
                if(j+1<n && s[j+1]==')'){
                    b++;
                    j++;
                }
                else{
                    b+=2;
                }
            }
            else if(st.empty() && s[j]==')'){
                if(j+1<n && s[j+1]!=')'){
                    b+=2;
                }
            }
        }

        while(!st.empty()){
            b+=2;
            st.pop();
        }
        return b;   
    }
};