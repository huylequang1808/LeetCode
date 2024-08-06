#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> rows;
        unordered_set<int> cols;

        for(size_t i = 0; i < matrix.size();  i++){
            for(size_t j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        } 

        for(int x : rows){
            setZeroesOnRows(matrix, x);
        }

        for(int y : cols){
            setZeroesOnCols(matrix, y);
        }
    }

    void setZeroesOnRows(vector<vector<int>>& matrix, int rows){
        for(size_t i = 0; i < matrix[0].size(); i++){
            matrix[rows][i] = 0;
        }
    }

    void setZeroesOnCols(vector<vector<int>>& matrix, int cols){
        for(size_t i = 0; i < matrix.size(); i++){
            matrix[i][cols] = 0;
        }
    }
};

int main(){
    Solution solution;

    vector<vector<int>> matrix{
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}
    };

    solution.setZeroes(matrix);

    for(int i = 0; i < matrix.size(); i++){
        for(int x : matrix[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}