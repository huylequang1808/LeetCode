#include <iostream>
#include <stack> 
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxLength = 0;
        
        // Left to right scan
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
                maxLength = max(maxLength, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        
        left = right = 0;
        
        // Right to left scan
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                right++;
            } else {
                left++;
            }
            
            if (left == right) {
                maxLength = max(maxLength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        
        return maxLength;
    }

    //   this function is check with string consist of ')' and '('
    bool isParentheses(string s){
        if(s.size() == 0){
            return  true;
        }

        if(s[0] == ')'){
            return false;
        }

        stack<char> st;
        st.push(s[0]);

        int count = 1;
        while(count < s.size()){
            if(s[count] == ')'){
                if(st.empty()){
                    return false;
                }
                st.pop();
            }
            
            if(s[count] == '('){
                st.push(s[count]);
            }
    
            count++;
        }

        if(!st.empty()){
            return  false;
        }

        return true;
    }
};

int main(){
    Solution solution;

    string s = ")()(()))))";

    cout << solution.longestValidParentheses(s) << endl;

    // if(solution.isParentheses(s)){
    //     cout << "true\n" ;
    // }
    // else{
    //     cout << "false\n";
    // }

    return 0;
}