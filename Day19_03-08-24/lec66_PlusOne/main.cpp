#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    vector<int> plusOne(vector<int>& digits) {
        int counter = digits.size() - 1;

        while(counter >= 0){
            digits[counter] += 1;

            if(digits[counter] >= 10){
                digits[counter] -= 10;

                if(counter == 0){
                    digits.insert(digits.begin(), 1);
                    break;
                }
                counter--;
            }
            else{
                break;
            }
        }

        return digits;
    }

};

int main(){

}