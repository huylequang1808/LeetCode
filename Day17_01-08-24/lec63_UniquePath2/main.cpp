#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> result(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));

        return helper(obstacleGrid, obstacleGrid.size() - 1, obstacleGrid[0].size() - 1, result);
    }

    int helper(vector<vector<int>>& obstacleGrid, int m, int n, vector<vector<int>>& result){
        if(m < 0 || n < 0 || obstacleGrid[m][n]){
            return 0;
        }

        if(m == 0 && n == 0){
            return 1;
        }

        if(result[m][n] != 0){
            return result[m][n];
        }

        result[m][n] = helper(obstacleGrid, m - 1, n, result) + helper(obstacleGrid, m, n - 1, result);

        return result[m][n];
    }
};



int main(){
    Solution solution;

    vector<vector<int>> obs{
        {0,1},
        {1  ,0}
    };

    cout << solution.uniquePathsWithObstacles(obs);

    return 0;
}