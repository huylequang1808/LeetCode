#include <iostream>

using namespace std;

class Solution{
public: 
    bool isMatch(string s, string p){
        return checkMatching(s, p, 0, 0);
    }

    bool checkMatching(string& s, string& p, int pos_1, int pos_2){
        if(pos_2 >= p.size()){
            return pos_1 == s.size();
        }
        
        bool nextCharIsStar = (pos_2 + 1 < p.size() && p[pos_2 + 1] == '*');

        if(nextCharIsStar){
            while(pos_1 < s.size() && (p[pos_2] == s[pos_1] || p[pos_2] == '.')){
                if (checkMatching(s, p, pos_1, pos_2 + 2)) {
                    return true;
                }
                pos_1++;
            }

            return checkMatching(s, p, pos_1, pos_2 + 2);
        }
        else{
            if(pos_1 < s.size() && (p[pos_2] == s[pos_1] || p[pos_2] == '.')){
                return checkMatching(s, p, pos_1 + 1, pos_2 + 1);
            }  

            if(p[pos_2] == s[pos_1 - 1]){
                return checkMatching(s, p, pos_1, pos_2 + 1);
            }
            return 0;
        }
        
    }
};


int main(){
    Solution solution; 

    if(solution.isMatch("aaa", "a*a")){
        cout << "true";
    }
    else{
        cout << "false";
    }
}