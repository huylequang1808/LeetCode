#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // we using math to solve this problem 
    string getPermutation(int n, int k) {
        vector<int> factorial(n, 1);
        vector<int> numbers;
        for (int i = 1; i < n; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        for (int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }

        k--;
        string result;

        for (int i = n; i > 0; i--) {
            int index = k / factorial[i - 1];
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= factorial[i - 1];
        }

        return result;
    }
};

int main(){
    Solution solution;

    cout << solution.getPermutation(4, 9);

    return 0;
}