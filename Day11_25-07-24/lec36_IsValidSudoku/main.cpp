#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rowsSet(9);
        vector<unordered_set<char>> colsSet(9);
        vector<unordered_set<char>> boxSet(9);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++ ){
                char num = board[i][j];

                if(num == '.'){
                    continue;
                }

                int box = (i / 3) * 3 + j/3;

                if(rowsSet[i].count(num) || colsSet[j].count(num) || boxSet[box].count(num)){
                    return false;
                }

                // insert
                rowsSet[i].insert(num);
                colsSet[j].insert(num);
                boxSet[box].insert(num);
            }
        }    
        return true;
    }

    // another solution 
    bool isValidSudoku(vector<vector<char>>& board) {
        bool usedRow[9][9]={}; 
        bool usedCol[9][9]={};
        bool usedGrid[9][9]={};
        for(size_t i{}; i < 9; ++i)
        {
            for(size_t j{}; j < 9; ++j)
            {
                int k = i / 3 * 3 + j / 3;
                char ch  = board[i][j];
                if(int num = ch-'1'; ch != '.')
                {
                    if(usedRow[j][num] || usedCol[i][num] || usedGrid[k][num])
                        return false;

                    usedRow[j][num] = usedCol[i][num] = usedGrid[k][num] = true;
                }
            }
        }
        
        return true;
    }
};

int main(){

}