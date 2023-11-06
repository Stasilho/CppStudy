#pragma once

#include <string>
#include <string_view>

/**
* Exercise 8-1
*/
class Person
{
	std::string m_firstName {};
	std::string m_lastName {};

	// Exercise 8-4
	std::string m_initials {};

public:

	Person() = default; // Exercise 8-2
	Person(std::string_view firstName, std::string_view lastName);
	// Exercise 8-4
	Person(std::string_view firstName, std::string_view lastName, std::string_view initials);

	// Exercise 8-3, 8-4
	Person(const Person& other) = default;
	Person& operator= (const Person& other) = default;
	virtual ~Person() = default;

	std::string getFirstName() const;

	void setFirstName(std::string_view firstName);

	std::string getLastName() const;

	void setLastName(std::string_view lastName);

	// Exercise 8-4
	std::string getInitials() const;

	void setInitials(std::string_view initials);
};