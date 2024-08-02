#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size()){
            return addBinary(b, a);
        }

        int size_a = a.size() - 1;
        int size_b = b.size() - 1;
        char carry = '0';
        int counter = 0;

        while(counter < size_b){
            a[size_a - counter] = ~(a[size_a - counter] | b[size_b - counter]);

            if(carry == '0'){
                if(a[size_a - counter] == '')
            }
        }

        
    }
};

int main(){

}