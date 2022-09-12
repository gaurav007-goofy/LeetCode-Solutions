class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        //perimeter of square is 4 
        //if 2 squares are joined perimeter becomes -> 6 why? becuase 2 edges are common and we need to subtract these 2 edges
        //so perimeter is 4*number of squres - 2*repeating edges
        
        int count = 0; //number of squares
        int repeat=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                    if(i!=0 && grid[i-1][j] == 1)repeat++;  //check for up
                    if(j!=0 && grid[i][j-1]==1)repeat++;  //check for left
                    //we only need to check these 2 cases as when the loop goes on all the sides will be covered for all squares -> take one example and see for yourself
                }
            }
        }
        
        return 4*count - (2*repeat);
    }
};