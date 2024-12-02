#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include "Pyatnashky_Logic.h";
using namespace std;



bool isSolvable(int matrix[4][4]) {
    int inversions = 0;
    int tiles[16];
    int index = 0;
    int zeroRow = 0;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            tiles[index] = matrix[i][j];
            index++;
        }
    }

    for (int i = 0; i < 16; ++i) {
        if (tiles[i] == 0) continue;
        for (int j = i + 1; j < 16; ++j) {
            if (tiles[j] == 0) continue;
            if (tiles[i] > tiles[j]) inversions++;
        }
    }

    for (int i = 3; i >= 0; --i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix[i][j] == 0) {
                zeroRow = 4 - i;
                break;
            }
        }
        if (zeroRow != 0) break;
    }

    return ((inversions + zeroRow) % 2 == 0);
}

void fillRandomNumbers(int matrix[4][4]) {
    srand(time(0));
    int numbers[16];
    for (int i = 0; i < 15; ++i) {
        numbers[i] = i + 1;
    }
    numbers[15] = 0;

    do {
        random_shuffle(numbers, numbers + 15);

        int index = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                matrix[i][j] = numbers[index];
                index++;
            }
        }
    } while (!isSolvable(matrix));
}