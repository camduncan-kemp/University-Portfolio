#include "employee.h"
#include "hourlyEmployee.h"
#include "salaryEmployee.h"
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;
const int NUM_ROWS = 20;

// OPERATORS
double operator +(const hourlyEmployee& inputOne, const hourlyEmployee& inputTwo)
{
    double temp = (inputOne.tax + inputTwo.tax);
    double total = temp;
    return total;

}

bool operator >(hourlyEmployee& inputOne, hourlyEmployee& inputTwo)
{
  return inputOne.getPay() > inputTwo.getPay();
}




void reportPayHourly(hourlyEmployee *hourlyWorkers) // Output for hourly employees.
{
  double sum = 0.0;
  cout << "Hourly Employee Pay Report." << endl;
  cout << "EmpID " << setw(10) << "Name " << setw(20) << right <<"Pay per Hour " << setw(20) << "Hours Worked" << setw(20) << "Pay for Week " << endl;
  for (int i = 0; i < NUM_ROWS; i++)
  {
    if (hourlyWorkers[i].getID() != 0)
    {
      sum += hourlyWorkers[i].computePay(hourlyWorkers[i].getHours());
      cout << hourlyWorkers[i].getID() << setw(10) << right << hourlyWorkers[i].getName() << setw(20) << right << hourlyWorkers[i].getPay() << setw(20) << hourlyWorkers[i].getHours() << setw(20) << hourlyWorkers[i].computePay(hourlyWorkers[i].getHours()) << endl;
    }
  }
  cout << "Total Pay Bill = $" << sum << endl;
};


void reportPaySalary(salaryEmployee *salaryWorkers) // Output for salary employees
{
  double sum = 0.0;
  cout << "Salary Employee Pay Report." << endl;
  cout << "EmpID " << setw(10) << "Name " << setw(20) << right <<"Salary " << setw(20) << "Perf Bonus " << setw(20) << "Pay for Week " << endl;
  for (int i = 0; i < NUM_ROWS; i++)
  {
    if (salaryWorkers[i].getID() != 0)
    {
      sum += salaryWorkers[i].computePay();
      cout << salaryWorkers[i].getID() << setw(10) << right << salaryWorkers[i].getName() << setw(17) <<"$"<< salaryWorkers[i].getPay() << setw(20) << "$" << salaryWorkers[i].getBonus() << setw(15) << "$" << salaryWorkers[i].computePay() << endl;
    }
  }
  cout << "Total Pay Bill = $" << sum << endl;
};

void topPerformers(hourlyEmployee *hourlyWorkers)
{

  int swap_index;
  hourlyEmployee temp;

  for (int i = 0; i < NUM_ROWS; i++)
  {
    swap_index = i;
      for (int j = i + 1; j < NUM_ROWS ; j++)
      {
          if (hourlyWorkers[j] > hourlyWorkers[swap_index])
          {
            swap_index = j;
          }
      }
    temp = hourlyWorkers[i];
    hourlyWorkers[i] = hourlyWorkers[swap_index];
    hourlyWorkers[swap_index] = temp;
  }
  int count = 1;
  cout << "Top Performers: " << endl;
  cout << "EmpID " << setw(10) << "Name " << setw(20) << "Earnings " << endl;
  for (int i = 0; i < NUM_ROWS; i++)
  {
    if (hourlyWorkers[i].getID() != 0 && count <= 3)
    {
      cout << hourlyWorkers[i].getID() << setw(10) << hourlyWorkers[i].getName() << setw(20) << hourlyWorkers[i].getTotalPaid() << endl;
      count++;
    }
  
  }
  

};

void totalPay(hourlyEmployee *hourlyWorkers)
{
  hourlyEmployee totalPaid;
  double result;
  double sum = 0.0;
  for (int i = 0; i < NUM_ROWS; i++)
  {
    result = hourlyWorkers[i] + hourlyWorkers[i+1];
    sum += result;
    i++;
  }
  // TAX OUTPUT
  cout << "Total Tax Payable = $" << sum << endl;
}
// other functions

int main(int argc, char const *argv[])
{

  hourlyEmployee *hourlyWorkers = new hourlyEmployee[NUM_ROWS];
  salaryEmployee *salaryWorkers = new salaryEmployee[NUM_ROWS];

  int hourlyIndexCount = 0;
  int salaryIndexCount = 0;

  //open the employee file and fill the arrays with the correct type
  ifstream firstWorkerFile("employee.txt");
  int ID = 0;
  string Name;
  double hours;
  double fixedHour;
  double hourBonus;

  for (int i = 0; i < NUM_ROWS; i++)
  {
    if (firstWorkerFile >> ID >> Name >> fixedHour)
    {

      if (ID <= 199 && ID >= 100)
      {
        salaryWorkers[salaryIndexCount].setID(ID);
        salaryWorkers[salaryIndexCount].setName(Name);
        salaryWorkers[salaryIndexCount].setPay(fixedHour);
        salaryIndexCount++;
      }
      else
      {
        hourlyWorkers[hourlyIndexCount].setID(ID);
        hourlyWorkers[hourlyIndexCount].setName(Name);
        hourlyWorkers[hourlyIndexCount].setPay(fixedHour);
        hourlyIndexCount++;
      }
    }
  }
  ifstream secondWorkerFile("work.txt");

  for (int i = 0; i < NUM_ROWS; i++)
  {

    if (secondWorkerFile >> ID >> hourBonus)
    {
      for (int i = 0; i < NUM_ROWS; i++)
      {
        int currentSalaryID = salaryWorkers[i].getID();
        int currentHourlyID = hourlyWorkers[i].getID();
        if (currentSalaryID == ID)
        {
          salaryWorkers[i].setBonus(hourBonus);
        }
        if (currentHourlyID == ID)
        {
          hourlyWorkers[i].setHours(hourBonus);
        }
      }
    }
  }

  // Report pays for hourly and salary workers.
  reportPayHourly(hourlyWorkers);
  reportPaySalary(salaryWorkers);
  // Initialise tax values for employees.
  for (int i = 0; i < NUM_ROWS; i++){
    hourlyWorkers[i].totalPay();
    salaryWorkers[i].totalPay();
  }
  topPerformers(hourlyWorkers);
  totalPay(hourlyWorkers);
  
  return 0;
}