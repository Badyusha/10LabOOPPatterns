#ifndef UNIT_HPP
#define UNIT_HPP

#include "Libs.hpp"

class Unit {
	std::string name;
public:
	Unit() : name("Евразия") {};

	std::string getName() const { return this->name; }

	void setName(const std::string& name_) { this->name = name_; }
};

#endif