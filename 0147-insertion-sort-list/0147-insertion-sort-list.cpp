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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr) return nullptr;
    
        
        for(ListNode* curr = head; curr != nullptr; curr = curr->next){
            for(ListNode* prev = head; prev != curr; prev = prev->next){
                if(curr->val < prev->val){
                    swap(curr->val,prev->val);
                }
            }
        }
        return head;
    }
};