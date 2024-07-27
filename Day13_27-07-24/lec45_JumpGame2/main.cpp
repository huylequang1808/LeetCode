#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums){
        if(nums[0] == 0 || nums.size() == 1){
            return 0;
        }

        int count = 1;
        int pivot = 0; 

        while(pivot + nums[pivot] < nums.size() - 1){
            int maxInRangeIndex = pivot + 1;

            int range = min(pivot + nums[pivot], int(nums.size()) - 1);
            for(int i = pivot + 1; i <= range; i++){
                if(maxInRangeIndex + nums[maxInRangeIndex]  < nums[i] + i){
                    maxInRangeIndex = i;
                }
            }
            
            count ++;
            pivot = maxInRangeIndex;
        }

        return count;
    }
};


int main(){
    Solution solution;

    vector<int> nums{2,3,1,1,4};

    cout << solution.jump(nums);

    return 0;
}