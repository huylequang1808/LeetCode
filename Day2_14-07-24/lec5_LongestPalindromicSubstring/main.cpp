#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

/* first solution --> using divide and conpuer --> so bad use lots of memory and time complexity  
class Solution {
public:
    string longestPalindrome(string s) {
        int maxlength = 0; 
        string longestString = ""; 

        findPalindromeString(s, longestString, maxlength);

        return longestString;
    }

    void findPalindromeString(string s, string& currentLongest, int& size){
        if(s.size() <= size){
            return;
        }

        if(palindromeCheck(s)){
            currentLongest = s;
            size = s.size();
        }
        else{
            findPalindromeString(s.substr(0, s.size() - 1), currentLongest, size); 
            findPalindromeString(s.substr(1), currentLongest, size);   
        }
    }

    bool palindromeCheck(string s){
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - 1 - i]){
                return false;
            }
        }

        return true;
    }
};
*/

// seccond solution --> matrix creation --> problem able to solve but not optimize 

class Solution{
public:
    string longestPalindrome(string s){
        int size = s.size();
        vector<vector<int>> strMatrix(size, vector<int>(size));

        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                strMatrix[i][j] = s[i] - s[size - j - 1];
            }
        }

        int pivot = 0;
        int longestSize = 0;

        // find the 
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(strMatrix[i][j] == 0){
                    int temp = 0;
                    while(true){
                        if(i + temp >= size || j + temp >= size  || strMatrix[i + temp][j + temp] != 0){
                            break;
                        }
                        temp ++;
                    }

                    if(temp > longestSize){
                        longestSize = temp;
                        pivot = i;
                    }
                    
                }
            }
        }

        if(!palindromeCheck(s.substr(pivot, longestSize))){
            return longestPalindrome(s.substr(pivot, longestSize));
        }

        return s.substr(pivot, longestSize);
    }

    bool palindromeCheck(string s){
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - 1 - i]){
                return false;
            }
        }

        return true;
    }

};

// third solution --> using dynamic programming --> use the matrix creation in seccond solution 

int main(){
    Solution solution;

    //std::cout << solution.longestPalindrome("babad");
    std::cout << solution.longestPalindrome("aacabdkacaa");
    //std::cout << solution.longestPalindrome("babaddtattarrattatddetartrateedredividerb");

    return 0;
}