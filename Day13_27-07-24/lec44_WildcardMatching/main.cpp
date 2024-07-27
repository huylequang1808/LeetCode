#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // bool isMatch(string s, string p) {
    //     // If pattern p is empty, s must also be empty to match
    //     if (p.empty()) return s.empty();
    
    //     // If string s is empty, pattern p must only contain '*' to match
    //     if (s.empty()) {
    //         for (char x : p) {
    //             if (x != '*') return false;
    //         }
    //         return true;
    //     }

    //     //create the memoization matrix 
    //     vector<vector<bool>> memo(p.size()); 
    //     for(int i = 0; i < p.size(); i++){
    //         if(p[i] == '?' || p[i] == '*'){
    //             memo[i] = vector<bool>(s.size(), 1);
    //         }
    //         else{
    //             memo[i] = vector<bool>(s.size(), 0);
    //             for(int j = 0; j < memo[i].size(); j++){
    //                 memo[i][j] = (s[j] == p[i]);
    //             }
    //         }
    //     }       

    //    return check(memo, p, s, 0, 0);
    // }

    // bool check(vector<vector<bool>>& memo, const string& p, string& s, int xPivot, int yPivot) {
    //     int m = p.size();
    //     int n = memo[0].size();  // s.size()
        
    //     if (xPivot == m && yPivot == n) return true;
    //     if (xPivot == m) return false;

    //     if (yPivot == n) {
    //         while (xPivot < m && p[xPivot] == '*') xPivot++;
    //         return xPivot == m;
    //     }
        
    //     if (p[xPivot] == '?' || p[xPivot] == s[yPivot]) {
    //         return check(memo, p, s, xPivot + 1, yPivot + 1);
    //     }
        
    //     if (p[xPivot] == '*') {
    //         return check(memo, p, s, xPivot + 1, yPivot) || check(memo, p, s, xPivot, yPivot + 1);
    //     }
        
    //     return false;
    // }

    bool isMatch(string s, string p) {
        // Create the memoization matrix
        vector<vector<bool>> memo(p.size() + 1, vector<bool>(s.size() + 1, false));
        memo[0][0] = true; // empty pattern matches empty string

        // Fill the matrix based on the pattern and string
        for (int i = 1; i <= p.size(); ++i) {
            if (p[i - 1] == '*') {
                memo[i][0] = memo[i - 1][0]; // '*' can match an empty sequence
            }
            for (int j = 1; j <= s.size(); ++j) {
                if (p[i - 1] == '*') {
                    memo[i][j] = memo[i - 1][j] || memo[i][j - 1];
                } else if (p[i - 1] == '?' || p[i - 1] == s[j - 1]) {
                    memo[i][j] = memo[i - 1][j - 1];
                }
            }
        }

        // Print the matrix to check correctness
        for (int i = 0; i < memo.size(); i++) {
            for (int j = 0; j < memo[i].size(); j++) {
                cout << memo[i][j] << " ";
            }
            cout << endl;
        }

        return memo[p.size()][s.size()];
    }
};

int main(){
    Solution solution;

    if(solution.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b")){
        cout << "TRUE\n";
    }
    else{
        cout << "FALSE\n";
    }


    return 0;
}