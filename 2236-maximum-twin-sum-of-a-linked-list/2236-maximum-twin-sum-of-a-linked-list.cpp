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
    int pairSum(ListNode* head) {
        // vector<int> numbers;
        // ListNode* tmp = head;
        // while (tmp){
        //     numbers.push_back(tmp->val);
        //     tmp = tmp->next;
        // }
        // int n = numbers.size();
        // int maxNum = numbers[0] + numbers[n-1-0];
        // for (int i = 1;i<n/2;i++){
        //     maxNum = max(maxNum,numbers[i] + numbers[n-1-i]);
        // }
        // return maxNum;

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next){ //middle of linkedList using fast-Slow
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* nextNode = nullptr;
        ListNode* prev = nullptr;
        //reverse the second half of the linkedlist
        while (slow) {
            nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        int maxNum = 0;
        ListNode* start = head;
        while (prev){
            maxNum = max(maxNum, start->val + prev->val);
            prev = prev->next;
            start = start->next;
        }
        
        return maxNum;
    }
};