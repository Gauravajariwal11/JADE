#ifndef _PRODUCT_H
#define _PRODUCT_H

#include <iostream>
#include <string>


class Product {

protected:
	std::string _name;
	double _price;
	double _cost;

public:
	Product (std::string name, double price, double cost);
	std::string name();
	virtual std::string to_string();

};

#endif