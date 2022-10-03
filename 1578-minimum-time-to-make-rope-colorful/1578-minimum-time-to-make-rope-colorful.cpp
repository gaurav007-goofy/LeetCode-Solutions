class Solution {
public:
    // dp solution
//     int solve(string &colors,vector<int> &time,int i,int n,int col,vector<vector<int>> &dp){
//         if (i>=n){
//             return 0;
//         }
//         if (dp[i][col]!=-1){
//             return dp[i][col];
//         }
//         if (col==colors[i]-'a'){
//             return dp[i][col] = time[i]+solve(colors,time,i+1,n,col,dp);
//         }
//         return dp[i][col] = min(solve(colors,time,i+1,n,colors[i]-             'a',dp),time[i]+solve(colors,time,i+1,n,col,dp));
//     }
    
//     int minCost(string colors, vector<int>& neededTime) {
//         int i = 0;
//         int n = colors.size();
//         vector<vector<int>> dp(n,vector<int> (27,-1));
//         return solve(colors,neededTime,i,n,26,dp);
        
//     }
    
    int minCost(string color, vector<int>& time) {
        char prevCh = '*';
        int costp = 0;
        
        int ans =0;
        for(int i=0;i<color.size();i++)
        {
            if(color[i]==prevCh)
            {
                if(costp < time[i])
                {
                    ans += costp;
                    costp= time[i];
                }
                else
                {
                    ans += time[i];
                }
            }
            else
            {
                prevCh = color[i];
                costp = time[i];
            }
        }
        
        return ans;
    }
};