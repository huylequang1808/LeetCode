#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // you can find the explanation for this solution on geeksforgeek
    // we using hash table and two pointer to solve this problem
    string minWindow(string s, string t) {
        if(s.size() < t.size()){
            return "";
        }

        //create the hash table for string t using arrray
        const int max_char = 256;
        int hash_pt[max_char]{0};
        int hash_str[max_char]{0};

        // input the char of string t into map 
        for(char x : t){
            hash_pt[x]++;
        }

        int start = 0;
        int beginPos = -1;
        int minSize = INT_MAX;

        int count = 0;
        for(int i = 0; i < s.size(); i++){
            hash_str[s[i]]++;

            if(hash_str[s[i]] <= hash_pt[s[i]]){
                count++;
            }

            if(count == t.size()){

                // try to minimize the window
                while(hash_str[s[start]] > hash_pt[s[start]] || hash_pt[s[start]] == 0){
                    if(hash_str[s[start]] > hash_pt[s[start]]){
                        hash_str[s[start]]--;
                    }

                    start++;
                }

                int windowSize = i - start + 1;
                if(windowSize < minSize){
                    minSize = windowSize;
                    beginPos = start;
                }
            }
        }
        
        if(beginPos == -1){
            return "";
        }

        return s.substr(beginPos, minSize);
    }
};

int main(){


    return  0;
}