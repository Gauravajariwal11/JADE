#include "java.h"

Java::Java(std::string name, double price, double cost, int darkness) : Product{name, price, cost}, _darkness{0} { }
void Java::add_shot(Shot shot) {_shots.push_back(shot);}
std::string Java::shots_to_string(Shot sts) {
	if (sts == Shot::None) return "None";
	else if (sts == Shot::Chocolate) return "Chocolate";
	else if (sts == Shot::Vanilla) return "Vanilla";
	else if (sts == Shot::Peppermint) return "Peppermint";
	else return "Hazelnut";
}

std::string Java::to_string() { 
	std::string result = Product::to_string();
	std::string separator = "(";
	std::string terminator = ".";

	result += std::to_string(_darkness);
	for (auto i : _shots) { result += shots_to_string(i) + " "; }

	result += terminator;

	return result;
}