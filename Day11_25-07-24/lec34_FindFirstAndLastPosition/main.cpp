#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int position = binarySearch(nums, 0, nums.size() - 1, target);

        vector<int> result(2, position);

        while(result[0] > 0 && nums[result[0] - 1] == target){
            result[0]--;
        }

        while(result[1] < nums.size() - 1 && nums[result[1] + 1] == target){
            result[1]++;
        }

        return result;
    }

    int binarySearch(vector<int>& nums, int left, int right, int target){
        if(left > right){
            return -1;
        }

        int mid = left + (right - left) / 2;

        if(nums[mid] == target){
            return mid;
        }

        if(nums[mid] < target){
            return binarySearch(nums, mid + 1, right, target);
        }

        return binarySearch(nums, left, mid - 1, target);
    }
};

int main(){

}
