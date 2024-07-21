#include <iostream>
#include <unordered_map>

using namespace std;

class Solution{
public:
    int romanToInt(string s){
        unordered_map<string, int> romanNumerals{
            {"M", 1000}, {"CM", 900}, {"D", 500},
            {"CD", 400},{"C", 100},{"XC", 90}, {"L", 50},{"XL", 40},
            {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}
        };

        int result = 0;
        int size = s.size();

        int i = 0;
        while(i < size){
            if(i != size - 1 && romanNumerals.find(s.substr(i, 2)) != romanNumerals.end()){
                result += romanNumerals[s.substr(i, 2)];
                i += 2;
            }
            else{
                result += romanNumerals[s.substr(i, 1)];
                i++;
            }
        }

        return result;
    }

    // another solution 
    int romanToInt(string s){
    unordered_map<char,int>m;
        m['I']=1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int ans=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(m[s[i]]<m[s[i+1]]){
                ans-=m[s[i]];
            }
            else{
                ans+=m[s[i]];
            }
        }
        return ans;
    }
};


int main(){
    Solution solution;

    cout << solution.romanToInt("MCMXCIV");

    return 0;
}