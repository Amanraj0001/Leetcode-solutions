class Solution {
public:
    int solve(vector<int>& nums, int target, int i, int sum,
              vector<vector<int>>& dp, int offset) {

        if(i == nums.size())
            return sum == target;

        if(dp[i][sum + offset] != -1)
            return dp[i][sum + offset];

        int pos = solve(nums, target, i + 1,
                        sum + nums[i], dp, offset);

        int neg = solve(nums, target, i + 1,
                        sum - nums[i], dp, offset);

        return dp[i][sum + offset] = pos + neg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);

        int offset = total;

        vector<vector<int>> dp(
            n,
            vector<int>(2 * total + 1, -1)
        );

        return solve(nums, target, 0, 0, dp, offset);
    }
};