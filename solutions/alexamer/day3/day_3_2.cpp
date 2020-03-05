//============================================================================
// Name        : day_3_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

typedef unsigned int uint;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(uint len, int* members) {
	if (!len) {
		return nullptr;
	}
	ListNode* l = new ListNode(members[0]), *templ = l;
	cout << "Create:\t" << templ->val;
	for (uint i = 1; i < len; i++) {
		templ->next = new ListNode(members[i]);
		templ = templ->next;
		cout << "->" << templ->val;
	}
	cout << endl;
	return l;
}

ListNode* mergeList(ListNode* l1, ListNode* l2) {
	cout << "Merge:\t";
	if (l1 == nullptr && l2 == nullptr) {
		return nullptr;
	}

	ListNode *l = new ListNode(0), *templ = l;
	while (l1 != nullptr || l2 != nullptr) {

		if (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				templ->val = l1->val;
				l1 = l1->next;
			}
			else {
				templ->val = l2->val;
				l2 = l2->next;
			}
		}
		else {

			if (l1 == nullptr) {
				templ->val = l2->val;
				l2 = l2->next;
			}
			else {
				templ->val = l1->val;
				l1 = l1->next;
			}
		}

		cout << templ->val;

		if (l1 != nullptr || l2 != nullptr) {
			templ->next = new ListNode(0);
			templ = templ->next;
			cout << "->";
		}
	}
	cout << endl;
	return l;
}

void clearList(ListNode *l) {
	cout << "Delete:\t";
	while (l != nullptr) {
		ListNode *nextmem = l->next;
		cout << l->val;
		delete l;
		l = nextmem;
		if (l != nullptr) {
			cout << "->";
		}
	}
	cout << endl;
}

int main() {
	int mem1[6] = {1,2,4,4,4,7};
	int mem2[8] = {1,3,4,5,7,7,8,10};

	ListNode* l1 = createList(6, mem1);
	ListNode* l2 = createList(8, mem2);

	ListNode* l3 = mergeList(l1, l2);

	clearList(l1);
	clearList(l2);
	clearList(l3);
	return 0;
}
