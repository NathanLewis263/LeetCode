class Solution {
public:
    unordered_map<int, int> dp = {
        {0, 0},
        {1, 1},
        {2, 1}
    };
    int tribonacci(int n) {
        if (dp.count(n)) {
            return dp[n];
        }
        int answer = tribonacci(n-3) + tribonacci(n-2) + tribonacci(n-1);
        dp[n] = answer;
        return answer;
    }
};