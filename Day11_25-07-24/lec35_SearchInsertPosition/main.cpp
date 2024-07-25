#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // in this problem we will use binary search but we will custom it
    int searchInsert(vector<int>& nums, int target) {
        int insertPosition = customBinarySearch(nums, 0, nums.size() - 1, target) + 1;

        while(insertPosition > 0 && nums[insertPosition - 1] == target){
            insertPosition--;
        }

        return insertPosition;
    }

    int customBinarySearch(vector<int>& nums, int left, int right, int target){
        int mid = 0;
        int closetPosition = -1;

        while(left <= right){
            mid = left + (right - left) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                closetPosition = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }

        return closetPosition;
    }
};

int main(){
    Solution solution;

    vector<int> nums{1,3,5,6};

    cout << solution.customBinarySearch(nums, 0, nums.size() - 1, 7);

    return 0;
}