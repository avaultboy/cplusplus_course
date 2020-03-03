/*
 * day_4_2.cpp
 *
 *  Created on: Mar 3, 2020
 *      Author: vkry
 */

#include <iostream>



using namespace std;


int main() {
	string in = "pwwkew";
	string longest;
	longest.clear();
	string tmp;
	tmp.clear();

	for (unsigned int i = 0; i < in.size(); i++) {
		char c = in.at(i);
		if (tmp.find(c) > tmp.size()){
			tmp += c;
		} else {

			int firstINd = in.find(c);
			string sub = in.substr(firstINd + 1, i - firstINd - 1);

			while (sub.find(c) <= sub.size()) {
				firstINd = sub.find(c);
				sub = sub.substr(firstINd + 1);
			}
			sub += c;
			tmp = sub;

		}
		if (tmp.size() > longest.size()) {
			longest = tmp;
		}
//		cout << "tmp: " << tmp << " long: " << longest << endl;
	}

	cout << "longest substring: " << longest << endl;
	cout << "length of the longest substring: " << longest.size() << endl;
}


