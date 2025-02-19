class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        if (n <= 2) {
            return n;
        }
        long fp = 1, pc = 1, fc = 2;  // Base cases

        for (int i = 3; i <= n; i++) {
            long curr = (fc +  fp + 2 * pc) % MOD;
            pc = (pc + fp) % MOD;
            fp = fc;
            fc = curr;
        }


        return fc;  // dp[n]
    }
};