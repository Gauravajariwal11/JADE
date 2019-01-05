#include "java.h"

Java::Java(std::string name, double price, double cost, int darkness) : Product{name, price, cost}, _darkness{darkness} { }
void Java::add_shot(Shot shot) {_shots.push_back(shot);}
std::string Java::shots_to_string(Shot sts) {
	if (sts == Shot::None) return "None";
	else if (sts == Shot::Chocolate) return "Chocolate";
	else if (sts == Shot::Vanilla) return "Vanilla";
	else if (sts == Shot::Peppermint) return "Peppermint";
	else return "Hazelnut";
}
std::string Java::Darkness_to_string(int _darkness) {
	if (_darkness == 1) return "Blonde"; 
	else if (_darkness == 2) return "Light";
	else if (_darkness == 3) return "Medium";
	else if (_darkness == 4) return "Dark";
	else return "Extra Dark";

}

std::string Java::to_string() { 
	std::string result = Product::to_string() + " (" + Java::Darkness_to_string(_darkness) + ") with ";


//	result += std::to_string(_darkness);
	for (auto i : _shots) { result += Java::shots_to_string(i) + " "; }

	result += ".";

	return result;
}