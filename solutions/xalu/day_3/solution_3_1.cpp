#include <iostream>

using namespace std;

typedef unsigned int uint;

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

const char* getMonth(Month m) {
   switch (m) {
      case january   : return "Январь";
      case february  : return "Февраль";
      case march     : return "Март";
      case april     : return "Апрель";
      case may       : return "Май";
      case june      : return "Июнь";
      case july      : return "Июль";
      case august    : return "Август";
      case september : return "Сентябрь";
      case october   : return "Октябрь";
      case november  : return "Ноябрь";
      case december  : return "Декабрь";
   }
   return "";
}
struct Date {
   Month month;
   uint year;
};

struct Address {
   const char* city;
   const char* street;
   uint number;
};

struct Apartment {
   uint size;
   uint nofRooms;
   uint floor;
   double price;
   const char* owner;
};

struct Building {
   const char* name;
   const char* owner;
   Address address;
   Date date;
   uint nofFloors;
   uint maxNofAparts = 0;

   double getBuildingPrice(void) const {
      double building_price;
      for (uint i = 0; i < nofApartments; ++i) {
         building_price += apartments[i].price;
      }
      return building_price;
   };
   void addApartment(const Apartment& apart) {
      if (apartments == nullptr) {
         apartments = new Apartment[maxNofAparts];
      }
      if (nofApartments < maxNofAparts) {
         apartments[nofApartments] = apart;
         ++nofApartments;
      }
   }
   Apartment* getAppartment(uint number) const {
      if (number > 0 and number <= nofApartments) {
         return apartments + number-1;
      }
      return nullptr;
   }
   uint getNofApartments(void) const {
      return nofApartments;
   }
   void clearApartments(void) {
      delete [] apartments;
      apartments = nullptr;
      nofApartments = 0;
   }
private:
   uint nofApartments = 0;
   Apartment* apartments = nullptr;
};

void showBuilding(const Building& building) {
   cout << "Название: " << building.name << endl;
   cout << "Владелец: " << building.owner << endl;
   cout << "Адрес: " << building.address.street
              << " " << building.address.number
              << ", "<< building.address.city << endl;
   cout << "Дата постройки: " << getMonth(building.date.month)
                       << " " << building.date.year << endl;
   cout << "Количество этажей: "  << building.nofFloors << endl;
   cout << "Количество квартир: " << building.getNofApartments() << endl;
   cout << "Квартиры:" << endl;
   for (uint i = 1; i <= building.getNofApartments(); ++i) {
      cout << "\tНомер: "     << i << endl
           << "\tЭтаж: "      << building.getAppartment(i)->floor << endl
           << "\tВладелец: "  << building.getAppartment(i)->owner << endl
           << "\tРазмер: "    << building.getAppartment(i)->size << endl
           << "\tКомнат: "    << building.getAppartment(i)->nofRooms << endl
           << "\tСтоимость: " << building.getAppartment(i)->price << endl << endl;
   }
}

int main() {
   Building building, building2;

   building.name = "Апартаменты Иванова";
   building.owner = "Иванов";
   building.address.city = "Брест";
   building.address.street = "Московская";
   building.address.number = 326;
   building.date = {april, 2006};            //date: month, year
   building.nofFloors = 3;
   building.maxNofAparts = 50;

   building.addApartment({54,2,1,34000,"Петров"}); //number, size, nofRoom, floor, price owner
   building.addApartment({31,1,1,25000,"Сидоров"});
   building.addApartment({78,4,2,65000,"Горбатчук"});

   building2.name = "Дом над Бугом";
   building2.owner = "Тучных";
   building2.address.city = "Брест";
   building2.address.street = "Варшавское шоссе";
   building2.address.number = 17;
   building2.date = {october, 2017};            //date: month, year
   building2.nofFloors = 12;
   building2.maxNofAparts = 120;

   building2.addApartment({48,2,1,33000,"Силиванов"}); //number, size, nofRoom, floor, price owner
   building2.addApartment({27,1,1,24500,"Мальцев"});
   building2.addApartment({97,4,2,69000,"Хромой"});
   building2.addApartment({32,1,2,27000,"Пантелеймонов"});
   building2.addApartment({33,2,2,30000,"Хилых"});

   showBuilding(building);
   showBuilding(building2);

   building.clearApartments(); //освобождаем память выделенную для квартир
   building2.clearApartments();
   return 0;
}