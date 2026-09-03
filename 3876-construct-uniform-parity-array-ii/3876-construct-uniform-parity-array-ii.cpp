class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int cE=0;
        int cO=0;
        int n=nums1.size();
        int mno=0;
        int mne=0;
        for(int i:nums1){
            if(i%2==0){
                mne=i;
            }
            else{
                mno=i;
            }
        }
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(mno>nums1[i] && nums1[i]%2!=0){
                mno=nums1[i];
                x=i;
            }
            else if(mne>nums1[i] && nums1[i]%2==0){
                mne=nums1[i];
                y=i;
            }
        }
        // cout<<mno<<" "<<mne<<endl;
        bool od=true;
        bool ev=true;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0 && ((nums1[i]-mno)<1 || (nums1[i]-mno)%2==0)){
                od=false;
            }
            else if(nums1[i]%2!=0 && ((nums1[i]-mne)%2!=0 || (nums1[i]-mne)<1)){
                ev=false;
            }

            if(nums1[i]%2==0) cE++;
            else cO++;
        }
        if(cE==n || cO==n || od || ev) return true;
        return false;
    }
};