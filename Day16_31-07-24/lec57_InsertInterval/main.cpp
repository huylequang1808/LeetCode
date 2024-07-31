#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

class Solution {
public:
    // un optimize solution because the intervals is sorted by first element and it non-overlapping 
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);;
        std::sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for(int i = 0; i < intervals.size(); i++){
            if(result.size() ==  0 || result[result.size() - 1][1] < intervals[i][0]){
                result.push_back(intervals[i]);
            }
            else{
                result[result.size() - 1][0] = min(result[result.size() - 1][0], intervals[i][0]);
                result[result.size() - 1][1] = max(result[result.size() - 1][1], intervals[i][1]);
            }
        }


        return result;
    }

    // another solution 
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int counter = 0;

        // insert the previous interval 
        while(counter < intervals.size() && intervals[counter][0] < newInterval[0]){
            result.push_back(intervals[counter]);
            counter++;
        }

        while(counter < intervals.size() && intervals[counter][1] < newInterval[0]){
            newInterval[0] = min(intervals[counter][0], newInterval[0]);
            newInterval[1] = max(intervals[counter][1], newInterval[1]);
            counter++;
        }

        // insert the new interval 
        result.push_back(newInterval);

        // insert the end 
        while(counter < intervals.size()){
            result.push_back(intervals[counter]);
            counter++;
        }

        return result;
    }
};

int main(){


    return 0;
}