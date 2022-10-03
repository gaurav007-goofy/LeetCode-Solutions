class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        
        vector<string>res;
        
        int c1 = 0,c2 = 0,c3 =0;
        for(int i=0;i<words.size();i++)
        {
            string str = words[i];
            for(int j=0;j<str.size();j++)
            {
                char ch = tolower(str[j]);
                if(s1.find(ch)!=string ::npos)
                    c1++;
                else if(s2.find(ch)!=string::npos)
                    c2++;
                else 
                    c3++;
            }
            if((c1>0 && c2==0 && c3==0)||(c2>0 && c1==0 &&c3==0)||(c3>0&&c1==0&&c2==0))
                res.push_back(str);
            c1=0;
            c2=0;
            c3=0;
        }
        
        return res;
    }
};