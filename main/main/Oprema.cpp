#include "Oprema.h"
#include <iostream>
float Oprema::prihofOp=0;
float Oprema::troaskOp=0;
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

void Oprema::setCijena()
{
    std::cout << "Unesite cijenu artikla:";
    std::cin >> this->cijena;
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

int Oprema::getCijena()
{
    return this->cijena;
}

void Oprema::prodajaOpreme()
{
    std::vector<Oprema>op;
    std::string pom, pom2;
    Oprema temp;
    int p = -3, ID = 0, kol = 0;//pomocne varijable koje ce nam trebat ovdje
    std::ifstream pro("Oprema.txt");//racuna broj laptopa
    if (pro.is_open()) {
        while (!pro.eof()) {
            getline(pro, pom);
            p++;
        }
        pro.close();
    }
    else {
        std::cout << "Nazalost,neuspjesno otvaranje datotetke Oprema.txt";
    }

    int t = -3;

    std::ifstream proo("NarudzbeOp.txt");//racuna broj narudzbi
    if (proo.is_open()) {
        while (!proo.eof()) {
            getline(proo, pom2);
            t++;
        }
        proo.close();
    }
    else {
        std::cout << "Nazalost,neuspjesno otvaranje datotetke NarudzbeOp.txt";
    }
    bool e = true;
    std::ifstream some("NarudzbeOp.txt");
    std::string te;
    some >> te;
    if (some.eof()) {
        some.close();
        std::ofstream upi("NarudzbeOp.txt");//postavlja prve 3 linije ako nam je datoteka prazna
        upi << "--------------------------------------------------------------------------------------------------------------\n";
        upi << std::left << std::setw(15) << "ID osobe" << std::left << std::setw(13) << "ID opreme" << std::left <<
            std::setw(12) << "Kolicina: " << std::left << std::setw(15) << "Ime" << std::left << std::setw(15) << "Prezime " << std::left <<
            std::setw(15) << "Ziro racun" << std::setw(15) << "Adresa" << std::endl;
        upi << "---------------------------------------------------------------------------------------------------------------\n";
        upi.close();
    }
    else some.close();

    std::ofstream naruci("NarudzbeOp.txt", std::ios::app);
    if (naruci.is_open()) {
        do {
            std::cout << "Unesite ID opreme koji zelite kupiti: ";
            std::cin >> ID;
        } while (ID > p - 1 || ID <= 0);
        std::cin.ignore();
        naruci << std::left << std::setw(15) << t++;
        naruci << std::left << std::setw(13) << ID;

        bool vrati = false, greska = true;
        pro.open("Oprema.txt", std::ios::in);//ovaj dio programa nam smjesta iz datoteke laptop,txt u niz,pa onda u vektor laptopi koji nam trebaju
        std::string t;
        Oprema* niz = new Oprema[100];
        int u = 0;
        if (pro.is_open()) {
            std::string upit;
            getline(pro, t);
            getline(pro, t);
            getline(pro, t);
            while (u != 1) {
                u++;
                for (int i = 0;i < p;i++) {
                    pro >> niz[i].naziv >> niz[i].kolicina >> niz[i].cijena >> niz[i].opis;
                    if (i == ID - 1) {
                        if (niz[i].kolicina == 1) {
                            std::cout << "Nazalost nemamo vise tog modela u nasem skladistu,preporuka da pogledate nase druge modele(:\n";
                            system("pause");
                            greska = false;
                            vrati = true;
                        }
                        else
                        {
                            do {
                                std::cout << "Unesite kolicinu opreme koji zelite kupiti: ";
                                std::cin >> kol;
                                std::cin.ignore();
                                if (niz[i].kolicina <= kol) {
                                    std::cout << "Nazalost nemamo toliku kolicinu,mozete kupiti najvise " << niz[i].kolicina - 1 << " artikala\n";
                                    std::cout << "Da li zelite kupiti ponudjenu kolicinu artikala?\n";
                                    do {
                                        std::cout << "Unesite izbor(DA,NE): ";
                                        getline(std::cin, upit);
                                        if (upit != "DA" && upit != "NE") {
                                            std::cout << "[GRESKA]Unesite DA ili NE\n";
                                        }
                                    } while (upit != "DA" && upit != "NE");
                                    if (upit == "DA") {
                                        vrati = true;
                                        kol = niz[i].kolicina - 1;
                                    }
                                    else {
                                        vrati = false;
                                    }
                                }
                                else {
                                    vrati = true;
                                }
                            } while (kol <= 0 || vrati != true);
                        }
                    }
                    op.push_back(niz[i]);
                }
            }
            delete[] niz;//brisanje dinamicko alociranog niza zbog toga sto nam nece vise trebat
            pro.close();
        }
        else { std::cout << "Neuspjesno otvaranje datoteke \n"; }

        if (greska == true) {
            naruci << std::left << std::setw(12) << kol;
            std::unique_ptr<Kupac>kupci = std::make_unique<Kupac>();
            kupci->setIme();
            naruci << std::left << std::setw(15) << kupci->getIme();
            kupci->setPrezime();
            naruci << std::left << std::setw(15) << kupci->getPrezime();
            kupci->setKartica();
            naruci << std::left << std::setw(15) << kupci->getKartica();
            kupci->setAdresa();
            naruci << std::left << std::setw(15) << kupci->getAdresa();
            naruci << std::endl;

            naruci.close();
            system("cls");
            std::cout << "Vrsi se transakcija novca.....\n";
            Sleep(2000);
            system("cls");
            std::cout << "Hvala Vam na povjerenju,laptop ce biti dostavljen brzom postom na adresu " << kupci->getAdresa() << " za manje od 24 sata.\nLijep i srdacan pozdrav (:\n";
            system("pause");
        }
    }
    else {
        std::cout << "Neuspjesno otvaranje datoteke\n";


    }
}

void Oprema::adminProdajaOpreme()
{
    std::string temp;
    int o = -3, idOs = 0, p = -1, kol = 0, l = 0, idLap = 0;//deklarisanje pomocnih varijabli koje ce nam trebat ovdje
    bool t = true;
    std::ifstream citaj("NarudzbeOp.txt");//otvaranje datoteke narudzbe gdje se prikuplja broj linija u ovoj datoteci
    if (citaj.is_open()) {
        while (!citaj.eof()) {
            getline(citaj, temp);
            std::cout << temp << std::endl;
            o++;
        }
        citaj.close();
    }
    else {
        std::cout << "Neuspjesno otvaranje datoteke narudzbeOp.txt\n";
    }
    if (o == 1) {
        t = false;
    }
    if (t == true) {


        do {
            std::cout << "Unesite ID osobe kojoj zelite poslati artikle;";
            std::cin >> idOs;
        } while (idOs<0 || idOs>o);//osigurava da se ne moze unijeti veci id od broja u narudzbama

        std::ifstream cit("NarudzbeOp.txt", std::ios::in);//smjesta id osobe,opreme te kolicinu,ovaj dio programa nam pamti te 3 varijable
        if (cit.is_open()) {
            while (!cit.eof()) {
                getline(cit, temp);
                p++;
                if (p == idOs) {
                    getline(cit, temp);
                    cit >> l;
                    cit >> idLap;
                    cit >> kol;
                }
            }
            cit.close();
        }
        else {
            std::cout << "Neuspjesno otvaranje datoteke narudzbe.txt\n";
        }

        std::ifstream cita("Oprema.txt");//broj laptopa u datoteci laptop.txt
        int d = 0;
        std::string pom;
        if (cita.is_open()) {
            getline(cita, pom);getline(cita, pom);getline(cita, pom);
            while (!cita.eof()) {

                getline(cita, pom);
                d++;
            } cita.close();
        }
        else {
            std::cout << "Nazalost,neuspjesno otvaranje datotetke Oprema.txt";
        }

        cita.open("Oprema.txt", std::ios::in);//ovaj dio programa nam smjesta iz datoteke laptop,txt u niz,pa onda u vektor laptopi koji nam trebaju
        Oprema* niz = new Oprema[100];
        std::vector<Oprema>kreiraj;
        int u = 0;
        if (cita.is_open()) {
            getline(cita, temp);
            getline(cita, temp);
            getline(cita, temp);
            while (u != 1) {
                u++;
                std::cout << "d=" << d << "\n";
                for (int i = 0;i < d-1;i++) {
                    cita >> niz[i].naziv >> niz[i].kolicina >> niz[i].cijena >> niz[i].opis;
                    if (i == idLap - 1) {
                        niz[i].kolicina = niz[i].kolicina - kol;
                        std::cout << "[CESTITAMO]Uspjesno smanjena kolicina\n";
                    }
                    kreiraj.push_back(niz[i]);
                }
            }
            delete[] niz;//brisanje dinamicko alociranog niza zbog toga sto nam nece vise trebat
            cita.close();
        }
        else { std::cout << "Neuspjesno otvaranje datoteke \n"; }

        std::ofstream pi("temppOp.txt", std::ios::out);//pravljenje pomocne datoteke tempp.txt gdje cemo smanjiti kolicinu 
        if (pi.is_open()) {
            pi << "------------------------------------------------------------------------------------------\n";
            pi << std::left << std::setw(15) << "Naziv" << std::left << std::setw(10) << "Kolicina " << std::setw(10) << "Cijena "
                << std::left << std::setw(30) << "Opis \n";
            pi << std::left<<"------------------------------------------------------------------------------------------\n";
            for (int i = 0;i < kreiraj.size();i++) {
                pi << std::left << std::setw(15) << kreiraj[i].naziv << std::left << std::setw(10) << kreiraj[i].kolicina
                    << std::left << std::setw(10) << kreiraj[i].cijena << std::left << std::setw(50) << kreiraj[i].opis << "\n";
            }
            pi.close();
        }
        else { std::cout << "[greska]Neuspjesno kreirana datoteka tempp.txt\n"; }

        remove("Oprema.txt");                 //brise Laptop.txt
        rename("temppOp.txt", "Oprema.txt");//tempp.txt je sada Laptop.txt
        std::cout << "Uspjesno tempp stvoren i izbrisan laptop\n";


        std::ofstream prihodi("PrihodiOp.txt", std::ios::app);
        std::ifstream novi("NarudzbeOp.txt");
        int nizz[100], h;
        for (int i = 1;i < 100;i++) {
            nizz[i] = i;
        }
        std::string linija;
        int j = -3;
        if (novi.is_open()) {
            std::ofstream smjesti("tempoOp.txt", std::ios::out);
            if (smjesti.is_open()) {
                while (j != o) {//sve dok ne prodjemo kroz datoteku narudzbe.txt
                    j++;
                    if (j < idOs) {
                        getline(novi, linija);
                        smjesti << linija << "\n";
                    } if (j == idOs) {
                        if (prihodi.is_open()) {
                            novi >> h;
                            getline(novi, linija);
                            prihodi << linija << "\n";
                            prihodi.close();
                        }
                        else {
                            std::cout << "Neuspjesno otvaranje datoteke prihodi\n";
                        }
                    }if (j > idOs) {
                        if (j < o) {
                            novi >> h;
                            smjesti << nizz[j - 1];
                            getline(novi, linija);
                            smjesti << std::left << linija << "\n";
                        }
                    }

                }
                smjesti.close();
            }
            else {
                std::cout << "Neuspjesno pravljenje tempo.txt\n";
            }

            novi.close();
        }
        else {
            std::cout << "Neuspjesno otvaranje datoteke Narudzbe.txt\n";
        }
        remove("NarudzbeOp.txt");                 //brise Narudzbe
        rename("tempoOp.txt", "NarudzbeOp.txt");
        std::cout << "Izbrisan tempo \n";
        system("pause");
    }
    else {
        std::cout << "Nazaloset nemamo narucenih oprema\n";
    }
}

float operator!(Oprema& a)
{
    Oprema::troaskOp = 0;
    std::string temp;
    int  b, c, d, e=0, f, g, h, i = 0, p, j;
    std::ifstream unos("Oprema.txt");
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
            b = temp[15] - '0';
            c = temp[16] - '0';
            d = temp[17] - '0';
            if (b > -1 && c > -1 && d > -1) e = b * 100 + c * 10 + d;
            else if (b > -1 && c > -1 && d < -1) e = b * 10 + c;
            else if (b > -1 && c < -1 && d < -1) e = b;
            f = temp[26] - '0';
            g = temp[27] - '0';
            h = temp[28] - '0';
            j = temp[29] - '0';
            if (f > -1 && g > -1 && h > -1 && j > -1) i = f * 1000 + g * 100 + h * 10 + j;
            if (f > -1 && g > -1 && h > -1 && j < -1) i = f * 100 + g * 10 + h;
            else if (f > -1 && g > -1 && h < -1 && j < -1) i = f * 10 + g;
            else if (f > -1 && g < -1 && h < -1 && j < -1) i = f;
            p = i * e;
            Oprema::troaskOp -= p;
        }
        unos.close();
    }
    return Oprema::troaskOp;
}

float operator*(Oprema& a)
{

    //std::ifstream datoteka("PrihodiL.txt");
    //std::string temp;
    //int* idLap = new int[100];
    //int* kol = new int[100];
    //int i = 0;
    //if (datoteka.is_open()) {
    //    getline(datoteka, temp);
    //    getline(datoteka, temp);
    //    getline(datoteka, temp);
    //    while (!datoteka.eof()) {
    //        datoteka >> idLap[i];
    //        datoteka >> kol[i];
    //        i++;
    //        getline(datoteka, temp);
    //    }
    //    datoteka.close();
    //}
    //else {
    //    std::cout << "Neuspjesno otvaranje daoteke PrihodiL\n";
    //}
    //int br = -3, f = 0, g = 0, h = 0, j = 0, t = 0, u = 0, k = 0;
    //float o = 0;
    //std::string pomocni;
    //std::ifstream lap("Laptop.txt");
    //if (lap.is_open()) {
    //    while (k != i - 1) {
    //        getline(lap, pomocni);
    //        br++;
    //        if (br >= 0) {
    //            for (int s = 0;s < i;s++)
    //            {
    //                if (br == idLap[s]) {
    //                    f = pomocni[71] - '0';
    //                    g = pomocni[72] - '0';
    //                    h = pomocni[73] - '0';
    //                    j = pomocni[74] - '0';
    //                    if (f > -1 && g > -1 && h > -1 && j > -1) t = f * 1000 + g * 100 + h * 10 + j;
    //                    if (f > -1 && g > -1 && h > -1 && j < -1)t = f * 100 + g * 10 + h;
    //                    else if (f > -1 && g > -1 && h < -1 && j < -1) t = f * 10 + g;
    //                    else if (f > -1 && g < -1 && h < -1 && j < -1) t = f;
    //                    o = t * kol[k];
    //                    k++;
    //                Oprema::prihofOp += o;
    //                }

    //            }
    //        }
    //    }
    //    lap.close();
    //}
    //else {
    //    std::cout << "Neuspjesno otvaranje datoteke Laptop.txt\n";
    //}


    //return Oprema::prihofOp;
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
        upi << "---------------------------------------------------------------------------------------------------------------\n";
        upi << std::left << std::setw(15) << "Naziv" << std::left << std::setw(10) << "Kolicina " << std::left << std::setw(10) << "Cijena"
            << std::left << std::setw(50) << "Opis \n";
        upi << std::left <<"-------------------------------------------------------------------------------------------------------------\n";
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
        a.setCijena();
        a.setOpis();
        std::vector<Oprema>op;
        std::ifstream cita("Oprema.txt");
        cita.open("Oprema.txt", std::ios::in);//ovaj dio programa nam smjesta iz datoteke PC.txt u niz,pa onda u vektor pc koji nam trebaju
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
                    cita >> niz[i].naziv >> niz[i].kolicina >>niz[i].cijena>> niz[i].opis;
                    if (niz[i].naziv == a.getNaziv() && niz[i].kolicina == a.getKolicina() && niz[i].cijena == a.getCijena() &&
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
            upis << std::left << std::setw(10) << a.getCijena();
            upis << std::left << std::setw(20) << a.getOpis();
            upis << std::endl;
            upis.close();
            std::cout << "[CESTITAMO]Uspjesno smjestene informacije u datoteku\n";

        }if (v == false) {
            std::ofstream piI("temp3OP.txt", std::ios::out);//pravljenje pomocne datoteke tempp.3PCtxt gdje cemo povecat kolicinu 
            if (piI.is_open()) {
                piI << "------------------------------------------------------------------------------------------\n";
                piI << std::left << std::setw(15) << "Naziv" << std::left << std::setw(10) << "Kolicina "<< std::setw(10) << "Cijena "
                    << std::left << std::setw(50) << "Opis \n";
               
                piI << "------------------------------------------------------------------------------------------\n";
                for (int i = 0; i < op.size(); i++) {
                    piI << std::left << std::setw(15) << op[i].naziv 
                        << std::left << std::setw(10) << op[i].kolicina << std::left << std::setw(10) << op[i].cijena
                        << std::left << std::setw(50) <<op[i].opis <<   "\n";
                }
                std::cout << "Uslo je u temp\n";
                piI.close();
                upis.close();
            }
            else { std::cout << "[greska]Neuspjesno kreirana datoteka temp3PC.txt\n"; }
            remove("Oprema.txt");           //brise PC.txt
            rename("temp3OP.txt", "Oprema.txt");//temp3.txt je sada 
        }
       
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
