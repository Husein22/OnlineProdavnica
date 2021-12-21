#pragma once
//Proizvodjac:  Model:    Godina proizvodnje : RAM(GB) : ROM(GB) : Koli�ina : Cijena(KM) :
#include <istream>
#include <string>
class Artikal
{
protected:
	std::string proizvodjac,model;
	int kolicina,godina_proiz;
	float cijena;
public:
	//static float stanje_kase;
	Artikal();
	Artikal(std::string a, std::string b, int c, int d, float e);
	//Artikal(const Artikal& p);
	void setProizvodjac();
	void setModel();
	void setKolicina();
	void setGodinaProizvodnje();
	void setCijena();
	std::string getProizvodjac();
	std::string getModel();
	int getKolicina();
	int getGodinaProizvodnje();
	float getCijena();
	friend std::istream& operator>>(std::istream& stream, Artikal& a);
	friend std::ostream& operator<<(std::ostream& stream, Artikal& a);
	~Artikal() = default;
};

