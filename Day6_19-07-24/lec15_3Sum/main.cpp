#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> result;
        int size = nums.size();

        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < size - 2; ++i) {
            // Bỏ qua các phần tử trùng lặp
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int left = i + 1;
            int right = size - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Bỏ qua các phần tử trùng lặp
                    while (left < right && nums[left] == nums[left + 1]) ++left;
                    while (left < right && nums[right] == nums[right - 1]) --right;
                    
                    ++left;
                    --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return result;
    }
};





int main(){
    Solution solution;

    vector<int> nums{0,0,0};

    vector<vector<int>> result = solution.threeSum(nums);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < 3; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}