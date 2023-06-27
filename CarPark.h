#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Transport.h"

class CarPark {
private:
	/*Створюємо вектор поінтерів*/
	std::vector<std::shared_ptr<TransportVehicle>> park;
public:
	CarPark(){}
	/*Функція, яка додає об'єкт(його поінт) до вектору парку*/
	void add(std::shared_ptr<TransportVehicle> obj){//Використовуємо TransportVehicle через те що він є батьківський
		//Пушимо до вектору поінт
		park.push_back(obj);
		std::cout << "Object add to park..." << std::endl;
	}
	/*Функція,яка шукає об'єкт за його серійним номером (SM), і повертає*/
	std::shared_ptr<TransportVehicle> search(std::string SM) {
		auto it = std::find_if(park.begin(), park.end(), [&SM](std::shared_ptr<TransportVehicle> vehicle) {
			return vehicle->getSM() == SM;
			});
		if (it != park.end()) {
			return *it;
		}
		return nullptr;
	}
	/*Функція видалення машини з автопарку*/
	void del(std::shared_ptr<TransportVehicle> obj) {
		auto it = std::find(park.begin(), park.end(),obj );
		if (it != park.end()) {
			std::cout << "Object delete from park..." << std::endl;
			park.erase(it);

		}
		
	}
	~CarPark(){std::cout<<"Park destructor is working..."<<std::endl; }
};