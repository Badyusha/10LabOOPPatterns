#ifndef NOTE_HPP
#define NOTE_HPP

#include "Unit.hpp"

class MiniMap : public Unit {
	std::string state;
public:
	MiniMap() : state("Europe") {};

	std::string getState() const { return this->state; }

	void setState(const std::string& state_) { this->state = state_; }
};

#endif