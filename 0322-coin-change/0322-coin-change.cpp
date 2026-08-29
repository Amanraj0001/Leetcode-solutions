class Solution {
public:
    int solve(vector<int>&coins,int amount,vector<vector<int>>&dp,int i){
      if(amount==0)return 0;
      if(i>=coins.size() || amount<0)return 1e9;
      
       
     if(dp[i][amount]!=-1)return dp[i][amount];

      int take=1+solve(coins,amount-coins[i],dp,i);
      int ntake=solve(coins,amount,dp,i+1);
      return dp[i][amount]=min(take,ntake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));

        int ans=solve(coins,amount,dp,0);
         return ans >= 1e9 ? -1 : ans;
    }
};