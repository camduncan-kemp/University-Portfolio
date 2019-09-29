#include <iostream>
#include <iomanip>
#include <cmath>
#include <tuple>



using namespace std;
struct foo2 //Create structure for function return data.
{
    float firstYear;
    float secondYear;
};
struct foo1 //Create structure for function return data.
{
    float a;
    float b;
    float c;
};
float calculate(float&, float&, float&, float&, float&); //Function declarations.
void display(float&, float&);
float input(float&, float&, float&);
    
int main(){
float firstYear,secondYear;
float cur, one, two;
input(cur, one, two);
calculate(cur, one, two,firstYear, secondYear);
display(firstYear,secondYear);






   return 0; 
}
float input(float& cur, float& one, float& two) //Receive user input 
{

cout << "Enter the current price of the item: ";
cin >> cur;
cout << "Enter the price of the item one year ago: ";
cin >> one;
cout << "Enter the price of the item two years ago: ";
cin >> two;

void display(float calculate(float& cur,float& one, float& two));

return 0;
};
float calculate(float& cur, float& one, float& two,float& firstYear, float& secondYear) //Calculate inflation rates
    {
        
        firstYear= (cur - one)/one;
        secondYear = (one - two)/two;
        
        void display(float& firstYear, float& secondYear);
        return 0;
    }
    void display(float& firstYear, float& secondYear) //Function to display the results
    {
        cout << "Current year inflation: " << setprecision(1) << firstYear << endl;
        cout << "Inflation one year ago: " <<  setprecision(1) <<  secondYear << endl;
        if (firstYear > secondYear) {
            cout << "Inflation is increasing.";
        };
        if (firstYear < secondYear){
            cout << "Inflation is decreasing.";
        }
        
    }