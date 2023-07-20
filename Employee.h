#pragma once
#include <iostream>;

using namespace std;

class Employee {
private:
	int id;
	int annual_salary;
	int hourly_pay;
	int contracted_hours;
	string name;
public:
	// Default Constructor
	Employee();

	// Parameterized constructor
	Employee(int id, int annual_salary, int hourly_pay, int contracted_hours, string name);

	// Other functions for the class
	const string get_name() const;
	const int get_annual_salary() const;
	const int get_contracted_hours() const;
};