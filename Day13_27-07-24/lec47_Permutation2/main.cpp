#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums){
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        helper(nums, 0, nums.size() - 1, result);

        return result;   
    }

    void helper(vector<int> nums, int left, int right, vector<vector<int>>& result){
        if(left == right){
            result.push_back(nums);
            return;
        }

        for(int i = left; i <= right; i++){
            if(i != left && nums[left] == nums[i]){
                continue;
            }

            swap(nums[left], nums[i]);
            helper(nums, left + 1, right, result);
            
        }
    }
};

int main(){
    Solution solution;

    vector<int> nums{1, 1, 2, 2};

    vector<vector<int>> result = solution.permuteUnique(nums);

    for(int i = 0; i < result.size(); i++){
        for(auto x : result[i]){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}