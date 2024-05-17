#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file;
    file.open("a.txt");

    if (!file.is_open())
    {
        cerr << "Error." << endl;
        return 1;
    }
    int num, position = 1, leastNum = INT_MAX;
    while (file >> num)
    {
        if ((position % 2) != 0 && num > 0)
        {
            if (num < leastNum)
            {
                leastNum = num;
            }
        }
        position++;
    }
    if (leastNum == INT_MAX) {
        cerr << "No positive number found at odd positions." << endl;
    }
    else {
        cout << leastNum << endl;
    }
    file.close();

    return 0;
}
