class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int cnt = 0;    // to count the no. of zeroes from lsb
        
        while(left!=right)
        {
            left >>= 1;
            right >>= 1;
            cnt++;
        }
        
        return left<<cnt;   // left shift the left by cnt times
    }
};