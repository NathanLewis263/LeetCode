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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i=0;i<left-1;i++){
            prev = curr;
            curr = curr->next;
        }
        ListNode* beforeLeft = prev;  
        ListNode* tail = curr;
        ListNode* nextNode = nullptr;
        
        for (int i = 0;i<=right-left;i++) {
            ListNode* nextNode = curr->next; // first, make sure we don't lose the next node
            curr->next = prev;               // reverse the direction of the pointer
            prev = curr;                     // set the current node to prev for the next node
            curr = nextNode;                 // move on
        }
        
        // Connect reversed part
        if (beforeLeft) {
            beforeLeft->next = prev;  // Connect first part to reversed part
        } else {
            head = prev;  // If left == 1, update head
        }
        
        tail->next = curr;  // Connect reversed part to remaining list

         return head;    
    }
};