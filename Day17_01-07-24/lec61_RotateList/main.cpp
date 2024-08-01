#include <iostream> 

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    // constructor 
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }

        int size = 1;
        ListNode* tail = head;
        while(tail->next != nullptr){
            tail = tail->next;
            size++;
        }
        tail->next = head;

        k = k % size;
        int newHeadPivot = size - k;
        for(int i = 0; i < newHeadPivot; i++){
            head = head->next;
            tail = tail->next;
        }

        // setting
        tail->next = nullptr;

        return head;
    }
};

int main(){
    

    return 0;
}