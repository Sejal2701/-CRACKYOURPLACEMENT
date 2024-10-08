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
        int carry=0;
        ListNode* head=NULL;
        ListNode* traverse=NULL;
        while(l1!=NULL or l2!=NULL)
        {
            int sum=0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            
            int val=sum%10;
            ListNode* curr=new ListNode(val);
            carry=int(sum/10);
            if(head==NULL)
            {
                head=curr;
                traverse=curr;
            }
            else
            {
                traverse->next=curr;
                traverse=traverse->next;
            }
            
        }
        if(carry==1)
        {
            ListNode* temp=new ListNode(1);
            traverse->next=temp;
        }
        return head;
    }
};