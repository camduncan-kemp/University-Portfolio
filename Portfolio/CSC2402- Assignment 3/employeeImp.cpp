#include "employee.h"
#include <iostream>
#include <string>

// default constructor
employee::employee() {
empID = 0 ;
name;
pay = 0.0;
tax = 0.0;
taxSum = 0.0;
totalPaid = 0.0;
}
void employee::setID(int ID)
{
    empID = ID;
}
int employee::getID(){
    return empID;
}
double employee::getTotalPaid()
{
    return totalPaid;
}
void employee::setName(string Name)
{
    name = Name;
}
string employee::getName()
{
    return name;
}
void employee::setHours(double hours){
    hoursWorked = hours;
}
double employee::getHours()
{
    return hoursWorked;
}
void employee::setPay(double Pay){
    pay = Pay;
}
double employee::getPay()
{
    return pay;
}
void employee::addTaxSum(double input)
{
    taxSum += input;
}
double employee::getTaxSum()
{
    return taxSum;
}
double employee::computePay()
{
    return pay;
}
double employee::totalPay()
{   
    double grossPay = pay * hoursWorked;
    double taxTotal = grossPay * 0.33;
    tax = taxTotal;
    double netPay = grossPay - taxTotal;
    totalPaid = netPay;
    return netPay;
}
void employee::payRise(int rate)
{
    double raise = pay * rate;
    double newTotal = pay + raise;
    pay = newTotal;
}

double employee::getTax()
{
    return tax;
}


// Rest of the employee methods