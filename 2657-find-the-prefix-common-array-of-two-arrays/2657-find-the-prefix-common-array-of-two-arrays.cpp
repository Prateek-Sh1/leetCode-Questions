class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>rs(n,0);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
           if(mp.find(A[i])==mp.end()){
                mp[A[i]]=1;
           }else{
            mp[A[i]]++;
           }
           if(mp.find(B[i])==mp.end()){
                mp[B[i]]=1;
           }else{
            mp[B[i]]++;
           }

           for(auto &it:mp){
            if(it.second==2) rs[i]++; 
           }      
        }
        return rs;

    }
};