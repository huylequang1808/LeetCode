#include <iostream>
#include <sstream>
#include <string> 
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string token = "";
        stringstream ss(path);

        stack<string> s;
        while(getline(ss, token, '/')){
            if(token == "" || token == "."){
                continue;
            }

            if(token == ".."){
                if(!s.empty()){
                    s.pop();
                }
                continue;
            }

            s.push(token);
        }

        if(s.empty()){
            return "/";
        }

        // get the string from stack 
        string result = "";
        while(!s.empty()){
            result = '/' + s.top() + result;
            s.pop();
        }

        return result;
    }
};

int main(){
    Solution solution;

    string result = solution.simplifyPath("/.../a/../b/c/../d/./");
    
    cout << "result: " << result;
    return 0;
}