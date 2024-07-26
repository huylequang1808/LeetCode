#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
// in this solution we try to put the num x to x - 1 position --> 
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            // Ensure nums[i] is in the range [1, n] and at its correct position
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        // Find the first missing positive number
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // If all positions are correct, return n + 1
        return n + 1;
    }
};

int main(){

}