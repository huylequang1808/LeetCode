#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> newNums;

        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                int buffer = nums[i] + nums[j];
                if(buffer == target){
                    newNums.push_back(i);
                    newNums.push_back(j);
                    break;
                }
            }
        
        }
        return newNums;
    }
};


int main(){
    
}