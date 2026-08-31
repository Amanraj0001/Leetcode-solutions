class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(vector<int>& nums, int i, int prev, int chk) {
        int n = nums.size();

        if (i >= n)
            return 0;

        int p = prev + 1;

        if (dp[i][p][chk] != -1)
            return dp[i][p][chk];

        int take = 0;

        if (chk == 1) {
            if (nums[i] > prev) {
                take = 1 + solve(nums, i + 1, nums[i], 0);
            }
        } else {
            if (nums[i] < prev) {
                take = 1 + solve(nums, i + 1, nums[i], 1);
            }
        }

        int skip = solve(nums, i + 1, prev, chk);

        return dp[i][p][chk] = max(take, skip);
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();

        if (n == 0)
            return 0;

        dp.assign(n, vector<vector<int>>(1002, vector<int>(2, -1)));

        int ans1 = 1 + solve(nums, 1, nums[0], 0);
        int ans2 = 1 + solve(nums, 1, nums[0], 1);

        return max(ans1, ans2);
    }
};