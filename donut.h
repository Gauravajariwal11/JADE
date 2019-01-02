#pragma once 
#include "product.h"
#include <string>
#include <iostream>

enum Frosting{UNFROSTED, CHOCOLATE_TOP, VANILLA_TOP, PINK_TOP};
enum Filling{UNFILLED, CREME, BAVARIAN, STRAWBERRY};


class Donut : public Product {

protected:
	Frosting _frosting;
	bool _sprinkles;
	Filling _filling;

public:
	Donut(std::string name,double price, double cost, Frosting frosting, bool sprinkles, Filling filling);
	std::string to_string() override; 
	std::string frosting_to_string (Frosting frost);
	std::string filling_to_string(Filling fill);
};