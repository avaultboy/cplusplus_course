/*
 * day_4_3.cpp
 *
 *  Created on: Mar 3, 2020
 *      Author: vkry
 */

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


int main() {

	vector<int> v1 = {1, 2};
	vector<int> v2 = {3, 4};
	int resSize = v1.size() + v2.size();
	vector<int> res(resSize);
	float median = 0.0;

	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), res.begin());

	if (res.size() % 2 == 0) {
		int middle1 = res.at(res.size() / 2);
		int middle2 = res.at((res.size() / 2) - 1);

		median = static_cast<float>(middle1 + middle2) / 2;
	} else {
		median = res.at((res.size() - 1) / 2);
	}

	cout << "resulted vector: ";
	for (int i : res) {
		cout << i << " ";
	}

	cout << "\nmedian: " << median;

}

