//
// Created by pily on 27/01/17.
//

#ifndef WPS_PIN_GENERATOR_GENERATOR_H
#define WPS_PIN_GENERATOR_GENERATOR_H

#include "GeneratorInterface.h"
#include "../Exceptions.h"

#include <string>
#include <vector>

/**
 * Base class Generator
 * Used to generate valid Pins
 */
class Generator : public GeneratorInterface {
public:
	/***
	 * Implementation of generatePin
	 * Returns result of generatePinImp based on the same data passed
	 * @param s string of data
	 * @return Pin valid pin generated
	 */
	std::vector<Pin> generatePin(const std::string &s) const override {
		throw NotImplementedException();
	}

private:

	/***
	 * Generates a valid Pin object using an algorithm based on <a href="http://www.auditoriaswireless.net/wireless-windows/computepin-c83a35-by-zhaochunsheng-(wps)/">zhaochunsheng's ComputePIN-C83A35</a> and <a href="https://github.com/linkp2p/WPS-PIN">linkp2p's WPS-PIN</a>
	 * @param s string of data
	 * @return Pin valid pin generated
	 */
	std::vector<Pin> generatePinImp(const std::string &s) const {
		throw NotImplementedException();
	}
};


#endif //WPS_PIN_GENERATOR_GENERATOR_H
