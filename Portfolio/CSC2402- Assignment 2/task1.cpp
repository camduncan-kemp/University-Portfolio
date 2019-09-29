#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <array>

using namespace std;
// Constant Declarations
const int NUM_OF_ROWS = 13;
const int NUM_OF_SEATS = 6;
const char taken = 'X';
const char available= '*';

//Function Definitions/Declarations
bool isSeatFree(int, int);

int seatRow(char ticketType){  //// Identify the row for seating
    int seatRow;
    while (ticketType != 'F' && ticketType != 'f' && ticketType != 'B' && ticketType != 'b' && ticketType != 'E' && ticketType != 'e') //Loop until valid input received
    {
        cout << "Enter ticket type: F/f (first class); (B/b) (business class); E/e (economy class): ";
        cin >> ticketType;
        cout << endl;
    }

    if (ticketType == 'F' || ticketType == 'f') //First class identification
    {
        cout << "Enter Row Number 1 - 2: ";
        cin >> seatRow;
        cout << endl;
        while (seatRow != 1 && seatRow != 2)
        {
        cout << "Enter Row Number 1 - 2: ";
        cin >> seatRow;
        cout << endl;   
        }
        
    }
    if (ticketType == 'B' || ticketType == 'b') //Business Class Identification
    {
        cout << "Enter Row Number 3 - 7: ";
        cin >> seatRow;
        cout << endl;
        while (seatRow < 3 && seatRow > 7)
        {
        cout << "Enter Row Number 3 - 7: ";
        cin >> seatRow;
        cout << endl;   
        }
    }
    if (ticketType == 'E' || ticketType == 'e') //Economy class identification
    {
        cout << "Enter Row Number 8 - 13: ";
        cin >> seatRow;
        cout << endl;
        while (seatRow < 8 && seatRow > 13)
        {
        cout << "Enter Row Number 8 - 13: ";
        cin >> seatRow;
        cout << endl;   
        }
    }
    return seatRow; //Return row number as integer
}


bool isSeatFree(int matrix[][NUM_OF_SEATS], int row) /// Check if the seat is free
{ 
    int seatNumber;
    char seat;
    cout << "Enter seat number (A - F): "; //Initial input
    cin >> seat;
    cout << endl;
    bool flag = true; //Set flag to true for first run
while(flag) //Flag check
{
    if(seat == 'A'){
        seatNumber = 0;
        flag= false;
    }
    else if(seat == 'B'){
        seatNumber = 1;
        flag= false;
    }
    else if(seat == 'C'){
        seatNumber = 2;
        flag= false;
    }
    else if(seat == 'D'){
        seatNumber = 3;
        flag= false;
    }
    else if(seat == 'E'){
        seatNumber = 4;
        flag= false;
    }
    else if(seat == 'F'){
        seatNumber = 5;
        flag= false;
    }
    else // Runs when flag = false
    {
        cout << "Enter seat number (A - F): ";
        cin >> seat;
        cout << endl;
    }
}

 if (matrix[row-1][seatNumber] == 0){ //Set seat to occupied if it is available, -1 to account for index off-set
     matrix[row-1][seatNumber] = 1;
     return true; //Return true if seat was available
 }
 else{
     return false; // Return false if seat is occupied already
 }
}


void printPlane(int seatMatrix[][NUM_OF_SEATS]){    //Function to print the current plane seating layout
cout << " This program assigns seats for a commercial airplane. " << endl;
cout << " The current seat assignments is as follows. " << endl;
cout << setw(10) << "A" << setw(5) << "B" << setw(5) << "C" << setw(5) << "D" << setw(5) << "E" << setw(5) << "F" << endl;
for(int row = 0; row < NUM_OF_ROWS; row++){
    cout << "Row " << row + 1 << setw(5);
    for(int seat = 0; seat < NUM_OF_SEATS; seat++){
            if(seatMatrix[row][seat] == 0){
              cout << setw(5) << available;  
            }
            else{
                cout << setw(5) << taken;
            }
            if(seat== 5){
                cout << endl;
            }
        }
    }

cout << " * -- available seat " << endl;
cout << " X -- occupied seat " << endl;
cout << "Rows 1 and 2 are for first class passengers. " << endl;
cout << "Rows 3 through 7 are for business class passengers. " << endl;
cout << "Rows 8 through 13 are for economy class passengers. " << endl;
}


// Start of main program
int main()
{
//Variable declarations
    char confirmStatus;
    char ticketType;
    char seat;
    bool confirmFlag;

    int seatMatrix[13][6];
    // Initialise all seats to empty
    for(int row= 0; row< NUM_OF_ROWS; row++){
        for(int seat=0; seat < NUM_OF_SEATS; seat++){
            seatMatrix[row][seat]= 0;
            }
        }

    printPlane(seatMatrix); //first run display of plane layout
    cout << "To reserve a seat enter Y/y(Yes), N/n(No): ";
    cin >> confirmStatus;
    if (confirmStatus == 'N' || confirmStatus == 'n'){ //If user inputs No, terminate program.
        return 0;
    }
    if(confirmStatus == 'Y' || confirmStatus == 'y'){
        confirmFlag = true; // Set flag to true if user inputs Yes.
    }
    else
    {
        confirmFlag= false; // Set flag to false if any other input is entered.
    }
    while(confirmFlag == false){ //Loop until user enters Yes or No.
        cout << "To reserve a seat enter Y/y(Yes), N/n(No): ";
        cin >> confirmStatus;
        cout << endl;
        if (confirmStatus == 'N' || confirmStatus == 'n')
        {
            return 0;
        }
        if(confirmStatus == 'Y' || confirmStatus == 'y'){
            confirmFlag = true;
        }
        else
        {
            confirmFlag= false;
        }
    }
    while(confirmFlag == true) //Start of loop that will run until the user terminates the program.
    {
        cout << endl;
        cout << "Enter ticket type: F/f (first class); (B/b) (business class); E/e (economy class): ";
        cin >> ticketType;
        cout << endl;

        int rowNumber = seatRow(ticketType); //Allocate row to variable
        bool seatFreeResult= isSeatFree(seatMatrix,rowNumber); //Allocate the seat status to a boolean flag
        if(seatFreeResult) //If seat status flag = true
        {
            cout << "This seat is reserved for you. " << endl;
            printPlane(seatMatrix);
            cout << "Reserve another seat Y/y(Yes), N/n(No): " ;
            cin >> confirmStatus;
            cout << endl;
            if(confirmStatus == 'Y' || confirmStatus == 'y')
            {
                printPlane(seatMatrix);
                confirmFlag = true;
            }  
        }

        else // If seat status flag = false
        {
            cout << "*#*#*#*# This seat is occupied *#*#*#*#" << endl;
            cout << "Make another selection." << endl;
        }
        
    }
}










