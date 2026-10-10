class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        vector<long long>v(100001,0);
        for(int i=0;i<n;i++){
            int w=abs(nums1[i]-nums2[i]);
            v[w]++;
        }
        long long k=k1+k2;
        for(int i=v.size()-1;i>0;i--){
            if(v[i]!=0){
                long long r=v[i];
                long long xnt=min(k,r);
                v[i]=(v[i]-xnt);
                v[i-1]=(v[i-1]+xnt);
                k-=xnt;                
            }
            if(k==0) break;
        }

        long long ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]!=0){
                ans+=((1LL*i*i)*v[i]);
            }
        }
        return ans;
    }
};