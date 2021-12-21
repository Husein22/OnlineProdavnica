#include "Laptop.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
float Laptop::stanje_kase = 1000000;
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
    std::cout << "Unesite operativni sistem(0-Windows,Linux-1,Unix-2, Mac_OS-3, AmigaOS-4, GNOME-5)\n";
    do {
        std::cout << "Unesite izbor: ";
        std::cin >> z;
        if (z > 5 || z < 0) {
            std::cout << "[GRESKA]Pogresan izbor\n";
        }
    } while (z < 0 || z > 5);
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
    case 2:
        return "Unix";
        break;
    case 3:
        return "Mac_OS";
        break;
    case 4:
        return "AmigaOS";
        break;
    case 5:
        return " GNOME";
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
void Laptop::pretragaPoProizImodelu(std::string a,std::string b)
{   
    std::string temp;
    std::string z;
    int p = 0,o=0;
    std::ifstream unos("Laptop.txt");
    if (unos.is_open()) {
        while (!unos.eof()) {
            unos >> temp;
            unos >> z;
            if (temp == a && z == b) {
                if (o == 0)
                {
                    std::cout << "Uspjesno pronadjen artikal\n";
                    std::cout << "-----------------------------------------------------------------------------------------------------------------------------\n";
                    std::cout << std::left << std::setw(15) << "Proizvodjac:" << std::left << std::setw(10) << "Model: " << std::left << std::setw(10) << "Kolièina:" <<
                        std::left << std::setw(20) << "Godina proizvodnje: " << std::left << std::setw(15) << "Cijena(KM) :" << std::left << std::setw(10)
                        << std::left << std::setw(10) << "CPU" << std::left << std::setw(10) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(10) <<
                        "RAM(GB): " << std::left << std::setw(10) << "HDD||SDD: \n";
                    std::cout << "------------------------------------------------------------------------------------------------------------------------------\n";
                    o++;
                }
                std::cout << std::left << std::setw(15) << temp;
                std::cout << std::left  << z;
                getline(unos, temp);
                std::cout << temp<<std::endl;
                p++;
            }
            getline(unos, temp);
        }
        if (p == 0) {
            std::cout << "Nazalost nemamo taj model artikala u prodaji\n";
        }

        unos.close();
    }
    else {
        std::cout << "Neuspjesno otvaranje datoteke\n";
    }
}

void Laptop::sortiranjePoSekundarnoj()
{
    
    std::ifstream unos("Laptop.txt");
    std::vector<std::string>nizl;
    std::vector<int>hdd;
    std::string temp;
    int a, b, c,x;
    int p = 0;
    if (unos.fail()) {
        std::cout << "Nemoguce otvaranje datoeke\n";
    }
    else {
        getline(unos, temp);
        getline(unos, temp);
        getline(unos, temp);
        while (true) {
            getline(unos, temp);
            if (unos.eof())break;
            nizl.push_back(temp);
            a = temp[122] - '0';
            b = temp[123] - '0'; 
            c = temp[124] - '0';
            if (a > -1 && b > -1 && c > -1) x = a * 100 + b * 10 + c + 1;
            else if (a > -1 && b > -1 && c < -1) x = a * 10 + b ;
            else if (a > -1 && b < -1 && c < -1) x = a;
            std::cout << x<<" ";
            hdd.push_back(x);
        }
        std::cout << "\n";
        int pom;
        std::string po;
        for (int i = 0;i < hdd.size();i++) {
            std::cout << nizl[i] << "\n";
        }
        for (int i = 0;i < hdd.size();i++) {
            for (int j = i ;j < hdd.size();j++) {
                if (hdd[j] > hdd[i]) {
                    pom = hdd[i];
                    hdd[i] = hdd[j];
                    hdd[j] = pom;
                    po = nizl[i];
                    nizl[i] = nizl[j];
                    nizl[j] = pom;
                }
            }
        }
        for (int i = 0;i < hdd.size();i++) {
            std::cout << nizl[i]<<"\n";
        }
        unos.close();
    }
    

}




std::istream& operator>>(std::istream& stream, Laptop& a)
{
    std::ifstream some("Laptop.txt");
    std::string temp;
    some >> temp;
    int ID = -3;
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
    std::ifstream unosID("Laptop.txt");
    std::string mobi;
    do {
        getline(unosID, mobi);           //ovim omogucujemo da se ID uvijek povecava za 1 prilikom unosenja novog mobitela
        ID++;
    } while (!unosID.eof());
    unosID.close();
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


    std::string temp;
    std::ifstream ispis("Laptop.txt");
    while (ispis.eof()) {
        ispis >> temp;
        stream << temp;

    }
    ispis.close();


    /*stream<< std::left << std::setw(15) << a.getProizvodjac() << std::left << std::setw(10) << a.getModel() << std::left << std::setw(10) << a.getKolicina()<< 
        std::left << std::setw(20) << a.getGodinaProizvodnje() << std::left << std::setw(15) << a.getCijena()<< std::left << std::setw(10) << a.getCPU()
      << std::left << std::setw(10) << a.getGPU()<<
        std::left << std::setw(22) << a.getOpsSisString()<< std::left << std::setw(10) << a.getMemorija()<< std::left << std::setw(10) << a.getHardDrive()<< "\n";*/

    return stream;
}

float operator!(Laptop& a)
{
    std::string temp;
    int  b, c, d, e, f,g,h,i=0,p,j;
    std::ifstream unos("Laptop.txt");
    if (unos.fail()) {
        std::cout << "Neuspjesno otvaranje datoteke\n";
    }
    else {
        std::vector<int>cijena;std::vector<int>kolicina;
        std::vector<std::string>lap;
        getline(unos, temp);
        getline(unos, temp);
        getline(unos, temp);
        while (true) {
            getline(unos, temp);
            if (unos.eof())break;
            //lap.push_back(temp);
            b = temp[25] - '0';
            c = temp[26] - '0';
            d = temp[27] - '0';
            if (b > -1 && c > -1 && d > -1) e = b * 100 + c * 10 + d;
            else if (b > -1 && c > -1 && d < -1) e = b * 10 + c;
            else if (b > -1 && c < -1 && d < -1) e = b;
            f = temp[55] - '0';
            g = temp[56] - '0';
            h = temp[57] - '0';
            j = temp[58] - '0';
            if (f > -1 && g > -1 && h > -1 && j > -1) i = f * 1000 + g * 100 + h * 10 +j;
            if (f > -1 && g > -1 && h > -1 && j<-1) i = f * 100 + g * 10 + h;
            else if (f > -1 && g > -1 && h < -1&& j < -1) i = f * 10 + g;
            else if (f > -1 && g < -1 && h < -1&& j < -1) i = f;
            p = i * e;
            Laptop::stanje_kase -= p;

        }
        unos.close();
    }
    return Laptop::stanje_kase;
}
