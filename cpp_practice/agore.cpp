#include <iostream>
#include "in.h"
using namespace std;

struct listNode
{
    int val;
    listNode* next;

    listNode(int val) {
        this->val = val;
    }

    listNode(int val, listNode* next) {
        this->val = val;
        this->next = next;
    }
};

/*
 * 1 -> 2 -> 3  n = 2
 * 1 -> 3
 * */
listNode* deleteRN(listNode* head, int n) {
    if (head == nullptr) return nullptr;
    listNode* p = head, *pdel = head, *parent = nullptr;
    // n is valid
    while (n--) p = p->next;
    while (p) {
        p = p->next;
        parent = pdel;
        pdel = pdel->next;
    }
    if (parent != nullptr) {
        parent->next = pdel->next;
        return head;
    }
    // parent is nullptr
    return head->next;

}

void printList(listNode* head) {
    string s;
    while (head) {
        s += std::to_string(head->val) + " -> ";
        head = head->next;
    }
    int cnt = 4;
    while (cnt--) s.pop_back();
    cout << s << endl;
}

int main()
{
    listNode* n5 = new listNode(5, nullptr);
    listNode* n4 = new listNode(4, n5);
    listNode* n3 = new listNode(3, n4);
    listNode* n2 = new listNode(2, n3);
    listNode* n1 = new listNode(1, n2);
    listNode* l = deleteRN(n1, 2);
    printList(l);


    return 0;
}

