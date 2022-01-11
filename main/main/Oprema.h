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
public:
	Oprema();
	Oprema(std::string a, std::string b, int c);
	void setNaziv();
	void setOpis();
	void setKolicina();
	std::string getNaziv();
	std::string getOpis();
	int getKolicina();
	void prodajaOpreme();
	void adminProdajaOpreme();
	friend float operator!(Oprema& a);
	friend float operator*(Oprema& a);
	friend std::istream& operator>>(std::istream& stream, Oprema& a);
	friend std::ostream& operator<<(std::ostream& stream, Oprema& a);



	~Oprema() = default;
	
};

