#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

struct Employee {
	std::string name;
	std::string position;
	unsigned int age;

	std::string getName() const
	{
		return name;
	}

	std::string getPosition() const
	{
		return position;
	}

	unsigned int getAge() const
	{
		return age;
	}

	Employee() = default;

	Employee(const std::string& p_name, const std::string& p_position,
			 unsigned int p_age)
		: name(p_name), position(p_position), age(p_age)
	{
	}
	
	friend std::ostream& operator<<(std::ostream& out, const Employee& employee)
	{
		out << ", Name: " << employee.getName()
			<< ", Position: " << employee.getPosition()
			<< ", Age: " << employee.getAge();
		return out;
	}
	
};

#endif
