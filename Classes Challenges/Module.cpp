#include "Module.h"


Module::Module()
{
	//std::cout << "Default constructor of the Module class called" << std::endl;
}
Module::Module(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints, int moduleMark) :
	moduleTitle_{ moduleTitle }, moduleCode_{ moduleCode }, moduleCreditPoints_{ moduleCreditPoints }, moduleMark_{ moduleMark } {

	//std::cout << "Custom constructor of the Module class called to create: " << moduleTitle_ << std::endl;
}

Module::Module(std::string moduleTitle, std::string moduleCode, int moduleCreditPoints) :
	moduleTitle_{ moduleTitle }, moduleCode_{ moduleCode }, moduleCreditPoints_{ moduleCreditPoints } {

	//std::cout << "Custom constructor of the Module class called to create: " << moduleTitle_ << std::endl;
}

Module::~Module()
{
	/*if (moduleTitle_.size() > 0) {
		std::cout << "Destructor of the Module class called on " << moduleTitle_ << std::endl;
	}
	else {
		std::cout << "Destructor of the Module class called on empty module" << std::endl;
	}*/
}

std::string Module::getModuleTitle() const{
	return moduleTitle_;
}
void Module::setModuleTitle(std::string title) {
	moduleTitle_ = title;
}

std::string Module::getModuleCode() const {
	return moduleCode_;
}
void Module::setModuleCode(std::string code) {
	moduleCode_ = code;
}


int Module::getModuleMark() const {
	return moduleMark_;
}
void Module::setModuleMark(int mark) {
	moduleMark_ = mark;
};


int  Module::getModuleCreditPoints() const {
	return moduleCreditPoints_;
}
void  Module::setModuleCreditPoints(int creditPoints) {
	moduleCreditPoints_ = creditPoints;
}

std::string Module::ToString() const {
	std::string output = moduleTitle_ + " " + moduleCode_ + " " + std::to_string(moduleCreditPoints_) + " " + std::to_string(moduleMark_) + " " + "\n";
	return output;
}