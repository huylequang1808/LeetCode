#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0) continue;
                
                int fromTop = (i > 0) ? grid[i-1][j] : INT_MAX;
                int fromLeft = (j > 0) ? grid[i][j-1] : INT_MAX;
                
                grid[i][j] += min(fromTop, fromLeft);
            }
        }

        return grid[m - 1][n - 1];
    }
};

int main(){
     
}