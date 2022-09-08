class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1] > 0)   // to make the element at index = nums[i]-1 to -ive
            {
                nums[abs(nums[i])-1] = -1*nums[abs(nums[i])-1];
            }
        }
        
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)         // push those indices whose value is +ive
                res.push_back(i+1);
        }
        return res;
    }
};