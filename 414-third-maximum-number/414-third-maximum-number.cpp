class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int>pq;
        for(auto num:nums)
        {
            pq.push(num);
        }
        int ans = INT_MIN;
        int cnt =0;
        int mx = pq.top();
        while(!pq.empty())
        {
            if(ans!=pq.top())
                cnt++;
            ans = pq.top();
            pq.pop();
            if(cnt==3)
                break;
        }
        if(cnt<3)
            return mx;
        return ans;
    }
};