#include <iostream>
//#include <climits>
#include <algorithm>
//#include <string>

using namespace std;

int toInt(string s);

int main() {

	int input;
	string tmp;

	cout << "enter number: ";
	cin >>  input;

	tmp = to_string(input);
	if (tmp.at(0) == '-'){
		tmp = tmp.substr(1);
		reverse(tmp.begin(), tmp.end());
		tmp = "-" + tmp;

		cout << toInt(tmp);

	} else {
		reverse(tmp.begin(), tmp.end());
		cout << toInt(tmp);
	}
}

int toInt(string s){
	try {
		return stoi(s);
	} catch (const out_of_range &e) {
		return 0;
	}
}
