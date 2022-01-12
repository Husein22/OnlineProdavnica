#include "PC.h"
 float PC::prihoPC=0;
 float PC::trosiPC = 0;

PC::PC()
{
}

PC::PC(std::string a, std::string b, int c, int d, float e, std::string f, std::string g, int kuc, int i, int j)
:Artikal(a, b, c, d, e), cpu(f), gpu(g), memorija(i), hard_drive(j)
{
    this->kuciste = static_cast<Kuciste>(kuc);
}

void PC::PosjedujemArtikal()
{
    std::string pom;
    int p = -3;
    std::ifstream pro("PC.txt");
    try {
        if (pro.is_open()) {
            while (!pro.eof()) {
                getline(pro, pom);
                ++p;
            }
            pro.close();
        }
        else {
            throw "Nazalost,neuspjesno otvaranje datotetke Laptop.txt\n";
        }
    }
    catch (const char* c) {
        std::cout << c;
    }
    std::cout << "\n\t                        " << p - 1 << " vrstu razlicitih PC\n";
}

void PC::setCPU()
{
    std::cout << "Unesite cpu PC-a: ";
    std::getline(std::cin, this->cpu);
}

void PC::setGPU()
{
    std::cout << "Unesite gpu PC-a: ";
    std::getline(std::cin, this->gpu);
}

void PC::setKuciste()
{

    int z = 0;
    std::cout << "Unesite operativni sistem(MS ELEMENT -0, CHASSIS INTER TECH B -1, GAMING KUĆIŠTE -2, MSF IGHTER V305 -3 , THERMALTAKE VIEW28 -4 , MS V315 Fighter RGB -5)\n";
    do {
        std::cout << "Unesite izbor: ";
        std::cin >> z;
        if (z > 5 || z < 0) {
            std::cout << "[GRESKA]Pogresan izbor\n";
        }
    } while (z < 0 || z > 5);
    this->kuciste = static_cast<Kuciste>(z);
}

void PC::setMemorija()
{
    std::cout << "Unesite kolicinu RAM memorije PC-a(GB): ";
    std::cin >> this->memorija;
    std::cin.ignore();
}

void PC::setHardDrivee()
{
    std::cout << "Unesite kolicinu sekundarane memorije(GB): ";
    std::cin >> this->hard_drive;
    std::cin.ignore();
}

std::string PC::getCPU()
{
    return this->cpu;
}

std::string PC::getGPU()
{
    return this->gpu;
}

Kuciste PC::getKuciste()
{
    return this->kuciste;
}

std::string PC::getKucisteString()
{
    switch (this->kuciste)
    {
    case 0:
        return "MS_ELEMENT";
        break;
    case 1:
        return "CHASSIS_INTER_TECH_B";
        break;
    case 2:
        return "GAMING_KUĆIŠTE";
        break;
    case 3:
        return "MS_FIGHTER_V305";
        break;
    case 5:
        return "MS_V315_Fighter_RGB";
        break;
    case 4:
        return "THERMALTAKE_VIEW28";
        break;
    default:
        break;
    }
}

int PC::getMemorija()
{
    return this->memorija;
}

int PC::getHardDrive()
{
    return this->hard_drive;
}

void PC::sortiranjePC(std::string rec)
{
    std::ifstream unos("PC.txt");
    std::vector<std::string>nizl;
    std::vector<int>hdd;
    std::vector<int>godine;
    std::vector<int>cijena;
    std::vector<int>ram;
    std::string temp;
    std::string po;
    int a = 0, b = 0, c = 0, d = 0, x = 0, p = 0;
    if (unos.fail())std::cout << "Nemoguce otvaranje datoeke\n";
    else {
        getline(unos, temp);
        getline(unos, temp);
        getline(unos, temp);
        while (true) {
            getline(unos, temp);
            if (unos.eof())break;
            nizl.push_back(temp);
            if (rec == "hdd") {
                a = temp[178] - '0';b = temp[179] - '0';c = temp[180] - '0';
                if (a > -1 && b > -1 && c > -1) x = a * 100 + b * 10 + c + 1;
                else if (a > -1 && b > -1 && c < -1) x = a * 10 + b;
                else if (a > -1 && b < -1 && c < -1) x = a;
                hdd.push_back(x);
            }
            if (rec == "ram") {
                a = temp[166] - '0';
                b = temp[167] - '0';
                c = temp[168] - '0';
                if (a > -1 && b > -1 && c > -1) x = a * 100 + b * 10 + c + 1;
                else if (a > -1 && b > -1 && c < -1) x = a * 10 + b;
                else if (a > -1 && b < -1 && c < -1) x = a;
                ram.push_back(x);
            }
            if (rec == "godine") {
                a = temp[51] - '0';
                b = temp[52] - '0';
                c = temp[53] - '0';
                d = temp[54] - '0';
                if (a > -1 && b > -1 && c > -1 && d > -1) x = a * 1000 + b * 100 + c * 10 + d;
                else if (a > -1 && b > -1 && c > -1 && d < -1) x = a * 100 + b * 10 + c;
                else if (a > -1 && b > -1 && c < -1 && d < -1) x = a * 10 + b;
                else if (a > -1 && b < -1 && c < -1 && d < -1) x = a;
                godine.push_back(x);
            }
            if (rec == "cijena") {
                a = temp[71] - '0';
                b = temp[72] - '0';
                c = temp[73] - '0';
                d = temp[74] - '0';
                if (a > -1 && b > -1 && c > -1 && d > -1) x = a * 1000 + b * 100 + c * 10 + d;
                else if (a > -1 && b > -1 && c > -1 && d < -1) x = a * 100 + b * 10 + c;
                else if (a > -1 && b > -1 && c < -1 && d < -1) x = a * 10 + b;
                else if (a > -1 && b < -1 && c < -1 && d < -1) x = a;
                cijena.push_back(x);
            }
        }
        if (rec == "hdd") {
            for (int i = 0;i < hdd.size();i++) {
                for (int j = i;j < hdd.size();j++) {
                    if (hdd[j] > hdd[i]) {
                        std::swap(hdd[j], hdd[i]);
                        std::swap(nizl[j], nizl[i]);
                    }
                }
            }
            //   osnova();
            for (int i = 0;i < hdd.size();i++)std::cout << nizl[i] << "\n";
        }
        if (rec == "ram") {
            for (int i = 0;i < ram.size();i++) {
                for (int j = i;j < ram.size();j++) {
                    if (ram[j] > ram[i]) {
                        std::swap(ram[j], ram[i]);
                        std::swap(nizl[j], nizl[i]);
                    }
                }
            }
            //    osnova();
            for (int i = 0;i < ram.size();i++)std::cout << nizl[i] << "\n";
        }if (rec == "godine") {
            for (int i = 0;i < godine.size();i++) {
                for (int j = i;j < godine.size();j++) {
                    if (godine[j] > godine[i]) {
                        std::swap(godine[j], godine[i]);
                        std::swap(nizl[j], nizl[i]);
                    }
                }
            }
            // osnova();
            for (int i = 0;i < godine.size();i++)std::cout << nizl[i] << "\n";
        }
        if (rec == "cijena") {
            for (int i = 0;i < cijena.size();i++) {
                for (int j = i;j < cijena.size();j++) {
                    if (cijena[j] > cijena[i]) {
                        std::swap(cijena[j], cijena[i]);
                        std::swap(nizl[j], nizl[i]);
                    }
                }
            }
            //osnova();
            for (int i = 0;i < cijena.size();i++)std::cout << nizl[i] << "\n";
        }
        unos.close();
    }
}

void PC::pretragaPoProizImodeluPC(std::string a, std::string b)
{
    std::string temp, z, pom;
    int p = 0, o = 0, l = -1;
    std::ifstream unos("PC.txt");
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
                    std::cout << std::left << std::setw(3) << "ID" << std::left << std::setw(15) << "Proizvodjac " << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolièina" <<
                        std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
                        << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Kuciste" << std::left << std::setw(12) <<
                        "RAM(GB) " << std::left << std::setw(10) << "HDD||SDD \n";
                    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    o++;
                }
                std::cout << std::left << std::setw(3) << l;
                std::cout << std::left << std::setw(15) << temp;
                std::cout << std::left << z;
                std::cout << pom << std::endl;
                p++;
            }
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

void PC::pretragaPoProizPC(std::string a)
{
    std::string temp, pom;
    int p = 0, o = 0, l = -3;
    std::ifstream unos("PC.txt");
    if (unos.is_open()) {
        while (!unos.eof()) {
            unos >> temp;
            getline(unos, pom);
            l++;
            if (temp == a) {
                if (o == 0)
                {
                    std::cout << "Uspjesno pronadjen artikal\n";
                    std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    std::cout << std::left << std::setw(3) << "ID" << std::left << std::setw(15) << "Proizvodjac " << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolièina" <<
                        std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
                        << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Kuciste" << std::left << std::setw(12) <<
                        "RAM(GB) " << std::left << std::setw(10) << "HDD||SDD \n";
                    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    o++;
                }
                std::cout << std::left << std::setw(3) << l;
                std::cout << std::left << temp;
                std::cout << pom << std::endl;
                p++;
            }
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

void PC::prodajaPC()
{
    std::string pom, pom2;
    std::vector<PC>pc;
    PC temp;
    int p = -3, ID = 0, kol = 0;//pomocne varijable koje ce nam trebat ovdje
    std::ifstream pro("PC.txt");//racuna broj laptopa
    if (pro.is_open()) {
        while (!pro.eof()) {
            getline(pro, pom);
            p++;
        }
        pro.close();
    }
    else {
        std::cout << "Nazalost,neuspjesno otvaranje datotetke PC.txt";
    }

    int t = -3;

    std::ifstream proo("NarudzbePC.txt");//racuna broj narudzbi
    if (proo.is_open()) {
        while (!proo.eof()) {
            getline(proo, pom2);
            t++;
        }
        proo.close();
    }
    else {
        std::cout << "Nazalost,neuspjesno otvaranje datotetke NarudzbePC.txt";
    }
    bool E = true;
    std::ifstream some("NarudzbePC.txt");
    std::string te;
    some >> te;
    if (some.eof()) {
        some.close();
        std::ofstream upi("NarudzbePC.txt");//postavlja prve 3 linije ako nam je datoteka prazna
        upi << "--------------------------------------------------------------------------------------------------------------\n";
        upi << std::left << std::setw(15) << "ID osobe" << std::left << std::setw(13) << "ID laptopa" << std::left <<
            std::setw(12) << "Kolicina: " << std::left << std::setw(15) << "Ime" << std::left << std::setw(15) << "Prezime " << std::left <<
            std::setw(15) << "Ziro racun" << std::setw(15) << "Adresa" << std::endl;
        upi << "---------------------------------------------------------------------------------------------------------------\n";
        
        upi.close();
    }
    else some.close();

        std::ofstream naruci("NarudzbePC.txt", std::ios::app);
        if (naruci.is_open()) {
            do {
                std::cout << "Unesite ID PC koji zelite kupiti: ";
                std::cin >> ID;
            } while (ID > p-1 || ID <= 0);
            std::cin.ignore();
            naruci << std::left << std::setw(15) << t++;
            naruci << std::left << std::setw(13) << ID;

            bool vrati = false, greska = true;
            pro.open("PC.txt", std::ios::in);//ovaj dio programa nam smjesta iz datoteke laptop,txt u niz,pa onda u vektor laptopi koji nam trebaju
            std::string t;
            PC* niz = new PC[100];
            int u = 0;
            if (pro.is_open()) {
                std::string upit;
                getline(pro, t);
                getline(pro, t);
                getline(pro, t);
                while (u != 1) {
                    u++;
                    for (int i = 0;i < p;i++) {
                        pro >> niz[i].proizvodjac >> niz[i].model >> niz[i].kolicina >> niz[i].godina_proiz >> niz[i].cijena >> niz[i].cpu >> niz[i].gpu >>
                            niz[i].KucisteNiz >> niz[i].memorija >> niz[i].hard_drive;
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
                                    std::cout << "Unesite kolicinu PC koji zelite kupiti: ";
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
                        pc.push_back(niz[i]);
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
                std::cout << "Hvala Vam na povjerenju,PC ce biti dostavljen brzom postom na adresu " << kupci->getAdresa() << " za manje od 24 sata.\nLijep i srdacan pozdrav (:\n";
                system("pause");
            }
        }
        else {
            std::cout << "Neuspjesno otvaranje datoteke\n";

        }
    


}

void PC::adminProdajaPC()
{
    std::string temp;
    int o = -3, idOs = 0, p = -1, kol = 0, l = 0, idLap = 0;//deklarisanje pomocnih varijabli koje ce nam trebat ovdje
    bool t=true;
    std::ifstream citaj("NarudzbePC.txt");//otvaranje datoteke narudzbe gdje se prikuplja broj linija u ovoj datoteci
    if (citaj.is_open()) {
        while (!citaj.eof()) {
            getline(citaj, temp);
            std::cout << temp << std::endl;
            o++;
        }
        citaj.close();
    }
    else {
        std::cout << "Neuspjesno otvaranje datoteke narudzbePC.txt\n";
    }
    if (o == 1) {
        t = false;
    }
    if (t == true) {

        do {
            std::cout << "Unesite ID osobe kojoj zelite poslati artikle;";
            std::cin >> idOs;
        } while (idOs<0 || idOs>o);//osigurava da se ne moze unijeti veci id od broja u narudzbama

        std::ifstream cit("NarudzbePC.txt", std::ios::in);//smjesta id osobe,laptopa te kolicinu,ovaj dio programa nam pamti te 3 varijable
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

        std::ifstream cita("PC.txt");//broj laptopa u datoteci laptop.txt
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
            std::cout << "Nazalost,neuspjesno otvaranje datotetke PC.txt";
        }

        cita.open("PC.txt", std::ios::in);//ovaj dio programa nam smjesta iz datoteke laptop,txt u niz,pa onda u vektor laptopi koji nam trebaju
        PC* niz = new PC[100];
        std::vector<PC>kreiraj;
        int u = 0;
        if (cita.is_open()) {
            getline(cita, temp);
            getline(cita, temp);
            getline(cita, temp);
            while (u != 1) {
                u++;
                std::cout << "d=" << d << "\n";
                for (int i = 0;i < d;i++) {
                    cita >> niz[i].proizvodjac >> niz[i].model >> niz[i].kolicina >> niz[i].godina_proiz >> niz[i].cijena >> niz[i].cpu >> niz[i].gpu >>
                        niz[i].KucisteNiz >> niz[i].memorija >> niz[i].hard_drive;
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

        std::ofstream pi("temppPC.txt", std::ios::out);//pravljenje pomocne datoteke tempp.txt gdje cemo smanjiti kolicinu 
        if (pi.is_open()) {
            pi << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
            pi << std::left << std::setw(15) << "Proizvodjac" << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolicina" <<
                std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
                << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Kuciste" << std::left << std::setw(12) <<
                "RAM(GB) " << std::left << std::setw(10) << "HDD||SSD \n";
            pi << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

            for (int i = 0;i < kreiraj.size();i++) {
                pi << std::left << std::setw(15) << kreiraj[i].proizvodjac << std::left << std::setw(26) << kreiraj[i].model
                    << std::left << std::setw(10) << kreiraj[i].kolicina << std::left << std::setw(20) << kreiraj[i].godina_proiz << std::left << std::setw(15) << kreiraj[i].cijena <<
                    std::left << std::setw(26) << kreiraj[i].cpu << std::left << std::setw(32) << kreiraj[i].gpu << std::left << std::setw(22) <<
                    kreiraj[i].KucisteNiz << std::left << std::setw(12) << kreiraj[i].memorija << std::left << std::setw(10) << kreiraj[i].hard_drive << "\n";
            }
            pi.close();
        }
        else { std::cout << "[greska]Neuspjesno kreirana datoteka temppPC.txt\n"; }

        remove("PC.txt");                 //brise Laptop.txt
        rename("temppPC.txt", "PC.txt");//tempp.txt je sada Laptop.txt
        std::cout << "Uspjesno temppPC stvoren i izbrisan PC\n";


        std::ofstream prihodi("PrihodiPC.txt", std::ios::app);
        std::ifstream novi("NarudzbePC.txt");
        int nizz[100], h;
        for (int i = 1;i < 100;i++) {
            nizz[i] = i;
        }
        std::string linija;
        int j = -3;
        if (novi.is_open()) {
            std::ofstream smjesti("tempoPC.txt", std::ios::out);
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
                std::cout << "Neuspjesno pravljenje tempoPC.txt\n";
            }

            novi.close();
        }
        else {
            std::cout << "Neuspjesno otvaranje datoteke NarudzbePC.txt\n";
        }
        remove("NarudzbePC.txt");                 //brise Narudzbe
        rename("tempoPC.txt", "NarudzbePC.txt");
        std::cout << "Izbrisan tempoPC\n";
        system("pause");
    }
else {
std::cout << "Nemamo narucenih racunara\n";
}

}

float operator!(PC& a)
{
    std::string temp;
    int  b=0, c=0, d=0, e=0, f=0, g=0, h=0, i = 0, p=0, j=0;
    std::ifstream unos("PC.txt");
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
            if (f > -1 && g > -1 && h > -1 && j > -1) i = f * 1000 + g * 100 + h * 10 + j;
            if (f > -1 && g > -1 && h > -1 && j < -1) i = f * 100 + g * 10 + h;
            else if (f > -1 && g > -1 && h < -1 && j < -1) i = f * 10 + g;
            else if (f > -1 && g < -1 && h < -1 && j < -1) i = f;
            p = i * e;
            PC::trosiPC -= p;
        }
        unos.close();
    }
    return PC::trosiPC;
}

float operator*(PC& a)
{
    std::ifstream datoteka("PrihodiPC.txt");
    std::string temp;
    int* idLap = new int[100];
    int* kol = new int[100];
    int i = 0;
    if (datoteka.is_open()) {
        getline(datoteka, temp);
        getline(datoteka, temp);
        getline(datoteka, temp);
        while (!datoteka.eof()) {
            datoteka >> idLap[i];
            datoteka >> kol[i];
            i++;
            getline(datoteka, temp);
        }
        datoteka.close();
    }
    else {
        std::cout << "Neuspjesno otvaranje daoteke PrihodiPC\n";
    }
    int br = -3, f = 0, g = 0, h = 0, j = 0, t = 0, u = 0, k = 0;
    float o = 0;
    std::string pomocni;
    std::ifstream lap("PC.txt");
    if (lap.is_open()) {
        while (k != i - 1) {
            getline(lap, pomocni);
            br++;
            if (br >= 0) {
                for (int s = 0;s < i;s++)
                {
                    if (br == idLap[s]) {
                        f = pomocni[71] - '0';
                        g = pomocni[72] - '0';
                        h = pomocni[73] - '0';
                        j = pomocni[74] - '0';
                        if (f > -1 && g > -1 && h > -1 && j > -1) t = f * 1000 + g * 100 + h * 10 + j;
                        if (f > -1 && g > -1 && h > -1 && j < -1)t = f * 100 + g * 10 + h;
                        else if (f > -1 && g > -1 && h < -1 && j < -1) t = f * 10 + g;
                        else if (f > -1 && g < -1 && h < -1 && j < -1) t = f;
                        o = t * kol[k];
                        k++;
                        PC::prihoPC += o;
                    }

                }
            }
        }
        lap.close();
    }
    else {
        std::cout << "Neuspjesno otvaranje datoteke Laptop.txt\n";
    }
    return PC::prihoPC;
}

std::istream& operator>>(std::istream& stream, PC& a)
{
    std::vector<PC>pc;
    std::ifstream some("PC.txt");
    std::string temp;
    some >> temp;
    int ID = -3;
    if (some.eof()) {
        some.close();
        std::ofstream upi("PC.txt");
        upi << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        upi << std::left << std::setw(15) << "Proizvodjac:" << std::left << std::setw(26) << "Model: " << std::left << std::setw(10) << "Kolièina:" <<
            std::left << std::setw(20) << "Godina proizvodnje: " << std::left << std::setw(15) << "Cijena(KM) :" << std::left << std::setw(10)
            << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Kuciste" << std::left << std::setw(12) <<
            "RAM(GB): " << std::left << std::setw(10) << "HDD||SDD: \n";
        upi << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        upi.close();
    }
    else some.close();
    std::ifstream unosID("PC.txt");
    if (unosID.is_open()) {
        std::string mobi;
        do {
            getline(unosID, mobi);           //ovim omogucujemo da se ID uvijek povecava za 1 prilikom unosenja novog mobitela
            ID++;
        } while (!unosID.eof());
        unosID.close();
    }
    else {
        std::cout << "Neuspjesno otvoren unosId\n";
    }
    std::ofstream upis("PC.txt", std::ios::app);
    if (upis.is_open()) {

        a.setProizvodjac();
        a.setModel();
        a.setKolicina();
        a.setGodinaProizvodnje();
        a.setCijena();
        a.setCPU();
        a.setGPU();
        a.setKuciste();
        a.setMemorija();
        a.setHardDrivee();

        std::ifstream cita("PC.txt");//broj laptopa u datoteci laptop.txt
        int d = 0;
        std::string pom;
        if (cita.is_open()) {
            while (!cita.eof()) {
                getline(cita, pom);
                d++;
            } cita.close();
        }
        else {
            std::cout << "Nazalost,neuspjesno otvaranje datotetke Laptop.txt";
        }


        cita.open("PC.txt", std::ios::in);//ovaj dio programa nam smjesta iz datoteke laptop,txt u niz,pa onda u vektor laptopi koji nam trebaju
        PC* niz = new PC[100];
        bool v = true;
        int u = 0;
        if (cita.is_open()) {

            getline(cita, temp);
            getline(cita, temp);
            getline(cita, temp);
            while (u != 1) {
                u++;
                for (int i = 0;i < d - 3;i++) {
                    cita >> niz[i].proizvodjac >> niz[i].model >> niz[i].kolicina >> niz[i].godina_proiz >> niz[i].cijena >> niz[i].cpu >> niz[i].gpu >>
                        niz[i].KucisteNiz >> niz[i].memorija >> niz[i].hard_drive;
                    if (niz[i].proizvodjac == a.getProizvodjac() && niz[i].model == a.getModel() && niz[i].godina_proiz == a.getGodinaProizvodnje() && niz[i].cijena == a.getCijena() &&
                        niz[i].cpu == a.getCPU() && niz[i].gpu == a.getGPU() && niz[i].KucisteNiz == a.getKucisteString() && niz[i].memorija == a.getMemorija() && niz[i].hard_drive == a.getHardDrive()) {
                        std::cout << "Posto indeticni navedeni artikal posjedujemo u skladistu dodali smo jos " << a.getKolicina() << " u skladiste\n";
                        std::cout << "Prije provmjene: " << niz[i].kolicina << " " << a.getKolicina() << "\n";
                        niz[i].kolicina = niz[i].kolicina + a.getKolicina();
                        std::cout << "Poslije provmjene: " << niz[i].kolicina << " " << a.getKolicina() << "\n";
                        v = false;
                    }
                    pc.push_back(niz[i]);
                }
            }
            delete[] niz;//brisanje dinamicko alociranog niza zbog toga sto nam nece vise trebat
            cita.close();
        }
        else { std::cout << "Neuspjesno otvaranje datoteke \n"; }

        if (v == true) {

            upis << std::left << std::setw(15) << a.getProizvodjac();
            upis << std::left << std::setw(26) << a.getModel();
            upis << std::left << std::setw(10) << a.getKolicina();
            upis << std::left << std::setw(20) << a.getGodinaProizvodnje();
            upis << std::left << std::setw(15) << a.getCijena();
            upis << std::left << std::setw(26) << a.getCPU();
            upis << std::left << std::setw(32) << a.getGPU();
            upis << std::left << std::setw(22) << a.getKucisteString();
            upis << std::left << std::setw(12) << a.getMemorija();
            upis << std::left << std::setw(10) << a.getHardDrive();
            upis << std::endl;
            upis.close();
            std::cout << "[CESTITAMO]Uspjesno smjestene informacije u datoteku\n";
        }if (v == false) {
            std::ofstream piI("temp3PC.txt", std::ios::out);//pravljenje pomocne datoteke tempp.txt gdje cemo povecat kolicinu 


            if (piI.is_open()) {
                piI << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                piI << std::left << std::setw(15) << "Proizvodjac" << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolicina" <<
                    std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) :" << std::left << std::setw(10)
                    << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(12) <<
                    "RAM(GB) " << std::left << std::setw(10) << "HDD||SDD \n";
                piI << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                for (int i = 0;i < pc.size() - 1;i++) {
                    piI << std::left << std::setw(15) << pc[i].proizvodjac << std::left << std::setw(26) << pc[i].model
                        << std::left << std::setw(10) << pc[i].kolicina << std::left << std::setw(20) << pc[i].godina_proiz << std::left << std::setw(15) << pc[i].cijena <<
                        std::left << std::setw(26) << pc[i].cpu << std::left << std::setw(32) << pc[i].gpu << std::left << std::setw(22) <<
                        pc[i].KucisteNiz << std::left << std::setw(12) << pc[i].memorija << std::left << std::setw(10) << pc[i].hard_drive << "\n";
                }
                piI.close();
                upis.close();
            }
            else { std::cout << "[greska]Neuspjesno kreirana datoteka temp2.txt\n"; }
            remove("PC.txt");           //brise PC.txt
            rename("temp3PC.txt", "PC.txt");//temp3PC.txt je sada PC.txt
            std::cout << "[CESTITAMO]Uspjesno povecana kolicina u skladistu\n";
        }


    }
    else {
        std::cout << "[GRESKA]Datoteka nije otvorena\n";
    }

    
    return stream;
}

std::ostream& operator<<(std::ostream& stream, PC& a)
{
    std::string tempp;
    std::ifstream cit("PC.txt");
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
        std::cout << "Neuspjesno otvaranje datoteke PC.txt\n";
    }


    return stream;
}
