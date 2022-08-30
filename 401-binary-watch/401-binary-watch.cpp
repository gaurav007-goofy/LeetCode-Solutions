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
        string temp;
        
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<60;j++)
            {
                temp = "";
                if(count_set_bits(i)+count_set_bits(j) == turnedOn)
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