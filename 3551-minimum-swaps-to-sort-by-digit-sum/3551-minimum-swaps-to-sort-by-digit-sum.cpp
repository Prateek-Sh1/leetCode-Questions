class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>tmp;
        unordered_map<int,int>mp;
        unordered_map<int,int>mp2;
        for(int i:nums){
            int z=i;
            int s=0;
            while(i>0){
                int x=i%10;
                s+=x;
                i/=10;
            }
            tmp.push_back({s,z});
        }
        sort(tmp.begin(),tmp.end(),[](const pair<int,int> &a ,const pair<int,int> &b){
                if(a.first!=b.first){
                    return a.first<b.first;
                }
                return a.second<b.second;
        });
        vector<int>ls;
        for(int i=0;i<n;i++){
            ls.push_back(tmp[i].second);
        }
        for(int i=0;i<n;i++){
            mp[ls[i]]=i;
        }        
        for(int i=0;i<n;i++){
            mp2[i]=mp[nums[i]];
        } 
        vector<bool>v(n,false);
        int nt=0;
        for(int i=0;i<n;i++){
            if(v[i] || mp2[i]==i) continue;
            int am=0;
            int j=i;
            while(!v[j]){
                v[j]=true;
                j=mp2[j];
                am++;
            }
            if(am>1){
                nt+=(am-1);
            }
        }
        return nt;
    }
};