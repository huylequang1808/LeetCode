#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;

        combiner(n, k, 1, vector<int>(k, 0), result);

        return result;
    }

    void combiner(int n, int k, int beginNum, vector<int> combineSet, vector<vector<int>>& result){
        if(k == 0){
            result.push_back(combineSet);
            return;
        }

        if(k < 0 || beginNum > n){
            return;
        }

        for(int i = beginNum; i <= n; i++){
            combineSet[combineSet.size() - k] = i;
            if(n - i > k - 2){
                combiner(n, k - 1, i + 1, combineSet, result);
            }
        }
    }
};

// another solution optimize than my solution 
class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		int i = 0;
		vector<int> p(k, 0);
		while (i >= 0) {
			p[i]++;
			if (p[i] > n) --i;
			else if (i == k - 1) result.push_back(p);
			else {
			    ++i;
			    p[i] = p[i - 1];
			}
		}
		return result;
	}
};


int main(){
    Solution solution;

    vector<vector<int>> result = solution.combine(19, 15);

    for(auto i = 0; i < result.size(); i++){
        for(int x : result[i]){
            cout << x << " ";
        }
        cout << endl;
    }


    return 0;
}