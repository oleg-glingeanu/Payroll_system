// Imports
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
using namespace std;

int get_annual_salary(int hour, int contracted_hours){
	return hour * contracted_hours * 52;
}

// Payroll System
// TXT FILE = [Employee Fname] [Employee Lname] [Last Payment]


int main() {

	int user_choice = 0;
	string employee_name;
	int annual_salary;
	int hourly_pay;
	int contracted_hours;
	int id;
	vector<Employee> employee_list;
	std::cout << "-------PAYROLL SYSTEM-------------" << endl;
	std::cout << "1. Input A new Employee" << endl;
	std::cout << "2. Input hours for Employees" << endl;
	std::cout << "3: Pay all the employees " << endl;
	std::cout << "4: Change Pay Ammount" << endl;
	std::cout << "5: Print out all employees" << endl;
	std::cout << "6: Print out employees in order" << endl;
	std::cout << "7: Exit" << endl;
	std::cout << "----------------------------------" << endl;
	std::cout << "Please enter a choice:";
	std::cin >> user_choice;

	// Some Basic Data
	Employee oleg(1, 40000, 27, 35, "Oleg Glingeanu");
	employee_list.push_back(oleg);
	Employee jibbie(2, 20000, 10, 30, "Jibril Adbulazeez");
	employee_list.push_back(jibbie);
	Employee daniel(3, 15000, 12, 26, "Daniel Cullen");
	employee_list.push_back(daniel);

	while (user_choice != 7) {
		switch (user_choice)
		{
		case 1: {
			std::cout << "Enter Employee Name: ";
			std::cin.ignore();
			getline(std::cin, employee_name);
			std::cout << "Enter Employee id: ";
			std::cin >> id;
			std::cout << "Enter Employee Hourly Pay: ";
			std::cin >> hourly_pay;
			std::cout << "Enter Employee Contracted Hours: ";
			std::cin >> contracted_hours;
			annual_salary = get_annual_salary(hourly_pay, contracted_hours);
			Employee new_employee(id, annual_salary, hourly_pay, contracted_hours, employee_name);
			employee_list.push_back(new_employee);
			std::cout << "Please enter a choice: ";
			std::cin >> user_choice;
			break;
		}
		case 2: {
			std::cout << "YOU HAVE ENTERED 2";
			std::cout << "Please enter a choice: ";
			std::cin >> user_choice;
			break;
		}
		case 5: {
			for (const Employee& emp: employee_list) {
				cout << "Name: " << emp.get_name() << "\tSalary: $" << emp.get_annual_salary() << endl;
			}

			std::cout << "Please enter a choice: ";
			std::cin >> user_choice;
			break;
		}
		case 7: {
			std::cout << "Thank You ";
			exit;
		}
		default:
			std::cout << "Sorry that is not an option !";
			std::cout << "Please enter a choice: ";
			std::cin >> user_choice;
			break;
		}
	}

	return 0;
}

