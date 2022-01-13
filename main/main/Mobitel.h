#pragma once
#include"Artikal.h"
enum OperativniSistemm {  Android=0,iOS, Windows_Phone, Symbian, Palm_OS};

class Mobitel
	:public Artikal
{
private:
	std::string cpu, display;
	OperativniSistemm opSis;
	std::string OperativniSistemNiz;
	int memorija, kamera;
public:
	static float trosiMob;
	static float prihodMob;
	Mobitel();
	Mobitel(std::string a, std::string b, int c, int d, float e, std::string f, std::string g, int op, int i, int j);
	//Laptop(const Laptop* p);
	void PosjedujemArtikal();
	void setCPU();
	void setDisplay();
	void setOpSis();
	void setMemorija();
	void setKmaera();
	std::string getCPU();
	std::string getDisplay();
	OperativniSistemm getOpSis();
	std::string getOpsSisString();
	int getMemorija();
	int getKmaera();
	void pretragaPoProizImodeluMob(std::string a, std::string b);
	void pretragaPoProizMob(std::string a);
	void prodajaMobitela();
	void adminProdajaMob();
	friend float operator!(Mobitel& a);
	friend float operator*(Mobitel& a);
	friend std::istream& operator>>(std::istream& stream, Mobitel& a);
	friend std::ostream& operator<<(std::ostream& stream, Mobitel& a);
	void sortiranjeMob(std::string rec);
	~Mobitel() = default;


};

