/*
* Person.h
*
* Version information
* Author: Dr. Shane Wilson
* Date: 22/11/2017
* Description: Class declaration header file for the Person base Class
* Copyright notice
*/

#pragma once
#include <iostream>
#include <sstream>
#include <string>

class Person
{
private:
	std::string name_;
	std::string email_;
public:
	Person();
	explicit Person(std::string name);
	Person(std::string name, std::string email);
	virtual ~Person();

	std::string GetName()const;
	void SetName(std::string name);

	std::string GetEmail()const;
	void SetEmail(std::string email);

	virtual std::string ToString() const =0;
	//virtual std::string ToString();

};

