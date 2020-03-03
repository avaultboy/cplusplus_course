
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertIntoSortedList(ListNode* linkedList, ListNode* nodeToInsert) {
    ListNode* tmpPtr;
    if (linkedList == NULL || nodeToInsert == NULL) return linkedList;


    if (nodeToInsert->val <= linkedList->val) {
        nodeToInsert->next = linkedList;
        return nodeToInsert;
    }

    tmpPtr = linkedList;
    while (tmpPtr->next != NULL && tmpPtr->next->val <= nodeToInsert->val){
        tmpPtr = tmpPtr->next;
    }
    nodeToInsert->next = tmpPtr->next;
    tmpPtr->next = nodeToInsert;

    return linkedList;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* tmp;
    if (l1 != NULL && l2 != NULL) {
        while (l2 != NULL) {
            tmp = l2;
            l2 = l2->next;
            l1 = insertIntoSortedList(l1, tmp);
        }
    }
    return l1;
}

void printList(ListNode* list) {
    while (list != NULL) {
        cout << list->val << "(" << list << ")" << ' ';
        list = list->next;
    }
}

void deleteList(ListNode* list) {
    ListNode* tmp;
    while (list != NULL) {
        tmp = list;
        list = list->next;
        cout << "deleting " << tmp << endl;
        delete tmp;
    }
}

int main() {
    ListNode* l1_5 = new ListNode(5);
    ListNode* l1_3 = new ListNode(3);
    ListNode* l1_2 = new ListNode(2);
    ListNode* l1_1 = new ListNode(1);
    ListNode* l2_6 = new ListNode(6);
    ListNode* l2_5 = new ListNode(5);
    ListNode* l2_4 = new ListNode(4);
    ListNode* l2_2 = new ListNode(2);
    ListNode* l2_0 = new ListNode(0);
    ListNode* merged;

    l2_0->next = l2_2;
    l2_2->next = l2_4;
    l2_4->next = l2_5;
    l2_5->next = l2_6;

    l1_1->next = l1_2;
    l1_2->next = l1_3;
    l1_3->next = l1_5;

    cout << "l1: ";
    printList(l1_1);
    cout << endl;
    cout << "l2: ";
    printList(l2_0);
    cout << endl;
    cout << "merged: ";
    merged = mergeTwoLists(l1_1, l2_0);
    printList(merged);
    cout << endl;

    deleteList(merged);

    return 0;
}
