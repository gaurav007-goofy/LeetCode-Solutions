class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mp;
        for(auto num:nums)
            mp[num]++;
        
        int res = 0;
        auto prev = mp.begin();
        
        
        for(auto it = mp.begin();it!=mp.end();it++)
        {
            if(abs(it->first - prev->first)==1)
            {
                res = max(res,it->second+prev->second);
            }
            prev = it;
        }
        
        return res;
    }
};