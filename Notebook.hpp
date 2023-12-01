#ifndef NOTEBOOK_HPP
#define NOTEBOOK_HPP

#include "PaperProduct.hpp"

class Notebook : public PaperProduct {
	bool isPlugIn;
	std::string type;
public:
	Notebook() : PaperProduct(), isPlugIn(false), type("Diary") {};
	Notebook(const int& paperCount_, const std::string& manufacturerName_,
		const bool& isPlugIn_, const std::string& type_) : PaperProduct(paperCount_, manufacturerName_)
	{
		this->isPlugIn = isPlugIn_;
		this->type = type_;
	}
	Notebook(const Notebook* object) : PaperProduct(object) {
		this->isPlugIn = object->isPlugIn;
		this->type = object->type;
	}
	~Notebook() {};

	PRODUCTS paperProductsType() const override { return PRODUCTS::NOTEBOOK; }

	Notebook* clone() const override {
		return new Notebook(*this);
	}

	static PaperProduct* makePaperProduct() { return new Notebook(); }

	static void Register() {
		PaperProduct::registerPaperProduct(Notebook::makePaperProduct());
	}

	void setIsPlugIn(const bool& isPlugIn_) { this->isPlugIn = isPlugIn_; }
	void setType(const std::string& type_) { this->type = type_; }

	bool IsPlugIn() const { return this->isPlugIn; }
	std::string getType() const { return this->type; }
};

#endif