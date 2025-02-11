class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int size = costs.size();
        priority_queue<int, vector<int>, greater<int>> head;
        priority_queue<int, vector<int>, greater<int>> tail;

        //left and right pointer
        int left = 0;
        int right = size-1; 
        long long cost = 0;

        while (k--){
            while (head.size() < candidates && left <= right){  //add candidates from the left (start)
                head.push(costs[left++]);
            }
            while (tail.size() < candidates && right >= left){  //add candidates from the right (end)
                tail.push(costs[right--]);
            }
            if (tail.empty() || (!head.empty() && head.top() <= tail.top())){ 
                cost += head.top();
                head.pop();
            } else {
                cost += tail.top();
                tail.pop();
            }
        }
        return cost;
    }
};