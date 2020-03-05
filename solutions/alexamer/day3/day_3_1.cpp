//============================================================================
// Name        : day_3_1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


struct Address
{
    string city;
    string street;
    unsigned int building;
};

enum Month {
    NONE, JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
};

struct Date
{
    Month month;
    int yaer;
};

struct Apartment
{
    int square;
    int num_rooms;
    int floor;
    int price;
    string owner;
};

struct Building
{
	string name;
    string owner;
    Address address;
    Date date;
    int num_floors;
    unsigned int num_aparts = 0;
private:
	Apartment* apartments = nullptr;
	unsigned int maxNofAparts;
public:

	Building(unsigned int maxN) {
		maxNofAparts = maxN;
	}

	void addApartment(const Apartment& apart) {
		if (apartments == nullptr) {
			apartments = new Apartment[maxNofAparts];
		}
		if (num_aparts < maxNofAparts) {
			apartments[num_aparts] = apart;
			num_aparts++;
		}
	}

	Apartment* getApartment(unsigned int number) const {
		if (number <= maxNofAparts) {
			return apartments + number;
		}
		return nullptr;
	}

	unsigned int getNofApartments(void) const {
		return this->num_aparts;
	}

	double getBuildingPrice(void) const {
		double _price = 0;
		for (unsigned int i = 1; i < num_aparts; i++) {
			_price += apartments[i].price;
		}
		return _price;
	}

	void clearApartment(void) {
		delete [] apartments;
		apartments = nullptr;
		num_aparts = 0;
	}
};

const char* getMounth(Month m) {
	switch (m) {
	case JAN : return "������";
	case FEB : return "�������";
	case MAR : return "����";
	case APR : return "������";
	case MAY : return "���";
	case JUN : return "����";
	case JUL : return "����";
	case AUG : return "������";
	case SEP : return "��������";
	case OCT : return "�������";
	case NOV : return "������";
	case DEC : return "�������";
	case NONE : return "";
	}
	return "";
}

void showBuilding(const Building& building) {
	cout << "��������:\t\t" << building.name << endl;
	cout << "��������:\t\t" << building.owner << endl;
	cout << "�����:\t\t\t�. " << building.address.city << ", " << building.address.street << " " << building.address.building << endl;
	cout << "���� ���������:\t\t" << getMounth(building.date.month) << " " << building.date.yaer << endl;
	cout << "���������� ������:\t" << building.num_floors << endl;
	cout << "���������� �������:\t" << building.num_aparts << endl;
	cout << "��������:" << endl;
	for (unsigned int i = 0; i < building.num_aparts; i++) {
		cout << "\t�����:\t\t" << i+1 << endl;
		cout << "\t����:\t\t" << building.getApartment(i)->floor << endl;
		cout << "\t��������:\t" << building.getApartment(i)->owner << endl;
		cout << "\t�������:\t" << building.getApartment(i)->square << endl;
		cout << "\t������:\t\t" << building.getApartment(i)->num_rooms << endl;
		cout << "\t���������:\t" << building.getApartment(i)->price << endl << endl;
	}
}

int main() {

	Building building1(50);

	building1.name = "����� ������";
	building1.owner = "������� ����������";
	building1.address.city = "�������";
	building1.address.street = "������������";
	building1.address.building = 13;
	building1.date.yaer = 1999;
	building1.date.month = FEB;
	building1.num_floors = 4;
	building1.addApartment({48,4,2,51500,"������"}); //number, square, num_rooms, floor, price, owner
	building1.addApartment({49,3,4,52500,"������"});
	building1.addApartment({100,6,1,151500,"�������"});
	building1.addApartment({203,26,1,1515000,"��������"});


	Building building2(6);

	building2.name = "����� ������";
	building2.owner = "����� ����";
	building2.address.city = "���������";
	building2.address.street = "����������";
	building2.address.building = 99;
	building2.date.yaer = 2020;
	building2.date.month = MAR;
	building2.num_floors = 298;
	building2.addApartment({48,4,2,51500,"������"});
	building2.addApartment({49,3,4,52500,"������"});
	building2.addApartment({101,16,1,151500,"�������"});
	building2.addApartment({203,26,1,1515000,"��������"});
	building2.addApartment({305,36,1,15150000,"��������"});

	showBuilding(building1);
	showBuilding(building2);

	building1.clearApartment();
	building2.clearApartment();
	return 0;
}
