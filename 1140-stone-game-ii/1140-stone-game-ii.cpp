class Solution {
public:
    int solve(vector<int>& piles, vector<vector<vector<int>>>& dp,
              int m, int person, int i) {

        int n = piles.size();

        if(i >= n) return 0;

        if(dp[i][m][person] != -1)
            return dp[i][m][person];

        int ans;

        if(person == 1) {  // Alice
            ans = 0;
            int sum = 0;

            for(int j = i; j < min(n, i + 2 * m); j++) {
                sum += piles[j];

                ans = max(ans,
                    sum + solve(piles, dp,
                                max(m, j - i + 1),
                                0,
                                j + 1));
            }
        }
        else {  // Bob
            ans = INT_MAX;
            int sum = 0;

            for(int j = i; j < min(n, i + 2 * m); j++) {
                sum += piles[j];

                ans = min(ans,
                    solve(piles, dp,
                          max(m, j - i + 1),
                          1,
                          j + 1));
            }
        }

        return dp[i][m][person] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(n + 1,
                vector<int>(2, -1))
        );

        return solve(piles, dp, 1, 1, 0);
    }
};