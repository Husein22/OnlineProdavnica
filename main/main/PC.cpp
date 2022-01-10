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
    std::cout << "\n\t" << p-1 << " vrstu razlicitih PC\n";
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
        return " GAMING_KUĆIŠTE";
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
}

void PC::pretragaPoProizImodeluPC(std::string a, std::string b)
{
}

void PC::pretragaPoProizPC(std::string a)
{
}

void PC::prodajaPC()
{
}

void PC::adminProdajaPC()
{
}

float operator!(PC& a)
{
    return 0.0f;
}

float operator*(PC& a)
{
    return 0.0f;
}

std::istream& operator>>(std::istream& stream, PC& a)
{
   
    std::ifstream some("PC.txt");
    std::string temp;
    some >> temp;
    int ID = -3;
    if (some.eof()) {
        some.close();
        std::ofstream upi("PC.txt");
        upi << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        upi << std::left << std::setw(15) << "Proizvodjac" << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolicina" <<
            std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
            << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Kuciste" << std::left << std::setw(12) <<
            "RAM(GB) " << std::left << std::setw(10) << "HDD||SSD(GB) \n";
        upi << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
        upi.close();
    }
    else some.close();

    std::ifstream unosID("PC.txt");
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

        std::vector<PC>pc;
        std::ifstream cita("PC.txt");
        cita.open("PC.txt", std::ios::in);//ovaj dio programa nam smjesta iz datoteke PC.txt u niz,pa onda u vektor pc koji nam trebaju
        PC* niz = new PC[100];
        bool v = true;
        int u = 0;
        if (cita.is_open()) {

            getline(cita, temp);
            getline(cita, temp);
            getline(cita, temp);
            while (u != 1) {
                u++;
                
                    for (int i = 0;i < ID - 3;i++) {
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
            std::cout << "v=" << v<<"\n";
            std::cout << "[CESTITAMO]Uspjesno smjestene informacije u datoteku\n";
            
        }if(v==false) {
            std::ofstream piI("temp3PC.txt", std::ios::out);//pravljenje pomocne datoteke tempp.3PCtxt gdje cemo povecat kolicinu 
            if (piI.is_open()) {
                piI << "------------------------------------------------------------------------------------------------------------------------------\n";
                piI << std::left << std::setw(15) << "Proizvodjac" << std::left << std::setw(26) << "Model " << std::left << std::setw(10) << "Kolièina" <<
                    std::left << std::setw(20) << "Godina proizvodnje " << std::left << std::setw(15) << "Cijena(KM) " << std::left << std::setw(10)
                    << std::left << std::setw(26) << "CPU" << std::left << std::setw(32) << "GPU" << std::left << std::setw(22) << "Kuciste" << std::left << std::setw(12) <<
                    "RAM(GB) " << std::left << std::setw(10) << "HDD||SDD(GB) \n";
                piI << "------------------------------------------------------------------------------------------------------------------------------\n";
                for (int i = 0;i < pc.size();i++) {
                    piI << std::left << std::setw(15) << pc[i].proizvodjac << std::left << std::setw(26) << pc[i].model
                        << std::left << std::setw(10) << pc[i].kolicina << std::left << std::setw(20) << pc[i].godina_proiz << std::left << std::setw(15) << pc[i].cijena <<
                        std::left << std::setw(26) << pc[i].cpu << std::left << std::setw(32) << pc[i].gpu << std::left << std::setw(22) <<
                        pc[i].KucisteNiz << std::left << std::setw(12) << pc[i].memorija << std::left << std::setw(10) << pc[i].hard_drive << "\n";
                }
                std::cout << "Uslo je u temp\n";
                piI.close();
            }
            else { std::cout << "[greska]Neuspjesno kreirana datoteka temp3PC.txt\n"; }
            remove("PC.txt");           //brise PC.txt
            rename("temp3PC.txt", "PC.txt");//temp3.txt je sada Laptop.txt
        }
        upis.close();
    }
    else {
        std::cout << "[GRESKA]Datoteka šravljenje pc nije otvorena\n";
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
    system("pause");


    return stream;
}
