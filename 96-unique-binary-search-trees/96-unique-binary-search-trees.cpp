class Solution {
public:
    int solve(vector<int> &dp,int n)
    {
        if(n==0 || n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        
        int ways =0;
        
        for(int i=1;i<=n;i++)
        {
            ways += solve(dp,i-1) * solve(dp,n-i);
        }
        
        return dp[n]=ways;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        
        return solve(dp,n);
    }
};