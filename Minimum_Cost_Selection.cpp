class Solution {
  public:
    int minCost(vector<vector<int>>& mat) {
        int n = mat.size();
            if (n == 0) return 0;

            vector<int> dp(3);
            dp[0] = mat[0][0];
            dp[1] = mat[0][1];
            dp[2] = mat[0][2];

            for (int i = 1; i < n; i++) {
                vector<int> newDp(3);
                newDp[0] = mat[i][0] + min(dp[1], dp[2]);
                newDp[1] = mat[i][1] + min(dp[0], dp[2]);
                newDp[2] = mat[i][2] + min(dp[0], dp[1]);
                dp = newDp;
            }

            return min({dp[0], dp[1], dp[2]});
        
    }
};
