/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL) return {-1,-1};
        vector<int>crtp;
        ListNode* lft=head;
        ListNode* cpt=head->next;
        ListNode* rgt=cpt->next;
        int cnt=2;
        while(rgt!=NULL){
            if(((cpt->val)<(rgt->val) && (cpt->val)<(lft->val)) || ((cpt->val)>(rgt->val) && (cpt->val)>(lft->val))){
                crtp.push_back(cnt);
            }
            lft=lft->next;
            cpt=cpt->next;
            rgt=rgt->next;
            cnt++;
        }
        int n=crtp.size();
        if(n<=1) return {-1,-1};
        if(n==2){
            return {crtp[1]-crtp[0],crtp[1]-crtp[0]};
        }
        else{
            int mn=INT_MAX;
            for(int i=0;i<n-1;i++){
                mn=min(mn,crtp[i+1]-crtp[i]);
            }
            return {mn,crtp[n-1]-crtp[0]};
        }
    }
};