class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find the front of non-increasing.
        int i = nums.size() - 2;
        
        for(;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
                break;
        }
        
        
        if(i >= 0){
            //scan the first bigger than nums[i]
            for(int j = nums.size() - 1; j > i; j--){
                if(nums[j] > nums[i]){
                    swap(nums[j], nums[i]);
                    break;
                }
            }
        }
        // after swap, the nums[i+1]~nums[end] is must be non-increasing.
        std::reverse(nums.begin() + i + 1, nums.end());
        
    }
};