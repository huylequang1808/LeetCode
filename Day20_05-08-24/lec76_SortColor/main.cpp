#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // in this solution we have 3 color is corresponding by 0, 1, 2 
    //--> we using couting sort with O(n) time complexity and O(3) space complexity.
    void sortColors(vector<int>& nums) {
        int color[3]{0};

        for(int x : nums){
            color[x]++;
        }

        int counter = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < color[i]; i++){
                nums[counter++] = i;
            }
        }
    }
};