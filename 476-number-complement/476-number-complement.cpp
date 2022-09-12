class Solution {
public:
    int bin_to_deci(string str)
    {
        int ans =0;
        
        for(int i=0;i<str.size();i++)
        {
            if(str[i]=='1')
                ans += pow(2,i);
        }
        return ans;
    }
    int findComplement(int num) {
        string str = "";
        while(num)
        {
            int x = num&1;
            str += to_string(1-x);
            num >>=1;
        }
        
        //reverse(str.begin(),str.end());
       // cout<<str;
        int res= bin_to_deci(str);
        return res;
    }
};