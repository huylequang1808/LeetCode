#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        helper(nums, 0, nums.size() - 1, result);

        return result;
    }

    void helper(vector<int> nums, int left, int right, vector<vector<int>>& result) {
        if (left == right) {
            result.push_back(nums);
            return;
        }

        for (int i = left; i <= right; i++) {
            swap(nums[left], nums[i]);
            helper(nums, left + 1, right, result);
            swap(nums[left], nums[i]);
        }
    }
};


int main(){

    return 0;
}