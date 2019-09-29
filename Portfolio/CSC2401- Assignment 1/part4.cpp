#include <stdexcept>
#include <exception>
#include <iostream>
#include <string>
#include <math.h>
#include <memory>

using namespace std;

class sampleWeights
{
    private:

    const int MAX_SAMPLES = 4 ; 

    public:

    sampleWeights(): weightArray {0,0,0,0} // Default constructor
    {
        cout << "Constructor Called" << endl;
        arrayCount = 0;
        inputCount = 0;
        
    };

    ~sampleWeights() //Destructor
    {
        cout << "Destructor Called." << endl;
    };

    void storeSample(float weight) // Store inputted data into array
    {
        if (arrayCount >= MAX_SAMPLES)
        {
            throw domain_error("Capacity Reached"); //Exception error handler
        };

        weightArray[arrayCount] = weight;
        arrayCount++;

    };

    float aveWeight() // Return average weight of inputted data.
    {
        float total = 0.0;

        float average = 0.0;

        if (numSamples() == 0) //Exception handler
        {
            throw domain_error("No inputs received.");
        }
        
        for (int i = 0; i < arrayCount; i++)
        {
            total += weightArray[i];
        }
        
        average = total / arrayCount;
        
        return average;

    }

    int numSamples() // Return number of samples that has been entered
    {
        return arrayCount;
    }
    void setInputCount(int input) // Record the number of inputs entered.
    {
        inputCount = input;
    }

    float weightArray[4]; //Storage array

    int arrayCount; //Count of how many data inputs have been recorded

    int inputCount; //Number of inputs entered.
};

void doAllWeights()
{
    unique_ptr<sampleWeights> testPool (new sampleWeights);
    float input;
    float average;
    cout <<"Please input a weight, input 0 to finish: ";
    cin >> input;
    while(input > 0.0) // Testing input is not zero
    {
           testPool->storeSample(input); 
           cout <<"Please input a weight, input 0 to finish: ";
           cin >> input;
    }

    average = testPool->aveWeight(); // Call average weight function

    cout << "Average of weights input: " << average << endl;
     

}

int main() //// Main program begin
{
    try
    {
        doAllWeights(); //Execute function
    }
    catch(const std::domain_error& e) // Error catching
        {
            std::cerr << "Domain error occured: " << e.what() << endl;
        }  
    
    return 0;

}