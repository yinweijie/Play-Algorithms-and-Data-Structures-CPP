#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* rev = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return rev;
    }
};