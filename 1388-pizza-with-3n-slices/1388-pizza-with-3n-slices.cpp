class Solution {
public:
    int solve(vector<int>& nums, int i, int end, int n,
              vector<vector<int>>& dp) {

        if(i > end || n == 0)
            return 0;

        if(dp[i][n] != -1)
            return dp[i][n];

        int skip = solve(nums, i + 1, end, n, dp);

        int take = nums[i] + solve(nums, i + 2, end, n - 1, dp);

        return dp[i][n] = max(take, skip);
    }

    int maxSizeSlices(vector<int>& nums) {

        int n = nums.size() / 3;
        int size = nums.size();

        vector<vector<int>> dp1(size, vector<int>(n + 1, -1));
        vector<vector<int>> dp2(size, vector<int>(n + 1, -1));

        int case1 = solve(nums, 0, size - 2, n, dp1);

        int case2 = solve(nums, 1, size - 1, n, dp2);

        return max(case1, case2);
    }
};