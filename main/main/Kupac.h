#pragma once
#include <string>

class Kupac
{
private:
	std::string username, pass,ime,prezime,kartica;
public:
	Kupac();
	Kupac(std::string a, std::string b, std::string c, std::string d, std::string e);
	void setusername();
	void setPass();
	void setIme();
	void setPrezime();
	void setKartica();
	std::string getUsername();
	std::string getPass();
	std::string getIme();
	std::string getPrezime();
	std::string getKartica();
	friend std::istream& operator>>(std::istream& stream, Kupac& a);
	friend std::ostream& operator<<(std::ostream& stream, Kupac& a);
	std::string unosPassworda(std::string password, int ch);
	bool login(std::string& admin, std::string& password);
	bool dodajProfil();
	~Kupac() = default;
};

