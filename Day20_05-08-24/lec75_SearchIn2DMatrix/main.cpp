#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int cols = matrix[0].size();
        int right = matrix.size() - 1;
        int left = 0;

        while(left <= right){
            int mid = left + (right - left) / 2;

            if(matrix[mid][0] <= target && target <= matrix[mid][cols - 1]){
                return binarySearchOnArray(matrix[mid], 0, cols - 1, target);
            }

            if(matrix[mid][0] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        
        return 0;
    }

    bool binarySearchOnArray(vector<int> arr, int left, int right, int target){
        if(left > right){
            return 0;
        }

        int mid = left + (right - left)/2;

        if(arr[mid] == target){
            return 1;
        }
        else if(arr[mid] > target){
            return binarySearchOnArray(arr, left, mid - 1, target);
        }
        else{
            return binarySearchOnArray(arr, mid + 1, right, target);
        }
    }
};

int main(){
    Solution solution;

    vector<vector<int>> matrix{
        {1,3,5,7},{10,11,16,20},{23,30,34,60}
    };

    if(solution.searchMatrix(matrix, 3)){
        cout << "true\n";
    }
    else{
        cout << "false\n";
    }

    return 0;
}