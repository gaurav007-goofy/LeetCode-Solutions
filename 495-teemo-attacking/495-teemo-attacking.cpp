class Solution {
public:
    int findPoisonedDuration(vector<int>& time, int duration) {
        
        int total = 0;
        
        for(int i=0;i<time.size()-1;i++)
        {
            
            if(time[i]+duration > time[i+1])
            {
                total += time[i+1] - time[i];
            }
            else
                total += duration;
        }
        return total + duration;
    }
};