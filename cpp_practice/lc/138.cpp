#include <iostream>
#include "in.h"
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p = head;
        if (p == nullptr) return nullptr;
        map<Node*, Node*> ma, ma2;
        Node* last = nullptr, *newHead = nullptr;
        while (p) {
            Node* n = new Node(p->val);
            if (last) last->next = n;
            else newHead = n;
            ma[p] = n;
            ma2[n] = p;
            last = n;
        }
        p = newHead;
        while (p) {
            if (ma2[p]->random == nullptr) p->random = nullptr;
            else p->random = ma[ma2[p]->random];
            p = p->next;
        }
        return newHead;
    }
};
int main()
{
    Solution* sol = new Solution();
    Node* n5 = new Node(1);
    Node* n4 = new Node(10);
    Node* n3 = new Node(11);
    Node* n2 = new Node(13);
    Node* n1 = new Node(7);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5;
    n1->random = nullptr;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;
    Node* p = sol->copyRandomList(n1);
    return 0;
}
