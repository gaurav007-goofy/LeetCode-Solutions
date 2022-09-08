class Solution {
public:
    int arrangeCoins(int n) {
        long int count =0;
        int i=0;
        while(count<n)
        {
            i++;
            count += i;
        }
        if(count==n)
            return i;
        return i-1;
    }
};