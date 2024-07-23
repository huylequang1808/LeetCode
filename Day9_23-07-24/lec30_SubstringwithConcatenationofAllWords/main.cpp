#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // we will using sliding window for this problem --> it oke but so slow 
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].size();
        int windowLength = wordLength * words.size();
        vector<int> result;

        if(s.size() < windowLength){
            return result;
        }

        //  using unordered_set because search with O(1)
        multiset<string> wordsSet;
        for(auto x : words){
            wordsSet.insert(x);
        }

        // main 
        for(int i = 0; s.size() - i >= windowLength; i++){
            if(isAllWordsInString(wordsSet, s.substr(i, windowLength), wordLength)){
                result.push_back(i);
            }
        }

        return result;
    }

    bool isAllWordsInString(multiset<string> words, string s, int stringLength){
        
        for(int i = 0; i < s.size(); i+= stringLength){
            auto it = words.find(s.substr(i, stringLength));
            if(it != words.end()){
                words.erase(it);
            }
            else{
                return false;
            }
        }

        if(words.empty()){
            return true;
        }

        return false;
    }

    // another solution 
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].size();
        int windowLength = wordLength * words.size();
        vector<int> result;

        if(s.size() < windowLength){
            return result;
        }

        //  using unordered_set because search with O(1)
        unordered_map<string, int> wordsSet;
        for(auto x : words){
            wordsSet.insert({x, 0});
        }

        // main 
        for(int i = 0; s.size() - i >= windowLength; i++){
            unordered_map<string, int> wordsCount;

            int j = 0;
            for(; j < words.size(); j++){
                int wordIndex = i + j * wordLength;
                string word = s.substr(wordIndex, wordLength);
                if(wordsSet.find(word) != wordsSet.end()){
                    wordsCount[word]++;
                    if(wordsCount[word] > wordsSet[word]){
                        break;
                    }
                }
                else{
                    break;
                }
            }

            if(j == words.size()){
                result.push_back(i);
            }
        }

        return result;
    }

    // another solution but fastest 
    // in this solution we not re_create the wordCount --> we just insert and remove one element while slide
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLength = words[0].size();
        int numWords = words.size();
        int windowLength = wordLength * numWords;
        vector<int> result;

        if (s.size() < windowLength) {
            return result;
        }

        // Create a frequency map for the words
        unordered_map<string, int> wordCount;
        for (const string& word : words) {
            wordCount[word]++;
        }

        // Slide window over the string
        for (int i = 0; i < wordLength; ++i) {
            unordered_map<string, int> seenWords;
            int left = i;
            int count = 0;
            
            for (int right = i; right + wordLength <= s.size(); right += wordLength) {
                string word = s.substr(right, wordLength);
                if (wordCount.find(word) != wordCount.end()) {
                    seenWords[word]++;
                    count++;
                    
                    // Move the left boundary of the window if needed
                    while (seenWords[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLength);
                        seenWords[leftWord]--;
                        count--;
                        left += wordLength;
                    }

                    // Check if all words match
                    if (count == numWords) {
                        result.push_back(left);
                    }
                } else {
                    // Reset the window
                    seenWords.clear();
                    count = 0;
                    left = right + wordLength;
                }
            }
        }

        return result;
    }
};

int main(){
    Solution solution;

    // string s = "barfoothefoobarman";
    // vector<string> words{"foo","bar"};

    string s = "wordgoodgoodgoodbestword";
    vector<string> words{"word","good","best","word"};


    vector<int> result = solution.findSubstring(s, words);

    for(auto x : result){
        cout  << x << "-->";
    }

    return 0;
}