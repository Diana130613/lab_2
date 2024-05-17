#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream file;
	file.open("a.txt");
	if (!file.is_open())
	{
		cout << "Error opening file. " << endl;
		return 1;
	}
	float negNum = 0, posNum = 0, num;
	while (file >> num)
	{
		if (num < 0)
		{
			negNum++;
		}
		if (num > 0)
		{
			posNum++;
		}
	}
	file.close();
	cout << "Number of negative numbers: " << negNum << endl;
	cout << "Number of positive numbers: " << posNum << endl;
	return 0;
}
