
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



void deleteList(ListNode* list) {
    ListNode* tmp;
    while (list != NULL) {
        tmp = list;
        list = list->next;
        cout << "deleting " << tmp << endl;
        delete tmp;
    }
}

ListNode* int2list(int number) {
    ListNode* result = NULL;
    ListNode* current = NULL;
    do{
        if (current == NULL) {
            current = new ListNode(number % 10);
            result = current;
        } else {
            current->next = new ListNode(number % 10);
            current = current->next;
        }
        number /= 10;
    } while (number != 0);
    return result;
}
int list2int(ListNode* list){
    int result = 0;
    int pow = 1;
    while(list != NULL)
    {
        result += list->val * pow;
        pow *= 10;
        list = list->next;
    }
    return result;
}

void printList(ListNode* list) {
    while (list != NULL) {
        cout << list->val << "(" << list << ")" << ' ';
        list = list->next;
    }
}

ListNode* sumLists(ListNode* l1, ListNode* l2) {
    ListNode* result = NULL;
    ListNode* current = NULL;
    ListNode* cont = NULL;
    int overflow = 0;
    while (l1 != NULL && l2 != NULL) {
        if (result == NULL) {
            current = new ListNode((l1->val + l2->val + overflow) % 10);
            result = current;
        } else {
            current->next = new ListNode((l1->val + l2->val + overflow) % 10);
            current = current->next;
        }
        overflow = (l1->val + l2->val + overflow) / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 != NULL) {
        cont = l1;
    } else if (l2 != NULL) {
        cont = l2;
    } else {
        if (overflow > 0) {
            current->next = new ListNode(overflow);
        }
    }
    while (cont != NULL) {
        current->next = new ListNode((cont->val + overflow) % 10);
        current = current->next;
        overflow = (cont->val + overflow) / 10;
        cont = cont->next;
    }
    return result;
}

int main() {

    int i1 = 38218321;
    int i2 = 702199;
    ListNode* l1 = int2list(i1);
    ListNode* l2 = int2list(i2);
    ListNode* sum = sumLists(l1, l2);
    cout << i1 << '\t';
    printList(l1);
    cout << endl << '+' << endl;
    cout << i2 << '\t';
    printList(l2);
    cout << endl << '=' << endl;
    cout << list2int(sum) << '\t';
    printList(sum);

    deleteList(l1);
    deleteList(l2);
    deleteList(sum);

    return 0;
}
