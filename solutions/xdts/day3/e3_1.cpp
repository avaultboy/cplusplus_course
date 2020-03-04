#include <iostream>
#include  <string>

using namespace std;

struct Apartment {
    float square;
    unsigned int roomNum;
    unsigned int floor;
    double price;
    string owner;
};

struct Address {
    string city;
    string street;
    unsigned int buildNumber;
};

enum Months  {
        January, February, March, April, May, June,
        July, August,September,October, November, December
};

struct BuildData {
    Months month;
    int year;
};

string MonthName[12] = {"January", "February", "March", "April", "May", "June", "July", "September", "October", "November", "December"};

struct Building {
   
private: 
     unsigned int nOfAparts = 0;
     Apartment* apartments;

public:
    string name;
    string owner;
    Address address;
    BuildData data;
    unsigned int  floorNumber;
    unsigned int maxNofAparts = 100;
    
    void addApartment(const Apartment& apartment) {
        if (nOfAparts == 0) {
            apartments = new  Apartment[maxNofAparts];
         }
         ++nOfAparts;
        apartments[nOfAparts] = apartment;
    };
    
    Apartment* getApartment(unsigned int number) const {
        if (nOfAparts > 0)  {
            return &apartments[number];
        }
        return nullptr;
    };
    
    unsigned int getNofApartments(void) const {
        return nOfAparts;
    };
    
    double getBuildingPrice(void) const {
        double tprice = 0;
        for (unsigned int i =1;  i <= nOfAparts;  i++ )  {
            tprice += apartments[i].price;
        }
        return tprice;
    }
    
    void clearApartments(void) {
        delete [] apartments;
        nOfAparts = 0;
    }
};

void showBuilding(const Building& building) {
    int numOfAparts = building.getNofApartments();
    
    cout << "Name: " << building.name << endl;
    cout << "Owner: " << building.owner << endl;
    cout << "Address: " << building.address.street << " " <<   building.address.buildNumber << " , " << building.address.city << endl;
    cout << "Building date:  " <<  MonthName[building.data.month] <<  " , " <<  building.data.year << endl;
    cout << "Floors number: " <<  building.floorNumber << endl;
     cout << "Total price: " <<  building.getBuildingPrice() << endl;
    if (numOfAparts  > 0) {
       cout << "Apartments number: " << building.getNofApartments() << endl;
       cout << "Apartments details:"  << endl;
       for (int i = 1; i <= numOfAparts; ++i) {
           Apartment *current = building.getApartment(i);
           cout << "------------------------------------------------------------"<< endl;
           cout << "Number: " <<  i << endl;
           cout << "Floor: " << current->floor << endl;
           cout << "Owner:" << current->owner << endl;
           cout << "Size: " << current->square << " m2" << endl;
           cout << "Rooms:" << current->roomNum << endl;
           cout << "Price: " << current->price << endl;
       }
       cout << "------------------------------------------------------------"<< endl;
    }
}

int main()
{
    Apartment kv1 = {40.5,3,1,10000.0,"Sidoroff"};
    Apartment kv2 = {55.5,4,1,20000.0,"Ivanoff"};
    Apartment kv3 = {25.5,2,2,8000.0,"Petroff"};
    
    Address domAdr = {"Brest","Puchkin St",13};
    
    BuildData domDate = {May,1881};
    
    Building dom;
    
    dom.name = "Halupa";
    dom.owner = "Gogol";
    dom.address = domAdr;
    dom.data = domDate;
    dom.floorNumber = 2;
    
    
    dom.addApartment(kv1);
    dom.addApartment(kv2);
    dom.addApartment(kv3);
    
    showBuilding(dom);
    
    dom.clearApartments();
   
    return 0;
}