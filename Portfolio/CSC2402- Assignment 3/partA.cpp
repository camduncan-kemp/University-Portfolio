#include <iostream>
#include<iomanip>
#include <string>
#include <fstream>


using namespace std;


void recurseFunction(int input, int count, int largest, int original) //Recursive function, maintain original input for result output
{
    if(input > largest) // Test for largest number reached
    {
        largest = input;
    }
    if (input == 1) //Output when number reaches 1
    {
        cout << "Starting with " << original << " it took " << count << " steps; The highest number achieved was " << largest << endl;
        return;
    }
    if (input % 2 == 0) //Test for even number
    {
        input /= 2;
        count++;
    }
    else //Run when not even/odd
    {
        input = input * 3 + 1;
        count++;
    }

    recurseFunction(input, count, largest, original); //Function recursion
}

int main()
{
    //Initialise variables
int count = 0;
int largest = 0;
int userInput;

cout << "Please input a test number: "; 
cin >> userInput; // User Input
recurseFunction(userInput, count, largest, userInput);



return 0;

}