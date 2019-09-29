#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
using namespace std;
// Declaration of functions and variables
bool isPrime(int);
bool isArmstrong(int);
int x, i,primeTotal, digitSum, temp, remain, digit;
bool flag;
string lineBreak = "+----------+----------+----------+\n"; //Set line divider as string for easy insertion

int main(){
ofstream myFile;
myFile.open("output.txt"); //Start outstream to file
int primeTotal = 0; //Initialisation of totals
int armTotal= 0;
int doubleTotal= 0;
// Printing of headers
myFile << left 
<< lineBreak
<< setw(11) << "|Number" 
<< setw(11) << "|Prime" 
<< setw(11) << "|Armstrong |" 
<< endl;
for(int i = 100; i <= 500; i++) //Initialise for-loop to run from 100-500 inclusive
{
    if(isPrime(i)){
        myFile 
        << lineBreak << "|"
        << setw(10) << i << "|"
        << setw(10) << "X" << "|"
        << setw(10) << " " << "|"
        << endl;
        primeTotal++;  
    }
    if (isArmstrong(i)) {
        myFile << lineBreak << "|"
        << setw(10) << i << "|"
        << setw(10) << " " << "|"
        << setw(10) << "X" << "|"
        << endl;
        armTotal++;
    }
    if(isArmstrong(i) && isPrime(i)){
        doubleTotal++;
    }
    
}
// Final total outputs
myFile << lineBreak << endl;
myFile << "Between 100 and 500 range a total of " << primeTotal << " prime numbers were found." << endl;
myFile << "Between 100 and 500 range a total of " << armTotal << " Armstrong numbers were found." << endl;
myFile << "Between 100 and 500 range a total of " << doubleTotal << " numbers were found that meet both the prime number and Armstrong number conditions." << endl;

return 0;

}

bool isPrime(int x){
    flag= true;
    for(i = 2; i <= x / 2; ++i){
        if(x % i == 0)
        {
            flag= false;
            break;
        }
    }
 return flag;
}

bool isArmstrong(int i){
   temp = i;
   digit = 0;

   while (temp != 0) {
      digit++;
      temp = temp/10;
   }
   temp = i;
   digitSum = 0;
 
   while (temp != 0) {
      remain = temp%10;
      digitSum = digitSum + pow(remain, digit);
      temp = temp/10;
   }
    if(digitSum == i){
        return true;
    }
    else
    {
        return false;
    }
    
}