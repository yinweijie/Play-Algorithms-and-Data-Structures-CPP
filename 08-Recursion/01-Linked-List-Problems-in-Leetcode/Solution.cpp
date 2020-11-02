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
        while(head != NULL && head->val == val) {
            ListNode* toDel = head;
            head = head->next;
            delete toDel;
        }

        if(head == NULL) {
            return NULL;
        }

        ListNode* pre = head;
        while(pre->next != NULL) {
            if(pre->next->val == val) {
                ListNode* toDel = pre->next;
                pre->next = toDel->next;
                delete toDel;
            }else{
                pre = pre->next;
            }
        }

        return head;
    }
};