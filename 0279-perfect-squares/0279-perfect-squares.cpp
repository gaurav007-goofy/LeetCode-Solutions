class Solution {
public:
    // int fun(int idx, int target,vector<vector<long>> &dp)
    // {
    //     if(target==0) return 0;
    //     if(target-(idx*idx)<0) return 1e9;
    //     if(dp[idx][target]!=-1) return dp[idx][target];
    //     int take = 1e9;
    //     if(target-(idx*idx)>=0)
    //     {
    //         take = 1+ fun(idx,target-(idx*idx),dp);
    //     }
    //     int notTake = 0+ fun(idx+1,target,dp);
    //     return dp[idx][target] = min(take,notTake);
    // }
    
    int numSquares(int n) {
        // vector<vector<long>>dp(sqrt(n)+10,vector<long>(n+1,-1));
        // return fun(1,n,dp);
        
        // Tabulation method
        if(n<4) return n;
        vector<int>dp(n+1,INT_MAX);   // dp initialzed
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        
        for(int i=4;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
                
        return dp[n];
    } 
};