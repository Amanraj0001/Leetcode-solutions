class Solution {
public:
    int countVowelPermutation(int n) {
        if(n==1)return 5;
        int mod = 1e9 + 7;
        vector<vector<long long>>dp(n+1,vector<long long>(5,-1));
        dp[2][0]=3;
        dp[2][1]=2;
        dp[2][2]=2;
        dp[2][3]=1;
        dp[2][4]=2;
        for(int i=3;i<=n;i++){
          dp[i][0]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4])%mod;
          dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mod;
          dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;
          dp[i][3]=(dp[i-1][2])%mod;
          dp[i][4]=(dp[i-1][2]+dp[i-1][3])%mod;

        }
        int total=0;
        for(int i=0;i<5;i++){
           total=(total+dp[n][i])%mod;
        }
        return total;
    }
};