#ifndef GEOMAP_HPP
#define GEOMAP_HPP

#include "PaperProduct.hpp"
#include "Note.hpp"

class GeoMap : public PaperProduct, public MiniMap {
	std::string region;
	std::string scale;
public:
	GeoMap() : PaperProduct(), region("World"), scale("1:50000000") {};
	GeoMap(const int& paperCount_, const std::string& manufacturerName_,
			const std::string& region_, const std::string& scale_) : PaperProduct(paperCount_, manufacturerName_)
	{
		this->region = region_;
		this->scale = scale_;
	}

	GeoMap(const GeoMap* object) : PaperProduct(object) {
		this->region = object->region;
		this->scale = object->scale;
	}

	~GeoMap() {};

	PRODUCTS paperProductsType() const override { return PRODUCTS::GEO_MAP; }

	GeoMap* clone() const override {
		return new GeoMap(*this);
	}

	static MiniMap* makeUnit() { return new MiniMap(); }

	static PaperProduct* makePaperProduct() { return new GeoMap(); }
	

	static void Register() {
		PaperProduct::registerPaperProduct(GeoMap::makePaperProduct());
	}


	void setRegion(const std::string& region_) { this->region = region_; }
	void setScale(const std::string& scale_) { this->scale = scale_; }

	std::string getRegion() const { return this->region; }
	std::string getScale() const { return this->scale; }
};


#endif