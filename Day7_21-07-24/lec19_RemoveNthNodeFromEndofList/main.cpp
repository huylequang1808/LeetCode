#include <iostream>
#include <stack>

using namespace std;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // we will using stack for this problem 
        stack<ListNode*> s;

        ListNode* node = head;
        while(node != nullptr){
            s.push(node);
            node = node->next;
        }

        if(n > s.size()){
            return nullptr;
        }

        if(s.size() == n){
            return removeHead(head);
        }

        for(int i = 0; i < n; i++){
            s.pop();
        }

        ListNode* headTemp = s.top();
        ListNode* delNode = headTemp->next;

        headTemp->next = delNode->next;
        delNode->next =  nullptr;
        delete delNode;

        return head;
    }

    ListNode* removeHead(ListNode* head){
        if(head == nullptr){
            return nullptr;
        }

        ListNode* delNode = head;
        head = head->next;
        delete delNode;
    
        return head;
    }
};

int main(){
    
}