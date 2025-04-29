// Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>


struct Person
{
	int age; 
	std::string name; 
	std::string eyeColor; 

};

void printListOfPeople(const std::vector<Person> listOfPeople)
{
	for (int i = 0; i < listOfPeople.size(); ++i)
		std::cout
		<< listOfPeople[i].name
		<< "\t"
		<< listOfPeople[i].age
		<< "\t" //SHOULD use std::setw() from <iomanip> 
		<< listOfPeople[i].eyeColor
		<< "\n";
}



int main()
{
	//arrays are "homogeneous" 
	//std::vector<int> nums = { 1, 2, 3, "42" };

	Person you = { 23, "Joe Blow from Cocomo", "A very pretty gray" };

	std::cout << you.name << "\t" << you.age << "\t" << you.eyeColor << "\n"; //behold! the dot operator 

	Person me = { 31, "Seth Norman", "A MILDLY pretty blue" };


	Person otherPerson = { 123, "Old person", "Faded with the wisdom of time" };

	//create a list of people: 
	std::vector<Person> listOfPeople =
	{
		me, you, otherPerson
	}; 

	printListOfPeople(listOfPeople); 


}
