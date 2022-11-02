class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        // solution using bitset
        int n = candyType.size();
        bitset<200001> hash;
        for (int i: candyType)
           hash.set(i + 100000);
        int count = hash.count();
        
        return min(count, n / 2);
        
        
//         int canEat = candyType.size()/2;
        
//         unordered_set<int>st;
//         for(auto type:candyType)
//         {
//             st.insert(type);
//         }
        
//         return canEat<st.size() ? canEat : st.size();
    }
};