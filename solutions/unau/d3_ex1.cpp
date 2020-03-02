
#include <iostream>
#include <string>

using namespace std;


enum Month {
	january,
	february,
	march,
	april,
	may,
	june,
	july,
	august,
	september,
	october,
	november,
	december
};

struct Date {
	Month month;
	int year;
};

struct Address {
	string city;
	string	street;
	unsigned int building_num;
};

struct Apt {
	float size;
	unsigned int room_num;
	unsigned int floor;
	double price;
	string apt_owner;

};

struct Building
{
	string name;
	string building_owner;
	Address address;
	Date date;
	unsigned int floor_num;
	unsigned int maxNofAparts = 0;

	void addApartment(const Apt& apart) {
		//выделяет память для максмиального количества квартир(если первая квартира),
		//	добавляет квартиру в здание
		if (app_num == 0) apartments = new Apt[maxNofAparts];
		if (app_num <= maxNofAparts) {
			apartments[app_num] = apart;
			app_num++;
		}
	}

	Apt* getApartment(unsigned int number) const {
		//возвращает указатель на квартиру по номеру в доме
		if (number > 0 && number <= app_num) {
			return apartments + number - 1;
		}
		return nullptr;
	}

	unsigned int getNofApartments(void) const {
		//возвращает количество квартир в доме
		return app_num;
	}

	double getBuildingPrice(void) const {
		double building_price = 0;
		for (int i = 0; i < app_num; i++) {
			building_price += apartments[i].price;
		}
		return building_price;
	}

	void clearApartments(void) {
		delete[] apartments;
		app_num = 0;
		apartments = nullptr;
		//удаляет все квартиры(освобождает память)
	}

private:
	Apt * apartments;
	unsigned int app_num = 0;
};

void showBuilding(const Building& building) {
	cout << "Name: " << building.name << endl;
	cout << "Building owner: " << building.building_owner << endl;
	cout << "Address: " << building.address.street << " " << building.address.building_num <<", " << building.address.city << endl;
	cout << "Build date: " << building.date.month + 1 << " " << building.date.year << endl;
	cout << "Floors number: " << building.floor_num << endl;
	cout << "Apts number: " << building.getNofApartments() << endl;
	cout << "Apts:" << endl;
	for (int i = 1; i <= building.getNofApartments(); i++) {
		cout << "\tNumber: " << i << endl 
			<< "\tFloor: " << building.getApartment(i)->floor << endl
			<< "\tApts owner: " << building.getApartment(i)->apt_owner << endl
			<< "\tSize: " << building.getApartment(i)->size << endl
			<< "\tRooms: " << building.getApartment(i)->room_num << endl
			<< "\tPrice: " << building.getApartment(i)->price << endl << endl;
	}
}
int main()
{
	Building building;
	building.name = "unau apts";
	building.building_owner = "unau";
	building.address.city = "Brest";
	building.address.street = "Moskovskaya";
	building.address.building_num = 332;
	building.date = { june, 1994 };            
	building.floor_num = 3;
	building.maxNofAparts = 3;

	building.addApartment({ 32,2,1,62000,"arty" }); 
	building.addApartment({ 31,1,1,60000,"vkry" });
	building.addApartment({ 78,4,2,150000,"xame" });

	showBuilding(building);
	cout << "Total building price is: " << building.getBuildingPrice() << endl;

	building.clearApartments();
	cout << "Total building price is: " << building.getBuildingPrice() << endl;
	showBuilding(building);

	return 0;

}

