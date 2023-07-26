// Imports
#include <iostream>
#include <vector>
#include <string>
#include "Employee.h"
using namespace std;

// Calculate anual salary based on inputs
int get_annual_salary(int hour, int contracted_hours){
	return hour * contracted_hours * 52;
}

// Swap Function for the bubble sort
void swap(vector<Employee> &vec, int index1, int index2) {
	Employee x = vec[index1];
	Employee y = vec[index2];
	vec[index2] = x;
	vec[index1] = y;
}

// Bubble sort for 6th option
void bubbleSort(vector<Employee> &vec, int size) {
	int i, j;
	bool swapped;
	for (int i = 0; i < size - 1; i++) {
		swapped = false;
		for (int j = 0; j < size - i - 1; j++) {
			if (vec[j].get_annual_salary() > vec[j + 1].get_annual_salary()) {
				swap(vec, j, j+1);
				swapped = true;
			}
		}

		if (swapped == false) {
			break;
		}
	}
}

// Bubble sort for 4th option
void searchBubbleSort(vector<Employee>& vec, int size) {
	int i, j;
	bool swapped;
	for (int i = 0; i < size - 1; i++) {
		swapped = false;
		for (int j = 0; j < size - i - 1; j++) {
			if (vec[j].get_id() > vec[j + 1].get_id()) {
				swap(vec, j, j + 1);
				swapped = true;
			}
		}

		if (swapped == false) {
			break;
		}
	}
}


// Binary Search for 4th option
int binarySearch(vector<Employee>& vec, int id, int low, int high) {
	int middle = (low + high) / 2;
	if (vec[middle].get_id() == id) {
		return middle;
	}
	else if (id > vec[middle].get_id()) {
		return binarySearch(vec, id, middle + 1, high);
	}
	else {
		return binarySearch(vec, id, low, middle -1);
	}
}


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
	Employee oleg2(72, 40020, 27, 35, "Oleg Glingeanu");
	employee_list.push_back(oleg2);
	Employee jibbie(7, 20000, 10, 30, "Jibril Adbulazeez");
	employee_list.push_back(jibbie);
	Employee jibbie2(76, 20020, 14, 30, "Jibril Adbulazeez");
	employee_list.push_back(jibbie2);
	Employee daniel(8, 15000, 12, 26, "Daniel Cullen");
	employee_list.push_back(daniel);
	Employee daniel2(66, 15003, 12, 26, "Daniel Cullen2");
	employee_list.push_back(daniel2);

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
			std::cout << "YOU HAVE ENTERED 2\n";
			std::cout << "Please enter a choice: ";
			std::cin >> user_choice;
			break;
		}
		case 4: {

			// Take in Employee ID
			std::cout << "Please enter Employee ID: ";
			std::cin >> id;


			// Make copy of the employee list to sort
			vector<Employee> search = employee_list;
			searchBubbleSort(search, search.size());


			// Binary search algorithm to find given ID
			int id_to_change = binarySearch(search, id, 0, search.size());
			Employee new_employee = search[id_to_change];


			// Display the Employee statistics
			cout << "Name: " << new_employee.get_name() << "\tID: " << new_employee.get_id() << "\tSalary: $" << new_employee.get_annual_salary() << endl;


			// Take in new wage for employee + update
			std::cout << "Please enter new hourly wage: ";
			std::cin >> hourly_pay;
			annual_salary = get_annual_salary(hourly_pay, new_employee.get_contracted_hours());
			new_employee.set_hourly_pay(hourly_pay);
			new_employee.set_annual_salary(annual_salary);


			// Display the Employee statistics after change
			cout << "Name: " << new_employee.get_name() << "\tID: " << new_employee.get_id() << "\tSalary: $" << new_employee.get_annual_salary() << endl;
			std::cout << "Please enter a choice: ";
			std::cin >> user_choice;
			break;

		}
		case 5: {
			for (const Employee& emp: employee_list) {
				cout << "Name: " << emp.get_name() << "\tID: "<< emp.get_id() << "\tSalary: $" << emp.get_annual_salary() << endl;
			}

			std::cout << "Please enter a choice: ";
			std::cin >> user_choice;
			break;
		}
		case 6: {
			vector<Employee> sorted = employee_list;
			bubbleSort(sorted, employee_list.size());
			for (const Employee& emp : sorted) {
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

