class Solution {
public:
    int solve(vector<int>& stones, int i, int sum,
              int total, vector<vector<int>>& dp) {

        if (i == stones.size()) {
            return abs(total - 2 * sum);
        }

        if (dp[i][sum] != -1)
            return dp[i][sum];

        int take = solve(stones, i + 1,
                         sum + stones[i], total, dp);

        int notTake = solve(stones, i + 1,
                            sum, total, dp);

        return dp[i][sum] = min(take, notTake);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(), stones.end(), 0);

        vector<vector<int>> dp(
            stones.size(),
            vector<int>(total + 1, -1)
        );

        return solve(stones, 0, 0, total, dp);
    }
};