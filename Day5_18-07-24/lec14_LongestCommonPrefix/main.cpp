#include <iostream>
#include <vector>
#include <unordered_map>




using namespace std;


// we set public for all to easy to access like struct 
class trieNode{
public: 
    unordered_map<char, trieNode*> children;
    bool isEndOfWord;   

    // constructor 
    trieNode() : isEndOfWord(false){}

    //destructor
    ~trieNode() {
        for (auto& child : children) {
            delete child.second;
        }
    }
};

class trie{
private: 
    trieNode* root; 

public:
    // constructor 
    trie(){ 
        root = new trieNode();
    }

    //destructor
    ~trie() {
        delete root;
    }

    void insert(string word){
        trieNode* node = root;

        for(char x : word){
            if(node->children.find(x) == node->children.end()){
                node->children[x] = new trieNode();
            }

            node = node->children[x];
        }

        node->isEndOfWord = true;
    }

    string findLongestCommonPrefix(){
        string result = "";
        trieNode* node = root;

        while(node){

            // if is the end of word of have another 
            if(node->children.size() != 1 || node->isEndOfWord){
                break;
            }

            auto it = node->children.begin();
            result += it->first;
            node = it->second;
        }

        return result;
    }
};

// in this solution we using trie to store the word --> it can unOptimize solution to solve this problem
class Solution{
public: 
    string longestCommonPrefix(vector<string>& strs){
        trie T;

        for(auto word : strs){
            T.insert(word);
        }

        return T.findLongestCommonPrefix();
    }

};

int main(){
    Solution solution;

    vector<string>strs = {"flower","flow","flight"};

    cout << solution.longestCommonPrefix(strs);

    return 0; 
}