#include <iostream>
#include <vector>

using std::vector;
using std::cout;

class Solution {
public:
    // this binary search will return the nearest pivot that has a value smaller
    // than target if it doesn't find the target
    int customBinarySearch(vector<int>& num, int beginPos, int target) {
        if (beginPos > num.size() - 1) {
            return num.size() - 1;
        }

        int low = beginPos;
        int high = num.size() - 1;
        int closestPos = beginPos;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (mid > high || mid < low) {
                break;
            }

            if (num[mid] == target) {
                return mid;
            } else if (num[mid] < target) {
                closestPos = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return closestPos;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n = nums1.size();
        const int m = nums2.size();
        int pivotIndex = (n + m) / 2;
        double pivotValue = 0.0;
        double prePivotValue = 0.0;
        double result = 0.0;

        if (n == 0 && m == 0) {
            return 0.0;
        }

        if (n == 0 || m == 0) {
            if (n == 0) {
                return findMedianSortedArrays(nums2, nums1);
            }

            if ((m + n) % 2 == 0) {
                return (double(nums1[pivotIndex]) +
                        double(nums1[pivotIndex - 1])) /
                       2;
            } else {
                return double(nums1[pivotIndex]);
            }
        }

        if (nums1[0] > nums2[0]) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int current = 0;
        bool checkInFirstArray = true;

        int nums1Index = 0;
        int nums2Index = 0;
        while (current <= pivotIndex) {
            int displacement = 0;
            if (checkInFirstArray) {
                if(nums2Index < m){
                    displacement = customBinarySearch(nums1, nums1Index, nums2[nums2Index]);
                    displacement -= nums1Index;
                }

                // find the value of the pivot
                if (current <= pivotIndex - 1 &&
                    pivotIndex - 1 <= current + displacement &&
                    prePivotValue == 0.0) {
                    prePivotValue =
                        nums1[nums1Index + pivotIndex - 1 - current];
                }

                if (current <= pivotIndex &&
                    pivotIndex <= current + displacement) {
                    pivotValue = nums1[nums1Index + pivotIndex - current];
                    break;
                }

                if(nums1Index < n){
                    current += displacement + 1;
                    nums1Index += displacement + 1;
                }
            } else{
                if(nums1Index < n){
                    displacement = customBinarySearch(nums2, nums2Index, nums1[nums1Index]);
                    displacement -= nums2Index;
                }
                // find the value of the pivot
                if (current <= pivotIndex - 1 &&
                    pivotIndex - 1 <= current + displacement &&
                    prePivotValue == 0.0) {
                    prePivotValue =
                        nums2[nums2Index + pivotIndex - 1 - current];
                }

                if (current <= pivotIndex &&
                    pivotIndex <= current + displacement) {
                    pivotValue = nums2[nums2Index + pivotIndex - current];
                    break;
                }

                if(nums2Index < m){
                    current += displacement + 1;
                    nums2Index += displacement + 1;
                }
            }

            checkInFirstArray = !checkInFirstArray;
        }

        if ((m + n) % 2 == 0) {
            result = (prePivotValue + pivotValue) / 2;
        } else {
            result = pivotValue;
        }

        return result;
    }
};

int main(){
    Solution solution;

    //vector<int> num1{1, 2, 3, 6, 9, 18, 19, 20, 21};
    //vector<int> num2{4, 5, 6, 7, 10, 12, 15, 22, 23, 24};

    //vector<int> num1{1, 2};
    //vector<int> num2{3, 5};

    vector<int> num2{1};
    vector<int> num1{2, 3, 4};

    double result = 0;
     
    result = solution.findMedianSortedArrays(num1, num2);

    cout << "result: " << result << std::endl;
    return 0;
}