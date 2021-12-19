#include "Artikal.h"
#include <iostream>
float Artikal:: stanje_kase=10000;
Artikal::Artikal()
{
}

Artikal::Artikal(std::string a, std::string b, int c, int d, float e):proizvodjac(a),model(b),kolicina(c),godina_proiz(d),cijena(e)
{
}

void Artikal::setProizvodjac()
{
    std::cout << "Unesite proizvodjaca: ";
    std::getline(std::cin, this->proizvodjac);
}

void Artikal::setModel()
{
    std::cout << "Unesite model: ";
    std::getline(std::cin, this->model);
}

void Artikal::setKolicina()
{
    std::cout << "Unesite kolicinu: ";
    std::cin >> this->kolicina;
    std::cin.ignore();
}

void Artikal::setGodinaProizvodnje()
{
    do {
        std::cout << "Unesite godinu proizvodnje: ";
        std::cin >> this->godina_proiz;
    } while (this->godina_proiz < 1|| this->godina_proiz>2022) ;
    std::cin.ignore();
}

void Artikal::setCijena()
{
    do {
        std::cout << "Unesite cijenu: ";
        std::cin >> this->cijena;
    } while (this->cijena < 1);
    Artikal::stanje_kase -= this->cijena;
    std::cin.ignore();
}

std::string Artikal::getProizvodjac()
{
    return this->proizvodjac;
}

std::string Artikal::getModel()
{
    return this->model;
}

int Artikal::getKolicina()
{
    return this->kolicina;
}

int Artikal::getGodinaProizvodnje()
{
    return this->godina_proiz;
}

float Artikal::getCijena()
{
    return this->cijena;
}

std::istream& operator>>(std::istream& stream, Artikal& a)
{



    return stream;
}

std::ostream& operator<<(std::ostream& stream, Artikal& a)
{



    return stream;
}
