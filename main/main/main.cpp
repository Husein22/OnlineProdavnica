#include <iostream>
#include<vector>
#include "Laptop.h"
#include<iomanip>
using namespace std;
vector<Laptop>laptopi;


void unosLaptopa() {
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	cin >> *temp;
	laptopi.push_back(*temp);
	cout << "Uspjesno smjesten laptop u vektor\n";
}
void ispisLaptopa() {
	cout<< "-----------------------------------------------------------------------------------------------------------------------------\n";
	cout << std::left << std::setw(15) << "Proizvodjac:" << std::left << std::setw(10) << "Model: " << std::left << std::setw(10) << "Kolièina:" <<
		std::left << std::setw(20) << "Godina proizvodnje: " << std::left << std::setw(15) << "Cijena(KM) :" << std::left << std::setw(10)
		<< std::left << std::setw(10) << "CPU" << std::left << std::setw(10) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(10) <<
		"RAM(GB): " << std::left << std::setw(10) << "HDD||SDD: \n";
	cout << "------------------------------------------------------------------------------------------------------------------------------\n";
	for (auto& i : laptopi) {
		cout << i;
	}
}
int main()
{
	unosLaptopa();
	ispisLaptopa();
}
