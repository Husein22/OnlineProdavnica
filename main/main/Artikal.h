#pragma once
#include <istream>
#include <string>
#include"Artikal.h"
#include <windows.h>
#include<iostream>
#include <algorithm>
#include<iostream>
#include<fstream>
#include<iomanip>
#include <vector>
#include <sstream>
#include "Kupac.h"
#include <windows.h>
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
	virtual void PosjedujemArtikal() = 0;
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
	virtual ~Artikal() = default;
};

