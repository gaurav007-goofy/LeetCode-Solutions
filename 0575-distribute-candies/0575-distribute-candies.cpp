class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int canEat = candyType.size()/2;
        
        unordered_set<int>st;
        for(auto type:candyType)
        {
            st.insert(type);
        }
        
        return canEat<st.size() ? canEat : st.size();
    }
};