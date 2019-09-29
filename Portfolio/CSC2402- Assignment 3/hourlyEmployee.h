// #ifndef H_WorkerType
// #define H_WorkerType

#include "employee.h"
#include <iostream>
#include <string>

using namespace std;

//derived class form employee base class
class hourlyEmployee : public employee {
public:
// default construcotr
  hourlyEmployee();
  hourlyEmployee(double);
  void setOvertime(int);
  double computePay(double);
  void printInfo();
  double getTaxSum();
  void addTaxSum(double);
  bool operator >(const hourlyEmployee&);
  friend double operator +(const hourlyEmployee& ,const hourlyEmployee&);
private:
// hourlyEmployee variables
int overtime;

};

// #endif
