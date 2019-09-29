#ifndef H_WorkerType
#define H_WorkerType

#include <iostream>
#include <string>

using namespace std;
const int WORK_HOURS = 40;


class employee {
public:
  employee();
  // other methods
  void setID(int);
  void setName(string);
  void setHours(double);
  void payRise(int);
  void setPay(double);
  virtual void addTaxSum(double);
  virtual double getTaxSum();
  int getID();
  string getName();
  double getHours();
  double getPay();
  virtual double computePay();
  virtual double totalPay();
  friend class hourlyEmployee;
  friend class salaryEmployee;
  double getTax();
  double getTotalPaid();
  friend double operator +(const employee&, const employee&);
  friend bool operator >(const employee&, const employee&);
  double tax;
private:
  int empID;
  string name;
  double hoursWorked;
  double pay;
  double totalPaid;
  double taxSum;
  // other properties
};

#endif