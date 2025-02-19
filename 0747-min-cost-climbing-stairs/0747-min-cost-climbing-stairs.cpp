class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int takeTwoSteps = 0, takeOneStep = 0;  // Base cases
        
        for (int i = 2; i <= cost.size(); i++) {
            int curr = min(takeOneStep + cost[i-1], takeTwoSteps + cost[i-2]);
            takeTwoSteps = takeOneStep;  // Move forward
            takeOneStep = curr;
        }
        
        return takeOneStep;   
    }
};