// #ifndef H_WorkerType
// #define H_WorkerType

#include <iostream>
#include <string>
#include "employee.h"

class salaryEmployee : public employee
{
public:
   salaryEmployee();
   void printInfo();
   double computePay();
   void setBonus(double);
   double totalPay();
   double getBonus();
   
private:
   double performanceBonus;
     
};

// #endif