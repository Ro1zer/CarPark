#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Transport.h"

class CarPark {
private:
	/*��������� ������ �������*/
	std::vector<std::shared_ptr<TransportVehicle>> park;
public:
	CarPark(){}
	/*�������, ��� ���� ��'���(���� ����) �� ������� �����*/
	void add(std::shared_ptr<TransportVehicle> obj){//������������� TransportVehicle ����� �� �� �� � �����������
		//������ �� ������� ����
		park.push_back(obj);
		std::cout << "Object add to park..." << std::endl;
	}
	/*�������,��� ���� ��'��� �� ���� ������� ������� (SM), � �������*/
	std::shared_ptr<TransportVehicle> search(std::string SM) {
		auto it = std::find_if(park.begin(), park.end(), [&SM](std::shared_ptr<TransportVehicle> vehicle) {
			return vehicle->getSM() == SM;
			});
		if (it != park.end()) {
			return *it;
		}
		return nullptr;
	}
	/*������� ��������� ������ � ���������*/
	void del(std::shared_ptr<TransportVehicle> obj) {
		auto it = std::find(park.begin(), park.end(),obj );
		if (it != park.end()) {
			std::cout << "Object delete from park..." << std::endl;
			park.erase(it);

		}
		
	}
	~CarPark(){std::cout<<"Park destructor is working..."<<std::endl; }
};