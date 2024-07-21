#include <iostream>
#include <stack>

using namespace std;

class Solution{
public: 
    bool isValid(string s){
        if(s.size() <= 1 || s[0] == '}' || s[0] == ')' || s[0] == ']'){
            return false;
        }

        stack<char> storerage;

        storerage.push(s[0]);
        int count = 1;

        while(count < s.size()){
            if(s[count] == '(' || s[count] == '[' || s[count] == '{'){
                storerage.push(s[count]);
            }
            else if(!storerage.empty() && this->closedBracket(storerage.top()) == s[count]){
                storerage.pop();
            }
            else{
                return false;
            }

            count++;
        }

        if(storerage.empty() && count == s.size()){
            return true;
        }
        else{
            return 0;
        }
    }

    char closedBracket(char ch){
        if(ch == '{'){
            return '}';
        }

        if(ch == '['){
            return ']';
        }

        return ')';
    }
};



int main(){ 
    Solution solution;

    if(solution.isValid("{}{}[][]{")){
        cout << "true";
    }
    else{
        cout << "false";
    }

    return 0;
}