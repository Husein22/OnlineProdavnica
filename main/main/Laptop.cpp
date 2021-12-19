#include "Laptop.h"
#include<iostream>
#include<fstream>
#include<iomanip>
Laptop::Laptop()
{
}

Laptop::Laptop(std::string a, std::string b, std::string c, int d, int e)
{
}

void Laptop::setCPU()
{
    std::cout << "Unesite cpu laptopa: ";
    std::getline(std::cin, this->cpu);
}

void Laptop::setGPU()
{
    std::cout << "Unesite gpu laptopa: ";
    std::getline(std::cin, this->gpu);
}

void Laptop::setOpSis()
{
    int z = 0;
    std::cout << "Unesite operativni sistem(0-Windows,Linux-1)\n";
    do {
        std::cout << "Unesite izbor: ";
        std::cin >> z;
        if (z > 2 || z < 0) {
            std::cout << "[GRESKA]Pogresan izbor\n";
        }
    } while (z < 0 || z > 2);
    this->opSis = static_cast<OperativniSistem>(z);
}

void Laptop::setMemorija()
{
    std::cout << "Unesite kolicinu RAM memorije: ";
    std::cin >> this->memorija;
    std::cin.ignore();
}

void Laptop::setHardDrivee()
{
    std::cout << "Unesite kolicinu sekundarne memorije memorije: ";
    std::cin >> this->hard_drive;
    std::cin.ignore();
}

std::string Laptop::getCPU()
{
    return this->cpu;
}

std::string Laptop::getGPU()
{
    return this->gpu;
}

OperativniSistem Laptop::getOpSis()
{
    return this->opSis;
}

std::string Laptop::getOpsSisString()
{
    switch (this->opSis)
    {
    case 0:
        return "Windows";
        break;
    case 1:
        return "Linux";
        break;
    default:
        break;
    }
}

int Laptop::getMemorija()
{
    return this->memorija;
}

int Laptop::getHardDrive()
{
    return this->hard_drive;
}

std::istream& operator>>(std::istream& stream, Laptop& a)
{
    std::ifstream some("Laptop.txt");
    std::string temp;
    some >> temp;
    if (some.eof()) {
        some.close();
        std::ofstream upi("Laptop.txt");
        upi << "-----------------------------------------------------------------------------------------------------------------------------\n";
        upi << std::left << std::setw(15) << "Proizvodjac:" << std::left << std::setw(10) << "Model: " << std::left << std::setw(10) << "Kolièina:" <<
            std::left << std::setw(20) << "Godina proizvodnje: " << std::left << std::setw(15) << "Cijena(KM) :" << std::left << std::setw(10)
            << std::left << std::setw(10) << "CPU" << std::left << std::setw(10) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(10) <<
            "RAM(GB): " << std::left << std::setw(10) << "HDD||SDD: \n";
        upi << "------------------------------------------------------------------------------------------------------------------------------\n";
        upi.close();
    }
    else some.close();

    std::ofstream upis("Laptop.txt", std::ios::app);
    if (upis.is_open()) {
        
            a.setProizvodjac();
            upis << std::left << std::setw(15) << a.getProizvodjac();
            a.setModel();
            upis << std::left << std::setw(10) << a.getModel();
            a.setKolicina();
            upis << std::left << std::setw(10) << a.getKolicina();
            a.setGodinaProizvodnje();
            upis << std::left << std::setw(20) << a.getGodinaProizvodnje();
            a.setCijena();
            upis << std::left << std::setw(15) << a.getCijena();
            a.setCPU();
            upis << std::left << std::setw(10) << a.getCPU();
            a.setGPU();
            upis << std::left << std::setw(10) << a.getGPU();
            a.setOpSis();
            upis << std::left << std::setw(22) << a.getOpsSisString();
            a.setMemorija();
            upis << std::left << std::setw(10) << a.getMemorija();
            a.setHardDrivee();
            upis << std::left << std::setw(10) << a.getHardDrive();
            upis << "\n";
            std::cout << "[CESTITAMO]Uspjesno smjestene informacije u datoteku\n";
        }
    else {
        std::cout << "[GRESKA]Datoteka nije otvorena\n";
    }
    upis.close();
    return stream;
}

std::ostream& operator<<(std::ostream& stream, Laptop& a)
{
   
    stream<< std::left << std::setw(15) << a.getProizvodjac() << std::left << std::setw(10) << a.getModel() << std::left << std::setw(10) << a.getKolicina()<< 
        std::left << std::setw(20) << a.getGodinaProizvodnje() << std::left << std::setw(15) << a.getCijena()<< std::left << std::setw(10) << a.getCPU()
      << std::left << std::setw(10) << a.getGPU()<<
        std::left << std::setw(22) << a.getOpsSisString()<< std::left << std::setw(10) << a.getMemorija()<< std::left << std::setw(10) << a.getHardDrive()<< "\n";

    return stream;
}
