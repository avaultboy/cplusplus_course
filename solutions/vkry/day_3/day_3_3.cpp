/*
 * day_3_3.cpp
 *
 *  Created on: Feb 28, 2020
 *      Author: vkry
 */


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


ListNode* sumLists(ListNode *l1, ListNode *l2){
	ListNode *tmp1 = l1;
	ListNode *tmp2 = l2;
	ListNode *res;

	int sum = tmp1->val + tmp2->val;
	int remainder = 0;

	if (sum >= 10) {
		res = new ListNode(sum % 10);
		remainder = 1;
	} else {
		res = new ListNode(sum);
	}

	tmp1 = tmp1->next;
	tmp2 = tmp2->next;

	while (tmp1 != NULL || tmp2 != NULL) {

		if (tmp1 == NULL) {
			sum = tmp2->val + remainder;
			tmp2 = tmp2->next;

			if (sum >= 10) {
				res->add(new ListNode(sum % 10));
			} else {
				res->add(new ListNode(sum));
			}

		} else if (tmp2 == NULL) {
			sum = tmp1->val + remainder;
			tmp1 = tmp1->next;

			if (sum >= 10) {
				res->add(new ListNode(sum % 10));
			} else {
				res->add(new ListNode(sum));
			}

		} else {
			sum = tmp1->val + tmp2->val + remainder;
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;

			if (sum >= 10) {
				res->add(new ListNode(sum % 10));
				remainder = 1;
			} else {
				res->add(new ListNode(sum));
				remainder = 0;
			}

		}

	}

	if (remainder == 1) {
		res->add(new ListNode(1));
	}


	return res;


}


int main() {

	ListNode *l1 = new ListNode(2);
	l1->add(new ListNode(4));
	l1->add(new ListNode(3));

	ListNode *l2 = new ListNode(5);
	l2->add(new ListNode(6));
	l2->add(new ListNode(4));

	cout << "l1: ";
	listNodes(l1);
	cout << "l2: ";
	listNodes(l2);


	ListNode *sumOfLists = sumLists(l1, l2);
	cout << "sum: ";
	listNodes(sumOfLists);

}




