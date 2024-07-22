#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// we will use solution at lec 21 
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0){
            return nullptr;
        }
        
        ListNode* resultList = lists[0];
        for(int i = 1; i < lists.size(); i++){
            resultList = mergeTwoLists(resultList, lists[i]);
        }
        
        return resultList;
    }

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