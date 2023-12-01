#ifndef MAGAZINE_HPP
#define MAGAZINE_HPP

#include "PaperProduct.hpp"

class Magazine : public PaperProduct {
	bool isSleek;
	std::string category;
public:
	Magazine() : PaperProduct(), isSleek(true), category("Fashion") {};
	Magazine(const int& paperCount_, const std::string& manufacturerName_,
		const bool& isSleek_, const std::string& category_) : PaperProduct(paperCount_, manufacturerName_)
	{
		this->isSleek = isSleek_;
		this->category = category_;
	}
	Magazine(const Magazine* object) : PaperProduct(object) {
		this->isSleek = object->isSleek;
		this->category = object->category;
	}
	~Magazine() {};

	PRODUCTS paperProductsType() const override { return PRODUCTS::MAGAZINE; }

	Magazine* clone() const override {
		return new Magazine(*this);
	}

	static PaperProduct* makePaperProduct() { return new Magazine(); }

	static void Register() {
		PaperProduct::registerPaperProduct(Magazine::makePaperProduct());
	}

	void setIsSleek(const bool& isSleek_) { this->isSleek = isSleek_; }
	void setCategory(const std::string& category_) { this->category = category_; }

	bool IsSleek() const { return this->isSleek; }
	std::string getCategory() const { return this->category; }
};

#endif