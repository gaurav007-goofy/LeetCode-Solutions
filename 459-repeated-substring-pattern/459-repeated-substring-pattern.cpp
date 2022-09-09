class Solution {
public:
    int compute(string s)
    {
        vector<int>lps(s.size());
        lps[0] = 0;
        int l =0;
        int i=1;
        while(i<s.size())
        {
            if(s[i]==s[l])
            {
                l++;
                lps[i] = l;
                i++;
            }
            else
            {
                if(l!=0)
                {
                    l = lps[l-1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return s.size()-lps[s.size()-1];
    }
    bool repeatedSubstringPattern(string s) {
        
        int n = s.size();
        set<char>st;
        for(auto ch:s)
            st.insert(ch);
        int distinct = st.size();
        
        
        int window_len = compute(s);
        string window = s.substr(0,window_len);
        cout<<window<<"\n";
        if(window_len==n)
            return false;
        int i;
        for(i=0;i<=n-window_len;i+=window_len)
        {
            string temp = s.substr(i,window_len);
            if(temp!=window)
                return false;
        }
        if(i<n)
            return false;
        return true;
    }
};