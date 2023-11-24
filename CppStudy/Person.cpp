#include "Person.h"

#include <format>
#include <iostream>

// Exercise 9-4
struct Person::Impl
{
	std::string m_firstName{};
	std::string m_lastName{};
	std::string m_initials{};

	Impl() = default;

	Impl(std::string firstName, std::string lastName);
	Impl(std::string firstName, std::string lastName, std::string initials);

	Impl(const Impl& other) = default;
	Impl& operator= (const Impl& other) = default;

	Impl(Impl&& other) noexcept;
	Impl& operator= (Impl&& other) noexcept;

	virtual ~Impl() = default;

	[[nodiscard]] auto operator<=> (const Impl& other) const = default;
	[[nodiscard]] bool operator== (const Impl& other) const = default;

	std::string getFirstName() const;

	void setFirstName(std::string_view firstName);

	std::string getLastName() const;

	void setLastName(std::string_view lastName);

	std::string getInitials() const;

	void setInitials(std::string_view initials);
};

Person::Impl::Impl(std::string firstName, std::string lastName)
	: Impl{ std::move(firstName),
	std::move(lastName),
	std::move(std::format("{}{}", firstName.substr(0, 1), lastName.substr(0, 1))) }
{
	std::cout << "Person Impl 2-arg ctor invoked." << std::endl;
}

Person::Impl::Impl(std::string firstName, std::string lastName, std::string initials)
	: m_firstName{ std::move(firstName) },
	m_lastName{ std::move(lastName) },
	m_initials{ std::move(initials) }
{
	std::cout << "Person Impl 3-arg ctor invoked." << std::endl;
}

Person::Impl::Impl(Person::Impl&& other) noexcept
	: m_firstName{ std::exchange(other.m_firstName, {}) },
	m_lastName{ std::exchange(other.m_lastName, {}) },
	m_initials{ std::exchange(other.m_initials, {}) }
{
	std::cout << "Person Impl MOVE ctor invoked." << std::endl;
}

Person::Impl& Person::Impl::operator=(Person::Impl&& other) noexcept
{
	m_firstName = std::exchange(other.m_firstName, {});
	m_lastName = std::exchange(other.m_lastName, {});
	m_initials = std::exchange(other.m_initials, {});

	std::cout << "Person Impl MOVE assignment invoked." << std::endl;

	return *this;
}

std::string Person::Impl::getFirstName() const
{
	return m_firstName;
}

void Person::Impl::setFirstName(std::string_view firstName)
{
	m_firstName = firstName;
}

std::string Person::Impl::getLastName() const
{
	return m_lastName;
}

void Person::Impl::setLastName(std::string_view lastName)
{
	m_lastName = lastName;
}

std::string Person::Impl::getInitials() const
{
	return m_initials;
}

void Person::Impl::setInitials(std::string_view initials)
{
	m_initials = initials;
}



Person::Person()
	: m_impl{ std::make_unique<Impl>() }
{
}

Person::Person(std::string firstName, std::string lastName)
	: Person{ std::move(firstName),
	std::move(lastName),
	std::move(std::format("{}{}", firstName.substr(0, 1), lastName.substr(0, 1))) }
{
	std::cout << "Person 2-arg ctor invoked." << std::endl;
}

Person::Person(std::string firstName, std::string lastName, std::string initials)
	: m_impl{ std::make_unique<Impl>(std::move(firstName), std::move(lastName), std::move(initials)) }
{
	std::cout << "Person 3-arg ctor invoked." << std::endl;
}

Person::Person(const Person& other)
	: m_impl{ std::make_unique<Impl>(*other.m_impl) }
{
	std::cout << "Person COPY ctor invoked." << std::endl;
}

Person& Person::operator=(const Person& other)
{
	m_impl = std::make_unique<Impl>(*other.m_impl);

	std::cout << "Person COPY assignment invoked." << std::endl;

	return *this;
}

Person::Person(Person&& other) noexcept
	: m_impl{ std::move(other.m_impl) }
{
	std::cout << "Person MOVE ctor invoked." << std::endl;
}

Person& Person::operator=(Person&& other) noexcept
{
	m_impl = std::move(other.m_impl);

	std::cout << "Person MOVE assignment invoked." << std::endl;

	return *this;
}

bool Person::operator==(const Person& other) const
{
	return *m_impl == *other.m_impl;
}

Person::~Person() = default;

std::strong_ordering Person::operator<=>(const Person& other) const
{
	return *m_impl <=> *other.m_impl;
}

std::string Person::getFirstName() const
{
	return m_impl->getFirstName();
}

void Person::setFirstName(std::string_view firstName)
{
	m_impl->setFirstName(firstName);
}

std::string Person::getLastName() const
{
	return m_impl->getLastName();
}

void Person::setLastName(std::string_view lastName)
{
	m_impl->setLastName(lastName);
}

std::string Person::getInitials() const
{
	return m_impl->getInitials();
}

void Person::setInitials(std::string_view initials)
{
	m_impl->setInitials(initials);
}


// Exercise 9-3

//bool operator<(const Person& left, const Person& right)
//{
//	if (left.getFirstName() < right.getFirstName()) {
//		return true;
//	} else if (left.getFirstName() == right.getFirstName()) {
//		if (left.getLastName() < right.getLastName()) {
//			return true;
//		} else if (left.getLastName() == right.getLastName()) {
//			if (left.getInitials() < right.getInitials()) {
//				return true;
//			}
//		}
//	}
//	
//	return false;
//}
//
//bool operator==(const Person& left, const Person& right)
//{
//	return left.getFirstName() == right.getFirstName() 
//		&& left.getLastName() == right.getLastName()
//		&& left.getInitials() == right.getInitials();
//}
//
//bool operator>(const Person& left, const Person& right)
//{
//	return !(left < right || left == right);
//}
//
//bool operator<=(const Person& left, const Person& right)
//{
//	return left < right || left == right;
//}
//
//bool operator>=(const Person& left, const Person& right)
//{
//	return !(left < right);
//}
//
//bool operator!=(const Person& left, const Person& right)
//{
//	return !(left == right);
//}