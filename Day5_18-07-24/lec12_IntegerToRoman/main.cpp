#include <iostream>
#include <map> 
#include <vector>

using namespace std;

class Solution{
public:
    string intToRoman(int num){
        map<int, char> romanNumerals = {
            {1000, 'M'},
            {500, 'D'},
            {100, 'C'}, 
            {50, 'L'},
            {10, 'X'}, 
            {5, 'V'}, 
            {1, 'I'}
        };

        // in scope of prolbem --> maximum number is 3999 --> maximum length 15 --> 
        string chr = "";

        int power = 1;
        while(num != 0){
            int temp = num % 10; 
            
            if(temp == 9){      
                chr = romanNumerals[(temp + 1) * power] + chr;
                chr = romanNumerals[(temp - 8) * power] + chr;
            }
            else if(temp == 4){
                chr = romanNumerals[(temp + 1) * power] + chr; 
                chr = romanNumerals[(temp - 3) * power] + chr; 
            }
            else{
                for(int i = 0; i < temp % 5; i++){
                    chr = romanNumerals[power] + chr;
                }

                if(temp >= 5){
                    chr = romanNumerals[5 * power] + chr;
                }
            }

            num /= 10;
            power *= 10;
        }

        return chr;
    }

    // another solution 
    string intToRoman(int num) {
        vector<pair<int, string>> romanMap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result;
        for (const auto& pair : romanMap) {
            while (num >= pair.first) {
                result += pair.second;
                num -= pair.first;
            }
        }
        return result;
    }
};


int main(){
    Solution solution;

    int num = 3749;

    cout << solution.intToRoman(num);

}