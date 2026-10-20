class Solution {
public:
    int calculate(string s) {
        stack<int>s1;
        int n=s.length();
        stack<char>s2;
        int i=0;
        int nt=0;
        for(int j=n-1;j>=0;j--){
            if(s[j]==' ') continue;
            if((s[j]-'0')>=0 && (s[j]-'0')<=9 ){
                i+=(s[j]-'0')*pow(10,nt);
                nt++;
            }
            else{
                s1.push(i);
                if(s1.size()>1){
                    while(!s2.empty() && (s2.top()=='/' || s2.top()=='*') && (s[j]!='/' && s[j]!='*')){
                        int i1=s1.top();
                        s1.pop();
                        int i2=s1.top();
                        s1.pop();
                        if(s2.top()=='*') s1.push(i1*i2);
                        else if(s2.top()=='/'){
                            if(i2==0){
                                s1.push(0);
                            }else s1.push(i1/i2);
                        } 
                        s2.pop();
                    }
                }
                i=0;
                nt=0;
                s2.push(s[j]);
            }
            
        }
        s1.push(i);
        while(s1.size()>1){
            int x1=s1.top();
            s1.pop();
            int x2=s1.top();
            s1.pop();
            if(s2.top()=='+'){
                s1.push(x1+x2);
            }
            else if(s2.top()=='-'){
                s1.push(x1-x2);
            }
            else if(s2.top()=='*'){
                s1.push(x1*x2);
            }
            else if(s2.top()=='/'){
                if(x2==0) s1.push(0);
                else s1.push(x1/x2);
            }
            s2.pop();
        }

        return s1.top();
    }
};