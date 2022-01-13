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
#include "Mobitel.h"
#include "Oprema.h"

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
void osnovaPC() {
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << std::left << std::setw(15) << "Proizvodjac " << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolièina" <<
		std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
		<< std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Kuciste" << std::left << std::setw(12) <<
		"RAM(GB) " << std::left << std::setw(10) << "HDD||SSD \n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}
void osnovaMob() {
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << std::left << std::setw(15) << "Proizvodjac " << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolièina" <<
		std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
		<< std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "Display" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(12) <<
		"RAM(GB) " << std::left << std::setw(10) << "Kmera(px) \n";
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
void prodajaRacunara() {
	string upit;
	std::shared_ptr<PC>temp = std::make_shared<PC>();
	cout << "Da li zelite kupiti jedan od racunara?(DA/NE)\n";
	do {
		cout << "Unesite izbor: ";
		getline(cin, upit);
		if (upit != "DA" && upit != "NE") {
			cout << "[GRESKA]Unesite DA ili NE\n";
		}
	} while (upit != "DA" && upit != "NE");
	if (upit == "DA") {
		temp->prodajaPC();
	}  


}
void prodajaMobitela() {
	string upit;
	std::shared_ptr<Mobitel>temp = std::make_shared<Mobitel>();
	cout << "Da li zelite kupiti jedan od mobitela?(DA/NE)\n";
	do {
		cout << "Unesite izbor: ";
		getline(cin, upit);
		if (upit != "DA" && upit != "NE") {
			cout << "[GRESKA]Unesite DA ili NE\n";
		}
	} while (upit != "DA" && upit != "NE");
	if (upit == "DA") {
		temp->prodajaMobitela();
	}
}
void prodajaOpreme() {
	string upit;
	std::shared_ptr<Oprema>temp = std::make_shared<Oprema>();
	cout << "Da li zelite kupiti jedan od nasih artikala opreme?(DA/NE)\n";
	do {
		cout << "Unesite izbor: ";
		getline(cin, upit);
		if (upit != "DA" && upit != "NE") {
			cout << "[GRESKA]Unesite DA ili NE\n";
		}
	} while (upit != "DA" && upit != "NE");
	if (upit == "DA") {
		temp->prodajaOpreme();
	}

}

void ispisLaptopa(string rec) {
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	cout << *temp;
	if (rec != "admin") {
		prodajaLaptopa();
	}
}
void ispisMobitela(string rec) {
	std::shared_ptr<Mobitel>temp = std::make_shared<Mobitel>();
	cout << *temp;
	if (rec != "admin") {
		prodajaMobitela();
	}
}
void ispisPC(string rec) {
	std::shared_ptr<PC>temp = std::make_shared<PC>();
	cout << *temp;
	if (rec != "admin") {
		prodajaRacunara();
	}
}
void ispisOpreme(string rec){
	std::shared_ptr<Oprema>temp = std::make_shared<Oprema>();
	cout << *temp;
	if (rec != "admin") {
		prodajaOpreme();
	}
}


void prodaja() {
	int iz = 0, lap = 0;
	do {
		system("cls");
		std::cout << "\n\n" << right << std::setw(81) << "*****************************************" << std::endl;
		std::cout << right << std::setw(81) << "*     >>>>  KUPOVINA PROIZVODA  <<<<     *" << std::endl;
		std::cout << right << std::setw(81) << "*****************************************" << std::endl;
		std::cin.clear();
		std::cout << "\n" << right << std::setw(81) << "* Odaberite neku od ponudjenih opcija : *";
		std::cout <<  "\n" << right << std::setw(81) << "*                                       *";
		std::cout <<  "\n" << right << std::setw(81) << "*        1. Kupovina laptopa            *";
		std::cout << "\n" <<right <<std::setw(81) << "*        2. Kupovina mobitela           *";
		std::cout << "\n" << right << std::setw(81) << "*        3. Kupovina racunara           *";
		std::cout << "\n" << right << std::setw(81) << "*        4. Kupovina opreme             *";
		std::cout << "\n" << right << std::setw(81) << "*        0. Vrati se nazad              *";
		std::cout << "\n" << right << std::setw(81) << "*****************************************";
		do {
			cout << "\n" << right << std::setw(67) << "Unesite izbor: ";
			cin >> iz;
		} while (iz < 0 || iz>4);
		cin.ignore();
		switch (iz)
		{
		case 1:
			ispisLaptopa("kupac");
			break;
		case 2:
			ispisMobitela("kupac");
			break;
		case 3:
			ispisPC("kupac");
			break;
		case 4:
			ispisOpreme("kupac");
			break;
		case 0:

			break;
		default:
			cout << "Usli ste u default opciju\n";
			break;
		}
	} while (iz != 0);



}

void unosArtikla() {
	int iz = 0;
	unique_ptr<Laptop>laptop = make_unique<Laptop>();
	unique_ptr<PC>pc = make_unique<PC>();
	unique_ptr<Mobitel>mob = make_unique<Mobitel>();
	unique_ptr<Oprema>op = make_unique<Oprema>();
	do {
		system("cls");
		std::cout << "\n\n" << std::setw(81) << right << "*******************************************" << std::endl;
		std::cout << std::setw(81) << right << "*     >>>>  UNESI   PROIZVOD  <<<<     *" << std::endl;
		std::cout << std::setw(81) << right << "*******************************************" << std::endl;
		std::cin.clear();
		std::cout << "\n" << std::setw(81) << right << "*  Odaberite neku od ponudjenih opcija    *";
		std::cout << "\n" << std::setw(81) << right << "*                                         *";
		std::cout << "\n" << std::setw(81) << right << "*          1. Unos laptopa                *";
		std::cout << "\n" << std::setw(81) << right << "*          2. Unos mobitela               *";
		std::cout << "\n" << std::setw(81) << right << "*          3. Unos racunara               *";
		std::cout << "\n" << std::setw(81) << right << "*          4. Unos opreme                 *";
		std::cout << "\n" << std::setw(81) << right << "*          0. Vrati se nazad              *";
		std::cout << "\n" << std::setw(81) << right << "*                                         *";
		do {
			std::cout << "\n\n" << std::setw(67) << "Unesite izbor: ";
			cin >> iz;
		} while (iz < 0 || iz>4);
		cin.ignore();
		switch (iz)
		{
		case 1:
			cin >> *laptop;
			cout << "Uspjesno smjesten laptop u datoteku\n";
			system("pause");
			break;
			
		case 2:
			cin >> *mob;
			cout << "Uspjesno smjesten mobitel u datoteku\n";
			system("pause");
			break;
		case 3:
			cin >> *pc;
			cout << "Uspjesno smjesten racunar u datoteku\n";
			system("pause");
			break;
		case 4:
			cin >> *op;
			cout << "Uspjesno smjestena oprema u datoteku\n";
			system("pause");
			break;
		default:
			break;
		}
	} while (iz != 0);



}



void pretragaPoProizziMod(string r) {
	unique_ptr<Laptop>laptop = make_unique<Laptop>();
	unique_ptr<PC>pc = make_unique<PC>();
	unique_ptr<Mobitel>mob = make_unique<Mobitel>();
	std::unique_ptr<string>p = std::make_unique<string>();
	std::unique_ptr<string>l = std::make_unique<string>();
	std::cout << "Unesite proizvodjaca za pretragu: ";
	getline(cin, *l);
	std::cout << "Unesite model za pretragu: ";
	getline(cin, *p);
	if (r == "Laptop") {
	laptop->pretragaPoProizImodeluLap(*l, *p); 
	prodajaLaptopa();
	}
	if (r == "PC") {
		pc->pretragaPoProizImodeluPC(*l, *p);
		prodajaLaptopa();
	}
	if (r == "Mobitel") {
		mob->pretragaPoProizImodeluMob(*l, *p);
		prodajaLaptopa();
	}
	

}

void pretragaPoProiz(string r) {
	unique_ptr<Laptop>laptop = make_unique<Laptop>();
	unique_ptr<PC>pc = make_unique<PC>();
	unique_ptr<Mobitel>mob = make_unique<Mobitel>();

	std::unique_ptr<string>p = std::make_unique<string>();
	std::unique_ptr<string>l = std::make_unique<string>();
	std::cout << "Unesite proizvodjaca za pretragu: ";
	getline(cin, *l);
	if (r == "Laptop") { 
		laptop->pretragaPoProiz(*l);
		prodajaLaptopa();
	}if (r == "PC") {
		pc->pretragaPoProizPC(*l);
		prodajaRacunara();
	}
	if (r == "Mobitel") {
		mob->pretragaPoProizMob(*l);
		prodajaMobitela();
	}
}


void info() {
	cout << "________________________________________________________________________________________" << "\n";
	cout << "|                                   ________________                                   |" << "\n";
	cout << "|                                   | DOBRO DOSLI! |                                   |" << "\n";
	cout << "|                                   |______________|                                   |" << "\n";
	cout << "|______________________________________________________________________________________|" << "\n";

	cout << "\n\n\n";
	std::unique_ptr<Admin>c = std::make_unique<Admin>();

	cout << "                                Nas IT shop posjeduje :                                " << "\n\n";
	Artikal* i1 = new Laptop();
	Artikal* i2 = new PC();
	Artikal* i3 = new Mobitel();
	Artikal* posjedujem[3]{ i1,i2,i3 };
	for (int i = 0;i < 3;i++) {
		posjedujem[i]->PosjedujemArtikal();

	}
	cout << "                              ______________________________                             \n";
	cout << "                              |         Admin team         |                             \n";
	cout << "                              |____________________________|                             \n";

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
		std::cout << "\n" << std::setw(81) << right << "*  Odaberite neku od ponudjenih opcija    *";
		std::cout << "\n" << std::setw(81) << right << "*                                         *";
		std::cout << "\n" << std::setw(81) << right << "*          1. Pretraga laptopa            *";
		std::cout << "\n" << std::setw(81) << right << "*          2. Pretraga mobitela           *";
		std::cout << "\n" << std::setw(81) << right << "*          3. Pretraga racunara           *";
		std::cout << "\n" << std::setw(81) << right << "*          0. Vrati se nazad              *";
		std::cout << "\n" << std::setw(81) << right << "*******************************************";
		do {
			std::cout << "\n\n" << std::setw(67) << "Unesite izbor: ";
			cin >> iz;
		} while (iz < 0 || iz>3);
		switch (iz)
		{
		case 1:
			do {
				system("cls");
			std::cout << "\n\n\n" << std::setw(81)<<right << "*******************************************";
				std::cout << "\n" << std::setw(81) << right << "*   1. Pretraga po proizvodjacu           *";
				std::cout << "\n" << std::setw(81) << right << "*   2. Pretraga po proizvodjacu i modelu  *";
				std::cout << "\n" << std::setw(81) << right << "*   0. Vrati na prethodni menu            *";
				std::cout << "\n" << std::setw(81) << right << "*******************************************";
				do {
					std::cout << "\n\n" << std::setw(67) << "Unesite izbor: ";
					cin >> lap;
				} while (lap < 0 || lap > 3);
				cin.ignore();
				system("cls");
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
		case 2:
			do {
				system("cls");
				std::cout << "\n\n\n" << std::setw(81) << right << "*******************************************";
				std::cout << "\n" << std::setw(81) << right << "*   1. Pretraga po proizvodjacu           *";
				std::cout << "\n" << std::setw(81) << right << "*   2. Pretraga po proizvodjacu i modelu  *";
				std::cout << "\n" << std::setw(81) << right << "*   0. Vrati na prethodni menu            *";
				std::cout << "\n" << std::setw(81) << right << "*******************************************";
				do {
					std::cout << "\n\n" << std::setw(67) << right << "Unesite izbor: ";
					cin >> lap;
				} while (lap < 0 || lap > 3);
				cin.ignore();
				switch (lap)
				{
				case 1:
					pretragaPoProiz("Mobitel");
					break;
				case 2:
					pretragaPoProizziMod("Mobitel");
					break;
				case 0:
					break;

				default:
					break;
				}
			} while (lap != 0);
		case 3:
			do {
				system("cls");
				std::cout << "\n\n\n" << std::setw(81)<<right << "*******************************************";
				std::cout << "\n" << std::setw(81) << right << "*   1. Pretraga po proizvodjacu           *";
				std::cout << "\n" << std::setw(81) << right << "*   2. Pretraga po proizvodjacu i modelu  *";
				std::cout << "\n" << std::setw(81) << right << "*   0. Vrati na prethodni menu            *";
				std::cout << "\n" << std::setw(81) << right << "*******************************************";
				do {
					std::cout << "\n\n" << std::setw(67) << right << "Unesite izbor: ";
					cin >> lap;
				} while (lap < 0 || lap > 3);
				cin.ignore();
				switch (lap)
				{
				case 1:
					pretragaPoProiz("PC");
					break;
				case 2:
					pretragaPoProizziMod("PC");
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
		std::cout << "\n\n" << std::setw(81) << right << "*****************************************" << std::endl;
		std::cout << std::setw(81) << right << "*     >>>>  ISPIS   PROIZVODA  <<<<     *" << std::endl;
		std::cout << std::setw(81) << right << "*****************************************" << std::endl;
		std::cin.clear();
		std::cout << "\n" << std::setw(81) <<right<< "* Odaberite neku od ponudjenih opcija : *";
		std::cout << "\n" << std::setw(81) << right << "*                                       *";
		std::cout << "\n" << std::setw(81) << right << "*        1. Ispis svih proizvoda        *";
		std::cout << "\n" << std::setw(81) << right << "*        2. Ispis mobitela              *";
		std::cout << "\n" << std::setw(81) << right << "*        3. Ispis racunara              *";
		std::cout << "\n" << std::setw(81) << right << "*        4. Ispis laptopa               *";
		std::cout << "\n" << std::setw(81) << right << "*        5. Ispis opreme                *";
		std::cout << "\n" << std::setw(81) << right << "*        0. Vrati se nazad              *";
		std::cout << "\n" << std::setw(81) << right << "*****************************************";
		do {
			cout << "\n" << std::setw(67) << right << "Unesite izbor: ";
			cin >> iz;
		} while (iz < 0 || iz>5);
		cin.ignore();
		system("cls");
		switch (iz)
		{
		case 1:
			//ispisSvih();
		case 2:
			ispisMobitela("kupac");
			break;
		case 3:
			ispisPC("kupac");
			break;
		case 4:
			ispisLaptopa("kupac");
			break;
		case 5:
			ispisOpreme("kupac");
			system("pause");
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
		std::cout << "\n\n" << std::setw(81) << right << "*****************************************" << std::endl;
		std::cout << std::setw(81) << right << "*     >>>>  ISPIS   PROIZVODA  <<<<     *" << std::endl;
		std::cout << std::setw(81) << right << "*****************************************" << std::endl;
		std::cin.clear();
		std::cout << "\n" << std::setw(81) << right << "* Odaberite neku od ponudjenih opcija : *";
		std::cout << "\n" << std::setw(81) << right << "*                                       *";
		std::cout << "\n" << std::setw(81) << right << "*        1. Ispis svih proizvoda        *";
		std::cout << "\n" << std::setw(81) << right << "*        2. Ispis mobitela              *";
		std::cout << "\n" << std::setw(81) << right << "*        3. Ispis racunara              *";
		std::cout << "\n" << std::setw(81) << right << "*        4. Ispis laptopa               *";
		std::cout << "\n" << std::setw(81) << right << "*        5. Ispis opreme                *";
		std::cout << "\n" << std::setw(81) << right << "*        0. Vrati se nazad              *";
		std::cout << "\n" << std::setw(81) << right << "*****************************************";
		do {
			cout << "\n" << std::setw(67) << "Unesite izbor: ";
			cin >> iz;
		} while (iz < 0 || iz>5);
		cin.ignore();
		system("cls");
		switch (iz)
		{
		case 1:
			//ispisSvih();
		case 2:
			ispisMobitela("admin");
			system("pause");
			break;
		case 3:
			ispisPC("admin");
			system("pause");
			break;
		case 4:
			ispisLaptopa("admin");
			system("pause");
			break;
		case 5:
			ispisOpreme("admin");
			system("pause");
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
	unique_ptr<Laptop>lape = make_unique<Laptop>();
	unique_ptr<PC>pc = make_unique<PC>();
	unique_ptr<Oprema>op = make_unique<Oprema>();
	unique_ptr<Mobitel>mob = make_unique<Mobitel>();
	int iz = 0, lap = 0;
	do {
		system("cls");
		cout << "\n" << setw(81) <<right << "************************************************" << endl;
		cout << setw(81) << right << "*      >>>>    AZURIRAJ PROIZVODE    <<<<      *" << endl;
		cout << setw(81) << right << "************************************************";
		cout << "\n" << setw(81) << right << "*                                              *";
		cout << "\n" << setw(81) << right << "*      Odaberite neku od ponudjenih opcija     *";
		cout << "\n" << setw(81) << right << "*            1. Azuriraj laptope               *";
		cout << "\n" << setw(81) << right << "*            2. Azuriraj mobitele              *";
		cout << "\n" << setw(81) << right << "*            3. Azuriraj racunare              *";
		cout << "\n" << setw(81) << right << "*            4. Azuriraj opremu                *";
		cout << "\n" << setw(81) << right << "*            0. Vrati se na admin menu         *";
		cout << "\n" << setw(81) << right << "*                                              *";
		cout << "\n" << setw(81) << right << "************************************************";
		do {
			cout << "\n" << std::setw(65) << right << "Unesite izbor: ";
			cin >> iz;
		} while (iz < 0 || iz>4);
		cin.ignore();
		system("cls");
		switch (iz)
		{
		case 1:
			lape->adminProdaja();
			break;
		case 2:
			mob->adminProdajaMob();
			break;
		case 3:
			pc->adminProdajaPC();
			break;
		case 4:
			op->adminProdajaOpreme();
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
	unique_ptr<PC>pc = make_unique<PC>();
	unique_ptr<Mobitel>mob = make_unique<Mobitel>();
	unique_ptr<Oprema>op = make_unique<Oprema>();
	!(*laptop);
	*(*laptop);
	!(*pc);
	*(*pc);
	!(*mob);
	*(*mob);
	!(*op);
	*(*op);
	system("cls");
	cout <<         "                                       ______________________________________________";
	cout << "\n" << "                                       |                 Stanje kase:               |";
	cout << "\n" << "                                       |____________________________________________|\n";
	cout << "\n" << "                                       Zarada na prodaji laptopa: " << Laptop::prihodL << " KM       ";
	cout << "\n" << "                                       Potroseno na kupovinu laptopa: " << Laptop::trosiL * (-1) << " KM   ";
	cout << "\n" << "                                       Bilans sto se tice laptopa: " << Laptop::prihodL - (Laptop::trosiL * (-1)) << " KM      ";
	cout << "\n" << "                                       ----------------------------------------------";
	cout << "\n" << "                                       Zarada na prodaji racuanara: " << PC::prihoPC << " KM     ";
	cout << "\n" << "                                       Potroseno na kupovinu racunara: " << PC::trosiPC * (-1) << " KM  ";
	cout << "\n" << "                                       Bilans sto se tice racunara: " << PC::prihoPC - (PC::trosiPC * (-1)) << " KM     ";
	cout << "\n" << "                                       ----------------------------------------------";
	cout << "\n" << "                                       Zarada na prodaji mobitela: " << Mobitel::prihodMob << " KM      ";
	cout << "\n" << "                                       Potroseno na kupovinu mobitela: " << Mobitel::trosiMob*(-1) << " KM      ";
	cout << "\n" << "                                       Bilans sto se tice mobitela: " << Mobitel::prihodMob - (Mobitel::trosiMob * (-1)) << " KM     ";
	cout << "\n" << "                                       ----------------------------------------------";
	cout << "\n" << "                                       Zarada na prodaji opreme: " << Oprema::prihofOp << " KM      ";
	cout << "\n" << "                                       Potroseno na kupovinu opreme: " << Oprema::troaskOp*(-1) << " KM      ";
	cout << "\n" << "                                       Bilans sto se tice opreme: " << Oprema::prihofOp - (Oprema::troaskOp * (-1)) << " KM     ";
	cout << "\n" << "                                       ______________________________________________";
	cout << "\n" << "                                       UKUPNO STANJE KASE         : " << (Laptop::prihodL - (Laptop::trosiL * (-1)))+(PC::prihoPC - (PC::trosiPC * (-1)))+
																			(Mobitel::prihodMob - (Mobitel::trosiMob * (-1)))+( Oprema::prihofOp - (Oprema::troaskOp * (-1))) << " KM     ";
	cout << "\n\n";
	

	system("pause");
}


void sortiranje() {
	unique_ptr<Laptop>laptop = make_unique<Laptop>();
	unique_ptr<PC>pc = make_unique<PC>();
	unique_ptr<Mobitel>mob = make_unique<Mobitel>();
	int iz = 0;
	do {
		system("cls");
		cout << setw(75) << right << "SORTIRANJE ARTIKALA\n";
		cout << left<<"-------------------------------------------------------------------------------------------------------------------------------------------------|\n";
		cout << "1-Ispis laptopa sortirano po cijeni                               |         5-Ispis racunara sortirano po cijeni\n";
		cout << "2-Ispis laptopa sortirano po godini proizvodnje                   |         6-Ispis racunara sortirano po godini proizvodnje\n";
		cout << "3-Ispis laptopa sortirano po velicini primarne memorije           |         7-Ispis racunara sortirano po velicini primarne memorije\n";
		cout << "4-Ispis laptopa sortirano po velicini sekundarne memorije         |         8-Ispis racunara sortirano po velicini sekundarne memorije\n";
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------|\n";
		cout << setw(78) <<right<< "9-Ispis mobitela sortirano po cijeni\n";
		cout << setw(91) <<right<< "10-Ispis mobitela sortirano po godini proizvodnje\n";
		cout << setw(99) << right<<"11-Ispis mobitela sortirano po velicini primarne memorije\n";
		cout << setw(86) <<right<< "12-Ispis mobitela sortirano po pikselizaciji\n";
		cout << setw(70) <<right<< "0-Vrati se na prethodni meni\n";
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------|\n";
	do {
		cout << setw(73) << right << "Unesite izbor:";
		cin >> iz;
	} while (iz < 0 || iz>12);
	system("cls");
		switch (iz)
		{
		case 1:
			osnova();
			laptop->sortiranjeLaptopa("cijena");
			break;
		case 2:
			osnova();
			laptop->sortiranjeLaptopa("godine");
			break;
		case 3:
			osnova();
			laptop->sortiranjeLaptopa("ram");
			break;
		case 4:
			osnova();
			laptop->sortiranjeLaptopa("hdd");
			break;
		case 5:
			osnovaPC();
			pc->sortiranjePC("cijena");
			break;
		case 6:
			osnovaPC();
			pc->sortiranjePC("godine");
			break;
		case 7:
			osnovaPC();
			pc->sortiranjePC("ram");
			break;
		case 8:
			osnovaPC();
			pc->sortiranjePC("hdd");
			break;
		case 9:
			osnovaMob();
			mob->sortiranjeMob("cijena");
			break;
		case 10:
			osnovaMob();
			mob->sortiranjeMob("godine");
			break;
		case 11:
			osnovaMob();
			mob->sortiranjeMob("ram");
			break;
		case 12:
			osnovaMob();
			mob->sortiranjeMob("kamera");
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
void adminOpcije() {
	system("cls");
	cout << "\n\n" << setw(81) << right << "*****************************************" << endl;
	cout << setw(81) << right << "* >>>>  DOBRO DOSLI NA ADMIN MENU  <<<< *" << endl;
	cout << setw(81) << right << "*****************************************";
	cin.clear();
	cout << "\n" << "                                        *                                       *";
	cout << "\n" << "                                        * Odaberite neku od ponudjenih opcija:  *";
	cout << "\n" << "                                        * 1. Ispis odredjene vrste proizvoda    *";
	cout << "\n" << "                                        * 2. Potrazi proizvod                   *";
	cout << "\n" << "                                        * 3. Predaja artikla u postu            *";
	cout << "\n" << "                                        * 4. Stanje kase                        *";
	cout << "\n" << "                                        * 5. Unos artikla                       *";
	cout << "\n" << "                                        * 6. Ispis sortiranih elemenata         *";
	cout << "\n" << "                                        * 0. Vrati se na glavni menu            *";
	cout << "\n" << "                                        *                                       *";
	cout << "\n" << "                                        *****************************************";
	cout << "\n\n";
}
void adminMenu() {
	int odabir = 0, odabirI = 0, odabirA = 0, odabirB = 0, odabirP = 0;
	do {
		adminOpcije();
		do {
			error = 0;
			cout << "\n" << setw(69) << right << "Upisi svoj izbor: ";
			cin >> odabir;
			if (odabir < 0 || odabir>6) {
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
		case 5:
			unosArtikla();
			break;
		case 6:
			sortiranje();
			break;
		case 0: {
			system("CLS");
		} break;
		}
	} while (odabir != 0);
}
void kupacOpcije() {
	system("cls");
	std::cout << "\n\n" << std::right << std::setw(81) << "*****************************************" << std::endl;
	std::cout << std::right << std::setw(81) << "* >>>>  DOBRO DOSLI NA KUPAC MENU  <<<< *" << std::endl;
	std::cout << std::right << std::setw(81) << "*****************************************" << std::endl;
	std::cin.clear();
	std::cout << "\n" << right << std::setw(81) << "* Odaberite neku od ponudjenih opcija : *";
	std::cout << "\n" << right << std::setw(81) << "*                                       *";
	std::cout << "\n" << right << std::setw(81) << "*      1. Prikazi proizvode         *"; //ponuditi posebno ako zeli svaku vrstu proizvoda slicno kao kod admina
	std::cout << "\n" << right << std::setw(81) << "*      2. Potrazi proizvod              *";
	std::cout << "\n" << right << std::setw(81) << "*      3. Kupi artikal                  *";
	std::cout << "\n" << right << std::setw(81) << "*      4. Ispis sortiranih artikala     *";
	std::cout << "\n" << right << std::setw(81) << "*      5. Info                          *";
	std::cout << "\n" << right << std::setw(81) << "*      0. Vrati se na glavni menu       *";
	std::cout << "\n" << right << std::setw(81) << "*****************************************";
	std::cout << std::endl;
}

void kupacMenu() {
	int odabir = 0, odabirI=0 , odabirP=0;
	do {
		kupacOpcije();
		do {
			error = 0;
			cout << "\n" << right << setw(69) << "Upisi svoj izbor: ";
			cin >> odabir;
			if (odabir < 0 || odabir>5) {
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
			sortiranje();
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
	cout << "Uspjesno smjesten laptop u datoteku\n";
}
void unosPC() {
	std::shared_ptr<PC>temp = std::make_shared<PC>();
	cin >> *temp;
	cout << "Uspjesno smjesten racunar u datoteku\n";
}void unosMobitela() {
	std::shared_ptr<Mobitel>temp = std::make_shared<Mobitel>();
	cin >> *temp;
	cout << "Uspjesno smjesten mobitel u datoteku\n";
}
void unosOpremea() {
	std::shared_ptr<Oprema>temp = std::make_shared<Oprema>();
	cin >> *temp;
	cout << "Uspjesno smjestena oprema u datoteku\n";
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
		cout << "\n" << setw(68) <<right<< "Upisi svoj izbor: ";
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
	int izbor=0,z=0,a=0,i=0, n=0;
	string user, password;
	bool l;
	Oprema o;
	//cin >> o;
	do {
		system("cls");
		cout << "\n\n" << setw(81) << right << "" << endl; 
			cout << "_________________________________________________________________________________________________________" << endl;
		cout << "|                                                                                                       |" << endl;
		cout << "|                                       ==========================                                      |" << endl;
		cout << "|                                       |   PRIJAVA NA IT SHOP!  |                                      |" << endl;
		cout << "|                                       ==========================                                      |" << endl;
		cout << "|_______________________________________________________________________________________________________|\n" << endl;
		cin.clear();
		cout << "                                    _____________________________________                                   " << endl;
		cout << "                                   /__________________o__________________\\                                 " << endl;
		cout << "     ________________              |           Odaberite opciju:         |               ____________       " << endl;
		cout << "    /_______o_______ \\             |                                     |              |____________|     " << endl;
		cout << "   | |______________| |            |         1. Admin login              |              |____________|      " << endl;
		cout << "   | |              | |            |         2. Kupac login              |              |____________|     " << endl;
		cout << "   | |              | |            |         3. Promjeni velicinu fonta  |              |            |      " << endl;
		cout << "   | |              | |            |         4. Promjena teme            |              |____________|      " << endl;
		cout << "   | |              | |            |         0. Kraj                     |              |          o |      " << endl;
		cout << "   | |              | |            |_____________________________________|              |            |      " << endl;
		cout << "   | |              | |           /---------------------------------------\\             |    ____    |     " << endl;
		cout << "   | |              | |          /  # ########################## ### ###   \\            |    |  |    |     " << endl;
		cout << "   | |              | |         /  ######################################   \\           |    |  |    |     " << endl;
		cout << "   | |______________| |        /  ################################# # ####   \\          |    |  |    |     " << endl;
		cout << "   |   <    o    >    |       /  ####### ################### ##### ### ####   \\         |    |  |    |     " << endl;
		cout << "   \\__________________/      /_________________________________________________\\        ||||||||||||||    " << endl;
		cout << "                            /_____________________|___|___|_____________________\\                          " << endl;
		cout << "                            \\___________________________________________________/                          " << endl;


		do {
			error = 0;
			cout  << setw(69)<< right << "Upisite svoj odabir : ";
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
				cout << "\n\n" << setw(81) <<right<< "Unesite sifru za ulazak u admin menu: ";
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
			cout << "\n" << setw(60)<<right << "Username: ";
		    getline(cin, user);
			cout << "\n" << setw(57)<<right << "Sifra: ";
			password = temp->unosPassworda(password, 0);
			if (temp->login(user, password)==true) {
				cout << "\n\n" << setw(75) <<right<< "Uspjesno logirani na admin acc." << endl;
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
					cout << "                                                Molim vas unesite kupac username: ";
					getline(cin, kupac);
					cout << "                                                Sifra: ";
					password = tempp->unosPassworda(password, 0);
					if (tempp->login(kupac, password) == true) {
						cout << "\n\n" << setw(75)<<right << "Uspjesno logirani na kupac acc." << endl;
						kupacMenu();
					}
					if (tempp->login(kupac, password) == false) {
						cout << "\n\n" << setw(78)<<right << "Username ili password nisu validni." << endl;
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
	return 0;
}
