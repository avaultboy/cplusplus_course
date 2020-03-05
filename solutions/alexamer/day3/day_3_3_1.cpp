//============================================================================
// Name        : day_3_3_1.cpp
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

ListNode* createList(uint len, uint* members) {
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

ListNode* sumList(ListNode* l1, ListNode* l2) {
	uint s, add(0);
	cout << "Sum:\t";
	if (l1 == nullptr && l2 == nullptr) {
		return nullptr;
	}

	ListNode *l = new ListNode(0), *templ = l;
	while (l1 != nullptr || l2 != nullptr) {

		if (l1 != nullptr && l2 != nullptr) {
			s = l1->val + l2->val + add;
			templ->val = s % 10;
			add = s / 10;
			l1 = l1->next;
			l2 = l2->next;
		}
		else {
			if (l1 == nullptr) {
				s = l2->val + add;
				templ->val = s % 10;
				add = s / 10;
				l2 = l2->next;
			}
			else {
				s = l1->val + add;
				templ->val = s % 10;
				add = s / 10;
				l1 = l1->next;
			}
		}

		cout << templ->val;

		if (l1 != nullptr || l2 != nullptr) {
			templ->next = new ListNode(0);
			templ = templ->next;
			cout << "->";
		}
		else if (add) {
			templ->next = new ListNode(add);
			cout << "->" << templ->next->val;
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
	uint mem1[] = {9,7,5};
	uint mem2[] = {3,2};

	ListNode* l1 = createList(3, mem1);
	ListNode* l2 = createList(2, mem2);

	ListNode* l3 = sumList(l1, l2);

	clearList(l1);
	clearList(l2);
	clearList(l3);
	return 0;
}
