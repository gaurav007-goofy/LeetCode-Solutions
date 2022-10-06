class Solution {
public:
//     Basic Idea
//     We are given an array where every integer, except one, occurs thrice. Therefore, at every bit position, there     is an odd bit while all other bits occur as multiples of 3.
//     The following example will make this clearer.

//     Take the input array : [2, 2, 2, 4, 4, 4, 5]

//     A B C
//     0 1 0 ~ 2
//     0 1 0
//     0 1 0
//     1 0 0 ~ 4
//     1 0 0
//     1 0 0
//     1 0 1 ~ 5

//     At bit position A : 3 occurences of '0' + 3 occurences of '1' + 1 occurence of '1'
//     At bit position B : 3 occurences of '1' + 3 occurences of '0' + 1 occurence of '0'
//     At bit position C : 6 occurences of '0' + 1 occurence of '1'

//     Therefore, at each bit position, we have bits that occur in multiples of 3, and one lone bit.
//     So, if we add up the bits at a given position as sum, and find the remainder when sum is divided by 3, we get     the left over bit.

//     For the bits at A, sum = 4 : 4 % 3 = 1
//     For the bits at B, sum = 3 : 3 % 3 = 0
//     For the bits at C, sum = 1 : 1 % 3 = 1
    
    int singleNumber(vector<int>& nums) {
        
        long ans =0;
        int p = 0;
        
        for(int i=0;i<32;i++)
        {
            int sum = 0;
            for(int j=0;j<nums.size();j++)
            {
                int bit = nums[j] & 1;
                sum += bit;
                
                nums[j] >>= 1;
            }
            sum = sum%3;
            
            ans += sum * pow(2,p);
            p++;
        }
        
        return ans;
        
    }
};