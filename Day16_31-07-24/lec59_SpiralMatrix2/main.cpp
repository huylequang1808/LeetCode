#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));;
        int counter = 1;
        int round = 0;
        int maximum = n * n;
        
        while(counter <= maximum){
            //filled from left to right 
            for(int i = round; i < n - round && counter <= maximum; i++){
                result[round][i] = counter;
                counter++;
            }

            // fill from top to bottom 
            for(int i = round + 1; i < n - round - 1 && counter <= maximum; i++){
                result[i][n - round - 1] = counter;
                counter++;
            }

            // fill from right to left 
            for(int i = n - round - 1; i >= round && counter <= maximum; i--){
                result[n - round - 1][i] = counter;
                counter++;
            }

            //fill from bottom to top 
            for(int i = n - round - 2; i > round  && counter <= maximum; i--){
                result[i][round] = counter;
                counter++;
            }
            round++;
        }

        return result;
    }
};

int main(){
    Solution solution;

    vector<vector<int>> result = solution.generateMatrix(4);

    for(auto x : result){
        for(int y : x){
            cout << y << " ";
        }
        cout << endl;
    }   


    return 0;
}