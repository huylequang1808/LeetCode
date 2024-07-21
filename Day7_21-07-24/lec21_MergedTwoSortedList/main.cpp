#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;

    // constructor
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(list1 == nullptr){
            return list2;
        }

        if(list2 == nullptr){
            return list1;
        }

        if(list1->val > list2->val){
            return mergeTwoLists(list2, list1);
        }

        // 
        ListNode* node1 = list1;
        ListNode* node2 = list2;
        while(node1 != nullptr && node2 != nullptr){
            
            ListNode* beginSubNode = node2;
            ListNode* endSubNode = node2;

            while(node1->next != nullptr && node1->next->val < node2->val){
                node1 = node1->next;
            }

            while(endSubNode->next != nullptr && endSubNode->next->val < node1->val){
                endSubNode = endSubNode->next;
            }
            

            // merging
            node2 = node2->next; 
            node1 = insertSubList(node1, beginSubNode, endSubNode);
        }

        if(node2 != nullptr){
            node1 = node2;
        }

        return list1;
    }

    // this insert method will return the end of list 
    ListNode* insertSubList(ListNode* list1, ListNode* beginNode, ListNode* endNode){
        if(list1 == nullptr){
            return endNode;
        }

        endNode->next = list1->next; 
        list1->next = beginNode;
        return endNode;
    }


    // another solution is stronger and faster 
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; // Dummy node to simplify edge cases
        ListNode* cur = &dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        // Append remaining nodes from either list
        cur->next = list1 ? list1 : list2;

        return dummy.next;
    }
};


int main(){

}