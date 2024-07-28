#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        // base case
        if (n == 0) {
            return 1.0;
        }

        // smallest negative
        if (n == INT_MIN) {
            if (x == 1.0 || x == -1.0) {
                return 1.0;
            } else {
                return 0.0; 
            }
        }

        // negative number
        if (n < 0) {
            if (x == 0) {
                throw std::invalid_argument("Base cannot be zero when the exponent is negative.");
            }
            x = 1 / x;
            n = -n;
        }

        // solve 
        double half = myPow(x, n / 2);
        if (n % 2 == 0) {
            return half * half;
        } else {
            return x * half * half;
        }
    }
};

int main(){

}