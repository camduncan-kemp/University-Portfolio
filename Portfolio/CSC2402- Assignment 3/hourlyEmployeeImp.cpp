#include "hourlyEmployee.h"
#include "employee.h"
#include <iostream>
#include <string>

// defult constructor implementation
hourlyEmployee::hourlyEmployee() : employee() {
    overtime = 0;
}
hourlyEmployee::hourlyEmployee(double tax) : employee() {
    overtime = 0;
    taxSum = tax;
}
void hourlyEmployee::setOvertime(int Overtime){
    overtime = Overtime;
}
void hourlyEmployee::printInfo() //TEST PRINT
{
    cout << empID << " " << name << " " << pay << " " << hoursWorked     << endl;
}
double hourlyEmployee::computePay(double hours)
{
    double over = hours - 40;
    int normalTime = 40 * pay;
    double overtimeRate = pay * 1.5;
    double overPay = over * overtimeRate;
    if (over >= 1)
    {
        double totalPay = normalTime + overPay;
        return totalPay;
    }
    else
    {
        double totalPay = hours * pay;
        return totalPay;
    }
    
    
}

bool hourlyEmployee::operator >(const hourlyEmployee& input)
{
    return this -> pay > input.pay;
}
double hourlyEmployee::getTaxSum()
{
    return taxSum;
}
void hourlyEmployee::addTaxSum(double input)
{
    taxSum += input;
}


// rest of the class methods here