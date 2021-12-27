#include "Kupac.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <vector>
using namespace std;
Kupac::Kupac()
{
}
std::string Kupac::unosPassworda(std::string password, int ch)
{
	password.clear();
	while (ch = _getch()) {
		if (ch != 13) {
			std::cout << "*";
		}
		password += ch;
		if (ch == 13) {
			break;
		}
	}
	password.erase(password.length() - 1);
	return password;
}

bool Kupac::login(std::string& kupac, std::string& password)
{
	bool valid = false;
	string uname;
	string pword;
	Kupac temp;
	vector <Kupac> vektor;
	ifstream kupacFile("kupac.txt");
	if (kupacFile.is_open()) {
		while (!kupacFile.eof()) {
			kupacFile >> uname;
			kupacFile >> pword;
			temp.username = uname;
			temp.pass = pword;
			vektor.push_back(temp);
			if (vektor.size() >= 200)
				break;
		}
	}
	kupacFile.close();
	for (int i = 0; i < vektor.size(); i++) {
		if (kupac == vektor[i].username && password == vektor[i].pass) {
			return true;
			valid = true; 
			break;
		}
		else if (kupac == "Guest" && password == "guest") {
			cout << "\n\n" << setw(78) << "Uspjesno logirani na guest acc." << endl;
			valid = true;
			break;
		}
	}
	if (!valid) {
		return false;
		
	}
}
void Kupac::dodajProfil() {
	ofstream file;
	file.open("kupac.txt", std::ios_base::app);
	if (!file) {
		cout << "\n" << setw(80) << "Nije moguce otvoriti datoteku!";
		return;
	}
	Kupac k;
	cout << "\n" << setw(63) << "Username: "; cin >> k.username;
	cout << "\n" << setw(63) << "Password: "; cin >> k.pass;
	file << " " << k.username << " ";
	file << k.pass << endl;
	file.close(); Sleep(1000); system("CLS");
}

