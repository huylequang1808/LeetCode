#include <iostream>
#include <vector>


using namespace std;

class Solution{    
public:

    // basic solution 
    // int maxArea(vector<int>& height){
    //     int Area = 0;
    //     int size = height.size();

    //     for(int i = 0; i < size; i++){
    //         for(int j = i + 1; j < size; j++){
    //             int temp = min(height[i], height[j]) * (j - i);
    //             if(Area < temp){
    //                 Area = temp;
    //             }
    //         }
    //     }

    //     return Area;
    // }

    // using greedy algorithm 
    int maxArea(vector<int>& height){
        int area = 0;

        int left = 0;
        int right = height.size() - 1;

        while(left < right){

            // change the area if found the bigger area
            int temp = min(height[left], height[right]) * (right - left);
            if(temp > area){
                area = temp; 
            } 

            // change the iter
            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }

        return area;
    }
};


int main(){
    Solution solution;

    vector<int> h{1,8,6,2,5,4,8,3,7};

    cout << solution.maxArea(h);

    return 0;
}