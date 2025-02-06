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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode* odd = head;
        ListNode* oddTail = odd;
        ListNode* evenHead = head->next;
        ListNode* evenTail = evenHead;
        odd = evenHead->next;
        int i = 0;
        while (odd){
            if (i % 2 == 0) {  // Odd-indexed node
                oddTail->next = odd;
                oddTail = oddTail->next;
            } else {           // Even-indexed node
                evenTail->next = odd;
                evenTail = evenTail->next;
            }
            odd = odd->next;
            i++;
        }
        oddTail->next = evenHead;
        evenTail->next = nullptr;

        return head;
        }
};