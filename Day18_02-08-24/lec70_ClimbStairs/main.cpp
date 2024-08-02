#include <iostream>
#include <vector>

using namespace std;;

class Solution {
public:
    int climbStairs(int n) {
        int result[n + 1];

        result[0] = result[1] = 1;

        for(int i = 2; i <= n; i++){
            result[i] = result[i - 1] + result[i - 2];
        }

        return result[n];
    }
};