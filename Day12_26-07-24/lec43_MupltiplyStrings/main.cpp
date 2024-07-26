#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }

        vector<char> result(num1.size() + num2.size(), '0');

        for(int i = num1.size() - 1; i >= 0; i--){
            for(int j = num2.size() - 1; j >= 0; j--){
                int temp = (num1[i] - '0') * (num2[j] - '0');
                int sum = temp + (result[i + j + 1] - '0');

                result[i + j + 1] = sum % 10 + '0'; 
                result[i + j] += sum / 10;  

                if(result[i + j + 1] > '9'){
                    result[i + j + 1] -= 10;
                    result[i + j] += 1;
                }
            }
        }

        // Bỏ qua các số 0 không cần thiết ở đầu
        int start = 0;
        while(start < result.size() && result[start] == '0') {
            start++;
        }

        // Nếu tất cả là số 0, kết quả là "0"
        if (start == result.size()) {
            return "0";
        }

        return string(result.begin() + start, result.end());
    }
};

int main(){
    Solution solution;

    cout << solution.multiply("123", "456");

    return 0;
}