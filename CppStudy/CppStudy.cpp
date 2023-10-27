// CppStudy.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <format>
#include <string>
#include <memory>
#include <array>
#include <vector>
#include <numeric>

#include "Point3D.h"

void excersise7_1();
void excersise7_2();
void excersise7_3();
void excersise7_4();

void printPoint(const Point3D& p);

void fillWithM(std::string& text);

int main()
{
	excersise7_2();
	excersise7_3();
	excersise7_4();

    return 0;
}

void excersise7_1()
{
	const size_t numberOfElements{ 10 };
	int* values{ new int[numberOfElements] };

	/**
	* 1. There is no need to create an array on the heap in this case since number of elements is a constant value
	* 2. Could be used std::array instead of using raw pointers
	* 3. Could be wrapped in unique ptr if the heap allocation is still considered
	*/

	// Set values to their index value.
	for (int index{ 0 }; index < numberOfElements; ++index) {
		values[index] = index;
	}

	/**
	* 1. This can be done using special tools
	*/
	
	// Set last value to 99.
	values[10] = 99;

	/**
	* 1. Last element index is 9, not 10. This will set the memory out of array bounds
	* 2. Better to use "numberOfElements - 1" instead of hardcoded index value
	* 3. Better to use size_t for the loop iterator type
	*/
	// Print all values.
	for (int index{ 0 }; index <= numberOfElements; ++index) {
		std::cout << values[index] << " ";
	}

	/**
	* 1. This will address array out of bounds again when index is equal to numberOfElements
	* 2. Raw pointer is not deleted in the end of use, memory leak!
	*/
}

void excersise7_2()
{
	std::array<int, 10> values {};

	std::iota(values.begin(), values.end(), 0);

	// Set last value to 99.
	values[values.size() - 1] = 99;

	// Print all values.
	for (size_t i{ 0 }; i < values.size(); ++i) {
		std::cout << values[i] << " ";
	}

	std::cout << std::endl;
}

void excersise7_3()
{
	auto pointPtr { std::make_unique<Point3D>(1.23f, .75f, -9.24f) };
	printPoint(*pointPtr);
}

void excersise7_4()
{
	std::string text{ "abcde" };
	fillWithM(text);

	std::cout << std::format("Filled string: {}", text) << std::endl;
}



void printPoint(const Point3D& p)
{
	std::cout << std::format("Point: x={}, y={}, z={}", p.getX(), p.getY(), p.getZ()) << std::endl;
}

void fillWithM(std::string& text)
{
	for (size_t i{ 0 }; i < text.size(); i++) {
		text[i] = 'm';
	}
}
