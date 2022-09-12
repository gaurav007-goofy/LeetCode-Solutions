class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt =0;
        
        while(x && y)
        {
            int a = x&1;
            int b = y&1;
            if(a!=b)
                cnt++;
            x >>=1;
            y >>=1;
        }
        while(x)
        {
            if(x&1==1)
                cnt++;
            x >>=1;
        }
        while(y)
        {
            if(y&1==1)
                cnt++;
            y >>=1;
        }
        return cnt;
    }
};