#include <iostream>
#include <cmath>
#include <tuple>


using namespace std;
//Initiliase variables
int a, b, t, c;
int sum= 0;
int spare= 0;

struct foo //Create structure for function return data.
{
    int sum;
    int spare;
};


foo calc(int, int, int) //Calculation function
    {
        c= a + b;
        if(t>=a) //for first run through
        {
            t= t-a;
            sum++;
        }
        while(t>=c) //for each subsequent run through
            {
            t -= c;
            c += b;
            sum++; 

            }
        spare += t;
        foo result = {sum, spare}; //return both to foo structure
    return result;
    }   

int main(){


// I/O statements
cout << "Enter the number of minutes to prepare first dish: ";
cin >> a;
cout << "Enter how many more minutes to prepare the next dish: ";
cin >> b;
cout << "Enter the total time (in minutes) to prepare all the dishes: ";
cin >> t;
calc(a, b, t); //Function call
cout << "In " << t << " minute(s) the pastry cook can prepare " << sum << " dishes with " << spare << " minutes to spare.";

return 0;
}
