/*
 * day_4_1.cpp
 *
 *  Created on: Mar 2, 2020
 *      Author: vkry
 */

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <chrono>



using namespace std;

int main() {
	ifstream fileStream("D:\\Eclipse\\cppCourse\\cplusplus_course\\exercises\\day_4\\names.txt");
	string word;
	word.clear();
	char ch;
	list<string> sl;
	long long sumOfNames = 0;

	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//	auto start = chrono::high_resolution_clock::now();

	if (!fileStream.is_open()) {
		cerr << "couldn't open the file" << endl;
		return 1;
	}

	while (fileStream >> ch){

		while (ch != '"' && ch != ','){
			word = word + ch;
			ch = fileStream.get();
		}

		if (!word.empty()) {
			sl.push_back(word);
			word.clear();
		}

	}

	sl.sort();
	int count = 1;
	for (string s : sl) {
		int name = 0;
		for (char c : s) {
			name += alphabet.find(c) + 1;
		}
		name *= count;
		sumOfNames += name;
		count++;
	}

//	auto stop = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

//	cout << "size: " << sv.size() << endl;
	cout << "total score: " << sumOfNames << endl;
//	cout << "time: " << duration.count() << endl;


	cout << "End program";
	return 0;
}


//int main() {
//	ifstream fileStream("D:\\Eclipse\\cppCourse\\cplusplus_course\\exercises\\day_4\\names.txt");
//	string word;
//	word.clear();
//	char ch;
//	map<string, int> sm;
//	long long totalSumOfNames = 0;
//
//	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//
//	auto start = chrono::high_resolution_clock::now();
//
//	if (!fileStream.is_open()) {
//		cerr << "couldn't open the file" << endl;
//		return 1;
//	}
//
//
//	while (fileStream >> ch){
//		int nameSum = 0;
//		while (ch != '"' && ch != ','){
//			word = word + ch;
//			nameSum += alphabet.find(ch) + 1;
//			ch = fileStream.get();
//		}
//
//		if (!word.empty()) {
//			sm.insert(pair<string, int>(word, nameSum));
//			word.clear();
//		}
//
//	}
//
//	int count = 1;
//	for (pair<string, int> p : sm) {
//		totalSumOfNames += (p.second * count);
//		count++;
//	}
//
//	auto stop = chrono::high_resolution_clock::now();
//	auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
//
//	cout << "size: " << sm.size() << endl;
//	cout << "total score: " << totalSumOfNames << endl;
//	cout << "time: " << duration.count() << endl;
//
//
//	cout << "End program";
//	return 0;
//}
