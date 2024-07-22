#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // bad solution 
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* cur1 = head;
        ListNode* cur2 = head->next;

        //swap for head
        cur1->next = cur2->next;
        cur2->next = cur1;
        head = cur2;

        ListNode* pre = cur1;
        cur1 = pre->next;
        if(cur1 == nullptr){
            return head;
        }
        cur2 = cur1->next;


        while(cur1 != nullptr && cur2 != nullptr){
            // swap 
            cur1->next = cur2->next;
            cur2->next = cur1;
            pre->next = cur2;

            //
            pre = cur1;
            cur1 = pre->next;
            if(cur1 == nullptr){
                break;
            }
            cur2 = cur1->next;
        }

        return head;
    }


    // another solution 
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
        return head;
       
       ListNode *temp = head->next;
       head->next = swapPairs(head->next->next);
       temp->next = head;

       return temp;
    }
};


int main(){
    Solution s;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    s.swapPairs(head);

    return 0;
}