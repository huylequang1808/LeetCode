#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int _val) : val(_val), next(nullptr) {}
    ListNode(int _val, ListNode* _next) : val(_val), next(_next) {}
};

class Solution{
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            ListNode* Tail = nullptr;
            ListNode* newNumber = Tail;

            int merCount = 0;
            while(l1 != nullptr || l2 != nullptr || merCount){
                int value = merCount;
                if(l1 != nullptr){
                    value += l1->val;
                    l1 = l1->next;
                }

                if(l2 !=  nullptr){
                    value += l2->val;
                    l2 = l2->next;
                }

                merCount = value / 10;
                value = value % 10;
                ListNode* temp = new ListNode(value);

                if(Tail == nullptr){
                    newNumber = temp;
                    Tail = temp;
                }
                else{
                    Tail->next = temp;
                    Tail = temp;
                }
            }

            return newNumber;
        }
};


int main(){

}