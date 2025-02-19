class Solution {
public:
    void backtrack(int start, int k, int n, vector<int>& current, vector<vector<int>>& result) {
        // Base Case: If k elements are chosen and sum is n, add to result
        if (current.size() == k && n == 0) {
            result.push_back(current);
            return;
        } else if (n < 0 || current.size() == k) {
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > n) {
                break; // if i is greater than n (sum) then break
            }

            current.push_back(i); // Choose number
            backtrack(i + 1, k, n - i, current, result); // reduce n and explore other choices
            current.pop_back(); // Undo choice
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(1, k, n, current, result);
        return result;
    }
};