#pragma once
#include "product.h"
//#include "mainwin.h"
#include <iostream>
#include <string>
#include <vector>

class Store {

protected:
	std::string _name;
	std::vector<Product*> _products;

public:
	Store(std::string store_name);
	std::string name();
	void add_product(Product* product);
	int number_of_products();
	std::string product_to_string(int product);

};