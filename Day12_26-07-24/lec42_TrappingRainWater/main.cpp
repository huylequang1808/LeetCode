#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution{
public:
    int trap(vector<int>& height) {
        int result = 0;
        int length = height.size();

        if (length <= 2) return 0;

        int firstPivot = 0;

        while (firstPivot < length - 1) {
            // Tìm firstPivot là đỉnh đầu tiên trong dãy
            while (firstPivot < length - 1 && height[firstPivot] <= height[firstPivot + 1]) {
                firstPivot++;
            }

            if (firstPivot >= length - 1) break;

            // Tìm lastPivot là đỉnh tiếp theo hoặc đỉnh gần nhất
            int lastPivot = firstPivot + 1;
            for (int temp = lastPivot; temp < length; temp++) {
                if (height[temp] >= height[firstPivot]) {
                    lastPivot = temp;
                    break;
                }
                if (height[temp] > height[lastPivot]) {
                    lastPivot = temp;
                }
            }

            // Tính lượng nước giữa firstPivot và lastPivot
            if (lastPivot < length) {
                result += fillWater(height, firstPivot, lastPivot);
                firstPivot = lastPivot;
            } else {
                break;
            }
        }
        return result;
    }
    

    int fillWater(vector<int>& height, int beginPos, int endPos){
        int minHeight = min(height[beginPos], height[endPos]);
        int result = 0;

        for(int i = beginPos + 1; i <= endPos; i++){
            result += max(0, minHeight - height[i]);
        }

        return result;
    }
};

// another solution using monotonic stack
int trap(vector<int>& height) {
    stack<int> s;
    int result = 0;
    int n = height.size();

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && height[i] > height[s.top()]) {
            int top = s.top();
            s.pop();

            if (s.empty()) break;

            int distance = i - s.top() - 1;
            int boundedHeight = min(height[i], height[s.top()]) - height[top];
            result += distance * boundedHeight;
        }
        s.push(i);
    }
    return result;
}

// solution for dynamic programming 
/*
Hãy tưởng tượng mỗi cột trong mảng height là một vách ngăn. 
Nước chỉ có thể bị giữ lại giữa các vách ngăn nếu có một vách ngăn cao hơn ở cả hai phía. 
Do đó, để tính lượng nước bị giữ lại ở cột nào đó, 
chúng ta chỉ cần biết vách ngăn cao nhất bên trái và bên phải của nó. 
Đây chính là những gì mà leftMax và rightMax cung cấp.
*/
int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    vector<int> leftMax(n), rightMax(n);
    int result = 0;

    leftMax[0] = height[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    for (int i = 0; i < n; ++i) {
        result += min(leftMax[i], rightMax[i]) - height[i];
    }

    return result;
}

int main(){
    Solution solution;

    vector<int> height {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << solution.trap(height);

    for(int i = 0; i < height.size(); i++){
        
            cout << height[i] << " ";
        
    }

    return 0;
};
