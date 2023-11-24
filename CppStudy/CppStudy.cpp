// CppStudy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <format>
#include <string>
#include <array>
#include <vector>
#include <memory>
#include <utility>

#include "Person.h"

void printPerson(const Person& person, std::string_view prefix = "Person")
{
    std::cout << std::format("{}: {} {} [{}]", prefix,
        person.getFirstName(), person.getLastName(), person.getInitials()) 
        << std::endl;
}

void printComparison(const Person& first, const Person& second)
{
    std::vector<std::pair<bool, std::string>> comparisons {
        {first < second, "less than"},
        {first > second, "greater than"},
        {first <= second, "less or equal to"},
        {first >= second, "greater or equal to"},
        {first == second, "is equal to"},
        {first != second, "is NOT equal to"}
    };

    for (const auto& pair : comparisons) {
        if (pair.first) {
            std::string message{ std::format("{} {} {} is {} {} {} {}",
                first.getFirstName(), first.getLastName(), first.getInitials(),
                pair.second, 
                second.getFirstName(), second.getLastName(), second.getInitials())};
            std::cout << message << std::endl;
        }
    }

    std::cout << std::endl;
}

void printComparisonTestCase()
{
    printComparison(Person{ "Aaron", "Blum" }, Person{ "Bonney", "Blum" });
    printComparison(Person{ "Daniel", "Blum" }, Person{ "Bonney", "Blum" });
    printComparison(Person{ "Aaron", "Blum" }, Person{ "Aaron", "Aber" });
    printComparison(Person{ "Aaron", "Blum" }, Person{ "Aaron", "Daniels" });
    printComparison(Person{ "John", "Doe" }, Person{ "John", "Doe" });
    printComparison(Person{ "John", "Doe", "MC" }, Person{ "John", "Doe", "DJ" });
}

int main()
{
    // Exercise 9-1
    std::cout << "Exercise 9-2" << "\n\n";

    std::string firstPersonFirstName { "Vasja" };
    std::string firstPersonLastName { "Pupkin" };
    Person firstPerson { firstPersonFirstName, firstPersonLastName };
    printPerson(firstPerson);

    Person secondPerson{ "Fedor", "Sumkin" };
    printPerson(secondPerson);

    Person thirdPerson{ "Dima", "Knopkin", "MC" };
    printPerson(thirdPerson);

    Person moveConstructedPerson{ Person{"Senja", "Popkin", "DJ"}};
    printPerson(moveConstructedPerson);

    Person moveAssignedPerson;
    moveAssignedPerson = std::move(moveConstructedPerson);
    printPerson(moveAssignedPerson, "Move assigned Person");

    // Exercise 9-2
    //std::cout << "\n\nExercise 9-2" << "\n\n";

    //printComparisonTestCase();

    // Conclusion: looks like the default <=> implementation is comparing all object fields in sequence they appear in the class, 
    // (if first fields are not equal then comparing next ones etc)

    // Exercise 9-3
    std::cout << "\n\nExercise 9-3" << "\n\n";
    printComparisonTestCase();

    return 0;
}
