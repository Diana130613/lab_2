#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Computer
{
	string name{};
	float frequency = 0.;
	int amountRAM = 0;
	int hardDrive = 0;
	string monitorType{};
	float monitorSize = 0.;
	int price = 0;
};
int main() {
	setlocale(LC_ALL, "ru");
	Computer comp_1 = { "DEXP Atlas H393", 2, 8, 256, "LED", 17.3, 27499 };
	Computer comp_2 = { "Katana 17", 2, 16, 512, "IPS", 17.3, 92699 };
	Computer comp_3 = { "ASUS Vivobook X1704ZA", 1.3, 16, 512, "IPS", 17.3, 65999 };
	ofstream ofs("computers.bin", ios::binary);
	if (!ofs.is_open())
	{
		cerr << "Error" << endl; return 1;
	}
	ofs.write((char*)&comp_1, sizeof(Computer));
	ofs.write((char*)&comp_2, sizeof(Computer));
	ofs.write((char*)&comp_3, sizeof(Computer));
	ofs.close();
	if (ofs.fail())
	{
		cerr << "Error closing file after writing" << endl;
		return 1;
	}
	ifstream ifs("computers.bin", ios::binary);
	if (!ifs.is_open()) 
	{
		cerr << "Error opening file for reading" << endl; return 1;
	}
	if (!ifs.is_open()) {
		cerr << "Ошибка при открытии файла для чтения" << endl;
		return 1;
	}
	Computer comp;
	Computer maxComp;
	maxComp.amountRAM = 2; // Устанавливаем минимальный объем оперативной памяти
	while (ifs.read((char*)&comp, sizeof(Computer)))
	{
		if (comp.amountRAM >= maxComp.amountRAM) 
		{
			if (comp.amountRAM > maxComp.amountRAM || comp.frequency > maxComp.frequency) 
			{
				maxComp = comp;
			}
		}
	}ifs.close(); if (ifs.fail())
	{
		cerr << "Error closing file after reading" << endl;
		return 1;
	}
	cout << "Название компьютера: " << maxComp.name << endl; 
	cout << "Частота процессора: " << maxComp.frequency << "ГГц" << endl; 
	cout << "Объем оперативной памяти: " << maxComp.amountRAM << "ГБ" << endl; 
	cout << "Объем жёсткого диска: " << maxComp.hardDrive << "ГБ" << endl; 
	cout << "Размер монитора: " << maxComp.monitorSize << " дюйма" << endl; 
	cout << "Цена: " << maxComp.price << " рублей" << endl; 
	return 0;
}