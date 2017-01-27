//
// Created by pily on 27/01/17.
//

#ifndef WPS_PIN_GENERATOR_PIN_H
#define WPS_PIN_GENERATOR_PIN_H

#include <string>

/**
 * Class Pin
 * This type identifies a WPS pin solution
 * @var pin: contains all the info about the pin
 */
class Pin {

private:
	long pin;  // content of the pin

public:
	/**
	 * Constructor using string
	 * @param pin
	 */
	Pin(const std::string &pin);

	/**
	 * Constructor using long integer
	 * @param pin
	 */
	Pin(const long &pin);

	/**
	 * Checks if the pin is a valid one
	 * @return true if valid, false otherwise
	 */
	bool valid() const;

	/**
	 * Returns pin using a string
	 * @return string of pin
	 */
	std::string toString() const;

	/**
	 * Returns pin using a long integer
	 * @return pin (integer)
	 * @attention This integer does not take in account initial 0 values
	 */
	long toInteger() const;
};


#endif //WPS_PIN_GENERATOR_PIN_H
