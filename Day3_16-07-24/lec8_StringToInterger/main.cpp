#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution{
public:
    int myAtoi(string s){
        // find the first position to run 
        int beginPos = s.find_first_not_of(" ") ;

        if (beginPos == string::npos) {
            return 0;
        }

        int isPositive = 1;

        // Checking positive or negative
        if (s[beginPos] == '-') {
            isPositive = -1;
            beginPos++;
        } else if (s[beginPos] == '+') {
            beginPos++;
        }


        int result = 0;
        while(beginPos < s.size() && s[beginPos] <= '9' && s[beginPos] >= '0'){
            int digit = s[beginPos] - '0';

            if (result > (INT_MAX - digit) / 10) {
                if(isPositive == 1){
                    return INT_MAX;
                }
                else{
                    return INT_MIN;
                }
            }

            result = result*10 + digit;
            beginPos++;
        }

        return isPositive * result;   
    }
};



int main(){
    Solution solution;

    cout << solution.myAtoi("   +42");

    return 0;
}