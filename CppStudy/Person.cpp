#include "Person.h"

#include <format>
#include <iostream>

Person::Person(std::string_view firstName, std::string_view lastName)
	: Person{firstName, lastName, std::format("{}{}", firstName.substr(0, 1), lastName.substr(0, 1))}
{
}

Person::Person(std::string_view firstName, std::string_view lastName, std::string_view initials)
	: m_firstName{firstName},
	m_lastName{lastName},
	m_initials{initials}
{
}

//Person::Person(const Person& other)
//	: m_firstName{other.m_firstName}, m_lastName{other.m_lastName}
//{
//	std::cout << std::format("Person {} {} Copy ctor invoked.", m_firstName, m_lastName) << std::endl;
//}
//
//Person& Person::operator=(const Person& other)
//{
//	if (this != &other) {
//		m_firstName = other.m_firstName;
//		m_lastName = other.m_lastName;
//	}
//
//	std::cout << std::format("Person {} {} assignment invoked.", m_firstName, m_lastName) << std::endl;
//
//	return *this;
//}
//
//Person::~Person()
//{
//	std::cout << std::format("Person {} {} Destructor invoked.", m_firstName, m_lastName) << std::endl;
//}

std::string Person::getFirstName() const
{
	return m_firstName;
}

void Person::setFirstName(std::string_view firstName)
{
	m_firstName = firstName;
}

std::string Person::getLastName() const
{
	return m_lastName;
}

void Person::setLastName(std::string_view lastName)
{
	m_lastName = lastName;
}

std::string Person::getInitials() const
{
	return m_initials;
}

void Person::setInitials(std::string_view initials)
{
	m_initials = initials;
}
