//
// Created by pily on 27/01/17.
//

#include <stdexcept>
#include "Generator.h"

Pin Generator::generatePin(const std::string &s) const {
	return generatePinImp(s);
}

Pin Generator::generatePinImp(const std::string &s) const {
	throw std::logic_error("NOT IMPLEMENTED");
}
