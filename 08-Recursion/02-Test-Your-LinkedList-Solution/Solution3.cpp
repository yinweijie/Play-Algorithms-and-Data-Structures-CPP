#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

    // 链表节点的构造函数
    // 使用arr为参数，创建一个链表，当前的ListNode为链表头结点
    ListNode(int arr[], int n) {
        if(arr == NULL || n == 0) {
            throw std::invalid_argument("arr can not be empty");
        }

        val = arr[0];
        ListNode* cur = this;
        for(int i = 1; i < n; i++) {
            cur->next = new ListNode(arr[i]);
            cur = cur->next;
        }
    }

    // 以当前节点为头结点的链表信息字符串
    friend ostream& operator<<(ostream& os, ListNode& list)
    {
        ListNode* cur = &list;
        while(cur)
        {
            os << cur->val << "->";
            cur = cur->next;
        }
        os << "NULL";

        return os;
    }
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

int main()
{
    int nums[] = {1, 2, 6, 3, 4, 5, 6};
    int n =  sizeof(nums) / sizeof(int);
    ListNode* head = new ListNode(nums, n);
    cout << (*head) << endl;
    
    ListNode* ret = Solution().removeElements(head, 6);
    cout << (*ret) << endl;
}