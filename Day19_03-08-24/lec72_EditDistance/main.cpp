#include <iostream>
#include <vector>

using namespace std;


// you can find this explaination for this problem in https://www.geeksforgeeks.org/edit-distance-dp-5/
/*
    this solution have some important realworld application 
    Spell Checking and Auto-Correction
    DNA Sequence Alignment
    Plagiarism Detection
    Natural Language Processing
    Version Control Systems
    String Matching 

    so you can find omptimize solution for this solution 
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));

        return minDis(word1, word2, word1.size(), word2.size(), dp);
    }

    int minDis(string word1, string word2, int n, int m, vector<vector<int>>& dp){
        if(n == 0){
            return m;
        }

        if(m == 0){
            return n;
        }

        if(dp[n][m] != -1){
            return dp[n][m];
        }

        if(word1[n -  1] == word2[m - 1]){
            dp[n - 1][m - 1] = minDis(word1, word2, n - 1, m - 1, dp);
            return dp[n - 1][m - 1];
        }

        int insertDis = minDis(word1, word2, n, m - 1, dp);
        int removeDis = minDis(word1, word2, n - 1, m, dp);
        int replaceDis = minDis(word1, word2, n - 1, m - 1, dp);

        dp[n][m] = 1 + min(insertDis, min(removeDis, replaceDis));
        return dp[n][m];
    }
};

int main(){
    Solution solution; 

    cout << solution.minDistance("intention", "execution");

    return 0;
}