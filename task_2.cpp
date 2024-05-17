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
		cout << "Error opening file." << endl;
		return 1;
	}
	float num;
	while (file1 >> num)
	{
		if (num > 0)
		{
			file2 << 5 * num << endl;
		}
	}
	file1.close();
	file2.close();

	cout << "Process completed successfully." << endl;
	return 0;
}
