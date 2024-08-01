#include <iostream>

using namespace std;


class Solution {
public:
    bool isNumber(string s) {

    }

    bool isDigit(char x){
        return (x >= '0' && x <= '9');
    }
};

int main(){
    Solution solution;


    if(solution.isDigit('a')){
        cout << " true";
    }
    else{
        cout << "false";
    }


    return 0;
}
