#include <iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include <conio.h>
#include <windows.h>


#include "Laptop.h"

using namespace std;
vector<Laptop>laptopi;

int error;
struct adminP {
	string adminUser;string adminPass;
};
struct kupacP {
	string kupacUser;string kupacPass;
};
void login(string& admin, string& password);
void kupacLogin(string& user, string& password);

string unosPassworda(string password, int ch = 0) {
	password.clear();
	while (ch = _getch()) {
		if (ch != 13) cout << "*";
		password += ch;
		if (ch == 13) break;
	}
	password.erase(password.length() - 1);
	return password;}

void fontsize() {
	short font, x, y;
	do {
		error = 0;cout << "\n" << setw(70) << "Upisi velicinu fonta: ";
		cin >> font;
		if (font >= 25 || font <= 5){
			cout << "\n" << setw(68) << "Pogresan unos, unesite velicinu izmejdu 5 i 25. \n";
			error = 1;cin.clear();cin.ignore();}
	} while (error == 1);
	x = font;y = 2 * x;
	HANDLE Hout = ::GetStdHandle(STD_OUTPUT_HANDLE);
	COORD fsize = { x,y };CONSOLE_FONT_INFOEX Font = { sizeof(Font) };
	::GetCurrentConsoleFontEx(Hout, FALSE, &Font);
	Font.dwFontSize = fsize;SetCurrentConsoleFontEx(Hout, 0, &Font);
	cin.clear();system("cls");
}

void tema() {
	int boja;
	cout << "\n" << setw(72) << "1. Black and White theme " << endl;
	cout << "\n" << setw(72) << "2. White and Black theme " << endl;
	cout << "\n" << setw(56) << "0. Return" << endl;
	do {
		do {
			error = 0;
			cout << "\n" << setw(67) << "Unesite svoj izbor: ";
			cin >> boja;
			if (boja > 2 || boja < 1) {
				cout << "\n" << setw(65) << "Unos nije validan." << endl;
				error = 1;
				cin.clear();
				cin.ignore(80, '\n');}
		} while (error == 1);
		if (boja == 1) {
			system("color 0F");system("cls");
			return;}
		else if (boja == 2) {
			system("color F0");
			system("cls");return;}
	} while (boja != 0);
	system("cls");
	return;
}

void login(string& admin, string& password) {
	bool valid = false;adminP temp;
	vector <adminP> vektor;
	ifstream adminFile("admin.txt");
	if (adminFile.is_open()) {

		while (adminFile >> temp.adminUser) {
			adminFile >> temp.adminPass;
			vektor.push_back(temp);
			if (vektor.size() >= 200)
				break;
		}
	}
	adminFile.close();
	for (int i = 0; i < vektor.size(); i++) {
		if (admin == vektor[i].adminUser && password == vektor[i].adminPass) {
			cout << "\n\n" << setw(75) << "Uspjesno logirani na admin acc." << endl;
			valid = true;
			//adminMenu();
			break;
			Sleep(2000);
		}
	}
	if (!valid) {
		cout << "\n\n" << setw(75) << "Username ili password nisu validni." << endl;
		system("pause");
		Sleep(2000);
		system("CLS");
	}

}
void dodajProfil() {

	ofstream file;
	file.open("kupac.txt", std::ios_base::app);
	if (!file) {
		cout << "\n" << setw(80) << "Nije moguce otvoriti datoteku!";
		return;}
	kupacP k;
	cout << "\n" << setw(63) << "Username: ";cin >> k.kupacUser;
	cout << "\n" << setw(63) << "Password: ";cin >> k.kupacPass;
	file << " " << k.kupacUser << " ";
	file << k.kupacPass << endl;
	file.close();Sleep(1000);system("CLS");
}
void kupacLogin(string& user, string& password) {
	bool valid = false;kupacP temp;
	vector <kupacP> vektor;
	ifstream kupacFile("kupac.txt");
	if (kupacFile.is_open()) {
		while (kupacFile >> temp.kupacUser) {
			kupacFile >> temp.kupacPass;
			vektor.push_back(temp);
			if (vektor.size() >= 200)
				break;}}
	kupacFile.close();
	for (int i = 0; i < vektor.size(); i++) {
		if (user == vektor[i].kupacUser && password == vektor[i].kupacPass) {
			cout << "\n\n" << setw(75) << "Uspjesno logirani na kupac acc." << endl;
			//kupacMenu();
			valid = true;break;}
		else if (user == "Guest" && password == "guest") {
			cout << "\n\n" << setw(78) << "Uspjesno logirani na guest acc." << endl;
			valid = true;break;}}
	if (!valid) {
		cout << "\n\n" << setw(78) << "Username ili password nisu validni." << endl;
		system("pause");Sleep(2000);system("CLS");
	}}



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

	int izbor;
	string user, password;

	do {
		cout << "\n\n" << setw(81) << "****************************************" << endl;
		cout << setw(77) << " * >>>> PRIJAVA NA IT SHOP <<<< *" << endl;
		cout << setw(81) << "****************************************" << endl;

		cin.clear();
		cout << "\n" << setw(79) << "Odaberite neku od ponudjenih opcija :";
		cout << "\n" << setw(63) << "1. Admin login: ";
		cout << "\n" << setw(63) << "2. Kupac login: ";
		cout << "\n" << setw(75) << "3. Promjeni velicinu fonta: ";
		cout << "\n" << setw(65) << "4. Promjena teme: ";
		cout << "\n" << setw(57) << "0. Kraj: \n";

		do {
			error = 0;
			cout << "\n" << setw(69) << "Upisite svoj odabir : ";
			cin >> izbor;
			if (izbor > 4 || izbor < 0) {
				cout << "\n" << setw(79) << "[POGRESAN IZBOR] Pokusajte ponovo: \n";
				error = 1;
				cin.clear();
				cin.ignore();
			}
		} while (error == 1);
		system("cls");
		int z = 0;
		switch (izbor) {
		case 1: {
			do {
				cout << "Unesite sifru za ulazak u admin menu\n";
				cin >> z;
			} while (z != 123);
			cout << "\n" << setw(60) << "Username: ";
			cin >> user;
			cout << "\n" << setw(57) << "Sifra: ";
			password = unosPassworda(password);
			login(user, password);
		} break;
		case 2: {
			int n;
			cout << "\n" << setw(79) << "Odaberite neku od ponudjenih opcija :";
			cout << "\n" << setw(62) << "1. Kupac login ";
			cout << "\n" << setw(70) << "2. Kupac registracija: ";
			cout << "\n" << setw(70) << "0. Vrati se glavnu menu";

			do {
				error = 0;
				cout << "\n" << setw(68) << "Upisi svoj izbor: ";
				cin >> n;
				if (n < 0 || n>2) {
					cout << setw(65) << "Unesite validan unos: " << endl;
					error = 1;
					cin.clear();
					cin.ignore();
				}
			} while (error == 1);

			switch (n) {
			case 1: {
				cout << "\n" << setw(75) << "Molim vas unesite kupac username: ";
				cin >> user;
				cout << "\n" << setw(62) << "Sifra: ";
				password = unosPassworda(password);
				kupacLogin(user, password);
				break;
			}
			case 2: {
				dodajProfil();
			}break;
			case 0: {
				system("CLS");
			} break;
			default: cout << setw(65) << "[GRESKA] -> Unos nije validan!" << endl;
			}
		}	break;
		case 3: {
			fontsize();
		}break;
		case 4: {
			tema();
			break;
		}
		case 0: {
			system("pause");
			return 0;
		}
		default: {
			cout << "\n\n" << setw(65) << "[GRESKA] -> Unos nije validan!" << endl;
			cout << "\n\n" << setw(62) << "Pokusajte ponovo sa 1,2,3,4,5, ili 0!" << endl;
			system("pause");
		}
		}

	} while (izbor != 0);
	sortiranjePoSekundarnoj();
	unosLaptopa();
	pretragaPoProizziMod();
	unosLaptopa();
	ispisLaptopa();
}
