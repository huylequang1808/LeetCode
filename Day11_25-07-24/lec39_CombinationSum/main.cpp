#include <iostream>
#include <vector>


using namespace std;

class Solution{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;

        for(int i = 0; i < candidates.size(); i++){
            vector<int> newCandidate(candidates.begin() + i, candidates.end());
            findCombinationSum(newCandidate, target, newCandidate[0], vector<int>(1, newCandidate[0]), result);
        }
        return result;
    }

    void findCombinationSum(vector<int>& candidates, int target, int currentSum, vector<int> current, vector<vector<int>>& result){
        if(currentSum == target){
            result.push_back(current);
            return;
        }

        if(currentSum > target){
            return;
        }

        for(int i = 0; i < candidates.size(); i++){
            vector<int> newCurrent = current;
            newCurrent.push_back(candidates[i]);
            vector<int> newCandidate(candidates.begin() + i, candidates.end());
            findCombinationSum(newCandidate, target, currentSum + candidates[i], newCurrent, result);
        }
    }

};

// another solution 
class Solution {
public:
    void help(int i,int target,vector<int>& arr,vector<int>& sum,vector<vector<int>>& ans){
        if(i==arr.size()){
            if(target==0) {
                ans.push_back(sum);
            }
            return;
            
        }

        if(arr[i]<=target){
            sum.push_back(arr[i]);
            help(i,target-arr[i],arr,sum,ans);
            sum.pop_back();
        }
        help(i+1,target,arr,sum,ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector <vector<int>> ans;
        vector<int>sum  ;
        help(0,target,c,sum,ans);
        return ans;
    }
};



int main(){
    Solution solution;

    vector<int> candidates{2,3,6,7};

    vector<vector<int>> result = solution.combinationSum(candidates, 7);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;    
}
