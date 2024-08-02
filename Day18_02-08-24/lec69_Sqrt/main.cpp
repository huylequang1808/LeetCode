#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        long left = (long) (exp(0.5* log(x)));
        long right = left+1;
        return right * right > x ? left : right;
    }
};
