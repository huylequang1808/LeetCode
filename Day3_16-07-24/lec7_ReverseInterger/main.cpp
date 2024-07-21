#include <iostream>

class Solution {
public:
    int reverse(int x) {
        
        int reverseNum = 0;
        int temp = 0;

        while(x != 0){
            temp = x % 10;
            x /= 10;

            if (reverseNum > INT_MAX / 10 || (reverseNum == INT_MAX / 10 && temp > 7)) {
                return 0; // Tràn số dương
            }
            if (reverseNum < INT_MIN / 10 || (reverseNum == INT_MIN / 10 && temp < -8)) {
                return 0; // Tràn số âm
            }
    
            reverseNum = reverseNum*10 + temp; 
            
        }

        return reverseNum;
    }
};



int main(){

}