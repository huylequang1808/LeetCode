#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

class Solution{
public: 
    // first solution we will using quêue to solve it (firstly idea)
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        queue<pair<string, int>> list;

        list.push(make_pair("(", 1));

        while(!list.empty()){
            auto temp = list.front();
            list.pop();

            if(temp.first.size() == n * 2){
                result.push_back(temp.first);
                continue;
            }

            if(temp.second < n){
                list.push(make_pair(temp.first + "(", temp.second + 1));
            }
            
            if(temp.first.size() < 2 * temp.second){
                list.push(make_pair(temp.first + ")", temp.second));
            }
        } 

        return result;
    }

    // another method is backtracking
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        if (current.size() == max * 2) {
            result.push_back(current);
            return;
        }

        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }
        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }

    // solution for dynamic programing 
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};

        vector<vector<string>> dp(n + 1);
        dp[0] = {""};

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                for (const string& inside : dp[j]) {
                    for (const string& outside : dp[i - 1 - j]) {
                        dp[i].push_back("(" + inside + ")" + outside);
                    }
                }
            }
        }

        return dp[n];
    }
};

int main(){
    Solution solution;

    vector<string> result = solution.generateParenthesis(8);

    for(auto x : result){
        cout << x << endl;
    }

    return 0;
}