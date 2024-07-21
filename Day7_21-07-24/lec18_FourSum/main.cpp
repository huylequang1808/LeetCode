#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) {
            return vector<vector<int>>();
        }

        vector<vector<int>> result;
        int size = nums.size();

        // sorting the list
        std::sort(nums.begin(), nums.end());

        for (int first = 0; first < size - 3; ++first) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue; // Skip duplicate elements

            for (int second = first + 1; second < size - 2; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue; // Skip duplicate elements

                int left = second + 1;
                int right = size - 1;

                while (left < right) {
                    long long sum =
                        (long long)nums[first] + nums[second] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[first], nums[second], nums[left],
                                          nums[right]});

                        while (left < right && nums[left] == nums[left + 1])
                            ++left; // Skip duplicate elements
                        while (left < right && nums[right] == nums[right - 1])
                            --right; // Skip duplicate elements

                        ++left;
                        --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }

        return result;
    }
};

int main(){
    Solution solution;

    vector<int> nums{2,2,2,2};

    vector<vector<int>> result = solution.fourSum(nums, 8);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}