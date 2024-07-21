#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    // in this problem we can use the method like solving permutation problem
    vector<string> letterCombinations(string digits){
        if(digits == ""){
            return vector<string>();
        }
        // init the vector store the letter corresponding to each digit
        vector<vector<string>> letterOfEachDigit{
            {},
            {},
            {"a", "b", "c"},
            {"d", "e", "f"},
            {"g", "h", "i"},
            {"j", "k", "l"},
            {"m", "n", "o"},
            {"p", "q", "r", "s"},
            {"t", "u", "v"},
            {"w", "x", "y", "z"}
        };

        if(digits.size() == 1){
            return letterOfEachDigit[digits[0] - '0'];
        }

        // firstly we using 'for' loop (bottom up method)
        vector<vector<string>> result(digits.size());
        
        // first step the begin digit
        result[0] = (letterOfEachDigit[digits[0] - '0']);
        
        for(int step = 1; step < digits.size(); step++){
            for(auto x : result[step - 1]){
                for(auto chr : letterOfEachDigit[digits[step] - '0']){
                    result[step].push_back(x + chr);
                }
            }
        }

        return result[digits.size() - 1];
    }
};

int main(){
    Solution solution;

    vector<string> result = solution.letterCombinations("");

    for(auto x : result){
        cout << x << " ";
    }

    return 0;
}