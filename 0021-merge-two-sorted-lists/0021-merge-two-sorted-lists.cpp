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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL and list2==NULL)
        {
            return NULL;
        }
        ListNode* head1=list1;
        ListNode* head2=list2;
        ListNode* temp=NULL;
        ListNode* newHead=NULL;
        while(head1!=NULL and head2!=NULL)
        {
            if(head1->val < head2->val)
            {
                if(temp==NULL)
                {
                    temp=head1;
                    newHead=head1;
                }
                else
                {
                    temp->next=head1;
                    temp=temp->next;
                }
                head1=head1->next;
            }
            else
            {
                if(temp==NULL)
                {
                    temp=head2;
                    newHead=head2;
                }
                else
                {
                    temp->next=head2;
                    temp=temp->next;
                }
                head2=head2->next;
            }
        }
        
        if(head1!=NULL)
        {
            if(temp==NULL)
            {
                newHead=head1;
                temp=head1;
            }
            else
            {
                temp->next=head1;
            }
        }
        if(head2!=NULL)
        {
            if(temp==NULL)
            {
                newHead=head2;
                temp=head2;
            }
            else
            {
                temp->next=head2;
            }
        }
        return newHead;
    }
};