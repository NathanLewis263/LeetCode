class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int size = costs.size();
        priority_queue<int, vector<int>, greater<int>> head;
        priority_queue<int, vector<int>, greater<int>> tail;

        long long cost = 0;
        int left , right; //left and right pointer

        for (left = 0;left < candidates && left < size; left++){ //add candidates from the left (start)
            head.push(costs[left]);
        }
        for (right = size - 1;right >= size - candidates && right >= left; right--){ //add candidates from the right (end)
            tail.push(costs[right]);
        }

        while (k--){
            if (tail.empty() || (!head.empty() && head.top() <= tail.top())){ 
                cost += head.top();
                head.pop();
                if (left <= right){
                    head.push(costs[left]);
                    left++;
                }
            } else {
                cost += tail.top();
                tail.pop();
                if (right>=left){
                    tail.push(costs[right]);
                    right--;
                }
            }
        }
        return cost;
    }
};