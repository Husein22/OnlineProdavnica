#include "Oprema.h"
#include <iostream>

Oprema::Oprema()
{
}

Oprema::Oprema(std::string a, std::string b, int c)
{
}

void Oprema::setNaziv()
{
	std::cout << "Unesite naziv opreme:";
	getline(std::cin, this->naziv);
}

void Oprema::setOpis()
{
	std::cout << "Unesite opis:";
	getline(std::cin, this->opis);
}

void Oprema::setKolicina()
{
	std::cout << "Unesite kolicnu:";
	std::cin >>this->kolicina;
	std::cin.ignore();
}

std::string Oprema::getNaziv()
{
	return this->naziv;
}

std::string Oprema::getOpis()
{
	return this->opis;
}

int Oprema::getKolicina()
{
	return this->kolicina;
}

void Oprema::prodajaOpreme()
{
}

void Oprema::adminProdajaOpreme()
{
}

float operator!(Oprema& a)
{
	return 0.0f;
}

float operator*(Oprema& a)
{


	return 0;
}

std::istream& operator>>(std::istream& stream, Oprema& a)
{

    std::ifstream some("Oprema.txt");
    std::string temp;
    some >> temp;
    int ID = -3;
    if (some.eof()) {
        some.close();
        std::ofstream upi("Oprema.txt");
        upi << "--------------------------------------------------------------------------------------------------------------------------------------\n";
        upi << std::left << std::setw(15) << "Naziv" << std::left << std::setw(10) << "Kolicina " 
            << std::left << std::setw(50) << "Opis \n";
        upi << "---------------------------------------------------------------------------------------------------------------------------------------\n";
        upi.close();
    }
    else some.close();

    std::ifstream unosID("Oprema.txt");
    if (unosID.is_open()) {
        std::string mobi;
        do {
            getline(unosID, mobi);           //ovim omogucujemo da se ID uvijek povecava za 1 prilikom unosenja novog pc
            ID++;
        } while (!unosID.eof());
        unosID.close();
    }
    else {
        std::cout << "Neuspjesno otvoren unosId\n";
    }
    std::ofstream upis("Oprema.txt", std::ios::app);
    if (upis.is_open()) {
        a.setNaziv();
        a.setKolicina();
        a.setOpis();
        std::vector<Oprema>op;
        std::ifstream cita("Oprema.txt");
        cita.open("PC.txt", std::ios::in);//ovaj dio programa nam smjesta iz datoteke PC.txt u niz,pa onda u vektor pc koji nam trebaju
        Oprema* niz = new Oprema[100];
        bool v = true;
        int u = 0;
        if (cita.is_open()) {

            getline(cita, temp);
            getline(cita, temp);
            getline(cita, temp);
            while (u != 1) {
                u++;

                for (int i = 0; i < ID - 3; i++) {
                    cita >> niz[i].naziv >> niz[i].kolicina >> niz[i].opis;
                    if (niz[i].naziv == a.getNaziv() && niz[i].kolicina == a.getKolicina() &&
                        niz[i].opis == a.getOpis()){
                        std::cout << "Posto indeticni navedeni artikal posjedujemo u skladistu dodali smo jos " << a.getKolicina() << " u skladiste\n";
                    std::cout << "Prije provmjene: " << niz[i].kolicina << " " << a.getKolicina() << "\n";
                    niz[i].kolicina = niz[i].kolicina + a.getKolicina();
                    std::cout << "Poslije provmjene: " << niz[i].kolicina << " " << a.getKolicina() << "\n";
                    v = false;
                }
                op.push_back(niz[i]);
            }
            
                }
            
            delete[] niz;//brisanje dinamicko alociranog niza zbog toga sto nam nece vise trebat
            cita.close();
        }
        else { std::cout << "Neuspjesno otvaranje datoteke \n"; }

        if (v == true) {
            upis << std::left << std::setw(15) << a.getNaziv();
            upis << std::left << std::setw(10) << a.getKolicina();
            upis << std::left << std::setw(20) << a.getOpis();
            upis << std::endl;
            std::cout << "[CESTITAMO]Uspjesno smjestene informacije u datoteku\n";

        }if (v == false) {
            std::ofstream piI("temp3OP.txt", std::ios::out);//pravljenje pomocne datoteke tempp.3PCtxt gdje cemo povecat kolicinu 
            if (piI.is_open()) {
                piI << "------------------------------------------------------------------------------------------\n";
                piI << std::left << std::setw(15) << "Naziv" << std::left << std::setw(10) << "Kolicina "
                    << std::left << std::setw(50) << "Opis \n";
               
                piI << "------------------------------------------------------------------------------------------\n";
                for (int i = 0; i < op.size(); i++) {
                    piI << std::left << std::setw(15) << op[i].naziv << std::left << std::setw(26) 
                        << std::left << std::setw(10) << op[i].kolicina
                        << std::left << std::setw(50) <<op[i].opis <<   "\n";
                }
                std::cout << "Uslo je u temp\n";
                piI.close();
            }
            else { std::cout << "[greska]Neuspjesno kreirana datoteka temp3PC.txt\n"; }
            remove("Oprema.txt");           //brise PC.txt
            rename("temp3OP.txt", "Oprema.txt");//temp3.txt je sada 
        }
        upis.close();
    }
    else {
        std::cout << "[GRESKA]Datoteka šravljenje pc nije otvorena\n";
    }


	return stream;
}

std::ostream& operator<<(std::ostream& stream, Oprema& a)
{

    std::string tempp;
    std::ifstream cit("Oprema.txt");
    int br = -3;
    if (cit.is_open()) {
        while (!cit.eof()) {
            getline(cit, tempp);
            br++;
            if (br == -1) {
                std::cout << std::left << std::setw(5) << "ID";
                std::cout << tempp << "\n";
            }
            if (br == 0 || br == -2) {
                std::cout << tempp << "------\n";
            }
            if (br > 0) {
                std::cout << std::left << std::setw(5) << br;
                std::cout << tempp << "\n";
            }
        }
        cit.close();

    }
    else {
        std::cout << "Neuspjesno otvaranje datoteke Oprema.txt\n";
    }

	return stream;
}
