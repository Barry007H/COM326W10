/*
* Main.cpp
*
* Version information v0.1
* Author: Dr. Shane Wilson
* Date: 8/10/2017
* Description: Driver to test the student class
* Copyright notice
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Student.h"
#include "Module.h"
#include "Person.h"
#include "Lecturer.h"

using namespace std;

bool WriteStudentDetails(std::vector<Student>& data);
std::vector<Student> ReadStudentDetails(std::string dataFile);

int main() {

	cout << "Creating student details " << endl;

	Student tempStudent1{ "Billy Friel", "B00456855", "BSc Hons Computing", 3 };
	tempStudent1.SetEmail("Bily@billy.com");
	tempStudent1.AddModule("Databases", "COM323", 20, 57);
	tempStudent1.AddModule("Programming 1", "COM322", 20, 87);
	tempStudent1.AddModule("Systems Analysis", "COM132", 20, 23);

	Student tempStudent2{ "Michael Doherty", "B00458665", "BA Celtic Studies", 3 };
	tempStudent2.SetEmail("Michael@Michael.com");
	tempStudent2.AddModule("Irish", "CEL211", 20, 82);
	tempStudent2.AddModule("Crosses and stuff", "CEL112", 20, 75);
	tempStudent2.AddModule("The druids", "CEL322", 20, 56);


	Student tempStudent3{ "Robert McGonigle", "B00658655", "BSc Hons Biomedical Science", 3 };
	tempStudent3.SetEmail("Robert@Robert.com");
	tempStudent3.AddModule("DNA 1", "BIO101", 20, 67);
	tempStudent3.AddModule("DNA 2", "BIO102", 20, 75);
	tempStudent3.AddModule("Organic chemistry", "BIO322", 20, 72);


	Student tempStudent4{ "Clare McLaughlin", "B00586565", "BSc Hons Mechanical Engineering", 3 };
	tempStudent4.SetEmail("Clare@Clare.com");
	tempStudent4.AddModule("Drills and presses", "MEC167", 20, 67);
	tempStudent4.AddModule("Lathes", "MEC573", 20, 82);
	tempStudent4.AddModule("Hammering metal", "MEC372", 20, 56);

	//Create a vector containing student details
	std::vector<Student> studentData;
	studentData.push_back(tempStudent1);
	studentData.push_back(tempStudent2);
	studentData.push_back(tempStudent3);
	studentData.push_back(tempStudent4);

	

	WriteStudentDetails(studentData);
	vector<Student> StudentDetailsFromFile = ReadStudentDetails("studentData.txt");

	cout << endl << endl;

	//Loop through the vector and write student details out
	for (std::vector<Student>::iterator it = StudentDetailsFromFile.begin(); it != StudentDetailsFromFile.end(); it++) {
		//Write out the details of the student to screen
		cout << it->ToString();
		vector<Module> studentModules = it->GetModules();
		for (int i = 0; i < studentModules.size(); i++) {
			cout << studentModules[i].ToString();
		}
		cout << std::endl;
	}	
	return 0;
}

bool WriteStudentDetails(std::vector<Student>& data) {

	//The issue is with writing student details out to the file. It adds a new line after the 
	//last record and therefore the read code doesn't reach eof after reading the last module.
	//As a result it reads the details again.

	cout << "Attempting to write student data to file" << endl;

	//Open a file for writing
	ofstream outFile{ "studentData.txt", ios::out };

	//Check to see if the file exists
	if (!outFile) {
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}
	
	//Loop through the vector and write student details out
	for (std::vector<Student>::iterator it = data.begin(); it != data.end(); it++) {
		//Write out the details of the student
		 outFile << quoted(it->GetName()) << " " << quoted(it->GetRegistrationID()) << " " << quoted(it->GetCourse()) << " " << it->GetYearofStudy() << std::endl;

		//Check to see if there is module data to write to file
		int numModules = it->GetNumberModules();
		if (numModules > 0) {
			//Write the number of modules for the student
			//outFile << numModules << std::endl; //remove don't add a new line after the number of modules
			outFile << numModules;
			for (int index = 0; index < numModules; index++) {
				//Write out the module details
				std::vector<Module> marks = it->GetModules();
				//outFile << quoted(marks[index].getModuleTitle()) << " " << quoted(marks[index].getModuleCode()) << " " << marks[index].getModuleCreditPoints() << " " << marks[index].getModuleMark() << std::endl;	
				outFile << "\n" << quoted(marks[index].getModuleTitle()) << " " << quoted(marks[index].getModuleCode()) << " " << marks[index].getModuleCreditPoints() << " " << marks[index].getModuleMark();
				//Start each module on a new line

			}
		}
		else {
			outFile << numModules << std::endl;
		}
	}
	outFile.close();

	return true;
}

std::vector<Student> ReadStudentDetails(std::string dataFile) {
	cout << "Attempting to read student data from file" << endl;

	//Open a file for writing
	ifstream inFile{ "studentData.txt", ios::in };

	//Check to see if the file exists
	if (!inFile) {
		cerr << "File could not be opened" << endl;
		exit(EXIT_FAILURE);
	}

	//We know the file format is:
	//"Student name" "ID" "COURSE" Year of study
	//number of modules
	//"module title" "code" credit points mark

	std::string name, ID, course, moduleTitle, code;
	int numModules, creditPoints, yearStudy;
	float mark;
	std::vector<Student> students;

	//Keep reading data until we get to the end of the file
	while (!inFile.eof()) {
		inFile >> quoted(name) >> quoted(ID) >> quoted(course) >> yearStudy >> numModules;
		//Create a sutdent 
		Student tempStudent{ name, ID, course, yearStudy };
		if (numModules > 0) {
			for (int index = 0; index < numModules; index++) {
				inFile >> quoted(moduleTitle) >> quoted(code) >> creditPoints >> mark;
				tempStudent.AddModule(moduleTitle, code, creditPoints, mark);
			}
			//Add the tempstudent to the vector
			students.push_back(tempStudent);
		}
	}
	inFile.close();
	
	return students;
}