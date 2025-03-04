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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head; 
        
        ListNode* dummy = new ListNode(0, head); // Dummy node to handle edge cases
        ListNode* prev = dummy;
        ListNode* current = head;

        while (current) {
            if (current->next && current->val == current->next->val) {
                while (current->next && current->val == current->next->val) {
                    current = current->next;
                }
                prev->next = current->next;
            } else {
                // Move prev only if no duplicate was found
                prev = prev->next;
            }

            current = current->next;
        }

        return dummy->next; 
    }
};