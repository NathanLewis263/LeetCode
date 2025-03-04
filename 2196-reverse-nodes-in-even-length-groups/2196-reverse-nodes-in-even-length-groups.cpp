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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* prev = head; // Previous group's last node
        ListNode* curr = head->next; // Current node
        int groupSize = 2; // The first group is always 1 node long

        while (curr) {
            ListNode* temp = curr;
            int count = 0;
            for (int i = 0; i < groupSize && temp; i++) {
                count++;
                temp = temp->next;
            }
            if (count % 2 == 0) {
                ListNode* prevGroupEnd = prev;
                ListNode* start = curr;
                ListNode* nextNode = nullptr;
                ListNode* prevNode = nullptr;

                // Reverse the group
                for (int i = 0; i < count; i++) {
                    nextNode = curr->next;
                    curr->next = prevNode;
                    prevNode = curr;
                    curr = nextNode;
                }

                // Connect the reversed group
                prevGroupEnd->next = prevNode;
                start->next = curr;
                prev = start; // Update `prev` to be the last node of the reversed group
            } else {
                // Move `prev` forward normally
                for (int i = 0; i < count; i++) {
                    prev = curr;
                    curr = curr->next;
                }
            }

            groupSize++; // Increase group size for next iteration
        }

        return head;
        }
};