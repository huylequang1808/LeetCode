#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1){
            return intervals;
        }

        // we using anonymous function(lamda) to custom sorting function
        std::sort(intervals.begin(), intervals.end(), [](vector<int> arr1, vector<int>arr2){
            return arr1[arr1.size() - 1] > arr2[arr2.size() - 1];
        }
        );

        vector<vector<int>> result;
        vector<bool> marked(intervals.size(), 0);
        
        for(int i = 0; i < intervals.size(); i++){
            if(marked[i]) continue;

            vector<int> ans = intervals[i];
            marked[i] = 1;
            for(int j = i + 1; j < intervals.size(); j++){
                if(ans[1] < intervals[j][0] || marked[j]){
                    continue;
                }
                
                ans[0] = min(ans[0], intervals[j][0]);
                ans[1] = max(ans[1], intervals[j][1]);
                marked[j] = 1;
            }    
            result.push_back(ans);
        }
        return result;
    }
};

// another solution optimize 
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for(int i = 0; i<n; i++){
            if(ans.empty() || arr[i][0] > ans.back()[1]){
                ans.push_back(arr[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }

        return ans;
    }
};

int main(){
    Solution solution;

    vector<vector<int>> intervals{
        {1,3},{8,10},
        {15,18},{2,6}, {1, 100}
    };

    vector<vector<int>> result = solution.merge(intervals);

    for(int i = 0; i < result.size(); i++){
        for(int x : result[i]){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}