#pragma once
#include"Artikal.h"
#include<iostream>
enum OperativniSistem  { Windows=0 ,Linux, Unix, Mac_OS, AmigaOS, GNOME};
class Laptop:
	public Artikal
{
private:
	std::string cpu, gpu;
	OperativniSistem opSis;
	std::string OperativniSistemNiz;
	int memorija, hard_drive;
public:
	static float stanje_kase;
	Laptop();
	Laptop(std::string a, std::string b, std::string c, int d, int e);
	//Laptop(const Laptop* p);
	void setCPU();
	void setGPU();
	void setOpSis();
	void setMemorija();
	void setHardDrivee();
	std::string getCPU();
	std::string getGPU();
	OperativniSistem getOpSis();
	std::string getOpsSisString();
	int getMemorija();
	int getHardDrive();
	void pretragaPoProizImodelu(std::string a,std::string b);
	void sortiranjePoSekundarnoj();
	friend float operator!(Laptop&a);
	friend std::istream& operator>>(std::istream& stream, Laptop& a);
	friend std::ostream& operator<<(std::ostream& stream, Laptop& a);
	


	~Laptop() = default;

};



