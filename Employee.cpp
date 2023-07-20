// Imports
#include <iostream>;
#include "Employee.h";
using namespace std;

Employee::Employee() {
	id : 0;
	annual_salary : 0;
	hourly_pay : 0;
	contracted_hours : 0;
	name: "Null";
}

Employee::Employee(int id, int annual_salary, int hourly_pay, int contracted_hours, string name) {
	this->id = id;
	this->annual_salary = annual_salary;
	this->hourly_pay = hourly_pay;
	this->contracted_hours = contracted_hours;
	this->name = name;
}

const string Employee::get_name() const {
	return name;
}

const int Employee::get_annual_salary() const{
	return annual_salary;
}

const int Employee::get_contracted_hours() const{
	return contracted_hours;
}