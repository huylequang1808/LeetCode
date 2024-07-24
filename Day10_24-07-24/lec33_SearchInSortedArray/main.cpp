#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return  binarySearch(nums, 0, nums.size() - 1, target);
    }

    int binarySearch(vector<int>& nums, int left, int right, int target){
        if (left > right) return -1;
    
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;

        // If the left half is sorted
        if (nums[left] <= nums[mid]) {
            // Check if target is in the sorted half
            if (nums[left] <= target && target < nums[mid]) {
                return binarySearch(nums, left, mid - 1, target);
            } 
            else {
                return binarySearch(nums, mid + 1, right, target);
            }
        }
        // If the right half is sorted
        else {
            // Check if target is in the sorted half
            if (nums[mid] < target && target <= nums[right]) {
                return binarySearch(nums, mid + 1, right, target);
            } 
            else {
                return binarySearch(nums, left, mid - 1, target);
            }
        }
    }
};

int main(){
    Solution solution;

    vector<int> nums{4,5,6,7,0,1,2};


    cout << solution.binarySearch(nums, 0, nums.size() - 1, 0);




    return 0;
}
