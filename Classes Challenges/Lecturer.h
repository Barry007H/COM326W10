/*
* Lecturer.h
*
* Version information
* Author: Dr. Shane Wilson
* Date: 22/11/2017
* Description: Class declaration header file for the lecturer Class
* Copyright notice
*/

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Person.h"
#include "Module.h"

class Lecturer : public Person {

private:
	std::string staffID_;
	std::string subjectArea_;
	std::vector<Module> modules_;

public:
	Lecturer();
	explicit Lecturer(std::string name);
	Lecturer(std::string name, std::string email, std::string staffID, std::string subject);

	void AddModule(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints);
	void AddModule(Module m);


	~Lecturer();

	virtual std::string ToString() const;
};

