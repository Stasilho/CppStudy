#pragma once

#include <string>
#include <string_view>
#include <memory>

class Person
{

	class Impl;
	std::unique_ptr<Impl> m_impl;

public:

	Person();

	Person(std::string firstName, std::string lastName);
	Person(std::string firstName, std::string lastName, std::string initials);

	Person(const Person& other);
	Person& operator= (const Person& other);

	Person(Person&& other) noexcept;
	Person& operator= (Person&& other) noexcept;

	// Exercise 9-2
	[[nodiscard]] std::strong_ordering operator<=> (const Person& other) const;
	[[nodiscard]] bool operator== (const Person& other) const;

	~Person();

	std::string getFirstName() const;

	void setFirstName(std::string_view firstName);

	std::string getLastName() const;

	void setLastName(std::string_view lastName);

	std::string getInitials() const;

	void setInitials(std::string_view initials);
};

// Exercise 9-3

//bool operator< (const Person& left, const Person& right);
//
//bool operator== (const Person& left, const Person& right);
//
//bool operator> (const Person& left, const Person& right);
//
//bool operator<= (const Person& left, const Person& right);
//
//bool operator>= (const Person& left, const Person& right);
//
//bool operator!= (const Person& left, const Person& right);

