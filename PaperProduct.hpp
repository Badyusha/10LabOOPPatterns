#ifndef PAPERPRODUCT_HPP
#define PAPERPRODUCT_HPP


#include "Unit.hpp"


class PaperProduct;

int paperProductsCount = 0;

std::vector<std::pair<int, PaperProduct*>> paperProductRegistryVector;

class PaperProduct {
	int papersCount;
	std::string manufacturerName;

public:
	PaperProduct() : papersCount(0), manufacturerName("none") {};
	PaperProduct(const int& paperCount_, const std::string& manufacturerName_);
	PaperProduct(const PaperProduct* object) {
		this->papersCount = object->papersCount;
		this->manufacturerName = object->manufacturerName;
	}
	
	static void registerPaperProduct(PaperProduct* factory) {
		paperProductRegistryVector.push_back(std::make_pair(paperProductsCount++, factory));
	}

	static PaperProduct* makePaperProduct(const int& paperProductType) {
		PaperProduct* factory = paperProductRegistryVector.at(paperProductType).second;
		return factory;
	}

	virtual ~PaperProduct() {};
	virtual PRODUCTS paperProductsType() const = 0;
	virtual PaperProduct* clone() const = 0;
};

inline PaperProduct::PaperProduct(const int& papersCount_, const std::string& manufacturerName_) {
	this->papersCount = papersCount_;
	this->manufacturerName = manufacturerName_;
}


#endif