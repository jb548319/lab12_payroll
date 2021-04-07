/*
 *        File: payroll.cc
 *      Author: Jonah Brautigam
 *        Date: 4/6/21
 * Description: Finds payroll from employees file
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

struct Employee
{
    int id;
    string first_name;
    string last_name;
    double salary;
};

/**
 * Loads input file into a vector of structures
 * @return vector of structures 
*/
vector <Employee> loadData ();

/**
 * Prints the results
 * @param employee vector that stores structures
 * @param total_payroll total dollars in payroll
*/
void printReport (vector <Employee> employee, double total_payroll);

/**
 * Finds the total price of the pizza log data
 * @param employee vector that stores structures
 * @return returns total payroll of all employees
*/
double totalPayroll (vector <Employee> employee);

int main(int argc, char const *argv[]) {

    vector <Employee> employee = loadData ();

    double total_payroll = totalPayroll (employee);

    printReport (employee, total_payroll);

    return 0;
}// main

vector <Employee> loadData ()
{
    vector <Employee> employee;
    ifstream ins;
    
    int id;
    string first_name;
    string last_name;
    double salary;
    
    cout << "Enter the employee file name: ";
    string input_file;
    cin >> input_file;

    ins.open(input_file);
    if (ins.fail())
    {
        cout << "\nError: Problem opening file" << endl;
        exit(0);
    }

    while (!ins.eof())
    {
        ins >> id;
        ins >> first_name;
        ins >> last_name;
        ins >> salary;

        Employee pizza = {id, first_name, last_name, salary};

        employee.push_back(pizza);
    }

    ins.close();

    return employee;
}

void printReport (vector <Employee> employee, double total_payroll)
{
    cout << "Sorted by name" << endl;
    cout << setw(10) << left << "ID" << setw(20) << left << "Name" << setw(20) << "Salary" << endl;

    cout << "------------------------------------" << endl;

    cout << fixed << setprecision(2);

    string full_name;

    for (size_t i = 0; i < employee.size(); i++)
    {
        full_name = employee[i].first_name + " " + employee[i].last_name;

        cout << setw(10) << left << employee[i].id << setw(20) << left << full_name;
        cout << "$" << employee[i].salary << endl;
    }

    cout << "\nTotal Payroll: $" << total_payroll;
}

double totalPayroll (vector <Employee> employee)
{
    double sum = 0;
    for (size_t i = 0; i < employee.size(); i++)
    {
        sum += employee[i].salary;
    }
    return sum;
}