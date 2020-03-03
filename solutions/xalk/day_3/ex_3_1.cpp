
#include <iostream>

using namespace std;

struct Address {
    Address() : city(""), street(""), buildNo(0) {}
    Address(char* city, char* street, unsigned short buildNo) {
        this->city = city;
        this->street = street;
        this->buildNo = buildNo;
    }
    char* city;
    char* street;
    unsigned short buildNo;
};

enum Month {January=1, February, March, April, May, June, July, August, September, October, November, December};
const char* monthNames[13] = {
       "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
};

struct Date {
    Date() : month(Month::January), year(1970) {}
    Month month;
    unsigned short year;
};

struct Apartment {
    Apartment() : size(0), nofRooms(0), level(0), price(0.0), owner("") {}
    unsigned short size;
    unsigned short nofRooms;
    unsigned short level;
    double price;
    char* owner;
};

struct Building {
    Building(int maxNofApartments) : name(""), owner(""), nofApartments(0), nofLevels(1) {
        this->maxNofApartments = maxNofApartments;
    }
    char* name;
    char* owner;
    Address address;
    Date dateBuilt;
    unsigned short nofLevels;
private:
    unsigned short nofApartments;
    unsigned short maxNofApartments;
    Apartment* apartments;

public:
    void addApartment(const Apartment& apart);
    Apartment* getApartment(unsigned int number) const;
    unsigned int getNofApartments(void) const;
    double getBuildingPrice(void) const;
    void clearApartments(void);
};

void Building::addApartment(const Apartment& apart)
{
    if (this->nofApartments == 0) {
        apartments = new Apartment[this->maxNofApartments];
    }
    if (nofApartments <= maxNofApartments) {
        this->apartments[nofApartments++] = apart;
    }
}

Apartment* Building::getApartment(unsigned int number) const {
    if (number <= nofApartments) {
        return &apartments[number-1];
    }
}

unsigned int Building::getNofApartments(void) const
{
    return nofApartments;
}

double Building::getBuildingPrice(void) const {
    double result = 0.0;
    for(int i=0; i<nofApartments; i++){
        result += apartments[i].price;
    }
    return result;
}

void Building::clearApartments(void) {
    delete [] apartments;
    nofApartments = 0;
}

void showBuilding(const Building& building) {
    unsigned short nofApartments;
    Apartment* ap;
    cout << "Name: " << building.name << endl;
    cout << "Owner: " << building.owner << endl;
    cout << "Address: " << building.address.street << ' ' << building.address.buildNo << ", " << building.address.city << endl;
    cout << "Built on: " << monthNames[building.dateBuilt.month] << ' ' << building.dateBuilt.year << endl;
    cout << "NofLevels: " << building.nofLevels << endl;
    nofApartments = building.getNofApartments();
    cout << "NofApartments: " << nofApartments << endl;
    if (nofApartments > 0) {
        cout << "Apartments:" << endl;
        for (int i = 0; i < nofApartments; i++){
            ap = building.getApartment(i+1);
            cout << '\t' << "ApNo: " << i+1 << endl;
            cout << '\t' << "Level: " << ap->level << endl;
            cout << '\t' << "Owner: " << ap->owner << endl;
            cout << '\t' << "Size: " << ap->size << endl;
            cout << '\t' << "Rooms: " << ap->nofRooms << endl;
            cout << '\t' << "Price: " << ap->price << endl << endl;
        }
    }
}

int main() {

    Building house(15);
    house.name = "NoName";
    house.owner = "JSPK GigabyteMinus";
    house.address = Address("Brest", "Kolesnika", 7);

    Apartment ap1;
    Apartment ap2;
    Apartment ap3;

    ap1.level = 1;
    ap1.nofRooms = 4;
    ap1.owner = "Pushkin";
    ap1.size = 130;
    ap1.price = 10000;

    ap2.level = 1;
    ap2.nofRooms = 4;
    ap2.owner = "Pushkin";
    ap2.size = 130;
    ap2.price = 20000;

    ap3.level = 1;
    ap3.nofRooms = 4;
    ap3.owner = "Pushkin";
    ap3.size = 130;
    ap3.price = 30000;

    house.addApartment(ap1); house.addApartment(ap2); house.addApartment(ap3);

    showBuilding(house);

    cout << "Total price: " << house.getBuildingPrice() << endl;

    return 0;
}
