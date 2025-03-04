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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* second = head;
        ListNode* first = head;
        ListNode* temp = head;

        for (int i = 0;i<k-1;i++){
            temp = temp->next;
        }
        first = temp;
        while (temp->next) {
            temp = temp->next;
            second = second->next;
        }
        // `second` now points to the k-th node from the end

        // Swap values of `first` and `second`
        swap(first->val, second->val);

        return head;
    }
};