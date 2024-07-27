#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();

        if(length <= 1){
            return;
        }

        for(int i = 0; i < length - 1; i++){
            for(int j = i + 1; j < length; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i = 0; i < length; i++){
            for(int j = 0; j < length / 2; j++){
                swap(matrix[i][j], matrix[i][length - 1 - j]);
            }
        }
    }
};

int main();