#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    // constructor
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}
};

class Solution{
public: 
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || head == nullptr || head->next == nullptr){
            return head;
        }

        // divide 
        int count = 1;
        ListNode* tail = head;

        while(count < k){
            tail = tail->next;
            count++;
            if(tail == nullptr){
                return head;
            }
        }

        //reversed
        ListNode* beginSubNode = tail->next;
        ListNode* temp = reverseList(head, beginSubNode);

        // recursive 
        head->next = reverseKGroup(beginSubNode, k);

        return temp;
    }

    // in this function we can change the list just have head --> maybe faster 
    ListNode* reverseList(ListNode* head, ListNode* tail){
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* previous = tail;
        ListNode* cur = head;
        ListNode* nextNode = head->next;
        
        while(nextNode != tail){
            cur->next = previous;
            previous = cur;
            cur = nextNode;
            nextNode = nextNode->next;
        }

        cur->next = previous;
        return cur;
    }

    void print(ListNode* head){
        ListNode* temp = head;
        
        while(temp != nullptr){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Solution solution;

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    ListNode* temp = new ListNode(4);
    head->next->next->next = temp;
    temp->next = new ListNode(10);

    solution.print(head);

    //ListNode* newHead = solution.reverseList(head, temp);

    ListNode* newHead = solution.reverseKGroup(head, 2);

    solution.print(newHead);



    return 0;
}