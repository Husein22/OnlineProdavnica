#include <iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include "Laptop.h"

using namespace std;
vector<Laptop>laptopi;

void smjestizaIspis(string n) {
	string temp;
	string ime = n+ ".txt";
	vector<string>lap;
	std::ifstream smjesti(ime);
	if (smjesti.is_open()) {
		getline(smjesti, temp);
		getline(smjesti, temp);
		getline(smjesti, temp);
		while (true) {
			getline(smjesti, temp);
			if (smjesti.eof())break;
			lap.emplace_back(temp);
		}
		smjesti.close();
	}
	else {
		cout << "Neuspjelo otvaranje datoteke\n";
	}
	for (auto& i : lap) {
		cout << i;
		cout << endl;
	}
}
void unosLaptopa() {
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	cin >> *temp;
	//laptopi.push_back(*temp);
	cout << "Uspjesno smjesten laptop u datoteku\n";
}
void ispisLaptopa() {
	cout<< "-----------------------------------------------------------------------------------------------------------------------------\n";
	cout << std::left << std::setw(15) << "Proizvodjac:" << std::left << std::setw(10) << "Model: " << std::left << std::setw(10) << "Koli�ina:" <<
		std::left << std::setw(20) << "Godina proizvodnje: " << std::left << std::setw(15) << "Cijena(KM) :" << std::left << std::setw(10)
		<< std::left << std::setw(10) << "CPU" << std::left << std::setw(10) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(10) <<
		"RAM(GB): " << std::left << std::setw(10) << "HDD||SDD: \n";
	cout << "------------------------------------------------------------------------------------------------------------------------------\n";
	smjestizaIspis("Laptop");
	/*for (auto& i : laptopi) {
		cout << i;
	}*/
}
void pretragaPoProizz() {
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	std::unique_ptr<string>l = std::make_unique<string>();
	std::cout << "Unesite proizvodjaca za pretragu: ";
	getline(cin, *l);
	temp->pretragaPoProiz(*l);
}
void pretragaPoModeluu() {
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	std::unique_ptr<string>l = std::make_unique<string>();
	std::cout << "Unesite proizvodjaca za pretragu: ";
	getline(cin, *l);
	temp->pretragaPoModelu(*l);
}
int main()
{
	pretragaPoModeluu();
	pretragaPoProizz();
	unosLaptopa();
	ispisLaptopa();
}
