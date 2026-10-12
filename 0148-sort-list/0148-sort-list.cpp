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
    ListNode* mrg(ListNode*x1,ListNode* x2){
        ListNode ummy(-1);
        ListNode* tail=&ummy;

        while(x1!=NULL && x2!=NULL){
            if(x1->val<=x2->val){
                tail->next=x1;
                x1=x1->next;
            }
            else{
                tail->next=x2;
                x2=x2->next;
            }
            tail=tail->next;
        }
        if(x1!=NULL){
            tail->next=x1;
        }else{
            tail->next=x2;
        }
        
        return ummy.next;
    }
    ListNode* hlpr(ListNode* st){
        if(st->next==NULL){
            return st;
        }
        ListNode* sl=st;
        ListNode* fl=st->next;
        while(fl!=NULL && fl->next!=NULL && fl->next->next!=NULL){
            sl=sl->next;
            fl=fl->next->next;
        }
        fl=sl->next;
        sl->next=NULL;
        return mrg(hlpr(st),hlpr(fl));
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return NULL; 
        return hlpr(head);
    }
};