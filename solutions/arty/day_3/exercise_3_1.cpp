// exercise_3_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

struct Address
{
	std::string  city = "";
	std::string  street = "";
	unsigned int buildingNumber = 0;

	Address(std::string city, std::string street, unsigned int buildingNumber) {
		this->city = city;
		this->street = street;
		this->buildingNumber = buildingNumber;
	}
};

enum Month : int{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};


const std::map <Month, std::string> monthTranslate
{
	{January, "������"},
	{February, "�������"},
	{March, "����"},
	{April, "������"},
	{May, "���"},
	{June, "����"},
	{July, "����"},
	{August, "������"},
	{September, "��������"},
	{October, "�������"},
	{November, "������"},
	{December, "�������"}
};


struct Date
{
	Month month;
	unsigned int year = 0;

	Date(Month month, unsigned int year) {
		this->month = month;
		this->year = year;
	}
};




std::string _GetMonths(Month month) {
	return monthTranslate.find(month)->second;
}

struct Apartment
{
	unsigned int size = 0;
	unsigned int numberOfRooms = 0;
	unsigned int floor = 0;
	unsigned int price = 0;
	std::string owner = "";

	Apartment() {};

	Apartment(
		unsigned int size, unsigned int numberOfRooms, unsigned int floor, unsigned int price, std::string owner
	)
	{
		this->size = size;
		this->numberOfRooms = numberOfRooms;
		this->floor = floor;
		this->price = price;
		this->owner = owner;
	}
};


struct Building
{
	std::string name = "";
	std::string owner = "";
	const Address * address = nullptr;
	const Date * dateOfConstruction = nullptr;
	unsigned int numberOfFloors = 0;
	unsigned int numberOfApartments = 0; // current busy
	unsigned int maxNumberOfApartments = 0;

	Building(
			std::string name,
			std::string owner,
			Address *_address,
			Date * _dateOfConstruction,
			unsigned int numberOfFloors,
			unsigned int maxNumberOfApartments
		):	
		address(_address), 
		dateOfConstruction(_dateOfConstruction)
	{
		this->name = name;
		this->owner = owner;
		this->numberOfFloors = numberOfFloors;
		this->maxNumberOfApartments = maxNumberOfApartments;
	}

	void addApartment(const Apartment& apart) {
		if (numberOfApartments < (maxNumberOfApartments)) {
			if (apartments == nullptr) {
				apartments = new Apartment[maxNumberOfApartments];
			}
			apartments[numberOfApartments] = apart;
			numberOfApartments++;
		}
	}

	Apartment* getApartment(unsigned int apartmentNumber) const {
		if (apartmentNumber > 0 and apartmentNumber <= this->numberOfApartments){
			return &this->apartments[apartmentNumber-1];
		}
		else {
			return nullptr;
		}
	}

	unsigned int getNumberOfApartments(void) const {
		return this->numberOfApartments;
	}

	double getBuildingPrice(void) const {
		
		double priceSum = 0;
		
		for (unsigned int c_apart = 0; c_apart < this->numberOfApartments; c_apart ++) {
			priceSum += apartments[c_apart].price;
		}

		return priceSum;
	}

	void clearApartments(void) {
		delete[] apartments;
		numberOfApartments = 0;
	}

private:
	Apartment* apartments = nullptr;
};

void showBuilding(const Building& building) {
	std::cout << "��������: " << building.name << std::endl;
	std::cout << "��������: " << building.owner << std::endl;
	std::cout << "�����: " << building.address->street << " " << building.address->buildingNumber << ", " << building.address->city << std::endl;
	std::cout << "���� ���������: " << _GetMonths(building.dateOfConstruction->month) << " " << building.dateOfConstruction->year << std::endl;
	std::cout << "���������� ������: " << building.numberOfFloors << std::endl;
	std::cout << "���������� �������: " << building.numberOfApartments << std::endl;
	std::cout << "��������:" << std::endl;
	for (unsigned int apart = 1; apart <= building.numberOfApartments; apart++) {
		std::cout << "\t����� ��������: " << apart << std::endl;
		std::cout << "\t����: " << building.getApartment(apart)->floor << std::endl;
		std::cout << "\t��������: " << building.getApartment(apart)->owner << std::endl;
		std::cout << "\t������: " << building.getApartment(apart)->size << std::endl;
		std::cout << "\t���������� ������: " << building.getApartment(apart)->numberOfRooms << std::endl;
		std::cout << "\t���������: " << building.getApartment(apart)->price << std::endl;
		std::cout << std::endl;
	}
}





int main()
{
	setlocale(LC_ALL, "Russian");
	Building firstBuilding =
		Building(
			"������",
			"�������",
			new Address(std::string("�����"), std::string("��������"), 12),
			new Date(August, 2001),
			2,
			4);

	firstBuilding.addApartment({ 35, 1, 1, 45000, "�������" });
	firstBuilding.addApartment({ 45, 1, 1, 75000, "�������" });
	firstBuilding.addApartment({ 40, 1, 1, 65000, "����������" });
	firstBuilding.addApartment({ 120, 3, 2, 90000, "������" });


	Building secondBuilding = 
		Building("������ ���", "������", new Address(std::string("�����"), std::string("���������"), '78�'), new Date(March, 2020), 2, 2);

	secondBuilding.addApartment(Apartment(60, 2, 1, 80000, "������"));
	secondBuilding.addApartment(Apartment(80, 2, 1, 75000, "�������"));

	std::cout << "������ ������:" << std::endl;
	showBuilding(firstBuilding);

	std::cout << "������ ������:" << std::endl;
	showBuilding(secondBuilding);
}
