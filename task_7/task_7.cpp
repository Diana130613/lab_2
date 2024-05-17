#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int k, l, m, n;
    vector<vector<vector<int>>> firstMatrices, secondMatrices;

    // данные первого файла
    ifstream firstFile("first_file.txt");
    firstFile >> k >> m >> n;
    firstMatrices.resize(k);
    for (int i = 0; i < k; i++) {
        firstMatrices[i].resize(m, vector<int>(n));
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < n; l++) {
                firstFile >> firstMatrices[i][j][l];
            }
        }
    }
    firstFile.close();

    // данные второго файла
    ifstream secondFile("second_file.txt");
    secondFile >> l >> m >> n;
    secondMatrices.resize(l);
    for (int i = 0; i < l; i++) {
        secondMatrices[i].resize(m, vector<int>(n));
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < n; l++) {
                secondFile >> secondMatrices[i][j][l];
            }
        }
    }
    secondFile.close();

    // меняем местами нечётные матрицы
    int minCount = min(k, l);
    for (int i = 0; i < minCount; i++) {
        if (i % 2 != 0) {
            swap(firstMatrices[i], secondMatrices[i]);
        }
    }
    cout << "Содержимое первого файла:" << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < n; l++) {
                cout << firstMatrices[i][j][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "Содержимое второго файла:" << endl;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < m; j++) {
            for (int l = 0; l < n; l++) {
                cout << secondMatrices[i][j][l] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
