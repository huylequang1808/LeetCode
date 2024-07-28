#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // we will used the solution of the previous problem 
    int totalNQueens(int n) {
        vector<vector<string>> result;

        vector<bool> colsMarked(n, 0);
        vector<vector<bool>> diagonalMarked(2, vector<bool>(2*n - 1, 0));

        helper(n, colsMarked, diagonalMarked, vector<string>(), result);

        return result.size();
    }

    void helper(int n, vector<bool> ColsMarked, vector<vector<bool>> diagonalMarked,
    vector<string> current, vector<vector<string>>& result){
        if(current.size() == n){
            result.push_back(current);
            return;
        }

        string line(n, '.'); 
        for(int i = 0; i < n; i++){
            if(ColsMarked[i] || diagonalMarked[0][i + current.size()] || diagonalMarked[1][i - current.size() + n - 1]){
                continue;
            }

            ColsMarked[i] = 1;
            diagonalMarked[0][i + current.size()] = 1;
            diagonalMarked[1][i - current.size() + n - 1] = 1;
            
            line[i] = 'Q';
            current.push_back(line);

            helper(n , ColsMarked, diagonalMarked, current, result);

            // backtrack 
            current.pop_back();
            line[i] = '.';
            ColsMarked[i] = 0;
            diagonalMarked[0][i + current.size()] = 0;
            diagonalMarked[1][i - current.size() + n - 1] = 0;
        }
    }
};