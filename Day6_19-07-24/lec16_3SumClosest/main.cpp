#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    int threeSumClosest(vector<int>& nums, int target){
        int result = INT_MAX;
        int size = nums.size();

        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < size - 2; i++){
            int left = i + 1; 
            int right = size - 1;

            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];

                if(sum == target){
                    return sum; 
                }

                if (abs(sum - target) < abs(result)) {
                    result = sum - target;
                }

                if (sum < target) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }

        return result + target;
    }
};

int main(){

}