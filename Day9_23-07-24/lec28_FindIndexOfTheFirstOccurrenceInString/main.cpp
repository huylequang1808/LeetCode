#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()){
            return -1;
        }

        int position = 0;

        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[0]){
                position = i;
                int count = 0;
                while(haystack[i + count] == needle[count] && i < haystack.size() && count < needle.size()){
                    count++;
                }

                if(count == needle.size()){
                    return position;
                } 
            }
        }

        return -1;
    }
};

main(){
    
    return 0;
}