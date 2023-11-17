// CppStudy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <format>
#include <string>
#include <array>
#include <vector>
#include <memory>

#include "Person.h"

int main()
{
    // Exercise 8-1
    Person stackPerson { "Fedor", "Sumkin" };
    auto heapPerson { std::make_unique<Person>("Vasja", "Pupkin") };

    // Exercise 8-2
    //Person phoneBook[3]; 
    // - doesn't compile because the lack of the default ctor for Person class.
    // The default ctor is absent because the ctor with parameters is declared

    // Exercise 8-3
    Person anotherForCopy{ stackPerson };
    Person anotherForAssignment;
    anotherForAssignment = *heapPerson;

    std::cout << std::format("Copied person: {}", anotherForCopy.getInitials()) << std::endl;
    std::cout << std::format("Assigned person: {}", anotherForAssignment.getInitials()) << std::endl;

    return 0;
}
