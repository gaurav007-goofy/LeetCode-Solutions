class Solution {
public:
    string convertToBase7(int num) {
        
        if(num==0)
            return "0";
        string ans = "";
        
        int sign = 1;
        if(num<0)
            sign = -1;
        
        num = abs(num);
        while(num)
        {
            int rem  =num%7;
            ans += to_string(rem);
            num /= 7;
        }
        if(sign==-1)
            ans += '-';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};