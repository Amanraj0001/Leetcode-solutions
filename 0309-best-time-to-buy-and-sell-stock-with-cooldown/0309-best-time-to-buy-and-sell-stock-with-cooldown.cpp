class Solution {
public:
    int solve(vector<int>&prices,vector<vector<int>> &dp,int i,int buy){
        int n=prices.size();
        if(i>=n)return 0;
        if(dp[i][buy]!=-1)return dp[i][buy];
        if(buy){
            int take= -prices[i]+solve(prices,dp,i+1,0);
            int ntake= solve(prices,dp,i+1,1);
            return dp[i][buy]=max(take,ntake);
        }else{
             int sell=prices[i]+solve(prices,dp,i+2,1);
            int nsell= solve(prices,dp,i+1,0);
            return dp[i][buy]=max(sell,nsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,dp,0,1);
    }
};