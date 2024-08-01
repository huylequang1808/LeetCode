#include <iostream>

using namespace std;


class Solution {
public:
    bool isNumber(string s) {
        bool haveComponent = false;
        bool isDecimal = false;
        bool haveSign = false;
        bool haveNumberBeforeE = false;

        for (int i = 0; i < s.size(); i++) {
            if (isDigit(s[i])) {
                haveNumberBeforeE = true;
                continue;
            }

            if (s[i] == '.') {
                if (isDecimal || haveComponent || (i == 0 && i == s.size() - 1)) {
                    return false;
                }
                isDecimal = true;
                continue;
            }

            if (s[i] == 'e' || s[i] == 'E') {
                if (!haveNumberBeforeE || haveComponent || i == s.size() - 1) {
                    return false;
                }
                haveComponent = true;
                haveSign = false;
                continue;
            }

            if (s[i] == '-' || s[i] == '+') {
                if (i != 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
                if (i == s.size() - 1) {
                    return false;
                }
                haveSign = true;
                continue;
            }

            return false;
        }

        return haveNumberBeforeE;
    }

    bool isDigit(char x){
        return (x >= '0' && x <= '9');
    }
};

int main(){
    Solution solution;


    if(solution.isNumber("+6e-1")){
        cout << " true";
    }
    else{
        cout << "false";
    }


    return 0;
}
