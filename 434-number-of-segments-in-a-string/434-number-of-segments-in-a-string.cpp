class Solution {
public:
    int countSegments(string s) {
        stringstream ss(s);
        
        int cnt =0;
        string word;
        while(ss>>word)
        {
            cnt++;
        }
        return cnt;
    }
};