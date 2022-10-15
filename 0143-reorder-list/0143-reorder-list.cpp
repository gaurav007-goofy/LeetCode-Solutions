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
        ListNode* curr = head,*prev = NULL, *nxt = NULL;
        
        while(curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt; 
        }
        
        return prev;
    }
    void reorderList(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* newHead = reverse(slow->next);
        slow->next = NULL;
        
        ListNode* curr1 = head, *curr2 = newHead;
        
        ListNode* nxt1=NULL, *nxt2 = NULL;
        while(curr1 && curr2)
        {
            nxt1 = curr1->next;
            nxt2 = curr2->next;
            
            curr1->next = curr2;
            curr2->next = nxt1;
            
            curr1 = nxt1;
            curr2 = nxt2;
        }
        
        
    }
};