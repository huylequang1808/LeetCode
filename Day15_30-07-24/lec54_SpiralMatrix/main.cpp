#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};

        int rows = matrix.size();
        int cols = matrix[0].size();
        int size = rows * cols;
        vector<int> array(size, 0);
        
        int counter = 0;
        int round = 0;

        while (counter < size) {
            // Traverse from left to right
            for (int i = round; i < cols - round && counter < size; ++i) {
                array[counter++] = matrix[round][i];
            }

            // Traverse from top to bottom
            for (int i = round + 1; i < rows - round && counter < size; ++i) {
                array[counter++] = matrix[i][cols - round - 1];
            }

            // Traverse from right to left
            for (int i = cols - round - 2; i >= round && counter < size; --i) {
                array[counter++] = matrix[rows - round - 1][i];
            }

            // Traverse from bottom to top
            for (int i = rows - round - 2; i > round && counter < size; --i) {
                array[counter++] = matrix[i][round];
            }

            ++round;
        }

        return array;
    }
};

int main(){
    Solution  solution;

    vector<vector<int>> matrix{
        {1, 2, 3},
        {4, 5, 6}, 
        {7, 8, 9}
    };

    vector<int> result = solution.spiralOrder(matrix);
    for(int x : result){
        cout << x << " ";
    }

    return 0;
}