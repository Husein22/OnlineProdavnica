#include "Laptop.h"

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
        if (z > 1 || z < 0) {
            std::cout << "[GRESKA]Pogresan izbor\n";
        }
    } while (z >= 0 || z < 2);
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
    std::ostream upis("Laptop.txt";std::ios:app)
    a.setProizvodjac();
    a.setModel();
    a.setGodinaProizvodnje();
    a.setCijena();
    a.setCPU();
    a.setGPU();
    a.setOpSis();
    a.setMemorija();
    a.setHardDrivee();

    return stream;
}

std::ostream& operator<<(std::ostream& stream, Laptop& a)
{



    return stream;
}
