#include "Lecturer.h"



Lecturer::Lecturer(){
}

Lecturer::Lecturer(std::string name){
}

Lecturer::Lecturer(std::string name, std::string email, std::string staffID, std::string subject) : Person{ name, email }, staffID_{ staffID }, subjectArea_{ subject } {
}

Lecturer::~Lecturer()
{
}


void Lecturer::AddModule(Module m) {
	modules_.push_back(m);
}

void Lecturer::AddModule(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints) {
	Module m(moduleTitle, moduleCode, moduleCreditPoints);
	modules_.push_back(m);

}

std::string Lecturer::ToString() const {
	std::string output = Person::GetName() + " " + staffID_ + " " + Person::GetEmail() + " " + subjectArea_ +  "\n";
	return output;
}