#include<iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	vector <double> numbers;
	double num;
	double difference;
	ifstream file;
	file.open("f.txt");
	if (!file.is_open())
	{
		cerr << " Ошибка в открытии файла. " << endl;
		return 1;
	}

	while (file >> num)
	{
		numbers.push_back(num);
	}
	if (!numbers.empty())
	{
		difference = numbers.front() - numbers.back();
		cout << "Числовая разница между первым элементом и последним: " << numbers.front() << " - " << numbers.back() << " = " << difference << endl;
	}
	else
	{
		cout << "Нет чисел." << endl;
	}

	return 0;
}
