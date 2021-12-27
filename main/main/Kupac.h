#pragma once
#include <string>

class Kupac
{
private:
	std::string username, pass;
public:
	Kupac();
	std::string unosPassworda(std::string password, int ch);
	bool login(std::string& admin, std::string& password);
	void dodajProfil();
	~Kupac() = default;
};

