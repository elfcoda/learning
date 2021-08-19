#include <iostream>
#include "in.h"
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
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr) return nullptr;
        ListNode *last1 = nullptr, *last2 = nullptr, *p1 = nullptr, *p2 = nullptr;
        while (head) {
            if (head->val < x) {
                if (last1 == nullptr) p1 = last1 = head;
                else last1 = last1->next = head;
            } else {
                if (last2 == nullptr) p2 = last2 = head;
                else last2 = last2->next = head;
            }
            head = head->next;
        }
        if (p1 == nullptr) return p2;
        last1->next = p2;
        return p1;
    }
};

int main()
{
    Solution* sol = new Solution();
    ListNode* n6 = new ListNode(2, nullptr);
    ListNode* n5 = new ListNode(5, n6);
    ListNode* n4 = new ListNode(2, n5);
    ListNode* n3 = new ListNode(3, n4);
    ListNode* n2 = new ListNode(4, n3);
    ListNode* n1 = new ListNode(1, n2);
    ListNode* node = sol->partition(n1, 3);
    while (node) {
        cout << node->val << " -> ";
        node = node->next;
    }
    return 0;
}
