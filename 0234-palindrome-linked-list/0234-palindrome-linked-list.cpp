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
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode* temp=head;
        stack<int> s;
        while(temp!=NULL)
        {
            s.push(temp->val);
            temp=temp->next;
        }
        
        temp=head;
        while(temp!=NULL and !s.empty())
        {
            if(temp->val!=s.top())
            {
                return false;
            }
            temp=temp->next;
            s.pop();
        }
        if(!s.empty())
        {return false;}
        
        if(temp!=NULL)
        {
            return false;
        }
        return true;
    }
};