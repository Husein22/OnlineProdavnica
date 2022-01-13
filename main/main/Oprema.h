#pragma once
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
class Oprema
{
private:
	std::string naziv, opis;
	int kolicina;
	float cijena;
public:
	static float troaskOp;
	static float prihofOp;
	Oprema();
	Oprema(std::string a, std::string b, int c);
	void setNaziv();
	void setOpis();
	void setKolicina();
	void setCijena();
	std::string getNaziv();
	std::string getOpis();
	int getKolicina();
	int getCijena();
	void prodajaOpreme();
	void adminProdajaOpreme();
	friend float operator!(Oprema& a);
	friend float operator*(Oprema& a);
	friend std::istream& operator>>(std::istream& stream, Oprema& a);
	friend std::ostream& operator<<(std::ostream& stream, Oprema& a);



	~Oprema() = default;
	
};

