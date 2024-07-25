#include <iostream>

using namespace std;

class Solution {
public:
    // we will reduce n to 1 and solve up to the top 
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }

        string result = countAndSay(n - 1);

        string newString = "";

        for(int i = 0; i < result.size(); i++){
            int count = 1;

            while(i < result.size() - 1 && result[i] == result[i + 1]){
                count++;
                i++;
            }

            newString += to_string(count) + result[i];
        }
        
        return newString;
    }
};

int main(){

    return 0;
}