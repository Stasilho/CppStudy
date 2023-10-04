// CppStudy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <format>
#include <string>
#include <array>
#include <vector>

#include "Employee.h"
#include "AirlineTicket.h"

int main()
{
    std::cout << "Exercise 1-1 -----------------------------\n";

    HR::Employee employee {
        .firstInitial = 'A',
        .lastInitial = 'B',
        .employeeNumber = 47,
        .salary = 100000,
        .title = HR::Title::ENGINEER
    };

    std::cout << std::format("Employee: {}{}", employee.firstInitial, employee.lastInitial) << std::endl;
    std::cout << std::format("Number: {}", employee.employeeNumber) << std::endl;
    std::cout << std::format("Salary: {}", employee.salary) << std::endl;
    
    std::cout << "Exercise 1-2 -----------------------------\n";
    std::cout << format("Employee title: {}", getTitleName(employee.title)) << std::endl << std::endl;

    std::cout << "Exercise 1-3 -----------------------------\n";
    std::array<HR::Employee, 3> employees{
        HR::Employee{'A', 'X', 1, 60000, HR::Title::ENGINEER},
        HR::Employee{'B', 'Y', 1, 80000, HR::Title::SENIOR_ENGINEER},
        HR::Employee{'A', 'Z', 1, 100000, HR::Title::MANAGER}
    };

    for (auto& employee : employees) {
        printEmployee(employee);
    }

    std::cout << "Exercise 1-4 -----------------------------\n";
    std::vector<HR::Employee> vecEmployees;
    for (auto& employee : employees) {
        vecEmployees.push_back(employee);
    }

    std::cout << "Exercise 1-5, 1-6 ------------------------\n";
    AirlineTicket airlineTicket{ "Fjodor Sumkin", 137, true };
    airlineTicket.setFrequentFlyerNumber(555);

    std::cout << std::format("Ticket for {}, miles: {}, has rewards: {}",
        airlineTicket.getPassengerName(), airlineTicket.getNumberOfMiles(), 
        airlineTicket.hasEliteSuperRewardStatus()) << std::endl;

    if (airlineTicket.getFrequentFlyerNumber()) {
        std::cout << std::format("Frequent Flyer Number: {}", airlineTicket.getFrequentFlyerNumber().value()) << std::endl;
    }

    return 0;
}
