#include "Mobitel.h"
 float Mobitel::trosiMob=0;
float Mobitel::prihodMob=0;
Mobitel::Mobitel()
{
}

Mobitel::Mobitel(std::string a, std::string b, int c, int d, float e, std::string f, std::string g, int op, int i, int j)
:Artikal(a, b, c, d, e), cpu(f), display(g), memorija(i), kamera(j)
{
    this->opSis = static_cast<OperativniSistemm>(op);

}

void Mobitel::PosjedujemArtikal()
{
    std::string pom;
    int p = -3;
    std::ifstream pro("Mobitel.txt");
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
    std::cout << "\n\t" << p - 1 << " vrstu razlicitih PC\n";
}

void Mobitel::setCPU()
{
    std::cout << "Unesite cpu mobitela: ";
    std::getline(std::cin, this->cpu);
}

void Mobitel::setDisplay()
{
    std::cout << "Unesite display mobitela: ";
    std::getline(std::cin, this->display);
}

void Mobitel::setOpSis()
{
    int z = 0;
    std::cout << "Unesite operativni sistem(Android -0,iOS -1, Windows_Phone -2 , Symbian -3 , Palm_OS -4)\n";
    do {
        std::cout << "Unesite izbor: ";
        std::cin >> z;
        if (z > 4 || z < 0) {
            std::cout << "[GRESKA]Pogresan izbor\n";
        }
    } while (z < 0 || z >4);
    this->opSis = static_cast<OperativniSistemm>(z);
}

void Mobitel::setMemorija()
{
    std::cout << "Unesite kolicinu RAM memorije(GB): ";
    std::cin >> this->memorija;
    std::cin.ignore();

}

void Mobitel::setKmaera()
{
    std::cout << "Unesite kameru(pixel): ";
    std::cin >> this->kamera;
    std::cin.ignore();
}

std::string Mobitel::getCPU()
{
    return this->cpu;
}

std::string Mobitel::getDisplay()
{
    return this->display;
}

OperativniSistemm Mobitel::getOpSis()
{
    return this->opSis;
}

std::string Mobitel::getOpsSisString()
{
    switch (this->opSis)
    {
    case 0:
        return "Android";
        break;
    case 1:
        return "iOS";
        break;
    case 2:
        return "Windows_Phone";
        break;
    case 3:
        return "Symbian";
        break;
    case 4:
        return "Palm_OS";
        break;
    default:
        break;
    }
}

int Mobitel::getMemorija()
{
    return this->memorija;
}

int Mobitel::getKmaera()
{
    return this->kamera;
}

void Mobitel::pretragaPoProizImodeluMob(std::string a, std::string b)
{
    std::string temp, z, pom;
    int p = 0, o = 0, l = -1;
    std::ifstream unos("Mobitel.txt");
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
                        << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(12) <<
                        "RAM(GB) " << std::left << std::setw(10) << "HDD||SDD \n";
                    std::cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                    o++;
                }
                std::cout << std::left << std::setw(3) << l;
                std::cout << std::left << std::setw(15) << temp;
                std::cout << std::left << z;
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

void Mobitel::pretragaPoProizMob(std::string a)
{
    std::string temp, pom;
    int p = 0, o = 0, l = -3;
    std::ifstream unos("Mobitel.txt");
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
                        << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Operativni Sistem" << std::left << std::setw(12) <<
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

void Mobitel::prodajaMobitela()
{
}

void Mobitel::adminProdajaMob()
{
}

void Mobitel::sortiranjeMob(std::string rec)
{
    std::ifstream unos("Mobitel.txt");
    std::vector<std::string>nizl;
    std::vector<int>kamera;
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
            if (rec == "kamera") {
                a = temp[178] - '0';b = temp[179] - '0';c = temp[180] - '0';
                if (a > -1 && b > -1 && c > -1) x = a * 100 + b * 10 + c + 1;
                else if (a > -1 && b > -1 && c < -1) x = a * 10 + b;
                else if (a > -1 && b < -1 && c < -1) x = a;
                kamera.push_back(x);
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
            for (int i = 0;i < kamera.size();i++) {
                for (int j = i;j < kamera.size();j++) {
                    if (kamera[j] > kamera[i]) {
                        std::swap(kamera[j], kamera[i]);
                        std::swap(nizl[j], nizl[i]);
                    }
                }
            }
            //   osnova();
            for (int i = 0;i < kamera.size();i++)std::cout << nizl[i] << "\n";
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

float operator!(Mobitel& a)
{
    std::string temp;
    int  b, c, d, e, f, g, h, i = 0, p, j;
    std::ifstream unos("Mobitel.txt");
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
            if (f > -1 && g > -1 && h > -1 && j > -1) i = f * 1000 + g * 100 + h * 10 + j;
            if (f > -1 && g > -1 && h > -1 && j < -1) i = f * 100 + g * 10 + h;
            else if (f > -1 && g > -1 && h < -1 && j < -1) i = f * 10 + g;
            else if (f > -1 && g < -1 && h < -1 && j < -1) i = f;
            p = i * e;
            Mobitel::trosiMob -= p;
        }
        unos.close();
    }
    return Mobitel::trosiMob;
}

float operator*(Mobitel& a)
{
    return 0.0f;
}

std::istream& operator>>(std::istream& stream, Mobitel& a)
{
    std::ifstream some("Mobitel.txt");
    std::string temp;
    some >> temp;
    int ID = -3;
    if (some.eof()) {
        some.close();
        std::ofstream upi("Mobitel.txt");
        upi << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        upi << std::left << std::setw(15) << "Proizvodjac" << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolicina" <<
            std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
            << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "Display" << std::left << std::setw(22) << "Operativni sistem" << std::left << std::setw(12) <<
            "RAM(GB) " << std::left << std::setw(10) << "Kamera(pix) \n";
        upi << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        upi.close();
    }
    else some.close();

    std::ifstream unosID("Mobitel.txt");
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
    std::ofstream upis("Mobitel.txt", std::ios::app);
    if (upis.is_open()) {

        a.setProizvodjac();
        a.setModel();
        a.setKolicina();
        a.setGodinaProizvodnje();
        a.setCijena();
        a.setCPU();
        a.setDisplay();
        a.setOpSis();
        a.setMemorija();
        a.setKmaera();

        std::vector<Mobitel>mob;
        std::ifstream cita("Mobitel.txt");
        cita.open("Mobitel.txt", std::ios::in);//ovaj dio programa nam smjesta iz datoteke Mobitel.txt u niz,pa onda u vektor pc koji nam trebaju
        Mobitel* niz = new Mobitel[100];
        bool v = true;
        int u = 0;
        if (cita.is_open()) {

            getline(cita, temp);
            getline(cita, temp);
            getline(cita, temp);
            while (u != 1) {
                u++;

                for (int i = 0;i < ID - 3;i++) {
                    cita >> niz[i].proizvodjac >> niz[i].model >> niz[i].kolicina >> niz[i].godina_proiz >> niz[i].cijena >> niz[i].cpu >> niz[i].display >>
                        niz[i].OperativniSistemNiz >> niz[i].memorija >> niz[i].kamera;
                    if (niz[i].proizvodjac == a.getProizvodjac() && niz[i].model == a.getModel() && niz[i].godina_proiz == a.getGodinaProizvodnje() && niz[i].cijena == a.getCijena() &&
                        niz[i].cpu == a.getCPU() && niz[i].display == a.getDisplay() && niz[i].OperativniSistemNiz == a.getOpsSisString() && niz[i].memorija == a.getMemorija() && niz[i].kamera == a.getKmaera()) {
                        std::cout << "Posto indeticni navedeni artikal posjedujemo u skladistu dodali smo jos " << a.getKolicina() << " u skladiste\n";
                        std::cout << "Prije provmjene: " << niz[i].kolicina << " " << a.getKolicina() << "\n";
                        niz[i].kolicina = niz[i].kolicina + a.getKolicina();
                        std::cout << "Poslije provmjene: " << niz[i].kolicina << " " << a.getKolicina() << "\n";
                        v = false;
                    }
                    mob.push_back(niz[i]);

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
            upis << std::left << std::setw(32) << a.getDisplay();
            upis << std::left << std::setw(22) << a.getOpsSisString();
            upis << std::left << std::setw(12) << a.getMemorija();
            upis << std::left << std::setw(10) << a.getKmaera();
            upis << std::endl;
            std::cout << "v=" << v << "\n";
            std::cout << "[CESTITAMO]Uspjesno smjestene informacije u datoteku\n";

        }if (v == false) {
            std::ofstream piI("temp3Mob.txt", std::ios::out);//pravljenje pomocne datoteke tempp.3PCtxt gdje cemo povecat kolicinu 
            if (piI.is_open()) {
                piI << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                piI << std::left << std::setw(15) << "Proizvodjac" << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolicina" <<
                    std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
                    << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "Display" << std::left << std::setw(22) << "Operativni sistem" << std::left << std::setw(12) <<
                    "RAM(GB) " << std::left << std::setw(10) << "Kamera(pix) \n";
                piI << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
                for (int i = 0;i < mob.size();i++) {
                    piI << std::left << std::setw(15) << mob[i].proizvodjac << std::left << std::setw(26) << mob[i].model
                        << std::left << std::setw(10) << mob[i].kolicina << std::left << std::setw(20) << mob[i].godina_proiz << std::left << std::setw(15) << mob[i].cijena <<
                        std::left << std::setw(26) << mob[i].cpu << std::left << std::setw(32) << mob[i].display << std::left << std::setw(22) <<
                       mob[i].OperativniSistemNiz << std::left << std::setw(12) << mob[i].memorija << std::left << std::setw(10) << mob[i].kamera << "\n";
                }
                std::cout << "Uslo je u temp\n";
                piI.close();
            }
            else { std::cout << "[greska]Neuspjesno kreirana datoteka temp3PC.txt\n"; }
            remove("MObitel.txt");           //brise PC.txt
            rename("temp3Mob.txt", "Mobitel.txt");//temp3.txt je sada Laptop.txt
        }
        upis.close();
    }
    else {
        std::cout << "[GRESKA]Datoteka šravljenje pc nije otvorena\n";
    }


    return stream;
}

std::ostream& operator<<(std::ostream& stream, Mobitel& a)
{
    std::string tempp;
    std::ifstream cit("Mobitel.txt");
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
        std::cout << "Neuspjesno otvaranje datoteke Mobitel.txt\n";
    }
    system("pause");
    return stream;
}
