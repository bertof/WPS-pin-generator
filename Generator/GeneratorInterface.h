//
// Created by pily on 27/01/17.
//

/***    GeneratorInterface
 * GeneratorInterface is an base class interface used to implement
 * the design pattern strategy
 */

#ifndef WPS_PIN_GENERATOR_GENERATORINTERFACE_H
#define WPS_PIN_GENERATOR_GENERATORINTERFACE_H

#include "../Pin/Pin.h"
#include <string>
#include <vector>

class GeneratorInterface {
public:
	/**
	 * Generates a valid pin based on the data passed
	 * @param s: string of data
	 * @return std::vector<Pin>: valid Pin object vector
	 */
	virtual std::vector<Pin> generatePin(const std::string &s) const =0;
};

#endif //WPS_PIN_GENERATOR_GENERATORINTERFACE_H
