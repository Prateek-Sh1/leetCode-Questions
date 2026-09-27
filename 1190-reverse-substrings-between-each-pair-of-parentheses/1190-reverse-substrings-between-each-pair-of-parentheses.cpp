class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        vector<int>frt;
        vector<int>match(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(s[i]=='(') frt.push_back(i);
        }
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int id=st.top();
                st.pop();

                match[id]=i;
                match[i]=id;
            }
        }
        int x=frt.size();
        for(int k=x-1;k>=0;k--){
            int f=frt[k];
            int b=match[f];
            reverse(s.begin()+f+1,s.begin()+b);
        }
        string res="";
        for(char c:s){
            if(c==')' || c=='(') continue;
            else{
                res+=c;
            }
        }
        return res;

    }
};