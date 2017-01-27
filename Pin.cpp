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
	throw std::logic_error("NOT IMPLEMENTED");
}

Pin::Pin(const std::string &pin) {
	this->pin = pin;
}

std::string Pin::toString() const {
	return pin;
}
