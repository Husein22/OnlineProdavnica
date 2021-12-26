#include "Admin.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <windows.h>
#include <iomanip>
#include <vector>
using namespace std;

Admin::Admin()
{

}

/*void Admin::setUsername()
{
	cout << "Unesi username: ";
	cin >> this->username;
}

void Admin::setPass()
{
	cout << "Unesi pass: ";
	cin >> this->pass;
}

string Admin::getUsername()
{
	return this->username;
}

string Admin::getPass()
{
	return this->pass;
} */
string Admin::unosPassworda(string password, int ch) {

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
void Admin::login(string& admin, string& password) {

	bool valid = false;
	string uname;
	string pword;
	Admin temp;
	vector <Admin> vektor;
	try {
		ifstream adminFile("admin.txt");
		if (adminFile.is_open()) {

			while (!adminFile.eof()) {
				adminFile >> uname;
				adminFile >> pword;
				temp.username = uname;
				temp.pass = pword;
				vektor.push_back(temp);
				if (vektor.size() >= 200)
					break;
			}

		}
		adminFile.close();
		for (int i = 0; i < vektor.size(); i++) {
			if (admin == vektor[i].username && password == vektor[i].pass) {
				cout << "\n\n" << setw(75) << "Uspjesno logirani na admin acc." << endl;
				valid = true;
				//adminMenu();
				break;
				Sleep(2000);
			}
		}
		if (valid == false) {
			throw "Username ili password nisu validni.";
			system("pause");
			Sleep(2000);
			system("CLS");
		}
	}
	catch(const char*a) {
		cout << "\n\n" << setw(75) <<a << endl;
		system("pause");
		Sleep(2000);
		system("CLS");
	}

}