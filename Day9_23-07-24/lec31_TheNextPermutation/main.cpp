#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(std::vector<int>& nums) {
        int n = nums.size();
        int k = -1;

        // Step 1: Find the largest index k such that nums[k] < nums[k + 1]
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        }

        // If no such k exists, the array is in its last permutation
        // Reverse the entire array to get the smallest permutation
        if (k == -1) {
            std::reverse(nums.begin(), nums.end());
            return;
        }

        int l = -1;
        // Step 2: Find the largest index l greater than k such that nums[k] < nums[l]
        for (int i = n - 1; i > k; --i) {
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        }

        // Step 3: Swap the values at indices k and l
        std::swap(nums[k], nums[l]);

        // Step 4: Reverse the sequence from k + 1 to the end
        std::reverse(nums.begin() + k + 1, nums.end());
    }
};

int main(){
    Solution solution;

    vector<int> nums{3, 1, 2};

    solution.nextPermutation(nums);

    for(auto x : nums){
        cout << x  << " ";
    }

    return 0;
}