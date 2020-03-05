//============================================================================
// Name        : day_3_3.cpp
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

ListNode* createListFromNum(uint num) {
	if (!num) {
		return nullptr;
	}

	ListNode* l = new ListNode(0), *templ = l;

	cout << "Sum:\t";

	while (num) {
		templ->val = num % 10;
		cout << templ->val;
		num /= 10;
		if (num) {
			templ->next = new ListNode(0);
			templ = templ->next;
			cout << "->";
		}
	}
	cout << endl;
	return l;
}

uint getNumber(ListNode *l) {
	uint number(0);
	while (l) {
		number += l->val;
		if (l->next) {
			number *= 10;
		}
		l = l->next;
	}
	return number;
}

uint reverseNum(uint a) {
	uint dec = 1;
	long long res = 0;
	while (a != 0) {
		res = res* dec + (a % 10); //остаток от деления на 10
		dec = 10; //установить множитель на 10
		a /= 10;
	}
	if (res > INT32_MAX)
		return 0;

	return res;
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
	uint mem1[6] = {1,2,4,4,4,7};
	uint mem2[8] = {1,3,4,5,7,7,8,1};
	uint num1, num2;

	ListNode* l1 = createList(6, mem1);
	ListNode* l2 = createList(8, mem2);

	num1 = getNumber(l1);
	num2 = getNumber(l2);

	ListNode* l3 = createListFromNum(reverseNum(num1+num2));

	clearList(l1);
	clearList(l2);
	clearList(l3);
	return 0;
}
