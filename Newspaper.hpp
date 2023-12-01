#ifndef NEWSPAPER_HPP
#define NEWSPAPER_HPP

#include "PaperProduct.hpp"

class Newspaper : public PaperProduct {
	int releaseNumber;
	bool isDaily;
public:
	Newspaper() : PaperProduct(), releaseNumber(4587), isDaily(false) {};
	Newspaper(const int& paperCount_, const std::string& manufacturerName_,
				const int& releaseNumber_, const bool& isDaily_) : PaperProduct(paperCount_, manufacturerName_)
	{
		this->releaseNumber = releaseNumber_;
		this->isDaily = isDaily_;
	}
	Newspaper(const Newspaper* object) : PaperProduct(object) {
		this->releaseNumber = object->releaseNumber;
		this->isDaily = object->isDaily;
	}
	~Newspaper() {};

	PRODUCTS paperProductsType() const override { return PRODUCTS::NEWSPAPER; }

	Newspaper* clone() const override {
		return new Newspaper(*this);
	}

	static PaperProduct* makePaperProduct() { return new Newspaper(); }

	static void Register() {
		PaperProduct::registerPaperProduct(Newspaper::makePaperProduct());
	}

	void setReleaseNumber(const int& releaseNumber_) { this->releaseNumber = releaseNumber_; }
	void setIsDaily(const bool& isDaily_) { this->isDaily = isDaily_; }

	int getReleaseNumber() const { return this->releaseNumber; }
	bool IsDaily() const { return this->isDaily; }
};

#endif