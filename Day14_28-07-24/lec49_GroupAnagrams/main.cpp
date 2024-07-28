#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
// in this solution we will hash the string and then group them 
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp; 

        for(string str : strs){
            mp[hashing(str)].push_back(str);
        }

        vector<vector<string>> result;
        for(auto it : mp){
            result.push_back(it.second);
        }

        return result;
    }

    string hashing(string str){
        std::sort(str.begin(), str.end());
        return str;
    }
};

int main(){


}