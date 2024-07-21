#include <iostream> 
#include <set>
#include <vector>

using namespace std;

class Solution{
    int lengthOfLongestSubstring(string s) {
        vector<char> subString;
        int longest = 0;
        int memo[128]{0}; // using with ascii table
        for(int i = 0; i < s.length(); i++){
            subString.push_back(s[i]);
            memo[(int)s[i]] ++;

            if(memo[(int)s[i]] > 1){
                bool flag = false;
                while(!flag){
                    if(subString[0] == s[i]){
                        flag = true;
                    }
                    memo[subString[0]]--;
                    subString.erase(subString.begin());
                }
            }
            if(longest < subString.size()) longest = subString.size();

        }

        return longest;
    }
};


int main(){

}