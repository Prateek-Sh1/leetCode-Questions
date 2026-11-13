class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st;
        for(char c:brokenLetters){
            st.insert(c);
        }
        int cnt=0;
        bool t=false;
        for(char c:text){
            if(st.find(c)!=st.end()){
                t=true;
                continue;
            }
            if(c==' ' && t){
                t=false;
            }
            else if(c==' ' && !t){
                cnt++;
            }
        }
        if(!t) cnt++;
        return cnt;
    }
};