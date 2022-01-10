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
#include "Admin.h"
#include "Kupac.h"
#include "PC.h"

using namespace std;
//vector<Laptop>laptopi;
int error;

void osnova() {
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << std::left << std::setw(15) << "Proizvodjac " << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolièina" <<
		std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
		<< std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(12) <<
		"RAM(GB) " << std::left << std::setw(10) << "HDD||SSD \n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}
void prodajaLaptopa() {
	string upit;
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	cout << "Da li zelite kupiti jedan od laptopa?(DA/NE)\n";
	do {
		cout << "Unesite izbor: ";
		getline(cin, upit);
		if (upit != "DA" && upit != "NE") {
			cout << "[GRESKA]Unesite DA ili NE\n";
		}
	} while (upit != "DA" && upit != "NE");
	if (upit == "DA") {
		temp->prodajaLaptopa();
	}
}


void ispisLaptopa(string rec) {
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	cout << *temp;
	if (rec != "admin") {
		prodajaLaptopa();
	}
}
void prodaja() {
	int iz = 0, lap = 0;
	do {
		system("cls");
		std::cout << "\n\n" << std::setw(81) << "*****************************************" << std::endl;
		std::cout << std::setw(81) << "*     >>>>  KUPOVINA PROIZVODA  <<<<     *" << std::endl;
		std::cout << std::setw(81) << "*****************************************" << std::endl;
		std::cin.clear();
		std::cout << "\n" << std::setw(81) << "* Odaberite neku od ponudjenih opcija : *";
		std::cout << "\n" << std::setw(81) << "*                                       *";
		std::cout << "\n" << std::setw(81) << "*        1. Kupovina laptopa            *";
		std::cout << "\n" << std::setw(81) << "*        2. Kupovina mobitela           *";
		std::cout << "\n" << std::setw(81) << "*        3. Kupovina racinara           *";
		std::cout << "\n" << std::setw(81) << "*        0. Vrati se nazad              *";
		std::cout << "\n" << std::setw(81) << "*                                       *";
		do {
			cout << "\n" << std::setw(67) << "Unesite izbor: ";
			cin >> iz;
		} while (iz < 0 || iz>4);
		cin.ignore();
		switch (iz)
		{
		case 1:
			ispisLaptopa("kupac");
		case 2:
			//ispisMob();
			break;
		case 3:
			//ispisRacunara();
			break;
		case 4:
			break;
		case 0:

			break;
		default:
			cout << "Usli ste u default opciju\n";
			break;
		}
	} while (iz != 0);



}





void pretragaPoProizziMod(string r) {
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	std::unique_ptr<string>p = std::make_unique<string>();
	std::unique_ptr<string>l = std::make_unique<string>();
	std::cout << "Unesite proizvodjaca za pretragu: ";
	getline(cin, *l);
	std::cout << "Unesite model za pretragu: ";
	getline(cin, *p);
	if (r == "Laptop") {
	temp->pretragaPoProizImodeluLap(*l, *p); 
	prodajaLaptopa();
	}
	

}

void pretragaPoProiz(string r) {
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	std::unique_ptr<string>p = std::make_unique<string>();
	std::unique_ptr<string>l = std::make_unique<string>();
	std::cout << "Unesite proizvodjaca za pretragu: ";
	getline(cin, *l);
	if (r == "Laptop") { 
		temp->pretragaPoProiz(*l);
		prodajaLaptopa();
	}
}


void info() {
	cout << "DOBRO DOSLI\n\n\n";
	std::unique_ptr<Admin>c = std::make_unique<Admin>();

	cout << " Nas IT shop posjeduje : \n";
	Artikal* i1 = new Laptop();
	Artikal* i2 = new PC();
	Artikal* posjedujem[2]{ i1,i2 };
	for (int i = 0;i < 2;i++) {
		posjedujem[i]->PosjedujemArtikal();

	}
	cout << "\n\t\tAdmin team\n";
	c->citanjeAdmina();
	cout << "\nUgodnu kupovinu i ostatak dana Vam zeli admin tim OO shopa (:\n";
	system("pause");
}
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
	int boja=0;
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

void pretragaOpcije() {
	int iz = 0, lap = 0;
	do {
		system("cls");
		std::cout << "\n\n" << std::setw(81) << "*******************************************" << std::endl;
		std::cout << std::setw(81) << "*     >>>>  PRETRAZI   PROIZVOD  <<<<     *" << std::endl;
		std::cout << std::setw(81) << "*******************************************" << std::endl;
		std::cin.clear();
		std::cout << "\n" << std::setw(81) << "*  Odaberite neku od ponudjenih opcija    *";
		std::cout << "\n" << std::setw(81) << "*                                         *";
		std::cout << "\n" << std::setw(81) << "*          1. Pretraga laptopa            *";
		std::cout << "\n" << std::setw(81) << "*          2. Pretraga mobitela           *";
		std::cout << "\n" << std::setw(81) << "*          3. Pretraga racunara           *";
		std::cout << "\n" << std::setw(81) << "*          0. Vrati se nazad              *";
		std::cout << "\n" << std::setw(81) << "*                                         *";
		do {
			std::cout << "\n\n" << std::setw(67) << "Unesite izbor: ";
			cin >> iz;
		} while (iz < 0 || iz>3);
		switch (iz)
		{
		case 1:
			do {
				system("cls");
				std::cout << "\n\n\n" << std::setw(81) << "*                                         *";
				std::cout << "\n" << std::setw(81) << "*   1. Pretraga po proizvodjacu           *";
				std::cout << "\n" << std::setw(81) << "*   2. Pretraga po proizvodjacu i modelu  *";
				std::cout << "\n" << std::setw(81) << "*   0. Vrati na prethodni menu            *";
				std::cout << "\n" << std::setw(81) << "*                                         *";
				do {
					std::cout << "\n\n" << std::setw(67) << "Unesite izbor: ";
					cin >> lap;
				} while (lap < 0 || lap > 3);
				cin.ignore();
				switch (lap)
				{
				case 1:
					pretragaPoProiz("Laptop");
					break;
				case 2:
					pretragaPoProizziMod("Laptop");
					break;
				case 0:
					break;

				default:
					break;
				}
			} while (lap != 0);

		default:
			break;
		}
	} while (iz!=0);
}
void ispisOpcijeKupac() {
	
	int iz = 0, lap = 0;
	do {
		system("cls");
		std::cout << "\n\n" << std::setw(81) << "*****************************************" << std::endl;
		std::cout << std::setw(81) << "*     >>>>  ISPIS   PROIZVODA  <<<<     *" << std::endl;
		std::cout << std::setw(81) << "*****************************************" << std::endl;
		std::cin.clear();
		std::cout << "\n" << std::setw(81) << "* Odaberite neku od ponudjenih opcija : *";
		std::cout << "\n" << std::setw(81) << "*                                       *";
		std::cout << "\n" << std::setw(81) << "*        1. Ispis svih proizvoda        *";
		std::cout << "\n" << std::setw(81) << "*        2. Ispis mobitela              *";
		std::cout << "\n" << std::setw(81) << "*        3. Ispis racunara              *";
		std::cout << "\n" << std::setw(81) << "*        4. Ispis laptopa               *";
		std::cout << "\n" << std::setw(81) << "*        0. Vrati se nazad              *";
		std::cout << "\n" << std::setw(81) << "*                                       *";
		do {
			cout << "\n" << std::setw(67) << "Unesite izbor: ";
			cin >> iz;
		} while (iz < 0 || iz>4);
		cin.ignore();
		switch (iz)
		{
		case 1:
			//ispisSvih();
		case 2:
			//ispisMob();
			break;
		case 3:
			//ispisRacunara();
			break;
		case 4:
			ispisLaptopa("kupac");
			break;
		case 0:

			break;
		default:
			cout << "Usli ste u default opciju\n";
			break;
		}
	} while (iz != 0);
}

void ispisOpcijeAdmin() {

	int iz = 0, lap = 0;
	do {
		system("cls");
		std::cout << "\n\n" << std::setw(81) << "*****************************************" << std::endl;
		std::cout << std::setw(81) << "*     >>>>  ISPIS   PROIZVODA  <<<<     *" << std::endl;
		std::cout << std::setw(81) << "*****************************************" << std::endl;
		std::cin.clear();
		std::cout << "\n" << std::setw(81) << "* Odaberite neku od ponudjenih opcija : *";
		std::cout << "\n" << std::setw(81) << "*                                       *";
		std::cout << "\n" << std::setw(81) << "*        1. Ispis svih proizvoda        *";
		std::cout << "\n" << std::setw(81) << "*        2. Ispis mobitela              *";
		std::cout << "\n" << std::setw(81) << "*        3. Ispis racunara              *";
		std::cout << "\n" << std::setw(81) << "*        4. Ispis laptopa               *";
		std::cout << "\n" << std::setw(81) << "*        0. Vrati se nazad              *";
		std::cout << "\n" << std::setw(81) << "*                                       *";
		do {
			cout << "\n" << std::setw(67) << "Unesite izbor: ";
			cin >> iz;
		} while (iz < 0 || iz>4);
		cin.ignore();
		switch (iz)
		{
		case 1:
			//ispisSvih();
		case 2:
			//ispisMob();
			break;
		case 3:
			//ispisRacunara();
			break;
		case 4:
			ispisLaptopa("admin");
			break;
		case 0:

			break;
		default:
			cout << "Usli ste u default opciju\n";
			break;
		}
	} while (iz != 0);


}



void updateOpcije() {
	shared_ptr<Laptop>lape = make_shared<Laptop>();
	int iz = 0, lap = 0;
	do {
		system("cls");
		cout << "\n\n" << setw(86) << "************************************************" << endl;
		cout << setw(86) << "*      >>>>   AZURIRAJ PROIZVODE    <<<<      *" << endl;
		cout << setw(86) << "************************************************" << endl;
		cout << "\n" << setw(79) << "Odaberite neku od ponudjenih opcija ";
		cout << "\n\n" << setw(80) << "1. Azuriraj laptope  ";
		cout << "\n" << setw(80) << "2. Azuriraj mobitele ";
		cout << "\n" << setw(80) << "3. Azuriraj racunare ";
		cout << "\n" << setw(76) << "0. Vrati se na administratorski menu\n";
		do {
			cout << "\n" << std::setw(67) << "Unesite izbor: ";
			cin >> iz;
		} while (iz < 0 || iz>4);
		cin.ignore();
		switch (iz)
		{
		case 1:
			lape->adminProdaja();
		case 2:
			//ispisMob();
			break;
		case 3:
			//ispisRacunara();
			break;
		case 4:
			break;
		case 0:

			break;
		default:
			cout << "Usli ste u default opciju\n";
			break;
		}
	} while (iz != 0);




}


void stanjeK() {
	unique_ptr<Laptop>laptop = make_unique<Laptop>();
	!(*laptop);
	*(*laptop);

	cout << "Stanje kase:  " << "\n\tZarada na prodaji laptopa: "  << Laptop::prihodL << " KM\n\t Potroseno na kupovinu laptopa : " << Laptop::trosiL * (-1) << " KM \n";
	cout << "Bilans sto se tice laptopa: " <<Laptop::prihodL-  (Laptop::trosiL*(-1)) << " KM\n";
	system("pause");
}



void adminOpcije() {
	
	system("cls");
	cout << "\n\n" << setw(81) << "*****************************************" << endl;
	cout << setw(81) << "* >>>>  DOBRO DOSLI NA ADMIN MENU  <<<< *" << endl;
	cout << setw(81) << "*****************************************" << endl;
	cin.clear();
	cout << "\n" << setw(79) << "Odaberite neku od ponudjenih opcija ";
	cout << "\n\n" << setw(69) << "1. Ispis odredjene vrste proizvoda";
	cout << "\n" << setw(66) << "2. Potrazi proizvod ";
	cout << "\n" << setw(67) << "3. Predaja artikla u postu ";
	cout << "\n" << setw(67) << "4. Stanje kase ";
	cout << "\n" << setw(75) << "0. Vrati se na glavni menu\n";
}
void adminMenu() {
	int odabir = 0, odabirI=0, odabirA=0, odabirB=0, odabirP=0;
	do {
		adminOpcije();
		do {
			error = 0;
			cout << "\n" << setw(69) << "Upisi svoj izbor: ";
			cin >> odabir;
			if (odabir < 0 || odabir>8) {
				cout << setw(65) << "Unesite validan unos: " << endl;
				error = 1;
			}
		} while (error == 1);
		cin.ignore();
		switch (odabir) {
		case 1:
			ispisOpcijeAdmin();
			break;
		case 2: 
			pretragaOpcije();
			break;
		case 3:
			updateOpcije();
			break;
		case 4:
			stanjeK();
			break;
		case 0: {
			system("CLS");
		} break;
		}
		
		
		

	} while (odabir != 0);
}
void sortiranjeLaptopa() {
	shared_ptr<Laptop>temp = make_shared<Laptop>();
	int iz = 0;
	do {
	cout << "1-Ispis laptopa sortirano po cijeni\n";
	cout << "2-Ispis laptopa sortirano po godini proizvodnje\n";
	cout << "3-Ispis laptopa sortirano po velicini promarne memorije\n";
	cout << "4-Ispis laptopa sortirano po velicini sekundarne memorije\n";
	cout << "0-Vrati se na prethodni meni\n";
	do {
		cout << "Unesite izbor:";
		cin >> iz;
	} while (iz < 0 || iz>4);
	if (iz != 0) {
		osnova();
	}
		switch (iz)
		{
		case 1:
			temp->sortiranjeLaptopa("cijena");
			break;
		case 2:
			temp->sortiranjeLaptopa("godine");
			break;
		case 3:
			temp->sortiranjeLaptopa("ram");
			break;
		case 4:
			temp->sortiranjeLaptopa("hdd");
			break;
		default:
			break;
		}
		if (iz != 0) {
			system("pause");
			system("cls");
		}
	}while(iz != 0);
}

void kupacOpcije() {
	system("cls");
	std::cout << "\n\n" << std::right << std::setw(81) << "*****************************************" << std::endl;
	std::cout << std::right << std::setw(81) << "* >>>>  DOBRO DOSLI NA KUPAC MENU  <<<< *" << std::endl;
	std::cout << std::right << std::setw(81) << "*****************************************" << std::endl;
	std::cin.clear();
	std::cout << "\n" << std::setw(81) << "* Odaberite neku od ponudjenih opcija : *";
	std::cout << "\n" << std::setw(81) << "*                                       *";
	std::cout << "\n" << std::setw(81) << "*      1. Prikazi sve proizvode         *"; //ponuditi posebno ako zeli svaku vrstu proizvoda slicno kao kod admina
	std::cout << "\n" << std::setw(81) << "*      2. Potrazi proizvod              *";
	std::cout << "\n" << std::setw(81) << "*      3. Kupi artikal                  *";
	std::cout << "\n" << std::setw(81) << "*      4. Ispis sortiranih artikala     *";
	std::cout << "\n" << std::setw(81) << "*      5. Info                          *";
	std::cout << "\n" << std::setw(81) << "*      6. Stanje kase                   *";
	std::cout << "\n" << std::setw(81) << "*      0. Vrati se na glavni menu       *";
	std::cout << "\n" << std::setw(81) << "*                                       *";
	std::cout << std::endl;
}

void kupacMenu() {
	int odabir = 0, odabirI=0 , odabirP=0;
	do {
		kupacOpcije();
		do {
			error = 0;
			cout << "\n" << setw(69) << "Upisi svoj izbor: ";
			cin >> odabir;
			if (odabir < 0 || odabir>5) {
				cout << setw(65) << "Unesite validan unos: " << endl;
				error = 1;
			}
		} while (error == 1);
		system("cls");
		switch (odabir) {
		case 1: 
			ispisOpcijeKupac();
			break;
		case 2: 
			pretragaOpcije();
			break;
		case 3:
			prodaja();
			system("pause");
			break;
		case 4:
			odabir = 4;
			sortiranjeLaptopa();
			break;
		case 5:
			info();
			break;
		case 6:
			stanjeK();
			break;
		case 0: {
			system("CLS");
		} break;

		}
	} while (odabir != 0);

}





void unosLaptopa() {
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	cin >> *temp;
	//laptopi.push_back(*temp);
	cout << "Uspjesno smjesten laptop u datoteku\n";
}







int kupacMe() {
	int n=0;
	cout << "_________________________________________________________________________________________________________" << endl;
	cout << "|                                                                                                       |" << endl;
	cout << "|                                       ==========================                                      |" << endl;
	cout << "|                                       | Postovani, dobrodosli! |                                      |" << endl;
	cout << "|                                       ==========================                                      |" << endl;
	cout << "|_______________________________________________________________________________________________________|\n" << endl;
	cout << "                                 _______________________________________                                 " << endl;
	cout << "                                 |                                     |                                 " << endl;
	cout << "                                 |      Odaberite zeljenu opciju:      |                                 " << endl;
	cout << "                                 |                                     |                                 " << endl;
	cout << "                                 |        1. Kupac login:              |                                 " << endl;
	cout << "                                 |        2. Kupac registracija:       |                                 " << endl;
	cout << "                                 |        0. Vrati se glavnu menu:     |                                 " << endl;
	cout << "                                 |_____________________________________|                               \n" << endl;
	do {
		error = 0;
		cout << "\n" << setw(68) << "Upisi svoj izbor: ";
		cin >> n;
		if (n < 0 || n>2) {
		  cout << "\n                                        ==========================                                     " << endl;
			cout << "                                        |   UNOS NIJE VALIDAN!   |                                    " << endl;
			cout << "                                        | Molimo unesite ponovo. |                                    " << endl;
			cout << "                                        ==========================                                   " << endl;
			error = 1;
			cin.clear();
		}
	} while (error == 1);
	cin.ignore();
	return n;
}


int main()
{
	int izbor=0,z=0,a=0,i=0;
	int n=0;
	string user, password;
	Laptop Lap ;
	info();
	bool l;
	//stanjeK();
	PC pc;
	
	cin >> pc;
	cout <<pc;
	
	do {
		cout << "\n\n" << setw(81) << right << "" << endl;
		cout << "_________________________________________________________________________________________________________" << endl;
		cout << "|                                                                                                       |" << endl;
		cout << "|                                       ==========================                                      |" << endl;
		cout << "|                                       |   PRIJAVA NA IT SHOP!  |                                      |" << endl;
		cout << "|                                       ==========================                                      |" << endl;
		cout << "|_______________________________________________________________________________________________________|\n" << endl;
		cin.clear();
		cout << "                                   _____________________________________                                   " << endl;
		cout << "                                  /__________________o__________________\\                                 " << endl;
		cout << "                                  |           Odaberite opciju:         |                                 " << endl;
		cout << "                                  |                                     |                                 " << endl;
		cout << "                                  |         1. Admin login              |                                 " << endl;
		cout << "                                  |         2. Kupac login              |                                 " << endl;
		cout << "                                  |         3. Promjeni velicinu fonta  |                                 " << endl;
		cout << "                                  |         4. Promjena teme            |                                 " << endl;
		cout << "                                  |         0. Kraj                     |                                 " << endl;
		cout << "                                  |_____________________________________|                                 " << endl;
		cout << "                                 /---------------------------------------\\                                " << endl;
		cout << "                                /  # ########################## ### ###   \\                               " << endl;
		cout << "                               /  ######################################   \\                              " << endl;
		cout << "                              /  ################################# # ####   \\                             " << endl;
		cout << "                             /  ####### ################### ##### ### ####   \\                            " << endl;
		cout << "                            /_________________________________________________\\                           " << endl;
		cout << "                           /_____________________|___|___|_____________________\\                          " << endl;
		cout << "                           \\___________________________________________________/                           \n" << endl;
		do {
			error = 0;
			cout << "\n" << setw(69)<< right << "Upisite svoj odabir : ";
			cin >> izbor;
			if (izbor > 4 || izbor < 0) {
				cout << "\n                                        ==========================                                     " << endl;
				cout << "                                        |     POGRESAN IZBOR!    |                                    " << endl;
				cout << "                                        | Molimo unesite ponovo. |                                    " << endl;
				cout << "                                        ==========================                                   " << endl;
				error = 1;
				cin.clear();
				
			}
		} while (error == 1);
		cin.ignore();
		system("cls");
		switch (izbor) {
		case 1: {
			do {
				cout << "\n\n" << setw(81) <<right<< "Unesite sifru za ulazak u admin menu : \n";
				cin >> z;
				a++;
				if (a == 3 && z!=123) {
					cout << "[GRESKA]Zbog nesigurnosti vseg identiteta,izbaceni ste sa naseg sajta :) \n";
					return 0;
					break;
				}
			} while (z != 123);
			cin.ignore();
			a = 0;
			string user, password;
			std::shared_ptr<Admin>temp = std::make_shared<Admin>();
			cout << "\n" << setw(60) << "Username: ";
		    getline(cin, user);
			cout << "\n" << setw(57) << "Sifra: ";
			password = temp->unosPassworda(password, 0);
			if (temp->login(user, password)==true) {
				cout << "\n\n" << setw(75) << "Uspjesno logirani na admin acc." << endl;
				system("pause");
				adminMenu();
			}
			if (temp->login(user, password) == false) {
				cout<< "\nUsername ili password nisu validni.";
				system("pause");
				Sleep(2000);
				system("CLS");
			}
		} break;
		case 2: {
			do {
				n = kupacMe();
				switch (n) {
				case 1: {
					string kupac, password;
					std::shared_ptr<Kupac>tempp = std::make_shared<Kupac>();
					cout << "Molim vas unesite kupac username: ";
					getline(cin, kupac);
					cout << "Sifra: ";
					password = tempp->unosPassworda(password, 0);
					if (tempp->login(kupac, password) == true) {
						cout << "\n\n" << setw(75) << "Uspjesno logirani na kupac acc." << endl;
						kupacMenu();
					}
					if (tempp->login(kupac, password) == false) {
						cout << "\n\n" << setw(78) << "Username ili password nisu validni." << endl;
						system("pause");
						Sleep(2000);
						system("CLS");
					}
				}break;
				case 2: {
					std::shared_ptr<Kupac>k = std::make_shared<Kupac>();
					l = k->dodajProfil();
					if (l == false) {
						cout << "[GRESKA]U nasem sistemu vec postoji jedan korisnik sa istim usernamee,pokusajte unijeti drugi(: \n";
					}
				}break;
				case 0: {
					system("CLS");
				} break;
				default: cout << setw(65) << "[GRESKA] -> Unos nije validan!" << endl;
				}

			} while (n != 0);
		}break;
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
	
}
