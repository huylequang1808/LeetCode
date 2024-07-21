#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return 0;
        }

        string numString = to_string(x);
        int size = numString.size();

        for(int i = 0; i < size / 2; i++){
            if(numString[i] != numString[size - 1 - i]){
                return 0;
            }
        }

        return 1;
    }
};

int main(){
    
}