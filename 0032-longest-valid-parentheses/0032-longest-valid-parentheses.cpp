class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        stack<int>st;
        vector<int>vc;
        int rs=INT_MIN;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')' && st.size()==0){
                vc.push_back(i);
            }
            else if(!st.empty() && s[i]==')' && s[st.top()]=='('){
                st.pop();
            }
        }
        while(!st.empty() && s[st.top()]=='('){
            vc.push_back(st.top());
            st.pop();
        }
        if(vc.empty()) return n;
        sort(vc.begin(),vc.end());
        rs=vc[0]-0;
        for(int i=0;i<vc.size()-1;i++){
            rs=max(rs,vc[i+1]-vc[i]-1);
        }
        int end=n-vc[vc.size()-1]-1;
        rs=max(rs,end);
        return rs;
    }
};