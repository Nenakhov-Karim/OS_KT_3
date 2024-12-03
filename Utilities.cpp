#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include "Pyatnashky_Logic.h";
using namespace std;


void clearScreen() {
    system("cls");
}



void printMatrix(int matrix[4][4]) {
    cout << "+----+----+----+----+" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "|";
        for (int j = 0; j < 4; j++) {
            if (matrix[i][j] == 0)
                cout << "    |";
            else
                cout << setw(3) << matrix[i][j] << " |";
        }
        cout << endl << "+----+----+----+----+" << endl;
    }
}


void findZero(int matrix[4][4], int& iZero, int& jZero) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j] == 0) {
                iZero = i;
                jZero = j;
                return;
            }
        }
    }
}