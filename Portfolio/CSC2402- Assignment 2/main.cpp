//Main program
  
#include <iostream>
#include <string>
#include <iomanip>
#include "roman.h" 

using namespace std; 

//Top level functions prototype to be implemented

romanType add(romanType, romanType);
romanType add(romanType, int);
void printTimesTable(romanType, romanType);

romanType add(romanType romanOne, romanType romanTwo)
{
    int val2 = romanTwo.getValue();
    romanOne.add(val2);
    return romanOne;
}
romanType add(romanType romanOne, int addedValue)
{
    romanOne.add(addedValue);
    return romanOne;
}

void printTimesTable(romanType baseNum, romanType multiplier)
{
    romanType product;
    int baseValue = baseNum.getValue();
    int factor = multiplier.getValue();
    for (int i = 0; i < 12; i++)
    {
        product = romanType((baseValue * factor));

        cout << baseNum.getRoman() << " * " << multiplier.getRoman() << "  =  "  << setw(5) << product.getRoman() << endl;
        baseNum.inc();
        baseValue = baseNum.getValue();
    }

}


int main()
{

    //test the constructors
    romanType roman1;  //default constructor
    romanType roman2 = romanType("XXIV"); //String Constructor
    romanType roman3 = romanType(33); //Integer Constructor

    //test the results from the constructors
    cout << endl << "Print the roman representation of the values" << endl;
    roman1.printRoman();
    cout << endl;
    roman2.printRoman();
    cout << endl;
    roman3.printRoman();
    cout << endl;
    
    //Add the rest of the tests to get the outputs as in the example output
    
    //Test the no parameter constructor
    cout << "Default romanType constructor with no parameter" << endl;
    cout << "Default romanType variable as Roman = " ;
    roman1.printRoman(); 
    cout << endl;
    cout << "Default romanType variable as number = " ;
    roman1.printPositiveInteger();
    cout << endl;    
    //Test change the romanType value and representation
    romanType roman4 = romanType(44);
    cout << "Setting the default romanType value to 44" << endl;
    cout << "Default romanType variable as Roman = ";
    roman4.printRoman();
    cout << endl;
    cout << "Default romanType variable as value = ";
    roman4.printPositiveInteger();
    cout << endl;        
    //Check the string constructor for romanType
    cout << "Get roman and value from the string constructor" << endl;
    cout << "String constructor romanType variable as Roman = " ;
    roman2.printRoman();
    cout << endl;
    cout << "String constructor romanType variable as value = ";
    roman2.printPositiveInteger();
    cout << endl;            
    //Check the value constructor for romanType
    cout << "Get roman and value from the integer constructor" << endl;
    cout << "Number constructor romanType variable as Roman = ";
    roman3.printRoman();
    cout << endl;
    cout << "Number constructor romanType variable as number = " ;
    roman3.printPositiveInteger();
    cout << endl;           
    //Check the increment and decrement operations
    cout << "Increment and Decrement on romanTypes" << endl;

    cout << "Increment class method on a romanType before ";
    roman3.printRoman();
    roman3.inc();
    cout << " After call to class method inc ";
    roman3.printRoman();
    cout << endl;

    cout << "Decrement class method on a romanType before ";
    roman3.printRoman();
    roman3.dec();
    cout << " After call to class method dec ";
    roman3.printRoman();
    cout << endl;
    //use the top level add function to add two romanTypes
    cout << "Add using function method on romanTypes" << endl;
    cout << "Add two romanType using top level function ";
    roman2.printRoman();
    cout << " plus ";
    romanType addedRoman = add(roman2, roman3);
    roman3.printRoman();
    cout << " = ";
    addedRoman.printRoman();
    cout << endl;
                    
    //use the overloaded add methods using an integer and a romanType as param
    cout << "Add using overloaded function method on romanTypes and integer" << endl;
    cout << "Add two romanType using top level function ";
    roman2.printRoman();
    cout << "plus 12 = ";
    romanType addedRoman2 = add(roman2, 12);
    addedRoman2.printRoman();
    cout << endl;

    //check the class method for the add function with romanType
    cout << "Using class method for addition of romanTypes ";
    roman2.printRoman();
    cout << " plus  ";
    roman3.printRoman();
    roman2.add(roman3);
    cout << " Result = ";
    roman2.printRoman();
    cout << endl;

    //check add integer class method to a romanType
    cout << "Using overloaded class method for addition of romanType and integer ";
    roman2.printRoman();
    cout << " plus 12, Result = ";
    roman2.add(12);
    roman2.printRoman();
    cout << endl;

    //check the times table using romanTypes
    cout << "Roman Times Table base 6 12 times" << endl;
    romanType base = romanType(1);
    romanType factor = romanType(6);
    printTimesTable(base, factor);
}
