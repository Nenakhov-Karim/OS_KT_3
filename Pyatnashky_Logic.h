

#ifndef PYATNASHKY_LOGIC_H
#define PYATNASHKY_LOGIC_H


void clearScreen();  //  Utilities
void printMatrix(int matrix[4][4]);  //  Utilities
bool isSolvable(int matrix[4][4]);  //  Data_Handler
void fillRandomNumbers(int matrix[4][4]);  //  Data_Handler
void findZero(int matrix[4][4], int& iZero, int& jZero);  //  Utilities
void moveLeft(int matrix[4][4], int& moveCount);  //  Main_Logic
void moveRight(int matrix[4][4], int& moveCount);  //  Main_Logic
void moveUp(int matrix[4][4], int& moveCount);  //   Main_Logic
void moveDown(int matrix[4][4], int& moveCount);  //    Main_Logic
bool isSorted(int matrix[4][4]);  //  Main_Logic
int start();  //  Main_Logic
int main(); //  Main


#endif //PYATNASHKY_LOGIC_H
