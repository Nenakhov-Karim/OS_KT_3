#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include "Pyatnashky_Logic.h";
using namespace std;



int start() {
    setlocale(LC_ALL, "Russian");

    int restart;
    do {
        int matrix[4][4];
        fillRandomNumbers(matrix);

        int moveCount = 0;

        while (true) {
            clearScreen();
            printMatrix(matrix);

            if (isSorted(matrix)) {
                cout << "Поздравляем! Вы собрали пятнашки!" << endl;
                cout << "Количество ходов: " << moveCount << endl;
                break;
            }

            cout << "Используйте стрелки для перемещения плиток. Esc - выход." << endl;

            int key = _getch();

            if (key == 224) {
                key = _getch();
                switch (key) {
                    case 72:
                        moveUp(matrix, moveCount);
                    break;
                    case 80:
                        moveDown(matrix, moveCount);
                    break;
                    case 75:
                        moveLeft(matrix, moveCount);
                    break;
                    case 77:
                        moveRight(matrix, moveCount);
                    break;
                    default:
                        break;
                }
            }
            else if (key == 27) {
                break;
            }
        }

        cout << "Хотите сыграть ещё раз? (1 - да, 0 - нет): ";
        cin >> restart;

    } while (restart != 0);

    return 0;
}



void moveLeft(int matrix[4][4], int& moveCount) {
    int iZero, jZero;
    findZero(matrix, iZero, jZero);
    if (jZero > 0) {
        swap(matrix[iZero][jZero], matrix[iZero][jZero - 1]);
        moveCount++;
    }
}



void moveUp(int matrix[4][4], int& moveCount) {
    int iZero, jZero;
    findZero(matrix, iZero, jZero);
    if (iZero > 0) {
        swap(matrix[iZero][jZero], matrix[iZero - 1][jZero]);
        moveCount++;
    }
}



void moveRight(int matrix[4][4], int& moveCount) {
    int iZero, jZero;
    findZero(matrix, iZero, jZero);
    if (jZero < 3) {
        swap(matrix[iZero][jZero], matrix[iZero][jZero + 1]);
        moveCount++;
    }
}



void moveDown(int matrix[4][4], int& moveCount) {
    int iZero, jZero;
    findZero(matrix, iZero, jZero);
    if (iZero < 3) {
        swap(matrix[iZero][jZero], matrix[iZero + 1][jZero]);
        moveCount++;
    }
}



bool isSorted(int matrix[4][4]) {
    int count = 1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == 3 && j == 3) {
                if (matrix[i][j] != 0)
                    return false;
            }
            else {
                if (matrix[i][j] != count)
                    return false;
                count++;
            }
        }
    }
    return true;
}