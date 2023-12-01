#ifndef BOOK_HPP
#define BOOK_HPP

#include "PaperProduct.hpp"

class Book : public PaperProduct {
	std::string genre;
	std::string coverType;
public:
	Book() : PaperProduct(), genre("Romantic"), coverType("Hard cover") {};
	Book(const int& paperCount_, const std::string& manufacturerName_,
			const std::string& genre_, const std::string& coverType_) : PaperProduct(paperCount_, manufacturerName_)
	{
		this->genre = genre_;
		this->coverType = coverType_;
	}
	Book(const Book* object) : PaperProduct(object) {
		this->genre = object->genre;
		this->coverType = object->coverType;
	}
	~Book() {};

	PRODUCTS paperProductsType() const override { return PRODUCTS::BOOK; }

	Book* clone() const override {
		return new Book(*this);
	}

	static PaperProduct* makePaperProduct() { return new Book(); }

	static void Register() {
		PaperProduct::registerPaperProduct(Book::makePaperProduct());
	}

	void setGenre(const std::string& genre_) { this->genre = genre_; }
	void setCoverType(const std::string& coverType_) { this->coverType = coverType_; }

	std::string getGenre() const { return this->genre; }
	std::string getCoverType() const { return this->coverType; }
};


#endif