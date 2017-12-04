/*
* Student.h
*
* Version information
* Author: Dr. Shane Wilson
* Date: 08/10/2017
* Description: Class declaration header file for the Student Class
* Copyright notice
*/

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Module.h"
#include "Person.h"

class Student : public Person {

	//Number of students
	static int numberofStudents_;

	//Priviate data members - we make them private so we can protect the data
	//This enforces encapsulation. We control access through the public member functions
private:
	std::string registrstionID_;
	std::string course_;
	int yearofStudy_;

	std::vector<Module> moduleMarks_{};

	//int moduleOneMark_;
	//int moduleTwoMark_;
	//int moduleThreeMark_;
	float CalculateAverage() const;

public:
	//Public member functions

	//Our default constructor. This does nothing other than create an empty student object. 
	//There isn't any data in the student object
	Student();

	//Custom constructor. We use this to initialise the object with data we pass in
	Student(std::string name, std::string registration, std::string course, int yearofStudy);

	Student(std::string name);

	//Student class destructor
	~Student();

	//Overload the output operator
	friend std::ostream& operator<<(std::ostream& output, const Student&);
	//Overload the input operator
	friend std::istream& operator>>(std::istream& output, Student&);

	//Overload the comparision operator
	bool operator==(const Student&) const;

	//Getters and setters for each member variable
	void SetName(std::string name);
	std::string GetName() const;

	void SetRegistrationID(std::string registrstionID);
	std::string GetRegistrationID() const;

	void SetCourse(std::string course);
	std::string GetCourse() const;

	void SetYearofStudy(int year);
	int GetYearofStudy() const;

	void AddModule(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark);
	void AddModule(Module m);
	void DeleteModule(std::string moduleCode);
	void UpdateModule(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark);
	std::vector<Module> GetModules();
	int GetNumberModules();

	//void ToString() const;
	virtual std::string ToString() const ;

	std::string Student::CalculateClassification() const;
	//std::string Student::CalculateClassification();
	
	static int GetEnrolled();
};