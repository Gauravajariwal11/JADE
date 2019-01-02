#include "java.h"

Java::Java(std::string name, double price, double cost, int darkness) : Product{name, price, cost}, _darkness{0} { }
void Java::add_shot(Shot shot) {return _shots.push_back(shot);}