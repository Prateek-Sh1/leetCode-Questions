class Solution {
public:
    int minPartitions(string n) {
        int mx=INT_MIN;
        for(char x:n){
            mx=max(mx,x-'0');
        }
        return mx;
    }

};