#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;

        int counter = 0;
        int size = words.size();

        while(counter < size){
            int amountOfWordsInLine = 0;
            int currentLength = 0;

            while(amountOfWordsInLine + counter < size &&
             amountOfWordsInLine + currentLength <= maxWidth - words[amountOfWordsInLine + counter].size()){
                currentLength += words[amountOfWordsInLine + counter].size();
                amountOfWordsInLine++;
            }


            // padding white spaces
            string buffer = "";
            if (amountOfWordsInLine + counter < size && amountOfWordsInLine > 1) {
                vector<string> whiteSpace = createWhiteSpace(amountOfWordsInLine - 1, maxWidth - currentLength);

                for (int i = 0; i < amountOfWordsInLine - 1; i++) {
                    buffer += words[counter + i] + whiteSpace[i];
                }
                buffer += words[counter + amountOfWordsInLine - 1];
            } 
            else {
                for (int i = 0; i < amountOfWordsInLine; i++) {
                    buffer += words[counter + i];
                    if (i != amountOfWordsInLine - 1) {
                        buffer += ' ';
                    }
                }
                buffer += string(maxWidth - buffer.size(), ' ');
            }

            result.push_back(buffer);
            counter += amountOfWordsInLine;
        }

        return result;
    }

    vector<string> createWhiteSpace(int amount, int length){
        if(length < amount || amount == 0 || length == 0){
            return vector<string>();
        }

        int count = 0;
        while(length >= amount){
            count++;
            length -= amount;
        }

        vector<string> result(amount, string(count, ' '));
        while(length > 0){
            result[length - 1] += ' ';
            length--;
        }

        return result;
    }
};

int main(){
    Solution solution;

    //vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
    vector<string> words = {"What","must","be","acknowledgment","shall","be"};
    vector<string> result = solution.fullJustify(words, 16);

    for(string x : result){
        cout << "-" << x << "-" << "length: " << x.size() << endl;
    }

    return 0;
}