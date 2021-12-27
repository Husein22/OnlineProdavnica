#pragma once
#include <string>
using namespace std;
class Admin
{
private:
	string username, pass;
public:
	Admin();
	string unosPassworda(string password, int ch);
	bool login(string& admin, string& password);
	~Admin() = default;
};
