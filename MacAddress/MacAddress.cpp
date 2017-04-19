//
// Created by pily on 29/03/17.
//

#include "MacAddress.h"
#include "../Exceptions/InvalidInputException.h"

MacAddress::MacAddress(std::string) {
	if (!MacAddress::checkValue(const std::string &valuePassed)){
		throw (InvalidInputException);
	}
}
