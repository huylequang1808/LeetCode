#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

class Solution{
public:
    void findCombination(vector<int>& candidates, int target, int beginPos, int currentTarget, vector<int>& current, vector<vector<int>>& result) {
        if (currentTarget == target) {
            result.push_back(current);
            return;
        }

        for (int i = beginPos; i < candidates.size(); ++i) {
            if (i > beginPos && candidates[i] == candidates[i - 1]) {
                continue; // Tránh sử dụng cùng một phần tử nhiều lần
            }

            if (currentTarget + candidates[i] > target) {
                break; // Dừng sớm khi tổng vượt quá mục tiêu
            }

            current.push_back(candidates[i]);
            findCombination(candidates, target, i + 1, currentTarget + candidates[i], current, result);
            current.pop_back(); // Quay lui (backtracking)
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        // Sắp xếp các phần tử của candidates để dễ dàng kiểm soát việc trùng lặp
        sort(candidates.begin(), candidates.end());
        
        findCombination(candidates, target, 0, 0, current, result);

        return result;
    }
};




int main(){
    Solution solution;

    vector<int> candidates{10,1,2,7,6,1,5};

    vector<vector<int>> result = solution.combinationSum2(candidates, 8);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;    
}