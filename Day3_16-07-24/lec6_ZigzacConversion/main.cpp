#include <iostream>
#include <string> 

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1){
            return s;
        }

        int size = s.size();

        // initializes a temporary matrix
        char** hierarchicalMatrix = new char*[numRows];
        int* counter = new int[numRows]{0};
        for(auto i = 0; i < numRows; i++){
            hierarchicalMatrix[i] = new char[size / numRows + 2];
        }

        int count = 0;
        while(count < size){
            for(int i = 0; i < numRows && count < size; i++){
                hierarchicalMatrix[i][counter[i]] = s[count];
                count++;
                counter[i]++; 
            }

            for(int i = numRows - 2; i > 0 && count < size; i--){
                hierarchicalMatrix[i][counter[i]] = s[count];
                count++;
                counter[i]++; 
            }
        }

        string endString = "";
        // adding the end charecter \0"
        for(int i = 0; i < numRows; i++){
            hierarchicalMatrix[i][counter[i]] = '\0';
            endString += string(hierarchicalMatrix[i]);

            delete hierarchicalMatrix[i];
        }

        delete[] hierarchicalMatrix;
        delete[] counter;

        return endString;      
    }
};

int main(){
    Solution solution;

    string s = "PAYPALISHIRING";

    cout << solution.convert(s, 4);


    return 0;
}