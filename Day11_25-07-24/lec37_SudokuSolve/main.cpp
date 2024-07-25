#include <iostream>
#include <vector> 


using namespace std;

class Solution {
public:  
    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; ++i) {
            // Kiểm tra hàng và cột
            if (board[row][i] == num || board[i][col] == num)
                return false;

            // Kiểm tra lưới con 3x3
            int gridRow = 3 * (row / 3) + i / 3;
            int gridCol = 3 * (col / 3) + i % 3;
            if (board[gridRow][gridCol] == num)
                return false;
        }
        return true;
    }

    bool solveSudoku(vector<vector<char>>& board) {
        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, row, col, num)) {
                            board[row][col] = num;
                            if (solveSudoku(board)) // điều quan trọng nhất ở đây --> gọi lại hàm này 
                                return true;
                            board[row][col] = '.'; // Backtrack --> nếu không đúng thì ta sẽ set lại giá trị 
                        }
                    }
                    return false; // Không có số hợp lệ
                }
            }
        }
        return true; // Đã điền đầy đủ
    }
};


int main(){

}