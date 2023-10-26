#include "Employee.h"

#include <iostream>
#include <format>

using namespace std;

std::string HR::getTitleName(Title title)
{
	switch (title) {
		using enum HR::Title;
		case MANAGER:
			return "Manager";
		case SENIOR_ENGINEER:
			return "Senior Engineer";
		case ENGINEER:
		default:
			return "Engineer";
	}
}

void HR::printEmployee(const Employee& employee)
{
	cout << format("Employee: {}{}", employee.firstInitial, employee.lastInitial) << endl;
	cout << format("Number: {}", employee.employeeNumber) << endl;
	cout << format("Salary: {}", employee.salary) << endl;
	cout << format("Employee title: {}", getTitleName(employee.title)) << endl << endl;
}