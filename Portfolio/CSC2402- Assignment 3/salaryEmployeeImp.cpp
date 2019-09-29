#include "salaryEmployee.h"
#include "employee.h"
#include <iostream>
#include <string>

// default constructor
salaryEmployee::salaryEmployee() : employee() {
    performanceBonus = 0.0;
}

void salaryEmployee::setBonus(double bonus)
{
    performanceBonus = bonus;
}
double salaryEmployee::getBonus()
{
    return performanceBonus;
}
void salaryEmployee::printInfo() //TEST PRINT
{
    cout << empID << " " << name << " " << pay << " " << performanceBonus << endl;
}
double salaryEmployee::computePay()
{
    double total = pay + performanceBonus;
    return total;
}
double salaryEmployee::totalPay()
{
    double grossPay = pay + performanceBonus;
    double tax = grossPay * 0.45;
    double netPay = grossPay - tax;
    return netPay;
}





// other methods here