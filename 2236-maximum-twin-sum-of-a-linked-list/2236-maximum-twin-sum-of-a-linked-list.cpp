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
        vector<int> numbers;
        ListNode* tmp = head;
        while (tmp){
            numbers.push_back(tmp->val);
            tmp = tmp->next;
        }
        int n = numbers.size();
        int maxNum = numbers[0] + numbers[n-1-0];
        for (int i = 1;i<n;i++){
            maxNum = max(maxNum,numbers[i] + numbers[n-1-i]);
        }
        return maxNum;
    }
};