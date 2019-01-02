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
	std::string shots_to_string (Shot sts);
	std::string to_string() override;

};