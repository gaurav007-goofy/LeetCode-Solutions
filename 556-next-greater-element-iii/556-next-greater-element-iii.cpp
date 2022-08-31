class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(str.begin(),str.end());
        
        long long neww = stoll(str);
        if(neww > INT_MAX)
            return -1;
        if(neww > n)
            return neww;
        return -1;
    }
};