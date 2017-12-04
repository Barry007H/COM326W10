#include "Person.h"



Person::Person(){
}


Person::Person(std::string name) : name_{ name } {

}
Person::Person(std::string name, std::string email) : name_{ name }, email_{ email } {}


Person::~Person(){
}

std::string Person::GetName()const {
	return name_;
}
void Person::SetName(std::string name) {
	name_ = name;
}

std::string Person::GetEmail()const {
	return email_;
}
void Person::SetEmail(std::string email) {
	email_ = email;
}

//std::string Person::ToString(){
//	std::ostringstream output;
//	output << name_ << " " << email_ << std::endl;
//
//	return output.str();
//}

