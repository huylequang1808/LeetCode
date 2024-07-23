#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> newNum(nums.size());
        int count = 0;
        newNum[0] = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(newNum[count] != nums[i]){
                newNum[++count] = nums[i];
                nums[count] = nums[i];
            }
        }

        return count + 1;
    }
};

int main(){


    return 0;
}