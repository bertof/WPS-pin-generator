//
// Created by pily on 27/01/17.
//

#include <stdexcept>
#include "Pin.h"

/***
 *	Checks if the pin passed is a valid pin
 * @param pin: object of class Pin
 * @return true if pin is valid, false otherwise
 */
bool Pin::valid() const {
	bool valid = true;

	//TODO tests

	switch (valid) {
		case true:
			return valid;
			break;
		case false:
			throw std::logic_error("Pin generated is not valid");
			break;
	}

}

Pin::Pin(const std::string &pin) {
	this->pin = pin;
	this->valid();
}

std::string Pin::toString() const {
	std::to_string(pin);
}

long Pin::toInteger() const {
	return pin;
}

Pin::Pin(const long &pin) {
	return ;
}
