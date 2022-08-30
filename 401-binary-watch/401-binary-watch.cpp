class Solution {
public:
    int count_set_bits(int n)
    {
        int cnt =0;
        
        while(n)
        {
            cnt += n&1;
            n >>= 1;
            
        }
        return cnt;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        
        vector<string>ans;
        vector<int>bits(60);  // for storing count of set bits from 0-59
        for(int i=0;i<60;i++)
        {
            bits[i] = count_set_bits(i);
        }
        
        string temp;
        
        for(int i=0;i<12;i++)
        {
            int bits_left = turnedOn - bits[i];
            if(bits_left <0)
                continue;
            
            for(int j=0;j<60;j++)
            {
                temp = "";
                if(count_set_bits(j) == bits_left)
                {
                    string hours = to_string(i);
                    string minutes = j>9 ? to_string(j) : "0"+to_string(j);
                    
                    temp = hours + ":" + minutes;
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};