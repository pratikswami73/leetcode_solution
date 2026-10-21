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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry =0;
        ListNode*temp1=l1;
        ListNode*temp2=l2;
        ListNode*prev=nullptr;

        while(temp1!=nullptr && temp2!=nullptr){
            temp1->val=temp1->val+temp2->val+carry;
            if(temp1->val>=10){
                temp1->val-=10;
                carry=1;
            }
            else{
                carry=0;
            }
            prev=temp1;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        while(temp1!=nullptr){
            temp1->val+=carry;
            if(temp1->val>=10){
                temp1->val-=10;
                carry=1;
            }
            else{
                carry=0;
            }
            prev=temp1;
            temp1=temp1->next;
        }

        while(temp2!=nullptr){
            ListNode* newnode=new ListNode;
            newnode->val=temp2->val+carry;
            prev->next=newnode;
            if(newnode->val>=10){
                newnode->val-=10;
                carry=1;
            }
            else{
                carry=0;
            }
            prev=prev->next;
           // temp1=temp1->next;
            temp2=temp2->next;
        }
        if(carry==1){
            ListNode* newnode=new ListNode;
            newnode->val=1;
        prev->next=newnode;
        }
        return l1;
    }
};