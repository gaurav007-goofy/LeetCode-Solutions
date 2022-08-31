class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        int n = nums.size();
        
        stack<int> st;
        map<int, int> m;
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() && st.top()< nums[i])
                st.pop();
            if(st.empty())
            {
                st.push(nums[i]);
                m[nums[i]] = -1;
            }
            else
            {
                m[nums[i]] = st.top();
                st.push(nums[i]);
            }
        }
        vector<int>ans;
        for(int i=0;i<findNums.size();i++)
        {
            if(m.find(findNums[i])!=m.end())
                ans.push_back(m[findNums[i]]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};