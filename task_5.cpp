#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Soldier {
    string surname;
    string name;
    string patronymic;
    string address;
    string nationality;
    string birthDate;
    string position;
    string rank;
};

void readFile(const string& filename) {
    ofstream file2;
    file2.open("leitenants.txt");

    ifstream file;
    file.open("soldier.txt");
    if (file.is_open()) {
        Soldier soldier;
        while (file >> soldier.surname >> soldier.name >> soldier.patronymic >> soldier.address >> soldier.nationality >> soldier.birthDate >> soldier.position >> soldier.rank)
        {
            if (soldier.position == "лейтенант")
            {
                cout << "Фамилия: " << soldier.surname << endl;
                cout << "Имя: " << soldier.name << endl;
                cout << "Отчество: " << soldier.patronymic << endl;
                cout << "Адрес: " << soldier.address << endl;
                cout << "Национальность: " << soldier.nationality << endl;
                cout << "Дата рождения: " << soldier.birthDate << endl;
                cout << "Должность: " << soldier.position << endl;
                cout << "Звание: " << soldier.rank << endl;
                cout << "................" << endl;
                file2 << soldier.surname << " " << soldier.name << " " << soldier.patronymic << " " << soldier.address << " " << soldier.nationality << " " << soldier.birthDate << " " << soldier.position << " " << soldier.rank << endl;

            }
        }
        file.close();
    }
    else {
        cerr << "Ошибка в открытии файла. " << endl;
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    readFile("leitenants.txt");

    return 0;
}