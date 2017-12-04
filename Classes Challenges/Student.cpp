/*
* Student.cpp
*
* Version information v0.1
* Author: Dr. Shane Wilson
* Date: 8/10/2017
* Description: Class definition .cpp file for the Student Class
* Copyright notice
*/

#include "Student.h"

//Initialise the static member
int Student::numberofStudents_{ 0 };

int Student::GetEnrolled() {
	return numberofStudents_;

}

//Default constuctor
//Note how we use the scope resolution operator ::
//We do that to specify which class the member functions belong to
//Class_Name::Member_Function
Student::Student() {
	std::cout << "The default Student class constructor was called to create an empty student" << std::endl;
	numberofStudents_++;
}

Student::Student(std::string name) : Person{ name } {
	
	std::cout << "The first custom Student class constructor was called to create " << Person::GetName() << std::endl;
	numberofStudents_++;
}

//This constructor creates and initialises it by copying the data from each variable
//into the specified data member. We use an initializer list but we could also initialize each
//variable by using assignment statements in the main body of the function
Student::Student(std::string name, std::string registration, std::string course, int yearofStudy) : Person{ name }, registrstionID_{ registration }, course_{ course },
	yearofStudy_{ yearofStudy}
{
	//std::cout << "The second custom Student class constructor was called to create " << Person::GetName() << std::endl;
	numberofStudents_++;

	//we could assign the values of the parameters to the data members like this
	//name_ = name;
};


Student::~Student() {
	//if (Person::GetName().size() > 0) {
	//	std::cout << "Destructor of the Student class called on " << Person::GetName() << std::endl;
	//}
	//else {
	//	std::cout << "Destructor of the Student  class called on empty student" << std::endl;
	//}
	numberofStudents_--;
}


//Overloaded equality operator 
bool Student::operator==(const Student& right) const {
	bool same{ true };
	if ((Person::GetName() != right.GetName()) || (course_ != right.GetCourse())) {
		return false;
	}
	return same;
}

//Getters and setters
void Student::SetName(std::string name) {
	Person::SetName(name);
}
//Make getters const so that it tells the compiler to complain if we accidentlly 
//try to change a data member 
std::string Student::GetName() const {
	return Person::GetName();
}

void Student::SetRegistrationID(std::string registrstionID) {
	registrstionID_ = registrstionID;
}
std::string Student::GetRegistrationID() const {
	return registrstionID_;
}

void Student::SetCourse(std::string course) {
	course_ = course;
}
std::string Student::GetCourse() const {
	return course_;
}

void Student::SetYearofStudy(int year) {
	yearofStudy_ = year;
}
int Student::GetYearofStudy() const {
	return yearofStudy_;
}

std::string Student::ToString() const {
	std::string output = Person::GetName() + " " + registrstionID_ + " " + course_ + " " + std::to_string(yearofStudy_) + " " + "\n";
		//+ std::to_string(moduleOneMark_) + " " + std::to_string(moduleTwoMark_) + " " + std::to_string(moduleThreeMark_) + "\n";
	//+yearofStudy_ + " " + moduleOneMark_ + " "	+ moduleTwoMark_ + " " + moduleThreeMark_;
	return output;
}

std::string Student::CalculateClassification() const {
//std::string Student::CalculateClassification(){

	float average{};

	//average = (moduleOneMark_ + moduleTwoMark_ + moduleThreeMark_) / 3;
	average = this->CalculateAverage();
	if (average < 40) {
		return "fail";
	}
	else if (average >= 40 && average <= 49) {
		return "3rd class";
	}
	else if (average >= 50 && average <= 59) {
		return "2nd class";
	}
	else if (average >= 60 && average <= 69) {
		return "2-1";
	}
	else
		return "1st class";

}

float Student::CalculateAverage() const {
	float average{};
	int index{ 0 };
	for (index ; index < this->moduleMarks_.size(); index++) {
		average += this->moduleMarks_.at(index).getModuleMark();
	}
	average = average / index;
		return average;
}

void Student::AddModule(Module m) {
	moduleMarks_.push_back(m);
}

void Student::AddModule(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark) {
	Module m(moduleTitle, moduleCode, moduleCreditPoints, moduleMark);
	moduleMarks_.push_back(m);

}

void Student::DeleteModule(std::string moduleCode) {
	//Loop through the module marks and remove a module that 
	for (int index = 0; index < moduleMarks_.size(); index++) {
		if (moduleMarks_.at(index).getModuleCode() == moduleCode) {
			moduleMarks_.erase(moduleMarks_.begin()+ index);
		}
	}

}
void Student::UpdateModule(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark) {
	//Loop through the module marks and remove a module that 
	for (int index = 0; index < moduleMarks_.size(); index++) {
		if (moduleMarks_.at(index).getModuleCode() == moduleCode) {
			moduleMarks_.at(index).setModuleCreditPoints(moduleCreditPoints);
			moduleMarks_.at(index).setModuleTitle(moduleTitle);
			moduleMarks_.at(index).setModuleMark(moduleMark);
		}
	}
}

int Student::GetNumberModules() {
	return this->moduleMarks_.size();

}

std::vector<Module> Student::GetModules() {
	return moduleMarks_;
}

std::ostream& operator<<(std::ostream& output, const Student& student) {
	output << "Name: " << student.GetName() << " Registration: " << student.registrstionID_ << " Course: " << student.course_ << " Year of study: " << student.yearofStudy_ << std::endl << std::endl;

	return output;
}

std::istream& operator>>(std::istream& input, Student& student) {
	//output << "Name: " << student.name_ << " Registration: " << student.registrstionID_ << " Course: " << student.course_ << " Year of study: " << student.yearofStudy_ << std::endl << std::endl;
	std::cout << "Please enter the student first name: ";
	std::string fname, sname;
	input >> fname;
	std::cout << "Please enter the student second name: ";
	input >> sname;
	
	fname += " " +sname;
	student.SetName(fname);
	std::cout << std::endl << "Please enter the student ID: ";
	input >> student.registrstionID_;
	std::cout << std::endl << "Please enter the student course: ";
	input >> student.course_;
	std::cout << std::endl << "Please enter the student year of study: ";
	input >> student.yearofStudy_;
	
	return input;
}

