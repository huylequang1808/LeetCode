#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // this problem has solution like grid travelsal 
    // in this problem we will using dynamic programming 
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, 0));

        return dynamic(m - 1, n - 1, memo);
    }

    int dynamic(int m, int n, vector<vector<int>>& memo){
        if(m < 0 || n < 0){
            
            return 0;
        }

        if(m == 0 && n == 0){
            return 1;
        }


        if(memo[m][n] != 0){
            return memo[m][n];
        }
        else{
            memo[m][n] = dynamic(m - 1, n, memo) + dynamic(m, n - 1, memo);
            return memo[m][n];
        }
    }
};


int main(){
    Solution solution;

    cout << solution.uniquePaths(3, 7);


    return 0;
}