// Another simple example of a STRUCTURE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


struct SomeObject
{
	int firstAtttribute; 
	std::string secondAttribute; 
	char thirdAttribute; 
};

struct Assignment
{
	int grade = 0; 
	std::string name = "To be determined";
	float weight = 0.20f; 
};

int main()
{
	Assignment firstAssignment = { 91, "Last assignment", 0.2f };
	Assignment secondAssignment = { 71, "Penultimate assignment", 0.2f };
	Assignment thirdAssignment = { 99, "Antepenultimate assignment", 0.2f };

	std::vector<Assignment> assignments = { firstAssignment, secondAssignment, thirdAssignment };


}
