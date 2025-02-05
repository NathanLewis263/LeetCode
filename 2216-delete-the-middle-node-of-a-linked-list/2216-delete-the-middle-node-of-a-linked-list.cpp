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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return nullptr;
        }
        int count = 0;
        ListNode* current = head;
        while (current != nullptr){
            count++;
            current = current->next;
        }
        int mid = count/2;
        current = head;
        for (int i = 0; i < mid - 1; i++) {
            current = current->next;
        }
        current->next = current->next->next;
        return head;
    }
};