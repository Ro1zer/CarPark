#pragma once
#include <iostream>
#include <string>
#include "CarPark.h"
/*Це класс автомобілів,усі вони (автомобілі та грузовки) наслідуються від батьківського класу TransportVehicle)
Взагалом,тут демонструються мої навички використання ООП які я набув тому нічого надзвичайного тут не повинно бути
*/
class TransportVehicle {
protected:
	std::string mark;
	std::string model;
	int yearMade;
	double price;
	std::string SM;
public:
	TransportVehicle(const std::string& t_mark,const std::string& t_model,int t_yearMade,double t_price,const std::string &t_SM){
		setMark(t_mark);
		setModel(t_model);
		setYearMade(t_yearMade);
		setPrice(t_price);
		setSM(t_SM);
	}
	void setMark(const std::string& t_mark) { mark = t_mark; }
	std::string getMark() { return mark; }

	void setModel(const std::string& t_model) { model = t_model; }
	std::string getModel() { return model; }

	void setYearMade(int t_yearMade) { yearMade = t_yearMade; }
	int getYearMade() { return yearMade; }

	void setPrice(double t_price) { price = t_price; }
	double getPrice() { return price; }

	void setSM(const std::string &t_SM) {
		SM = t_SM;
	}
	std::string getSM() {
		return SM;
	}

	virtual void getAll(){
		std::cout <<"\nMark: " << getMark() << std::endl;
		std::cout <<"Model: " << getModel() << std::endl;
		std::cout <<"Year of made: " << getYearMade() << std::endl;
		std::cout << "Price($): " << getPrice() << std::endl;
		std::cout << "Serial model: " << getSM() << std::endl;
	}

	~TransportVehicle() { std::cout << "Father destructor is working..." << std::endl; }
};

class Car :public TransportVehicle {
private:
	int coutDors;
	std::string typeFuel;
public:
	Car(const std::string& t_mark, const std::string& t_model, int t_yearMade, double t_price,int t_countDors,const std::string& t_typeFuel, const std::string& t_SM)
		:TransportVehicle(t_mark, t_model, t_yearMade, t_price,t_SM){
		setCountDours(t_countDors);
		setTypeFuel(t_typeFuel);
	}
	void setCountDours(int t_countDors) { coutDors = t_countDors; }
	int getCountDours() { return coutDors; }

	void setTypeFuel(const std::string& t_typeFuel) { typeFuel = t_typeFuel; }
	std::string getTypeFuel() { return typeFuel; }

	void getAll() override {
		TransportVehicle::getAll();
		std::cout<<"Count of dors: " << getCountDours() << std::endl;
		std::cout<<"Type fuel: " << getTypeFuel() << std::endl;
		std::cout << std::endl;
	}
	~Car() { std::cout << "Car destructor is working..."<<std::endl; }
};

class Truck :public TransportVehicle {
private:
	double maxWeight;
	std::string typeTrailer;
public:
	Truck(const std::string& t_mark, const std::string& t_model, int t_yearMade, double t_price,double t_maxWeigth,const std::string & t_typeTrailer, const std::string& t_SM)
	:TransportVehicle(t_mark, t_model, t_yearMade, t_price,t_SM){
		setMaxWeight(t_maxWeigth);
		setTypeTrailer(t_typeTrailer);
	}
	void setMaxWeight(double t_maxWeigth) { maxWeight = t_maxWeigth; }
	double getMaxWeight() { return maxWeight; }

	void setTypeTrailer(const std::string& t_typeTrailer) { typeTrailer = t_typeTrailer; }
	std::string getTypeTrailer() { return typeTrailer; }

	void getAll() override {
		TransportVehicle::getAll();
		std::cout<<"Maximum weigth(t): " << getMaxWeight() << std::endl;
		std::cout <<"Type trailer: " << getTypeTrailer() << std::endl;
		std::cout << std:: endl;
	}
	~Truck() { std::cout << "Truck destructor is working..." << std::endl; }
};