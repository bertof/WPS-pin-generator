//
// Created by pily on 27/01/17.
//

#ifndef WPS_PIN_GENERATOR_PIN_H
#define WPS_PIN_GENERATOR_PIN_H

#include <string>

class Pin {

private:
	std::string pin;  // content of the pin (string with 8 digits)

public:
	Pin(const std::string &pin);

	bool valid() const;

	std::string toString() const;

};


#endif //WPS_PIN_GENERATOR_PIN_H
