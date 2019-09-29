
//Roman Number Implementation file

#include <iostream> 
#include <string>
#include "roman.h"
 
using namespace std;

    romanType::romanType()
    {
        num = 1;
        romanNum = intToRoman(1);
    }
    romanType::romanType(string romanString)
    {
        romanNum = romanString;
        romanToPositiveInteger();
    }
    romanType::romanType(int intValue)
    {
        num = intValue;
        romanNum= intToRoman(intValue);
    }

    void romanType::setRoman(string i)
    {
        romanNum = i;
        romanToPositiveInteger();
    }

    void romanType::setRoman(int j)
    {
        num = j;
        romanNum= intToRoman(j);
    }


    void romanType::romanToPositiveInteger()
    {
        int val1 = 0;
        int val2= 0;
        int sum = 0;
        int length = romanNum.length();
        for (int i = 0; i < length; i++)
        {
            if (romanNum[i] == 'I'){
                val1 = 1;
            }
            if (romanNum[i] == 'V'){
                val1 = 5;
            }
            if (romanNum[i] == 'X'){
                val1 = 10;
            }
            if (romanNum[i] == 'L'){
                val1 = 50;
            }
            if (romanNum[i] == 'C'){
                val1 = 100;
            }
            if (romanNum[i] == 'D'){
                val1 = 500;
            }
            if (romanNum[i] == 'M'){
                val1 = 1000;
            }
                if ((i+1) < length)
                {
                    if (romanNum[i+1] == 'I'){
                        val2 = 1;
                    }
                    if (romanNum[i+1] == 'V'){
                        val2 = 5;
                    }
                    if (romanNum[i+1] == 'X'){
                        val2 = 10;
                    }
                    if (romanNum[i+1] == 'L'){
                        val2 = 50;
                    }
                    if (romanNum[i+1] == 'C'){
                        val2 = 100;
                    }
                    if (romanNum[i+1] == 'D'){
                        val2 = 500;
                    }
                    if (romanNum[i+1] == 'M')
                    {
                        val2 = 1000;  
                    }
                    if (val1 >= val2)
                    {
                        sum += val1;
                    }
                    else
                    {
                        sum = sum + val2 - val1;
                        i++;
                    }
                }
                else
                {
                    sum += val1;
                    i++;
                }
        }   
        num = sum;
        
    }


    void romanType::printPositiveInteger() const
    {
        cout << num;
    }

    void romanType::printRoman() const
    {
        cout << romanNum;
    }

    string romanType::getRoman()
    {
        return romanNum;
    }

    int romanType::getValue()
    {
        return num;
    }

    void romanType::inc()
    {
        num++;
        romanNum = intToRoman(num);
    }

    void romanType::dec()
    {
        num--;
        romanNum = intToRoman(num);
    }
    void romanType::add(int addedValue)
    {
        num += addedValue;
        romanNum = intToRoman(num);
    }
    void romanType::add(romanType romNum)
    {
        num += romNum.num;
        romanNum = intToRoman(num);
    }


    string romanType::intToRoman(int value)
    {
        auto romDigit = [&](char one, char five, char ten, int value) 
        {
            if (value <= 3) 
                return string().assign(value, one);
            if (value <= 5) 
                return string().assign(5 - value, one) + five;
            if (value <= 8) 
            return five + string().assign(value - 5, one);

        return string().assign(10 - value, one) + ten;
        };
    
            if (value >= 1000) 
                return "M" + intToRoman(value - 1000);
            if (value >= 100) 
                return romDigit('C', 'D', 'M', value / 100) + intToRoman(value % 100);
            if (value >= 10) 
                return romDigit('X', 'L', 'C', value / 10) + intToRoman(value % 10);
        return romDigit('I', 'V', 'X', value);
    }




































