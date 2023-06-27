#include <iostream>
#include "CarPark.h"
#include"Transport.h"

int main() {
	
	setlocale(0, "");

	auto myCar = std::make_shared<Car>("Mersedes", "MV3", 2003, 200.0, 4, "Gas", "STRV0054");
	auto myTruck = std::make_shared<Truck>("Volvo", "TRV500", 1995, 1000.0, 500.50, "bigger", "STRV0054");
	CarPark park;
	park.add(myCar);
	park.add(myTruck);

	myCar->getAll();
	myTruck->getAll();
	
	auto _myCar = park.search("STRV0054");
	myCar->getAll();
	myTruck->getAll();
	

	park.del(myCar);
	park.del(myTruck);
	return 0;
}


