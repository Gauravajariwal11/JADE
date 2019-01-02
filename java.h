#pragma once
#include "product.h"
#include <iostream>
#include <string>
#include <vector>

enum Shot{None, Chocolate, Vanilla, Peppermint, Hazelnut};

class Java : public Product {

protected:
	int _darkness;
	std::vector<Shot> _shots;

public:
	Java(std::string name, double price, double cost, int darkness);
	void add_shot(Shot shot);

};