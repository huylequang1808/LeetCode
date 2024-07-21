// chu ý ở bài này các gtri của mỗi node được viết theo đúng thứ tự giá trị của nó 
#include <iostream> 
#include <stack>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _x) : val(_x), next(nullptr) {}
    ListNode(int _x, ListNode* _next) : val(_x), next(_next) {}
};

class Solution {
    public: 
    ListNode* addTwoNumber(ListNode* l1, ListNode* l2){
        ListNode* newNumber = nullptr;
        stack<int> s1;
        stack<int> s2;

        ListNode* iter1 = l1;
        while(iter1 != nullptr){
            s1.push(iter1->val);
            iter1 = iter1->next;
        }   

        ListNode* iter2 = l2;
        while(iter2 != nullptr){
            s2.push(iter2->val);
            iter2 = iter2->next;
        }

        //solving
        int merCount = 0; 
        while(!s1.empty() || !s2.empty() || merCount){
            int value = merCount;
            if(!s1.empty()){
                value += s1.top();
                s1.pop();
            }

            if(!s2.empty()){
                value += s2.top();
                s2.pop();
            }

            merCount = value / 10;
            value = value % 10;

            ListNode* temp = new ListNode(value, newNumber);
            newNumber = temp;
        }

        return newNumber;    
    }

    void printNumber(const ListNode* number){
        while(number != nullptr){
            cout << number->val << " ";
            number = number->next;
        }
    }
};

int main(){
    
}