#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0 || abs(dividend) < abs(divisor)) {
            return 0;
        }

        int sign = 1;

        if((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            sign = -1;
        }

        if(dividend == divisor){
            return sign;
        }

        if(abs(divisor) == 1) {
            if(sign == 1) {
                if(dividend == INT_MIN) {
                    return INT_MAX;
                }
                return abs(dividend);
            } else {
                if(dividend == INT_MIN) {
                    return INT_MIN;
                }
                return -abs(dividend);
            }
        }

        int quotient = 0;

        if(dividend == INT_MIN) {
            dividend += abs(divisor);
            quotient++;
        }

        dividend = abs(dividend);
        divisor = abs(divisor);

        while(dividend >= divisor) {
            dividend -= divisor;
            quotient++;
        }

        return sign * quotient;
    }

    //  another solution using bitwise 

    int divide(int dividend, int divisor) {
        if(divisor == 0) {
            throw std::invalid_argument("divisor cannot be zero");
        }

        if(dividend == 0) {
            return 0;
        }

        if(divisor == 1) {
            return dividend;
        }

        if(divisor == -1) {
            if (dividend == INT_MIN) {
                return INT_MAX; // Handle overflow case
            }
            return -dividend;
        }

        // Determine the sign of the result
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

        // Convert dividend and divisor to positive values
        long long absDividend = labs(dividend);
        long long absDivisor = labs(divisor);

        int quotient = 0;

        // Subtract the divisor from the dividend until dividend is less than divisor
        for (int i = 31; i >= 0; i--) {
            if ((absDividend >> i) >= absDivisor) {
                quotient += (1 << i);
                absDividend -= (absDivisor << i);
            }
        }

        return sign * quotient;
    }

};



int main(){
    Solution solution;

    cout << solution.divide(-1, 1);

    cout << endl << INT_MIN << endl << INT_MAX;

    return 0;
}