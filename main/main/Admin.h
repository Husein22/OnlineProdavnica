#pragma once
#include <string>
using namespace std;
class Admin
{
private:
	string username, pass;
public:
	Admin();
	void setUsername();
	void setPass();
	std::string getUsername();
	std::string getPass();
	std::string unosPassworda(string password, int ch);
	bool login(string& admin, string& password);
	void citanjeAdmina();
	~Admin() = default;
};
