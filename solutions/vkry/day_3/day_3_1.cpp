#include <iostream>

using namespace std;


enum e_month {
	january,
	february,
	march,
	april,
	may,
	june,
	july,
	september,
	october,
	november,
	december
};

const string MONTH[] = {"January", "February", "March", "April", "May", "June", "July", "September", "October", "November", "December"};

struct Apartment {
	float square;
	int roomNumber;
	int floor;
	float price;
	string appartmentOwner;
};

struct Address {
	string city;
	string street;
	int buildingNumber;
};

struct Date {
	e_month month;
	int year;
};


struct Building {
	string buildingName;
	string buildingOwner;
	Address address;
	Date built;
	int floors;
//	int numberOfAppartments;

private:
	int maxNofAparts = 50;
	Apartment *apartments;
	int numberOfAppartments = -1;

public:
	void addApartment(const Apartment &apartment){
		if (numberOfAppartments < 0){
			apartments = new Apartment[maxNofAparts];
			numberOfAppartments++;
		}
		apartments[numberOfAppartments] = apartment;
		numberOfAppartments++;
	}

	Apartment* getApartment(unsigned int number) const {
		if (numberOfAppartments > 0 && number > 0) {
			return &apartments[number - 1];
		} else {
			return nullptr;
		}
	}

	unsigned int getNofApartments(void) const {
		return numberOfAppartments;
	}

	double getBuildingPrice(void) const {
		double price = 0;

		for (int i = 0; i < numberOfAppartments - 1; i++) {
			price += apartments[i].price;
		}
		return price;
	}

	void clearApartments(void) {
		delete[] apartments;
		apartments = NULL;
		numberOfAppartments = -1;
	}

};

void showBuilding(const Building &building) {
	int numOfApts = building.getNofApartments();
	if(numOfApts == -1) {
		numOfApts = 0;
	}

	cout << "Название: " << building.buildingName << endl;
	cout << "Владелец: " << building.buildingOwner << endl;
	cout << "Адрес: " << building.address.street << " " << building.address.buildingNumber << ", " << building.address.city << endl;
	cout << "Дата постройки: " << MONTH[building.built.month] << " " << building.built.year << endl;
	cout << "Количество этажей: " << building.floors << endl;
	cout << "Количество квартир: " << numOfApts << endl;
	cout << "Квартиры:" << endl;

	for (int i = 1; i <= numOfApts; i++){
		Apartment *ap = building.getApartment(i);
		cout << "\tНомер: " << i << endl;
		cout << "\tЭтаж: " << ap->floor << endl;
		cout << "\tВладелец: " << ap->appartmentOwner << endl;
		cout << "\tРазмер: " << ap->square << endl;
		cout << "\tКомнат: " << ap->roomNumber << endl;
		cout << "\tСтоимость: " << ap->price << endl;
		cout << endl;
	}

}


int main()
{
	Apartment apart1;
	apart1.square = 110.0;
	apart1.roomNumber = 5;
	apart1.price = 122310.0;
	apart1.floor = 1;
	apart1.appartmentOwner = "appartmentOwner1";

	Apartment apart2;
	apart2.square = 40.0;
	apart2.roomNumber = 1;
	apart2.price = 5645.0;
	apart2.floor = 2;
	apart2.appartmentOwner = "appartmentOwner2";

	Address address;
	address.street = "streetForTheBuilding";
	address.buildingNumber = 13;
	address.city = "Brest";

	Date dateBuilt;
	dateBuilt.month = e_month::march;
	dateBuilt.year = 1917;

	Building building;
	building.buildingName = "newBuilding";
	building.buildingOwner = "buildingOwner";
	building.address = address;
	building.built = dateBuilt;
	building.floors = 3;

	building.addApartment(apart1);
	building.addApartment(apart2);

	showBuilding(building);

	building.clearApartments();

	showBuilding(building);


}
