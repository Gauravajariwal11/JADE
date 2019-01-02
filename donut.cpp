#include "donut.h"

Donut::Donut(std::string name,double price, double cost, Frosting frosting, bool sprinkles, Filling filling) 
	: Product{name, price, cost}, _frosting{frosting}, _sprinkles{false}, _filling{filling} {}

std::string Donut::frosting_to_string(Frosting frost) {
	if(frost == Frosting::UNFROSTED) {return "Unfrosted";}
	else if (frost == Frosting::CHOCOLATE_TOP) {return "Chocolate_Top";}
	else if (frost == Frosting::VANILLA_TOP) {return "Vanilla_Top";}
	else {return "Pink_Top";}
}

std::string Donut::filling_to_string(Filling fill){
	if (fill == Filling::UNFILLED) return "Unfilled";
	else if (fill == Filling::CREME) return "Creme";
	else if (fill == Filling::BAVARIAN) return "Bavarian";
	else return "Strawberry";
}

std::string Donut::to_string() {

	std::string result = Product::to_string();
	std::string separator = "(";
	std::string terminator = ".";

	if(_frosting != UNFROSTED) {
		result += separator + "frosted with " + Donut::frosting_to_string(_frosting);
		if (_sprinkles) result += " and sprinkles";
		separator = ", ";
		terminator = ")"; 
	}

	if (_filling != UNFILLED){
		result += separator + "filled with " + Donut::filling_to_string(_filling);
		terminator = ")";
	}

	result += terminator;
	return result;

}