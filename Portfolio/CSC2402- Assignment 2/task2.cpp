#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <array>

using namespace std;

const int NUM_OF_ROWS = 10;
const int NUM_OF_COLS= 4;
//Function Definitions Start
void inputArray(int* array){
    int input;
        for (int i=0; i<20 ; i++){
        cout << "Input number: ";
        cin >>  array[i];
}
}

void doubleArray(const int array[], int* secondArray)
    {
    int i, j;
    for (i = 0 ; i < 20; i++){
        j = array[i] * 2;
        secondArray[i] = j;
    }
}

void copyAlphaBeta(const int array[], const int secondArray[], int matrixArray[][NUM_OF_COLS]){
    int alphaCounter = 0;
    int betaCounter = 0;
    int row,col;
    for(int row= 0; row< NUM_OF_ROWS; row++){
        for(int col=0; col < NUM_OF_COLS; col++){
            if (row >= 0 && row <5)
            {
                matrixArray[row][col]= array[alphaCounter];
                alphaCounter++;
            }
            if(row >= 5 && row <10){
                matrixArray[row][col]= secondArray[betaCounter];
                betaCounter++;
            }
            
        }
    }

}
void printTwoDimension(const int matrixArray[][NUM_OF_COLS]){
    cout << "Two-Dimensional Array: " << endl;
    for (int row= 0; row < NUM_OF_ROWS; row++){
        for (int col = 0; col < NUM_OF_COLS; col++){
            cout << setw(5) << matrixArray[row] [col] << " " ;
            if (col % 3 == 0 && col !=0){
                cout << endl;
            }
        }
    }
}
void printArray(const int array[], int n){
    cout << "Array printout: " << endl;
    for(int i=0; i < n; i++){
        cout << array[i] << "  ";
        if (i % 15==0 && i!= 0)
        {
            cout << endl;   
        }
   
    }
    cout << endl;
}
// Function Definition END
int main()
    {
    int alpha[20] = {0}; 
    int beta[20] = {0}; 
    int matrix[10][4];
    int input;
    //Initialise arrays to 0
    for(int i=0; i>20; i++){
        alpha[i] = 0;
        beta[i]= 0;
    }

    for(int row= 0; row< NUM_OF_ROWS; row++){
        for(int col=0; col < NUM_OF_COLS; col++){
            matrix[row][col]= 0;
        }
    }
    // Display initialised Arrays
    cout << "Initial Alpha ";
    printArray(alpha, 20);
    cout << "Initial Beta ";
    printArray(beta, 20);
    cout << "Initial Matrix ";
    printTwoDimension(matrix);
    //Call functions manipulate arrays
    inputArray(alpha);
    doubleArray(alpha, beta);
    copyAlphaBeta(alpha, beta, matrix);
    // Display altered arrays
    cout << "Final Alpha ";
    printArray(alpha, 20);
    cout << "Final Beta ";
    printArray(beta, 20);
    cout << "Final Matrix ";
    printTwoDimension(matrix);

    }