class Solution {
public:
    int solve(vector<vector<int>>& d, vector<vector<int>>& dp, int i, int j) {
        int n = d.size();
        int m = d[0].size();

        if (i == n - 1 && j == m - 1) {
            return max(1, 1 - d[i][j]);
        }

        if (i >= n || j >= m)
            return INT_MAX;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solve(d, dp, i, j + 1);
        int down = solve(d, dp, i + 1, j);

        int next = min(right, down);

        return dp[i][j] = max(1, next - d[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& d) {
        int n = d.size();
        int m = d[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(d, dp, 0, 0);
    }
};