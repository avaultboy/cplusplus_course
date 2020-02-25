
#include <iostream>

using namespace std;

const int lenghts[]  = {
        0,//none for 0
        3,//one
        3,//two
        5,//three
        4,//four
        4,//five
        3,//six
        5,//seven
        5,//eight
        4,//nine
        3,//ten
        6,//eleven
        6,//twelve
        8,//thirteen
        8,//fourteen
        7,//fifteen
        7,//sixteen
        9,//seventeen
        8,//eighteen
        8,//nineteen
        6,//twenty
        6,//thirty
        5,//forty
        5,//fifty
        5,//sixty
        7,//seventy
        6,//eighty
        6,//ninety
        7,//hundred
        8,//thousand
        3//and
};

const int andIdx = 30;
const int twentyIdx = 20;
const int hundredIdx = 28;
const int thousandIdx = 29;


int lettersCnt(int number){
    int cnt = 0;
    int tens;
    int hundreds;
    int thousands = number / 1000;
    number %= 1000;
    hundreds = number / 100;
    number %= 100;

    if (thousands > 0){
        cnt += lenghts[thousands] + lenghts[thousandIdx];
    }
    if (hundreds > 0){
        cnt += lenghts[hundreds] + lenghts[hundredIdx];
        if (number > 0){
            cnt += lenghts[andIdx];
        }
    }

    if (number > 20) {
        tens = number / 10;
        cnt += lenghts[twentyIdx + tens - 2];
        number %= 10;
        cnt += lenghts[number];
    } else {
        cnt += lenghts[number];
    }

    return cnt;
}


int main() {
	int number;
	cout << "Enter number 0-9999: ";
	cin >> number;
	while (number < 0 || number > 9999) {
	    cout << "Wrong number!" << endl << "Enter number from range 0-1000:";
	    cin >> number;
	}
	cout << "You entered: " << number << endl;
	cout << "Number of letters: " << lettersCnt(number) << endl;
	return 0;
}
