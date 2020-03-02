#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

    void add(ListNode *newNode){
    	ListNode *current = this;
    	while(current->next != NULL) {
    		current = current->next;
    	}
    	current->next = newNode;
    }


  };


void listNodes(ListNode *list){
	ListNode *tmp = list;

	while(tmp != NULL){
//		cout << "current: " << tmp << " " << "val: " << tmp->val <<  ", next: " << tmp->next << "; ";
		cout << tmp->val << "; ";
		tmp = tmp->next;
	}
	cout << endl;
}


ListNode* mergeLists(ListNode *l1, ListNode *l2){
	ListNode *tmp1 = l1;
	ListNode *tmp2 = l2;
	ListNode *res;

	if (l1 == NULL) {
		return l2;
	}

	if (l2 == NULL) {
		return l1;
	}


	if (tmp1->val < tmp2->val){
		res = new ListNode(tmp1->val);
		tmp1 = tmp1->next;

	} else if (tmp1->val > tmp2->val){
		res = new ListNode(tmp2->val);
		tmp2 = tmp2->next;

	} else {
		res = new ListNode(tmp1->val);
		tmp1 = tmp1->next;
	}


	while (tmp1 != NULL || tmp2 != NULL){

		if (tmp1 == NULL){
			res->add(new ListNode(tmp2->val));
			tmp2 = tmp2->next;

		} else if (tmp2 == NULL) {
			res->add(new ListNode(tmp1->val));
			tmp1 = tmp1->next;

		} else if (tmp1->val < tmp2->val){
			res->add(new ListNode(tmp1->val));
			tmp1 = tmp1->next;

		} else if (tmp1->val > tmp2->val){
			res->add(new ListNode(tmp2->val));
			tmp2 = tmp2->next;

		} else {
			res->add(new ListNode(tmp1->val));
			tmp1 = tmp1->next;
		}
	}

	return res;
}

int main() {

	ListNode *l1 = new ListNode(1);
	l1->add(new ListNode(2));
	l1->add(new ListNode(4));

	ListNode *l2 = new ListNode(1);
	l2->add(new ListNode(3));
	l2->add(new ListNode(4));

	cout << "l1: ";
	listNodes(l1);
	cout << "l2: ";
	listNodes(l2);

	ListNode *merged = mergeLists(l1, l2);

	cout << "merged: ";
	listNodes(merged);
}
