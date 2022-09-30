class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        
        string res = "";
        
        string temp = "";
        for(int i=s.size()-1;i>=0;i--)
        {
            if(temp.size()<k && s[i]!='-')
            {
                temp += toupper(s[i]);
            }
            else if(temp.size()>=k)
            {
                res += temp;
                res += '-';
                temp = "";
                if(s[i]!='-')
                    temp += toupper(s[i]);
            }
            //cout<<temp<<"\n";
        }
      
        res += temp;
        if(res.size()>0 && res[res.size()-1]=='-')
            res.pop_back();
        reverse(res.begin(),res.end());
        
        return res;
    }
};