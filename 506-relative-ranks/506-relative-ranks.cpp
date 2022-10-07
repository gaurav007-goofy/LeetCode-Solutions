class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<int>v = score;
        
        int n  =score.size();
        
        sort(score.begin(),score.end());
        unordered_map<int,string>mp;
        
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
                mp[score[i]] = "Gold Medal";
            else if(i==n-2)
                mp[score[i]] = "Silver Medal";
            else if(i==n-3)
                mp[score[i]] = "Bronze Medal";
            else
                mp[score[i]] = to_string(n-i);
        }
        
        vector<string>ans;
        
        for(int i=0;i<n;i++)
        {
            ans.push_back(mp[v[i]]);
        }
        
        return ans;
    }
};