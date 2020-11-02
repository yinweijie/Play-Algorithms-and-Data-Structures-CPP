#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode* pre = dummyHead;
        while(pre->next != NULL) {
            if(pre->next->val == val) {
                ListNode* toDel = pre->next;
                pre->next = toDel->next;
                delete toDel;
            }else{
                pre = pre->next;
            }
        }

        ListNode* ret = dummyHead->next;
        delete dummyHead;

        return ret;
    }
};