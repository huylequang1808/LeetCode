#include <iostream>

using namespace std;;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        int pivot = s.size() - 1;
        // ship the spaces in last 
        while(pivot >= 0 && s[pivot] == ' '){
            pivot--;
        }

        while(pivot >= 0 && s[pivot] != ' '){
            pivot --;
            length++;
        }

        return length;
    }
};

int main(){
    
}