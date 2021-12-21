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
void osnova() {
	cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
	cout << std::left << std::setw(15) << "Proizvodjac " << std::left << std::setw(10) << "Model " << std::left << std::setw(10) << "Kolièina" <<
		std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
		<< std::left << std::setw(10) << "CPU" << std::left << std::setw(10) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(10) <<
		"RAM(GB) " << std::left << std::setw(10) << "HDD||SDD \n";
	cout << "------------------------------------------------------------------------------------------------------------------------------\n";
}
void ispisLaptopa() {
	osnova();
	smjestizaIspis("Laptop");
}

void pretragaPoProizziMod() {
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	std::unique_ptr<string>p = std::make_unique<string>();
	std::unique_ptr<string>l = std::make_unique<string>();
	std::cout << "Unesite proizvodjaca za pretragu: ";
	getline(cin, *l);
	std::cout << "Unesite model za pretragu: ";
	getline(cin, *p);
	temp->pretragaPoProizImodelu(*l, *p);
}


void sortiranjePoSekundarnoj(){
		std::ifstream unos("Laptop.txt");
		std::vector<std::string>nizl;std::vector<int>hdd;std::string temp;int pom;std::string po;
		int a, b, c, x, p = 0;
		if (unos.fail())std::cout << "Nemoguce otvaranje datoeke\n";
		else {
			getline(unos, temp);getline(unos, temp);getline(unos, temp);
			while (true) {
				getline(unos, temp);
				if (unos.eof())break;
				nizl.push_back(temp);
				a = temp[122] - '0';b = temp[123] - '0';c = temp[124] - '0';
				if (a > -1 && b > -1 && c > -1) x = a * 100 + b * 10 + c + 1;
				else if (a > -1 && b > -1 && c < -1) x = a * 10 + b;
				else if (a > -1 && b < -1 && c < -1) x = a;
				hdd.push_back(x);
			}
			for (int i = 0;i < hdd.size();i++) {
				for (int j = i;j < hdd.size();j++) {
					if (hdd[j] > hdd[i]) {
						std::swap(hdd[j], hdd[i]);
						std::swap(nizl[j], nizl[i]);
					}}}
			osnova();
			for (int i = 0;i < hdd.size();i++)std::cout << nizl[i] << "\n";
			unos.close();
		}}

int main()
{
	sortiranjePoSekundarnoj();
	unosLaptopa();
	pretragaPoProizziMod();
	unosLaptopa();
	//ispisLaptopa();
}
