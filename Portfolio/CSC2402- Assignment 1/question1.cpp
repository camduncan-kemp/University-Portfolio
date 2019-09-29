#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>



using namespace std;

bool numberPalindrome(string, int& sum); // Function prototype

int sum = 0; //Initialisation of sum

int main()
{
    string number;
   
    int x;
    int temp;

    ifstream inFile; //Open filestream
    inFile.open("numbers.txt");
    if (!inFile) { //Test if file opened correctly
        cout << "Unable to open the requested file";
        exit(1);
    }
    while(inFile.good()){ //Run while file still has data left
        getline (inFile, number);
        if(numberPalindrome(number, sum)){
            cout << "Number: " << number << " is a palindromic number." << endl;
        }
       
    }
     cout << "A total of " << sum << " palindromic numbers were found.";

    return 0;





}

bool numberPalindrome(string number, int& sum){ //Function to test if palindrome
    int length = number.length();
    for (int i = 0; i < length / 2; i++)
        if (number[i] != number[length - 1 - i])
            return false;
    sum++;
    return true;
}