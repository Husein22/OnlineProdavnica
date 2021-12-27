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

using namespace std;
vector<Laptop>laptopi;
int error;


void pretragaPoProizziMod(string r) {
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	std::unique_ptr<string>p = std::make_unique<string>();
	std::unique_ptr<string>l = std::make_unique<string>();
	std::cout << "Unesite proizvodjaca za pretragu: ";
	getline(cin, *l);
	std::cout << "Unesite model za pretragu: ";
	getline(cin, *p);
	if (r == "Laptop") { temp->pretragaPoProizImodeluLap(*l, *p); }
}

void pretragaPoProiz(string r) {
	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
	std::unique_ptr<string>p = std::make_unique<string>();
	std::unique_ptr<string>l = std::make_unique<string>();
	std::cout << "Unesite proizvodjaca za pretragu: ";
	getline(cin, *l);
	if (r == "Laptop") { 
		temp->pretragaPoProiz(*l);
	}
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
//
//void login(string& admin, string& password) {
//	bool valid = false;adminP temp;
//	vector <adminP> vektor;
//	ifstream adminFile("admin.txt");
//	if (adminFile.is_open()) {
//
//		while (adminFile >> temp.adminUser) {
//			adminFile >> temp.adminPass;
//			vektor.push_back(temp);
//			if (vektor.size() >= 200)
//				break;
//		}
//	}
	//adminFile.close();
//	for (int i = 0; i < vektor.size(); i++) {
//		if (admin == vektor[i].adminUser && password == vektor[i].adminPass) {
//			cout << "\n\n" << setw(75) << "Uspjesno logirani na admin acc." << endl;
//			valid = true;
//			adminMenu();
//			break;
//			Sleep(2000);
//		}
//	}
//	if (!valid) {
//		cout << "\n\n" << setw(75) << "Username ili password nisu validni." << endl;
//		system("pause");
//		Sleep(2000);
//		system("CLS");
//	}
//
//}
//void dodajProfil() {
//
//	ofstream file;
//	file.open("kupac.txt", std::ios_base::app);
//	if (!file) {
//		cout << "\n" << setw(80) << "Nije moguce otvoriti datoteku!";
//		return;}
//	kupacP k;
//	cout << "\n" << setw(63) << "Username: ";cin >> k.kupacUser;
//	cout << "\n" << setw(63) << "Password: ";cin >> k.kupacPass;
//	file << " " << k.kupacUser << " ";
//	file << k.kupacPass << endl;
//	file.close();Sleep(1000);system("CLS");
//}
//void kupacLogin(string& user, string& password) {
//	bool valid = false;kupacP temp;
//	vector <kupacP> vektor;
//	ifstream kupacFile("kupac.txt");
//	if (kupacFile.is_open()) {
//		while (kupacFile >> temp.kupacUser) {
//			kupacFile >> temp.kupacPass;
//			vektor.push_back(temp);
//			if (vektor.size() >= 200)
//				break;}}
//	kupacFile.close();
//	for (int i = 0; i < vektor.size(); i++) {
//		if (user == vektor[i].kupacUser && password == vektor[i].kupacPass) {
//			cout << "\n\n" << setw(75) << "Uspjesno logirani na kupac acc." << endl;
//			kupacMenu();
//			valid = true;break;}
//		else if (user == "Guest" && password == "guest") {
//			cout << "\n\n" << setw(78) << "Uspjesno logirani na guest acc." << endl;
//			valid = true;break;}}
//	if (!valid) {
//		cout << "\n\n" << setw(78) << "Username ili password nisu validni." << endl;
//		system("pause");Sleep(2000);system("CLS");
//	}}


void pretragaOpcije() {
	system("pause");
	system("cls");
	cout << "\n\n" << setw(81) << "*****************************************" << endl;
	cout << setw(81) << "*     >>>>  PRETRAZI   PROIZVOD  <<<<     *" << endl;
	cout << setw(81) << "*****************************************" << endl;
	cin.clear();
	cout << "\n" << setw(79) << "Odaberite neku od ponudjenih opcija :";
	cout << "\n\n" << setw(73) << "1. Pretraga laptopa: ";
	cout << "\n" << setw(74) << "2. Pretraga mobitela: ";
	cout << "\n" << setw(81) << "3. Pretraga racunara: ";
	cout << "\n" << setw(83) << "0. Vrati se nazad\n";
}
void brisiOpcije() {
	system("pause");
	system("cls");
	cout << "\n\n" << setw(86) << "**********************************************" << endl;
	cout << setw(86) << "*     >>>>    IZBRISI    PROIZVOD    <<<<      *" << endl;
	cout << setw(86) << "**********************************************" << endl;
	cin.clear();
	cout << "\n" << setw(79) << "Odaberite neku od ponudjenih opcija :";
	cout << "\n\n" << setw(79) << "1. Brisanje laptopa: ";
	cout << "\n" << setw(80) << "2. Brisanje racunara: ";
	cout << "\n" << setw(80) << "2. Brisanje mobitela: ";
	cout << "\n" << setw(78) << "0. Vrati se na menu:\n";
}
void ispisOpcije() {
	system("pause");
	system("cls");
	cout << "\n\n" << setw(81) << "*****************************************" << endl;
	cout << setw(81) << "*     >>>>  ISPIS   PROIZVODA  <<<<     *" << endl;
	cout << setw(81) << "*****************************************" << endl;
	cin.clear();
	cout << "\n" << setw(79) << "Odaberite neku od ponudjenih opcija :";
	cout << "\n\n" << setw(73) << "1. Ispis svih proizvoda: ";
	cout << "\n" << setw(74) << "2. Ispis mobitela: ";
	cout << "\n" << setw(81) << "3. Ispis racunara: ";
	cout << "\n" << setw(81) << "3. Ispis laptopa: ";
	cout << "\n" << setw(83) << "0. Vrati se nazad\n";
}
void updateOpcije() {
	system("pause");
	system("cls");
	cout << "\n\n" << setw(86) << "************************************************" << endl;
	cout << setw(86) << "*      >>>>   AZURIRAJ PROIZVODE    <<<<      *" << endl;
	cout << setw(86) << "************************************************" << endl;
	cin.clear();
	cout << "\n" << setw(79) << "Odaberite neku od ponudjenih opcija :";
	cout << "\n\n" << setw(80) << "1. Azuriraj laptope : ";
	cout << "\n" << setw(80) << "2. Azuriraj mobitele: ";
	cout << "\n" << setw(80) << "3. Azuriraj racunare: ";
	cout << "\n" << setw(76) << "0. Vrati se na administratorski menu:\n";
}
void adminOpcije() {
	system("pause");
	system("cls");
	cout << "\n\n" << setw(81) << "*****************************************" << endl;
	cout << setw(81) << "* >>>>  DOBRO DOSLI NA ADMIN MENU  <<<< *" << endl;
	cout << setw(81) << "*****************************************" << endl;
	cin.clear();
	cout << "\n" << setw(79) << "Odaberite neku od ponudjenih opcija :";
	cout << "\n\n" << setw(69) << "1. Ispis odredjene vrste proizvoda: (onda da bira koji ce proizvod, te nakon odabira iste ispisati) ";
	cout << "\n" << setw(70) << "2. Prikazi sve proizvode: ";
	cout << "\n" << setw(66) << "3. Potrazi proizvod: ";
	cout << "\n" << setw(66) << "4. Izbrisi proizvod: ";
	cout << "\n" << setw(67) << "5. (U slucaju nabavke)Azuriraj broj proizvoda: ";
	cout << "\n" << setw(75) << "0. Vrati se na glavni menu:\n";
}
void adminMenu() {
	int odabir, odabirI, odabirA, odabirB, odabirP;
	do {
		adminOpcije();
		do {
			error = 0;
			cout << "\n" << setw(69) << "Upisi svoj izbor: ";
			cin >> odabir;
			if (odabir < 0 || odabir>8) {
				cout << setw(65) << "Unesite validan unos: " << endl;
				error = 1;
				cin.clear();
				cin.ignore();
			}
		} while (error == 1);
		cin.ignore();
		switch (odabir) {
		case 1: {odabir == 1; break;}
		case 2: //ispisProizvoda(); 
			break;
		case 3: odabir = 3; break;
		case 4: odabir = 4; break;
		case 0: {
			system("CLS");
		} break;
		default: cout << setw(62) << "[GRESKA] -> Unos nije validan!" << endl;
		}
		if (odabir == 1) {
			do {
				ispisOpcije();
				do {
					error = 0;
					cout << "\n" << setw(70) << "Unesite svoj izbor: ";
					cin >> odabirI;
					if (odabirI < 0 || odabirI>3) {
						cout << "Molimo za validan unos: ";
						error = 1;
						cin.clear();
						cin.ignore();
					}
				} while (error == 1);
				cin.ignore();
				switch (odabirI) {
				case 1: //ispislaptopa(); 
					break;
				case 2: //ispismobitela(); 
					break;
				case 3: //ispisracunara(); 
					break;
				case 0: {
					system("pause");
				}
				default: cout << "[GRESKA] -> Unos nije validan!" << endl;
				}
			} while (odabirI != 0);
		}
		if (odabir == 2) {
			do {
				pretragaOpcije();
				do {
					error = 0;
					cout << "\n" << setw(70) << "Unesite svoj izbor: ";
					cin >> odabirP;
					if (odabirP < 0 || odabirP>3) {
						cout << setw(65) << "Molimo za validan unos: ";
						error = 1;
						cin.clear();
						cin.ignore();
					}
				} while (error == 1);
				cin.ignore();
				switch (odabirP) {
				case 1: {
					pretragaPoProizziMod("Laptop");
					//pretragaLaptopa();
					break;
				}
				case 2: {
					//pretragaMobitela();
					break;
				}
				case 3: {
					//pretragaRacunara();
					break;
				}
				case 0: {
					system("pause");
				} break;
				default: cout << setw(62) << "[GRESKA] -> Unos nije validan!" << endl;
				}
			} while (odabirP != 0);
		}
		if (odabir == 4) {
			do {
				brisiOpcije();
				do {
					error = 0;
					cout << "\n" << setw(70) << "Unesite svoj izbor: ";
					cin >> odabirB;
					if (odabirB < 0 || odabirB>3) {
						cout << setw(62) << "Molimo za validan unos: ";
						error = 1;
						cin.clear();
						cin.ignore();
					}
				} while (error == 1);

				switch (odabirB) {
				case 1: {//ispislaptopa();
					//brisanjeOdredjenogLaptopa(); ----------------> dodati fju u laptop <--------------------
				}break;
				case 2: {//ispislaptopa();
					//brisanjeOdredjenogLaptopa(); ----------------> dodati fju u racunar <-------------------- 
				}break;
				case 3: {//ispislaptopa();
					//brisanjeOdredjenogLaptopa(); ----------------> dodati fju u mobitel <-------------------- 
				}break;
				case 0: {
					system("pause");
				} break;
				default: cout << "[GRESKA] -> Unos nije validan!" << endl;
				}
			} while (odabirB != 0);
		}
		if (odabir == 5) {
			do {
				updateOpcije();
				do {
					error = 0;
					cout << "\n" << setw(70) << "Unesite svoj izbor: ";
					cin >> odabirA;
					if (odabirA < 0 || odabirA>2) {
						cout << setw(62) << "Molimo za validan unos: ";
						error = 1;
						cin.clear();
						cin.ignore();
					}
				} while (error == 1);

				switch (odabirA) {
				case 1: {//ispislaptopa();
					//azuriranjeOdredjenogLaptopa(); ----------------> dodati fju u laptop, kao operator da se poveca broj <--------------------; 
				}
					  break;
				case 2: {//ispisMobitela();
					//azuriranjeOdredjenogMobitela(); ----------------> dodati fju u mobitel, kao operator da se poveca broj <--------------------; 
				}
					  break;
				case 3: {//ispisRacunara();
				//azuriranjeOdredjenogRacunara(); ----------------> dodati fju u mobitel, kao operator da se poveca broj <--------------------; 
				}
					  break;
				case 0: {
					system("pause");

				} break;
				default: cout << setw(62) << "[GRESKA] -> Unos nije validan!" << endl;
				}
			} while (odabirA != 0);
		}

	} while (odabir != 0);
}
void kupacOpcije() {
	system("pause");
	system("cls");
	cout << "\n\n" << setw(81) << "*****************************************" << endl;
	cout << setw(81) << "* >>>>  DOBRO DOSLI NA KUPAC MENU  <<<< *" << endl;
	cout << setw(81) << "*****************************************" << endl;
	cin.clear();
	cout << "\n" << setw(79) << "Odaberite neku od ponudjenih opcija :";
	cout << "\n" << setw(70) << "1. Prikazi sve proizvode : "; //ponuditi posebno ako zeli svaku vrstu proizvoda slicno kao kod admina
	cout << "\n" << setw(66) << "2. Potrazi proizvod: ";
	cout << "\n" << setw(63) << "3. Kupi knjigu: ";
	cout << "\n" << setw(75) << "0. Vrati se na glavni menu:\n";
}
void kupacMenu() {
	int odabir, odabirI, odabirP;
	do {
		kupacOpcije();
		do {
			error = 0;
			cout << "\n" << setw(69) << "Upisi svoj izbor: ";
			cin >> odabir;
			if (odabir < 0 || odabir>3) {
				cout << setw(65) << "Unesite validan unos: " << endl;
				error = 1;
				cin.clear();
				cin.ignore();
			}
		} while (error == 1);

		switch (odabir) {
		case 1: {
			odabir = 1;
		}break;
		case 2: odabir = 2; break;
		case 3: odabir = 3; break;
		case 0: {
			system("CLS");
		} break;
		default: cout << setw(62) << "[GRESKA] -> Unos nije validan!" << endl;
		}
		if (odabir == 1) {
			do {
				ispisOpcije();
				do {
					error = 0;
					cout << "\n" << setw(70) << "Unesite svoj izbor: ";
					cin >> odabirI;
					if (odabirI < 0 || odabirI>3) {
						cout << "Molimo za validan unos: ";
						error = 1;
						cin.clear();
						cin.ignore();
					}
				} while (error == 1);

				switch (odabirI) {
				case 1: //ispislaptopa(); 
					break;
				case 2: //ispismobitela(); 
					break;
				case 3: //ispisracunara(); 
					break;
				case 0: {
					system("pause");
				}
				default: cout << "[GRESKA] -> Unos nije validan!" << endl;
				}
			} while (odabirI != 0);
		}
		if (odabir == 2) {
			do {
				pretragaOpcije();
				do {
					error = 0;
					cout << "\n" << setw(70) << "Unesite svoj izbor: ";
					cin >> odabirP;
					if (odabirP < 0 || odabirP>3) {
						cout << setw(65) << "Molimo za validan unos: ";
						error = 1;
						cin.clear();
						cin.ignore();
					}
				} while (error == 1);

				switch (odabirP) {
				case 1: {
					pretragaPoProizziMod("Laptop");
					//pretragaLaptopa();
					break;
				}
				case 2: {
					//pretragaMobitela();
					break;
				}
				case 3: {
					//pretragaRacunara();
					break;
				}
				case 0: {
					system("pause");
				} break;
				default: cout << setw(62) << "[GRESKA] -> Unos nije validan!" << endl;
				}
			} while (odabirP != 0);
		}
		if (odabir == 3) {
			int x;
			do {
				cout << setw(83) << "Da li zelite kupiti knjigu (0 -ne, 1 - da)?  ";
				cin >> x;
				if (x == 0) break;
				else if (x == 1) break;//fkupiProizvod();  / break stavljen samo da ne izbacuje gresku
									/*------------> Razmisliti na koji nacin ovo realizovati <------------------------

									Mogucnosti/prijedlozi:
									1. Omoguciti odabir proizvoda, kucanjem svih informacija o njemu, te kreiranjem
									operatora -- samo smanjiti broj proizvoda i reci da je proizvod uspjesno kupljen.
									2. Ako budemo imali vremena napraviti sistem sa "placanjem preko kartice".

									*/
			} while (x < 0 || x>1);
		}
	} while (odabir != 0);

}


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
	cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << std::left << std::setw(15) << "Proizvodjac " << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolièina" <<
		std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
		<< std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(12) <<
		"RAM(GB) " << std::left << std::setw(10) << "HDD||SDD \n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
}

//
//void pretragaPoProizziMod(string r) {
//	std::shared_ptr<Laptop>temp = std::make_shared<Laptop>();
//	std::unique_ptr<string>p = std::make_unique<string>();
//	std::unique_ptr<string>l = std::make_unique<string>();
//	std::cout << "Unesite proizvodjaca za pretragu: ";
//	getline(cin, *l);
//	std::cout << "Unesite model za pretragu: ";
//	getline(cin, *p);
//	if (r == "Laptop") { temp->pretragaPoProizImodeluLap(*l, *p); }
//}

//
//void sortiranjePoSekundarnoj(){
//		std::ifstream unos("Laptop.txt");
//		std::vector<std::string>nizl;std::vector<int>hdd;std::string temp;int pom;std::string po;
//		int a, b, c, x, p = 0;
//		if (unos.fail())std::cout << "Nemoguce otvaranje datoeke\n";
//		else {
//			getline(unos, temp);getline(unos, temp);getline(unos, temp);
//			while (true) {
//				getline(unos, temp);
//				if (unos.eof())break;
//				nizl.push_back(temp);
//				a = temp[122] - '0';b = temp[123] - '0';c = temp[124] - '0';
//				if (a > -1 && b > -1 && c > -1) x = a * 100 + b * 10 + c + 1;
//				else if (a > -1 && b > -1 && c < -1) x = a * 10 + b;
//				else if (a > -1 && b < -1 && c < -1) x = a;
//				hdd.push_back(x);
//			}
//			for (int i = 0;i < hdd.size();i++) {
//				for (int j = i;j < hdd.size();j++) {
//					if (hdd[j] > hdd[i]) {
//						std::swap(hdd[j], hdd[i]);
//						std::swap(nizl[j], nizl[i]);
//					}}}
//			osnova();
//			for (int i = 0;i < hdd.size();i++)std::cout << nizl[i] << "\n";
//			unos.close();
//		}}


void stanjeK() {
	std::shared_ptr<Laptop>laptop = std::make_shared<Laptop>();
	cout << "Stanje kase za laptope:\n\t Trenutno stanje : " << !(*laptop)<<"\n";
}


void ispisLaptopa() {
	osnova();
	smjestizaIspis("Laptop");
}
void sortiranjeLaptopa(std::string rec) {
	std::ifstream unos("Laptop.txt");
	std::vector<std::string>nizl;
	std::vector<int>hdd;
	std::vector<int>godine;
	std::vector<int>cijena;
	std::vector<int>ram;
	std::string temp;
	std::string po;
	int a=0, b=0, c=0, d=0, x=0, p = 0;
	if (unos.fail())std::cout << "Nemoguce otvaranje datoeke\n";
	else {
		getline(unos, temp);
		getline(unos, temp);
		getline(unos, temp);
		while (true) {
			getline(unos, temp);
			if (unos.eof())break;
			nizl.push_back(temp);
			if (rec == "hdd") {
				a = temp[178] - '0';b = temp[179] - '0';c = temp[180] - '0';
				if (a > -1 && b > -1 && c > -1) x = a * 100 + b * 10 + c + 1;
				else if (a > -1 && b > -1 && c < -1) x = a * 10 + b;
				else if (a > -1 && b < -1 && c < -1) x = a;
				hdd.push_back(x);
			}
			if (rec == "ram") {
				a = temp[166] - '0';
				b = temp[167] - '0';
				c = temp[168] - '0';
				if (a > -1 && b > -1 && c > -1) x = a * 100 + b * 10 + c + 1;
				else if (a > -1 && b > -1 && c < -1) x = a * 10 + b;
				else if (a > -1 && b < -1 && c < -1) x = a;
				cout << a << " " << b << " " << c << " "  << x << "\n ";
				ram.push_back(x);
			}
			if (rec == "godine") {
				a = temp[51] - '0';
				b = temp[52] - '0';
				c = temp[53] - '0';
				d = temp[54] - '0';
				if (a > -1 && b > -1 && c > -1 && d > -1) x = a * 1000 + b * 100 + c * 10 + d;
				else if (a > -1 && b > -1 && c > -1 && d < -1) x = a * 100 + b * 10 + c;
				else if (a > -1 && b > -1 && c < -1 && d < -1) x = a * 10 + b;
				else if (a > -1 && b < -1 && c < -1 && d < -1) x = a;
				godine.push_back(x);
			}
			if (rec == "cijena") {
				a = temp[71] - '0';
				b = temp[72] - '0';
				c = temp[73] - '0';
				d = temp[74] - '0';
				if (a > -1 && b > -1 && c > -1 && d > -1) x = a * 1000 + b * 100 + c * 10 + d;
				else if (a > -1 && b > -1 && c > -1 && d < -1) x = a * 100 + b * 10 + c;
				else if (a > -1 && b > -1 && c < -1 && d < -1) x = a * 10 + b;
				else if (a > -1 && b < -1 && c < -1 && d < -1) x = a;
				cijena.push_back(x);
			}
		}
		if (rec == "hdd") {
			for (int i = 0;i < hdd.size();i++) {
				for (int j = i;j < hdd.size();j++) {
					if (hdd[j] > hdd[i]) {
						std::swap(hdd[j], hdd[i]);
						std::swap(nizl[j], nizl[i]);
					}}}
			osnova();
			for (int i = 0;i < hdd.size();i++)std::cout << nizl[i] << "\n";
		}
		if (rec == "ram") {
			for (int i = 0;i < ram.size();i++) {
				for (int j = i;j < ram.size();j++) {
					if (ram[j] > ram[i]) {
						std::swap(ram[j], ram[i]);
						std::swap(nizl[j], nizl[i]);
					}}}
			osnova();
			for (int i = 0;i < ram.size();i++)std::cout << nizl[i] << "\n";
		}if (rec == "godine") {
			for (int i = 0;i < godine.size();i++) {
				for (int j = i;j < godine.size();j++) {
					if (godine[j] > godine[i]) {
						std::swap(godine[j], godine[i]);
						std::swap(nizl[j], nizl[i]);
					}}}
			osnova();
			for (int i = 0;i < godine.size();i++)std::cout << nizl[i] << "\n";
		}
			if (rec == "cijena") {
				for (int i = 0;i < cijena.size();i++) {
					for (int j = i;j < cijena.size();j++) {
						if (cijena[j] > cijena[i]) {
							std::swap(cijena[j], cijena[i]);
							std::swap(nizl[j], nizl[i]);
						}}}
				osnova();
				for (int i = 0;i < cijena.size();i++)std::cout << nizl[i] << "\n";
			}
		unos.close();
	}
}




int main()
{
	stanjeK();
	int izbor=0,z=0,a=0,i=0;
	string user, password;
	//sortiranjeLaptopa("cijena");
	//pretragaPoProiz("Laptop");
	ispisLaptopa();
    sortiranjeLaptopa("ram");
	sortiranjeLaptopa("hdd");
	sortiranjeLaptopa("godine");
		//unosLaptopa();
	
	//ispisLaptopa();
	pretragaPoProizziMod("Laptop");
	
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
				adminMenu();
			}
			if (temp->login(user, password) == false) {
				cout<< "\nUsername ili password nisu validni.";
				system("pause");
				Sleep(2000);
				system("CLS");
			}

			/*cout << "\n" << setw(60) << "Username: ";
			cin >> user;
			cout << "\n" << setw(57) << "Sifra: ";
			password = unosPassworda(password);
			login(user, password);*/
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
				string kupac, password;
				std::shared_ptr<Kupac>temp = std::make_shared<Kupac>();
				cout << "Molim vas unesite kupac username: ";
				getline(cin,kupac);
				cout << "Sifra: ";
				password = temp->unosPassworda(password, 0);
				if (temp->login(kupac, password) == true) {
					cout << "\n\n" << setw(75) << "Uspjesno logirani na kupac acc." << endl;
					kupacMenu();
				}
				if (temp->login(kupac, password) == false) {
					cout << "\n\n" << setw(78) << "Username ili password nisu validni." << endl;
					system("pause");
					Sleep(2000);
					system("CLS");
				}
			}
			case 2: {
				std::shared_ptr<Kupac>k = std::make_shared<Kupac>();
				k->dodajProfil();
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
	
}
