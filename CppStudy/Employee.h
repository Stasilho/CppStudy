#pragma once

#include <string>

namespace HR 
{

	enum class Title
	{
		MANAGER,
		SENIOR_ENGINEER,
		ENGINEER
	};

	struct Employee
	{
		char firstInitial;
		char lastInitial;
		int employeeNumber;
		int salary;
		Title title;
	};

	std::string getTitleName(Title title);

	void printEmployee(Employee& employee);
}