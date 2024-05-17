#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream file1;
	file1.open("a.txt");
	ofstream file2;
	file2.open("a2.txt");
	if (!file1.is_open() || !file2.is_open())
	{
		cout << "Error." << endl;
		return 1;
	}
	char c;
	while (file1.get(c))
	{
		if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
		{
			file2 << '*';
		}
		else
		{
			file2 << c;
		}
	}
	file1.close();
	file2.close();

	cout << "Process completed successfully." << endl;
	return 0;
}
