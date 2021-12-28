#include "Laptop.h"
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include <vector>
#include <sstream>
#include <algorithm>
#include "Kupac.h"
#include <windows.h>
float Laptop::stanje_kase = 0;
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
        return "GNOME";
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
void Laptop::pretragaPoProizImodeluLap(std::string a,std::string b)
{   
    std::string temp,z,pom;
    int p = 0,o=0,l=-1;
    std::ifstream unos("Laptop.txt");
    if (unos.is_open()) {
        while (!unos.eof()) {
            unos >> temp;
            unos >> z;
            getline(unos, pom);
            l++;
            if (temp == a && z == b) {
                if (o == 0)
                {
                    std::cout << "Uspjesno pronadjen artikal\n";
                    std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    std::cout << std::left << std::setw(3) << "ID" <<std::left << std::setw(15) << "Proizvodjac " << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolièina" <<
                        std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
                        << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(12) <<
                        "RAM(GB) " << std::left << std::setw(10) << "HDD||SDD \n";
                    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    o++;
                }
                std::cout << std::left << std::setw(3) << l;
                std::cout << std::left << std::setw(15) << temp;
                std::cout << std::left  << z;
               // getline(unos, temp);
                std::cout << pom<<std::endl;
                p++;
            }
           // getline(unos, temp);
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

void Laptop::pretragaPoProiz(std::string a)
{
    std::string temp, pom;
    int p = 0, o = 0, l = -3;
    std::ifstream unos("Laptop.txt");
    if (unos.is_open()) {
        while (!unos.eof()) {
            unos >> temp;
            getline(unos, pom);
            l++;
            if (temp == a ) {
                if (o == 0)
                {
                    std::cout << "Uspjesno pronadjen artikal\n";
                    std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    std::cout << std::left << std::setw(3) << "ID" << std::left << std::setw(15) << "Proizvodjac " << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolièina" <<
                        std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
                        << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(12) <<
                        "RAM(GB) " << std::left << std::setw(10) << "HDD||SDD \n";
                    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    o++;
                }
                std::cout << std::left << std::setw(3) << l;
                std::cout << std::left  << temp;
                // getline(unos, temp);
                std::cout << pom << std::endl;
                p++;
            }
            // getline(unos, temp);
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


///*-------------------POTVRDI PRODAJU ARTIKLA (funkciju koju ima samo admin)---------------------*/
//void Laptop::prodajaLaptopa() {
//    //brisanje narudzbe iz datoteke narudzbe.txt
//    std::cin.ignore();
//    std::string line, name;
//    std::string tem;
//    std::unique_ptr<Kupac>kupci = std::make_unique<Kupac>();
//         //  kupci->setIme();
//     //naruci << std::left << std::setw(15) << kupci->getIme()
//    do {
//        kupci->setIme();
//        //cout << "Unesite ime i prezime osobe koja je narucila mobitel: ";
//       //getline(cin, name);
//    } while (kupci->getIme().length() < 1);    //ne moze se unijet prazan string
//   std:: ifstream narudzbe("narudzbe.txt", std::ios::in);
//    std::ofstream ispiss("tempp.txt");
//    while (getline(narudzbe, line))
//    {
//        if (line.substr(0, name.size()) != name) { //sve dok je razlicito od imena i prezimena koje smo unijeli
//            ispiss << line << std::endl;                //ispisuje liniju u datoteku 
//        }
//        else if (line.substr(0, name.size()) == name) { //ako se poklopi ime i prezime sa necim u datoteci
//            getline(narudzbe, tem);                     //preskace sljedecu liniju (ispod svake narudzbe u datoteci imaju linije zbog izgleda, ali je i njih potrebno izbrisati zajedno sa narudzbom)
//        }
//    }
//    narudzbe.close();
//    ispiss.close();
//    remove("narudzbe.txt");                 //brise narudzbe.txt
//    rename("tempp.txt", "narudzbe.txt");  //mijenja naziv temp.txt u skladiste.txt
//    std::string tenp;
//    std::ifstream unos("skladiste.txt");
//    int br1 = 0;
//    if (unos.is_open()) {
//        while (!unos.eof()) {
//            getline(unos, tenp);
//            br1++;
//        }
//        unos.close();
//    }
//
//    //smanjivanje kolièine za 1 iz datoteke skladiste.txt
//    unos.open("Laptop.txt", std::ios::in);
//    std::ofstream ispis("temp.txt");
//    std::string temp;
//    int ID;
//    do {
//        std::cout << "\nUnesite ID mobitela: ";
//        std::cin >> ID;
//    } while (ID<0 || ID>br1 - 4); //ne moze se unositi ID veci od onih u datoteci
//    int broj;
//    if (unos.fail()) std::cout << "Nemoguce otvoriti datoteku!" << std::endl;
//    else {
//        getline(unos, temp);
//        ispis << temp << std::endl;
//        getline(unos, temp);
//        ispis << temp << std::endl;
//        getline(unos, temp);
//        ispis << temp << std::endl;
//        while (true) {
//            unos >> broj;
//            if (unos.eof()) break;
//            if (broj == ID) {
//                ispis << std::left << std::setw(6) << broj;
//                unos >> temp;
//                ispis << std::setw(14) << temp;
//                unos >> temp;
//                ispis << std::setw(10) << temp;
//                unos >> temp;
//                ispis << std::setw(21) << temp;
//                unos >> temp;
//                ispis << std::setw(10) << temp;
//                unos >> temp;
//                ispis << std::setw(10) << temp;
//                unos >> broj;
//                ispis << std::setw(12) << broj - 1; // smanjujemo kolicinu iz datoteke za 1
//                unos >> temp;
//                ispis << std::setw(13) << temp << std::endl;
//            }
//            else {
//                ispis << broj;
//                getline(unos, temp);
//                ispis << temp << std::endl;
//            }
//        }
//    }
//    unos.close();
//    ispis.close();
//    remove("Laptop.txt");                     //brise skladiste.txt
//    rename("temp.txt", "Laptop.txt");        //mijenja naziv temp.txt u skladiste.txt
//    system("cls");
//    std::cout <<"-------------------------------------------------------\n";
//    std::cout << "\n\t\t\t\t  Loading...\n" << std::endl;
//    std::cout << "-------------------------------------------------------\n";
//    Sleep(2000);//ubaceno da bi se program malo zaustavio (loading) prije nego sto se ispise sljedeca poruka
//    system("cls");
//    std::cout << "-------------------------------------------------------\n";
//    std::cout << "\t      _____________________________________________________" << std::endl;
//    std::cout << "\t      |                                                   |" << std::endl;
//    std::cout << "\t      |            Artikal je uspjeno prodan!             |" << std::endl;
//    std::cout << "\t      | Brza posta je obavijestena za preuzimanje paketa. |" << std::endl;
//    std::cout << "\t      |___________________________________________________|\n" << std::endl;
//    std::cout << "-------------------------------------------------------\n";
//    system("PAUSE");
//    std::cin.ignore();
//    system("cls");
//   // provjeriNarudzbe();
//}
///*-------------------FUNKCIJA KOJU IZBACUJE KAD KUPAC ODABERE OPCIJU -Kupi artikal- ---------------------*/
////void KupiArtikal() {
////    string tenp;
////    ifstream unos("skladiste.txt");
////    int br1 = 0;
////    if (unos.is_open()) {
////        while (!unos.eof()) {
////            getline(unos, tenp);
////            br1++;
////        }
////        unos.close();
////    }
////    int izbor;
////    ofstream narudzba("narudzbe.txt", ios::app); //smjesta u posebnu datoteku narudzbe.txt koja je dostupna adminu
////    narudzba << "--------------------------------------------------------\n";
////    cout << crt;
////    do {
////        cout << "Unesite vase ime i prezime: ";
////        cin.ignore();
////        getline(cin, kupac.imePrezime);
////        narudzba << kupac.imePrezime << " ";
////    } while (kupac.imePrezime.length() < 1);
////    cout << crt;
////    do {
////        cout << "Unesite vasu adresu (npr. Zelenih-beretki-22-Sarajevo): ";
////        getline(cin, kupac.adresa);
////        narudzba << kupac.adresa << " ";
////    } while (kupac.adresa.length() < 1);
////    cout << crt;
////    do {
////        cout << "Unesite broj telefona: ";
////        getline(cin, kupac.brTel);
////        narudzba << kupac.brTel << " ";
////    } while (kupac.brTel.length() < 1);
////    cout << crt;
////    do {
////        cout << "Unesite ID mobitela koji zelite kupiti: ";
////        cin >> id;
////    } while (id<0 || id>br1 - 4);
////    narudzba << id << " ";
////    cout << crt;
////    cout << "Odaberite brzu postu: " << endl;
////    cout << crt;
////    cout << "\t\t";for (int i = 1;i <= 53;i++) { cout << "_"; };cout << endl;
////    cout << "\t\t|                                                   |" << endl;
////    cout << "\t\t| 1-EuroExpress (10 KM - isporuka u toku 24h)       |" << endl;
////    cout << "\t\t| 2-BH PostExpress (8 KM - isporuka u toku 24h-48h) |" << endl;
////    cout << "\t\t| 3-A2B Express (12 KM - isporuka u toku 24h)       |" << endl;
////    cout << "\t\t| 4-X Express (13 KM - isporuka u toku 24h)         |" << endl;
////    cout << "\t\t|___________________________________________________|\n" << endl;
////    cout << crt;
////    do {
////        cout << "\t\tIzbor: ";
////        cin >> izbor;
////    } while (izbor < 1 || izbor>4);
////    narudzba << vratiPostu(izbor);
////    narudzba << "\n--------------------------------------------------------";
////    narudzba.close();
////    system("cls");
////    cout << crt2;
////    cout << "\n\t\t\t\t  Loading...\n" << endl;
////    cout << crt2;
////    Sleep(2000);//ubaceno da bi se program malo zaustavio (loading) prije nego sto se ispise sljedeca poruka
////    system("cls");
////    cout << crt2;
////    cout << "\t\t  ";for (int i = 1;i <= 45;i++) { cout << "_"; };cout << endl;
////    cout << "\t\t  |                                           |" << endl;
////    cout << "\t\t  | Cestitamo, uspjesno ste narucili mobitel. |" << endl;
////    cout << "\t\t  | Paket ocekujte u roku od 48 sati.         |" << endl;
////    cout << "\t\t  | Vas MOBI-Shop, uvijek tu za vas!          |" << endl;
////    cout << "\t\t  |___________________________________________|\n" << endl;
////    cout << crt2;
////    system("PAUSE");
////    cin.ignore();
////    korisnickiMenu("korisnik");
////}
////





void Laptop::prodajaLaptopa()
{
    
    std::string pom;
    Laptop temp ;
    int p=0, ID = 0,kol=0;
    std::ifstream pro("Laptop.txt");
        if (pro.is_open()) {
            while (!pro.eof()) {
                getline(pro, pom);
                p++;
            }
            pro.close();
        }
        else {
            std::cout<< "Nazalost,neuspjesno otvaranje datotetke Laptop.txt";
        }
    





    std::ifstream some("Narudzbe.txt");
    std::string te;
    some >> te;
    if (some.eof()) {
        some.close();
        std::ofstream upi("Narudzbe.txt");
        upi << "--------------------------------------------------------------------------------------------------------------\n";
        upi << std::left << std::setw(15) << "Ime" << std::left << std::setw(15) << "Prezime " << std::left << std::setw(15) << "Ziro racun" << std::left << std::setw(15) << "ID laptopa" <<
            std::left << std::setw(10) << "Kolicina: " << std::endl;
        upi << "---------------------------------------------------------------------------------------------------------------\n";
        upi.close();
    }
    else some.close();



   std:: ofstream naruci("Narudzbe.txt", std::ios::app);
    if (naruci.is_open()) {
        do {
            std::cout << "Unesite ID laptopa koji zelite kupiti: ";
            std::cin >> ID;
        } while (ID > p || ID <= 0);
            std::cout << "Unesite kolicinu laptopa koji zelite kupiti: ";
            std::cin >> kol;
        std::cin.ignore();
        std::unique_ptr<Kupac>kupci = std::make_unique<Kupac>();
        kupci->setIme();
        naruci << std::left << std::setw(15) << kupci->getIme();
        kupci->setPrezime();
        naruci << std::left << std::setw(15) << kupci->getPrezime();
        kupci->setKartica();
        naruci << std::left << std::setw(15) << kupci->getKartica();
        naruci << std::left << std::setw(15) << ID;
        naruci << std::left << std::setw(10) <<kol;

        naruci << std::endl;

        naruci.close();
    }
    else {
        std::cout << "Neuspjesno otvaranje datoteke\n";
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
        upi << std::left << std::setw(15) << "Proizvodjac:" << std::left << std::setw(26) << "Model: " << std::left << std::setw(10) << "Kolièina:" <<
            std::left << std::setw(20) << "Godina proizvodnje: " << std::left << std::setw(15) << "Cijena(KM) :" << std::left << std::setw(10)
            << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(12) <<
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
            upis << std::left << std::setw(26) << a.getModel();
            a.setKolicina();
            upis << std::left << std::setw(10) << a.getKolicina();
            a.setGodinaProizvodnje();
            upis << std::left << std::setw(20) << a.getGodinaProizvodnje();
            a.setCijena();
            upis << std::left << std::setw(15) << a.getCijena();
            a.setCPU();
            upis << std::left << std::setw(26) << a.getCPU();
            a.setGPU();
            upis << std::left << std::setw(32) << a.getGPU();
            a.setOpSis();
            upis << std::left << std::setw(22) << a.getOpsSisString();
            a.setMemorija();
            upis << std::left << std::setw(12) << a.getMemorija();
            a.setHardDrivee();
            upis << std::left << std::setw(10) << a.getHardDrive();
            upis << std::endl;
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
            b = temp[41] - '0';
            c = temp[42] - '0';
            d = temp[43] - '0';
            if (b > -1 && c > -1 && d > -1) e = b * 100 + c * 10 + d;
            else if (b > -1 && c > -1 && d < -1) e = b * 10 + c;
            else if (b > -1 && c < -1 && d < -1) e = b;
            f = temp[71] - '0';
            g = temp[72] - '0';
            h = temp[73] - '0';
            j = temp[74] - '0';
            if (f > -1 && g > -1 && h > -1 && j > -1) i = f * 1000 + g * 100 + h * 10 +j;
            if (f > -1 && g > -1 && h > -1 && j<-1) i = f * 100 + g * 10 + h;
            else if (f > -1 && g > -1 && h < -1&& j < -1) i = f * 10 + g;
            else if (f > -1 && g < -1 && h < -1&& j < -1) i = f;
            p = i * e;
            std::cout << p << "\n";
            Laptop::stanje_kase -= p;

        }
        unos.close();
    }
    return Laptop::stanje_kase;
}
