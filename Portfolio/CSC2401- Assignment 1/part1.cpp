#include <stdexcept>
#include <exception>
#include <iostream>
#include <string>
#include <math.h>

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
            throw runtime_error("Capacity Reached"); //Exception error handler
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
            throw runtime_error("No inputs received.");
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

int main(int argc, char *argv[]) //// Main program begin
{
    sampleWeights testPool;


    testPool.setInputCount(argc-1);


    for (int i = 1; i < argc; i++)    //Store inputs within the array
    {
        try
        {
            float x;
            x = atof(argv[i]);
            if(argc > 1)
                {
                    testPool.storeSample(x);
                }
        }
        catch(const std::runtime_error& e) //Error catching
        {
            cerr << "Runtime error: " << e.what() << endl;
            return 0;
        }       
    };

    
    try
    {
        float average = testPool.aveWeight();
       cout << "Average of weights input = " << average << endl;
    }
    catch(const std::runtime_error& e) //Error catching
    {
        std::cerr << "Runtime error: " << e.what() << endl;
        return 0;
    }
    
    return 0;

}