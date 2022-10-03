class Solution {
public:
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