#pragma once
#include"Artikal.h"
enum Kuciste { MS_ELEMENT=0, CHASSIS_INTER_TECH_B_42, GAMING_KUÆIŠTE, MS_FIGHTER_V305, THERMALTAKE_VIEW28, MS_V315_Fighter_RGB};
class PC
	:public Artikal
{
private:
	std::string cpu, gpu;
	Kuciste kuciste;
	std::string KucisteNiz;
	int memorija, hard_drive;
public:
	static float trosiPC;
	static float prihoPC;
	PC();
	PC(std::string a, std::string b, int c, int d, float e, std::string f, std::string g, int kuc, int i, int j);
	//Laptop(const Laptop* p);
	void PosjedujemArtikal();
	void setCPU();
	void setGPU();
	void setKuciste();
	void setMemorija();
	void setHardDrivee();
	std::string getCPU();
	std::string getGPU();
	Kuciste getKuciste();
	std::string getKucisteString();
	int getMemorija();
	int getHardDrive();
	void sortiranjePC(std::string rec);
	void pretragaPoProizImodeluPC(std::string a, std::string b);
	void pretragaPoProizPC(std::string a);
	void prodajaPC();
	void adminProdajaPC();
	friend float operator!(PC& a);
	friend float operator*(PC& a);
	friend std::istream& operator>>(std::istream& stream, PC& a);
	friend std::ostream& operator<<(std::ostream& stream, PC& a);
	~PC() = default;

};

